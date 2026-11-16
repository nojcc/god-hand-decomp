/* sn-2.95.3-136 matched TU. */
#include "godhand/cSubScrOption.h"

/* Draw the options screen: the second display while it is shown or fading back (modes 2 and 3), then the panel. */
__attribute__((section(".text.func_00166B60")))
void func_00166B60(cSubScrOption *self) {
    switch (self->obj.state) {
    case 2:
    case 3:
        cIDBase_trans(&self->sub);
        /* fall through */
    case 0:
    case 1:
    case 4:
    default:
        cIDBase_trans(&self->obj.base);
    }
}
