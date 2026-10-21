/* NON_MATCHING func_00276478 (sn-2.95.3-136): 19 differing words. Retail tests emNo
 * with xori, extracts bit 6 of D_00747A84 with dsrl, and builds ~0x10 for objFlags with
 * lui/ori (an unsigned constant); the int types used here give li/bne, srl and addiu. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cCamera.h"
#include "godhand/cCamManager.h"
#include "godhand/cSaveLoad.h"
#include "godhand/vu0.h"

#define EM_NO_SCREEN_GHOST   0x26A
#define SYSFLAG_SCENE_HIDE   0x20000000
#define EMFLAG_SECOND_PART   0x1000000
#define OBJFLAG_SEE_THROUGH  0x10
#define GHOST_RATE           0.3f
#define GHOST_HEAD_NEAR_SQ   64.0f
#define GHOST_PART_NEAR_SQ   36.0f

/* The frame: the camera target and the child count cOmBase_childAt stores. */
typedef struct GhostFrame {
    cVec target;
    int childNum;
} GhostFrame;

extern unsigned int D_00747A84;
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);

/* Makes the enemy see-through and slow while the camera target is close to its head
 * child (or, when flagged, its ninth child); otherwise restores it. */
__attribute__((section(".text.func_00276478")))
void func_00276478(cEm00 *self)
{
    GhostFrame f;
    cOmBase *child;
    unsigned int flags;
    int near;

    if (self->emNo != EM_NO_SCREEN_GHOST) {
        return;
    }
    flags = D_00747A84;
    if (!(flags & SYSFLAG_SCENE_HIDE)) {
        if (!(flags & SAVELOAD_FLAG_BUSY)) {
            if (!((flags >> 6) & 1)) {
                if (D_005CAFF0 == 0) {
                    return;
                }
                VU0_SQC2_VF0_MEM(&f.target, 0);
                cVec_copy3(&f.target, &D_005CAFF0->target);
                near = 0;
                child = cOmBase_childAt((cOmBase *)self, &f.childNum, 16);
                if (child != 0 && capVu0MagnitudeSqXZ(child->pos, &f.target) < GHOST_HEAD_NEAR_SQ) {
                    near = 1;
                }
                if (self->emFlags & EMFLAG_SECOND_PART) {
                    child = cOmBase_childAt((cOmBase *)self, &f.childNum, 9);
                    if (child != 0 && capVu0MagnitudeSqXZ(child->pos, &f.target) < GHOST_PART_NEAR_SQ) {
                        near = 1;
                    }
                }
                if (near) {
                    self->objFlags |= OBJFLAG_SEE_THROUGH;
                    self->animRate = GHOST_RATE;
                    return;
                }
            }
        }
    }
    self->objFlags &= ~OBJFLAG_SEE_THROUGH;
    self->animRate = 1.0f;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00276478);
#endif
