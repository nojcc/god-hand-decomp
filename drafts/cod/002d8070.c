/* sn-2.95.3-136 */
#include "godhand/cWorldLight.h"
#include "godhand/cOmBase.h"
#include "include_asm.h"

/* Fog colour and fog level for a depth: the world light's fog colour, clamped at zero, packed into
 * the GS FOGCOL word, and the fog level at depth (0..255, 255 when depth is not positive) stored
 * in fog[1].w.
 * Differs from retail as func_002D81A0 does: retail forms self + 0x10000 and the zero constant
 * again for each colour channel, keeping self in a3. */
#ifdef NON_MATCHING
__attribute__((section(".text.func_002D8070")))
void func_002D8070(cWorldLight *self, cVec *fog, unsigned long *fogcol, float depth)
{
    unsigned int r, g, b;
    float range;
    float level;

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
    if (depth > 0.0f) {
        range = self->fogFar - self->fogNear;
        level = (self->fogNear / range + 1.0f - depth / range) * 255.0f;
    } else {
        level = 255.0f;
    }
    if (level < 0.0f) {
        level = 0.0f;
    }
    if (level > 255.0f) {
        level = 255.0f;
    }
    fog[1].w = level;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002D8070);
#endif
