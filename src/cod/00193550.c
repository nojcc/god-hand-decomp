/* sn-2.95.3-136: func_00193550, hit volume 1.18 x 1.61 x 0.67 with the origin at half the depth, the damage-take
 * marked active, and a five entry table at 0x620. */

#include "godhand/cDamageManage.h"
#include "godhand/cOmHitVolume.h"
#include "godhand/cOmHitVolumeSetup.h"

__attribute__((section(".text.func_00193550")))
int func_00193550(cOmHitVolume *self) {
    cVec v[1];
    cVec sizeVec;
    cVec originVec;
    cVec origin2Vec;
    cVec *t;
    cVec *m;
    cVec *nv;
    void *slot;

    func_001B6FB8(self);
    t = &sizeVec;
    m = &originVec;
    v[0].x = 1.18f;
    v[0].y = 1.61f;
    v[0].z = 0.67f;
    v[0].w = 1.0f;
    sizeVec.x = 1.18f;
    sizeVec.y = 1.61f;
    sizeVec.z = 0.67f;
    t->w = 1.0f;
    originVec.x = 0.0f;
    originVec.y = 0.0f;
    originVec.z = v[0].z * 0.5f;
    m->w = 1.0f;
    slot = cDamageManage_CreateDamageTake(&D_00574380, self, 2);
    self->damageTake = slot;
    if (slot != 0) {
        nv = &origin2Vec;
        origin2Vec.x = 0.0f;
        origin2Vec.y = 0.0f;
        origin2Vec.z = 0.0f;
        nv->w = 1.0f;
        func_001FD9D8(slot, self->base.mtx, m, nv, t);
        if (self->damageTake != 0)
            *(int *)self->damageTake |= 1;
    }
    self->base.hpMax = 1;
    self->base.hp = 1;
    self->table = self->tableData;
    self->count = 5;
    self->unk5EC = 7;
    self->unk5E8 = 0;
    self->unk5F4 = -1;
    self->unk5E4 = 0;
    self->unk5F0 = 0;
    self->unk5F6 = 0;
    func_001C28A0(self);
    return 1;
}
