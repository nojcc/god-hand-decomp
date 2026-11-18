/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/player.h"

extern int irand(void);
extern int Obj0000_Get_Field_5FC_NE_Zero_12C748(void *a0);

/* Put the enemy in phase 0x46 when its enemy number allows it, it has hp kept
 * back, the last hit was of kind 0x17, 0x18 or 0x1B and the game-level dice
 * agree (force == 1 skips the dice); 1 when it did. */
__attribute__((section(".text.func_0020CAC8")))
int func_0020CAC8(cEm00 *self, int force)
{
    cGameObj *pl = Getplayer();
    unsigned short seq;
    int kind;
    int ok;

    switch (self->unk17BC) {
    case 0:
        return 0;
    case 1:
        if ((irand() & 1) != 0) {
            return 0;
        }
        break;
    case 2:
        break;
    default:
        return 0;
    }
    if (D_005CB010 != 0) {
        return 0;
    }
    if (Obj0000_Get_Field_5FC_NE_Zero_12C748(pl) != 0) {
        return 0;
    }
    if (func_0026F1D8(self) != 0) {
        return 0;
    }
    seq = self->seqFlags;
    if ((seq & 0x100) != 0) {
        return 0;
    }
    if (self->counterVital <= 0) {
        return 0;
    }
    if (2.3561945f < self->unk760) {
        return 0;
    }
    if (self->speedRate < 1.0f) {
        return 0;
    }
    if (0.0f < self->unk1740) {
        return 0;
    }
    if ((seq & 8) != 0) {
        return 0;
    }
    if ((seq & 0x20) != 0) {
        return 0;
    }
    if ((seq & 4) != 0) {
        return 0;
    }
    kind = self->unk698->kind;
    if (kind < 0x17 || (kind >= 0x19 && kind != 0x1B)) {
        return 0;
    }
    switch (cCoreSave_getGameLevel(&D_00569B70)) {
    case 1:
    default:
        ok = ((unsigned int)irand() % 8) == 0;
        break;
    case 2:
        ok = ((unsigned int)irand() % 6) == 0;
        break;
    case 3:
    case 4:
        ok = ((unsigned int)irand() % 4) == 0;
        break;
    case 5:
        ok = ((unsigned int)irand() % 3) == 0;
        break;
    }
    if (force == 1) {
        ok = 1;
    }
    if (ok == 0) {
        return 0;
    }
    self->stepArg = 0;
    self->mode = 0;
    self->step = 0;
    self->phase = 0x46;
    return 1;
}
