/* sn-2.95.3-136 matched TU. */
#include "godhand/CustomIDWork.h"
#include "godhand/ColiseumEmSelectFn.h"


/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001F55C0")))
void func_001F55C0(ColiseumEmDisp *self, int a1, int a2, int a3) {
    float buf[2];
    CustomIDWork *bar;

    func_002D65D0(&self->elem[100], &buf[0]);
    bar = &self->elem[102];
    func_002D65D0(bar, &buf[1]);
    CustomIDWork_SetOffsetPosY(bar, (int)(buf[0] / (float)a1 * (float)a3));
}
