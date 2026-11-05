/* NON_MATCHING func_0020A178 (sn-2.95.3-136): 2646 vs 2644 words, 2571 the same
 * with s-registers masked. Needs extern_jtbl D_00430890 D_004309F0 D_00430AE0
 * D_00430BD0 D_00430D00 D_00430E20 D_00430F70 D_00430F90 D_00430FB0 D_004311A0
 * D_00431300 D_004314C0 D_00431620 D_00431780 D_004318E0 D_00431950 D_00431B10
 * D_00431CD0 (all 18 tables come out in retail's order and range).
 * Still differs: retail saves one more s-register (0xE0 frame) holding 1 for the
 * 0x17BD counter bonus (movn), where this gives slt; take->flags loads lw, retail lwu;
 * 0x17CA reads lh in retail (cEm00.h types it unsigned short); several setState
 * store orders and cross-jumped tails (the death blocks, vital = 0, 0x17C8, the
 * 1/0x16 tails of kinds 0x20/0x21); register choice in the absf code and the two
 * spark effects. Retail has identical arms (kind 0x19/0x1A flinch, and case 0xD of
 * the last emNo switch), written here as a switch with two equal bodies. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/player.h"
#include "godhand/cCoreSave.h"
#include "godhand/cHeatSys.h"
#include "godhand/cSnd.h"
#include "godhand/cObjBase.h"
#include "godhand/angle.h"
#include "godhand/mtx.h"
#include "godhand/rand.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

/* Fields cEm00.h still covers with padding (it is off-limits while #25-#37 are open). */
#define EM00_770(self) (*(float *)((char *)(self) + 0x770))
#define EM00_1718(self) (*(float *)((char *)(self) + 0x1718))
#define EM00_1734(self) (*(float *)((char *)(self) + 0x1734))
#define EM00_173C(self) (*(float *)((char *)(self) + 0x173C))
#define EM00_1754(self) (*(float *)((char *)(self) + 0x1754))
#define EM00_17A4(self) (*(int *)((char *)(self) + 0x17A4))
#define EM00_17B4(self) (*(int *)((char *)(self) + 0x17B4))
#define EM00_17BD(self) (*(unsigned char *)((char *)(self) + 0x17BD))
#define EM00_17BF(self) (*(unsigned char *)((char *)(self) + 0x17BF))

/* A float past the end of cEm00, in the derived enemy's record. */
#define EM00_F1940(self) (*(float *)((char *)(self) + 0x1940))

/* The hit record the enemy is answering. */
#define EM_TAKE(self) ((cDamageTake *)(self)->unk698)

/* Mode and phase bytes (0x2F4, 0x2F5) read as one test of the state dword. */
#define EM_MODE_PHASE_IS(self, m, p) \
    ((*(long *)&(self)->unk2F0 & 0xFFFF00000000L) == ((long)(((p) << 8) | (m)) << 32))

extern cEm00 *D_00586A80;
extern unsigned short D_00747A50;

long func_0020CAC8(void *a0, int a1);
int func_0020D140(void *a0);
int func_0020CD00(cEm00 *self);
int func_0020EF08(cEm00 *self);
int func_0024BF20(cEm00 *self);
int func_0020D398(cEm00 *self);
int func_0020DA18(cEm00 *self);
int func_0020DCF0(cEm00 *self);
int func_0020E480(cEm00 *self);
/* Always 0; self is not read. */
int ReturnZero_20D138(cEm00 *self);
void func_0026A338(char *o);
void func_0026ECD0(void *a0, int a1);
void func_0026EE40(char *a0, int a1, int a2);
int func_00272688(char *a0);
void func_0028ED28(void *a0, int d);

/* Sets the hit points to v, capped at vitalMax. */
static __inline__ void cEm00_setVital(cEm00 *self, int v)
{
    if (v >= self->vitalMax) {
        self->vital = self->vitalMax;
    } else {
        self->vital = v;
    }
}

/* Child part idx of the enemy, or 0. */
static __inline__ cOmBase *cEm00_part(cEm00 *self, int idx)
{
    int frame[3];

    return cOmBase_childAt((cOmBase *)self, frame, idx);
}

/* The guard-break spark: a sound, effect 0x4C 0.2 in front of child part 4,
 * and 100 game level points. */
static __inline__ void cEm00_guardBreak(cEm00 *self)
{
    int frame[3];
    cOmBase *part;

    cSnd_SeCall_2CBA48(&D_005FEE00, 0, 1, self, 0, 0, 0, 0);
    self->unk1740 = 60.0f;
    part = cOmBase_childAt((cOmBase *)self, frame, 4);
    if (part) {
        float mtx[16] __attribute__((aligned(16)));
        cVec spot;

        VU0_SQC2_VF0_MEM(&spot, 0);
        MtxInitRotY(mtx, self->rot.y);
        spot.x = 0.0f;
        spot.z = 0.2f;
        spot.y = 0.0f;
        sceVu0ApplyMatrix(&spot, mtx, &spot);
        VU0_VADD_XYZ_IP(&spot, 0, part->pos);
        SetEffectPos(0, 0x4C, 0, &spot, 1.0f, -1);
    }
    cCoreSave_addGameLevelPoint(&D_00569B70, 100);
}

/* Mode 1 phase 7 with stepArg a, unless that flinch is already running and
 * its motion flag 4 is set. */
