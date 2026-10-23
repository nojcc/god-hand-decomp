/* NON_MATCHING func_00129718 (sn-2.95.3-136, extern_jtbl D_0041CE10): 159 vs 181 words. Every case body matches; retail shares the two state stores only among the mode 1 cases (each loads 1 and the phase and branches to one sb/sb pair), while the twelve mode 0 cases (28..39) keep their own sb $zero / sb phase. Ours also merges the mode 0 stores into one tail. */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/pl00.h"
#include "godhand/cEmManage.h"
#include "godhand/cSnd.h"

extern void func_00126770(char *a0);
extern void cSnd_SeStop(cSnd *self, int handle);
extern cSnd D_005FEE00;

/* pl00.h does not name these yet: the enemy holding the player and the held sound effect handle. */
#define PL00_CATCHER(p) (*(void **)((char *)(p) + 0x694))
#define PL00_SE(p)      (*(int *)((char *)(p) + 0x1620))

/* The player is caught by an enemy: pick the caught state for the hold kind, flash, stop the held sound effect and
 * tell the enemy manager the player is caught. */
__attribute__((section(".text.func_00129718")))
void func_00129718(pl00 *self, void *catcher, unsigned int kind)
{
    switch (kind) {
    default:
        return;
    case 0:
        self->base.mode = 1;
        self->base.phase = 0x8;
        break;
    case 1:
        self->base.mode = 1;
        self->base.phase = 0x9;
        break;
    case 2:
        self->base.mode = 1;
        self->base.phase = 0xA;
        break;
    case 3:
        self->base.mode = 1;
        self->base.phase = 0xB;
        break;
    case 4:
        self->base.mode = 1;
        self->base.phase = 0xC;
        break;
    case 5:
        self->base.mode = 1;
        self->base.phase = 0xD;
        break;
    case 6:
        self->base.mode = 1;
        self->base.phase = 0xE;
        break;
    case 7:
        self->base.mode = 1;
        self->base.phase = 0xF;
        break;
    case 8:
        self->base.mode = 1;
        self->base.phase = 0x10;
        break;
    case 12:
        self->base.mode = 1;
        self->base.phase = 0x11;
        break;
    case 13:
        self->base.mode = 1;
        self->base.phase = 0x12;
        break;
    case 14:
        self->base.mode = 1;
        self->base.phase = 0x13;
        break;
    case 15:
        self->base.mode = 1;
        self->base.phase = 0x14;
        break;
    case 16:
        self->base.mode = 1;
        self->base.phase = 0x15;
        break;
    case 17:
        self->base.mode = 1;
        self->base.phase = 0x16;
        break;
    case 18:
        self->base.mode = 1;
        self->base.phase = 0x17;
        break;
    case 19:
        self->base.mode = 1;
        self->base.phase = 0x18;
        break;
    case 20:
        self->base.mode = 1;
        self->base.phase = 0x19;
        break;
    case 9:
        self->base.mode = 1;
        self->base.phase = 0x1A;
        break;
    case 10:
        self->base.mode = 1;
        self->base.phase = 0x1B;
        break;
    case 11:
        self->base.mode = 1;
        self->base.phase = 0x1C;
        break;
    case 21:
        self->base.mode = 1;
        self->base.phase = 0x1D;
        break;
    case 22:
        self->base.mode = 1;
        self->base.phase = 0x1E;
        break;
    case 23:
        self->base.mode = 1;
        self->base.phase = 0x1F;
        break;
    case 24:
        self->base.mode = 1;
        self->base.phase = 0x20;
        break;
    case 25:
        self->base.mode = 1;
        self->base.phase = 0x21;
        break;
    case 26:
        self->base.mode = 1;
        self->base.phase = 0x22;
        break;
    case 27:
        self->base.mode = 1;
        self->base.phase = 0x23;
        break;
    case 28:
        self->base.mode = 0;
        self->base.phase = 0x38;
        break;
    case 29:
        self->base.mode = 0;
        self->base.phase = 0x39;
        break;
    case 30:
        self->base.mode = 0;
        self->base.phase = 0x3A;
        break;
    case 31:
        self->base.mode = 0;
        self->base.phase = 0x3B;
        break;
    case 32:
        self->base.mode = 0;
        self->base.phase = 0x3C;
        break;
    case 33:
        self->base.mode = 0;
        self->base.phase = 0x3D;
        break;
    case 34:
        self->base.mode = 0;
        self->base.phase = 0x3E;
        break;
    case 35:
        self->base.mode = 0;
        self->base.phase = 0x3F;
        break;
    case 36:
        self->base.mode = 0;
        self->base.phase = 0x40;
        break;
    case 37:
        self->base.mode = 0;
        self->base.phase = 0x41;
        break;
    case 38:
        self->base.mode = 0;
        self->base.phase = 0x42;
        break;
    case 39:
        self->base.mode = 0;
        self->base.phase = 0x43;
        break;
    case 40:
        self->base.mode = 1;
        self->base.phase = 0x24;
        break;
    case 41:
        self->base.mode = 1;
        self->base.phase = 0x25;
        break;
    }
    self->base.step = 0;
    self->base.stepArg = 0;
    func_00126770((char *)self);
    self->base.hitFlash = 5.0f;
    cSnd_SeStop(&D_005FEE00, PL00_SE(self));
    PL00_SE(self) = 0;
    cEmManage_SetPlCatched(&D_005864F0);
    cEmManage_SetSlotWait(&D_005864F0, 2);
    PL00_CATCHER(self) = catcher;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00129718);
#endif
