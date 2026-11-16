/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 */
#include "godhand/cDamageManage.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

extern void func_001B6FB8(void *self);
extern void cOmDoor_setObjCollision(void *self);

/* Set up a door-like object: 1 life, a 2.13 by 3.78 by 0.2 hit box through the damage manager, the box size kept at 0x610, its collision object and the second body at 0x650. */
#define DOORBOX_RING_OFFSET  0x650      /* second body inside the object */

typedef struct DoorBoxObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    void *damage;                       /* 0x600 */
    char unk604[0xC];
    float size[3];                      /* 0x610 */
    char unk61C[8];
    unsigned char hasBody;              /* 0x624 */
    char unk625[3];
    void *body;                         /* 0x628 */
} DoorBoxObj;

#define COMBASE_F2_BIT1  0x2            /* flags2 bit 1 */

__attribute__((section(".text.DoorBoxObj_constructWide")))
int DoorBoxObj_constructWide(DoorBoxObj *self)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    cVec *t;
    void *slot;
    float one, ca, cb, cc;
    int hp;

    func_001B6FB8(self);
    one = 1.0f;
    ca = 2.13f;
    cb = 3.78f;
    cc = 0.2f;
    t = &v[1];
    m = &v[2];
    v[0].x = ca;
    v[1].x = ca;
    v[0].y = cb;
    v[0].z = cc;
    v[1].z = cc;
    v[1].y = cb;
    v[0].w = one;
    t->w = one;
    v[2].x = v[0].x * -0.5f;
    *(int *)&v[2].y = 0;
    *(int *)&v[2].z = 0;
    m->w = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, self, 2);
    self->damage = slot;
    if (slot != 0) {
        nv = &v[3];
        *(int *)&v[3] = 0;
        *(int *)&v[3].y = 0;
        *(int *)&v[3].z = 0;
        nv->w = one;
        func_001FD9D8(slot, (char *)self + 0x80, m, nv, t);
    }
    hp = 1;
    self->base.hpMax = hp;
    self->base.hp = hp;
    cVec_copy3((cVec *)self->size, &v[0]);
    cOmDoor_setObjCollision(self);
    self->hasBody = hp;
    self->body = (char *)self + DOORBOX_RING_OFFSET;
    func_001BBF68(self);
    self->base.flags2 |= COMBASE_F2_BIT1;
    return 1;
}
