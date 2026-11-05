/* sn-2.95.3-136 */
#include "godhand/vu0.h"
#include "godhand/cGameObj.h"

/* Starts effect id of the given kind for self with the default parameters and
 * records handle and killMode as the effect to kill with self. With no owner
 * the effect sits on self, looping and at self's size when self's motionFlags
 * has bit 1; otherwise it sits on owner at self's size. Either way it follows
 * self. */
__attribute__((section(".text.InitRenderStruct_2A8608")))
void InitRenderStruct_2A8608(cGameObj *self, int kind, int id, int handle, int killMode, void *owner) {
    cEffectParam param;

    cEffectParam_init(&param);
    self->effArg = killMode;
    param.unk70 = 0;
    param.unk72 = 0;
    param.unk74 = 0;
    param.unk78 = 0;
    self->effNo = handle;
    if (owner == 0) {
        if (self != 0) {
            if (self->motionFlags & 2) {
                param.flags |= EFFECT_PARAM_LOOP;
                param.size = self->scale.y;
            }
        }
        SetEffect(kind, id, self, &param, handle, (unsigned int)self);
    } else {
        if (self != 0) {
            param.size = self->scale.y;
        }
        SetEffect(kind, id, owner, &param, handle, (unsigned int)self);
    }
}
