/* NON_MATCHING func_0019AD00 (NEAR-MISS): sibling emDamageVol style; hill-climbed tail order leaves 0x5EC sw / 0x60C sb (shared a2=7) swapped; direct swap or chain assignment make it worse */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/emDamageVol.h"

extern void func_001B6FB8(char *p);
extern void *cDamageManage_CreateDamageTake(void *mgr, void *owner, int kind);
extern void func_001FD9D8(void *slot, void *mtx, float *ofs, float *rot, float *size);
extern char D_00574380[];

int func_0019AD00(char *p)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 3.2f;
    cb = 1.1f;
    cc = 1.4f;
    t = &f[4];
    m = &f[8];
    f[4] = ca;
    f[5] = cb;
    f[6] = cc;
    f[0] = ca;
    f[1] = cb;
    f[2] = cc;
    f[3] = one;
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
    }
    *(int *)(p + EM_WORK_5E8) = 0;
    *(short *)(p + EM_COL_A) = 1;
    *(int *)(p + EM_WORK_5E4) = 0;
    *(short *)(p + EM_COL_B) = 1;
    *(char **)(p + EM_SUB_PTR) = p + EM_SUB_BUF;
    *(short *)(p + EM_TARGET) = -1;
    *(int *)(p + EM_WORK_5EC) = 7;
    *(unsigned char *)(p + EM_SUB_KIND) = 7;
    *(int *)(p + EM_WORK_5F0) = 0;
    *(short *)(p + EM_WORK_5F6) = 0;
    func_001C28A0(p);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0019AD00);
#endif
