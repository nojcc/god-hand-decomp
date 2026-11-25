/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00Fn.h"
#include "godhand/player.h"

extern int Obj0000_Get_Field_5FC_NE_Zero_12C748(void *a0);
extern int irand(void);

/* After enough hits of the listed kinds (a random count that drops with the
 * game level), restore hp from counterVital, capped at hpMax, and start
 * func_00274238's kind 1; 1 when it did. */
__attribute__((section(".text.func_0020D140")))
int func_0020D140(cEm00 *self)
{
    unsigned short seq;
    cDamageTake *take;
    int kind;
    int vital;
    unsigned int lim;
    int ok;

    if (Obj0000_Get_Field_5FC_NE_Zero_12C748(Getplayer()) != 0) {
        return 0;
    }
    if (0.0f < self->unk1740) {
        return 0;
    }
    seq = self->seqFlags;
    if ((seq & 8) != 0) {
        return 0;
    }
    if ((seq & 0x20) != 0) {
        return 0;
    }
    if ((seq & 4) != 0) {
        return 0;
    }
    take = self->unk698;
    kind = take->kind;
    switch (kind) {
    case 1: case 2: case 3: case 4:
    case 7: case 8:
    case 12:
    case 14:
    case 17: case 18: case 19:
    case 21: case 22: case 23: case 24: case 25: case 26: case 27:
    case 43:
        break;
    case 85: /* retail's table runs up to kind 85 */
    default:
        return 0;
    }
    if (self->unk17BB == 0) {
        goto ret0;
    }
    if (self->unk17BB != 1) {
        return 0;
    }
    if (D_005CB010 != 0) {
        return 0;
    }
    if (func_0026F1D8(self) != 0) {
        return 0;
    }
    if ((self->seqFlags & 0x100) != 0) {
        return 0;
    }
    if (self->counterVital <= 0) {
        return 0;
    }
    switch (cCoreSave_getGameLevel(&D_00569B70)) {
    case 1:
    default:
        lim = (irand() & 3) + 5;
        break;
    case 2:
        lim = (irand() & 3) + 4;
        break;
    case 3:
    case 4:
        lim = (irand() & 3) + 3;
        break;
    case 5:
        lim = (irand() & 3) + 2;
        break;
    }
    if (self->slowFlinch != 0) {
        lim -= 2;
    }
    self->unk17BF++;
    if (self->unk17BF > 100) {
        self->unk17BF = 100;
    }
    if (self->unk17BF < lim) {
        return 0;
    }
    ok = 1;
    if (1.5707964f < self->unk760) {
        ok = 0;
    }
    if ((irand() & 3) != 0) {
        ok = 0;
    }
    if (ok == 0) {
        return 0;
    }
    vital = self->counterVital;
    if (vital >= self->hpMax) {
        self->hp = self->hpMax;
    } else {
        self->hp = vital;
    }
    func_00274238(self, 1);
    self->hitSeKey = 0;
    self->hitSeSlot = -1;
    self->unk17BF = (unsigned int)irand() % 3;
    return 1;
ret0: /* returning straight from the unk17BB test instead changes the code */
    return 0;
}
