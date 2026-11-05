/* sn-2.95.3-136 matched TU. */
#include "godhand/cDamageUnit.h"

extern int KeyFollower_attach(cDamageNode *node, int group, void *mtx, cVec *ofs, cVec *rot, cVec *size,
                              cDamageUnit *owner);

/* Append a box volume at ofs in mtx's space; its id, or -1. */
__attribute__((section(".text.func_001FD9D8")))
int func_001FD9D8(cDamageUnit *self, void *mtx, cVec *ofs, cVec *rot, cVec *size) {
    const cDamageVtEnt *ent;
    cDamageNode *node;
    cDamageNode *last;
    int result;

    if (self->type == CDAMAGE_TYPE_SPARE) {
        return -1;
    }
    ent = &self->vt[CDAMAGE_UNIT_NEWNODE];
    node = ((cDamageNode *(*)(void *))ent->pfn)((char *)self + ent->delta);
    if (node == 0) {
        return -1;
    }
    if (func_001FD908(self) == 0) {
        return -1;
    }
    result = KeyFollower_attach(node, func_001FD908(self), mtx, ofs, rot, size, self);
    if (result == -1) {
        return -1;
    }
    if (self->nodes != 0) {
        last = self->nodes;
        if (last->next != 0) {
            do {
                last = last->next;
            } while (last->next != 0);
        }
        last->next = node;
        node->prev = last;
    } else {
        self->nodes = node;
    }
    return result;
}
