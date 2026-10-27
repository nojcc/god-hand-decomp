/* sn-2.95.3-136 */
#include "include_asm.h"
#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cEmManage.h"
#include "godhand/cModel.h"
#include "godhand/cSnd.h"
#include "godhand/cVec.h"
#include "godhand/mtx.h"
#include "godhand/objField.h"

#define PIECE_NUM 8

/* An object that breaks into flying pieces, one per child body. */
typedef struct cOmPieceObj {
    cOmBase base;
    char unk5E0[0x648 - 0x5E0];
    int se;                             /* 0x648 sound stopped when it breaks */
    char unk64C[4];
    cDamageUnit *hit[3];                /* 0x650 its damage volumes, switched off when it breaks */
    char unk65C[4];
    cOmPiece piece[PIECE_NUM];          /* 0x660 piece[0] belongs to the body itself */
    short timer;                        /* 0x960 */
} cOmPieceObj;

extern void SetField5B0Bit2ClearBit8_1B7908(cOmBase *self);
extern unsigned char GetField_54_173900(unsigned char *a0);
extern void MtxInitRotVec(void *a0, float *a1, unsigned char order);
extern void CopyVec3ToField30_147C40(float *a0, float *a1);
extern void MtxMulScaleVec(int a0, int a1, int a2);
extern void func_001B4F48(char *p);

/* Break the object: switch its damage volumes off, wait 30 frames, fade it
 * out over 15, then end; every frame each active piece flies on, turning
 * and falling, until it drops below -1000.
 * Still differs from retail: retail keeps -1000.0f and the high half of
 * D_005864F0 in saved registers across the piece loop; with the operator
 * asm in the loop body ours loads both inside it. */
__attribute__((section(".text.func_001B4A18")))
void func_001B4A18(cOmPieceObj *self)
{
    int i;

    switch (self->base.phase) {
    case 0:
        if (self->hit[0] != 0)
            cDamageUnit_SetDamageCollActive(self->hit[0], 0);
        if (self->hit[1] != 0)
            cDamageUnit_SetDamageCollActive(self->hit[1], 0);
        if (self->hit[2] != 0)
            cDamageUnit_SetDamageCollActive(self->hit[2], 0);
        cSnd_SeStop(&D_005FEE00, self->se);
        self->se = 0;
        func_001B4F48((char *)self);
        SetField5B0Bit2ClearBit8_1B7908(&self->base);
        self->base.phase = 1;
        self->timer = 30;
        self->base.step = 0;
        self->base.stepArg = 0;
    case 1:
        if (--self->timer <= 0) {
            self->timer = 15;
            self->base.phase = 2;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    case 2:
        self->timer--;
        self->base.animRate = self->timer / 15.0f;
        if (self->timer <= 0) {
            self->base.step = 0;
            self->base.phase = 3;
            self->base.stepArg = 0;
        }
        break;
    case 3:
        self->base.phase = 0;
        self->base.mode = 4;
        self->base.step = 0;
        self->base.stepArg = 0;
        break;
    }
    for (i = 1; i < PIECE_NUM && self->base.childNum != i; i++) {
        CVEC_TEMPS;
        float mtx[16] __attribute__((aligned(16)));
        cOmPiece *pc = &self->piece[i];
        float rate;

        if (GetField_54_173900((unsigned char *)pc) != 1)
            continue;
        rate = cEmManage_GetSpeedRate(&D_005864F0);
        CVEC_STORE(&tmp_, pc->vel);
        CVEC_MUL_SCALAR(tmp_, rate);
        CVEC_STORE(&ret_, tmp_);
        CVEC_ADD_TO(pc->pos, &ret_);
        CVEC_STORE(&tmp_, pc->spin);
        CVEC_MUL_SCALAR(tmp_, rate);
        CVEC_STORE(&ret_, tmp_);
        CVEC_ADD_TO(pc->rot, &ret_);
        Adjust_theta_vec(&pc->rot);
        MtxInitRotVec(mtx, &pc->rot.x, 0);
        CopyVec3ToField30_147C40(mtx, &pc->pos.x);
        MtxMulScaleVec((int)mtx, (int)mtx, (int)&pc->scale);
        MtxCopy(pc->mtx, mtx);
        pc->vel.y += pc->gravity * rate;
        if (pc->vel.y < -1000.0f)
            Obj0000_Set_Byte_54(pc, 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001B4A18);
#endif
