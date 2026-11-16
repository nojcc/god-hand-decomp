/* sn-2.95.3-136 matched TU. */
#include "godhand/BlackJack.h"

extern void CustomIDWork_SetColorAnimNormal_2D68D8(void *a0, int a1, int a2, int a3);

/* sn-2.95.3-136 matched TU. */






__attribute__((section(".text.func_001D6310")))
void func_001D6310(BlackJack *self, int a1, int a2, int a3) {
    switch (a1 & 0xFFFF) {
    default:
    case 0:
        CustomIDWork_SetOffsetPosX(&self->elem[0x14], -0x1C2);
        SetFlagOnEntries7C_1D51B8(self, 0x14, 0);
        break;
    case 1:
        CustomIDWork_SetOffsetPosX(&self->elem[0x14], 0);
        SetFlagOnEntries7C_1D51B8(self, 0x14, 1);
        break;
    case 2:
        CustomIDWork_SetMoveOffsetPosX(&self->elem[0x14], -0x1C2, 0, 0x14);
        SetFlagOnEntries7C_1D51B8(self, 0x14, 1);
        break;
    case 3:
        CustomIDWork_SetMoveOffsetPosX(&self->elem[0x14], 0, 0x1C2, 0x14);
        SetFlagOnEntries7C_1D51B8(self, 0x14, 1);
        break;
    case 4: {
        CustomIDWork *p = &self->elem[0x14];
        CustomIDWork_SetColorAnimNormal_2D68D8(p,
            (((((((a3 & ~0x00FF0000) | 0x00800000) & ~0x0000FF00) | 0x00008000) & ~0x000000FF) | 0x00000080) & ~0xFF000000),
            (((((((a2 & ~0x00FF0000) | 0x00800000) & ~0x0000FF00) | 0x00008000) & ~0x000000FF) | 0x00000080) & ~0xFF000000) | 0x80000000,
            8);
        CustomIDWork_SetOffsetPosX(p, 0);
        SetFlagOnEntries7C_1D51B8(self, 0x14, 1);
        break;
    }
    }
}
