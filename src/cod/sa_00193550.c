/* sn-2.95.3-136: hit volume 1.18 x 1.61 x 0.67 with the origin at half the depth, the damage-take marked
 * active, and a five entry table at 0x620; returns 1. */

#include "godhand/cOmHitVolume.h"

extern void func_001B6FB8(void *self);
extern void *cDamageManage_CreateDamageTake(void *mgr, void *owner, int kind);
extern void func_001FD9D8(void *unit, void *pos, float *a, float *b, float *size);

extern int D_00574380;

__attribute__((section(".text.func_00193550")))
int func_00193550(cOmHitVolume *self) {
    float box[4];
    float sizeVec[4];
    float originVec[4];
    float origin2Vec[4];
    float *t;
    float *m;
    float *nv;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(self);
    one = 1.0f;
    ca = 1.18f;
    cb = 1.61f;
    cc = 0.67f;
    t = &sizeVec[0];
    m = &originVec[0];
    box[0] = ca;
    box[1] = cb;
    box[2] = cc;
    box[3] = one;
    sizeVec[0] = ca;
    sizeVec[1] = cb;
    sizeVec[2] = cc;
    t[3] = one;
    originVec[0] = 0.0f;
    originVec[1] = 0.0f;
    originVec[2] = box[2] * 0.5f;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, self, 2);
    self->damageTake = slot;
    if (slot != 0) {
        nv = &origin2Vec[0];
        origin2Vec[0] = 0.0f;
        origin2Vec[1] = 0.0f;
        origin2Vec[2] = 0.0f;
        nv[3] = one;
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