#define EM_FLINCH7(self, a)                                             \
    {                                                                   \
        if (EM_MODE_PHASE_IS(self, 1, 7) && ((self)->moveFlags & 4)) {  \
            return 1;                                                   \
        }                                                               \
        cEm00_setState(self, 1, 7, a);                                  \
        return 1;                                                       \
    }

/* Picks the enemy's reaction to the hit it was just given (the hit record at
 * 0x698): heat for the player, damage, the counter attack, and the next mode
 * and phase. 1 when the state changed, 0 when the hit is ignored. */
__attribute__((section(".text.func_0020A178")))
int func_0020A178(cEm00 *self)
{
    cGameObj *pl;
    cEm00 *atk;
    int power;
    int big;
    float heat;
    int bonus;
    int strong;
    int counter;
    unsigned int lim;

    pl = Getplayer();
    if (EM00_770(self) > 0.0f && self->vital > 0) {
        EM00_1718(self) -= self->speedRate;
        if (EM00_1718(self) <= 0.0f) {
            EM00_1718(self) = 15.0f;
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x2A, self, 0, 0, 0, 0);
        }
        EM00_770(self) -= self->speedRate;
        if (EM00_770(self) <= 0.0f) {
            self->emFlags2 |= 0x100000;
            cEm00_setState(self, 2, 2, 0);
            self->hitFlash = 30.0f;
            self->vital = 0;
            return 1;
        }
    }
    if (self->emNo == 0x21F && (self->emFlags2 & 0x100000) && self->vital > 0 &&
        D_00586A80 != 0 && D_00586A80->vital <= 0) {
        cEm00_setState(self, 2, 2, 0);
        self->hitFlash = 30.0f;
        self->vital = 0;
        return 1;
    }
    if (EM_TAKE(self) == 0) {
        return 0;
    }
    if ((EM_TAKE(self)->flags & 1) == 0) {
        return 0;
    }
    if (self->hitFlash > 0.0f) {
        return 0;
    }
    if (!(self->moveFlags & 8) && cDamageTake_kind(EM_TAKE(self)) == 0x2B) {
        return 0;
    }
    if (self->unk17CA) {
        self->moveFlags &= ~0x100;
    }
    if ((self->emFlags & 0x40000) || self->unk1740 > 0.0f || EM00_1734(self) > 0.0f) {
        self->moveFlags |= 0x100;
        self->emFlags2 |= 0x8000;
    }
    self->unk17CA = 10;
    atk = (cEm00 *)EM_TAKE(self)->attacker;
    switch (cDamageTake_kind(EM_TAKE(self))) {
    case 0x2E:
        if (self->vital <= 0) {
            return 0;
        }
        /* fall through */
    case 0x2F:
        if (self->emFlags & 0x1000) {
            return 0;
        }
        break;
    }

    switch (cDamageTake_kind(EM_TAKE(self))) {
    case 7: case 0xE:
        heat = 0.8f;
        break;
    case 0x2C:
        heat = 0.6f;
        break;
    case 0x2B:
        heat = 0.4f;
        break;
    case 2: case 5: case 6:
        heat = 1.5f;
        break;
    case 8: case 0xA: case 0xB: case 0x10: case 0x11: case 0x12: case 0x13:
    case 0x15: case 0x16: case 0x17: case 0x18: case 0x19: case 0x1A: case 0x1B:
        heat = 2.0f;
        break;
    case 1: case 3: case 4: case 9: case 0xC: case 0xD: case 0xF: case 0x14:
    case 0x1C: case 0x1D: case 0x27:
        heat = 3.0f;
        break;
    case 0x55:
    default:
        heat = 0.0f;
        break;
    }
    if (self->vital <= 0) {
        heat = 0.0f;
    }
    if (heat > 0.0f) {
        cHeatSys_AddHeatGage(&D_005CB000, 0, heat);
        if (self->moveFlags & 0x100) {
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                cHeatSys_AddHeatGage(&D_005CB000, 0, 1.0f);
            } else {
                cHeatSys_AddHeatGage(&D_005CB000, 0, 4.0f);
            }
        }
    }
    self->counterVital = self->vital;
    power = EM_TAKE(self)->power;
    if (cDamageTake_kind(EM_TAKE(self)) == 0x54) {
        self->vital = 0;
    }
    if (self->moveFlags & 0x100) {
        switch (cDamageTake_kind(EM_TAKE(self))) {
        case 0x1C: case 0x1D: case 0x1E: case 0x1F: case 0x20: case 0x21: case 0x22:
        case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x29: case 0x2A:
        case 0x2E: case 0x2F: case 0x30: case 0x31: case 0x52: case 0x55:
            break;
        default:
            power *= 2;
            break;
        }
        self->emFlags &= ~0x800000;
    }
    big = 0;
    switch (cDamageTake_kind(EM_TAKE(self))) {
    case 0x1C: case 0x1D: case 0x1E: case 0x1F: case 0x20: case 0x21: case 0x22:
    case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x29: case 0x2A:
    case 0x2E: case 0x2F: case 0x30: case 0x31: case 0x52: case 0x55:
        big = 1;
        break;
    }
    CEM00_VCALL(self, hit, power, atk, 0, big);
    EM00_17A4(self) += power;
    self->unk17A8 += power;
    EM00_17B4(self) = power;
    if (self->emNo == 0x218 && D_00747A50 == 1 && self->vital <= 0) {
        self->vital = 1;
    }
    if (cDamageTake_kind(EM_TAKE(self)) == 0x2C || cDamageTake_kind(EM_TAKE(self)) == 0x24) {
        if (self->vital <= 0) {
            self->vital = 1;
        }
        self->unk5B4 = 0;
        self->unk17CC = 0;
        self->unk17A8 = 0;
    }
    EM00_F1940(self) = -0.05f;
    switch (self->emNo) {
    case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218:
    case 0x245: case 0x246: case 0x247: case 0x24F: case 0x250: case 0x251:
    case 0x260: case 0x278: case 0x279:
        self->unk17C4 = 1;
        self->unk17C8 = 0x2A;
        break;
    }
    self->hitFlash = 3.0f;
    switch (cDamageTake_kind(EM_TAKE(self))) {
    case 0xD: case 0xF: case 0x1A: case 0x1B:
        self->hitFlash = 10.0f;
        break;
    case 0x1C: case 0x1D: case 0x27: case 0x2E: case 0x2F: case 0x30: case 0x52: case 0x55:
        self->hitFlash = 15.0f;
        break;
    }
    func_0026EE40((char *)self, 0, 0);

    if (self->counterVital > 0) {
        switch (self->emNo) {
        case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            break;
        default:
        bonus = 0;
        switch (EM00_17BD(self)) {
        case 0:
            break;
        case 1:
            bonus = 1;
            if (cCoreSave_getGameLevel(&D_00569B70) < 3) {
                bonus = 0;
            }
            break;
        case 2:
            bonus = 1;
            if (cCoreSave_getGameLevel(&D_00569B70) < 2) {
                bonus = 0;
            }
            break;
        }
        if (bonus) {
            if (self->unk16EC <= 0) {
                self->unk16E8 += 5;
                if (power >= 10) {
                    self->unk16E8 += 15;
                }
            }
            func_0026ECD0(self, 0);
        }
            break;
        }
    }

    switch (self->emNo) {
    case 0x275: case 0x276:
        return func_0020DCF0(self);
    case 0x223:
        return func_0020E480(self);
    case 0x26A:
        return func_0020EF08(self);
    }

    if (cDamageTake_kind(EM_TAKE(self)) == 0x1E) {
        if ((self->emFlags2 & 0x100000) && self->vital <= 0) {
            cEm00_setState(self, 2, 2, 0);
            return 1;
        }
        cEm00_setState(self, 1, 5, 0);
        return 1;
    } else if (cDamageTake_kind(EM_TAKE(self)) == 0x1F) {
        cEm00_setState(self, 1, 0xB, 0);
        return 1;
    } else if (cDamageTake_kind(EM_TAKE(self)) == 0x21 || cDamageTake_kind(EM_TAKE(self)) == 0x54) {
        if (EM_MODE_PHASE_IS(self, 1, 0x16) && self->step < 4) {
            if (self->vital > 0) {
                cEm00_setState(self, 1, 0x16, 0);
            } else {
                cEm00_setState(self, 2, 4, 0);
            }
            return 1;
        }
        if (cDamageTake_kind(EM_TAKE(self)) == 0x54) {
            self->vital = 0;
            cEm00_setState(self, 1, 0x13, 1);
            return 1;
        }
        cEm00_setState(self, 1, 0x13, 0);
        return 1;
    } else if (cDamageTake_kind(EM_TAKE(self)) == 0x20) {
        if (EM_MODE_PHASE_IS(self, 1, 0x16) && self->step < 4) {
            if (self->vital > 0) {
                cEm00_setState(self, 1, 0x16, 0);
            } else {
                cEm00_setState(self, 2, 4, 0);
            }
            return 1;
        }
        cEm00_setState(self, 1, 0xB, 1);
        return 1;
    } else if (cDamageTake_kind(EM_TAKE(self)) == 0x22) {
        switch (self->emNo) {
        case 0x215: case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E:
        case 0x225: case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248:
        case 0x249: case 0x24C: case 0x24D: case 0x24E: case 0x252: case 0x25A:
            cEm00_setVital(self, self->counterVital);
            self->unk17C8 = 0x7C;
            self->hitFlash = 5.0f;
            self->moveFlags &= ~0x100;
            self->unk17C4 = 0;
            break;
        }
        if (EM_MODE_PHASE_IS(self, 1, 0x16) && self->step < 4) {
            cEm00_setVital(self, self->counterVital);
            self->unk17C4 = -1;
            self->hitFlash = 5.0f;
            self->unk17C8 = 0;
            return 0;
        }
        cEm00_setState(self, 1, 0x15, 0);
        return 1;
    } else if (cDamageTake_kind(EM_TAKE(self)) == 0x23) {
        switch (self->emNo) {
        default:
            if (EM_MODE_PHASE_IS(self, 1, 8)) {
                cEm00_setState(self, 1, 8, 5);
            } else {
                cEm00_setState(self, 1, 8, 6);
            }
            return 1;
        case 0x260: case 0x264: case 0x265:
            if (irand() & 1) {
                cEm00_setState(self, 1, 0, 1);
            } else {
                cEm00_setState(self, 1, 1, 1);
            }
            return 1;
        }
    } else if (cDamageTake_kind(EM_TAKE(self)) == 0x25) {
        if (EM_MODE_PHASE_IS(self, 1, 0x16)) {
            cEm00_setVital(self, self->counterVital);
            self->unk17C4 = -1;
            self->hitFlash = 5.0f;
            self->unk17C8 = 0;
            return 0;
        }
        self->moveFlags &= ~0x100;
        if (self->slowFlinch == 0) {
            cEm00_setVital(self, self->slowFlinch);
        }
        if (self->vital > 0) {
            cEm00_setState(self, 1, 0xB, 1);
            return 1;
        }
        if (self->emFlags2 & 0x100000) {
            cEm00_setState(self, 2, 2, 0);
            return 1;
        }
        if (self->slowFlinch == 0) {
            cEm00_setVital(self, self->slowFlinch);
        }
        if (func_00272688((char *)self) && self->vital <= 0) {
            cEm00_setVital(self, 0);
            cEm00_setState(self, 1, 0xC, 0);
            return 1;
        }
        cEm00_setState(self, 1, 3, 0);
        return 1;
    } else if (cDamageTake_kind(EM_TAKE(self)) == 0x26) {
        cEm00_setState(self, 1, 0xB, 1);
        return 1;
    } else if (cDamageTake_kind(EM_TAKE(self)) == 0x28) {
        func_0028ED28(self, 999);
        if (self->vital <= 0) {
            if (self->counterVital < 2) {
                cEm00_setState(self, 1, 3, 0);
                return 1;
            }
            self->vital = 1;
        }
        switch (self->emNo) {
        case 0x20F: case 0x210: case 0x211: case 0x226:
        case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            func_0026F120(self);
            if (func_0026F1D8(self)) {
                func_00270C78(self);
                return 1;
            }
            cEm00_setState(self, 1, 8, 5);
            return 1;
        }
        cEm00_setState(self, 1, 1, 1);
        return 1;
    } else if (cDamageTake_kind(EM_TAKE(self)) == 0x1C) {
        self->hitFlash = 15.0f;
        if ((self->emFlags2 & 0x100000) && self->vital <= 0) {
            cEm00_setState(self, 2, 2, 0);
            return 1;
        }
        if (self->emNo == 0x265) {
            self->hitFlash = 45.0f;
            cEm00_setState(self, 1, 4, 0);
            return 1;
        }
        cEm00_setState(self, 1, 8, 2);
        return 1;
    } else if (cDamageTake_kind(EM_TAKE(self)) == 0x1D) {
        cEm00_setState(self, 1, 4, 0);
        return 1;
    } else if (cDamageTake_kind(EM_TAKE(self)) == 0x27) {
        cEm00_setState(self, 1, 3, 0);
        return 1;
    } else if (cDamageTake_kind(EM_TAKE(self)) == 0x2C || cDamageTake_kind(EM_TAKE(self)) == 0x24) {
        self->hitFlash = 3.0f;
        EM00_17A4(self) = 0;
        switch (self->emNo) {
        case 0x20F: case 0x210: case 0x211: case 0x226:
        case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            cEm00_setState(self, 1, 8, 5);
            return 1;
        }
        if (irand() & 1) {
            cEm00_setState(self, 1, 0, 1);
        } else {
            cEm00_setState(self, 1, 1, 1);
        }
        return 1;
    } else if (self->emFlags2 & 0x80000) {
        cEm00_setState(self, 1, 0x23, 0);
        return 1;
    }

    if (self->emFlags & 0x2000) {
        if (D_005CB010 || Obj0000_Get_Field_5FC_NE_Zero_12C748((char *)pl)) {
            cEm00_guardBreak(self);
            cEm00_setState(self, 1, 0x12, 0);
            return 1;
        }
        switch (cDamageTake_kind(EM_TAKE(self))) {
        default:
            if (atk && absf(Turn_dest(&self->pos->x, &atk->pos->x, self->rot.y, 3.14159274f)) > 1.57079637f) {
                break;
            }
            if (!(self->unk760 < 1.57079637f)) {
                break;
            }
            if (self->emFlags2 & 0x2000) {
                cEm00_setVital(self, self->counterVital);
                self->emFlags2 |= 0x4000;
                return 1;
            }
            if (EM00_173C(self) > 0.0f) {
                if (func_0020CAC8(self, 1)) {
                    return 0;
                }
                if (cCoreSave_getGameLevel(&D_00569B70) >= 3 && fRand0_1() <= 0.5f) {
                    EM00_173C(self) = 0.0f;
                }
                cEm00_setVital(self, self->counterVital);
                func_00274238(self, 1);
                self->unk17C8 = 0;
                self->unk17C4 = -1;
                EM00_17BF(self) = (unsigned int)irand() % 3;
                return 0;
            }
            cEm00_setVital(self, self->counterVital);
            cEm00_setState(self, 0, 0x6F, 0);
            return 1;
        case 9: case 0x1C: case 0x30: case 0x52:
            cEm00_setState(self, 1, 8, 2);
            return 1;
        case 0x55:
            cEm00_setState(self, 1, 3, 2);
            return 1;
        case 3: case 4: case 0x2D: case 0x32: case 0x34: {
            cOmBase *part;

            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 1, self, 0, 0, 0, 0);
            self->unk1740 = 60.0f;
            part = cEm00_part(self, 4);
            if (part) {
                float mtx[16] __attribute__((aligned(16)));
                cVec spot;

                VU0_SQC2_VF0_MEM(&spot, 0);
                MtxInitRotY(mtx, self->rot.y);
                spot.x = 0.0f;
                spot.z = 0.2f;
                spot.y = 0.0f;
                sceVu0ApplyMatrix(&spot, mtx, &spot);
                VU0_VADD_XYZ_IP(&spot, 0, part->pos);
                SetEffectPos(0, 0x4C, 0, &spot, 1.0f, -1);
            }
            cCoreSave_addGameLevelPoint(&D_00569B70, 100);
        }
            cEm00_setState(self, 1, 0x12, 0);
            return 1;
        case 0x33: case 0x35:
            switch (self->emNo) {
            case 0x20F: case 0x210: case 0x211: case 0x226:
            case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
                cEm00_setState(self, 1, 4, 0);
                return 1;
            }
            cEm00_setState(self, 1, 3, 0);
            return 1;
        case 0xD:
            cEm00_setState(self, 1, 4, 0);
            return 1;
        }
    }

    if ((self->emFlags & 0x800000) && self->vital > 0 && !D_005CB010) {
        func_0026A338((char *)self);
        return 1;
    }
    if (EM_MODE_PHASE_IS(self, 1, 0x16) && self->step < 4) {
        switch (cDamageTake_kind(EM_TAKE(self))) {
        case 8: case 9: case 0xA: case 0xB: case 0x1C: case 0x30: case 0x52:
            cEm00_setState(self, 1, 8, 0);
            return 1;
        }
        if (self->vital <= 0) {
            cEm00_setState(self, 2, 4, 0);
            return 1;
        }
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            lim = 15;
            break;
        case 2:
            lim = 10;
            break;
        case 3:
            lim = 5;
            break;
        case 4:
            lim = 5;
            break;
        case 5:
            lim = 5;
            break;
        }
        switch (self->emNo) {
        case 0x211: case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            if (lim < self->unk1866 && (irand() & 1)) {
                self->mode = 1;
                self->phase = 0x16;
                self->step = 4;
                self->stepArg = 0;
                self->unk1866 = 0;
                return 0;
            }
            break;
        }
        cEm00_setState(self, 1, 0x16, 0);
        return 1;
    }
    if ((self->moveFlags & 8) || (cDamageTake_kind(EM_TAKE(self)) == 0x2B && EM00_1754(self) > 0.0f)) {
        counter = 0;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            lim = 15;
            break;
        case 2:
            lim = 10;
            break;
        case 3:
            lim = 5;
            break;
        case 4:
            lim = 5;
            break;
        case 5:
            lim = 3;
            break;
        }
        switch (self->emNo) {
        case 0x220: case 0x221: case 0x222: case 0x223:
            lim /= 2;
            break;
        }
        if (cDamageTake_kind(EM_TAKE(self)) == 0x2B) {
            self->unk5B4 = 0;
            if (self->unk1866 >= lim) {
                counter = irand() & 1;
            }
        } else {
            switch (self->emNo) {
            default:
                counter = (irand() & 7) == 0;
                break;
            case 0x204: case 0x205: case 0x206: case 0x207: case 0x208: case 0x209:
            case 0x20B: case 0x20C: case 0x20D: case 0x210: case 0x211: case 0x213:
            case 0x217: case 0x21C: case 0x21F: case 0x224: case 0x226: case 0x227:
            case 0x228: case 0x229: case 0x22A: case 0x22B: case 0x22C: case 0x22D:
            case 0x22E: case 0x22F: case 0x23A: case 0x241: case 0x24A: case 0x24B:
            case 0x24F: case 0x250: case 0x251: case 0x252: case 0x256: case 0x25A:
            case 0x25B: case 0x260: case 0x264: case 0x265: case 0x275: case 0x276:
            case 0x278: case 0x279: case 0x27E:
                counter = !(irand() & 1);
                break;
            }
        }
        if (cCoreSave_getGameLevel(&D_00569B70) >= 3 && (unsigned int)irand() % 3 == 0) {
            counter = 1;
        }
        if (D_005CB010) {
            counter = 0;
        }
        if (counter && self->counterVital > 0 && !func_0026F1D8(self)) {
            self->unk1866 = 0;
            cEm00_setVital(self, self->counterVital);
            self->hitFlash = 5.0f;
            self->unk17C4 = -1;
            cEm00_setState(self, 1, 0x14, 0);
            self->unk17C8 = 0;
            return 0;
        }
        if ((self->emFlags2 & 0x100000) && self->vital <= 0) {
            cEm00_setState(self, 2, 2, 0);
            return 1;
        }
        switch (cDamageTake_kind(EM_TAKE(self))) {
        case 2: case 3: case 4: case 5: case 7: case 0x19: case 0x2A: case 0x2C:
        case 0x2D: case 0x2E:
            if (self->vital > 0) {
                func_0026A338((char *)self);
                return 1;
            }
            cEm00_setState(self, 1, 0x13, 0);
            return 1;
        case 0x32: case 0x34: case 0x36:
            cEm00_setState(self, 1, 0x13, 0);
            return 1;
        case 0x12: case 0x15: case 0x17: case 0x1B:
            EM_FLINCH7(self, 0);
        case 0x11: case 0x16: case 0x18:
            EM_FLINCH7(self, 1);
        case 0x13: case 0x53:
            cEm00_setState(self, 1, 0xA, 0);
            return 1;
        case 0x54:
            self->vital = 0;
            cEm00_setState(self, 1, 0x13, 1);
            return 1;
        case 0x14:
            cEm00_setState(self, 1, 0xA, 1);
            return 1;
        case 0x2B:
            cEm00_setState(self, 1, 0x13, 0);
            return 1;
        case 1: case 0x55:
            break;
        case 8: case 0xA:
            switch (self->emNo) {
            case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218:
            case 0x245: case 0x246: case 0x247: case 0x24F: case 0x250: case 0x251:
            case 0x260: case 0x264: case 0x265: case 0x278: case 0x279:
                if (self->vital > 0) {
                    func_0026A338((char *)self);
                    return 1;
                }
                cEm00_setState(self, 1, 0x13, 0);
                return 1;
            }
            break;
        }
    }

    if (self->emFlags & 0x4000) {
        cEm00_setVital(self, self->counterVital);
        if (cDamageTake_kind(EM_TAKE(self)) == 0x30 || cDamageTake_kind(EM_TAKE(self)) == 0x52) {
            cEm00_setState(self, 1, 0x10, 0);
            return 1;
        }
    }
    if (self->vital <= 0 && (self->emFlags2 & 0x100000)) {
        cEm00_setState(self, 2, 2, 0);
        return 1;
    }
    if (self->emFlags2 & 0x40) {
        cEm00_setState(self, 1, 0x18, 0);
        return 1;
    }
    if ((self->moveFlags & 0x24) || (self->emFlags & 0x20)) {
        switch (cDamageTake_kind(EM_TAKE(self))) {
        case 0x1C: case 0x30: case 0x36: case 0x52:
            break;
        default:
            if (func_0020DA18(self)) {
                return 0;
            }
            break;
        }
        switch (cDamageTake_kind(EM_TAKE(self))) {
        default:
            cEm00_setState(self, 1, 8, 1);
            return 1;
        case 0x12: case 0x15: case 0x17: case 0x1B:
            EM_FLINCH7(self, 0);
        case 0x11: case 0x16: case 0x18:
            EM_FLINCH7(self, 1);
        case 8:
            cEm00_setState(self, 1, 8, 0);
            return 1;
        case 0xA: case 0xB:
            cEm00_setState(self, 1, 8, 3);
            return 1;
        case 9: case 0x1C: case 0x30: case 0x52:
            cEm00_setState(self, 1, 8, 2);
            return 1;
        case 1: case 6: case 0xC: case 0xE: case 0xF: case 0x10: case 0x19: case 0x1A:
        case 0x2A: case 0x2F: case 0x33: case 0x35:
            cEm00_setState(self, 1, 3, 0);
            return 1;
        case 0x13: case 0x53:
            cEm00_setState(self, 1, 0xA, 0);
            return 1;
        case 0x54:
            self->vital = 0;
            cEm00_setState(self, 1, 0x13, 0);
            return 1;
        case 0x14:
            cEm00_setState(self, 1, 0xA, 1);
            return 1;
        case 0x55:
            cEm00_setState(self, 1, 3, 2);
            return 1;
        case 0xD:
            cEm00_setState(self, 1, 4, 0);
            return 1;
        }
    }
    if (self->vital <= 0 || self->counterVital <= 0) {
        switch (cDamageTake_kind(EM_TAKE(self))) {
        case 2: case 3: case 4: case 5: case 7: case 0x2C: case 0x2D: case 0x2E:
            if (self->moveFlags & 8) {
                cEm00_setState(self, 2, 1, 0);
            } else {
                cEm00_setState(self, 2, 0, 0);
            }
            return 1;
        case 0x12: case 0x15: case 0x17: case 0x1B:
            EM_FLINCH7(self, 0);
        case 0x11: case 0x16: case 0x18:
            EM_FLINCH7(self, 1);
        case 1:
        default:
            cEm00_setState(self, 1, 3, 0);
            return 1;
        case 8:
            cEm00_setState(self, 1, 8, 0);
            return 1;
        case 9: case 0x1C: case 0x30: case 0x52:
            cEm00_setState(self, 1, 8, 2);
            return 1;
        case 0xA: case 0xB:
            cEm00_setState(self, 1, 8, 3);
            return 1;
        case 0x33: case 0x35:
            cEm00_setState(self, 1, 3, 0);
            return 1;
        case 0x13: case 0x53:
            cEm00_setState(self, 1, 0xA, 0);
            return 1;
        case 0x54:
            self->vital = 0;
            cEm00_setState(self, 1, 0x13, 0);
            return 1;
        case 0x14:
            cEm00_setState(self, 1, 0xA, 1);
            return 1;
        case 0x55:
            cEm00_setState(self, 1, 3, 2);
            return 1;
        case 0xD:
            cEm00_setState(self, 1, 4, 0);
            return 1;
        }
    }

    if (ReturnZero_20D138(self)) {
        return 1;
    }
    if (func_0020CAC8(self, 0)) {
        return 0;
    }
    if (func_0020D398(self)) {
        return 0;
    }
    if (func_0020CD00(self)) {
        return 0;
    }
    if (func_0020D140(self)) {
        return 0;
    }
    switch (cDamageTake_kind(EM_TAKE(self))) {
    default:
        if (func_0024BF20(self)) {
            return 1;
        }
        if (func_0026F1D8(self) || (self->moveFlags & 0x100)) {
            switch (self->emNo) {
            default:
                cEm00_setState(self, 1, 1, 0);
                return 1;
            case 0x20F: case 0x210: case 0x211: case 0x226:
            case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
                cEm00_setState(self, 1, 8, 4);
                return 1;
            }
        }
        switch (self->emNo) {
        case 0x20F: case 0x210: case 0x211: case 0x226:
        case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            cEm00_setState(self, 1, 8, 4);
            return 1;
        }
        switch (cDamageTake_kind(EM_TAKE(self))) {
        case 2: case 3: case 4: case 5:
            cEm00_setState(self, 1, 1, 0);
            return 1;
        }
        cEm00_setState(self, 1, 0, 0);
        return 1;
    case 0x2C:
        if (irand() & 1) {
            cEm00_setState(self, 1, 0, 1);
        } else {
            cEm00_setState(self, 1, 1, 1);
        }
        return 1;
    case 0x11: case 0x12: case 0x15: case 0x16:
        if (func_0024BF20(self)) {
            return 1;
        }
        strong = 0;
        if (func_0026F1D8(self) || (self->moveFlags & 0x100)) {
            strong = 1;
        }
        switch (self->emNo) {
        case 0x260: case 0x264: case 0x265:
            cEm00_setState(self, 1, 0, 0);
            return 1;
        case 0x20F: case 0x210: case 0x211: case 0x226:
        case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            strong = 1;
            break;
        }
        if (strong) {
            switch (cDamageTake_kind(EM_TAKE(self))) {
            case 0x12: case 0x15:
            default:
                EM_FLINCH7(self, 0);
            case 0x11: case 0x16:
                EM_FLINCH7(self, 1);
            }
        }
        switch (cDamageTake_kind(EM_TAKE(self))) {
        case 0x15:
        default:
            cEm00_setState(self, 1, 2, 0);
            return 1;
        case 0x16:
            cEm00_setState(self, 1, 2, 1);
            return 1;
        case 0x11: case 0x12:
            cEm00_setState(self, 1, 1, 0);
            return 1;
        }
    case 0x17: case 0x18: case 0x1B:
        if (func_0024BF20(self)) {
            return 1;
        }
        strong = 0;
        if (func_0026F1D8(self) || (self->moveFlags & 0x100)) {
            strong = 1;
        }
        switch (self->emNo) {
        case 0x260: case 0x264: case 0x265:
            cEm00_setState(self, 1, 0, 0);
            return 1;
        case 0x20F: case 0x210: case 0x211: case 0x226:
        case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            strong = 1;
            break;
        }
        if (self->slowFlinch == 0 && cCoreSave_getGameLevel(&D_00569B70) <= 4) {
            strong = 1;
        }
        if (strong) {
            switch (cDamageTake_kind(EM_TAKE(self))) {
            default:
                EM_FLINCH7(self, 0);
            case 0x18:
                EM_FLINCH7(self, 1);
            }
        }
        switch (cDamageTake_kind(EM_TAKE(self))) {
        case 0x18:
        default:
            cEm00_setState(self, 1, 2, 1);
            return 1;
        case 0x17: case 0x1B:
            cEm00_setState(self, 1, 2, 0);
            return 1;
        }
    case 1: case 6: case 0xE: case 0x10: case 0x19: case 0x1A:
        if (func_0026F1D8(self) || (self->moveFlags & 0x100)) {
            switch (self->emNo) {
            default:
                cEm00_setState(self, 1, 3, 0);
                return 1;
            case 0x260: case 0x264: case 0x265:
                cEm00_setState(self, 1, 1, 0);
                return 1;
            }
        }
        switch (self->emNo) {
        case 0x20F: case 0x210: case 0x211: case 0x226:
        case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            cEm00_setState(self, 1, 3, 0);
            return 1;
        case 0x260: case 0x264: case 0x265:
            switch (cDamageTake_kind(EM_TAKE(self))) {
            case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 0xA:
            case 0xB: case 0xC: case 0xD: case 0xF: case 0x11: case 0x12: case 0x13:
            case 0x14: case 0x15: case 0x16: case 0x17: case 0x18: case 0x19: case 0x1A:
            default:
                cEm00_setState(self, 1, 0, 0);
                return 1;
            case 1: case 0xE: case 0x10:
                cEm00_setState(self, 1, 1, 0);
                return 1;
            }
        }
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1: case 2: case 3: case 4:
            switch (self->emNo) {
            case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218:
            case 0x220: case 0x221: case 0x222: case 0x223: case 0x245: case 0x246:
            case 0x247: case 0x24F: case 0x250: case 0x251: case 0x260: case 0x264:
            case 0x265: case 0x278: case 0x279:
                break;
            default:
                switch (cDamageTake_kind(EM_TAKE(self))) {
                case 0x19:
                    break;
                default:
                    if (self->slowFlinch == 0 && cCoreSave_getGameLevel(&D_00569B70) < 5) {
                        cEm00_setState(self, 1, 3, 0);
                        return 1;
                    }
                    break;
                case 0x1A:
                    if (self->slowFlinch == 0 && cCoreSave_getGameLevel(&D_00569B70) < 5) {
                        cEm00_setState(self, 1, 3, 0);
                        return 1;
                    }
                    break;
                }
                break;
            }
            break;
        case 5:
            break;
        }
        cEm00_setState(self, 1, 1, 0);
        return 1;
    case 0xC: case 0xF:
        if (func_0026F1D8(self) || (self->moveFlags & 0x100)) {
            switch (self->emNo) {
            case 0x260: case 0x264: case 0x265:
                cEm00_setState(self, 1, 1, 0);
                return 1;
            }
            cEm00_setState(self, 1, 4, 0);
            return 1;
        }
        switch (self->emNo) {
        case 0x260: case 0x264: case 0x265:
            cEm00_setState(self, 1, 1, 0);
            return 1;
        }
        cEm00_setState(self, 1, 3, 0);
        return 1;
    case 0xD:
        if (func_0026F1D8(self) || (self->moveFlags & 0x100)) {
            switch (self->emNo) {
            case 0x260: case 0x264: case 0x265:
                cEm00_setState(self, 1, 1, 0);
                return 1;
            }
            cEm00_setState(self, 1, 4, 0);
            return 1;
        }
        switch (self->emNo) {
        case 0x260: case 0x264: case 0x265:
            cEm00_setState(self, 1, 1, 0);
            return 1;
        }
        cEm00_setState(self, 1, 4, 0);
        return 1;
    case 8:
        switch (self->emNo) {
        case 0x264: case 0x265:
            cEm00_setState(self, 1, 0, 0);
            return 1;
        }
        if (func_0026F1D8(self) || (self->moveFlags & 0x100)) {
            cEm00_setState(self, 1, 8, 2);
            return 1;
        }
        if (D_005CB010) {
            cEm00_setState(self, 1, 8, 0);
            return 1;
        }
        if (func_0020DA18(self)) {
            return 0;
        }
        switch (self->emNo) {
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218:
        case 0x220: case 0x221: case 0x222: case 0x223: case 0x245: case 0x246:
        case 0x247: case 0x24F: case 0x250: case 0x251: case 0x264: case 0x265:
        case 0x278: case 0x279:
            cEm00_setState(self, 1, 1, 0);
            return 1;
        }
        cEm00_setState(self, 1, 8, 0);
        return 1;
    case 0xA: case 0xB:
        switch (self->emNo) {
        case 0x264: case 0x265:
            cEm00_setState(self, 1, 0, 0);
            return 1;
        }
        if (func_0026F1D8(self) || (self->moveFlags & 0x100)) {
            cEm00_setState(self, 1, 8, 3);
            return 1;
        }
        if (func_0020DA18(self)) {
            return 0;
        }
        cEm00_setState(self, 1, 8, 3);
        return 1;
    case 9: case 0x1C: case 0x30: case 0x52:
        cEm00_setState(self, 1, 8, 2);
        return 1;
    case 0x55:
        cEm00_setState(self, 1, 3, 2);
        return 1;
    case 0x2E:
        cEm00_setState(self, 1, 0x11, 0);
        return 1;
    case 0x2F:
        switch (self->emNo) {
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218:
        case 0x220: case 0x221: case 0x222: case 0x223: case 0x245: case 0x246:
        case 0x247: case 0x24F: case 0x250: case 0x251: case 0x260: case 0x264:
        case 0x265: case 0x278: case 0x279:
            cEm00_setState(self, 1, 0x11, 0);
            return 1;
        }
        cEm00_setState(self, 1, 3, 0);
        return 1;
    case 0x13: case 0x14:
        switch (self->emNo) {
        case 0x20F: case 0x210: case 0x211: case 0x226:
        case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            cEm00_setState(self, 1, 0xA, 0);
            return 1;
        case 0x260: case 0x264: case 0x265:
            cEm00_setState(self, 1, 0, 0);
            return 1;
        }
        if (func_0026F1D8(self) || (self->moveFlags & 0x100)) {
            if (cDamageTake_kind(EM_TAKE(self)) == 0x14) {
                cEm00_setState(self, 1, 0xA, 1);
                return 1;
            }
            cEm00_setState(self, 1, 0xA, 0);
            return 1;
        }
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            cEm00_setState(self, 1, 1, 0);
            return 1;
        }
        cEm00_setState(self, 1, 0xA, 0);
        return 1;
    case 0x2A:
        switch (self->emNo) {
        default:
            cEm00_setState(self, 1, 1, 0);
            return 1;
        case 0x20F: case 0x210: case 0x211: case 0x226:
        case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            cEm00_setState(self, 1, 3, 0);
            return 1;
        }
    case 0x31:
        switch (self->emNo) {
        default:
            cEm00_setState(self, 1, 1, 0);
            return 1;
        case 0x20F: case 0x210: case 0x211: case 0x226:
        case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            cEm00_setState(self, 1, 3, 0);
            return 1;
        }
    case 0x53:
        cEm00_setState(self, 1, 0xA, 0);
        return 1;
    case 0x54:
        self->vital = 0;
        cEm00_setState(self, 1, 0x13, 0);
        return 1;
    case 0x32: case 0x34: case 0x36:
        switch (self->emNo) {
        default:
            cEm00_setState(self, 1, 1, 0);
            return 1;
        case 0x20F: case 0x210: case 0x211: case 0x226:
        case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            cEm00_setState(self, 1, 3, 0);
            return 1;
        }
    case 0x33: case 0x35:
        switch (self->emNo) {
        default:
            cEm00_setState(self, 1, 3, 0);
            return 1;
        case 0x20F: case 0x210: case 0x211: case 0x226:
        case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
            cEm00_setState(self, 1, 4, 0);
            return 1;
        }
    }
}
#else
INCLUDE_ASM("nonmatching", func_0020A178);
#endif
