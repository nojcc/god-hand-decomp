/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
#include "godhand/cGameObj.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern unsigned int irand(void);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

/* Phase machine on the step byte, 73 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * cSnd_SeCall_2CBA48, GetSeqSEBase, func_002A8578, func_0026F120, cCoreSave_getGameLevel and 10
 * more. */
__attribute__((section(".text.func_0024F050"))) void func_0024F050(cEm00 *self)
{
    int s3;
    int s1;
    int s4;

    switch (self->step) {
        case 0:
            s4 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            if (self->unk17C3 != 0) {
                if (self->stepArg != 0)
                    self->stepArg = 0;
                else
                    self->stepArg = 1;
            }
            switch (self->emNo) {
                case 0x200:
                case 0x201:
                case 0x204:
                case 0x213:
                case 0x217:
                case 0x227:
                case 0x228:
                case 0x22B:
                case 0x23A:
                case 0x23B:
                case 0x240:
                case 0x242:
                case 0x243:
                case 0x244:
                case 0x24A:
                case 0x256:
                case 0x25B:
                case 0x27E: {
                    if (self->stepArg != 0) {
                        char *wa1 = self->pack;
                        s3 = EM_RES_REC(wa1, 0x300);
                        s1 = EM_RES_REC(wa1, 0x304);
                    } else {
                        char *wb1 = self->pack;
                        s3 = EM_RES_REC(wb1, 0x2F8);
                        s1 = EM_RES_REC(wb1, 0x2FC);
                    }
                    break;
                }
                default: {
                    if (self->stepArg != 0) {
                        char *wa2 = self->pack;
                        s3 = EM_RES_REC(wa2, 0x820);
                        s1 = EM_RES_REC(wa2, 0x824);
                    } else {
                        char *wb2 = self->pack;
                        s3 = EM_RES_REC(wb2, 0x818);
                        s1 = EM_RES_REC(wb2, 0x81C);
                    }
                    break;
                }
                case 0x20A:
                case 0x20B:
                case 0x20C:
                case 0x20D:
                case 0x20E:
                case 0x218:
                case 0x245:
                case 0x246:
                case 0x247:
                case 0x24F:
                case 0x278:
                case 0x279: {
                    if (self->stepArg != 0) {
                        char *wa3 = self->pack;
                        s3 = EM_RES_REC(wa3, 0x9E8);
                        s1 = EM_RES_REC(wa3, 0x9EC);
                    } else {
                        char *wb3 = self->pack;
                        s3 = EM_RES_REC(wb3, 0x9E0);
                        s1 = EM_RES_REC(wb3, 0x9E4);
                    }
                    break;
                }
                case 0x250:
                case 0x251: {
                    if (self->stepArg != 0) {
                        char *we = self->pack;
                        s3 = EM_RES_REC(we, 0x9E8);
                        s1 = EM_RES_REC(we, 0x9EC);
                    } else {
                        char *wf = self->pack;
                        s3 = EM_RES_REC(wf, 0x9E0);
                        s1 = EM_RES_REC(wf, 0x9E4);
                    }
                    cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(self) + 0x23), self, 0, 0, 0,
                                       0);
                    break;
                }
                case 0x260: {
                    if (self->stepArg != 0) {
                        char *wa5 = self->pack;
                        s3 = EM_RES_REC(wa5, 0x3144);
                        s1 = EM_RES_REC(wa5, 0x3148);
                    } else {
                        char *wb5 = self->pack;
                        s3 = EM_RES_REC(wb5, 0x3144);
                        s1 = EM_RES_REC(wb5, 0x3148);
                        s4 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
                    }
                    break;
                }
                case 0x264: {
                    if (self->stepArg != 0) {
                        char *wa6 = self->pack;
                        s3 = EM_RES_REC(wa6, 0x3310);
                        s1 = EM_RES_REC(wa6, 0x3314);
                    } else {
                        char *wb6 = self->pack;
                        s3 = EM_RES_REC(wb6, 0x3308);
                        s1 = EM_RES_REC(wb6, 0x330C);
                    }
                    break;
                }
                case 0x265: {
                    if (self->stepArg != 0) {
                        char *wa7 = self->pack;
                        s3 = EM_RES_REC(wa7, 0x3888);
                        s1 = EM_RES_REC(wa7, 0x388C);
                    } else {
                        char *wb7 = self->pack;
                        s3 = EM_RES_REC(wb7, 0x3880);
                        s1 = EM_RES_REC(wb7, 0x3884);
                    }
                    break;
                }
                case 0x205:
                case 0x206:
                case 0x207:
                case 0x208:
                case 0x224: {
                    if (self->stepArg != 0) {
                        char *wa8 = self->pack;
                        s3 = EM_RES_REC(wa8, 0x16A0);
                        s1 = EM_RES_REC(wa8, 0x16A4);
                    } else {
                        char *wb8 = self->pack;
                        s3 = EM_RES_REC(wb8, 0x1698);
                        s1 = EM_RES_REC(wb8, 0x169C);
                    }
                    break;
                }
                case 0x241: {
                    if (self->stepArg != 0) {
                        char *wa9 = self->pack;
                        s3 = EM_RES_REC(wa9, 0x3AA4);
                        s1 = EM_RES_REC(wa9, 0x3AA8);
                    } else {
                        char *wb9 = self->pack;
                        s3 = EM_RES_REC(wb9, 0x3A9C);
                        s1 = EM_RES_REC(wb9, 0x3AA0);
                    }
                    break;
                }
                case 0x209:
                case 0x21F: {
                    if (self->stepArg != 0) {
                        char *wa10 = self->pack;
                        s3 = EM_RES_REC(wa10, 0x16A0);
                        s1 = EM_RES_REC(wa10, 0x16A4);
                    } else {
                        char *wb10 = self->pack;
                        s3 = EM_RES_REC(wb10, 0x1698);
                        s1 = EM_RES_REC(wb10, 0x169C);
                    }
                    break;
                }
                case 0x220:
                case 0x221:
                case 0x222: {
                    if (self->stepArg != 0) {
                        char *wa11 = self->pack;
                        s3 = EM_RES_REC(wa11, 0x820);
                        s1 = EM_RES_REC(wa11, 0x824);
                    } else {
                        char *wb11 = self->pack;
                        s3 = EM_RES_REC(wb11, 0x818);
                        s1 = EM_RES_REC(wb11, 0x81C);
                    }
                    break;
                }
                case 0x223: {
                    char *w = self->pack;
                    s3 = EM_RES_REC(w, 0x2E4C);
                    s1 = EM_RES_REC(w, 0x2E50);
                    break;
                }
                case 0x214:
                case 0x215:
                case 0x21A:
                case 0x21B:
                case 0x21C:
                case 0x21D:
                case 0x21E:
                case 0x225:
                case 0x22C:
                case 0x22D:
                case 0x22E:
                case 0x22F:
                case 0x248:
                case 0x249:
                case 0x24C:
                case 0x24D:
                case 0x24E:
                case 0x252:
                case 0x25A: {
                    if (self->stepArg != 0) {
                        char *wa12 = self->pack;
                        s3 = EM_RES_REC(wa12, 0x1260);
                        s1 = EM_RES_REC(wa12, 0x1264);
                    } else {
                        char *wb12 = self->pack;
                        s3 = EM_RES_REC(wb12, 0x1258);
                        s1 = EM_RES_REC(wb12, 0x125C);
                    }
                    break;
                }
            }
            if (self->unk6EC != 0) {
                if (self->stepArg != 0) {
                    char *wc = self->pack;
                    s3 = EM_RES_REC(wc, 0x820);
                    s1 = EM_RES_REC(wc, 0x824);
                } else {
                    char *wd = self->pack;
                    s3 = EM_RES_REC(wd, 0x818);
                    s1 = EM_RES_REC(wd, 0x81C);
                }
            }
            func_002A8578(self, s3, s1, 2, 0.0f, s4, 0);
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)GetSeqSEBase(self), self, 0, 0, 0, 0);
            func_0026F120(self);
            self->timerA = 0;
            {
                cDamageTake *take = self->unk698;
                if (take != 0) {
                    cGameObj *atk = take->attacker;
                    if (atk != 0) {
                        cVec *d = &self->posB;
                        cVec *src;
                        self->timerA = 0xA;
                        src = atk->pos;
                        if (d != src) {
                            self->posB.x = src->x;
                            d->y = src->y;
                            d->z = src->z;
                        }
                    }
                }
            }
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                default:
                case 1:
                    self->timerB = 0x3E7;
                    break;
                case 2:
                    self->timerB = irand() % 15U + 0x14;
                    break;
                case 3:
                    self->timerB = irand() % 15U + 0xF;
                    break;
                case 4:
                    self->timerB = irand() % 15U + 0xF;
                    break;
                case 5:
                    self->timerB = irand() % 15U + 0xA;
                    break;
            }
            self->step = self->step + 1;
            /* fallthrough */
        case 1:
            if (self->emNo != 0x264) {
                int t = self->timerA;
                if (t != 0) {
                    self->timerA = t - 1;
                    cGameObj_SetTgtTurn(self, &self->posB, self->speedRate * 0.3926991f);
                }
            }
            if (moveMotion(self)) {
                if (func_0026F1D8(self))
                    func_00270C78(self);
                else
                    func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (self->seqFlags & 0x10)
                self->timerB = 0;
            {
                int u = self->timerB;
                if (u != 0) {
                    self->timerB = u - 1;
                } else if (!func_0026F1D8(self)) {
                    if (irand() % 12U == 0 && self->playerDist < 9.0f && D_005CB010 == 0 &&
                        self->unk17BB != 0 && self->unk1740 <= 0.0f)
                        func_00274238(self, 0);
                    else
                        func_00262AA8(self);
                }
            }
            break;
        default:
            break;
    }
}
