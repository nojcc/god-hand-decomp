/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"

extern char *InitFields_1B6E90(cOmBase *self);
extern cVtEnt D_0042AA98[];

/* A 0x790-byte map object with seven pairs of vectors from 0x6B0. */
typedef struct cOmVecPairs {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x6B0 - 0x5E0];
    cVec pair[7][2];                    /* 0x6B0 */
} cOmVecPairs;




/* Constructor: the map-object base, this class's vtable, then four vectors and the seven pairs zeroed. */
__attribute__((section(".text.func_001C9140")))
cOmVecPairs *func_001C9140(cOmVecPairs *self)
{
    cVec *p;
    int i;

    InitFields_1B6E90(&self->base);
    self->base.vtable = D_0042AA98;
    VU0_SQC2_VF0(self, 0x610);
    VU0_SQC2_VF0(self, 0x620);
    VU0_SQC2_VF0(self, 0x640);
    VU0_SQC2_VF0(self, 0x6A0);
    p = self->pair[0];
    i = 6;
    do {
        VU0_SQC2_VF0(p, 0x0);
        VU0_SQC2_VF0(p, 0x10);
        p += 2;
    } while (--i != -1);
    return self;
}

extern int SpawnRec_create(cDamageNode *node, int group, void *mtx, cVec *pos, cVec *dir, cDamageUnit *owner,
                         float height, float radius);

/* Append a cylinder volume from pos along dir; its id, or -1. */
__attribute__((section(".text.cDamageUnit_AddDamageCollCylinder")))
int cDamageUnit_AddDamageCollCylinder(cDamageUnit *self, void *mtx, cVec *pos, cVec *dir,
                                      float height, float radius)
{
    const cDamageVtEnt *ent;
    cDamageNode *node;
    cDamageNode *p;
    int r;

    if (self->type == CDAMAGE_TYPE_SPARE) return -1;
    ent = &self->vt[CDAMAGE_UNIT_NEWNODE];
    node = ((cDamageNode *(*)(void *))ent->pfn)((char *)self + ent->delta);
    if (node == 0) return -1;
    if (func_001FD908(self) == 0) return -1;
    r = SpawnRec_create(node, func_001FD908(self), mtx, pos, dir, self, height, radius);
    if (r == -1) return r;
    if (self->nodes != 0) {
        p = self->nodes;
        while (p->next != 0) p = p->next;
        p->next = node;
        node->prev = p;
    } else {
        self->nodes = node;
    }
    return r;
}
