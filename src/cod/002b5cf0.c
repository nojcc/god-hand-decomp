/* sn-2.95.3-136 matched TU. */
#include "godhand/cNode.h"

/* func_002B5D58 leaves a child that has a parent where it is, so with a
 * non-null parent the loop only ends when the node has no children. */
__attribute__((section(".text.func_002B5CF0")))
void func_002B5CF0(cNode *self, cNode *parent) {
    while (self->child) {
        func_002B5D58(self->child, parent);
    }
    self->child = 0;
    func_002B5EC0(self);
}
