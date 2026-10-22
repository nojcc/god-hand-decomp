/* NON_MATCHING func_0012B328 (sn-2.95.3-136, fp_hazard_rules fdiv,mtc1): 160 words vs 165.
 * Retail keeps &fwd in a saved register across the loop (one more saved register, 0x10 more
 * frame). cOmBase_canCarry is defined as returning long long, which SN cc1 rejects; it is
 * declared int here until that definition is corrected. */
#include "include_asm.h"
#include "godhand/cGameObj.h"
#include "godhand/cMc.h"
#include "godhand/sceVu0.h"

#ifdef NON_MATCHING
extern cMcObjList *D_00754C58;
extern int cOmBase_canCarry(void *a0);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);

/* Whether id is a placed object's actor id (0x300..0x4FF). */
static __inline__ unsigned char isPlacedId(int id)
{
    if (id < 0x300) {
        return 0;
    }
    return id < 0x500;
}

/* The placed object self can pick up: carryable, within 1.5 of the point 0.8 ahead of self,
 * at most 0.5 above or below, within 60 degrees of self's heading and in line of sight;
 * the nearest such object, or 0. */
__attribute__((section(".text.func_0012B328")))
cGameObj *func_0012B328(cGameObj *self)
{
    cVec fwd;
    cVec from;
    cVec to;
    cMcObj **it;
    cMcObj **cur;
    cMcObj **end;
    cGameObj *obj;
    cGameObj *best;
    float bestDist;
    float dist;
    float dy;
    float ady;
    float turn;
    float aturn;

    cVec_zero(&fwd);
    fwd.z = 0.8f;
    fwd.x = 0.0f;
    fwd.y = 0.0f;
    end = D_00754C58->end;
    it = D_00754C58->begin;
    best = 0;
    cVec_applyMatrix(&fwd, self->mtx);
    bestDist = 2.25f;
    while (it != end) {
        cur = it++;
        obj = (cGameObj *)*cur;
        if (obj->objFlags & 0x8000) continue;
        if (obj->objFlags < 0) continue;
        if (!isPlacedId(obj->actorId)) continue;
        if (!cOmBase_canCarry(obj)) continue;
        if (self->mode != 0) continue;
        dist = capVu0MagnitudeSqXZ(&fwd, ((cGameObj *)*cur)->pos);
        if (bestDist < dist) continue;
        dy = self->pos->y - obj->pos->y;
        ady = (dy < 0.0f) ? -dy : dy;
        if (0.5f < ady) continue;
        turn = Turn_dest(self->pos, obj->pos, self->rot[1], 3.14159274f);
        aturn = (turn < 0.0f) ? -turn : turn;
        if (1.04719758f < aturn) continue;
        cVec_zero(&from);
        cVec_zero(&to);
        cVec_copy3(&from, &self->posA);
        cVec_copy3(&to, obj->pos);
        from.y += 0.5f;
        to.y += 0.5f;
        if (ChkLine(&from, &to, 0, 0, 7, 0x10, 0, 0, 0, 0, 0, 0, 1) == 0) {
            best = obj;
            bestDist = dist;
        }
    }
    return best;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0012B328);
#endif
