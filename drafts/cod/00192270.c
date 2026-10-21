/* NON_MATCHING func_00192270 (sn-2.95.3-136): 53 words. cc1 folds f[9] = cb * half
 * to the constant 1.18; retail multiplies at run time (mov.s/mul.s), which shifts the whole volume setup. */
#include "include_asm.h"

#ifdef NON_MATCHING

extern int func_001B6FB8(void *a0);
extern void *cDamageManage_CreateDamageTake(void *a0, void *a1, int a2);
extern void cDamageUnit_AddDamageCollCylinder(void *a0, void *a1, float *a2, float *a3, float f0, float f1);
extern void cOmBase_setMeshDispFromLayer(void *a0, int a1, int a2);
extern int D_00574380;

__attribute__((section(".text.func_00192270")))
int func_00192270(char *p)
{
    float f[16];
    float *m;
    float *nv;
    void *slot;

    int i, n, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    m = &f[8];
    f[1] = 2.36f;
    f[4] = 2.74f;
    f[5] = 2.36f;
    f[6] = 0.274f;
    f[0] = 2.74f;
    f[9] = f[1] * 0.5f;
    f[2] = 0.274f;
    f[3] = 1.0f;
    f[7] = 1.0f;
    f[8] = 0.0f;
    f[10] = 0.0f;
    m[3] = 1.0f;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    *(void **)(p + 0x604) = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = 1.0f;
        cDamageUnit_AddDamageCollCylinder(slot, p + 0x80, m, nv, f[5], f[4] * 0.5f);
    }
    cOmBase_setMeshDispFromLayer(p, 0, 1);
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);
    *(short *)(p + 0x602) = 30;
    i = 1;
    if (*(unsigned char *)(p + 0x2B4) != i) {
        n = 1;
        while (1) {
        ok1 = ((*(int *)&f[4] = b1 = *(unsigned char *)(p + 0x2B4)), (n >= 0 && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) |= 8;
        ok2 = ((*(int *)&f[4] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= 0 && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) |= 0x10;
        i++;
        n++;
        if (!(i < 10 && *(unsigned char *)(p + 0x2B4) != i)) break;
        }
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00192270);
#endif
