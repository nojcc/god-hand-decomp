#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern int cEmManage_CkPlSorry(void *a0);
extern int cEmManage_CkPlCatched(void *a0);
extern void func_00262750(void *a0, int a1);
extern void func_00274FE8(void *a0);
extern int GetSeqSEBase(void *a0);
extern unsigned char D_005864F0[];
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"
#define FRAME ((char *)va)
static __inline__ void vcopy(float *d, float *s)
{
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}
/* Phase machine on the step byte, 50 case labels. Calls CheckSlotsShort2FEAndSetByte1864_262A10,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, cCoreSave_getGameLevel, StoreMotionParamsBoth_2609A8,
 * func_002A8578, cGameObj_SetTgtTurn and 18 more. */
__attribute__((section(".text.func_002236E8"))) void func_002236E8(cEm00 *self)
{
    float va[8];
    int gb;
    int s2, motB;
    float one;

    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(self);
    switch (self->step) {
        case 0:
            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            switch (self->emNo) {
                default: {
                    char *v = self->pack;
                    s2 = EM_RES_REC((int)v, 0x98C);
                    motB = EM_RES_REC((int)v, 0x990);
                    if (cCoreSave_getGameLevel(&D_00569B70) >= 2) {
                        char *w = self->pack;
                        motB = EM_RES_REC((int)w, 0x994);
                    }
                    StoreMotionParamsBoth_2609A8(self, 0x28, 0xA, 0x41, 0, 0xF5);
                    *(int *)((char *)self + 0x5C0) = 0;
                    *(int *)((char *)self + 0x5C4) = 0;
                    self->home.z = 0.5f;
                    self->home.w = 1.0f;
                    switch (cCoreSave_getGameLevel(&D_00569B70)) {
                        case 1:
                        default:
                            self->home.z = 0.5f;
                            break;
                        case 2:
                            self->home.z = 0.75f;
                            break;
                        case 3:
                            self->home.z = 0.75f;
                            break;
                        case 4:
                            self->home.z = 0.75f;
                            break;
                        case 5:
                            self->home.z = 1.0f;
                            break;
                    }
                    switch (cCoreSave_getGameLevel(&D_00569B70)) {
                        case 1:
                        default:
                            self->timerA = 0x1E;
                            break;
                        case 2:
                            self->timerA = 0x23;
                            break;
                        case 3:
                            self->timerA = 0x28;
                            break;
                        case 4:
                            self->timerA = 0x28;
                            break;
                        case 5:
                            self->timerA = 0x3E7;
                            break;
                    }
                } break;
                case 0x250:
                case 0x251: {
                    char *v = self->pack;
                    s2 = EM_RES_REC((int)v, 0x19F4);
                    motB = EM_RES_REC((int)v, 0x19F8);
                    self->home.z = 0.400000006f;
                    if (cCoreSave_getGameLevel(&D_00569B70) >= 5) {
                        char *w = self->pack;
                        motB = EM_RES_REC((int)w, 0x19FC);
                        self->home.z = 0.75f;
                    }
                    StoreMotionParamsBoth_2609A8(self, 0x3C, 0xA, 0x44, 0, 0xF5);
                    *(int *)((char *)self + 0x5C0) = 0;
                    *(int *)((char *)self + 0x5C4) = 0;
                    self->home.z = 0.5f;
                    self->home.w = 1.0f;
                    switch (cCoreSave_getGameLevel(&D_00569B70)) {
                        case 1:
                        default:
                            self->home.z = 0.800000012f;
                            break;
                        case 2:
                            self->home.z = 1.20000005f;
                            break;
                        case 3:
                            self->home.z = 1.20000005f;
                            break;
                        case 4:
                            self->home.z = 1.20000005f;
                            break;
                        case 5:
                            self->home.z = 1.60000002f;
                            break;
                    }
                    switch (cCoreSave_getGameLevel(&D_00569B70)) {
                        case 1:
                        default:
                            self->timerA = 0x14;
                            break;
                        case 2:
                            self->timerA = 0x19;
                            break;
                        case 3:
                            self->timerA = 0x1E;
                            break;
                        case 4:
                            self->timerA = 0x1E;
                            break;
                        case 5:
                            self->timerA = 0x19;
                            break;
                    }
                } break;
            }
            func_002A8578(self, s2, motB, 10, 0.0f, gb, 0);
            self->timerC = 0;
            self->step += 1;
            /* fallthrough */
        case 1:
            if (self->timerA != 0) {
                self->timerA -= 1;
                cGameObj_SetTgtTurn(self, Getplayer()->pos,
                                    self->speedRate * 0.19634955f);
            }
            if (moveMotion(self) != 0)
                self->step += 1;
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
        case 2:
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            switch (self->emNo) {
                default: {
                    char *v = self->pack;
                    s2 = EM_RES_REC((int)v, 0x998);
                    motB = EM_RES_REC((int)v, 0x99C);
                } break;
                case 0x250:
                case 0x251: {
                    char *v = self->pack;
                    s2 = EM_RES_REC((int)v, 0x1A00);
                    motB = EM_RES_REC((int)v, 0x1A04);
                } break;
                case 0x24F:
                case 0x20C: {
                    char *v = self->pack;
                    s2 = EM_RES_REC((int)v, 0x1F68);
                    motB = EM_RES_REC((int)v, 0x1F6C);
                } break;
            }
            func_002A8578(self, s2, motB, 2, 0.0f, gb, 0);
            self->timerA = 4;
            self->posB.x = 99999.9f;
            self->posB.y = 99999.9f;
            self->posB.z = 99999.9f;
            self->step += 1;
            self->timerB = 0;
            /* fallthrough */
        case 3:
            if (moveMotion(self) != 0) {
                self->timerA -= 1;
                if (self->timerA <= 0) {
                    switch (self->emNo) {
                        case 0x20C:
                        case 0x24F:
                        case 0x250:
                        case 0x251:
                            self->step = 6;
                            break;
                        default:
                            self->step = 4;
                            break;
                    }
                }
            }
            {
                float k = self->speedRate;
                char *cp = FRAME + 0x10;
                VU0_LQC2(4, &self->home.x, 0);
                VU0_SQC2(4, FRAME, 0x10);
                VU0_LQC2(4, FRAME, 0x10);
                VU0_LOAD_SCALAR(5, k);
                VU0_VMULX_XYZ(4, 4, 5);
                VU0_SQC2(4, FRAME, 0x10);
                VU0_LQC2(4, cp, 0);
                VU0_SQC2(4, FRAME, 0);
                vcopy((float *)&self->nullSpeed.x, va);
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            if (*(int *)(*(int *)((char *)self + 0x670) + 0x34) != 0) {
                switch (self->emNo) {
                    case 0x250:
                    case 0x251:
                        break;
                    default:
                        self->step = 6;
                        break;
                }
            }
            if (self->unk1864 != 0)
                self->step = 6;
            if (cEmManage_CkPlSorry(D_005864F0) != 0 || cEmManage_CkPlCatched(D_005864F0) != 0)
                self->step = 6;
            if (func_00275888((cGameObj *)self, 2.0f) != 0) {
                self->step = 6;
                if (self->emNo >= 0x250 && self->emNo < 0x252) {
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5 &&
                        self->playerDist > 64.0f && self->stepArg == 0) {
                        self->stepArg = 1;
                        self->step = 8;
                    }
                }
            }
            func_00262750(self, 1);
            break;
        case 4:
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            {
                char *v = self->pack;
                func_002A8578(self, EM_RES_REC((int)v, 0x9A0), EM_RES_REC((int)v, 0x9A4), 2, 0.0f, gb,
                              0);
            }
            self->timerA = 5;
            self->step += 1;
            /* fallthrough */
        case 5:
            if (moveMotion(self) != 0) {
                func_00274FE8(self);
                return;
            }
            if (*(int *)(*(int *)((char *)self + 0x670) + 0x34) != 0)
                self->step = 6;
            self->home.z = self->home.z * 0.949999988f;
            vcopy((float *)&self->nullSpeed.x, (float *)&self->home.x);
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
        case 6:
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            switch (self->emNo) {
                case 0x20C:
                case 0x24F:
                case 0x250:
                case 0x251: {
                    char *v = self->pack;
                    s2 = EM_RES_REC((int)v, 0xCF0);
                    motB = EM_RES_REC((int)v, 0xCF4);
                } break;
                default: {
                    char *v = self->pack;
                    s2 = EM_RES_REC((int)v, 0x9A8);
                    motB = EM_RES_REC((int)v, 0x9AC);
                } break;
            }
            func_002A8578(self, s2, motB, 2, 0.0f, gb, 0);
            self->step += 1;
            self->timerA = 5;
            /* fallthrough */
        case 7:
            if (moveMotion(self) != 0 || ((self->seqFlags & 0x10) &&
                                        cCoreSave_getGameLevel(&D_00569B70) >= 2)) {
                switch (self->emNo) {
                    case 0x20C:
                    case 0x24F:
                    case 0x250:
                    case 0x251:
                        func_002705D8(self);
                        break;
                    default:
                        func_00274FE8(self);
                        break;
                }
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
        case 8:
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(self) + 6), self, 0, 0, 0, 0);
            {
                char *v = self->pack;
                func_002A8578(self, EM_RES_REC((int)v, 0x1A08), EM_RES_REC((int)v, 0x1A0C), 2, 0.0f,
                              gb, 0);
            }
            self->timerA = 5;
            self->step += 1;
            /* fallthrough */
        case 9:
            if (self->seqFlags & 0x10) {
                cGameObj_SetTgtTurn(self, Getplayer()->pos,
                                    self->speedRate * 0.392699093f);
            }
            if (moveMotion(self) != 0)
                self->step = 2;
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
    }
    func_00260B30(self);
    if (self->seqFlags & 3) {
        self->unk16F8 = 10;
        self->timerC = 1;
        self->emFlags |= 0x1000;
    }
    if (self->timerC != 0)
        self->emFlags2 &= 0xFFFFFBFF;
}
