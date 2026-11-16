/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cCockItem.h"

/* Forget the ticket. */
__attribute__((section(".text.ClearField90_13E400")))
void ClearField90_13E400(cCockItem *self) {
    if (self->ticket != 0) {
        self->ticket = 0;
    }
}
