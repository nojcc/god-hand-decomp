/* sn-2.95.3-136: func_001B67D0, enemy setup with a three-sphere (radius 0.25) damage-give volume along z, the give attributes 0x41/0x14/0xF0 and a forward direction. */
#include "godhand/cDamageManage.h"
#include "godhand/cOmHitVolumeSetup.h"
#include "godhand/cDamageGive.h"
#include "godhand/vecInline.h"

/* An enemy whose attack is a damage-give volume of three spheres along z. */
typedef struct cOmGiveSpheres {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x620 - 0x5E0];
    cDamageGive *give;                  /* 0x620 */
} cOmGiveSpheres;

__attribute__((section(".text.func_001B67D0")))
int func_001B67D0(cOmGiveSpheres *self)
{
    cVec v[4];
    cVec *t;
    cVec *a;
    cVec *b;
    void *give;
    cDamageGive *u;

    func_001B6FB8((cOmHitVolume *)self);
    v[0].x = 0.0f;
    v[0].y = 0.0f;
    v[0].z = 0.5f;
    v[0].w = 1.0f;
    t = &v[1];
    a = t;
    v[1].x = 0.0f;
    a->y = 0.0f;
    a->z = 0.0f;
    a->w = 1.0f;
    t = &v[2];
    b = t;
    v[2].x = 0.0f;
    b->y = 0.0f;
    b->z = -0.5f;
    b->w = 1.0f;
    t = &v[3];
    v[3].x = 0.0f;
    v[3].y = 0.0f;
    t->z = 1.0f;
    t->w = 1.0f;
    give = cDamageManage_CreateDamageGive(&D_00574380, 2, self);
    self->give = give;
    if (give != 0) {
        cDamageUnit_AddDamageCollSphere(give, self->base.mtx, &v[0], 0.25f);
        cDamageUnit_AddDamageCollSphere((cDamageUnit *)self->give, self->base.mtx, a, 0.25f);
        cDamageUnit_AddDamageCollSphere((cDamageUnit *)self->give, self->base.mtx, b, 0.25f);
        cDamageUnit_SetDamageCollActive((cDamageUnit *)self->give, 0);
        self->give->flags |= 1;
        self->give->kind = 0x41;
        self->give->power = 0x14;
        u = self->give;
        u->unk44 = 0xF0;
        u->unk40 = 0;
        vec3_copy(&self->give->hitVec.x, &v[3].x);
    }
    self->base.flags2 &= ~1;
    return 1;
}
