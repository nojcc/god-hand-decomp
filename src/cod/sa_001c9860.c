/* sn-2.95.3-136: gimmick per-frame update: park both damage units, sync the speed rate and the
 * timer, run the current phase handler, update the model, keep the follow positions in step and
 * die when the object falls out of the stage. Phase dispatch as sa_00281968.c. */
extern char D_005864F0[];
extern int ClearField5B4IfFlagUnset_1B76B0(char *a0);
extern void cDamageUnit_SetDamageCollActive(void *self, int active);
extern float cEmManage_GetSpeedRate(void *a0);
extern void cModel_ScrollTexture(void *a0, float f);
extern void func_001CF3A8(char *self);
extern void cModel_calcParts(void *a0);
extern void cOmBase_dieCommon(void *a0);

#include "godhand/emPhaseTable.h"

extern EmPhaseTable D_003BDE88;

__attribute__((section(".text.func_001C9860")))
void func_001C9860(char *s0)
{
    char *e;
    int i8;
    int f0;
    int type; int arg; void (*fp)(int); long entry;
    float rate;
    float *src;
    float *dst;

    if (ClearField5B4IfFlagUnset_1B76B0(s0) == 0)
        return;
    if (*(char **)(s0 + 0x650) != 0) {
        *(short *)(*(char **)(s0 + 0x650) + 0x46) = 0;
        *(int *)(*(char **)(s0 + 0x650) + 0x4C) = 0;
        cDamageUnit_SetDamageCollActive(*(void **)(s0 + 0x650), 0);
    }
    if (*(char **)(s0 + 0x658) != 0) {
        *(short *)(*(char **)(s0 + 0x658) + 0x46) = 0;
        *(int *)(*(char **)(s0 + 0x658) + 0x4C) = 0;
        cDamageUnit_SetDamageCollActive(*(void **)(s0 + 0x658), 0);
    }
    rate = cEmManage_GetSpeedRate(D_005864F0);
    *(float *)(s0 + 0x5A8) = rate;
    if (*(float *)(s0 + 0x66C) > 0.0f)
        *(float *)(s0 + 0x66C) -= rate;
    *(char *)(s0 + 0x664) = *(char *)(s0 + 0x665) = 0;

    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDE88 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (void (*)(int))(int)(entry >> 32);
    } else {
        fp = *(void (**)(int))((char *)&D_003BDE88 + i8 + 4);
    }
    f0 = D_003BDE88.e[*(unsigned char *)(s0 + 0x2F4)].adjust;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));

    cModel_ScrollTexture(s0, *(float *)(s0 + 0x5A8));
    func_001CF3A8(s0);
    cModel_calcParts(s0);

    src = *(float **)(s0 + 0xF0);
    dst = (float *)(s0 + 0x490);
    if (dst != src) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
    dst = (float *)(s0 + 0x5D0);
    src = (float *)(s0 + 0x100);
    if (dst != src) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
    if (*(int *)(s0 + 0x600) == 0 && (*(float **)(s0 + 0xF0))[1] < -1000.0f)
        cOmBase_dieCommon(s0);
    if (*(unsigned short *)(s0 + 0x2FE) == 0x390)
        *(int *)(s0 + 0x668) = 0x3E7;
}
