/* sn-2.95.3-136: cObjPtrArrayWrapper_insert, insert a pointer before position while the list has room. */
#include "godhand/cObjPtrArrayWrapper.h"

__attribute__((section(".text.cObjPtrArrayWrapper_insert")))
void **cObjPtrArrayWrapper_insert(PtrVecRef *self, void **position, void *value)
{
    void *local;
    PtrVec *v;
    int index;
    void **vp;

    local = value;
    if (!PtrVecRef_hasRoom(self))
        return 0;
    v = self->v;
    vp = &local;
    index = position - v->begin;
    if (v->end != v->cap && position == v->end) {
        if (position != 0)
            *position = local;
        v->end = v->end + 1;
    } else {
        func_00317FF0(v, position, vp);
    }
    return v->begin + index;
}
