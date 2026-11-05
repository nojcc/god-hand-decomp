/* TU: CustomIDWork [id] - recovered C++ class. */
#include "godhand/CustomIDWork.h"

/* Shows the element when `show` is 1, hides it otherwise. */
__attribute__((section(".text.CustomIDWork_SetDisp")))
void CustomIDWork_SetDisp(CustomIDWork *self, int show) {
    cIDBaseEnt *obj = self->obj;
    if (obj != 0) {
        if ((show ^ 1) != 0) {
            obj->flags |= IDENT_FLAG_HIDDEN;
        } else {
            obj->flags &= ~IDENT_FLAG_HIDDEN;
        }
    }
}

/* Sets the number the element displays. */
__attribute__((section(".text.CustomIDWork_SetNumber")))
void CustomIDWork_SetNumber(CustomIDWork *self, int number) {
    cIDBaseEnt *obj = self->obj;
    if (obj != 0) {
        obj->seed = number;
    }
}
