/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cObjBase.h"
#include "godhand/cGameObj.h"
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"
#include "godhand/rand.h"

#define EMFLAG_FLINCH           0x1000
#define EMFLAG2_GET_UP          0x100000
#define EMFLAG1644_STAY_DOWN    0x800000
#define EMMOVE_COUNTER_FRAME    0x8
#define EMMOVE_FALL_FRAME       0x10
#define PI_F                    3.1415927f
#define EM_PHASE_COUNTER        0x14

/* Ends the flinch of an enemy with no hit points left: get up (phase 2),
 * stay down (phase 3) or, when func_0025FE30 doesn't take over, fall (phase 1). */
static inline void Em_endFlinchDown(cEm00 *self)
{
    if (self->emFlags2 & EMFLAG2_GET_UP) {
        self->mode = 2;
        self->phase = 2;
        self->step = 0;
        self->stepArg = 0;
    } else if (self->flags1644 & EMFLAG1644_STAY_DOWN) {
        self->mode = 2;
        self->phase = 3;
        self->step = 0;
        self->stepArg = 0;
    } else if (func_0025FE30(self, 0x1000000, 0) != 0) {
        self->mode = 2;
        self->phase = 2;
        self->step = 0;
        self->stepArg = 0;
    } else {
        self->mode = 2;
        self->phase = 1;
        self->step = 0;
        self->stepArg = 0;
    }
}

/* Flinch phase machine: now and then release the unk6EC handle, face the attacker,
 * play the enemy's flinch motion for the side it was hit on, then on the
 * counter frame maybe start a counter attack (from game level 2 up), or end
 * the flinch. */
