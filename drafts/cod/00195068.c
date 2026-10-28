/* sn-2.95.3-136 */
/* NON_MATCHING func_00195068 (retail 215 words). The switch and the phase code
 * match; in the piece loop retail keeps -1000.0f in $f21 and forms the matrix
 * address (sp + 0x40) at each call, while this form keeps the matrix address
 * in a saved register and spills the tmp_ pointer (frame 0x140 vs 0x130). */
#include "godhand/cOmBase.h"
#include "godhand/cObjBase.h"
#include "godhand/cEmManage.h"
#include "godhand/cModel.h"
#include "godhand/cSnd.h"
#include "godhand/cVec.h"
#include "godhand/mtx.h"
#include "godhand/objField.h"

/* One flying piece of a broken object: it moves and spins every frame and
 * falls until it is far below the room. */
typedef struct cOmBreakPiece {
    cVec pos;                           /* 0x00 */
    cVec rot;                           /* 0x10 */
    cVec vel;                           /* 0x20 */
    cVec spin;                          /* 0x30 */
    cVec scale;                         /* 0x40 */
    float *mtx;                         /* 0x50 the part's matrix */
    unsigned char active;               /* 0x54 */
    char pad55[0x58 - 0x55];
    float gravity;                      /* 0x58 added to vel.y every frame */
    char pad5C[0x60 - 0x5C];
} cOmBreakPiece;

/* A breakable object: its pieces, the break countdown and the sound that
 * stops when it breaks. */
typedef struct cOmBreakObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x630 - 0x5E0];
    cOmBreakPiece piece[9];             /* 0x630 one per child, from child 3 */
    char unk990[0xAF0 - 0x990];
    short timer;                        /* 0xAF0 frames left in the phase */
    char unkAF2[0xB20 - 0xAF2];
    int se;                             /* 0xB20 looping sound, 0 when none */
} cOmBreakObj;

extern int GetField_54_173900(void *rec);
extern int cEmManage_CreateItem(void *self, cVec *pos, int kind, int mode);
extern void func_00195620(char *p);
extern void SetField5B0Bit2ClearBit8_1B7908(cOmBase *self);
extern void MtxInitRotVec(float *mtx, cVec *rot, unsigned char order);
extern void CopyVec3ToField30_147C40(float *mtx, cVec *pos);
extern void MtxMulScaleVec(float *dst, float *src, cVec *scale);

/* Break sequence: stop the sound, start the break effect and sound at child 2,
 * drop an item and throw the pieces; wait 150 frames, then 15, then go back
 * to mode 0. Every phase moves the active pieces from child 3 on. */
__attribute__((section(".text.func_00195068")))
void func_00195068(cOmBreakObj *self)
{
    cVec pos;
    int frame[3];
    CVEC_TEMPS;
    float mtx[16];
    int i;
    float rate;
    cOmBreakPiece *pc;

    switch (self->base.phase) {
    case 0:
        if (self->se != 0) {
            cSnd_SeStop(&D_005FEE00, self->se);
            self->se = 0;
        }
        CVEC_ZERO(pos);
        ForwardVec3At30_147C60(&pos, cOmBase_childAt(&self->base, frame, 2)->mtx);
        SetEffect(0x177, 2, self, 0, -1, 0xFFFFFFFF);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x87, self, 0,
                           (int)cOmBase_childAt(&self->base, frame, 2), 0, 0);
        KillEffect((int)self, 1, 2);
        cEmManage_CreateItem(&D_005864F0, &pos, 0xFFFF, 0);
        func_00195620((char *)self);
        SetField5B0Bit2ClearBit8_1B7908(&self->base);
        self->timer = 150;
        self->base.phase = 1;
        self->base.step = 0;
        self->base.stepArg = 0;
        /* fall through */
    case 1:
        if (--self->timer <= 0) {
            self->timer = 15;
            self->base.phase = 2;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    case 2:
        if (--self->timer <= 0) {
            self->base.phase = 3;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    case 3:
        self->base.mode = 0;
        self->base.phase = 0;
        self->base.step = 0;
        self->base.stepArg = 0;
        break;
    }

    for (i = 3; i < 9 && self->base.childNum != i; i++) {
        pc = &self->piece[i];
        if (GetField_54_173900(pc) != 1)
            continue;
        rate = cEmManage_GetSpeedRate(&D_005864F0);
        CVEC_INIT_MUL(ret_, &pc->vel, rate);
        CVEC_ADD_TO(pc->pos, &ret_);
        CVEC_INIT_MUL(ret_, &pc->spin, rate);
        CVEC_ADD_TO(pc->rot, &ret_);
        Adjust_theta_vec(&pc->rot);
        MtxInitRotVec(mtx, &pc->rot, 0);
        CopyVec3ToField30_147C40(mtx, &pc->pos);
        MtxMulScaleVec(mtx, mtx, &pc->scale);
        MtxCopy(pc->mtx, mtx);
        pc->vel.y += pc->gravity * rate;
        if (pc->vel.y < -1000.0f)
            Obj0000_Set_Byte_54(pc, 0);
    }
}
