/* NON_MATCHING TransEsp (sn-2.95.3-136, retail rematerializes %hi(D_00747A84) in the loop instead of hoisting the game work address, builds the parent-alive flag with li 1 / movn, and keeps a copy of the object pointer in a1 for the virtual call) */
#include "include_asm.h"

#ifdef NON_MATCHING
/* TransEsp, runs the transform virtual of every live object that is neither hidden nor stopped, skipping
 * objects whose parent is dead; while paused only objects flagged to run through the pause (always, or with the
 * slow-mode bit when it is on, or through an active parent) are run. */
typedef struct EspVtEnt {
    short delta;
    short index;
    void (*fn)(void *self);
} EspVtEnt;

typedef struct EspObj {
    char pad000[0xF0];
    EspVtEnt *vtbl;                   /* 0x0F0 */
    char pad0F4[0x104 - 0xF4];
    unsigned int pauseFlags;            /* 0x104 */
    char pad108[0x114 - 0x108];
    struct EspObj *parent;           /* 0x114 */
    char pad118[0x250 - 0x118];
    unsigned int state;                 /* 0x250 */
    char pad254[0x400 - 0x254];
} EspObj;

extern unsigned int D_00747A84[];
typedef struct EspGameView {
    char pad000[0x5E4];
    unsigned int flags5E4;              /* 0x5E4 */
} EspGameView;
extern EspGameView D_007474A0;   /* game work flags 0x5E4; [-1] is 0x5E0, [-22] is 0x58C */
extern unsigned int D_0071B7C0[];
extern unsigned int D_0071B840[];
extern unsigned int D_0071B8C0[];
extern EspObj D_0061B7C0[];

#define VT_TRANS 5

__attribute__((section(".text.TransEsp")))
void TransEsp(void)
{
    int i;
    int paused;
    unsigned int t;
    int run;
    unsigned int mask;
    int w;
    EspObj *o;
    EspObj *p;

    t = D_00747A84[0] & 0x10000;
    paused = t != 0;
    if (D_00747A84[-1] & 0x10000000)
        return;
    if (D_00747A84[-22] & 0x400)
        return;
    o = D_0061B7C0;
    for (i = 0; i < 1024; i++, o++) {
        w = (unsigned int)i >> 5;
        mask = 0x80000000 >> (i & 31);
        if (!(D_0071B7C0[w] & mask))
            continue;
        if (D_0071B840[w] & mask)
            continue;
        if (D_0071B8C0[w] & mask)
            continue;
        p = o->parent;
        if (p != 0 && (p->state & 0x8000))
            continue;
        run = 0;
        if (p != 0)
            run = (p->state & 0x8000) ? 0 : 1;
        if (paused && !(o->pauseFlags & 2)) {
            if ((o->pauseFlags >> 6) & 1) {
                if (!(D_007474A0.flags5E4 & 0x4000000))
                    continue;
            } else if (!run) {
                continue;
            }
        }
        o->vtbl[VT_TRANS].fn((char *)o + o->vtbl[VT_TRANS].delta);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", TransEsp);
#endif
