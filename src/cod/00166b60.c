/* sn-2.95.3-136 */
#include "godhand/cSubScrOption.h"

/* Draw the options panel: the second display too while it is open (modes 2 and 3). */
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
