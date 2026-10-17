/* NON_MATCHING func_00178E18 (sn-2.95.3-136): 2 diffs. Only the 0x5F4/0x5F6 halfword stores swap in the tail;
 * every ordering of the tail stores tried by order search leaves them swapped. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/emDamageVol.h"

extern void func_001B6FB8(char *p);
extern void *cDamageManage_CreateDamageTake(void *mgr, void *owner, int kind);
extern void func_001FD9D8(void *slot, void *mtx, float *ofs, float *rot, float *size);
extern char D_00574380[];

__attribute__((section(".text.func_00178E18")))
int func_00178E18(char *p)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    float one, c0, c1;

    func_001B6FB8(p);
    one = 1.0f;
    c0 = 4.8f;
    c1 = 3.0f;
    t = &f[4];
    m = &f[8];
    f[0] = c0;
    f[1] = c1;
    f[2] = c0;
    f[5] = c1;
    f[3] = one;
    f[4] = c0;
    f[6] = c0;
    t[3] = one;
    f[8] = 0.0f;
    f[9] = 0.0f;
    f[10] = 0.0f;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(D_00574380, p, 2);
    *(void **)(p + EM_DMG_TAKE) = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, p + 0x80, m, nv, t);
        **(unsigned int **)(p + EM_DMG_TAKE) |= 1;
    }
    *(short *)(p + EM_COL_A) = 1;
    *(short *)(p + EM_COL_B) = 1;
    *(char **)(p + EM_SUB_PTR) = p + EM_SUB_BUF;
    *(unsigned char *)(p + EM_SUB_KIND) = 18;
    *(unsigned int *)(p + 0x5B8) |= 0x800;
    *(int *)(p + EM_WORK_5E8) = 0;
    *(int *)(p + EM_WORK_5EC) = 17;
    *(short *)(p + EM_WORK_5F6) = 5;
    *(int *)(p + EM_WORK_5E4) = 0;
    *(short *)(p + EM_TARGET) = -1;
    *(int *)(p + EM_WORK_5F0) = 0;
    func_001C28A0(p);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00178E18);
#endif
