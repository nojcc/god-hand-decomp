/* sn-2.95.3-136 */
#include "godhand/ptrVec.h"

static inline unsigned int vecSize(PtrVecRef *l)
{
    return l->v ? (unsigned int)(l->v->end - l->v->begin) : 0;
}

static inline unsigned int vecCap(PtrVecRef *l)
{
    PtrVec *v = l->v;
    if (v) {
        void **b = v->begin;
        void **c = v->cap;
        return c - b;
    }
    return 0;
}

/* Append obj when the list has room; returns its slot, or 0 when full. */
__attribute__((section(".text.func_003129D0")))
void **func_003129D0(PtrVecRef *list, void *obj)
{
    PtrVec *v;

    if (!(vecSize(list) < vecCap(list)))
        return 0;
    v = list->v;
    if (v->end != v->cap) {
        if (v->end != 0)
            *v->end = obj;
        v->end++;
    } else {
        func_00317FF0(v, v->end, &obj);
    }
    return list->v->end - 1;
}
