/* sn-2.95.3-136: CustomID panel helpers at 0x1ECE30 (works are 0x7C bytes from +0x60). */
#include "godhand/CustomIDPanel.h"
#include "godhand/DogRace.h"


/* Set slot 0..4's two number elements to n / 10 and n % 10 (n capped at 999). */
__attribute__((section(".text.func_001ED050")))
void func_001ED050(DogRaceResult *self, unsigned short slot, int n)
{
    CustomIDDigitTbl tbl;

    if (slot < 5) {
        if (n >= 1000) n = 999;
        tbl = D_0042BD70;
        CustomIDWork_SetNumber(&self->elem[tbl.w[slot][0]], n / 10);
        CustomIDWork_SetNumber(&self->elem[tbl.w[slot][1]], n - n / 10 * 10);
    }
}


/* Show the elements of result layout 0 or 1. */
__attribute__((section(".text.func_001ED178")))
void func_001ED178(DogRaceResult *self, unsigned char mode)
{
    int i;

    CustomIDWork_setDispAllButEight(self, DOGRACE_RESULT_ELEM_NUM, 0);
    switch (mode) {
    case 0:
        for (i = 0; i < 0x1D; i++)
            CustomIDWork_setDispAllButEight(self, i, 1);
        CustomIDWork_setDispAllButEight(self, 0x24, 1);
        CustomIDWork_setDispAllButEight(self, 0x25, 1);
        CustomIDWork_setDispAllButEight(self, 0x1D, 1);
        CustomIDWork_setDispAllButEight(self, 0x2B, 1);
        CustomIDWork_setDispAllButEight(self, 0x26, 1);
        CustomIDWork_setDispAllButEight(self, 0x27, 1);
        CustomIDWork_setDispAllButEight(self, 0x28, 1);
        CustomIDWork_setDispAllButEight(self, 0x29, 1);
        CustomIDWork_setDispAllButEight(self, 0x2A, 1);
        func_001ED4B0(self, 1);
        CustomIDOwner_setBob(self, 0);
        break;
    case 1:
        for (i = 0; i < 0x1D; i++)
            CustomIDWork_setDispAllButEight(self, i, 1);
        CustomIDWork_setDispAllButEight(self, 0x24, 1);
        CustomIDWork_setDispAllButEight(self, 0x25, 1);
        CustomIDWork_setDispAllButEight(self, 0x1E, 1);
        CustomIDWork_setDispAllButEight(self, 0x2C, 1);
        CustomIDWork_setDispAllButEight(self, 0x1F, 1);
        CustomIDWork_setDispAllButEight(self, 0x20, 1);
        CustomIDWork_setDispAllButEight(self, 0x21, 1);
        CustomIDWork_setDispAllButEight(self, 0x22, 1);
        CustomIDWork_setDispAllButEight(self, 0x23, 0);
        CustomIDWork_setDispAllButEight(self, 0x26, 1);
        CustomIDWork_setDispAllButEight(self, 0x27, 1);
        CustomIDWork_setDispAllButEight(self, 0x28, 1);
        CustomIDWork_setDispAllButEight(self, 0x29, 1);
        CustomIDWork_setDispAllButEight(self, 0x2A, 1);
        func_001ED4B0(self, 0);
        CustomIDOwner_setBob(self, 1);
        break;
    case 2:
        break;
    }
}
