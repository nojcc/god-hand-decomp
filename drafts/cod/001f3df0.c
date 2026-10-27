/* sn-2.95.3-136 */
/* func_001F3DF0: 120 of 120 words, 2 differ. Retail loads emA and emB with
 * lh (a sign-extended short); a plain field-to-field copy loads them with
 * lhu. */
#include "include_asm.h"
#include "godhand/cOmBase.h"
#include "godhand/cScenario.h"
#include "godhand/ColiseumEmSelect.h"

#ifdef NON_MATCHING
extern unsigned char D_0074748C;

/* Once the fade is done (bit 2 of D_0074748C), hand the pick to the fight,
 * close the screen, end the soft event and jump to the fight's room. */
__attribute__((section(".text.func_001F3DF0")))
void func_001F3DF0(ColiseumEmSelect *self)
{
    cVec pos;

    if (self->step == 0 && (D_0074748C >> 2) & 1) {
        D_00568240.emA = self->emA;
        D_00568240.emB = self->emB;
        ColiseumEmSelect_close(self);
        cScenario__endSoftEvent(D_003C2F84);
        D_00568240.entry = self->entry;
        switch (self->entry.room) {
        case 0x4F:
        default:
            pos.x = 3.6f;
            pos.y = 0.0f;
            pos.z = 0.6f;
            pos.w = 1.0f;
            cScenario_beginRoomJump_2C4548(D_003C2F84, 0x4F, &pos.x, -1.5882496f, 0, 0x80000000, 1);
            break;
        case 0x40:
            pos.x = 0.3f;
            pos.y = 1.0f;
            pos.z = 3.8f;
            pos.w = 1.0f;
            cScenario_beginRoomJump_2C4548(D_003C2F84, 0x40, &pos.x, -3.1415927f, 0, 0x80000000, 1);
            break;
        case 0x41:
            pos.x = 0.0f;
            pos.y = 1.0f;
            pos.z = 3.5f;
            pos.w = 1.0f;
            cScenario_beginRoomJump_2C4548(D_003C2F84, 0x41, &pos.x, 3.1415927f, 0, 0x80000000, 1);
            break;
        case 0x42:
            pos.x = 0.0f;
            pos.y = 1.0f;
            pos.z = 3.5f;
            pos.w = 1.0f;
            cScenario_beginRoomJump_2C4548(D_003C2F84, 0x42, &pos.x, 3.1415927f, 0, 0x80000000, 1);
            break;
        case 0x4E:
            pos.x = -3.0f;
            pos.y = 0.0f;
            pos.z = 8.4f;
            pos.w = 1.0f;
            cScenario_beginRoomJump_2C4548(D_003C2F84, 0x4E, &pos.x, -3.1415927f, 0, 0x80000000, 1);
            break;
        }
        self->step++;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001F3DF0);
#endif
