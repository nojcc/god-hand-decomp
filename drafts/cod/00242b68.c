/* sn-2.95.3-136 */
#include "include_asm.h"
/* NON_MATCHING func_00242B68 (fp_hazard_rules fdiv, extern_jtbl D_0043C870
 * D_0043C890): 552 of 552 words, 17 differ. Retail keeps the temporary's
 * address in s2 and the return slot's in s3 for the heading to the next
 * spot (this C swaps them), and in step 5 puts the temporary's address in
 * v1 instead of v0. */
#include "godhand/cEm00.h"
#include "godhand/cEmManage.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cObjBase.h"
#include "godhand/cGameObj.h"
#include "godhand/cCamera.h"
#include "godhand/capVu0.h"
#include "godhand/player.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
#include "godhand/rand.h"
#include "godhand/sceVu0.h"
#include "godhand/cVec.h"

/* cVec r = *a * s; (operator* by a scalar, as CVEC_INIT_MUL with s bound
 * first: retail loads the scale before the vector's address). */

#ifdef NON_MATCHING

#define FLOAT_MUL(r, a, s)                                      \
    {                                                           \
        float s_ = (s);                                         \
        cVec *t_ = &tmp_;                                       \
        cVec *a_ = (a);                                         \
                                                                \
        VU0_LQC2(4, a_, 0);                                     \
        VU0_SQC2_MEM(4, &tmp_, 0);                              \
        VU0_VSCALE_XYZ_MEM(&tmp_, 0, s_);                       \
        VU0_LQC2(4, t_, 0);                                     \
        VU0_SQC2_MEM(4, &(r), 0);                               \
    }

#define EMFLAG_NO_SOLID         0x10000
#define EM_TURN_RATE            0.09817477f /* pi / 32 per frame at full speed */
#define EM_FLY_TURN_RATE        0.19634955f /* pi / 16 */
#define EM_BOB_STEP             0.17453292f /* 10 degrees per frame */
#define EM_BOB_HEIGHT           0.02f
#define EM_SPOT_NUM             7
#define EM_PHASE_FLOAT_END      0x83

/* A floating enemy's flight between the seven way points. It starts at the
 * nearest spot, waits 15 frames, picks the next spot (any of 1 to 6 from
 * spot 0, otherwise one of three by a table, half the time spot 0), flies
 * there at 0.3 per frame for up to 90 frames easing to its float height,
 * then drifts to a stop and either attacks (0x80 to 0x82) or starts over.
 * When unk172C runs out it goes to phase 0x83. The body bobs every frame
 * except while it flies. followTimer holds the spot it is at. */
