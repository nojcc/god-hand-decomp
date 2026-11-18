/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern unsigned int irand(void);
extern int GetSeqSEBase(void *a0);
extern int cEmManage_CkPlCatched(void *a0);
extern unsigned char D_005864F0[];

/* sn-2.95.3-136 matched TU. */






















__attribute__((section(".text.func_002130C8")))
void func_002130C8(cEm00 *self)
{
    int flag = 1;
    int s2v, s0v, gb;

    switch (self->emNo) {
    case 0x20F: case 0x210: case 0x211:
    case 0x226:
    case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
        break;
    default:
        self->emFlags = self->emFlags | 0x400;
        break;
    }

    switch (self->step) {
    case 0:
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        switch (self->emNo) {
        default:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0xB0) + b;
                s0v = *(int *)(b + 0xB4) + b;
            }
            break;
        case 0x202: case 0x203:
        case 0x213:
        case 0x216: case 0x217:
        case 0x229: case 0x22A:
        case 0x24B:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x650) + b;
                s0v = *(int *)(b + 0x654) + b;
            }
            break;
        case 0x242: case 0x243: case 0x244:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x35D4) + b;
                s0v = *(int *)(b + 0x35D8) + b;
            }
            break;
        case 0x256:
        case 0x27E:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x25DC) + b;
                s0v = *(int *)(b + 0x25E0) + b;
            }
            break;
        case 0x214: case 0x215:
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E:
        case 0x22C: case 0x22D: case 0x22E: case 0x22F:
        case 0x248: case 0x249:
        case 0x24C:
        case 0x24E:
        case 0x252:
        case 0x25A:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x10B0) + b;
                s0v = *(int *)(b + 0x10B4) + b;
            }
            break;
        case 0x225:
        case 0x24D:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x3C90) + b;
                s0v = *(int *)(b + 0x3C94) + b;
            }
            break;
        case 0x20A: case 0x20B:
        case 0x20D: case 0x20E:
        case 0x218:
        case 0x245: case 0x246: case 0x247:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x830) + b;
                s0v = *(int *)(b + 0x834) + b;
            }
            break;
        case 0x278: case 0x279:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x1FB8) + b;
                s0v = *(int *)(b + 0x1FBC) + b;
            }
            break;
        case 0x20C:
        case 0x24F:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x1EB4) + b;
                s0v = *(int *)(b + 0x1EB8) + b;
            }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208:
        case 0x224:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x1568) + b;
                s0v = *(int *)(b + 0x156C) + b;
            }
            break;
        case 0x241:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x3A08) + b;
                s0v = *(int *)(b + 0x3A0C) + b;
            }
            break;
        case 0x209:
        case 0x21F:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x3420) + b;
                s0v = *(int *)(b + 0x3424) + b;
            }
            break;
        case 0x250: case 0x251:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x18F8) + b;
                s0v = *(int *)(b + 0x18FC) + b;
            }
            break;
        case 0x260:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x3040) + b;
                s0v = *(int *)(b + 0x3044) + b;
            }
            break;
        case 0x264:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x3274) + b;
                s0v = *(int *)(b + 0x3278) + b;
            }
            break;
        case 0x265:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x3734) + b;
                if (self->playerDist > 64.0f && (irand() & 1) != 0) {
                    int b2 = EM_RES(self);
                    cEm00 *t2 = self->unk744;
                    s0v = *(int *)(b2 + 0x373C) + b2;
                    if (t2 != 0) {
                        ForwardAnimParamPairByIndex_27EA50(t2, 5);
                    }
                } else {
                    int b3 = EM_RES(self);
                    cEm00 *t3 = self->unk744;
                    s0v = *(int *)(b3 + 0x3738) + b3;
                    if (t3 != 0) {
                        ForwardAnimParamPairByIndex_27EA50(t3, 4);
                    }
                }
            }
            break;
        case 0x26A:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x3D34) + b;
                s0v = *(int *)(b + 0x3D38) + b;
            }
            break;
        case 0x20F: case 0x210: case 0x211:
        case 0x226:
        case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0xD00) + b;
                s0v = *(int *)(b + 0xD04) + b;
            }
            break;
        case 0x220: case 0x221: case 0x222:
            {
                int b;
                cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                                   (short)(GetSeqSEBase(self) + 0xA),
                                   self, 0, 0, 0, 0);
                b = EM_RES(self);
                s2v = *(int *)(b + 0x1BC8) + b;
                s0v = *(int *)(b + 0x1BCC) + b;
            }
            break;
        case 0x223:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x2D48) + b;
                s0v = *(int *)(b + 0x2D4C) + b;
            }
            break;
        case 0x275: case 0x276:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x227C) + b;
                s0v = *(int *)(b + 0x2280) + b;
            }
            break;
        }
        if (*(int *)((char *)self + 0x6EC) != 0) {
            int b = EM_RES(self);
            s2v = *(int *)(b + 0x454) + b;
            s0v = *(int *)(b + 0x458) + b;
        }
        func_002A8578(self, s2v, s0v, 10, 0.0f, gb, 0);
        self->timerB = irand() % 60 + 0x78;
        self->step = self->step + 1;
    case 1:
        cGameObj_SetTgtTurn(self, (cVec *)&self->unk16A0.x,
                                         self->speedRate * 0.09817477f);
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if ((self->seqFlags & 0x20) != 0) {
            flag = 0;
        }
        if (flag != 0) {
            float lim = 16.0f;
            int w;

            switch (self->emNo) {
            case 0x264:
                if (self->unk75C < 0.34906584f) {
                    lim = 9.0f;
                } else {
                    lim = 1.0f;
                }
                break;
            case 0x265:
                lim = 1.0f;
                break;
            case 0x266:
                break;
            }
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
            default:
            case 1:
                if (self->unk16D8 < 1) {
                    lim = 2.25f;
                }
                break;
            case 2:
                if (self->unk16D8 < 2) {
                    lim = 2.25f;
                }
                break;
            case 3:
                if (self->unk16D8 < 3) {
                    lim = 2.25f;
                }
                break;
            case 4:
                if (self->unk16D8 < 3) {
                    lim = 2.25f;
                }
                break;
            case 5:
                if (self->unk16D8 < 3) {
                    lim = 2.25f;
                }
                break;
            }
            if (self->unk16D8 >= 3) {
                lim = 49.0f;
            }
            if (self->unk16D8 >= 6) {
                lim = 121.0f;
            }
            w = self->emNo;
            if (w == 0x264) {
                lim = 64.0f;
            }
            if (self->playerDist < lim) {
                func_002705D8(self);
                return;
            }
        }
        {
            int w2 = self->emNo;
            if (w2 < 0x223) {
              if (w2 >= 0x220) {
                if (self->timerB != 0) {
                    self->timerB = self->timerB - 1;
                } else {
                    self->timerB = irand() % 60 + 0x78;
                    cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                                       (short)(GetSeqSEBase(self) + 0xA),
                                       self, 0, 0, 0, 0);
                }
              }
            }
        }
        break;
    }

    if (Getplayer()->hp <= 0
        || D_005864F0[0x5B5] != 0
        || cEmManage_CkPlCatched(D_005864F0) != 0) {
        func_002705D8(self);
    } else if (flag == 0 || func_00262AA8(self) == 0) {
        if (self->unk16EC > 0) {
            if (self->playerDist > 64.0f) {
                if ((unsigned int)(self->emNo - 0x250) < 2) {
                    self->mode = 0;
                    self->phase = 0xB;
                    self->step = 0;
                    self->stepArg = 0;
                } else {
                    self->mode = 0;
                    self->phase = 6;
                    self->step = 0;
                    self->stepArg = 0;
                }
            } else {
                self->mode = 0;
                self->phase = 6;
                self->step = 0;
                self->stepArg = 0;
            }
        } else if (func_0024BB68(self) == 0) {
            func_0024BDA0(self);
        }
    }
}
