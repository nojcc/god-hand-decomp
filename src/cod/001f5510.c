/* sn-2.95.3-136 matched TU. */
#include "godhand/CustomIDWork.h"
#include "godhand/ColiseumEmSelectFn.h"


/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_001F5510")))
void func_001F5510(ColiseumEmDisp *self, int a, int b)
{
    float v;
    float t;

    func_002D65D0(&self->elem[100], &v);
    t = (float)b / (float)a;
    if (t > 1.0f) {
        t = 1.0f;
    }
    func_002D65A0(&self->elem[102], (int)(v * t));
    CustomIDWork_SetMoveOffsetPosYSin(&self->elem[97], -3, 0x10);
    CustomIDWork_SetMoveOffsetPosYSin(&self->elem[98], 3, 0x10);
}
