/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/sceVu0.h"
#include "godhand/cIDBase.h"
#include "godhand/cIDManager.h"
#include "godhand/cGameObj.h"

extern void CustomIDWork_SetDisp(char *p, int v);

__attribute__((section(".text.Add_nullspeed")))
void Add_nullspeed(cGameObj *self)
{
	/* 0x330: the null node's step vector, past cGameObj's named fields */
	sceVu0ApplyMatrix(self->pos, self->mtx, (char *)self + 0x330);
}

/* Give the entry table back to the manager. 1 when there was one. */
__attribute__((section(".text.cIDBase_release")))
int cIDBase_release(cIDBaseObj *self)
{
    if (self->ent) {
        func_002ACF30(*D_003C2384, self->ent, self->resNo, self->id);
        self->src = 0;
        self->ent = 0;
        self->packed = 0;
        return 1;
    }
    return 0;
}

__attribute__((section(".text.SetCustomIDDispOneOrAll_1EE1C0")))
void SetCustomIDDispOneOrAll_1EE1C0(char *a0, int a1, int a2)
{
    int i;
    if (a2) {
        if (a1 == 0x1D) {
            for (i = 0; i < 0x1D; i++) {
                if (i != 0)
                    CustomIDWork_SetDisp(a0 + 0x60 + i * 0x7C, 1);
            }
        } else if (a1 != 0) {
            CustomIDWork_SetDisp(a0 + (a1 * 0x7C + 0x60), 1);
        }
    } else {
        if (a1 == 0x1D) {
            for (i = 0; i < 0x1D; i++) {
                if (i != 0)
                    CustomIDWork_SetDisp(a0 + 0x60 + i * 0x7C, 0);
            }
        } else if (a1 != 0) {
            CustomIDWork_SetDisp(a0 + (a1 * 0x7C + 0x60), 0);
        }
    }
}
