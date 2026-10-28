/* NON_MATCHING func_00129EB0 (sn-2.95.3-136): 151 words vs 150, register allocation differs
 * throughout. Retail keeps the list element and its cOm60 view in two registers (s1, s0), recomputes
 * self->mtx and &D_005FEE00 inside the loop and spills &ret to the stack; here loop optimisation hoists
 * both invariants into saved registers and the element lives in one. */
#include "include_asm.h"
#include "../vu0_pending.h"
#include "godhand/cGameObj.h"
#include "godhand/cOm60.h"
#include "godhand/cMc.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"
#include "godhand/cSnd.h"

#ifdef NON_MATCHING
extern cMcObjList *D_00754C58;
extern int cOm60_ckParent(cOm60 *self);
extern void cOm60_setThrow(cOm60 *self, cVec *dir, float speed);
extern void MtxInverse(void *dst, void *src);
extern void capVu0ApplyMatrixXYZ(cVec *dst, float *mtx, cVec *v);

#define KNOCK_ACTOR_ID  0x364
#define KNOCK_SE        0x119

/* Knock away every free object of kind 0x364 that stands in the box in front of self, with a sound. */
__attribute__((section(".text.func_00129EB0")))
void func_00129EB0(cGameObj *self)
{
    cVec local;
    cVec push;
    float inv[16];
    cVec ret;
    cVec tmp;
    cGameObj **it;
    cGameObj **end;
    cGameObj *obj;
    cOm60 *om;

    VU0_SQC2_VF0_MEM(&local, 0);
    VU0_SQC2_VF0_MEM(&push, 0);
    end = (cGameObj **)D_00754C58->end;
    for (it = (cGameObj **)D_00754C58->begin; it != end; it++) {
        obj = *it;
        if (obj->objFlags & GAMEOBJ_OBJ_SUSPEND) {
            continue;
        }
        if (obj->objFlags < 0) {
            continue;
        }
        if (!(cGameObj_idInRange(obj, 0x300, 0x500) & 0xFF) || obj->actorId != KNOCK_ACTOR_ID) {
            continue;
        }
        om = (cOm60 *)obj;
        if (cOm60_ckParent(om) != 0) {
            continue;
        }
        MtxInverse(inv, self->mtx);
        VU0_LQC2_SQC2_MEM(4, &tmp, om->base.pos);
        cVec_applyMatrix(&tmp, inv);
        VU0_LQC2_SQC2_MEM(4, &ret, &tmp);
        cVec_copy3(&local, &ret);
        if (local.x < -0.8f || 0.8f < local.x || local.z < -0.8f || 2.5f < local.z
            || local.y < -0.7f || 2.0f < local.y) {
            continue;
        }
        push.x = 0.0f;
        push.y = 0.3f;
        push.z = 0.3f;
        capVu0ApplyMatrixXYZ(&push, self->mtx, &push);
        cOm60_setThrow((cOm60 *)obj, &push, 0.0f);
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, KNOCK_SE, self, 0, 0, 0, 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00129EB0);
#endif
