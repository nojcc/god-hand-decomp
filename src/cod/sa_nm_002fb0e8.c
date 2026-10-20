/* NON_MATCHING MoveEsp (sn-2.95.3-136;
 * PARK, 61 diffs): pre-pass, control flow and calls match; loop invariant motion
 * differs as in MoveEmitter: retail hoists the 0x4000000 mask and the D_0071B840 base but keeps D_0071B8C0 in the loop,
 * this source hoists both bitmap bases.
 * Runs every live effect slot (0x400 slots of 0x400 bytes): destroys killed ones,
 * moves paused ones to the kill set, skips frozen-owner / disallowed-while-paused ones and moves the rest. */
#include "include_asm.h"

#ifdef NON_MATCHING
#define ESP_SLOT_NUM   0x400
#define ESP_SLOT_SIZE  0x400

typedef struct EspVtEnt {
    short delta;
    short pad;
    void (*fn)();
} EspVtEnt;

typedef struct EspVt {
    char pad00[8];
    EspVtEnt destroy;                   /* 0x08 */
    char pad10[0x10];
    EspVtEnt move;                      /* 0x20 */
} EspVt;

typedef struct EspOwner {
    char pad000[0x250];
    int flags;                          /* 0x250 */
} EspOwner;

typedef struct Esp {
    char pad000[0xF0];
    EspVt *vt;                          /* 0x0F0 */
    char pad0F4[0x10];
    int mode;                           /* 0x104 */
    char pad108[0xC];
    EspOwner *owner;                    /* 0x114 */
} Esp;

extern unsigned int D_0071B7C0[];       /* bit set: slot in use */
extern unsigned int D_0071B840[];       /* bit set: slot paused */
extern unsigned int D_0071B8C0[];       /* bit set: slot marked for kill */
extern unsigned char D_0061B7C0[];      /* the effect slots */
extern unsigned int D_00747A84;
extern int D_003C3BB8;
extern char D_007419A0[];
extern char D_00743250[];
extern void func_00305C20(void *p);
extern void func_00306E38(void *p);

__attribute__((section(".text.MoveEsp")))
void MoveEsp(void)
{
    Esp *e;
    EspOwner *own;
    unsigned int bit;
    unsigned int w;
    int i;
    int n;
    int paused;
    int ok;
    int mode;
    long t;

    t = (int)D_00747A84;
    if ((t & 0x20000000) == 0 && (((unsigned long)t >> 6) & 1UL) == 0)
        func_00305C20(D_007419A0);
    else if (D_00747A84 & 0x4000000)
        func_00305C20(D_007419A0);
    func_00306E38(D_00743250);
    n = 0;
    paused = 0;
    if (D_00747A84 & 0x10000)
        paused = 1;
    for (i = 0; i < ESP_SLOT_NUM; i++) {
        w = (unsigned int)i >> 5;
        bit = 0x80000000u >> (i & 0x1F);
        if ((D_0071B7C0[w] & bit) == 0)
            continue;
        e = (Esp *)(D_0061B7C0 + i * ESP_SLOT_SIZE);
        if (D_0071B8C0[w] & bit) {
            e->vt->destroy.fn((char *)e + e->vt->destroy.delta, 2);
            D_0071B7C0[w] &= ~bit;
            continue;
        }
        if (D_0071B840[w] & bit) {
            D_0071B8C0[w] |= bit;
            continue;
        }
        own = e->owner;
        if (own != 0 && (own->flags & 0x8000))
            continue;
        if (paused) {
            ok = 0;
            if (own != 0)
                ok = (own->flags & 0x8000) == 0;
            mode = e->mode;
            if ((mode & 2) == 0) {
                if ((mode >> 6) & 1) {
                    if ((D_00747A84 & 0x4000000) == 0)
                        continue;
                } else if (ok == 0) {
                    continue;
                }
            }
        }
        n++;
        e->vt->move.fn((char *)e + e->vt->move.delta);
    }
    D_003C3BB8 = n;
}
#else
INCLUDE_ASM("asm/nonmatching", MoveEsp);
#endif
