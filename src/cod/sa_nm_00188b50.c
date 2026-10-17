/* NON_MATCHING func_00188B50 (NEAR-MISS): sn; everything up to the tail matches (dead base[] vector, direct x/z + pointer y/w split); emDamageVol tail store schedule (constants 1/p+0x620/6/0xC9/-1 materialized first) not reproduced; hill climb best 10 diffs. Same idiom as func_0019AA80 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/emDamageVol.h"

extern void func_001B6FB8(char *p);
extern void *cDamageManage_CreateDamageTake(void *mgr, void *owner, int kind);
extern void func_001FD9D8(void *slot, void *mtx, float *ofs, float *rot, float *size);
extern char D_00574380[];

int func_00188B50(char *p)
{
    float base[4];
    float size[4];
    float ofs[4];
    float rot[4];
    float *sz;
    float *of;
    float *rt;
    void *slot;
    float one;

    func_001B6FB8(p);
    one = 1.0f;
    base[0] = 4.4f;
    base[1] = 1.234f;
    base[2] = 0.3f;
    base[3] = one;
    sz = size;
    size[0] = 4.4f;
    sz[1] = 1.6f;
    size[2] = 0.3f;
    sz[3] = one;
    of = ofs;
    ofs[0] = 0.0f;
    ofs[1] = 0.0f;
    ofs[2] = 0.0f;
    of[3] = one;
    slot = cDamageManage_CreateDamageTake(D_00574380, p, 2);
    *(void **)(p + EM_DMG_TAKE) = slot;
    if (slot != 0) {
        rt = rot;
        rot[0] = 0.0f;
        rot[1] = 0.0f;
        rot[2] = 0.0f;
        rt[3] = one;
        func_001FD9D8(slot, p + 0x80, of, rt, sz);
    }
    *(int *)(p + EM_WORK_5E8) = 0;
    *(int *)(p + EM_WORK_5E4) = 0;
    *(int *)(p + EM_WORK_5F0) = 0;
    *(short *)(p + EM_WORK_5F6) = 0;
    *(short *)(p + EM_COL_A) = 1;
    *(char **)(p + EM_SUB_PTR) = p + EM_SUB_BUF;
    *(unsigned char *)(p + EM_SUB_KIND) = 6;
    *(int *)(p + EM_WORK_5EC) = 0xC9;
    *(short *)(p + EM_COL_B) = 1;
    *(short *)(p + EM_TARGET) = -1;
    func_001C28A0(p);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00188B50);
#endif
