/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/cOmWeapon.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern int irand(void);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern int cEmManage_CkPlCatched(void *a0);
extern unsigned char D_005864F0[];

/* sn-2.95.3-136 matched TU. */






















/* sn-2.95.3-136 matched TU. */

















__attribute__((section(".text.func_00213710")))
void func_00213710(cEm00 *self)
{
    int s2v, s0v;

    self->emFlags = self->emFlags | 0x400;
    switch (self->step) {
    case 0: {
        int gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        cOmWeapon *q;

        switch (self->emNo) {
        default:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0xC0) + b;
                s0v = *(int *)(b + 0xC4) + b;
            }
            break;
        case 0x202: case 0x203: case 0x213: case 0x216: case 0x217:
        case 0x229: case 0x22A: case 0x24B:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x660) + b;
                s0v = *(int *)(b + 0x664) + b;
            }
            break;
        case 0x242: case 0x243: case 0x244:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x35E4) + b;
                s0v = *(int *)(b + 0x35E8) + b;
            }
            break;
        case 0x256: case 0x27E:
            if ((self->emFlags2 & 0x4000000) != 0) {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x25F4) + b;
                s0v = *(int *)(b + 0x25F8) + b;
            } else {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x25EC) + b;
                s0v = *(int *)(b + 0x25F0) + b;
            }
            break;
        case 0x214: case 0x215:
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E:
        case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249:
        case 0x24C: case 0x24E: case 0x252: case 0x25A:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x10C0) + b;
                s0v = *(int *)(b + 0x10C4) + b;
            }
            break;
        case 0x225: case 0x24D:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x3CA0) + b;
                s0v = *(int *)(b + 0x3CA4) + b;
            }
            break;
        case 0x20A: case 0x20B: case 0x20D: case 0x20E: case 0x218:
        case 0x245: case 0x246: case 0x247:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x840) + b;
                s0v = *(int *)(b + 0x844) + b;
            }
            break;
        case 0x278: case 0x279:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x1FC8) + b;
                s0v = *(int *)(b + 0x1FCC) + b;
            }
            break;
        case 0x20C: case 0x24F:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x1EC4) + b;
                s0v = *(int *)(b + 0x1EC8) + b;
            }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x1578) + b;
                s0v = *(int *)(b + 0x157C) + b;
            }
            break;
        case 0x241:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x3A18) + b;
                s0v = *(int *)(b + 0x3A1C) + b;
            }
            break;
        case 0x209: case 0x21F:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x3430) + b;
                s0v = *(int *)(b + 0x3434) + b;
            }
            break;
        case 0x250: case 0x251:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x1908) + b;
                s0v = *(int *)(b + 0x190C) + b;
            }
            break;
        case 0x260:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x3050) + b;
                s0v = *(int *)(b + 0x3054) + b;
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
                if (64.0f < self->playerDist && (irand() & 1) != 0) {
                    int c = EM_RES(self);
                    cEm00 *t = self->unk744;
                    s0v = *(int *)(c + 0x373C) + c;
                    if (t != 0) {
                        ForwardAnimParamPairByIndex_27EA50(t, 5);
                    }
                } else {
                    int c = EM_RES(self);
                    cEm00 *t = self->unk744;
                    s0v = *(int *)(c + 0x3738) + c;
                    if (t != 0) {
                        ForwardAnimParamPairByIndex_27EA50(t, 4);
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
        case 0x20F:
            {
                int b;
                cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                                   (short)(GetSeqSEBase(self) + 6),
                                   self, 0, 0, 0, 0);
                b = EM_RES(self);
                s2v = *(int *)(b + 0xD10) + b;
                s0v = *(int *)(b + 0xD14) + b;
            }
            break;
        case 0x210: case 0x226:
            {
                int b;
                cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                                   (short)(GetSeqSEBase(self) + 6),
                                   self, 0, 0, 0, 0);
                b = EM_RES(self);
                s2v = *(int *)(b + 0xD38) + b;
                s0v = *(int *)(b + 0xD3C) + b;
            }
            break;
        case 0x211:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x2454) + b;
                s0v = *(int *)(b + 0x2458) + b;
            }
            break;
        case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x2154) + b;
                s0v = *(int *)(b + 0x2158) + b;
            }
            break;
        case 0x220: case 0x221: case 0x222:
            {
                int b;
                cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                                   (short)(GetSeqSEBase(self) + 0xA),
                                   self, 0, 0, 0, 0);
                b = EM_RES(self);
                s2v = *(int *)(b + 0x1BD0) + b;
                s0v = *(int *)(b + 0x1BD4) + b;
            }
            break;
        case 0x223:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x2D54) + b;
                s0v = *(int *)(b + 0x2D58) + b;
            }
            break;
        case 0x275: case 0x276:
            {
                int b = EM_RES(self);
                s2v = *(int *)(b + 0x228C) + b;
                s0v = *(int *)(b + 0x2290) + b;
            }
            break;
        }
        q = self->unk6EC;
        if (q != 0) {
            int b = EM_RES(self);
            s2v = *(int *)(b + 0x4B8) + b;
            s0v = *(int *)(b + 0x4BC) + b;
            if (q->base.actorId == 0x3B7) {
                s2v = *(int *)(b + 0x4F4) + b;
                s0v = *(int *)(b + 0x4F8) + b;
                cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x64, self, 0, 0, 0, 0);
            }
        }
        func_002A8578(self, s2v, s0v, 10, 0.0f, gb, 0);
        self->timerA = 0x5A;
        self->timerB = (int)((unsigned int)irand() % 60) + 0x78;
        self->step = self->step + 1;
    }
    case 1: {
        float one = 1.0f;
        float lim = 16.0f;
        int w;

        cGameObj_SetTgtTurn(self, (cVec *)&self->unk16A0,
                                         self->speedRate * 0.2617994f);
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            if (self->unk16D8 == 0) {
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
        switch (w) {
        case 0x264:
            lim = 1.0f;
            if (self->unk75C < 0.34906584f) {
                lim = 9.0f;
            }
            break;
        case 0x265:
            lim = 1.0f;
            break;
        }
        if (self->playerDist < lim) {
            func_002705D8(self);
        }
        if (self->timerA != 0) {
            self->timerA = self->timerA - 1;
        } else {
            switch (self->emNo) {
            case 0x20A: case 0x245: case 0x250: case 0x278: case 0x279:
                self->mode = 0;
                self->phase = 0x66;
                self->step = 0;
                self->stepArg = 0;
                break;
            default:
                break;
            }
        }
        switch (self->emNo) {
        case 0x20F: case 0x210: case 0x211:
        case 0x226:
        case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            if (self->timerB != 0) {
                self->timerB = self->timerB - 1;
            } else {
                self->timerB =
                    (int)((unsigned int)irand() % 60) + 0x78;
                cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                                   (short)(GetSeqSEBase(self) + 6),
                                   self, 0, 0, 0, 0);
            }
        case 0x220: case 0x221: case 0x222:
            if (self->timerB != 0) {
                self->timerB = self->timerB - 1;
            } else {
                self->timerB =
                    (int)((unsigned int)irand() % 60) + 0x78;
                cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                                   (short)(GetSeqSEBase(self) + 0xA),
                                   self, 0, 0, 0, 0);
            }
            break;
        default:
            break;
        }
        break;
    }
    }
    if (Getplayer()->hp <= 0
        || D_005864F0[0x5B5] != 0
        || cEmManage_CkPlCatched(D_005864F0) != 0) {
        func_002705D8(self);
    } else if (func_00262AA8(self) == 0 && func_0024BB68(self) == 0) {
        func_0024BDA0(self);
    }
}
