/* NON_MATCHING func_001299F0 (sn-2.95.3-136): 100 differing words, from one cause.
 * Retail builds &f.work (addiu s0, sp, 0x60) before the first quadword copy, so the
 * offset pointer needs its own saved register (s3) and the frame is 0x10 larger; here
 * &f.work is built after the copy and shares s0. The floats at 0x550 are not yet in
 * cGameObj. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cGameObj.h"
#include "godhand/cCamera.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

#define HOLD_FACE_TARGET  0
#define HOLD_FACE_HOLDER  1

#define OBJ_VEL(o)  ((float *)((char *)(o) + 0x550))

/* The frame: the target's rotation, the offset, the transform's result and work copy. */
typedef struct HoldFrame {
    float mtx[16];
    cVec at;
    cVec out;
    cVec work;
} HoldFrame;

#define HOLDFRAME_OFFSET(field) ((int)&((HoldFrame *)0)->field)

extern float Turn_dest(void *from, void *to, float angle, float limit);
extern void MtxInitRotY(void *mtx, float angle);

/* Puts the holder at an offset in front of the held object and faces them toward each
 * other, then stops both. With HOLD_FACE_HOLDER only the held object turns. */
__attribute__((section(".text.func_001299F0")))
void func_001299F0(cGameObj *self, cGameObj *held, cVec *offset, int how, float turn)
{
    HoldFrame f;

    if (held == 0) {
        return;
    }
    switch (how) {
    default:
    case HOLD_FACE_TARGET:
        self->rot[1] += Turn_dest(self->pos, held->pos, self->rot[1], 3.1415927f);
        self->rot[1] = Adjust_theta(self->rot[1]);
        held->rot[1] = self->rot[1] + 3.1415927f;
        held->rot[1] = Adjust_theta(held->rot[1]);
        self->rot[1] += turn;
        self->rot[1] = Adjust_theta(self->rot[1]);
        break;
    case HOLD_FACE_HOLDER:
        held->rot[1] = self->rot[1] + 3.1415927f;
        held->rot[1] = Adjust_theta(held->rot[1]);
        break;
    }
    VU0_SQC2_VF0_MEM(&f.at, 0);
    MtxInitRotY(f.mtx, held->rot[1]);
    f.at.x = offset->x * held->scale[0];
    f.at.y = 0.0f;
    f.at.z = offset->z * held->scale[2];
    VU0_LQC2(4, &f.at, 0);
    VU0_SQC2(4, &f, HOLDFRAME_OFFSET(work));
    sceVu0ApplyMatrix(&f.work, f.mtx, &f.work);
    VU0_LQC2(4, &f.work, 0);
    VU0_SQC2(4, &f, HOLDFRAME_OFFSET(out));
    f.at.x = f.out.x;
    f.at.y = f.out.y;
    f.at.z = f.out.z;
    VU0_VADD_XYZ_IP(&f.at, 0, held->pos);
    self->pos->x = f.at.x;
    self->pos->z = f.at.z;
    OBJ_VEL(held)[2] = 0.0f;
    OBJ_VEL(held)[0] = 0.0f;
    OBJ_VEL(held)[1] = 0.0f;
    OBJ_VEL(self)[2] = 0.0f;
    OBJ_VEL(self)[0] = 0.0f;
    OBJ_VEL(self)[1] = 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001299F0);
#endif
