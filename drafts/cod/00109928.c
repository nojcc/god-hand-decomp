/* sn-2.95.3-136 */
#include "godhand/criStm.h"
#include "godhand/pl00.h"
#include "godhand/cGameObj.h"
#include "godhand/cEm00.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cObjBase.h"
#include "godhand/cSnd.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEmManage.h"
#include "godhand/gameWork.h"
#include "godhand/rand.h"
#include "include_asm.h"

extern char D_0041B940[]; /* "cEm00" */

/* Defined as int func_0012CAE0(cEm00 *self); it reads only the cGameObj part. */
extern int func_0012CAE0(cGameObj *self);
extern short func_0012C0F8(void *self, int power);
extern void func_00126770(char *self);
extern void pl00_clearMotionCam(void *self, int a1, int a2);

/* NON_MATCHING: 8 instructions differ, in the hit sound. Retail keeps the
 * reloaded damage record in v0 and loads the attacker before the cDamageTake
 * unk40 test; here the record lands in v1 and the attacker load moves into
 * the branch delay slot. */

#ifdef NON_MATCHING
/* The player's reaction to the hit in self->damage: damage, score, sounds,
 * effects, and the knock-back or death state for the attack kind. */
__attribute__((section(".text.func_00109928")))
void func_00109928(pl00 *self)
{
    unsigned long sysFlags = D_00747A2C.unk00;
    unsigned long noHit = (sysFlags >> 3) & 1;
    cDamageTake *dmg;
    char *attacker;
    char *owner;
    cGameObj *em;
    cOmBase *child;
    int frame[3];
    int power;

    if (noHit != 0) {
        return;
    }
    if (func_0012CAE0(&self->base) != 0) {
        return;
    }
    dmg = self->damage;
    if (dmg == 0) {
        return;
    }
    {
        long hf = dmg->flags;
        long live = hf & 1;

        if (live == 0) {
            return;
        }
    }
    if (self->base.hitFlash > 0.0f) {
        return;
    }

    attacker = dmg->attacker;
    self->comboTimer = 0;
    power = dmg->power;
    self->unk160C = 0;
    switch (cDamageTake_kind(dmg)) {
    case 0x37: /* listed in retail: the table starts at 0x37 */
        break;
    case 0x3E:
    case 0x3F:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x48:
    case 0x52:
    case 0x55:
        self->unk160C = power / 4;
        power -= power / 4;
        break;
    case 0x54:
        power = 100;
        break;
    }
    func_0012C0F8(self, power);

    dmg = self->damage;
    if (power > 0) {
        switch (cDamageTake_kind(dmg)) {
        case 0x37:
        case 0x38:
        case 0x3D:
            cCoreSave_addGameLevelPoint(&D_00569B70, -0xA0);
            break;
        case 0x44: /* retail builds a table here, which needs more listed kinds */
        case 0x45:
        case 0x46:
        default:
            cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
            break;
        }
        dmg = self->damage;
    }

    owner = dmg->attacker;
    if (~dmg->unk40) {
        cSnd_SeCall_2CBA48(&D_005FEE00, dmg->unk40, dmg->unk44, self, owner, 0, 0, 0);
    } else {
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x6E, self, 0, 0, 0, 0);
    }

    dmg = self->damage;
    em = (cGameObj *)dmg->attacker;
    switch (cDamageTake_kind(dmg)) {
    case 0x3A:
    case 0x3B:
        if (em != 0 && func_003A5678(D_0041B940, em->kindName) == 0) {
            struct cOmWeapon *weapon = ((cEm00 *)em)->unk6EC;

            if (weapon != 0 && (weapon->base.actorId == 0x363 || weapon->base.actorId == 0x3B7)) {
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x137, self, 0, 0, 0, 0);
            }
        }
        break;
    }

    cSnd_SeStop(&D_005FEE00, self->seHandle);
    self->seHandle = 0;
    if (self->damage->kind == 0x55) {
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x12B, self, 0, 0, 0, 0);
    }

    switch (cDamageTake_kind(self->damage)) {
    default:
        child = cOmBase_childAt((cOmBase *)self, frame, 4);
        if (child != 0) {
            SetEffectPos(0, 3, 0, child->pos, -1, 1.0f);
        }
        break;
    case 0x38:
    case 0x39:
        SetEffect(0, 0x4B, self, 0, -1, 0xFFFFFFFF);
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x12B, self, 0, 0, 0, 0);
        break;
    case 0x4A:
        SetEffect(0x58, 0x2A, 0, 0, -1, 0xFFFFFFFF);
        if (attacker != 0) {
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase((int *)attacker) + 0x1F), self, owner, 0, 0, 0);
        }
        break;
    case 0x4B:
        SetEffect(0xA8, 0xE, 0, 0, -1, 0xFFFFFFFF);
        if (attacker != 0) {
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x36, self, owner, 0, 0, 0);
        }
        break;
    case 0x4C:
        SetEffect(0x63, 0xE, 0, 0, -1, 0xFFFFFFFF);
        if (attacker != 0) {
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase((int *)attacker) + 0x1F), self, owner, 0, 0, 0);
        }
        break;
    case 0x4D:
        SetEffect(0xBD, 4, 0, 0, -1, 0xFFFFFFFF);
        if (attacker != 0) {
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase((int *)attacker) + 0x25), self, owner, 0, 0, 0);
        }
        break;
    }

    self->base.hitFlash = 3.0f;
    func_00126770((char *)self);
    pl00_clearMotionCam(self, 0, 0);
    switch (cDamageTake_kind(self->damage)) {
    case 0x48:
    case 0x52:
    case 0x55:
        cEmManage_SetPlBombHit(&D_005864F0);
        break;
    }

    if (self->base.hp <= 0) {
        switch (cDamageTake_kind(self->damage)) {
        case 0x3B:
        case 0x3E:
        case 0x48:
        case 0x52:
        case 0x54:
        case 0x55:
            self->base.mode = 2;
            self->base.phase = 1;
            self->base.step = 0;
            self->base.stepArg = 0;
            break;
        case 0x41:
            self->base.mode = 2;
            self->base.phase = 1;
            self->base.step = 0;
            self->base.stepArg = 1;
            break;
        case 0x42:
            self->base.mode = 2;
            self->base.phase = 1;
            self->base.step = 0;
            self->base.stepArg = 2;
            break;
        case 0x43:
            self->base.mode = 2;
            self->base.phase = 1;
            self->base.step = 0;
            self->base.stepArg = 3;
            break;
        case 0x44:
            self->base.mode = 2;
            self->base.phase = 1;
            self->base.step = 0;
            self->base.stepArg = 4;
            break;
        case 0x45:
            self->base.mode = 2;
            self->base.phase = 1;
            self->base.step = 0;
            self->base.stepArg = 5;
            break;
        case 0x46:
            self->base.mode = 2;
            self->base.phase = 1;
            self->base.step = 0;
            self->base.stepArg = 6;
            break;
        case 0x3F:
            self->base.stepArg = (unsigned int)irand() % 3 + 2;
            self->base.mode = 2;
            self->base.phase = 1;
            self->base.step = 0;
            break;
        case 0x37: /* listed in retail: the table starts at 0x37 */
        default:
            self->base.mode = 2;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
            break;
        }
        return;
    }

    if (self->flags15F4 & 0x800) {
        return;
    }
    switch (cDamageTake_kind(self->damage)) {
    case 0x3C:
    case 0x40:
        self->unk5F4 += 100;
        break;
    case 0x38:
    case 0x39:
        self->unk5F4 += 0x32;
        break;
    }

    switch (cDamageTake_kind(self->damage)) {
    case 0x37: /* listed in retail: the table starts at 0x37 */
    default:
        self->unk5F8 += 0x96;
        self->unk5F4 += 0x28;
        if (self->unk5F4 >= 0x82) {
            self->unk5F4 = 0;
            self->base.mode = 1;
            self->base.phase = 6;
            self->base.step = 0;
            self->base.stepArg = 0;
        } else {
            self->base.mode = 1;
            self->base.phase = 1;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    case 0x3D:
        self->unk5F8 += 0x96;
        self->unk5F4 += 0x14;
        if (self->unk5F4 >= 0x82) {
            self->unk5F4 = 0;
            self->base.mode = 1;
            self->base.phase = 6;
            self->base.step = 0;
            self->base.stepArg = 0;
        } else {
            self->base.mode = 1;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    case 0x49:
        self->base.mode = 1;
        self->base.phase = 2;
        self->base.step = 0;
        self->base.stepArg = 0;
        break;
    case 0x39:
    case 0x3B:
    case 0x3E:
    case 0x48:
    case 0x52:
    case 0x54:
    case 0x55:
        self->unk5F8 += 0x96;
        self->unk5F4 += 100;
        self->base.mode = 1;
        self->base.phase = 3;
        self->base.step = 0;
        self->base.stepArg = 0;
        break;
    case 0x41:
        self->unk5F8 += 0x96;
        self->unk5F4 += 100;
        self->base.mode = 1;
        self->base.phase = 3;
        self->base.step = 0;
        self->base.stepArg = 1;
        break;
    case 0x42:
        self->unk5F8 += 0x96;
        self->unk5F4 += 100;
        self->base.mode = 1;
        self->base.phase = 3;
        self->base.step = 0;
        self->base.stepArg = 2;
        break;
    case 0x43:
        self->unk5F8 += 0x96;
        self->unk5F4 += 100;
        self->base.mode = 1;
        self->base.phase = 3;
        self->base.step = 0;
        self->base.stepArg = 3;
        break;
    case 0x44:
        self->unk5F8 += 0x96;
        self->unk5F4 += 100;
        self->base.mode = 1;
        self->base.phase = 3;
        self->base.step = 0;
        self->base.stepArg = 4;
        break;
    case 0x45:
        self->unk5F8 += 0x96;
        self->unk5F4 += 100;
        self->base.mode = 1;
        self->base.phase = 3;
        self->base.step = 0;
        self->base.stepArg = 5;
        break;
    case 0x46:
        self->unk5F8 += 0x96;
        self->unk5F4 += 100;
        self->base.mode = 1;
        self->base.phase = 3;
        self->base.step = 0;
        self->base.stepArg = 6;
        break;
    case 0x3F:
        self->unk5F8 += 0x96;
        self->unk5F4 += 100;
        self->base.stepArg = (unsigned int)irand() % 3 + 3;
        self->base.mode = 1;
        self->base.phase = 3;
        self->base.step = 0;
        break;
    case 0x4A:
    case 0x4B:
    case 0x4C:
    case 0x4D:
        self->base.mode = 1;
        self->base.phase = 1;
        self->base.step = 0;
        self->base.stepArg = 0;
        break;
    case 0x4E:
        self->unk5F4 = 0;
        self->base.mode = 1;
        self->base.phase = 5;
        self->base.step = 0;
        self->base.stepArg = 0;
        break;
    case 0x53:
        self->unk5F8 += 0x96;
        self->unk5F4 += 100;
        self->base.mode = 1;
        self->base.phase = 1;
        self->base.step = 0;
        self->base.stepArg = 0;
        break;
    case 0x51:
        self->base.hitFlash = 15.0f;
        self->unk5F4 = 0;
        self->base.mode = 1;
        self->base.phase = 6;
        self->base.step = 0;
        self->base.stepArg = 0;
        break;
    case 0x50:
        self->base.mode = 0;
        self->base.phase = 0x46;
        self->base.step = 0;
        self->base.stepArg = 0;
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00109928);
#endif
