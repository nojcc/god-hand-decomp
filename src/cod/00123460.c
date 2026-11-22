/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cObjBase.h"
#include "godhand/cOmWeapon.h"
#include "godhand/gameWork.h"
#include "godhand/pl00.h"
#include "godhand/player.h"
#include "godhand/globals.h"

extern void KillEffect(int owner, int id, int mode);
extern void SetMotionStep(void *self, float step);
extern void cOmWeapon_kickOff(cOmWeapon *self);


/* The player's per-frame heat upkeep: drop the weapon in hand unless flags15F4 bit 0x20 is set,
 * refill the gauge (and add a god item, up to 3) while GameSys bit 0x80000 is set, drain the gauge
 * in heat mode, and pick the player's effect by flags15F4 bit 0x20, the gauge level and the
 * costume (unk5F2: 0 none, 1 effect 0x25/0x73, 3 effect 0x21/0x72). Nothing past the weapon runs
 * in modes 5 and 6. */
__attribute__((section(".text.func_00123460")))
void func_00123460(pl00 *self)
{
    float g;
    int ph;

    g = D_003BD4A0;
    if (self->weapon != 0) {
        if ((self->flags15F4 & 0x20) == 0) {
            cOmWeapon_kickOff(self->weapon);
            self->weapon = 0;
            cCoreSave_clearPaper(&D_00569B70);
        }
    }
    ph = self->base.mode;
    if (ph == 5) {
        return;
    }
    if (ph == 6) {
        return;
    }

    if (D_00747A2C.unk00 & 0x80000) {
        cHeatSys_SetHeatGage(&D_005CB000, D_005CB000.max);
        if (cCoreSave_getGodItemNum(&D_00569B70) < 3) {
            cCoreSave_addGodItem(&D_00569B70, 1);
        }
    }

    {
        int f1 = self->flags15F4;
        int locked = f1 & 0x200;
        int drain = (locked == 0);
        cHeatSys *h = &D_005CB000;

        if (h->mode != 0) {
            if (drain) {
                if (f1 & 0x80000) {
                    g = g * 0.25f;
                }
                cHeatSys_SubHeatGage(h, 1, g * self->base.speedRate);
            }
        }
    }

    if (self->flags15F4 & 0x20) {
        if (cHeatSys_GetHeatLv(&D_005CB000) == 0) {
            if (self->unk5F2 != 0) {
                KillEffect((int)self, 3, 2);
                self->unk5F2 = 0;
            }
        } else if (self->unk5F2 != 1) {
            KillEffect((int)self, 3, 2);
            self->unk5F2 = 1;
            switch (cCoreSave_getCostumeNo(&D_00569B70)) {
            case 0:
            case 2:
            case 4:
            case 6:
            default:
                SetEffect(0, 0x25, Getplayer(), 0, 3, 0xFFFFFFFFu);
                break;
            case 1:
            case 3:
            case 5:
            case 7:
                SetEffect(0, 0x73, Getplayer(), 0, 3, 0xFFFFFFFFu);
                break;
            }
        }
    } else if (self->unk5F2 != 3) {
        self->unk5F2 = 3;
        switch (cCoreSave_getCostumeNo(&D_00569B70)) {
        case 0:
        case 2:
        case 4:
        case 6:
        default:
            SetEffect(0, 0x21, self, 0, 3, 0xFFFFFFFFu);
            break;
        case 1:
        case 3:
        case 5:
        case 7:
            SetEffect(0, 0x72, Getplayer(), 0, 3, 0xFFFFFFFFu);
            break;
        }
    }

    self->unk5DC = 1.0f;
    self->base.speedRate = 1.0f;
    SetMotionStep(self, 1.0f);
}
