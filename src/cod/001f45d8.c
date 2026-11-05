/* sn-2.95.3-136 matched TU. */
#include "godhand/CustomIDWork.h"

extern void cIDBase(void *a0);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001F45D8")))
void *func_001F45D8(void *a0) {
    char *p = (char *)a0;
    char *q;
    int i;

    *(int *)p = 0;
    cIDBase(p + 0x10);

    q = p + 0x60;
    /* `!= -1`, not `>= 0`: retail materialises -1 and closes with `bne`. */
    for (i = 0x6E; i != -1; i--) {
        CustomIDWork__ctor((CustomIDWork *)q);
        q += 0x7C;
    }
    return p;
}
