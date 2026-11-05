/* Hides (`hide` nonzero) or shows the element's children. */
#include "godhand/CustomIDWork.h"
__attribute__((section(".text.CustomIDWork_SetChildNoDisp")))
void CustomIDWork_SetChildNoDisp(CustomIDWork *self, int hide)
{
    cIDBaseEnt *obj = self->obj;

    if (obj == 0) {
        return;
    }
    if (hide) {
        obj->flags |= IDENT_FLAG_CHILD;
    } else {
        obj->flags &= ~IDENT_FLAG_CHILD;
    }
}
