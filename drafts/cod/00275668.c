/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cEm00.h"
#include "godhand/cVec.h"
#include "godhand/sceVu0.h"

#ifdef NON_MATCHING
/* Differs from retail: the unit vector's loads all come before its stores
 * (retail interleaves them), and self and &self->unk480 take swapped saved
 * registers. */

/* Lower the body (child 0's anchor) on a slope: normalize the 0x480 normal and
 * ease unk1758 toward how far it tilts from straight up, by enemy number. */
__attribute__((section(".text.func_00275668")))
void func_00275668(cEm00 *self)
{
    int frame[3];
    CVEC_TEMPS;
    cEm00 *body;
    float max;
    float rate;
    float sink;
    float keep;

    rate = 0.5f;
    max = 0.4f;
    switch (self->emNo) {
    case 0x205:
    case 0x206:
    case 0x207:
    case 0x208:
    case 0x209:
    case 0x21F:
    case 0x224:
    case 0x241:
        rate = 0.7f;
        max = 0.06f;
        break;
    case 0x20F:
    case 0x210:
    case 0x223:
    case 0x226:
    case 0x260:
    case 0x264:
    case 0x265:
    case 0x26A:
    case 0x270:
    case 0x271:
    case 0x272:
    case 0x273:
    case 0x274:
        return;
    }
    body = (cEm00 *)cOmBase_childAt((cOmBase *)self, frame, 0);
    if (body == 0)
        return;
    rate *= self->unk114;
    max *= self->unk114;
    CVEC_SET_UNIT(self->unk480, &self->unk480);
    sink = 0.0f;
    if (self->unk480.y != 0.0f && self->vital > 0) {
        sink = (1.0f - self->unk480.y) * rate;
        if (max < sink)
            sink = max;
        if (self->moveFlags & 0x42C)
            sink = 0.0f;
        if (self->mode == 2)
            sink = 0.0f;
    }
    keep = 1.0f - self->speedRate * 0.15f;
    self->unk1758 = self->unk1758 * keep + sink * (1.0f - keep);
    if (self->unk1758 < 0.0f)
        self->unk1758 = 0.0f;
    body->anchor->y -= self->unk1758;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00275668);
#endif
