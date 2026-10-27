/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cObjSimple.h"
#include "godhand/capVu0.h"
#include "godhand/cutCmd.h"
#include "godhand/sceVu0.h"
#include "godhand/cVec.h"
#include "godhand/vecInline.h"

extern void MtxInverse(void *dst, void *src);
extern char D_00586AF0[];               /* cEvent */

#define BUST_CHILD     29
#define BUST_MAX_TILT  0.5235988f

#ifdef NON_MATCHING
/* Swing child 29 (the bust) of the prop: the anchor's motion since last frame,
 * taken into the bust's frame, tilts it about x (up to 30 degrees either way)
 * and a damped spring pulls the tilt back. A cut at frame 0, or flags bit 0,
 * resets the swing. Still differs from retail: retail multiplies by a 1.0
 * held in $f20 at run time (1.0 * 0.2 and the spring term times 1.0), and
 * keeps &bustPos, &bustPrevPos and &bustVel in saved registers. */
__attribute__((section(".text.cObjSimple_MoveBust")))
void cObjSimple_MoveBust(cObjSimple *self)
{
    int frame[3];
    sceVu0FMATRIX inv;
    cVec v;
    CVEC_TEMPS;
    cObjSimpleChild *root;
    cObjSimpleChild *bust;
    float tilt;

    root = cObjSimple_childAt(self, frame, 0);
    bust = cObjSimple_childAt(self, frame, BUST_CHILD);
    if (bust == 0) {
        return;
    }
    CVEC_ZERO(v);
    vec4_set_point(&ret_.x, root->worldPos.x, root->worldPos.y, root->worldPos.z);
    CVEC_FROM_RET(self->bustPos);
    CVEC_SUB(&self->bustPos, &self->bustPrevPos);
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
    if (tilt > BUST_MAX_TILT) {
        tilt = BUST_MAX_TILT;
    }
    if (tilt < -BUST_MAX_TILT) {
        tilt = -BUST_MAX_TILT;
    }
    bust->rot.x += tilt * 0.5f;
    bust->rot.x += self->bustSwing;
    if (cEvent_getCutFrame(D_00586AF0) == 0.0f || (self->flags & 1)) {
        bust->rot.x = 0.0f;
        self->bustSwing = 0.0f;
    }
    if (bust->rot.x > BUST_MAX_TILT) {
        bust->rot.x = BUST_MAX_TILT;
        self->bustSwing = 0.0f;
    }
    if (bust->rot.x < -BUST_MAX_TILT) {
        bust->rot.x = -BUST_MAX_TILT;
        self->bustSwing = 0.0f;
    }
    self->bustSwing *= 0.8f;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.03f;
    self->bustSwing += -bust->rot.x * 0.5f;
    sceVu0ApplyMatrix(&v, bust->mtx, &v);
    CVEC_ASSIGN_VEC(self->bustVel, v);
    CVEC_ASSIGN_VEC(self->bustPrevPos, self->bustPos);
}
#else
INCLUDE_ASM("asm/nonmatching", cObjSimple_MoveBust);
#endif
