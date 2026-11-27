/* sn-2.95.3-136 matched TU. */
#include "godhand/shadowPacket.h"

/* Clear the shadow quad: every corner at 0, colour 0 and Q = 1.0. */
__attribute__((section(".text.func_0015EEE0")))
void func_0015EEE0(ShadowPacket *p)
{
    FloatBits bits;
    bits.f = 1.0f;
    p->vtx[0].xyz = 0;
    p->vtx[3].xyz = 0;
    p->vtx[2].xyz = 0;
    p->vtx[1].xyz = 0;
    p->rgbaq = (long)bits.u << 32;
}