__attribute__((section(".text.func_00242B68")))
void func_00242B68(cEm00 *self)
{
    cVec step;
    CVEC_TEMPS;
    unsigned short sel;
    unsigned int i;
    float best;
    float dist;
    float bob;
    int go;

    CVEC_ZERO(step);
    cCollisionSolidManage_SetActive((int)D_00462FC0, (int)self, 0);
    self->emFlags |= EMFLAG_NO_SOLID;
    switch (self->step) {
    case 0:
        best = 1e12f;
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x2464), EM_RES_REC(self->resource, 0x2468), 3, 0.0f, sel, 0);
        self->followTimer = 0;
        for (i = 0; i < EM_SPOT_NUM; i++) {
            dist = capVu0MagnitudeSqXZ(&D_00585040[i], self->pos);
            if (best < dist)
                continue;
            self->followTimer = i;
            best = dist;
        }
        self->unk60C = 0.0f;
        self->timer = 15.0f;
        self->step++;
        /* fallthrough */
    case 1:
        cGameObj_SetTgtTurn((char *)self, Getplayer()->pos, self->speedRate * EM_TURN_RATE);
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        self->timer -= self->speedRate;
        if (self->timer <= 0.0f) {
            self->step++;
        }
        break;
    case 2:
        Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        switch (self->followTimer) {
        case 0:
            self->unk56C = (unsigned int)irand() % 6 + 1;
            break;
        case 1:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                self->unk56C = 0;
                break;
            case 1:
                self->unk56C = 2;
                break;
            case 2:
                self->unk56C = 3;
                break;
            }
            if (irand() & 1) {
                self->unk56C = 0;
            }
            break;
        case 2:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                self->unk56C = 0;
                break;
            case 1:
                self->unk56C = 1;
                break;
            case 2:
                self->unk56C = 3;
                break;
            }
            if (irand() & 1) {
                self->unk56C = 0;
            }
            break;
        case 3:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                self->unk56C = 0;
                break;
            case 1:
                self->unk56C = 1;
                break;
            case 2:
                self->unk56C = 2;
                break;
            }
            if (irand() & 1) {
                self->unk56C = 0;
            }
            break;
        case 4:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                self->unk56C = 0;
                break;
            case 1:
                self->unk56C = 5;
                break;
            case 2:
                self->unk56C = 6;
                break;
            }
            if (irand() & 1) {
                self->unk56C = 0;
            }
            break;
        case 5:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                self->unk56C = 0;
                break;
            case 1:
                self->unk56C = 4;
                break;
            case 2:
                self->unk56C = 6;
                break;
            }
            if (irand() & 1) {
                self->unk56C = 0;
            }
            break;
        case 6:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                self->unk56C = 0;
                break;
            case 1:
                self->unk56C = 4;
                break;
            case 2:
                self->unk56C = 5;
                break;
            }
            if (irand() & 1) {
                self->unk56C = 0;
            }
            break;
        }
        if (self->unk56C >= EM_SPOT_NUM) {
            self->unk56C = EM_SPOT_NUM - 1;
        }
        cVec_copy3(&self->unk580, &D_00585040[self->unk56C]);
        CVEC_SUB(&self->unk580, self->pos);
        cVec_copy3(&self->unk590, &ret_);
        self->unk590.y = 0.0f;
        CVEC_UNIT(&self->unk590);
        cVec_copy3(&self->unk590, &ret_);
        CVEC_MUL_SCALAR(self->unk590, 0.3f);
        self->timer = 90.0f;
        cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x20, self, 0, 0, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x24, self, 0, 0, 0, 0);
        self->step++;
        /* fallthrough */
    case 3:
        FLOAT_MUL(ret_, &self->unk590, self->speedRate);
        CVEC_FROM_RET(step);
        CVEC_ADD_TO(*self->pos, &step);
        cGameObj_SetTgtTurn((char *)self, &self->unk580, self->speedRate * EM_FLY_TURN_RATE);
        moveMotion(self);
        if (capVu0MagnitudeSqXZ(&self->unk580, self->pos) < 9.0f) {
            self->step = 4;
            break;
        }
        self->timer -= self->speedRate;
        if (self->timer <= 0.0f) {
            self->step = 4;
            break;
        }
        self->pos->y = self->pos->y * 0.9f + self->unk1738 * 0.1f;
        return;
    case 4:
        Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        self->step++;
        /* fallthrough */
    case 5:
        cGameObj_SetTgtTurn((char *)self, Getplayer()->pos, self->speedRate * EM_TURN_RATE);
        FLOAT_MUL(ret_, &self->unk590, self->speedRate);
        CVEC_FROM_RET(step);
        CVEC_ADD_TO(*self->pos, &step);
        CVEC_MUL_SCALAR(self->unk590, 1.0f - self->speedRate * 0.1f);
        if (capVu0LengthSq(&self->unk590) < 0.0004f) {
            go = 0;
            if ((irand() & 1) || self->stepArg != 0) {
                go = 1;
            }
            if (Getplayer()->hp <= 0) {
                go = 0;
            }
            if (cEmManage_CkPlSorry(&D_005864F0)) {
                go = 0;
            }
            if (cEmManage_CkPlCatched(&D_005864F0)) {
                go = 0;
            }
            if (go != 0) {
                if (func_0026F328(self) && (irand() & 1)) {
                    self->mode = 0;
                    self->phase = 0x82;
                    self->step = 0;
                    self->stepArg = 0;
                } else if (irand() & 1) {
                    self->mode = 0;
                    self->phase = 0x80;
                    self->step = 0;
                    self->stepArg = 0;
                } else {
                    self->mode = 0;
                    self->phase = 0x81;
                    self->step = 0;
                    self->stepArg = 0;
                }
            } else {
                self->step = 0;
                self->stepArg++;
            }
        }
        moveMotion(self);
        break;
    }
    if (self->unk172C <= 0.0f) {
        self->mode = 0;
        self->phase = EM_PHASE_FLOAT_END;
        self->step = 0;
        self->stepArg = 0;
        return;
    }
    bob = capVu0Sin(self->unk60C) * EM_BOB_HEIGHT;
    self->unk60C += self->speedRate * EM_BOB_STEP;
    self->unk60C = Adjust_theta(self->unk60C);
    self->pos->y += bob * self->speedRate;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00242B68);
#endif
