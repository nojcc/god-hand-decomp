/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/cOm60.h"
#include "godhand/ptrVec.h"
#include "godhand/sceVu0.h"
#include "godhand/cVec.h"

extern void MtxInverse(float *dst, float *src);
extern int cOm60_ckParent(cOm60 *self);
extern void SetActionKickBomb(void);

#define BOMB_ACTOR_ID 0x364

/* If a bomb (actor 0x364) that no one holds lies in the box in front of
 * enemy self (x within 0.5, z from -0.5 to 2, y from -0.5 to 1.5, in the
 * enemy's own frame), offer the player's bomb kick; 1 if it did.
 * Still differs from retail: the loop hoists &inv and the 0x364 id into
 * saved registers where retail hoists the 2.0 and 1.5 bounds and compares
 * the id with xori, so two more saved registers and a 0x10 larger frame. */
#ifdef NON_MATCHING
__attribute__((section(".text.func_00129CC8")))
int func_00129CC8(cEm00 *self)
{
    cVec loc;
    float inv[16];
    CVEC_TEMPS;
    void **it;
    void **end;

    CVEC_ZERO(loc);
    if (self->unk6A0 != 0) {
        return 0;
    }
    MtxInverse(inv, self->mtx);
    end = D_00754C58.v->end;
    it = D_00754C58.v->begin;
    while (it != end) {
        cGameObj *obj = *it++;

        if (obj->objFlags & 0x8000) {
            continue;
        }
        if (obj->objFlags & 0x80000000) {
            continue;
        }
        if ((cGameObj_idInRange(obj, 0x300, 0x500) & 0xFF) == 0) {
            continue;
        }
        if (obj->actorId != BOMB_ACTOR_ID) {
            continue;
        }
        if (cOm60_ckParent((cOm60 *)obj) != 0) {
            continue;
        }
        CVEC_SET_APPLY(loc, inv, obj->pos);
        if (loc.x < -0.5f || 0.5f < loc.x) {
            continue;
        }
        if (loc.z < -0.5f || 2.0f < loc.z) {
            continue;
        }
        if (loc.y < -0.5f || 1.5f < loc.y) {
            continue;
        }
        SetActionKickBomb();
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00129CC8);
#endif
