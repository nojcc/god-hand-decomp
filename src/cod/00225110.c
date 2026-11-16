#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cEmManage.h"
#include "godhand/player.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_00262750(void *a0, int a1);

/* sn-2.95.3-136 matched TU. */

















#include "godhand/vu0.h"
#include "godhand/cGameObj.h"

#define FRAME ((char *)va - 0x30)

/* Phase machine on the step byte, 6 case labels. Calls VU0_LQC2, VU0_SQC2, VU0_SQC2_VF0,
 * CheckSlotsShort2FEAndSetByte1864_262A10, Obj0000_Get_Byte_17C3_NZ_2_276468,
 * StoreMotionParamsBoth_2609A8 and 14 more. */
__attribute__((section(".text.func_00225110"))) void func_00225110(cEm00 *self)
{
    float va[4], vb[4], vc[4], vd[4], ve[4];
    cVec *p = self->pos;

    VU0_LQC2(4, p, 0);
    VU0_SQC2(4, FRAME, 0x30);
    VU0_LQC2(4, p, 0);
    VU0_SQC2(4, FRAME, 0x40);
    VU0_SQC2_VF0(FRAME, 0x50);
    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(self);
    switch (self->step) {
        case 0: {
            int gb;
            char *v0;
            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            StoreMotionParamsBoth_2609A8(self, 0x28, 0xA, 0x41, 0, 0xF5);
            v0 = self->pack;
            func_002A8578(self, EM_RES_REC(v0, 0x974), EM_RES_REC(v0, 0x978), 0xA, 0.0f, gb,
                          0);
            self->timerC = 0;
            self->step += 1;
        }
            /* fallthrough */
        case 1: {
            cGameObj *o = Getplayer();
            cGameObj_SetTgtTurn(self, o->pos, self->speedRate * 0.19634955f);
            if (moveMotion(self) != 0) {
                self->step += 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
        case 2: {
            int gb;
            char *v1;
            float z = 0.0f;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            v1 = self->pack;
            func_002A8578(self, EM_RES_REC(v1, 0x97C), EM_RES_REC(v1, 0x980), 2, z, gb, 0);
            self->unk580.x = z;
            self->unk580.z = 0.2f;
            self->unk580.y = self->unk170C * 15.0f;
            self->timer = z;
            self->timerA = 4;
            self->step += 1;
        }
            /* fallthrough */
        case 3: {
            float dt;
            float *dp;
            char *ep;

            self->emFlags |= 0x10000;
            moveMotion(self);
            dt = self->speedRate;
            ep = (char *)ve;
            VU0_LQC2(4, &self->unk580, 0);
            VU0_SQC2(4, FRAME, 0x70);
            VU0_LQC2(4, FRAME, 0x70);
            VU0_LOAD_SCALAR(5, dt);
            VU0_VMULX_XYZ(4, 4, 5);
            VU0_SQC2(4, FRAME, 0x70);
            VU0_LQC2(4, ep, 0);
            VU0_SQC2(4, FRAME, 0x60);
            dp = &self->nullSpeed.x;
            if (dp != vd) {
                float t0, t1, t2;
                t0 = vd[0];
                t1 = vd[1];
                dp[0] = t0;
                *(volatile float *)&dp[1] = t1;
                t2 = *(volatile float *)&vd[2];
                dp[2] = t2;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (self->unk580.y <= 0.0f) {
                cVec *q = self->pos;
                va[1] = va[1] + 0.5f;
                vb[1] = q->y - 10.0f;
                if (ChkLine(va, vb, vc, 0, 2, 0x400, 0, 0, 0, 0, 0, 0, 1) == 1) {
                    cVec *r = self->pos;
                    if (r->y <= vc[1] + 0.01f) {
                        int n;
                        r->y = vc[1];
                        self->timer = 3.0f;
                        self->unk580.y = self->unk170C * 15.0f;
                        n = self->timerA - 1;
                        self->timerA = n;
                        if (n <= 0) {
                            self->step = 4;
                        }
                    }
                }
            } else {
                cVec *q;
                VU0_SQC2_VF0(FRAME, 0x60);
                q = self->pos;
                vb[1] = q->y + 10.0f;
                if (ChkLine(va, vb, vd, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                    cVec *r = self->pos;
                    float h = vd[1] - 1.5f;
                    if (h < r->y) {
                        r->y = h;
                        self->unk580.y = 0.0f;
                    }
                }
            }
            self->unk580.y =
                self->unk580.y - self->unk170C * self->speedRate;
            if (0.0f < self->timer) {
                self->timer = self->timer - self->speedRate;
                if (36.0f < self->playerDist) {
                    cGameObj *o = Getplayer();
                    cGameObj_SetTgtTurn(self, o->pos,
                                        self->speedRate * 0.5235988f);
                }
            }
            if (self->playerDist < 16.0f) {
                if (self->timerA >= 2) {
                    self->timerA = 1;
                }
            }
            if (cEmManage_CkPlSorry(&D_005864F0) != 0 || cEmManage_CkPlCatched(&D_005864F0) != 0) {
                self->unk1864 = 1;
            }
            if (self->unk1864 != 0) {
                self->timerA = 0;
            }
            func_00262750(self, 1);
            break;
        }
        case 4: {
            int gb;
            char *v1;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            v1 = self->pack;
            func_002A8578(self, EM_RES_REC(v1, 0x984), EM_RES_REC(v1, 0x988), 2, 0.0f, gb,
                          0);
            self->step += 1;
        }
            /* fallthrough */
        case 5:
            if (moveMotion(self) != 0) {
                func_002705D8(self);
                return;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
    func_00260B30(self);
    if (self->seqFlags & 3) {
        self->unk16F8 = 0xA;
        self->timerC = 1;
        self->emFlags |= 0x1000;
    }
    if (self->timerC != 0) {
        self->emFlags2 &= 0xFFFFFBFF;
    }
}
