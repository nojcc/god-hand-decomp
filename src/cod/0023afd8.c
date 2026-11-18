/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

extern unsigned int irand(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0026EE40(void *a0, int a1, int a2);

/* A motion picked by enemy number, turning toward the player for a few
 * frames and moving by timer2 (negative when stepArg is set); when timer runs
 * out, play a second motion by enemy number unless func_00262AA8 takes over;
 * func_00274150 or a positive unk1734 sends it to phase 0x89 instead. */
__attribute__((section(".text.func_0023AFD8"))) void func_0023AFD8(cEm00 *self)
{
    int motA;
    int motB;

    self->emFlags |= 0x400;
    switch (self->step) {
        case 0: {
            int nb;

            self->unk1864 = 0;
            switch (self->emNo) {
                default: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x39C);
                    motB = EM_RES_REC(p, 0x3A0);
                } break;
                case 0x214:
                case 0x215: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x1B80);
                    motB = EM_RES_REC(p, 0x1B84);
                } break;
                case 0x202:
                case 0x203:
                case 0x213:
                case 0x216:
                case 0x217:
                case 0x229:
                case 0x22A:
                case 0x24B: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x7C4);
                    motB = EM_RES_REC(p, 0x7C8);
                } break;
                case 0x256:
                case 0x27E: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x2BA8);
                    motB = EM_RES_REC(p, 0x2BAC);
                } break;
                case 0x242:
                case 0x243:
                case 0x244: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x3698);
                    motB = EM_RES_REC(p, 0x369C);
                } break;
                case 0x20A:
                case 0x20D:
                case 0x20E:
                case 0x245:
                case 0x247: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0xB74);
                    motB = EM_RES_REC(p, 0xB78);
                } break;
                case 0x278: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x3C0C);
                    motB = EM_RES_REC(p, 0x3C10);
                } break;
                case 0x218:
                case 0x246:
                case 0x279: {
                    int p;
                    ReleaseField6ECByTag564_26B1E8(self);
                    p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x3C1C);
                    motB = EM_RES_REC(p, 0x3C20);
                } break;
                case 0x20B: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x1E34);
                    motB = EM_RES_REC(p, 0x1E38);
                } break;
                case 0x20C:
                case 0x24F: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x1F80);
                    motB = EM_RES_REC(p, 0x1F84);
                } break;
                case 0x205:
                case 0x206:
                case 0x207:
                case 0x208:
                case 0x224: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x17D8);
                    motB = EM_RES_REC(p, 0x17DC);
                } break;
                case 0x241: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x3AFC);
                    motB = EM_RES_REC(p, 0x3B00);
                } break;
                case 0x209:
                case 0x21F: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x345C);
                    motB = EM_RES_REC(p, 0x3460);
                } break;
                case 0x250:
                case 0x251: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x1A18);
                    motB = EM_RES_REC(p, 0x1A1C);
                    cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(self) + 0x23), self, 0, 0,
                                       0, 0);
                } break;
                case 0x260: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x1A18);
                    motB = EM_RES_REC(p, 0x1A1C);
                } break;
                case 0x264: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x326C);
                    motB = EM_RES_REC(p, 0x3270);
                } break;
                case 0x265: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x3724);
                    motB = EM_RES_REC(p, 0x3728);
                } break;
                case 0x220:
                case 0x221:
                case 0x222: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x1D50);
                    motB = EM_RES_REC(p, 0x1D54);
                } break;
                case 0x223: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x2ECC);
                    motB = EM_RES_REC(p, 0x2ED0);
                } break;
                case 0x275:
                case 0x276: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x23A8);
                    motB = EM_RES_REC(p, 0x23AC);
                } break;
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
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x13B8);
                    motB = EM_RES_REC(p, 0x13BC);
                } break;
            }
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            func_002A8578(self, motA, motB, 3, 0.0f, nb, 0);
            self->timerA = irand() % 0x1E + 0x1E;
            if (self->emNo == 0x250 || self->emNo == 0x251) {
                self->timerA = 0x3C;
            }
            if ((irand() & 3) != 0) {
                self->timerA = 0x14;
            }
            self->timer2 = 0.0f;
            if (self->stepArg != 0) {
                self->timer2 = -0.3f;
            }
            if (self->fx0 != 0) {
                Obj1D00_ClearState_6(&self->fx0->base);
            }
            if (self->fx6 != 0) {
                Obj1D00_ClearState_7(&self->fx6->base);
            }
            self->timerA = 5;
            self->timer = 15.0f;
            self->step += 1;
        }
            /* fallthrough */
        case 1:
            self->emFlags |= 0x2000;
            if (self->timerA != 0) {
                self->timerA--;
                cGameObj_SetTgtTurn(self, Getplayer()->pos, self->speedRate * 0.39269909f);
            }
            moveMotion(self);
            self->nullSpeed.z += self->timer2 * self->speedRate;
            self->timer2 *= 1.0f - self->speedRate * 0.3f;
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (self->unk173C <= 0.0f) {
                self->timer -= self->speedRate;
                if (self->timer <= 0.0f) {
                    if (func_00262AA8(self) != 0) {
                        break;
                    }
                    self->step = 2;
                }
            }
            if (func_00274150(self) == 0) {
                if (!(self->unk1734 > 0.0f)) {
                    break;
                }
            }
            self->stepArg = 0;
            self->mode = 0;
            self->step = 0;
            self->phase = 0x89;
            break;
        case 2: {
            int nb;

            switch (self->emNo) {
                default: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x3A4);
                    motB = EM_RES_REC(p, 0x3A8);
                } break;
                case 0x214:
                case 0x215: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x1B88);
                    motB = EM_RES_REC(p, 0x1B8C);
                } break;
                case 0x256:
                case 0x27E: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x2BB8);
                    motB = EM_RES_REC(p, 0x2BBC);
                } break;
                case 0x242:
                case 0x243:
                case 0x244: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x36A0);
                    motB = EM_RES_REC(p, 0x36A4);
                } break;
                case 0x20A:
                case 0x20D:
                case 0x20E:
                case 0x245:
                case 0x247: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0xB7C);
                    motB = EM_RES_REC(p, 0xB80);
                } break;
                case 0x278: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x3C14);
                    motB = EM_RES_REC(p, 0x3C18);
                } break;
                case 0x218:
                case 0x246:
                case 0x279: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x3C24);
                    motB = EM_RES_REC(p, 0x3C28);
                } break;
                case 0x250:
                case 0x251: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x1A20);
                    motB = EM_RES_REC(p, 0x1A24);
                } break;
                case 0x260: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x1A20);
                    motB = EM_RES_REC(p, 0x1A24);
                } break;
                case 0x264: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x326C);
                    motB = EM_RES_REC(p, 0x3270);
                } break;
                case 0x265: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x3724);
                    motB = EM_RES_REC(p, 0x3728);
                } break;
                case 0x20B: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x1E3C);
                    motB = EM_RES_REC(p, 0x1E40);
                } break;
                case 0x20C:
                case 0x24F: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x1F88);
                    motB = EM_RES_REC(p, 0x1F8C);
                } break;
                case 0x205:
                case 0x206:
                case 0x207:
                case 0x208:
                case 0x224: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x17E8);
                    motB = EM_RES_REC(p, 0x17EC);
                } break;
                case 0x241: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x3B0C);
                    motB = EM_RES_REC(p, 0x3B10);
                } break;
                case 0x209:
                case 0x21F: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x346C);
                    motB = EM_RES_REC(p, 0x3470);
                } break;
                case 0x220:
                case 0x221:
                case 0x222: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x1D58);
                    motB = EM_RES_REC(p, 0x1D5C);
                } break;
                case 0x223: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x2ED4);
                    motB = EM_RES_REC(p, 0x2ED8);
                } break;
                case 0x275:
                case 0x276: {
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x23B0);
                    motB = EM_RES_REC(p, 0x23B4);
                } break;
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
                    int p = EM_RES(self);
                    motA = EM_RES_REC(p, 0x13C0);
                    motB = EM_RES_REC(p, 0x13C4);
                } break;
            }
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            func_002A8578(self, motA, motB, 0xA, 0.0f, nb, 0);
            self->timer = 10.0f;
            self->step += 1;
        }
            /* fallthrough */
        case 3:
            if (self->timer > 0.0f) {
                self->emFlags |= 0x2000;
                self->timer -= self->speedRate;
            }
            if (moveMotion(self) != 0) {
                func_0026EE40(self, 0, 0);
                func_002705D8(self);
            } else {
                cObjBase_addNullSpeed_Rotation(self, 1.0f);
                cObjBase_addNullSpeed(self, 1.0f);
            }
            break;
    }
}
