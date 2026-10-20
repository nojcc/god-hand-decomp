/* sn-2.95.3-136: enemy setup with two mirrored damage-take boxes on one take unit, then the
 * enemy work defaults (as sa_00192a98.c). */
#include "godhand/emDamageVol.h"

__attribute__((section(".text.func_00192D20")))
int func_00192D20(EmDmgVol *em)
{
    float f[28];
    float *b;
    float *c;
    float *d;
    float *e;
    float *g;
    float *nv;
    void *slot;
    char *mtx;
    float one, c0, c1, c2;

    func_001B6FB8(em);
    one = 1.0f;
    c0 = 0.4f;
    c1 = 1.2f;
    c2 = 2.3f;
    b = &f[4];
    c = &f[8];
    d = &f[12];
    e = &f[16];
    g = &f[20];
    f[0] = c0;
    f[2] = c2;
    f[4] = c2;
    f[1] = c1;
    f[3] = one;
    b[1] = c1;
    b[2] = c0;
    b[3] = one;
    f[8] = f[0];
    f[9] = f[1];
    f[10] = f[2];
    c[3] = one;
    f[12] = f[4];
    f[13] = f[5];
    f[14] = f[6];
    d[3] = one;
    f[16] = 0.0f;
    f[17] = 0.0f;
    e[2] = one;
    e[3] = one;
    f[20] = -1.0f;
    f[21] = 0.0f;
    f[22] = 0.0f;
    g[3] = one;
    slot = cDamageManage_CreateDamageTake(D_00574380, em, 2);
    em->dmgTake = slot;
    if (slot != 0) {
        nv = &f[24];
        mtx = em->base.mtx;
        f[24] = 0.0f;
        f[25] = 0.0f;
        f[26] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, mtx, e, nv, c);
        f[24] = 0.0f;
        f[25] = 0.0f;
        f[26] = 0.0f;
        nv[3] = one;
        func_001FD9D8(em->dmgTake, mtx, g, nv, d);
    }
    em->base.hpMax = 1;
    em->base.hp = 1;
    em->sub = em->subBuf;
    em->subKind = 6;
    em->unk5EC = 7;
    em->unk5E8 = 0;
    em->unk5E4 = 0;
    em->unk5F0 = 0;
    em->unk5F6 = 0;
    em->target = -1;
    func_001C28A0(em);
    return 1;
}
