/* sn-2.95.3-136 */
#include "godhand/cGrid.h"
#include "godhand/cVec.h"
#include "godhand/criStm.h"

/* Box collision body constructor: the base body's clear, then the owner, its
 * position and rotation, the two vectors, the size made positive per axis, the
 * six faces (each marked unset), and flags 5. */
__attribute__((section(".text.func_0012D970")))
cCollBody *func_0012D970(cCollBody *self, cModel *owner, int param, cVec *v70, cVec *v90,
                         cVec *size, cCollFace *f0, cCollFace *f1, cCollFace *f2,
                         cCollFace *f3, cCollFace *f4, cCollFace *f5)
{
    cVec *p;
    int i;
    float f;

    self->vt = D_0041D5A8;
    self->flags = 0;
    CVEC_ZERO(self->min);
    CVEC_ZERO(self->max);
    self->param = 0;
    self->id = 0;
    self->next = 0;
    self->unk54 = 0;
    func_003A52F0(self->unk34, 0, 0x20);
    self->vt = D_0041D558;
    CVEC_ZERO(self->pos);
    CVEC_ZERO(self->unk70);
    CVEC_ZERO(self->rot);
    CVEC_ZERO(self->unk90);
    CVEC_ZERO(self->u.box.extent);
    /* retail counts the corners down; a for loop over them changes the code */
    p = self->u.box.corner;
    i = 7;
    do {
        CVEC_ZERO(*p);
        p++;
    } while (--i != -1);
    self->param = param;
    self->type = CCOLLBODY_BOX;
    self->id = (int)owner;
    CVEC_PUT_PTR(&self->pos, owner->pos);
    CVEC_PUT_PTR(&self->unk70, v70);
    CVEC_PUT_PTR(&self->rot, &owner->rot);
    CVEC_PUT_PTR(&self->unk90, v90);
    f = size->x;
    if (f < 0.0f)
        f = -f;
    self->u.box.extent.x = f;
    f = size->y;
    if (f < 0.0f)
        f = -f;
    self->u.box.extent.y = f;
    f = size->z;
    if (f < 0.0f)
        f = -f;
    self->u.box.extent.z = f;
    self->u.box.face[0] = *f0;
    self->u.box.face[0].unk8 = 0xFFFF;
    self->u.box.face[0].unkB = 0;
    self->u.box.face[0].unkA = 0;
    self->u.box.face[1] = *f1;
    self->u.box.face[1].unk8 = 0xFFFF;
    self->u.box.face[1].unkB = 0;
    self->u.box.face[1].unkA = 0;
    self->u.box.face[2] = *f2;
    self->u.box.face[2].unk8 = 0xFFFF;
    self->u.box.face[2].unkB = 0;
    self->u.box.face[2].unkA = 0;
    self->u.box.face[3] = *f3;
    self->u.box.face[3].unk8 = 0xFFFF;
    self->u.box.face[3].unkB = 0;
    self->u.box.face[3].unkA = 0;
    self->u.box.face[4] = *f4;
    self->u.box.face[4].unk8 = 0xFFFF;
    self->u.box.face[4].unkB = 0;
    self->u.box.face[4].unkA = 0;
    self->u.box.face[5] = *f5;
    self->u.box.face[5].unk8 = 0xFFFF;
    self->u.box.face[5].unkB = 0;
    self->u.box.face[5].unkA = 0;
    self->flags |= 5;
    return self;
}
