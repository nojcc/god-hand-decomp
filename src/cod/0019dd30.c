/* sn-2.95.3-136 matched TU. */

#include "godhand/cDamageManage.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cOmHitVolume.h"

extern void func_001B6FB8(void *self);



/* Set the object up: a damage-take unit with a 0.8 x 4.6 x 0.8 volume whose origin sits at half the box depth, one hit point, a six entry table at 0x620 and the state words set; returns 1. */
__attribute__((section(".text.cOmHitVolume_setupBox08x46x08")))
int cOmHitVolume_setupBox08x46x08(cOmHitVolume *self) {
    cVec box;
    cVec sizeVec;
    cVec originVec;
    cVec origin2Vec;
    cVec *t;                           /* sizeVec, addressed through a register as retail does */
    cVec *m;
    cVec *nv;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(self);
    one = 1.0f;
    ca = 0.8f;
    cb = 4.6f;
    cc = 0.8f;
    t = &sizeVec;
    m = &originVec;
    box.x = ca;
    box.y = cb;
    box.z = cc;
    box.w = one;
    sizeVec.x = ca;
    sizeVec.y = cb;
    sizeVec.z = cc;
    t->w = one;
    originVec.x = 0.0f;
    originVec.y = 0.0f;
    originVec.z = box.z * 0.5f;
    m->w = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, self, 2);
    self->damageTake = slot;
    if (slot != 0) {
        nv = &origin2Vec;
        origin2Vec.x = 0.0f;
        origin2Vec.y = 0.0f;
        origin2Vec.z = 0.0f;
        nv->w = one;
        func_001FD9D8(slot, self->base.mtx, m, nv, t);
    }
    self->base.hpMax = 1;
    self->base.hp = 1;
    self->table = self->tableData;
    self->count = 6;
    self->unk5EC = 7;
    self->unk5E8 = 0;
    self->unk5F4 = -1;
    self->unk5E4 = 0;
    self->unk5F0 = 0;
    self->unk5F6 = 0;
    func_001C28A0(self);
    return 1;
}
