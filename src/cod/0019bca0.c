/* sn-2.95.3-136 matched TU. */

#include "godhand/cDamageManage.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cOmHitVolume.h"
extern void func_001B6FB8(void *self);


/* Init: registers the object's damage-take volume (size 4 x 1 x 2) and sets its hit state fields; returns 1. */
__attribute__((section(".text.cOmHitVolume_setupLongBox")))
int cOmHitVolume_setupLongBox(cOmHitVolume *p)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    cVec *t;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 4.0f;
    cb = one;
    cc = 2.0f;
    t = &v[1];
    m = &v[2];
    v[0].x = ca;
    v[1].x = ca;
    v[0].y = cb;
    v[0].z = cc;
    v[1].z = cc;
    v[0].w = one;
    v[1].y = cb;
    t->w = one;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    m->w = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    p->damageTake = slot;
    if (slot != 0) {
        nv = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        nv->w = one;
        func_001FD9D8(slot, p->base.mtx, m, nv, t);
    }
    p->base.hpMax = 1;
    p->base.hp = 1;
    p->table = p->tableData;
    p->count = 0xC;
    p->unk5EC = 7;
    p->unk5E8 = 0;
    p->unk5F4 = -1;
    p->unk5E4 = 0;
    p->unk5F0 = 0;
    p->unk5F6 = 0;
    func_001C28A0(p);
    return 1;
}
