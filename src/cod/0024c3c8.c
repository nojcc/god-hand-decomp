/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cObjBase.h"
#include "godhand/cGameObj.h"
#include "godhand/cCamera.h"
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"
#include "godhand/rand.h"
#include "godhand/angle.h"
#include "godhand/player.h"

/* Wait step machine. Before step 0 an enemy 0x241 may switch to step 4, and an
 * attacker more than 135 degrees off the facing sends it to step 2. Step 0
 * may drop the held weapon, plays the wait motion picked by the enemy number
 * and aims at the player or the attacker; step 1 turns, waits on timerB and
 * then tries an attack, and on timer2 may act after three waits. Step 2 plays
 * the turning wait motion, sometimes from frame 10, turns by up to 30 degrees
 * and sets timerB from the game level; step 3 waits like step 1. Steps 4 and 5
 * play enemy 0x241's motion turning toward the player. */
__attribute__((section(".text.func_0024C3C8")))
void func_0024C3C8(cEm00 *self)
{
    float start = 0.0f;
    cDamageTake *hit;
    int ma;
    int mb;
    unsigned short sel;
    int go;

    if (self->step == 0) {
        if (self->emNo == 0x241 && self->stepArg == 0 && func_0026F1D8(self) == 0
            && (irand() & 3) == 0) {
            self->step = 4;
        }
        hit = self->unk698;
        if (hit != 0 && hit->attacker != 0) {
            float turn = Turn_dest(&self->pos->x, &((cGameObj *)hit->attacker)->pos->x,
                                   self->rot.y, 3.1415927f);

            turn = absf(turn);
            if (turn > 2.3561945f) {
                self->step = 2;
            }
        }
    }
    switch (self->step) {
    case 0:
        if (self->unk6EC != 0) {
            switch (self->emNo) {
            case 0x227: case 0x228: case 0x229: case 0x22A: case 0x22B:
            case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x23A:
            case 0x24A: case 0x24B: case 0x25A:
                break;
            default:
                if ((irand() & 7) == 0) {
                    ReleaseField6ECByTag564_26B1E8(self);
                }
                break;
            }
            if (self->stepArg != 0) {
                ReleaseField6ECByTag564_26B1E8(self);
            }
        }
        switch (self->emNo) {
        case 0x200: case 0x201: case 0x204: case 0x213: case 0x217:
        case 0x227: case 0x228: case 0x22B: case 0x23A: case 0x23B:
        case 0x240: case 0x242: case 0x243: case 0x244: case 0x24A:
        case 0x25B:
            if (irand() & 1) {
                ma = EM_RES_REC(self->resource, 0x2D0);
                mb = EM_RES_REC(self->resource, 0x2D4);
            } else {
                ma = EM_RES_REC(self->resource, 0x2D8);
                mb = EM_RES_REC(self->resource, 0x2DC);
            }
            break;
        case 0x256: case 0x27E:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                ma = EM_RES_REC(self->resource, 0x26D8);
                mb = EM_RES_REC(self->resource, 0x26DC);
                break;
            case 1:
                ma = EM_RES_REC(self->resource, 0x29F0);
                mb = EM_RES_REC(self->resource, 0x29F4);
                break;
            case 2:
                ma = EM_RES_REC(self->resource, 0x29E8);
                mb = EM_RES_REC(self->resource, 0x29EC);
                break;
            }
            break;
        default:
            if (irand() & 1) {
                ma = EM_RES_REC(self->resource, 0x774);
                mb = EM_RES_REC(self->resource, 0x778);
            } else {
                ma = EM_RES_REC(self->resource, 0x77C);
                mb = EM_RES_REC(self->resource, 0x780);
            }
            break;
        case 0x214: case 0x215: case 0x21A: case 0x21B: case 0x21C:
        case 0x21D: case 0x21E: case 0x225: case 0x22C: case 0x22D:
        case 0x22E: case 0x22F: case 0x248: case 0x249: case 0x24C:
        case 0x24D: case 0x24E: case 0x252: case 0x25A:
            if (irand() & 1) {
                ma = EM_RES_REC(self->resource, 0x1238);
                mb = EM_RES_REC(self->resource, 0x123C);
            } else {
                ma = EM_RES_REC(self->resource, 0x1240);
                mb = EM_RES_REC(self->resource, 0x1244);
            }
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
        case 0x218: case 0x245: case 0x246: case 0x247: case 0x24F:
        case 0x278: case 0x279:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                ma = EM_RES_REC(self->resource, 0x9B0);
                mb = EM_RES_REC(self->resource, 0x9B4);
                break;
            case 1:
                ma = EM_RES_REC(self->resource, 0x9B8);
                mb = EM_RES_REC(self->resource, 0x9BC);
                break;
            case 2:
                ma = EM_RES_REC(self->resource, 0x9C0);
                mb = EM_RES_REC(self->resource, 0x9C4);
                break;
            }
            break;
        case 0x250: case 0x251:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                ma = EM_RES_REC(self->resource, 0x9B0);
                mb = EM_RES_REC(self->resource, 0x9B4);
                break;
            case 1:
                ma = EM_RES_REC(self->resource, 0x9B8);
                mb = EM_RES_REC(self->resource, 0x9BC);
                break;
            case 2:
                ma = EM_RES_REC(self->resource, 0x9C0);
                mb = EM_RES_REC(self->resource, 0x9C4);
                break;
            }
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase((int *)self) + 0x23), self,
                               0, 0, 0, 0);
            break;
        case 0x260:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                ma = EM_RES_REC(self->resource, 0x311C);
                mb = EM_RES_REC(self->resource, 0x3120);
                break;
            case 1:
                ma = EM_RES_REC(self->resource, 0x3124);
                mb = EM_RES_REC(self->resource, 0x3128);
                break;
            case 2:
                ma = EM_RES_REC(self->resource, 0x312C);
                mb = EM_RES_REC(self->resource, 0x3130);
                break;
            }
            break;
        case 0x264:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                ma = EM_RES_REC(self->resource, 0x3300);
                mb = EM_RES_REC(self->resource, 0x3304);
                break;
            case 1:
                ma = EM_RES_REC(self->resource, 0x3308);
                mb = EM_RES_REC(self->resource, 0x330C);
                break;
            case 2:
                ma = EM_RES_REC(self->resource, 0x3310);
                mb = EM_RES_REC(self->resource, 0x3314);
                break;
            }
            if (self->emFlags2 & 0x10000000) {
                switch (irand() & 1) {
                case 0:
                default:
                    ma = EM_RES_REC(self->resource, 0x3398);
                    mb = EM_RES_REC(self->resource, 0x339C);
                    break;
                case 1:
                    ma = EM_RES_REC(self->resource, 0x33A0);
                    mb = EM_RES_REC(self->resource, 0x33A4);
                    break;
                }
            }
            break;
        case 0x265:
            if (self->emFlags2 & 0x20000000) {
                switch (irand() & 1) {
                case 0:
                default:
                    ma = EM_RES_REC(self->resource, 0x3928);
                    mb = EM_RES_REC(self->resource, 0x392C);
                    break;
                case 1:
                    ma = EM_RES_REC(self->resource, 0x3930);
                    mb = EM_RES_REC(self->resource, 0x3934);
                    break;
                }
                break;
            }
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                ma = EM_RES_REC(self->resource, 0x3890);
                mb = EM_RES_REC(self->resource, 0x3894);
                if (self->unk744 != 0) {
                    ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0x20);
                }
                break;
            case 1:
                ma = EM_RES_REC(self->resource, 0x3888);
                mb = EM_RES_REC(self->resource, 0x388C);
                if (self->unk744 != 0) {
                    ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0x1F);
                }
                break;
            case 2:
                ma = EM_RES_REC(self->resource, 0x3880);
                mb = EM_RES_REC(self->resource, 0x3884);
                if (self->unk744 != 0) {
                    ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0x1E);
                }
                break;
            }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
            switch (irand() & 1) {
            case 0:
            default:
                ma = EM_RES_REC(self->resource, 0x1680);
                mb = EM_RES_REC(self->resource, 0x1684);
                break;
            case 1:
                ma = EM_RES_REC(self->resource, 0x1688);
                mb = EM_RES_REC(self->resource, 0x168C);
                break;
            }
            break;
        case 0x241:
            switch (irand() & 1) {
            case 0:
            default:
                ma = EM_RES_REC(self->resource, 0x3A84);
                mb = EM_RES_REC(self->resource, 0x3A88);
                break;
            case 1:
                ma = EM_RES_REC(self->resource, 0x3A8C);
                mb = EM_RES_REC(self->resource, 0x3A90);
                break;
            }
            break;
        case 0x209: case 0x21F:
            switch (irand() & 1) {
            case 0:
            default:
                ma = EM_RES_REC(self->resource, 0x1680);
                mb = EM_RES_REC(self->resource, 0x1684);
                break;
            case 1:
                ma = EM_RES_REC(self->resource, 0x1688);
                mb = EM_RES_REC(self->resource, 0x168C);
                break;
            }
            break;
        case 0x220: case 0x221: case 0x222:
            if (irand() & 1) {
                ma = EM_RES_REC(self->resource, 0x1CF8);
                mb = EM_RES_REC(self->resource, 0x1CFC);
            } else {
                ma = EM_RES_REC(self->resource, 0x1D00);
                mb = EM_RES_REC(self->resource, 0x1D04);
            }
            break;
        case 0x223:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                ma = EM_RES_REC(self->resource, 0x2E34);
                mb = EM_RES_REC(self->resource, 0x2E38);
                break;
            case 1:
                ma = EM_RES_REC(self->resource, 0x2E3C);
                mb = EM_RES_REC(self->resource, 0x2E40);
                break;
            case 2:
                ma = EM_RES_REC(self->resource, 0x2E44);
                mb = EM_RES_REC(self->resource, 0x2E48);
                break;
            }
            break;
        case 0x275: case 0x276:
            if (irand() & 1) {
                ma = EM_RES_REC(self->resource, 0x2354);
                mb = EM_RES_REC(self->resource, 0x2358);
            } else {
                ma = EM_RES_REC(self->resource, 0x235C);
                mb = EM_RES_REC(self->resource, 0x2360);
            }
            break;
        }
        if (self->unk6EC != 0) {
            if (irand() & 1) {
                ma = EM_RES_REC(self->resource, 0x774);
                mb = EM_RES_REC(self->resource, 0x778);
            } else {
                ma = EM_RES_REC(self->resource, 0x77C);
                mb = EM_RES_REC(self->resource, 0x780);
            }
        }
        func_002A8578((int)self, ma, mb, 2, 0.0f, Obj0000_Get_Byte_17C3_NZ_2_276468(self), 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)GetSeqSEBase((int *)self), self, 0, 0, 0, 0);
        func_0026F120(self);
        self->timerA = 0;
        cVec_copy3(&self->posB, Getplayer()->pos);
        hit = self->unk698;
        if (hit != 0) {
            cGameObj *attacker = (cGameObj *)hit->attacker;

            if (attacker != 0) {
                self->timerA = 10;
                cVec_copy3(&self->posB, attacker->pos);
            }
        }
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            self->timerB = 15;
            break;
        case 2:
            self->timerB = 15;
            break;
        case 3:
            self->timerB = 10;
            break;
        case 4:
            self->timerB = 10;
            break;
        case 5:
            self->timerB = 10;
            break;
        }
        if (self->stepArg != 0) {
            self->timerB = 999;
        }
        self->timer = 5.0f;
        self->timer2 = 2.0f;
        self->timer3 = 20.0f;
        self->step += 1;
        /* fallthrough */
    case 1:
        switch (self->emNo) {
        case 0x264: case 0x265:
            break;
        default:
            if (self->timerA != 0) {
                self->timerA--;
                cGameObj_SetTgtTurn((cGameObj *)self, &self->posB, self->speedRate * 0.3926991f);
            }
            break;
        }
        self->unk434 |= 8;
        if (self->stepArg != 0) {
            moveMotion(self);
            self->timer3 -= self->speedRate;
            if (self->timer3 <= 0.0f) {
                if (func_0026F1D8(self) != 0) {
                    func_00270C78(self);
                } else {
                    func_002705D8(self);
                }
            }
        } else {
            if (moveMotion(self) != 0) {
                if ((self->emFlags2 & 0x10000000) && self->emNo == 0x264) {
                    func_00270C78(self);
                } else if (func_0026F1D8(self) != 0) {
                    func_00270C78(self);
                } else {
                    func_002705D8(self);
                }
                break;
            }
            if (func_0026F1D8(self) != 0) {
                self->timer -= self->speedRate;
                if (self->timer <= 0.0f) {
                    if (self->emNo != 0x264) {
                        func_00270C78(self);
                    } else if (!(self->emFlags2 & 0x10000000)) {
                        func_00270C78(self);
                    }
                }
            }
        }
        if (self->stepArg == 0) {
            cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
            cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
            if (self->timerB != 0) {
                self->timerB--;
            } else if (func_0026F1D8(self) == 0) {
                switch (self->emNo) {
                case 0x20E:
                    if ((irand() & 3) == 0 && self->playerDist < 9.0f && D_005CB010 == 0
                        && (irand() & 1)) {
                        self->mode = 0;
                        self->phase = 0x28;
                        self->step = 0;
                        self->stepArg = 0;
                        return;
                    }
                    break;
                case 0x250: case 0x251: case 0x260:
                    if ((irand() & 3) == 0 && self->playerDist < 25.0f && D_005CB010 == 0
                        && func_00268068(self, 1) != 0) {
                        return;
                    }
                    break;
                }
                if ((unsigned int)irand() % 12 == 0 && self->playerDist < 9.0f && D_005CB010 == 0
                    && self->unk17BB != 0 && self->unk1740 <= 0.0f) {
                    func_00274238(self, 0);
                    return;
                }
                if (func_00262AA8(self) != 0) {
                    return;
                }
            }
        }
        if (self->timer2 > 0.0f && D_005CB010 == 0 && self->stepArg == 0) {
            self->timer2 -= self->speedRate;
            if (self->timer2 <= 0.0f) {
                go = 0;
                switch (self->emNo) {
                case 0x223: case 0x260: case 0x264: case 0x265: case 0x275: case 0x276:
                    if (++self->unk17C0 >= 3) {
                        switch (cCoreSave_getGameLevel(&D_00569B70)) {
                        default:
                        case 1:
                            if (fRand0_1() < 0.3f) {
                                go = 1;
                            }
                            break;
                        case 2:
                            if (fRand0_1() < 0.35f) {
                                go = 1;
                            }
                            break;
                        case 3:
                            if (fRand0_1() < 0.4f) {
                                go = 1;
                            }
                            break;
                        case 4:
                            if (fRand0_1() < 0.4f) {
                                go = 1;
                            }
                            break;
                        case 5:
                            if (fRand0_1() < 0.5f) {
                                go = 1;
                            }
                            break;
                        }
                        if (go != 0 && func_00262AA8(self) != 0) {
                            self->unk17C0 = 0;
                            self->emFlags |= 0x800000;
                        }
                    }
                    break;
                }
            }
        }
        break;
    case 2:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        self->timer3 = 0.0f;
        switch (self->emNo) {
        case 0x200: case 0x201: case 0x204: case 0x213: case 0x217:
        case 0x227: case 0x228: case 0x22B: case 0x23A: case 0x23B:
        case 0x240: case 0x242: case 0x243: case 0x244: case 0x24A:
        case 0x25B:
            ma = EM_RES_REC(self->resource, 0x540);
            mb = EM_RES_REC(self->resource, 0x544);
            if (irand() & 3) {
                self->timer3 = start = 10.0f;
            }
            break;
        case 0x256: case 0x27E:
            ma = EM_RES_REC(self->resource, 0x2BEC);
            mb = EM_RES_REC(self->resource, 0x2BF0);
            if (irand() & 3) {
                self->timer3 = start = 10.0f;
            }
            break;
        default:
            ma = EM_RES_REC(self->resource, 0x540);
            mb = EM_RES_REC(self->resource, 0x544);
            if (irand() & 3) {
                self->timer3 = start = 10.0f;
            }
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
        case 0x218: case 0x245: case 0x246: case 0x247: case 0x24F:
        case 0x278: case 0x279:
            ma = EM_RES_REC(self->resource, 0x9F0);
            mb = EM_RES_REC(self->resource, 0x9F4);
            if (irand() & 3) {
                self->timer3 = start = 10.0f;
            }
            break;
        case 0x250: case 0x251:
            ma = EM_RES_REC(self->resource, 0x9F0);
            mb = EM_RES_REC(self->resource, 0x9F4);
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase((int *)self) + 0x23), self,
                               0, 0, 0, 0);
            if (irand() & 3) {
                self->timer3 = start = 10.0f;
            }
            break;
        case 0x260:
            ma = EM_RES_REC(self->resource, 0x314C);
            mb = EM_RES_REC(self->resource, 0x3150);
            if (irand() & 3) {
                self->timer3 = start = 10.0f;
            }
            break;
        case 0x264:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                ma = EM_RES_REC(self->resource, 0x3300);
                mb = EM_RES_REC(self->resource, 0x3304);
                break;
            case 1:
                ma = EM_RES_REC(self->resource, 0x3308);
                mb = EM_RES_REC(self->resource, 0x330C);
                break;
            case 2:
                ma = EM_RES_REC(self->resource, 0x3310);
                mb = EM_RES_REC(self->resource, 0x3314);
                break;
            }
            if (self->emFlags2 & 0x10000000) {
                switch (irand() & 1) {
                case 0:
                default:
                    ma = EM_RES_REC(self->resource, 0x3398);
                    mb = EM_RES_REC(self->resource, 0x339C);
                    break;
                case 1:
                    ma = EM_RES_REC(self->resource, 0x33A0);
                    mb = EM_RES_REC(self->resource, 0x33A4);
                    break;
                }
            }
            break;
        case 0x265:
            if (self->emFlags2 & 0x20000000) {
                switch (irand() & 1) {
                case 0:
                default:
                    ma = EM_RES_REC(self->resource, 0x3938);
                    mb = EM_RES_REC(self->resource, 0x393C);
                    break;
                case 1:
                    ma = EM_RES_REC(self->resource, 0x3940);
                    mb = EM_RES_REC(self->resource, 0x3944);
                    break;
                }
                break;
            }
            if (irand() & 1) {
                ma = EM_RES_REC(self->resource, 0x3898);
                mb = EM_RES_REC(self->resource, 0x389C);
                if (self->unk744 != 0) {
                    ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0x21);
                }
            } else {
                ma = EM_RES_REC(self->resource, 0x38A0);
                mb = EM_RES_REC(self->resource, 0x38A4);
                if (self->unk744 != 0) {
                    ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0x22);
                }
            }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
            ma = EM_RES_REC(self->resource, 0x16A8);
            mb = EM_RES_REC(self->resource, 0x16AC);
            if (irand() & 3) {
                self->timer3 = start = 10.0f;
            }
            break;
        case 0x241:
            ma = EM_RES_REC(self->resource, 0x3AAC);
            mb = EM_RES_REC(self->resource, 0x3AB0);
            if (irand() & 3) {
                self->timer3 = start = 10.0f;
            }
            break;
        case 0x209: case 0x21F:
            ma = EM_RES_REC(self->resource, 0x16A8);
            mb = EM_RES_REC(self->resource, 0x16AC);
            if (irand() & 3) {
                self->timer3 = start = 10.0f;
            }
            break;
        case 0x220: case 0x221: case 0x222:
            ma = EM_RES_REC(self->resource, 0x540);
            mb = EM_RES_REC(self->resource, 0x544);
            if (irand() & 3) {
                self->timer3 = start = 10.0f;
            }
            break;
        case 0x223:
            ma = EM_RES_REC(self->resource, 0x2EB4);
            mb = EM_RES_REC(self->resource, 0x2EB8);
            if (irand() & 3) {
                self->timer3 = start = 10.0f;
            }
            break;
        case 0x214: case 0x215: case 0x21A: case 0x21B: case 0x21C:
        case 0x21D: case 0x21E: case 0x225: case 0x22C: case 0x22D:
        case 0x22E: case 0x22F: case 0x248: case 0x249: case 0x24C:
        case 0x24D: case 0x24E: case 0x252: case 0x25A:
            ma = EM_RES_REC(self->resource, 0x1268);
            mb = EM_RES_REC(self->resource, 0x126C);
            if (irand() & 3) {
                self->timer3 = start = 10.0f;
            }
            break;
        case 0x275: case 0x276:
            ma = EM_RES_REC(self->resource, 0x236C);
            mb = EM_RES_REC(self->resource, 0x2370);
            if (irand() & 3) {
                self->timer3 = start = 10.0f;
            }
            break;
        }
        func_002A8578((int)self, ma, mb, 2, start, sel | 0x40, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)GetSeqSEBase((int *)self), self, 0, 0, 0, 0);
        func_0026F120(self);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            self->timerB = (unsigned int)irand() % 45 + 60;
            break;
        case 2:
            self->timerB = (unsigned int)irand() % 45 + 45;
            break;
        case 3:
            self->timerB = (unsigned int)irand() % 45 + 30;
            break;
        case 4:
        case 5:
            self->timerB = (unsigned int)irand() % 45 + 15;
            break;
        }
        self->rot.y += fRand1_1() * 0.5235988f;
        self->rot.y = Adjust_theta(self->rot.y);
        self->timer = 10.0f;
        self->timer2 = 2.0f;
        self->step += 1;
        /* fallthrough */
    case 3:
        if (self->timer3 > 0.0f) {
            self->emFlags |= 0x800000;
            self->timer3 -= self->speedRate;
        }
        if (moveMotion(self) != 0) {
            if ((self->emFlags2 & 0x10000000) && self->emNo == 0x264) {
                func_00270C78(self);
                break;
            }
            if (func_0026F1D8(self) != 0) {
                func_00270C78(self);
            } else {
                func_002705D8(self);
            }
        }
        if (self->stepArg == 0 && func_0026F1D8(self) != 0) {
            self->timer -= self->speedRate;
            if (self->timer <= 0.0f) {
                if (self->emNo != 0x264) {
                    func_00270C78(self);
                } else if (!(self->emFlags2 & 0x10000000)) {
                    func_00270C78(self);
                }
            }
        }
        if (self->moveFlags & 0x10) {
            self->timerB = 0;
        }
        if (self->timerB != 0) {
            self->timerB--;
        } else if (func_0026F1D8(self) == 0) {
            if ((unsigned int)irand() % 12 == 0 && self->playerDist < 9.0f && D_005CB010 == 0
                && self->unk17BB != 0 && self->unk1740 <= 0.0f) {
                func_00274238(self, 0);
                break;
            }
            if (func_00262AA8(self) != 0) {
                break;
            }
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        if (self->timer2 > 0.0f && D_005CB010 == 0) {
            self->timer2 -= self->speedRate;
            if (self->timer2 <= 0.0f) {
                go = 0;
                switch (self->emNo) {
                case 0x223: case 0x260: case 0x264: case 0x265: case 0x275: case 0x276:
                    if (++self->unk17C0 >= 3) {
                        switch (cCoreSave_getGameLevel(&D_00569B70)) {
                        default:
                        case 1:
                            if (fRand0_1() < 0.3f) {
                                go = 1;
                            }
                            break;
                        case 2:
                            if (fRand0_1() < 0.35f) {
                                go = 1;
                            }
                            break;
                        case 3:
                            if (fRand0_1() < 0.4f) {
                                go = 1;
                            }
                            break;
                        case 4:
                            if (fRand0_1() < 0.4f) {
                                go = 1;
                            }
                            break;
                        case 5:
                            if (fRand0_1() < 0.5f) {
                                go = 1;
                            }
                            break;
                        }
                        if (go != 0 && func_00262AA8(self) != 0) {
                            self->unk17C0 = 0;
                            self->emFlags |= 0x800000;
                        }
                    }
                    break;
                }
            }
        }
        break;
    case 4:
        ma = EM_RES_REC(self->resource, 0x3A70);
        mb = EM_RES_REC(self->resource, 0x3A74);
        func_002A8578((int)self, ma, mb, 2, 0.0f, Obj0000_Get_Byte_17C3_NZ_2_276468(self), 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)GetSeqSEBase((int *)self), self, 0, 0, 0, 0);
        StoreMotionParamsBoth_2609A8(self, 0x1E, 0, 0x3E, -1, 0);
        self->timerA = 15;
        self->timer = 30.0f;
        self->step += 1;
        /* fallthrough */
    case 5:
        if (self->timer != 0.0f) {
            self->emFlags |= 0x800000;
            self->timer -= self->speedRate;
        }
        if (self->timerA != 0) {
            self->timerA--;
            cGameObj_SetTgtTurn((cGameObj *)self, Getplayer()->pos, self->speedRate * 0.19634955f);
        }
        if (moveMotion(self) != 0) {
            if (func_0026F1D8(self) != 0) {
                func_00270C78(self);
            } else {
                func_002705D8(self);
            }
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        func_00260B30(self);
        break;
    }
}
