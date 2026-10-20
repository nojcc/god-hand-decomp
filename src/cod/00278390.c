/* sn-2.95.3-136: enemy per-frame update: player distance, run the current phase handler, swap
 * which of the two linked parts is shown (0x3AC bit 15), update the model and IK and keep the
 * follow position in step with the root. Same layout as 00278390.c. */
extern int D_00747A78;
extern char D_00462FC0[];
extern char *Getplayer(void);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void func_00278570(char *self);
extern void cObjBase_SetSeqEffect(void *a0);
extern void func_00279B20(char *self);
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);

#include "godhand/emPhaseTable.h"

extern EmPhaseTable D_003BFB00;

__attribute__((section(".text.func_00278390")))
void func_00278390(char *s0)
{
    char *e;
    int i8;
    int f0;
    int type; int arg; void (*fp)(int); long entry;
    float *src;
    float *dst;

    if (D_00747A78 & 0x40000000)
        return;
    *(float *)(s0 + 0x618) = capVu0MagnitudeSqXZ(*(void **)(Getplayer() + 0xF0), *(void **)(s0 + 0xF0));
    func_00278570(s0);
    *(unsigned int *)(s0 + 0x1560) &= ~2;

    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BFB00 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (void (*)(int))(int)(entry >> 32);
    } else {
        fp = *(void (**)(int))((char *)&D_003BFB00 + i8 + 4);
    }
    f0 = D_003BFB00.e[*(unsigned char *)(s0 + 0x2F4)].adjust;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));

    if (*(unsigned short *)(s0 + 0x3AC) & 0x8000) {
        if (*(char **)(s0 + 0x156C) != 0)
            *(unsigned int *)(*(char **)(s0 + 0x156C) + 0x380) &= ~1;
        if (*(char **)(s0 + 0x1570) != 0)
            *(unsigned int *)(*(char **)(s0 + 0x1570) + 0x380) |= 1;
    } else {
        if (*(char **)(s0 + 0x156C) != 0)
            *(unsigned int *)(*(char **)(s0 + 0x156C) + 0x380) |= 1;
        if (*(char **)(s0 + 0x1570) != 0)
            *(unsigned int *)(*(char **)(s0 + 0x1570) + 0x380) &= ~1;
    }

    cObjBase_SetSeqEffect(s0);
    func_00279B20(s0);
    cModel_calcParts(s0);
    IK_InverseKinematics(s0 + 0x448, s0);
    cModel_calcWorldParts(s0);
    cCollisionSolidManage_SetActive(D_00462FC0, s0, 0);

    src = *(float **)(s0 + 0xF0);
    dst = (float *)(s0 + 0x490);
    if (dst != src) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
}
