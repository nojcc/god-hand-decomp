/* NON_MATCHING func_001EB7B8 (sn-2.95.3-136):
 * 10 instructions differ, all in the prologue: retail computes &pos (sp + 0x10) into s0 among the register
 * saves, before the zero-and-subtract block; this build computes it after that block. */
#include "include_asm.h"
#include "../vu0_pending.h"
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

#ifdef NON_MATCHING
#define CAM_FAR_LIMIT     -35.0f
#define CAM_EASE          0.1f
#define CAM_LAG_EASE      0.001f
#define CAM_NEAR_MARGIN   1.5f

/* The camera record the casino scene points at from 0x200. */
typedef struct CasinoCam {
    char unk000[0x208];
    float z;                            /* 0x208 */
    char unk20C[0xC];
    float zLag;                         /* 0x218 trails z */
} CasinoCam;

/* A view of the casino scene object: only the camera pointer. */
typedef struct CasinoScene {
    char unk000[0x200];
    CasinoCam *cam;                     /* 0x200 */
} CasinoScene;

/* The slot func_001EC388 returns: word 0 is the object in it. */
typedef struct CasinoSlot {
    cOmBase *obj;
} CasinoSlot;

extern cVec D_00568220;
extern cVec D_00568230;
extern CasinoSlot *func_001EC388(CasinoScene *self, int arg);

/* Fetch the position of the object in a slot, or the origin when the slot is empty. */
static inline void CasinoSlot_getPos(CasinoSlot *slot, cVec *pos)
{
    cVec zero;

    if (slot->obj != 0) {
        cVec_copy3(pos, slot->obj->pos);
    } else {
        cVec_set4(&zero, 0.0f, 0.0f, 0.0f, 1.0f);
        cVec_copy3(pos, &zero);
    }
}

/* Ease the scene camera's depth toward the object in the first slot, keeping the trailing depth behind it. */
__attribute__((section(".text.func_001EB7B8")))
void func_001EB7B8(CasinoScene *self)
{
    cVec ofs;
    cVec pos;
    CasinoSlot *slot;
    float z;

    VU0_ZERO_VSUB_XYZ_TO(&pos, 0, &D_00568230, &D_00568220);
    VU0_LQC2_SQC2_MEM(4, &ofs, &pos);
    if (CAM_FAR_LIMIT < self->cam->z) {
        slot = func_001EC388(self, 0);
        if (slot == 0) {
            return;
        }
        VU0_SQC2_VF0_MEM(&pos, 0);
        CasinoSlot_getPos(slot, &pos);
        if (pos.z < self->cam->z) {
            self->cam->z += (pos.z - self->cam->z) * CAM_EASE;
            self->cam->zLag = self->cam->z - ofs.z;
        }
    } else {
        slot = func_001EC388(self, 0);
        if (slot == 0) {
            return;
        }
        VU0_SQC2_VF0_MEM(&pos, 0);
        CasinoSlot_getPos(slot, &pos);
        z = pos.z - CAM_NEAR_MARGIN;
        if (z < self->cam->z) {
            self->cam->z += (z - self->cam->z) * CAM_EASE;
        }
        self->cam->zLag += (self->cam->z - self->cam->zLag) * CAM_LAG_EASE;
        if (self->cam->z < self->cam->zLag) {
            self->cam->zLag = self->cam->z;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001EB7B8);
#endif
