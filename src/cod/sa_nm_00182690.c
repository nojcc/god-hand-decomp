/* NON_MATCHING func_00182690 (sn-2.95.3-136): 25 diffs. Retail copies each damage slot to a0 before the null
 * test and builds the unit vector through v0; this C keeps the slot in v0, which shifts registers in both blocks.
 * The volume store order is also not yet searched. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/emDamageVol.h"

extern void func_001B6FB8(char *p);
extern void *cDamageManage_CreateDamageTake(void *mgr, void *owner, int kind);
extern void func_001FD9D8(void *take, void *mtx, float *ofs, float *rot, float *size);
extern void *cDamageManage_CreateDamageGive(void *mgr, int kind, void *owner);
extern int cDamageUnit_AddDamageCollSphere(void *unit, void *mtx, float *ofs, float r);
extern void cDamageUnit_SetDamageCollActive(void *unit, int active);
extern char D_00574380[];

__attribute__((section(".text.func_00182690")))
int func_00182690(char *p)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *take;
    void *give;
    float one, c0;

    func_001B6FB8(p);
    one = 1.0f;
    c0 = 3.24f;
    t = &f[4];
    m = &f[8];
    f[0] = c0;
    f[1] = one;
    f[2] = one;
    f[4] = c0;
    f[5] = one;
    f[6] = one;
    f[3] = one;
    t[3] = one;
    f[8] = 0.0f;
    f[9] = 0.0f;
    f[10] = 0.0f;
    m[3] = one;
    take = cDamageManage_CreateDamageTake(D_00574380, p, 2);
    *(void **)(p + EM_DMG_TAKE) = take;
    if (take != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        func_001FD9D8(take, p + 0x80, m, nv, t);
    }
    give = cDamageManage_CreateDamageGive(D_00574380, 0, p);
    *(void **)(p + EM_DMG_GIVE) = give;
    if (give != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        cDamageUnit_AddDamageCollSphere(give, p + 0x80, nv, 2.0f);
        *(short *)(*(char **)(p + EM_DMG_GIVE) + 0x46) = 46;
        *(int *)(*(char **)(p + EM_DMG_GIVE) + 0x4C) = 0;
        cDamageUnit_SetDamageCollActive(*(void **)(p + EM_DMG_GIVE), 0);
    }
    *(short *)(p + EM_COL_A) = 1;
    *(short *)(p + EM_COL_B) = 1;
    *(char **)(p + EM_SUB_PTR) = p + EM_SUB_BUF;
    *(unsigned char *)(p + EM_SUB_KIND) = 8;
    *(int *)(p + EM_WORK_5EC) = 7;
    *(int *)(p + EM_WORK_5E8) = 0;
    *(int *)(p + EM_WORK_5E4) = 0;
    *(int *)(p + EM_WORK_5F0) = 0;
    *(short *)(p + EM_WORK_5F6) = 0;
    *(short *)(p + EM_TARGET) = -1;
    func_001C28A0(p);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00182690);
#endif
