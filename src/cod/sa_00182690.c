#include "godhand/emDamageVol.h"

extern void *cDamageManage_CreateDamageGive(void *mgr, int kind, void *owner);
extern int cDamageUnit_AddDamageCollSphere(void *unit, void *mtx, float *ofs, float r);
extern void cDamageUnit_SetDamageCollActive(void *unit, int active);

static inline void InitDmgVol(EmDmgVol *em, int col, char *sub, int kind, int w, int t)
{
    em->unk5E8 = t;
    em->unk5E4 = 0;
    em->unk5F0 = t;
    em->unk5F6 = 0;
    em->base.hpMax = col;
    em->base.hp = col;
    em->sub = sub;
    em->subKind = kind;
    em->unk5EC = w;
    em->target = -1;
}

__attribute__((section(".text.func_00182690")))
int func_00182690(EmDmgVol *em)
{
    float f[16];
    float *m;
    float *t;
    void *take;
    void *give;
    float one, c0;

    func_001B6FB8(em);
    one = 1.0f;
    c0 = 3.24f;
    t = &f[4];
    m = &f[8];
    f[0] = c0;
    f[1] = one;
    f[2] = one;
    f[4] = c0;
    f[3] = one;
    f[5] = one;
    f[6] = one;
    t[3] = one;
    f[8] = 0.0f;
    f[9] = 0.0f;
    f[10] = 0.0f;
    m[3] = one;
    take = cDamageManage_CreateDamageTake(D_00574380, em, 2);
    em->dmgTake = take;
    if (take != 0) {
        float *nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        func_001FD9D8(take, em->base.mtx, m, nv, t);
    }
    give = cDamageManage_CreateDamageGive(D_00574380, 0, (char *)em);
    em->dmgGive = give;
    if (give != 0) {
        float *nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        cDamageUnit_AddDamageCollSphere(give, em->base.mtx, nv, 2.0f);
        *(short *)(((char *)em->dmgGive) + 0x46) = 46;
        *(int *)(((char *)em->dmgGive) + 0x4C) = 0;
        cDamageUnit_SetDamageCollActive(em->dmgGive, 0);
    }
    InitDmgVol((char *)em, 1, em->subBuf, 8, 7, 0);
    func_001C28A0(em);
    return 1;
}
