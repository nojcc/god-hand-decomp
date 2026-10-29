/* sn-2.95.3-136 */
#include "include_asm.h"
/* NON_MATCHING: retail keeps &ret_, &tmp_, &d and the constant 1 of the
 * actor test in saved registers across the moves (frame 0xB0, s0-s6; ours
 * 0x90, s0-s4), and step 0 addresses tmp_ as &ret_ + 0x10. The control flow,
 * the stack slots and the loop shape match. */
#include "godhand/cOmSub.h"
#include "godhand/cGameObj.h"
#include "godhand/cEmManage.h"
#include "godhand/cVec.h"

/* Move target and the parts held at 0xC by d and pass each actor among the
 * parts its new position. A macro: retail shares the caller's return slot
 * and temporary, which an inline function gets its own of. */
#define COMSUB_MOVE_BY(self, d)                                                 \
    {                                                                           \
        unsigned int i_;                                                        \
                                                                                \
        CVEC_SET_ADD(*(self)->target, (self)->target, &(d));                    \
        for (i_ = 0; i_ < COMSUB_PART_COUNT; i_++) {                            \
            if ((self)->part[i_] != 0) {                                        \
                int actor_;                                                     \
                                                                                \
                CVEC_SET_ADD(*(self)->part[i_]->pos, (self)->part[i_]->pos, &(d)); \
                actor_ = 0;                                                     \
                if ((cGameObj_idInRange((self)->part[i_], 0x100, 0x1FF) & 0xFF) || \
                    (cGameObj_idInRange((self)->part[i_], 0x200, 0x300) & 0xFF) || \
                    (cGameObj_idInRange((self)->part[i_], 0x300, 0x500) & 0xFF) || \
                    (cGameObj_idInRange((self)->part[i_], 0x500, 0x600) & 0xFF))   \
                    actor_ = 1;                                                 \
                if (actor_ == 1)                                                \
                    cGameObj_vt((self)->part[i_])->unk74((char *)(self)->part[i_] +      \
                        cGameObj_vt((self)->part[i_])->unk70Delta, (self)->part[i_]->pos); \
            }                                                                   \
        }                                                                       \
    }

#ifdef NON_MATCHING
/* Fall step: speed up by accel, move target and the parts by the speed,
 * bounce on the start height until the speed drops below accel, then settle
 * on the goal. Returns 0 once done. */
__attribute__((section(".text.func_001C5F48")))
int func_001C5F48(cOmSubFall *fall)
{
    cOmSub *self = &fall->base;
    float rate;
    cVec d;
    CVEC_TEMPS;

    self->time += 1.0f;
    CVEC_ZERO(d);
    rate = cEmManage_GetSpeedRate(&D_005864F0);
    switch (self->mode) {
    case 0:
        if (self->reverse == COMSUB_REVERSED) {
            CVEC_INIT_MUL(ret_, &self->accel, -1.0f);
            CVEC_PUT(&self->accel, ret_);
        }
        self->time = 1.0f;
        self->mode++;
    case 1:
        CVEC_SET_MUL(d, &self->accel, rate);
        CVEC_INIT_ADD(ret_, &self->vel, &d);
        CVEC_PUT(&self->vel, ret_);
        CVEC_SET_MUL(d, &self->vel, rate);
        if (self->flags & COMSUB_LAND) {
            if (self->accel.y > 0.0f) {
                if (self->target->y + d.y < self->startA.y) {
                    if (!(self->flags & COMSUB_HOLD) && self->ent != 0) {
                        COMSUB_MOVE_BY(self, d);
                    }
                    return 1;
                }
            } else if (self->startA.y < self->target->y + d.y) {
                if (!(self->flags & COMSUB_HOLD) && self->ent != 0) {
                    COMSUB_MOVE_BY(self, d);
                }
                return 1;
            }
            CVEC_ASSIGN(d, &self->vel);
            d.y -= self->target->y + self->vel.y - self->startA.y;
            if (!(self->flags & COMSUB_HOLD) && self->ent != 0) {
                COMSUB_MOVE_BY(self, d);
            }
            self->vel.y *= -fall->bounce;
            if (__builtin_fabsf(self->accel.y) < __builtin_fabsf(self->vel.y)) {
                return 1;
            }
        }
        self->mode++;
    case 2:
        if (self->flags & COMSUB_LAND) {
            CVEC_SET_SUB(d, self->target, &self->goalA);
            d.y = self->startA.y - self->goalA.y;
        }
        func_001C7310(self);
        if (!(self->flags & COMSUB_HOLD) && self->ent != 0) {
            COMSUB_MOVE_BY(self, d);
        }
        self->mode++;
    case 3:
        return 0;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001C5F48);
#endif
