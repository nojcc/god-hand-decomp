/* sn-2.95.3-136 matched TU. */
#include "godhand/cNode.h"
extern void StoreVecFromFieldB0_2B6160(void *dst, void *self);


__attribute__((section(".text.func_002B5D58")))
void func_002B5D58(cNode *self, cNode *parent) {
    cVec scale;
    cVec rot;
    cVec trans;
    cNode *p;

    if (parent == 0) {
        func_002B6080(&scale, self);
        func_002B60D0(&rot, self);
        StoreVecFromFieldB0_2B6160(&trans, self);
        func_002B5EC0(self);
        self->parent = 0;
        cNode_setLocalScale(self, &scale);
        func_002B6230(self, &rot);
        cNode_setLocalTranslation(self, &trans);
    } else if (func_002B5E50(self) == 0) {
        self->parent = parent;
        if (parent->child == 0) {
            parent->child = self;
        } else {
            p = parent->child;
            while (p->next != 0) {
                p = p->next;
            }
            self->prev = p;
            p->next = self;
        }
    }
}