__attribute__((section(".text.func_00253DE8")))
void func_00253DE8(cEm00 *self)
{
    cDamageTake *hit;
    int motA;
    int motB;
    unsigned short sel;
    int side;
    int counter;

    self->emFlags |= EMFLAG_FLINCH;
    switch (self->step) {
    case 0:
        if (self->unk6EC != 0) {
            switch (self->emNo) {
            case 0x227:
            case 0x228:
            case 0x229:
            case 0x22A:
            case 0x22B:
            case 0x22C:
            case 0x22D:
            case 0x22E:
            case 0x22F:
            case 0x23A:
            case 0x24A:
            case 0x24B:
            case 0x25A:
                break;
            default:
                if ((irand() & 3) == 0) {
                    ReleaseField6ECByTag564_26B1E8(self);
                }
                break;
            }
        }
        self->unk1710 = 0;
        hit = self->unk698;
        if (hit != 0 && hit->attacker != 0) {
            cGameObj_SetTgtTurn((cGameObj *)self, ((cGameObj *)hit->attacker)->pos, PI_F);
        }
        side = self->stepArg;
        if (self->unk17C3 != 0) {
            side ^= 1;
        }
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        if (side == 0) {
            switch (self->emNo) {
            default:
                motA = EM_RES_REC(self->resource, 0x5E0);
                motB = EM_RES_REC(self->resource, 0x5E4);
                break;
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
            case 0x279:
                motA = EM_RES_REC(self->resource, 0xABC);
                motB = EM_RES_REC(self->resource, 0xAC0);
                break;
            case 0x250:
            case 0x251:
                motA = EM_RES_REC(self->resource, 0xABC);
                motB = EM_RES_REC(self->resource, 0xAC0);
                cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase((int *)self) + 0x23), self, 0, 0, 0, 0);
                break;
            case 0x260:
                motA = EM_RES_REC(self->resource, 0xABC);
                motB = EM_RES_REC(self->resource, 0xAC0);
                break;
            case 0x264:
                motA = EM_RES_REC(self->resource, 0x3300);
                motB = EM_RES_REC(self->resource, 0x3304);
                break;
            case 0x265:
                motA = EM_RES_REC(self->resource, 0x3818);
                motB = EM_RES_REC(self->resource, 0x381C);
                break;
            case 0x20F:
            case 0x210:
            case 0x211:
            case 0x226:
            case 0x270:
            case 0x271:
            case 0x272:
            case 0x273:
            case 0x274:
                motA = EM_RES_REC(self->resource, 0xEFC);
                motB = EM_RES_REC(self->resource, 0xF00);
                break;
            case 0x205:
            case 0x206:
            case 0x207:
            case 0x208:
            case 0x224:
            case 0x241:
                motA = EM_RES_REC(self->resource, 0x1750);
                motB = EM_RES_REC(self->resource, 0x1754);
                break;
            case 0x209:
            case 0x21F:
                motA = EM_RES_REC(self->resource, 0x1750);
                motB = EM_RES_REC(self->resource, 0x1754);
                break;
            case 0x220:
            case 0x221:
            case 0x222:
                motA = EM_RES_REC(self->resource, 0x5E0);
                motB = EM_RES_REC(self->resource, 0x5E4);
                break;
            case 0x223:
                motA = EM_RES_REC(self->resource, 0x2E4C);
                motB = EM_RES_REC(self->resource, 0x2E50);
                break;
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
            case 0x25A:
                motA = EM_RES_REC(self->resource, 0x1328);
                motB = EM_RES_REC(self->resource, 0x132C);
                break;
            }
            func_002A8578((int)self, motA, motB, 5, 0.0f, sel, 0);
            InitRenderStruct_2A8608((cGameObj *)self, 0x58, (void *)0x2F, 0, 2, 0);
        } else {
            switch (self->emNo) {
            default:
                motA = EM_RES_REC(self->resource, 0x5E8);
                motB = EM_RES_REC(self->resource, 0x5EC);
                break;
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
            case 0x279:
                motA = EM_RES_REC(self->resource, 0xAC4);
                motB = EM_RES_REC(self->resource, 0xAC8);
                break;
            case 0x250:
            case 0x251:
                motA = EM_RES_REC(self->resource, 0xAC4);
                motB = EM_RES_REC(self->resource, 0xAC8);
                cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase((int *)self) + 0x23), self, 0, 0, 0, 0);
                break;
            case 0x260:
                motA = EM_RES_REC(self->resource, 0xAC4);
                motB = EM_RES_REC(self->resource, 0xAC8);
                break;
            case 0x264:
                motA = EM_RES_REC(self->resource, 0x3300);
                motB = EM_RES_REC(self->resource, 0x3304);
                break;
            case 0x265:
                motA = EM_RES_REC(self->resource, 0x3818);
                motB = EM_RES_REC(self->resource, 0x381C);
                break;
            case 0x20F:
            case 0x210:
            case 0x211:
            case 0x226:
            case 0x270:
            case 0x271:
            case 0x272:
            case 0x273:
            case 0x274:
                motA = EM_RES_REC(self->resource, 0xF04);
                motB = EM_RES_REC(self->resource, 0xF08);
                break;
            case 0x205:
            case 0x206:
            case 0x207:
            case 0x208:
            case 0x224:
            case 0x241:
                motA = EM_RES_REC(self->resource, 0x1758);
                motB = EM_RES_REC(self->resource, 0x175C);
                break;
            case 0x209:
            case 0x21F:
                motA = EM_RES_REC(self->resource, 0x1758);
                motB = EM_RES_REC(self->resource, 0x175C);
                break;
            case 0x220:
            case 0x221:
            case 0x222:
                motA = EM_RES_REC(self->resource, 0x5E8);
                motB = EM_RES_REC(self->resource, 0x5EC);
                break;
            case 0x223:
                motA = EM_RES_REC(self->resource, 0x2E4C);
                motB = EM_RES_REC(self->resource, 0x2E50);
                break;
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
            case 0x25A:
                motA = EM_RES_REC(self->resource, 0x1330);
                motB = EM_RES_REC(self->resource, 0x1334);
                break;
            }
            func_002A8578((int)self, motA, motB, 5, 0.0f, sel, 0);
            InitRenderStruct_2A8608((cGameObj *)self, 0x58, (void *)0x30, 0, 2, 0);
        }
        cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)GetSeqSEBase((int *)self), self, 0, 0, 0, 0);
        self->timerA = 1;
        self->step++;
        /* fallthrough */
    case 1:
        if (moveMotion(self) != 0) {
            if (self->vital <= 0) {
                Em_endFlinchDown(self);
                break;
            }
            if (cEm00_startHitUnitAim(self) != 0) {
                break;
            }
            func_00274FE8(self);
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        if ((self->moveFlags & EMMOVE_FALL_FRAME) && self->vital <= 0) {
            Em_endFlinchDown(self);
            break;
        }
        if ((self->moveFlags & EMMOVE_COUNTER_FRAME) && self->timerA != 0 && func_0026F1D8(self) == 0
            && self->vital > 0) {
            self->timerA = 0;
            counter = 0;
            if (cCoreSave_getGameLevel(&D_00569B70) >= 2) {
                switch (self->counterChance) {
                case 0: /* never counters; dropping the case changes the switch code */
                    break;
                case 1:
                    if (irand() & 1) {
                        counter = 1;
                    }
                    break;
                case 2:
                    if ((unsigned int)irand() % 3 != 0) {
                        counter = 1;
                    }
                    break;
                }
            }
            if (self->vital <= 0) {
                counter = 0;
            }
            if (counter != 0) {
                self->mode = 1;
                self->hitFlash = 5.0f;
                self->phase = EM_PHASE_COUNTER;
                self->stepArg = 0;
                self->step = 0;
            }
        }
        break;
    }
}
