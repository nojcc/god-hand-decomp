/* sn-2.95.3-136: func_00183650, enemy setup with a unit damage-take box, a radius 2 damage-give sphere and the enemy work defaults. */
#include "godhand/emDamageVol.h"

extern void *cDamageManage_CreateDamageGive(void *mgr, int kind, void *owner);
extern int cDamageUnit_AddDamageCollSphere(void *unit, void *mtx, float *ofs, float r);
extern int cDamageUnit_SetDamageCollActive(void *unit, int on);

__attribute__((section(".text.func_00183650")))
int func_00183650(EmDmgVol *em)
{
    float f[16];
    float *m;
    float *nv;
    void *slot;
    void *give;
    float *ov;
    float *t;
    float one;

    func_001B6FB8(em);
    one = 1.0f;
    t = &f[4];
    m = &f[8];
    f[0] = one;
    f[1] = one;
    f[2] = one;
    f[3] = one;
    f[4] = one;
    f[5] = one;
    f[6] = one;
    t[3] = one;
    f[8] = 0.0f;
    f[9] = 0.0f;
    f[10] = 0.0f;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(D_00574380, em, 2);
    em->dmgTake = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, em->base.mtx, m, nv, t);
    }
    give = cDamageManage_CreateDamageGive(D_00574380, 0, (char *)em);
    em->dmgGive = give;
    if (give != 0) {
        ov = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        ov[3] = one;
        cDamageUnit_AddDamageCollSphere(give, em->base.mtx, ov, 2.0f);
        *(short *)(((char *)em->dmgGive) + 0x46) = 0x2E;
        *(int *)(((char *)em->dmgGive) + 0x4C) = 0;
        cDamageUnit_SetDamageCollActive(em->dmgGive, 0);
    }
    em->base.hpMax = 1;
    em->base.hp = 1;
    em->sub = em->subBuf;
    em->subKind = 1;
    em->unk5EC = 7;
    em->unk5E8 = 0;
    em->target = -1;
    em->unk5E4 = 0;
    em->unk5F0 = 0;
    em->unk5F6 = 0;
    em->base.flags2 |= 2;
    func_001C28A0(em);
    return 1;
}
