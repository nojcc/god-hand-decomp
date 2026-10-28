/* sn-2.95.3-136 */
#include "include_asm.h"
/* NON_MATCHING func_001C6CB8 (fp_hazard_rules fdiv): 317 vs 287 words.
 * Each operator* by a scalar reads the temporary through a copy of $s3
 * instead of $s3 itself, and the three strength branches don't share the
 * turn multiply: retail jumps all three into one tail from the mul.s on,
 * which needs the asm statements of that tail to come from one source line
 * (an inline operator), not from three macro expansions. */
#include "godhand/cOmSub.h"
#include "godhand/rand.h"
#include "godhand/sceVu0.h"
#include "godhand/cVec.h"

#ifdef NON_MATCHING
/* This frame's shake of a move record: push is moveA as a unit vector
 * scaled to 1/100, turn is moveB as a unit vector scaled to radians, each
 * times fRand1_1() and the strength for the current part of the move (fade
 * in, middle, fade out). Both are zero when the record doesn't shake. */
__attribute__((section(".text.func_001C6CB8")))
void func_001C6CB8(cOmSubShake *self, cVec *push, cVec *turn)
{
    CVEC_TEMPS;
    float amp;

    if (self->base.flags & COMSUB_SHAKE) {
        CVEC_ASSIGN(*push, &self->base.moveA);
        CVEC_ASSIGN(*turn, &self->base.moveB);
        if (!(push->x == 0.0f && push->y == 0.0f && push->z == 0.0f))
            CVEC_SET_UNIT(*push, push);
        if (!(turn->x == 0.0f && turn->y == 0.0f && turn->z == 0.0f))
            CVEC_SET_UNIT(*turn, turn);
        CVEC_SET_MUL(*push, push, 0.01f);
        CVEC_SET_MUL(*turn, turn, 0.017453292f);
        if (self->base.time <= self->fadeIn) {
            amp = fRand1_1() * self->inAmp;
            CVEC_SET_MUL(*push, push, amp);
            amp = fRand1_1() * self->inAmp;
            CVEC_SET_MUL(*turn, turn, amp);
        } else if (self->base.length - self->fadeOut < self->base.time) {
            amp = fRand1_1() * self->outAmp;
            CVEC_SET_MUL(*push, push, amp);
            amp = fRand1_1() * self->outAmp;
            CVEC_SET_MUL(*turn, turn, amp);
        } else {
            amp = fRand1_1() * self->midAmp;
            CVEC_SET_MUL(*push, push, amp);
            amp = fRand1_1() * self->midAmp;
            CVEC_SET_MUL(*turn, turn, amp);
        }
    } else {
        push->x = 0.0f;
        push->y = 0.0f;
        push->z = 0.0f;
        turn->x = 0.0f;
        turn->y = 0.0f;
        turn->z = 0.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001C6CB8);
#endif
