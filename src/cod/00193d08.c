/* sn-2.95.3-136 matched TU. */

#include "godhand/cDamageManage.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cOmHitVolume.h"

extern void func_001B6FB8(cOmHitVolume *self);

/* Set the object up: a damage-take unit with a 1.0 x 2.0 x 1.0 volume at its position, one hit point, a five entry table at 0x620 and the state words set; returns 1. */
__attribute__((section(".text.cOmHitVolume_setupBox10x20x10")))
int cOmHitVolume_setupBox10x20x10(cOmHitVolume *self)
{
    cVec box;
    cVec sizeVec;
    cVec originVec;
    cVec origin2Vec;
    cVec *size;                        /* sizeVec, addressed through a register as retail does */
    cVec *origin;
    cVec *origin2;
    void *take;
    float one, cb;

    func_001B6FB8(self);
    one = 1.0f;
    cb = 2.0f;
    size = &sizeVec;
    box.x = one;
    box.y = cb;
    box.z = one;
    box.w = one;
    sizeVec.x = one;
    sizeVec.y = cb;
    sizeVec.z = one;
    size->w = one;
    origin = &originVec;
    originVec.x = 0.0f;
    originVec.y = 0.0f;
    originVec.z = 0.0f;
    origin->w = one;
    take = cDamageManage_CreateDamageTake(&D_00574380, self, 2);
    self->damageTake = take;
    if (take != 0) {
        origin2 = &origin2Vec;
        origin2Vec.x = 0.0f;
        origin2Vec.y = 0.0f;
        origin2Vec.z = 0.0f;
        origin2->w = one;
        func_001FD9D8(take, self->base.mtx, origin, origin2, size);
    }
    self->base.hpMax = 1;
    self->base.hp = 1;
    self->table = self->tableData;
    self->count = 5;
    self->unk5EC = 0x11;
    self->unk5F6 = 0x2E;
    self->unk5E8 = 0;
    self->unk5E4 = 0;
    self->unk5F4 = -1;
    self->unk5F0 = 0;
    func_001C28A0(self);
    return 1;
}

/* Set the object up: a damage-take unit with a 1.2 x 1.5 x 1.2 volume at its position, one hit point, a six entry table at 0x620 and the state words set; returns 1. */
__attribute__((section(".text.cOmHitVolume_setupBox12x15x12")))
int cOmHitVolume_setupBox12x15x12(cOmHitVolume *self)
{
    cVec box;
    cVec sizeVec;
    cVec originVec;
    cVec origin2Vec;
    cVec *size;                        /* sizeVec, addressed through a register as retail does */
    cVec *origin;
    cVec *origin2;
    void *take;
    float one, ca, cb;

    func_001B6FB8(self);
    one = 1.0f;
    ca = 1.2f;
    cb = 1.5f;
    size = &sizeVec;
    origin = &originVec;
    box.x = ca;
    box.y = cb;
    box.z = ca;
    box.w = one;
    sizeVec.x = ca;
    sizeVec.y = cb;
    sizeVec.z = ca;
    size->w = one;
    originVec.x = 0.0f;
    originVec.y = 0.0f;
    originVec.z = 0.0f;
    origin->w = one;
    take = cDamageManage_CreateDamageTake(&D_00574380, self, 2);
    self->damageTake = take;
    if (take != 0) {
        origin2 = &origin2Vec;
        origin2Vec.x = 0.0f;
        origin2Vec.y = 0.0f;
        origin2Vec.z = 0.0f;
        origin2->w = one;
        func_001FD9D8(take, self->base.mtx, origin, origin2, size);
    }
    self->base.hpMax = 1;
    self->base.hp = 1;
    self->table = self->tableData;
    self->count = 6;
    self->unk5EC = 0x11;
    self->unk5F6 = 0x2E;
    self->unk5E8 = 0;
    self->unk5E4 = 0;
    self->unk5F4 = -1;
    self->unk5F0 = 0;
    func_001C28A0(self);
    return 1;
}

/* Set the object up: a damage-take unit with a 2.4306 x 1.1591 x 0.2 volume at its position, one hit point, a four entry table at 0x620 and the state words cleared; returns 1. */
__attribute__((section(".text.cOmHitVolume_setupBox24x12x02")))
int cOmHitVolume_setupBox24x12x02(cOmHitVolume *self)
{
    cVec box;
    cVec sizeVec;
    cVec originVec;
    cVec origin2Vec;
    cVec *size;                        /* sizeVec, addressed through a register as retail does */
    cVec *origin;
    cVec *origin2;
    void *take;
    float one, cx, cy, cz;

    func_001B6FB8(self);
    one = 1.0f;
    cx = 2.4306f;
    cy = 1.1591f;
    cz = 0.2f;
    size = &sizeVec;
    origin = &originVec;
    box.x = cx;
    box.y = cy;
    box.z = cz;
    box.w = one;
    sizeVec.x = cx;
    sizeVec.y = cy;
    sizeVec.z = cz;
    size->w = one;
    originVec.x = 0.0f;
    originVec.y = 0.0f;
    originVec.z = 0.0f;
    origin->w = one;
    take = cDamageManage_CreateDamageTake(&D_00574380, self, 2);
    self->damageTake = take;
    if (take != 0) {
        origin2 = &origin2Vec;
        origin2Vec.x = 0.0f;
        origin2Vec.y = 0.0f;
        origin2Vec.z = 0.0f;
        origin2->w = one;
        func_001FD9D8(take, self->base.mtx, origin, origin2, size);
    }
    self->base.hpMax = 1;
    self->base.hp = 1;
    self->table = self->tableData;
    self->count = 4;
    self->unk5EC = 7;
    self->unk5E8 = 0;
    self->unk5F4 = -1;
    self->unk5E4 = 0;
    self->unk5F0 = 0;
    self->unk5F6 = 0;
    func_001C28A0(self);
    return 1;
}
