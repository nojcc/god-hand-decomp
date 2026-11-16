/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/CustomIDWork.h"
#include "godhand/DogRace.h"

extern int *D_003C2384;

__attribute__((section(".text.Add_nullspeed")))
int Add_nullspeed(char *a0)
{
	return sceVu0ApplyMatrix(*(int *)(a0 + 0xF0), (int)(a0 + 0x80), (int)(a0 + 0x330));
}

__attribute__((section(".text.cIDBase_release")))
int cIDBase_release(int *a0)
{
    int a1;
    a1 = a0[1];
    if (a1) {
        func_002ACF30(*D_003C2384, a1, a0[5], a0[4]);
        a0[0] = 0;
        a0[1] = 0;
        a0[2] = 0;
        return 1;
    }
    return 0;
}

__attribute__((section(".text.SetCustomIDDispOneOrAll_1EE1C0")))
void SetCustomIDDispOneOrAll_1EE1C0(DogRaceList *self, int id, int on)
{
    int i;
    if (on) {
        if (id == DOGRACE_LIST_ELEM_NUM) {
            for (i = 0; i < DOGRACE_LIST_ELEM_NUM; i++) {
                if (i != 0)
                    CustomIDWork_SetDisp(&self->elem[i], 1);
            }
        } else if (id != 0) {
            CustomIDWork_SetDisp(&self->elem[id], 1);
        }
    } else {
        if (id == DOGRACE_LIST_ELEM_NUM) {
            for (i = 0; i < DOGRACE_LIST_ELEM_NUM; i++) {
                if (i != 0)
                    CustomIDWork_SetDisp(&self->elem[i], 0);
            }
        } else if (id != 0) {
            CustomIDWork_SetDisp(&self->elem[id], 0);
        }
    }
}
