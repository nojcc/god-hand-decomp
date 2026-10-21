/* NON_MATCHING func_0019AF80 (sn-2.95.3-136): setup and part flagging match; retail keeps
 * the outer range loop un-strength-reduced (j*2 recomputed, t1 = table, t3 = table + 1) and enters the inner loop at a
 * bottom test, while this source gets a pointer-walked outer loop and a rotated inner one.
* Damage-take volume, mesh
 * layers, then flags parts in the D_004258D8 (start, count) ranges 2 and 3 with 0x8 and 0x10. */
#include "godhand/cOmBase.h"
#include "include_asm.h"

#ifdef NON_MATCHING
extern int func_001B6FB8(void *a0);
extern void *cDamageManage_CreateDamageTake(void *a0, void *a1, int a2);
extern int func_001FD9D8(void *unit, void *mtx, cVec *ofs, cVec *rot, cVec *size);
extern void cOmBase_setMeshDispFromLayer(void *a0, int a1, int a2);
extern int D_00574380;
extern unsigned char D_004258D8[];

__attribute__((section(".text.func_0019AF80")))
int func_0019AF80(char *p)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    int i, j, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    t = &f[4];
    m = &f[8];
    f[0] = 1.2f;
    f[1] = 2.0f;
    f[5] = 2.0f;
    f[2] = 1.2f;
    f[3] = 1.0f;
    f[4] = 1.2f;
    f[6] = 1.2f;
    t[3] = 1.0f;
    f[8] = 0.0f;
    f[9] = 0.0f;
    f[10] = 0.0f;
    m[3] = 1.0f;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    *(void **)(p + 0x600) = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = 1.0f;
        func_001FD9D8(slot, p + 0x80, m, nv, t);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    cOmBase_setMeshDispFromLayer(p, 0, 1);
    cOmBase_setMeshDispFromLayer(p, 1, 1);
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);
    cOmBase_setMeshDispFromLayer(p, 0x41, 0);
    for (j = 2; j < 4; j++) {
        for (i = D_004258D8[j * 2]; i < D_004258D8[j * 2] + D_004258D8[j * 2 + 1] && i < (*(int *)&f[4] = b1 = *(unsigned char *)(p + 0x2B4)); i++) {
            ok1 = i >= 0 && i < b1;
            if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
            *(int *)(obj1 + 0x154) |= 8;
            ok2 = ((*(int *)&f[4] = b2 = *(unsigned char *)(p + 0x2B4)), (i >= 0 && i < b2));
            if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
            *(int *)(obj2 + 0x154) |= 0x10;
        }
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0019AF80);
#endif
