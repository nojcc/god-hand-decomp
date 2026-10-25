/* sn-2.95.3-136 */
#include "godhand/cWorldLight.h"
#include "godhand/cOmBase.h"
#include "include_asm.h"

/* Fog setup from the world light: the fog colour, clamped at zero, packed
 * into the GS FOGCOL word, and the near/far range turned into the VU1 fog
 * scale (fog[0].w) and slope (fog[1].w).
 * Differs from retail in addressing: retail forms self + 0x10000 again for
 * each colour channel (keeping self in a3) where ours forms it once. */
#ifdef NON_MATCHING
__attribute__((section(".text.func_002D81A0")))
void func_002D81A0(cWorldLight *self, cVec *fog, unsigned long *fogcol)
{
    unsigned int r, g, b;

    r = 0;
    if (!(self->fogColor[0] < 0.0f)) {
        r = (int)self->fogColor[0];
    }
    g = 0;
    if (!(self->fogColor[1] < 0.0f)) {
        g = (int)self->fogColor[1];
    }
    b = 0;
    if (!(self->fogColor[2] < 0.0f)) {
        b = (int)self->fogColor[2];
    }
    *fogcol = (unsigned long)r | ((unsigned long)g << 8) | ((unsigned long)b << 16);
    fog[0].w = (self->fogNear / (self->fogFar - self->fogNear) + 1.0f) * 255.0f;
    fog[1].w = -255.0f / (self->fogFar - self->fogNear);
}
#else
INCLUDE_ASM("asm/nonmatching", func_002D81A0);
#endif
