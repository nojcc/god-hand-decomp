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

/* Guard wait step machine. Before step 0 an enemy 0x241 may switch to step 4,
 * and an attacker more than 135 degrees off the facing sends it to step 2.
 * Step 0 may drop the held weapon, plays the guard motion picked by the enemy
 * number, sets timerB from the game level (sometimes a short 20 with the
 * counter flag) and aims at the player or the attacker; step 1 turns, waits on
 * timerB and then tries an attack or a counter, and on timer2 may act after
 * two waits. Step 2 plays the turning guard motion, sets timerB from the game
 * level and turns by up to 30 degrees; step 3 waits like step 1. Steps 4 and 5
 * play enemy 0x241's motion turning toward the player. */
__attribute__((section(".text.func_0024DA80")))
void func_0024DA80(cEm00 *self)
{
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
                if ((irand() & 3) == 0) {
                    ReleaseField6ECByTag564_26B1E8(self);
                }
                break;
            }
            if (self->stepArg != 0) {
                ReleaseField6ECByTag564_26B1E8(self);
            }
        }
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        switch (self->emNo) {
        case 0x200: case 0x201: case 0x204: case 0x213: case 0x217:
        case 0x227: case 0x228: case 0x22B: case 0x23A: case 0x23B:
        case 0x240: case 0x242: case 0x243: case 0x244: case 0x24A:
        case 0x25B:
            switch (irand() & 1) {
            case 0:
            default:
                ma = EM_RES_REC(self->resource, 0x2E0);
                mb = EM_RES_REC(self->resource, 0x2E4);
                break;
            case 1:
                ma = EM_RES_REC(self->resource, 0x2E8);
                mb = EM_RES_REC(self->resource, 0x2EC);
                break;
            }
            break;
        case 0x256: case 0x27E:
            switch ((unsigned int)irand() & 3) {
            case 0:
            default:
                ma = EM_RES_REC(self->resource, 0x26E0);
                mb = EM_RES_REC(self->resource, 0x26E4);
                break;
            case 1:
                ma = EM_RES_REC(self->resource, 0x26E8);
                mb = EM_RES_REC(self->resource, 0x26EC);
                break;
            case 2:
                ma = EM_RES_REC(self->resource, 0x2BC8);
                mb = EM_RES_REC(self->resource, 0x2BCC);
                break;
            case 3:
                ma = EM_RES_REC(self->resource, 0x2BD0);
                mb = EM_RES_REC(self->resource, 0x2BD4);
                break;
            }
            break;
        default:
            switch (irand() & 1) {
            case 0:
            default:
                ma = EM_RES_REC(self->resource, 0x784);
                mb = EM_RES_REC(self->resource, 0x788);
                break;
            case 1:
                ma = EM_RES_REC(self->resource, 0x78C);
                mb = EM_RES_REC(self->resource, 0x790);
                break;
            }
            break;
        case 0x214: case 0x215: case 0x21A: case 0x21B: case 0x21C:
        case 0x21D: case 0x21E: case 0x225: case 0x22C: case 0x22D:
        case 0x22E: case 0x22F: case 0x248: case 0x249: case 0x24C:
        case 0x24D: case 0x24E: case 0x252: case 0x25A:
            if (irand() & 1) {
                ma = EM_RES_REC(self->resource, 0x1248);
                mb = EM_RES_REC(self->resource, 0x124C);
            } else {
                ma = EM_RES_REC(self->resource, 0x1250);
                mb = EM_RES_REC(self->resource, 0x1254);
            }
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
        case 0x218: case 0x245: case 0x246: case 0x247: case 0x24F:
        case 0x278: case 0x279:
            if (irand() & 1) {
                ma = EM_RES_REC(self->resource, 0x9D0);
                mb = EM_RES_REC(self->resource, 0x9D4);
            } else {
                ma = EM_RES_REC(self->resource, 0x9D8);
                mb = EM_RES_REC(self->resource, 0x9DC);
            }
            break;
        case 0x250: case 0x251:
            if (irand() & 1) {
                ma = EM_RES_REC(self->resource, 0x9D0);
                mb = EM_RES_REC(self->resource, 0x9D4);
            } else {
                ma = EM_RES_REC(self->resource, 0x9D8);
                mb = EM_RES_REC(self->resource, 0x9DC);
            }
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase((int *)self) + 0x23), self,
                               0, 0, 0, 0);
            break;
        case 0x260:
            if (irand() & 1) {
                ma = EM_RES_REC(self->resource, 0x3134);
                mb = EM_RES_REC(self->resource, 0x3138);
            } else {
                ma = EM_RES_REC(self->resource, 0x313C);
                mb = EM_RES_REC(self->resource, 0x3140);
            }
            break;
        case 0x264:
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
            } else {
                ma = EM_RES_REC(self->resource, 0x3318);
                mb = EM_RES_REC(self->resource, 0x331C);
                if (self->subA != 0) {
                    Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_27DB08((cEm00 *)((char *)self->subA));
                }
            }
            break;
        case 0x265:
            if (self->emFlags2 & 0x20000000) {
                switch (irand() & 1) {
                case 0:
                default:
                    ma = EM_RES_REC(self->resource, 0x3948);
                    mb = EM_RES_REC(self->resource, 0x394C);
                    break;
                case 1:
                    ma = EM_RES_REC(self->resource, 0x3950);
                    mb = EM_RES_REC(self->resource, 0x3954);
                    break;
                }
                break;
            }
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                ma = EM_RES_REC(self->resource, 0x3818);
                mb = EM_RES_REC(self->resource, 0x381C);
                if (self->unk744 != 0) {
                    ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0x23);
                }
                break;
            case 1:
                ma = EM_RES_REC(self->resource, 0x3820);
                mb = EM_RES_REC(self->resource, 0x3824);
                if (self->unk744 != 0) {
                    ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0x24);
                }
                break;
            case 2:
                ma = EM_RES_REC(self->resource, 0x3828);
                mb = EM_RES_REC(self->resource, 0x382C);
                if (self->unk744 != 0) {
                    ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0x25);
                }
                break;
            }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
            ma = EM_RES_REC(self->resource, 0x1690);
            mb = EM_RES_REC(self->resource, 0x1694);
            break;
        case 0x241:
            ma = EM_RES_REC(self->resource, 0x3A94);
            mb = EM_RES_REC(self->resource, 0x3A98);
            break;
        case 0x209: case 0x21F:
            ma = EM_RES_REC(self->resource, 0x1690);
            mb = EM_RES_REC(self->resource, 0x1694);
            break;
        case 0x220: case 0x221: case 0x222:
            ma = EM_RES_REC(self->resource, 0x1D08);
            mb = EM_RES_REC(self->resource, 0x1D0C);
            break;
        case 0x223:
            ma = EM_RES_REC(self->resource, 0x2E4C);
            mb = EM_RES_REC(self->resource, 0x2E50);
            break;
        case 0x275: case 0x276:
            ma = EM_RES_REC(self->resource, 0x2364);
            mb = EM_RES_REC(self->resource, 0x2368);
            break;
        }
        if (self->unk6EC != 0) {
            ma = EM_RES_REC(self->resource, 0x784);
            mb = EM_RES_REC(self->resource, 0x788);
        }
        func_002A8578((int)self, ma, mb, 2, 0.0f, sel, 0);
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
        if (self->stepArg != 0) {
            self->timerB = 999;
        }
        self->unk568 = 0;
        if ((unsigned int)irand() % 3 == 0 && func_0026F1D8(self) == 0 && D_005CB010 == 0) {
            self->timerB = 20;
            self->unk568 = 1;
        }
        cVec_copy3(&self->posB, Getplayer()->pos);
        hit = self->unk698;
        self->timerA = 0;
        if (hit != 0) {
            cGameObj *attacker = (cGameObj *)hit->attacker;

            if (attacker != 0) {
                self->timerA = 10;
                cVec_copy3(&self->posB, attacker->pos);
            }
        }
        self->timer = 15.0f;
        self->timer2 = 2.0f;
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
        if (self->timerB != 0) {
            self->timerB--;
        } else {
            if (self->unk17BB != 0 && self->unk1740 <= 0.0f && self->unk568 != 0) {
                switch (self->emNo) {
                case 0x20E:
                    if (self->playerDist < 9.0f && D_005CB010 == 0 && (irand() & 1)) {
                        self->mode = 0;
                        self->phase = 0x28;
                        self->step = 0;
                        self->stepArg = 0;
                        return;
                    }
                    break;
                case 0x250: case 0x251: case 0x260:
                    if (self->playerDist < 25.0f && D_005CB010 == 0 && (irand() & 1)
                        && func_00268068(self, 1) != 0) {
                        return;
                    }
                    break;
                }
                if ((unsigned int)irand() % 12 == 0 && self->playerDist < 9.0f
                    && D_005CB010 == 0) {
                    func_00274238(self, 0);
                    return;
                }
            }
            if (func_0026F1D8(self) == 0) {
                if ((unsigned int)irand() % 12 == 0 && self->playerDist < 9.0f
                    && D_005CB010 == 0 && self->unk17BB != 0 && self->unk1740 <= 0.0f) {
                    func_00274238(self, 0);
                    return;
                }
                if (self->counterReady != 0 && (irand() & 3) == 0
                    && func_00273C38((cGameObj *)self) != 0) {
                    self->mode = 0;
                    self->phase = 0xA;
                    self->step = 0;
                    self->stepArg = 1;
                    return;
                }
                if (func_00262AA8(self) != 0) {
                    return;
                }
            }
        }
        if (self->stepArg == 0) {
            cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
            cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        }
        if (self->timer2 > 0.0f && D_005CB010 == 0 && self->stepArg == 0) {
            self->timer2 -= self->speedRate;
            if (self->timer2 <= 0.0f) {
                go = 0;
                switch (self->emNo) {
                case 0x223: case 0x260: case 0x264: case 0x265: case 0x275: case 0x276:
                    if ((self->unk17C0 += 2) >= 3) {
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
        switch (self->emNo) {
        case 0x200: case 0x201: case 0x204: case 0x213: case 0x217:
        case 0x227: case 0x228: case 0x22B: case 0x23A: case 0x23B:
        case 0x240: case 0x242: case 0x243: case 0x244: case 0x24A:
        case 0x25B:
            ma = EM_RES_REC(self->resource, 0x540);
            mb = EM_RES_REC(self->resource, 0x544);
            break;
        case 0x256: case 0x27E:
            ma = EM_RES_REC(self->resource, 0x2BEC);
            mb = EM_RES_REC(self->resource, 0x2BF0);
            break;
        default:
            ma = EM_RES_REC(self->resource, 0x540);
            mb = EM_RES_REC(self->resource, 0x544);
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
        case 0x218: case 0x245: case 0x246: case 0x247: case 0x24F:
        case 0x278: case 0x279:
            ma = EM_RES_REC(self->resource, 0x9F0);
            mb = EM_RES_REC(self->resource, 0x9F4);
            break;
        case 0x250: case 0x251:
            ma = EM_RES_REC(self->resource, 0x9F0);
            mb = EM_RES_REC(self->resource, 0x9F4);
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase((int *)self) + 0x23), self,
                               0, 0, 0, 0);
            break;
        case 0x260:
            ma = EM_RES_REC(self->resource, 0x314C);
            mb = EM_RES_REC(self->resource, 0x3150);
            break;
        case 0x264:
            ma = EM_RES_REC(self->resource, 0x3320);
            mb = EM_RES_REC(self->resource, 0x3324);
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
                    ma = EM_RES_REC(self->resource, 0x3958);
                    mb = EM_RES_REC(self->resource, 0x395C);
                    break;
                case 1:
                    ma = EM_RES_REC(self->resource, 0x3960);
                    mb = EM_RES_REC(self->resource, 0x3964);
                    break;
                }
                break;
            }
            if (irand() & 1) {
                ma = EM_RES_REC(self->resource, 0x3830);
                mb = EM_RES_REC(self->resource, 0x3834);
                if (self->unk744 != 0) {
                    ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0x26);
                }
            } else {
                ma = EM_RES_REC(self->resource, 0x3838);
                mb = EM_RES_REC(self->resource, 0x383C);
                if (self->unk744 != 0) {
                    ForwardAnimParamPairByIndex_27EA50((void *)self->unk744, 0x27);
                }
            }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
            ma = EM_RES_REC(self->resource, 0x16A8);
            mb = EM_RES_REC(self->resource, 0x16AC);
            break;
        case 0x241:
            ma = EM_RES_REC(self->resource, 0x3AAC);
            mb = EM_RES_REC(self->resource, 0x3AB0);
            break;
        case 0x209: case 0x21F:
            ma = EM_RES_REC(self->resource, 0x16A8);
            mb = EM_RES_REC(self->resource, 0x16AC);
            break;
        case 0x220: case 0x221: case 0x222:
            ma = EM_RES_REC(self->resource, 0x540);
            mb = EM_RES_REC(self->resource, 0x544);
            break;
        case 0x223:
            ma = EM_RES_REC(self->resource, 0x2EB4);
            mb = EM_RES_REC(self->resource, 0x2EB8);
            break;
        case 0x214: case 0x215: case 0x21A: case 0x21B: case 0x21C:
        case 0x21D: case 0x21E: case 0x225: case 0x22C: case 0x22D:
        case 0x22E: case 0x22F: case 0x248: case 0x249: case 0x24C:
        case 0x24D: case 0x24E: case 0x252: case 0x25A:
            ma = EM_RES_REC(self->resource, 0x1268);
            mb = EM_RES_REC(self->resource, 0x126C);
            break;
        case 0x275: case 0x276:
            ma = EM_RES_REC(self->resource, 0x236C);
            mb = EM_RES_REC(self->resource, 0x2370);
            break;
        }
        func_002A8578((int)self, ma, mb, 2, 0.0f, sel | 0x40, 0);
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
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            if ((irand() & 7) == 0) {
                self->timerB = 15;
            }
            break;
        case 2:
            if ((unsigned int)irand() % 6 == 0) {
                self->timerB = 15;
            }
            break;
        case 3:
            if ((irand() & 3) == 0) {
                self->timerB = 15;
            }
            break;
        case 4:
            if ((irand() & 3) == 0) {
                self->timerB = 15;
            }
            break;
        case 5:
            if ((irand() & 3) == 0) {
                self->timerB = 15;
            }
            break;
        }
        self->timer = 10.0f;
        self->timer2 = 2.0f;
        self->rot.y += fRand1_1() * 0.5235988f;
        self->rot.y = Adjust_theta(self->rot.y);
        self->step += 1;
        /* fallthrough */
    case 3:
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
        if (self->stepArg == 0) {
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
            if (self->moveFlags & 0x10) {
                self->timerB = 0;
            }
            if (self->timerB != 0) {
                self->timerB--;
            } else if (func_0026F1D8(self) == 0) {
                if ((unsigned int)irand() % 12 == 0 && self->playerDist < 9.0f
                    && D_005CB010 == 0 && self->unk17BB != 0 && self->unk1740 <= 0.0f) {
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
                        if ((self->unk17C0 += 2) >= 3) {
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
        }
        break;
    case 4:
        ma = EM_RES_REC(self->resource, 0x3A70);
        mb = EM_RES_REC(self->resource, 0x3A74);
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        func_002A8578((int)self, ma, mb, 2, 0.0f, sel, 0);
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
