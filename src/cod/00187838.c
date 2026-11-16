/* sn-2.95.3-136 matched TU. */

#include "godhand/cDamageManage.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cOmHitVolume.h"

extern void func_001B6FB8(void *a0);


#define BOX_HALF_XY 2.0f                /* half extent along x and y */
#define BOX_HALF_Z  1.6f                /* half extent along z */

/* Spawn setup of an object with a box hit area: build the box, register it with the damage manager, and set the fields the step code starts from. */
__attribute__((section(".text.cOmHitVolume_setupBox_20_16")))
int cOmHitVolume_setupBox_20_16(cOmHitVolume *self)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    cVec *t;
    void *slot;
    float one, c, w;

    func_001B6FB8(self);
    c = BOX_HALF_XY;
    one = 1.0f;
    w = BOX_HALF_Z;
    v[0].x = c;
    v[0].y = c;
    t = &v[1];
    v[0].z = w;
    v[0].w = one;
    v[1].x = c;
    v[1].y = c;
    v[1].z = w;
    t->w = one;
    m = &v[2];
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    m->w = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, self, 2);
    self->damageTake = slot;
    if (slot != 0) {
        nv = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        nv->w = one;
        func_001FD9D8(slot, self->base.mtx, m, nv, t);
    }
    self->unk5E8 = 0;
    self->base.hpMax = 1;
    self->unk5E4 = 0;
    self->unk5F0 = 0;
    self->base.hp = 1;
    self->unk5F4 = -1;
    self->table = self->tableData;
    self->count = 8;
    self->unk5EC = 0x11;
    self->unk5F6 = 0x89;
    func_001C28A0(self);
    return 1;
}
