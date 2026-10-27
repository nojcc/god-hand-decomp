/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cOmBase.h"
#include "godhand/cVec.h"
#include "godhand/vu0.h"
#include "godhand/vecInline.h"

#ifdef NON_MATCHING
/* What a delayed motion passes on when it starts (as drafts/cod/001ebb78.c). */
typedef struct MotionArgs {
    int kind;                           /* 0x00 */
    int delay;                          /* 0x04 */
    float step;                         /* 0x08 */
    int unk0C[2];
    float limitZ;                       /* 0x14 the object trips once its z falls below this; 0 for none */
    int unk18[3];
} MotionArgs;                           /* 0x24 */

/* One delayed motion, 0x40 bytes; the owner holds five at 0x5C. */
typedef struct DelayedMotion {
    cOmBase *obj;                       /* 0x00 */
    int unk04;
    MotionArgs args;                    /* 0x08 */
    char unk2C[0x30 - 0x2C];
    unsigned int flags;                 /* 0x30 bit 1 started, bit 3 tripped */
    char unk34[0x40 - 0x34];
} DelayedMotion;

extern void cOm71_SetMotionKokeru(cOmBase *self);

/* Trip each of the owner's five motion objects (cOm71_SetMotionKokeru) once
 * its z falls below the motion's limit; a motion with no object uses the
 * origin.
 * Still differs from retail: the loop keeps &pos in a saved register (a 0x10
 * larger frame) where retail forms it again before each self-check. */
__attribute__((section(".text.func_001EBC58")))
void func_001EBC58(char *owner)
{
    DelayedMotion *m;
    int i;

    m = (DelayedMotion *)(owner + 0x5C);
    for (i = 0; i < 5; i++, m++) {
        MotionArgs args = m->args;
        long flags;
        long tripped;

        if (args.limitZ == 0.0f) {
            continue;
        }
        flags = (unsigned int)m->flags;
        tripped = flags >> 3 & 1;
        if (tripped != 0) {
            continue;
        }
        {
            cVec pos;
            cVec zero;

            CVEC_ZERO(pos);
            if (m->obj != 0) {
                CVEC_ASSIGN(pos, m->obj->pos);
            } else {
                vec4_set_point(&zero.x, 0.0f, 0.0f, 0.0f);
                pos.x = zero.x;
                pos.y = zero.y;
                pos.z = zero.z;
            }
            {
                MotionArgs now = m->args;

                if (pos.z < now.limitZ) {
                    cOm71_SetMotionKokeru(m->obj);
                    m->flags |= 8;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001EBC58);
#endif
