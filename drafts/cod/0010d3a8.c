/* sn-2.95.3-136 */
#include "godhand/pl00.h"
#include "godhand/cGameObj.h"
#include "godhand/cObjBase.h"
#include "godhand/cSnd.h"
#include "godhand/cHeatSys.h"
#include "godhand/player.h"
#include "godhand/gameWork.h"
#include "godhand/comboObj.h"
#include "godhand/capVu0.h"
#include "godhand/motion.h"
#include "include_asm.h"

/* NON_MATCHING: the two range tests for combos 0x6E..0x71 (the charge-time
 * switch and the attack-strength switch) branch the other way round from
 * retail, and retail starts the 0x26 effect from two separate copies of the
 * call for combos 0x2E/0x63 and 0x44. Builds with the SN assembler. */
#ifdef NON_MATCHING

/* Defined as int func_0010B2E8(BusyOwner *self, int flag); BusyOwner is its view of pl00. */
extern int func_0010B2E8(pl00 *self, int flag);
extern int ComboObj_startNext(ComboObj *self);
extern float capVu0MagnitudeXZ(void *a0, void *a1);
extern void func_00124EC0(void *obj);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern int func_00124540(void *a0, int a1);
extern void func_0010A438(void *a0);
extern int func_00123938(void *a0, int a1);
extern void InvokeVirtualAtField214AndForward_124E68(char *a0, float f12);
extern int D_003BC7D0[][5];             /* combo table, 0x14 bytes per combo */

/* Distance in the XZ plane from pos to the object the player is locked on to. */
static __inline__ float pl00_targetDistXZ(cVec *pos, cGameObj *target)
{
    return capVu0MagnitudeXZ(pos, cGameObj_vt(target)->getPos((char *)target + cGameObj_vt(target)->getPosDelta));
}

/* The same distance, squared. */
static __inline__ float pl00_targetDistSqXZ(cVec *pos, cGameObj *target)
{
    return capVu0MagnitudeSqXZ(pos, cGameObj_vt(target)->getPos((char *)target + cGameObj_vt(target)->getPosDelta));
}

/* A combo attack: start the next combo of the set, close in on the target,
 * charge while the attack buttons are held, release with the effect for the
 * combo, then pick the attack strength from the charge. */
