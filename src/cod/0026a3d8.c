/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cOmBase.h"

/* Child idx of the enemy, as cOmBase_childAt. Calling cOmBase_childAt
 * directly drops the copy of the result that retail keeps. */
static __inline__ cOmBase *Em_childAt(cEm00 *self, int *frame, int idx)
{
    return cOmBase_childAt((cOmBase *)self, frame, idx);
}

/* Copies unk16FC to child bodies 1 and 2 (their unk150, with meshFlags bit
 * 0x800 set while it is nonzero), then scales it by 0.6 (by -0.6 for enemies
 * 0x223, 0x275 and 0x276) and clears it once it is within one degree of 0. */
__attribute__((section(".text.func_0026A3D8")))
void func_0026A3D8(cEm00 *self)
{
    int frame[3];
    cOmBase *child;
    float d;

    child = Em_childAt(self, frame, 1);
    if (child != 0) {
        if (self->unk16FC != 0.0f) {
            child->meshFlags |= 0x800;
            child->unk150 = self->unk16FC;
        } else {
            child->unk150 = 0.0f;
            child->meshFlags &= ~0x800;
        }
    }
    child = Em_childAt(self, frame, 2);
    if (child != 0) {
        if (self->unk16FC != 0.0f) {
            child->meshFlags |= 0x800;
            child->unk150 = self->unk16FC;
        } else {
            child->unk150 = 0.0f;
            child->meshFlags &= ~0x800;
        }
    }
    switch (self->emNo) {
    default:
        self->unk16FC *= 0.6f;
        break;
    case 0x223:
    case 0x275:
    case 0x276:
        self->unk16FC *= -0.6f;
        break;
    }
    d = self->unk16FC;
    if (d < 0.0f) {
        d = -d;
    }
    if (d <= 0.017453292f) {
        self->unk16FC = 0.0f;
    }
}
