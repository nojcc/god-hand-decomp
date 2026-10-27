/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cOmBase.h"
#include "godhand/capVu0.h"
#include "godhand/sceVu0.h"
#include "godhand/cVec.h"

extern void MtxInverse(void *dst, void *src);
extern float D_003C0460;                /* the bust spring's rest offset along z */

#define EMBUST_KIND_A    0x2A7
#define EMBUST_KIND_B    0x2AB
#define EMBUST_CHILD     29
#define EMBUST_MAX_TILT  0.5235988f

/* View of the enemies 0x2A7 and 0x2AB past cOmBase: their bust state. cEm00.h
 * names 0x15F4 and 0x1603 for other enemies' fields. */
typedef struct cEmBust {
    cOmBase base;
    char unk5E0[0x15F0 - 0x5E0];
    cVec bustVel;                       /* 0x15F0 bust velocity, kept in the bust's local frame */
    float bustSwing;                    /* 0x1600 bust swing angle rate */
} cEmBust;

#ifdef NON_MATCHING
/* Enemies 0x2A7 and 0x2AB: swing child 29 (the bust) like cObjSimple_MoveBust,
 * scaled by the enemy's speed rate. Still differs from retail: the saved
 * registers for &bustVel, &v and the 0x70 temporary are assigned in another
 * order, and the float registers of the swing update differ. */
__attribute__((section(".text.func_002890A0")))
void func_002890A0(cEmBust *self)
{
    int frame[3];
    sceVu0FMATRIX inv;
    cVec v;
    CVEC_TEMPS;
    cOmBase *bust;
    float tilt;

    if (self->base.actionId != EMBUST_KIND_A && self->base.actionId != EMBUST_KIND_B) {
        return;
    }
    bust = cOmBase_childAt(&self->base, frame, EMBUST_CHILD);
    if (bust == 0) {
        return;
    }
    CVEC_ZERO(v);
    CVEC_SUB(self->base.pos, &self->base.posA);
    v.x = ret_.x;
    v.z = ret_.z;
    v.y = 0.0f;
    CVEC_ADD_TO(self->bustVel, &v);
    MtxInverse(inv, bust->mtx);
    CVEC_APPLY(inv, &self->bustVel);
    v.x = ret_.x;
    v.y = ret_.y;
    v.z = ret_.z;
    tilt = -capVu0Atan2(v.y, __builtin_sqrtf(v.x * v.x + v.z * v.z));
    if (tilt > EMBUST_MAX_TILT) {
        tilt = EMBUST_MAX_TILT;
    }
    if (tilt < -EMBUST_MAX_TILT) {
        tilt = -EMBUST_MAX_TILT;
    }
    bust->posPrev.x += tilt * 0.5f * self->base.speedRate;
    bust->posPrev.x += self->bustSwing * self->base.speedRate;
    if (bust->posPrev.x > EMBUST_MAX_TILT) {
        bust->posPrev.x = EMBUST_MAX_TILT;
        self->bustSwing = 0.0f;
    }
    if (bust->posPrev.x < -EMBUST_MAX_TILT) {
        bust->posPrev.x = -EMBUST_MAX_TILT;
        self->bustSwing = 0.0f;
    }
    self->bustSwing *= 1.0f - self->base.speedRate * 0.2f;
    v.x = 0.0f;
    v.y = 0.0f;
    self->bustSwing += -bust->posPrev.x * 0.5f * self->base.speedRate;
    v.z = D_003C0460;
    sceVu0ApplyMatrix(&v, bust->mtx, &v);
    CVEC_ASSIGN_VEC(self->bustVel, v);
}
#else
INCLUDE_ASM("asm/nonmatching", func_002890A0);
#endif
