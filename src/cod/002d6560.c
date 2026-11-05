/* Sets the message number the element shows. */
#include "godhand/CustomIDWork.h"
__attribute__((section(".text.CustomIDWork_SetMessNo")))
void CustomIDWork_SetMessNo(CustomIDWork *self, int messNo)
{
    cIDBaseEnt *obj = self->obj;

    if (obj) {
        obj->msg = messNo;
    }
}
