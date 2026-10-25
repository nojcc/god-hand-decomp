/* sn-2.95.3-136 */
#include "godhand/cSubScrMenu.h"

/* Clear the menu: the head, the kept file and the row state. */
__attribute__((section(".text.func_00164EF8")))
void func_00164EF8(cSubScrMenu *self)
{
    ClearFields_1614D0(&self->obj);
    self->data = 0;
    self->obj.state = 0;
    self->obj.step = 0;
    self->obj.unk5C = 0;
    self->obj.unk5D = 0;
}
