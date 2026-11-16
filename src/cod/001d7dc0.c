/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/Poker.h"
#include "godhand/cSnd.h"

extern void SetBlendField4BCColor_1DDC60(Poker *self, int a1);
extern int D_007474A0;

/* sn-2.95.3-136 matched TU. */















__attribute__((section(".text.func_001D7DC0")))
void func_001D7DC0(Poker *self) {
    char *g;

    switch (self->phase) {
    case 0:
        func_001DD910(self, 0);
        SetBlendField4BCColor_1DDC60(self, 1);
        self->phase = self->phase + 1;
        /* fallthrough */
    case 1:
        g = (char *)&D_007474A0;
        if (*(long *)(g + 0x1B0) & 0xCC0000C000000L) {
            if (self->bet < self->betMax) {
                func_001DD910(self, 1);
                SetBlendField4BCColor_1DDC60(self, 0);
                self->phase = 0;
                self->state = 1;
            }
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
        } else if (*(long *)(g + 0x1B0) & 0x3300003000000L) {
            func_001DD910(self, 1);
            SetBlendField4BCColor_1DDC60(self, 0);
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            self->phase = 0;
            self->state = 4;
        } else if (*(long *)(g + 0x1A0) & 0x10000000) {
            SetBlendField4BCColor_1DDC60(self, 0);
            func_001DD770(self, 2);
            func_001DD840(self, 2);
            func_001DD9E0(self, 2);
            self->phase = 0;
            self->state = 5;
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
        } else if (*(long *)(g + 0x1A0) & 0x20000000) {
            cCoreSave_addGold(&D_00569B70, 0x64, 0);
            self->bet = self->bet - 0x64;
            CustomIDWork_SetNumber_1DD218(self, self->bet);
            func_001DD770(self, 1);
            func_001DD840(self, 1);
            if (self->bet == 0) {
                func_001DD910(self, 2);
                func_001DD5A0(self, 1);
                self->phase = 0;
                self->state = 1;
            }
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x161, -1, -1, 0, 0);
        }
        break;
    }
    SetCustomIDNumberIndexed_1DD648(self, 0, self->bet ? self->bet * 0x32 : 0x32);
    SetCustomIDNumberIndexed_1DD648(self, 1, self->bet ? self->bet * 0x14 : 0x14);
    SetCustomIDNumberIndexed_1DD648(self, 2, self->bet ? self->bet * 0xF : 0xF);
    SetCustomIDNumberIndexed_1DD648(self, 3, self->bet ? self->bet * 0xA : 0xA);
    SetCustomIDNumberIndexed_1DD648(self, 4, self->bet ? self->bet * 8 : 8);
    SetCustomIDNumberIndexed_1DD648(self, 5, self->bet ? self->bet * 8 : 8);
    SetCustomIDNumberIndexed_1DD648(self, 6, self->bet ? self->bet * 3 : 3);
    SetCustomIDNumberIndexed_1DD648(self, 7, self->bet ? self->bet * 2 : 2);
}
