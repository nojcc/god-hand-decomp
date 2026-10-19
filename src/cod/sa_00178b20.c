/* sn-2.95.3-136: func_00178B20, enemy setup with a 3.7 x 1.5 x 1.352 damage-take volume, a radius 2 damage-give sphere and the enemy work defaults. */
#include "godhand/emDamageVol.h"

extern void *cDamageManage_CreateDamageGive(void *mgr, int kind, void *owner);
extern int cDamageUnit_AddDamageCollSphere(void *unit, void *mtx, float *ofs, float r);
extern int cDamageUnit_SetDamageCollActive(void *unit, int on);

__attribute__((section(".text.func_00178B20")))
int func_00178B20(EmDmgVol *em)
{
    Vec4f v[4];             /* size twice, offset, rotation */
    Vec4f *ofs;
    Vec4f *rot;
    Vec4f *size;
    float *ov;
    void *slot;
    void *give;
    float one, c0, c1, c2;

    func_001B6FB8(em);
    one = 1.0f;
    c0 = 3.7f;
    c1 = 1.5f;
    c2 = 1.352f;
    size = &v[1];
    ofs = &v[2];
    v[0].x = c0;
    v[0].y = c1;
    v[0].z = c2;
    v[1].x = c0;
    v[1].y = c1;
    v[1].z = c2;
    v[0].w = one;
    size->w = one;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    ofs->w = one;
    slot = cDamageManage_CreateDamageTake(D_00574380, em, 2);
    em->dmgTake = slot;
    if (slot != 0) {
        rot = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        rot->w = one;
        func_001FD9D8(slot, em->base.mtx, ofs, rot, size);
    }
    give = cDamageManage_CreateDamageGive(D_00574380, 0, (char *)em);
    em->dmgGive = give;
    if (give != 0) {
        ov = &v[3].x;
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        ov[3] = one;
        cDamageUnit_AddDamageCollSphere(give, em->base.mtx, ov, 2.0f);
        *(short *)(((char *)em->dmgGive) + 0x46) = 0x2E;
        *(int *)(((char *)em->dmgGive) + 0x4C) = 0;
        cDamageUnit_SetDamageCollActive(em->dmgGive, 0);
    }
    em->base.hpMax = 1;
    em->base.hp = 1;
    em->sub = em->subBuf;
    em->subKind = 8;
    em->unk5EC = 7;
    em->unk5E8 = 0;
    em->target = -1;
    em->unk5E4 = 0;
    em->unk5F0 = 0;
    em->unk5F6 = 0;
    func_001C28A0(em);
    return 1;
}
