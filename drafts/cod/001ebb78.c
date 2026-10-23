/* NON_MATCHING func_001EBB78 (sn-2.95.3-136): 2 differing. Retail loads the saved step into f12 before the object into a0 for SetMotionStep; ours loads them the other way round. Only a block-scoped float temporary for the step reorders them. */
/* sn-2.95.3-136: func_001EBB78, run the owner's five delayed motions: each one not yet started counts its
 * delay down, and when it runs out the motion is marked started and its object starts it at its step. */
#include "include_asm.h"

#ifdef NON_MATCHING
/* What a delayed motion passes on when it starts. */
typedef struct MotionArgs {
    int kind;                           /* 0x00 */
    int delay;                          /* 0x04 frames left before the motion starts */
    float step;                         /* 0x08 */
    int unk0C[6];
} MotionArgs;                           /* 0x24 */

/* One delayed motion, 0x40 bytes; the owner holds five at 0x5C. */
typedef struct DelayedMotion {
    void *obj;                          /* 0x00 */
    int unk04;
    MotionArgs args;                    /* 0x08 */
    char unk2C[0x30 - 0x2C];
    unsigned int flags;                 /* 0x30 bit 1 = started */
    char unk34[0x40 - 0x34];
} DelayedMotion;

#define MOTION_STARTED  2
#define MOTION_NUM      5

extern void cOm71_SetMotionRun(void *a0);
extern void SetMotionStep(void *a0, float f12);

/* Count the delay down; nonzero once it has run out. */
/* Count the delay down; nonzero once it has run out. */
static inline unsigned char delayDone(DelayedMotion *m)
{
    if (m->args.delay != 0) {
        m->args.delay--;
        return 0;
    }
    return 1;
}

__attribute__((section(".text.func_001EBB78")))
void func_001EBB78(char *owner)
{
    DelayedMotion *m;
    int i;

    for (i = 0; i < MOTION_NUM; i++) {
        long flags;

        m = (DelayedMotion *)(owner + 0x5C) + i;
        flags = (unsigned int)m->flags;

        if ((flags >> 1 & 1) == 0 && delayDone(m)) {
            MotionArgs args = m->args;

            m->flags |= MOTION_STARTED;
            cOm71_SetMotionRun(m->obj);
            SetMotionStep(m->obj, args.step);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001EBB78);
#endif
