/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/CustomIDWork.h"
#include "godhand/Poker.h"
#include "godhand/ColiseumEmSelectFn.h"

extern struct T32 D_0042B5B0;

__attribute__((section(".text.SetCustomIDDispOneOrAll_1DD258")))
void SetCustomIDDispOneOrAll_1DD258(Poker *self, int a1, int a2)
{
    int i;

    if (a2 != 0) {
        if (a1 == 0x4D) {
            for (i = 0; i < 0x4D; i++) {
                if (i != 0)
                    CustomIDWork_SetDisp(&self->elem[i], 1);
            }
        } else if (a1 != 0) {
            CustomIDWork_SetDisp(&self->elem[a1], 1);
        }
    } else {
        if (a1 == 0x4D) {
            for (i = 0; i < 0x4D; i++) {
                if (i != 0)
                    CustomIDWork_SetDisp(&self->elem[i], 0);
            }
        } else if (a1 != 0) {
            CustomIDWork_SetDisp(&self->elem[a1], 0);
        }
    }
}

__attribute__((section(".text.SetCustomIDDispOneOrAll_1F4778")))
void SetCustomIDDispOneOrAll_1F4778(ColiseumEmDisp *self, int id, int on)
{
    if (on != 0) {
        if (id == COLISEUMEM_ELEM_NUM) {
            CustomIDWork *s0 = self->elem;
            int s1;
            for (s1 = 0x6E; s1 >= 0; s1--) {
                CustomIDWork_SetDisp(s0, 1);
                s0++;
            }
        } else {
            CustomIDWork_SetDisp(&self->elem[id], 1);
        }
    } else {
        if (id == COLISEUMEM_ELEM_NUM) {
            CustomIDWork *s0 = self->elem;
            int s1;
            for (s1 = 0x6E; s1 >= 0; s1--) {
                CustomIDWork_SetDisp(s0, 0);
                s0++;
            }
        } else {
            CustomIDWork_SetDisp(&self->elem[id], 0);
        }
    }
}

struct T32 { int v[8]; };


__attribute__((section(".text.SetCustomIDNumberIndexed_1DD648")))
void SetCustomIDNumberIndexed_1DD648(Poker *self, unsigned int a1, int a2) {
    unsigned int i = a1 & 0xFFFF;
    if (i < 8) {
        struct T32 buf;
        buf = D_0042B5B0;
        CustomIDWork_SetNumber(&self->elem[buf.v[i]], a2);
    }
}
