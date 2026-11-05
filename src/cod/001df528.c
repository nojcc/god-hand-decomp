/* sn-2.95.3-136 matched TU. */
#include "godhand/PanelObj.h"
#include "godhand/CustomIDWork.h"

extern void CustomIDWork_SetColorAnimNormal_2D68D8(void *a0, int a1, int a2, int a3);
extern char D_0042B6B8[];

/* sn-2.95.3-136 matched TU. */






typedef struct { int w[3]; } T12;


__attribute__((section(".text.func_001DF528")))
void func_001DF528(PanelObj *self, unsigned char idx, unsigned short mode) {
    T12 arr;
    unsigned int i;
    int c6;
    int c7;

    if (idx < 3) {
        arr = *(T12 *)D_0042B6B8;
        for (i = 0; i < 3; i++) {
            func_001DEE60(self, arr.w[i], 0);
        }
        switch (mode) {
        default:
        case 0:
            CustomIDWork_SetOffsetPosX(&self->elem[arr.w[idx]], -0x1C2);
            break;
        case 1:
            CustomIDWork_SetOffsetPosX(&self->elem[arr.w[idx]], 0);
            func_001DEE60(self, arr.w[idx], 1);
            break;
        case 2:
            CustomIDWork_SetMoveOffsetPosX(&self->elem[arr.w[idx]], -0x1C2, 0, 0xA);
            func_001DEE60(self, arr.w[idx], 1);
            break;
        case 3:
            CustomIDWork_SetMoveOffsetPosX(&self->elem[arr.w[idx]], 0, 0x1C2, 0xA);
            func_001DEE60(self, arr.w[idx], 1);
            break;
        case 4: {
            CustomIDWork *q;
            {
            int ca = (((((((c6 & ~0x00FF0000) | 0x00800000) & ~0x0000FF00) | 0x00008000) & ~0x000000FF) | 0x00000080) & ~0xFF000000);
            int cb = (((((((c7 & ~0x00FF0000) | 0x00800000) & ~0x0000FF00) | 0x00008000) & ~0x000000FF) | 0x00000080) & ~0xFF000000) | 0x80000000;
            q = &self->elem[arr.w[idx]];
            CustomIDWork_SetColorAnimNormal_2D68D8(q, ca, cb, 8);
            }
            CustomIDWork_SetOffsetPosX(&self->elem[arr.w[idx]], 0);
            func_001DEE60(self, arr.w[idx], 1);
            break;
        }
        }
    }
}
