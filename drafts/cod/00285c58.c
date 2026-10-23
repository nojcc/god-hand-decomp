/* NON_MATCHING func_00285C58 (sn-2.95.3-136, extern_jtbl D_00448AD0): 7 of 152 insns differ, all in the 0x200..0x2FF actor id test. Retail does two signed compares (slti 0x200, slti 0x300) into a 0/1 value and masks it with andi 0xFF; ours folds the test into one unsigned range compare. */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"

extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, void *t0, int t1, int t2, int t3);
extern void SetEffectPos(int kind, int id, void *owner, cVec *pos, int handle, float size);
extern char D_005FEE00[];

/* cEm00.h does not name 0x670 yet: the cDamageTake of the last hit. */
#define EM00_DAMAGE_TAKE(self) (*(cDamageTake **)((char *)(self) + 0x670))

/* Whether an actor id is in the 0x200..0x2FF range. */
static inline int isEnemyId(int id)
{
    return id >= 0x200 && id < 0x300;
}

/* Enemy hit reaction: take the damage of the last hit, flash, play the hit sound and effect, then switch to the
 * hurt (mode 1) or down (mode 2) state. */
__attribute__((section(".text.func_00285C58")))
void func_00285C58(cEm00 *self)
{
    cDamageTake *take;
    cOmBase *attacker;
    cOmBase *child;
    long flags;
    int strong;
    int vital;
    int kind;
    char frame[16];                     /* cOmBase_childAt stores the child count here, a dead store retail keeps */

    if (self->vital <= 0)
        return;
    take = EM00_DAMAGE_TAKE(self);
    if (take == 0)
        return;
    flags = (unsigned int)take->flags;
    if ((flags & 1) == 0 || 0.0f < self->hitFlash)
        return;
    attacker = (cOmBase *)take->attacker;
    strong = 0;
    if (attacker != 0)
        strong = attacker->actorId == 0x100;
    self->hitFlash = 3.0f;
    kind = take->kind;
    switch (kind) {
    case 0x01: case 0x02: case 0x03: case 0x04: case 0x05: case 0x06: case 0x07: case 0x08:
    case 0x09: case 0x0A: case 0x0B: case 0x0C: case 0x0D: case 0x0E: case 0x0F: case 0x10:
    case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
    case 0x19: case 0x1A: case 0x1B: case 0x1C: case 0x1D: case 0x1E: case 0x1F: case 0x20:
    case 0x21: case 0x22: case 0x23: case 0x25: case 0x26: case 0x27: case 0x29: case 0x2A:
    case 0x2B: case 0x2C: case 0x2D: case 0x2E: case 0x2F: case 0x30: case 0x31: case 0x32:
    case 0x33: case 0x34: case 0x35: case 0x36:
        strong = 1;
        break;
    default:
        self->hitFlash = 15.0f;
        break;
    }
    if (self->stepScale <= 0.0f && strong)
        self->gotoFlags |= 0x40;
    vital = self->vital;
    vital -= EM00_DAMAGE_TAKE(self)->power * 5;
    if (vital <= 0)
        vital = 0;
    if (vital >= self->vitalMax)
        self->vital = self->vitalMax;
    else
        self->vital = vital;
    cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xA, self, 0, 0, 0, 0);
    child = cOmBase_childAt((cOmBase *)self, (int *)frame, 4);
    if (child != 0)
        SetEffectPos(0x58, 0x10, 0, child->pos, -1, 1.0f);
    if (isEnemyId(attacker->actorId))
        self->hitFlash = 8.0f;
    if (vital <= 0) {
        if (self->moveFlags & 2) {
            self->mode = 2;
            self->phase = 1;
            self->stepArg = 0;
        } else {
            self->stepArg = 0;
            self->mode = 2;
            self->phase = 0;
        }
    } else if ((self->gotoFlags & 2) || (self->moveFlags & 2)) {
        self->stepArg = 0;
        self->mode = 1;
        self->phase = 1;
    } else {
        self->stepArg = 0;
        self->mode = 1;
        self->phase = 0;
    }
    self->step = 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00285C58);
#endif