__attribute__((section(".text.func_0010D3A8")))
void func_0010D3A8(pl00 *self)
{
    float d;
    float lim;

    if (self->base.hp <= 0) {
        self->base.hp = 1;
    }
    if (func_0010B2E8(self, 0) != 0 && self->combo == 0x5D) {
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x35, self, 0, 0, 0, 0);
        cHeatSys_AddHeatGage(&D_005CB000, 0, 16.0f);
    }

    switch (self->base.step) {
    case 0:
        func_00124540(self, 0);
        self->unk1588 = 0.0f;
        if (self->unk640 != 0) {
            d = pl00_targetDistXZ(self->base.pos, self->unk640) - 1.2f;
            lim = 0.5f;
            if (self->comboSlot == 0 && self->unk61F != 0) {
                lim = 1.0f;
            }
            if (lim < d) {
                d = lim;
            }
            if (0.0f < d) {
                self->unk1588 = d * 0.15f;
            }
        }
        self->prevCombo = self->combo;
        if (self->comboSlot == 0) {
            self->prevCombo = 0x72;
        }
        self->combo = ComboObj_startNext((ComboObj *)self);
        self->base.stepArg = 0;
        if (self->combo == 0x2D) {
            self->base.stepArg = 1;
            self->base.hitFlash = 5.0f;
            self->unk1588 = 0.0f;
        }
        self->unk15C0 = 1.0f;
        self->unk15C4 = 0.0f;
        self->unk15B0 = 1;
        self->unk15B4 = 0;
        self->unk15B8 = 1;
        self->unk5F0 = 10;
        self->base.unk568 = 999;
        self->base.unk56A = 0;
        switch (self->combo) {
        case 0x55:
        case 0x6E:
        case 0x6F:
        case 0x70:
        case 0x71:
            InitRenderStruct_2A8608(&self->base, 0, (void *)0x26, 2, 2, 0);
            break;
        case 0x44:
            self->base.unk56A = 999;
            InitRenderStruct_2A8608(&self->base, 0, (void *)0x43, 2, 2, 0);
            break;
        }
        self->unk1598 = 0.5f;
        self->base.step++;
    case 1:
        if (self->base.motionFlags & GAMEOBJ_MOTION_END) {
            self->base.unk56A = 0;
        }
        if (self->base.unk56A != 0) {
            self->base.unk56A--;
            self->flags15F4 |= 0x800;
        }
        if (self->combo == 0x44) {
            func_00124EC0(self);
        }
        if (self->base.unk568 != 0) {
            self->base.unk568--;
            InvokeVirtualAtField214AndForward_124E68((char *)self, 0.19634955f);
        }
        if (self->unk640 != 0) {
            self->unk648 = 0x14;
        }
        self->base.speedRate = 1.0f;
        self->unk5DC = 1.0f;
        if ((self->base.motionFlags & 0x80) && self->unk15B0 != 0) {
            switch (self->combo) {
            case 0x2E:
            case 0x44:
            case 0x63:
                if (self->unk15C4 <= 0.0f) {
                    self->unk15C4 = 1.0f;
                }
                break;
            case 0x55:
            case 0x6E:
            case 0x6F:
            case 0x70:
            case 0x71:
                if (self->unk15C4 <= 0.0f) {
                    self->unk15C4 = 4.0f;
                }
                break;
            }
        }
        if (0.0f < self->unk15C4 && self->unk15B0 != 0) {
            if (self->unk15B4 == 0) {
                self->unk15B4 = 1;
                switch (self->combo) {
                case 0x2E:
                case 0x44:
                case 0x63:
                    InitRenderStruct_2A8608(&self->base, 0, (void *)0x26, 2, 2, 0);
                    break;
                }
            }
            if (D_007474A0.unk000 & 0xD0) {
                switch (self->combo) {
                case 0x2E:
                case 0x63:
                default:
                    self->base.speedRate = 0.025f;
                    self->unk15C4 -= 0.025f;
                    self->unk5DC = 0.025f;
                    break;
                case 0x44:
                    self->unk5DC = 0.1f;
                    self->base.speedRate = 0.1f;
                    self->unk15C4 -= 0.025f;
                    break;
                case 0x55:
                case 0x6E:
                case 0x6F:
                case 0x70:
                case 0x71:
                    self->base.speedRate = 0.1f;
                    self->unk15C4 -= 0.1f;
                    self->unk5DC = 0.1f;
                    break;
                }
                SetMotionStep(self, self->base.speedRate);
                self->unk15C0 += 0.05f;
                if (self->unk15C4 <= 0.0f) {
                    self->unk15C0 += 1.0f;
                }
                if (1.1f <= self->unk15C0 && self->unk15B8 != 0) {
                    self->unk15B8 = 0;
                    self->seHandle = cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x11B, self, 0, 0, 0, 0);
                }
            } else {
                self->unk15C4 = 0.0f;
                self->unk15B0 = 0;
            }
            if (self->unk15C4 <= 0.0f) {
                self->unk15B0 = 0;
            }
        } else {
            if (self->base.motionFlags & (GAMEOBJ_MOTION_END | GAMEOBJ_MOTION_LOOP)) {
                KillEffect((int)Getplayer(), 2, 2);
            }
            if (self->unk15B4 != 0) {
                self->unk15B4 = 0;
                if (2.5f <= self->unk15C0) {
                    switch (self->combo) {
                    case 0x2E:
                    case 0x55:
                    case 0x63:
                    case 0x6E:
                    case 0x6F:
                    case 0x70:
                        KillEffect((int)Getplayer(), 2, 2);
                        SetEffect(0, 0x27, self, 0, -1, 0xFFFFFFFF);
                        break;
                    case 0x71:
                        KillEffect((int)Getplayer(), 2, 2);
                        SetEffect(0, 0x65, self, 0, -1, 0xFFFFFFFF);
                        break;
                    case 0x44:
                        break;
                    }
                }
                cSnd_SeStop(&D_005FEE00, self->seHandle);
                self->seHandle = 0;
            }
        }
        if (moveMotion(self)) {
            pl00_clearMotionCam(self, 1, 0);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        ((cObjBase *)self)->nullSpeed.z += self->unk1588;
        self->unk1588 *= 0.9f;
        if (self->combo == 0x63 && (self->base.motionFlags & 0x200)) {
            ((cObjBase *)self)->nullSpeed.z += self->unk1598;
            self->unk1598 *= 0.9f;
        }
        if (self->unk640 != 0 && self->base.stepArg == 0
            && pl00_targetDistSqXZ(self->base.pos, self->unk640) < 1.21f) {
            ((cObjBase *)self)->nullSpeed.x = 0.0f;
            ((cObjBase *)self)->nullSpeed.z = 0.0f;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        if (self->base.stepArg != 0) {
            cObjBase_addNullSpeed((cObjBase *)self, 1.5f);
        } else {
            cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        }
        break;
    }

    if (self->base.motionFlags & 0x10) {
        if (self->unk5F0 != 0) {
            self->unk5F0--;
        } else {
            self->comboSlot = 0;
            self->comboSet = 0;
        }
    }
    self->unk1610 = self->unk15C0;
    switch (self->combo) {
    case 0x2E:
    case 0x63:
        if (2.5f <= self->unk15C0) {
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, self->unk1660, 0xD, 0, 0x123);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, self->unk1664, 0xD, 0, 0x123);
        }
        break;
    case 0x55:
    case 0x6E:
    case 0x6F:
    case 0x70:
    case 0x71:
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 10, 10, 0, 0x123);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 10, 10, 0, 0x123);
        if (self->unk1610 < 1.5f) {
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 10, 8, 0, 10);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 10, 8, 0, 10);
        }
        if (2.5f < self->unk1610) {
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, self->moveA, 10, 9, 0, 0x123);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, self->moveB, 10, 9, 0, 0x123);
        }
        break;
    }
    func_0010A438(self);
    if (self->base.motionFlags & (GAMEOBJ_MOTION_END | GAMEOBJ_MOTION_LOOP)) {
        self->comboStage = 1;
    } else {
        if (self->comboStage != 0) {
            if (++self->comboTicks >= 5) {
                self->comboTicks = 4;
            }
            self->moveA = self->moveB = D_003BC7D0[self->combo][self->comboTicks];
        }
        self->comboStage = 0;
    }
    if (func_00123938(self, 1) != 0) {
        pl00_clearMotionCam(self, 1, 0);
    } else if (self->unk1618 != 0) {
        self->unk1603 = 2;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0010D3A8);
#endif
