/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

extern int irand(void);
extern int GetSeqSEBase(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern float Turn_dest(void *a0, float f12, float f13, void *a1);
extern float Adjust_theta(float f12);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern float SetMotionStep(void *a0, float f12);
extern void Obj293_OrByte_5A3(void *a0, int a1);
extern void Obj293_OrByte_5A4(void *a0, int a1);
extern void Obj293_OrByte_5A5_1(void *a0);
extern void Obj293_ClearBytes_5A0_5A3(void *a0);
extern int D_005864F0;

/* sn-2.95.3-136 matched TU. */


























/* sn-2.95.3-136 matched TU. */


/* Phase machine on the step byte, 14 case labels. Calls func_002A8578, cSnd_SeCall_2CBA48,
 * GetSeqSEBase, cGameObj_SetTgtTurn, moveMotion, cObjBase_addNullSpeed_Rotation and 16 more. */
__attribute__((section(".text.func_0022C3F8"))) void func_0022C3F8(cEm00 *self)
{
    char *s2;
    int flag = 0;

    self->emFlags2 |= 4;
    if (self->emNo == 0x214) {
        char *g = (char *)&D_005864F0;

        s2 = *(char **)(g + 0x564);
    } else {
        char *g = (char *)&D_005864F0;

        s2 = *(char **)(g + 0x560);
    }
    if (self->step == 0xB) {
        char *g = (char *)&D_005864F0;

        if (*(unsigned char *)(g + 0x5A2) != 0) {
            self->step = 0xC;
        }
    }
    if (s2 != 0) {
        if ((*(long *)(s2 + 0x2F0) & 0xFFFF00000000L) == 0x3C0000000000L) {
            flag = 1;
        } else {
            flag = 0;
        }
    }
    switch (self->step) {
        case 0: {
            char *b = self->pack;

            self->unk1864 = 0;
            func_002A8578(self, EM_RES_REC((int)b, 0x10C0), EM_RES_REC((int)b, 0x10C8), 0xA, 0.0f, 0,
                          0);
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(self) + 0xA), self, 0, 0, 0, 0);
            self->timer = 150.0f;
            self->step += 1;
        }
            /* fallthrough */
        case 1: {
            cVec *m = &self->unk580;

            cGameObj_SetTgtTurn(self, m, self->speedRate * 0.196349546f);
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (capVu0MagnitudeSqXZ(m, self->pos) < 1.0f) {
                self->step += 1;
            }
            self->timer = self->timer - self->speedRate;
            if (s2 == 0 || self->timer <= 0.0f) {
                char *g = (char *)&D_005864F0;

                Obj293_ClearBytes_5A0_5A3(g);
                func_002705D8(self);
            }
            break;
        }
        case 2: {
            char *b = self->pack;

            func_002A8578(self, EM_RES_REC((int)b, 0x1A98), EM_RES_REC((int)b, 0x1A9C), 0xA, 0.0f, 0,
                          0);
            {
                char *g = (char *)&D_005864F0;

                if (self->emNo == 0x214) {
                    Obj293_OrByte_5A3(g, 1);
                } else {
                    Obj293_OrByte_5A3(g, 2);
                }
            }
            self->timer = 90.0f;
            self->step += 1;
        }
            /* fallthrough */
        case 3:
            if (s2 != 0) {
                cGameObj_SetTgtTurn(self, *(cVec **)(s2 + 0xF0), self->speedRate * 0.196349546f);
            }
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            self->timer = self->timer - self->speedRate;
            if (s2 == 0 || self->timer <= 0.0f) {
                goto L784;
            }
            {
                char *g = (char *)&D_005864F0;

                if (*(unsigned char *)(g + 0x5A0) != 0) {
                    self->step += 1;
                }
            }
            break;
        case 4:
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                self->timer = 16.0f;
            } else {
                self->timer = 45.0f;
            }
            self->step += 1;
            /* fallthrough */
        case 5:
            if (s2 != 0) {
                cGameObj_SetTgtTurn(self, *(cVec **)(s2 + 0xF0), self->speedRate * 0.196349546f);
            }
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (s2 != 0) {
                goto L79C;
            }
        L784:
            {
                char *g = (char *)&D_005864F0;

                Obj293_ClearBytes_5A0_5A3(g);
            }
            func_002705D8(self);
            break;
        L79C:
            self->timer = self->timer - self->speedRate;
            if (self->timer <= 0.0f) {
                self->step += 1;
            }
            break;
        case 6: {
            char *b;
            char *g = (char *)&D_005864F0;

            if (self->emNo == 0x214) {
                Obj293_OrByte_5A4(g, 1);
            } else {
                Obj293_OrByte_5A4(g, 2);
            }
            b = self->pack;
            func_002A8578(self, EM_RES_REC((int)b, 0x1AA0), EM_RES_REC((int)b, 0x1AA4), 3, 0.0f, 0,
                          0);
            self->step += 1;
        }
            /* fallthrough */
        case 7:
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            {
                char *g = (char *)&D_005864F0;

                if (*(unsigned char *)(g + 0x5A1) != 0) {
                    self->step += 1;
                }
            }
            break;
        case 8: {
            char *b = self->pack;

            func_002A8578(self, EM_RES_REC((int)b, 0x1AB0), EM_RES_REC((int)b, 0x1AB4), 0, 0.0f, 0,
                          0);
            self->step += 1;
        }
            /* fallthrough */
        case 9:
            if (moveMotion(self) != 0) {
                self->step += 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            goto LA64;
        case 10: {
            char *b = self->pack;

            func_002A8578(self, EM_RES_REC((int)b, 0x1AC0), EM_RES_REC((int)b, 0x1AC4), 0, 0.0f, 0,
                          0);
            self->timer2 = 1.0f;
            self->step += 1;
        }
            /* fallthrough */
        case 11: {
            float acc;
            float theta;
            float turn;

            acc = self->timer2 + self->speedRate * 0.0199999996f;
            self->timer2 = acc;
            if (2.0f < acc) {
                self->timer2 = 2.0f;
            }
            SetMotionStep(self, *(float *)(s2 + 0x5A8) * self->timer2);
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (2.0f <= self->timer2) {
                theta = Adjust_theta(self->rot.y + 3.14159274f);
                {
                    cVec *o = self->pos;
                    cGameObj *r = Getplayer();

                    turn = Turn_dest(o, theta, 3.14159274f, r->pos);
                }
                if (irand() & 1) {
                    if (-0.785398185f < turn) {
                        if (turn < -0.261799395f) {
                            char *g = (char *)&D_005864F0;

                            Obj293_OrByte_5A5_1(g);
                            *(float *)(g + 0x59C) = Adjust_theta(theta + turn);
                        }
                    }
                }
            }
        LA64:
            if (self->seqFlags & 1) {
                StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3F, -1, 0);
                func_00260B30(self);
            }
            if (flag != 0) {
                break;
            }
            self->mode = 1;
            self->phase = 0x11;
            self->step = 0;
            self->stepArg = 0;
            return;
        }
        case 12: {
            char *b;
            char *g = (char *)&D_005864F0;

            self->rot.y = *(float *)(g + 0x59C) + 3.14159274f;
            self->rot.y = Adjust_theta(self->rot.y);
            b = self->pack;
            func_002A8578(self, EM_RES_REC((int)b, 0x1AD0), EM_RES_REC((int)b, 0x1AD4), 0, 0.0f, 0,
                          0);
            self->step += 1;
        }
            /* fallthrough */
        case 13:
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (self->seqFlags & 1) {
                StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3F, -1, 0);
                func_00260B30(self);
            }
            break;
    }
    if (self->seqFlags & 0x20) {
        cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    }
}
