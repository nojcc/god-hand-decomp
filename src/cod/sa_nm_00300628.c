/* NON_MATCHING MoveEmitter (sn-2.95.3-136; PARK, 118 diffs): control flow and calls match; loop invariant motion
 * differs: retail keeps the D_00741940 / D_0071B940 bases and 0x80000000 in the loop (mtlo/madd slot address) and
 * hoists the 0x40000000 / 0x4000000 masks plus the D_00741960 / D_00741980 bases instead. */
#include "include_asm.h"

#ifdef NON_MATCHING
#define EMITTER_SLOT_NUM   0x100
#define EMITTER_SLOT_SIZE  0x260

typedef struct EmVtEnt {
    short delta;
    short pad;
    void (*fn)();
} EmVtEnt;

typedef struct EmVt {
    char pad00[8];
    EmVtEnt destroy;                    /* 0x08 */
    char pad10[0x10];
    EmVtEnt move;                       /* 0x20 */
} EmVt;

typedef struct EmOwner {
    char pad000[0x250];
    int flags;                          /* 0x250 */
} EmOwner;

typedef struct Emitter {
    char pad000[0xF0];
    EmVt *vt;                           /* 0x0F0 */
    char pad0F4[0x14];
    EmOwner *owner;                     /* 0x108 */
    char pad10C[8];
    int flags;                          /* 0x114 */
    int mode;                           /* 0x118 */
} Emitter;

extern unsigned int D_00741940[];       /* bit set: slot in use */
extern unsigned int D_00741960[];       /* bit set: slot paused */
extern unsigned int D_00741980[];       /* bit set: slot hidden */
extern unsigned char D_0071B940[];      /* the 0x100 emitter slots, 0x260 bytes each */
extern unsigned int D_00747A84;
extern int D_003C3BC0;
extern char D_0044FC10[];
extern void DebugPrintfWrapper(int x, int y, int a2, int a3, char *fmt, ...);

__attribute__((section(".text.MoveEmitter")))
void MoveEmitter(void)
{
    Emitter *e;
    EmOwner *own;
    unsigned int bit;
    unsigned int w;
    int i;
    int n;
    int paused;
    int ok;
    int mode;

    paused = 0;
    if (D_00747A84 & 0x10000)
        paused = 1;
    n = 0;
    for (i = 0; i < EMITTER_SLOT_NUM; i++) {
        w = (unsigned int)i >> 5;
        bit = 0x80000000u >> (i & 0x1F);
        if ((D_00741940[w] & bit) == 0)
            continue;
        e = (Emitter *)(D_0071B940 + i * EMITTER_SLOT_SIZE);
        if (D_00741980[w] & bit) {
            e->vt->destroy.fn((char *)e + e->vt->destroy.delta, 2);
            D_00741940[w] &= ~bit;
            continue;
        }
        if (D_00741960[w] & bit) {
            D_00741980[w] |= bit;
            continue;
        }
        if ((e->flags & 0x40000000) == 0) {
            own = e->owner;
            ok = 0;
            if (own != 0 && (own->flags & 0x8000))
                continue;
            if (own != 0)
                ok = (own->flags & 0x8000) == 0;
            if (paused) {
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
        }
        n++;
        e->vt->move.fn((char *)e + e->vt->move.delta);
    }
    DebugPrintfWrapper(100, 100, 0, 4, D_0044FC10, n);
    D_003C3BC0 = n;
}
#else
INCLUDE_ASM("asm/nonmatching", MoveEmitter);
#endif
