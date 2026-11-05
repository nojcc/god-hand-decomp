/* sn-2.95.3-136 matched TU. */
#include "godhand/cDamageUnit.h"

__attribute__((section(".text.func_001FD908")))
int func_001FD908(cDamageUnit *self)
{
    int a, b, c;

    switch (self->kind) {
    case 0:
        c = self->type;
        a = 1;
        b = 2;
    tail:
        return (c == 1) ? a : b;
    case 1:
        c = self->type;
        a = 3;
        b = 4;
        goto tail;
    case 2:
        c = self->type;
        a = 5;
        b = 6;
        goto tail;
    case 3:
        c = self->type;
        a = 7;
        b = 8;
        goto tail;
    case 4:
    default:
        return 0;
    }
}
