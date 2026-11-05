/* sn-2.95.3-136 matched TU. */
#include "godhand/player.h"
#include "godhand/cSnd.h"
#include "godhand/cModel.h"

/* Release obj once: detach its sounds, call its release method (vtable entry 9)
 * and mark it released (the sign bit of objFlags) and always drawn. */
__attribute__((section(".text.ReleaseObj")))
void ReleaseObj(struct cModel *obj) {
    if (obj != 0) {
        unsigned int hi = 0x80000000;

        if ((obj->objFlags & hi) == 0) {
            cSnd_SeDetachObj(&D_005FEE00, obj);
            CVCALL_FN(obj, 9, void (*)(void *))(CVCALL_THIS(obj, 9));
            obj->objFlags = (obj->objFlags | hi) | CMODEL_F_SHOWN;
        }
    }
}
