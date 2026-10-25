/* sn-2.95.3-136. Differs from retail in the four colour-channel conversions:
 * retail converts each clamped channel in place (cvt.w.s $f0,$f0); ours
 * converts into $f1. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cScrSpriteDraw.h"
#include "godhand/capVu0.h"
#include "godhand/drawPrim.h"

/* A scaled channel back to a byte; negative values clamp to 0. */
static __inline__ unsigned int scrChanToByte(float f)
{
    if (f < 0.0f) {
        return 0;
    }
    return (int)f;
}

/* Draw texture tex as a w x h quad rotated by angle and anchored at (x, y)
 * by mode (0 centre, 1 top left, 2 top right, 3 bottom left, 4 bottom
 * right), scaled by scale about the screen's vertical centre line and tinted
 * by the packed colour. Nothing is drawn without a texture. */
__attribute__((section(".text.func_002C5EA8")))
void func_002C5EA8(cScrSpriteDraw *self, void *tex, unsigned int color, unsigned int mode,
                   float x, float y, float w, float h, float angle,
                   float u0, float v0, float u1, float v1, float scale)
{
    cScrVtx v[4];
    cScrTexCfg cfg;
    float c, s, hw, hh, wc, ws, hc, hs;
    unsigned int a, b, g, r;
    void *pkt;
    int i;

    if (tex == 0) {
        return;
    }
    x += self->shiftX;
    y += self->shiftY;
    c = capVu0Cos(angle);
    s = capVu0Sin(angle);
    hw = w * self->scaleX;
    hh = h * self->scaleY;
    wc = hw * c;
    ws = -hw * s;
    hs = hh * s;
    hc = hh * c;
    switch (mode) {
    case 0:
        wc *= 0.5f;
        ws *= 0.5f;
        hs *= 0.5f;
        hc *= 0.5f;
        v[0].x = x - wc + hs;
        v[0].y = y + ws - hc;
        v[0].z = (float)self->clip;
        v[0].w = 1.0f;
        v[1].x = x + wc + hs;
        v[1].y = y - ws - hc;
        v[1].z = (float)self->clip;
        v[1].w = 1.0f;
        v[2].x = x - wc - hs;
        v[2].y = y + ws + hc;
        v[2].z = (float)self->clip;
        v[2].w = 1.0f;
        v[3].x = x + wc - hs;
        v[3].y = y - ws + hc;
        v[3].z = (float)self->clip;
        v[3].w = 1.0f;
        break;
    case 1:
        v[0].x = x;
        v[0].y = y;
        v[0].z = (float)self->clip;
        v[0].w = 1.0f;
        v[1].x = x + wc;
        v[1].y = y - ws;
        v[1].z = (float)self->clip;
        v[1].w = 1.0f;
        v[2].x = x - hs;
        v[2].y = y + hc;
        v[2].z = (float)self->clip;
        v[2].w = 1.0f;
        v[3].x = x + wc - hs;
        v[3].y = y - ws + hc;
        v[3].z = (float)self->clip;
        v[3].w = 1.0f;
        break;
    case 3:
        v[0].x = x + hs;
        v[0].y = y - hc;
        v[0].z = (float)self->clip;
        v[0].w = 1.0f;
        v[1].x = x + wc + hs;
        v[1].y = y - ws - hc;
        v[1].z = (float)self->clip;
        v[1].w = 1.0f;
        v[2].x = x;
        v[2].y = y;
        v[2].z = (float)self->clip;
        v[2].w = 1.0f;
        v[3].x = x + wc;
        v[3].y = y - ws;
        v[3].z = (float)self->clip;
        v[3].w = 1.0f;
        break;
    case 2:
        v[0].x = x - wc;
        v[0].y = y + ws;
        v[0].z = (float)self->clip;
        v[0].w = 1.0f;
        v[1].x = x;
        v[1].y = y;
        v[1].z = (float)self->clip;
        v[1].w = 1.0f;
        v[2].x = x - wc - hs;
        v[2].y = y + ws + hc;
        v[2].z = (float)self->clip;
        v[2].w = 1.0f;
        v[3].x = x - hs;
        v[3].y = y + hc;
        v[3].z = (float)self->clip;
        v[3].w = 1.0f;
        break;
    case 4:
        v[0].x = x - wc + hs;
        v[0].y = y + ws - hc;
        v[0].z = (float)self->clip;
        v[0].w = 1.0f;
        v[1].x = x + hs;
        v[1].y = y - hc;
        v[1].z = (float)self->clip;
        v[1].w = 1.0f;
        v[2].x = x - wc;
        v[2].y = y + ws;
        v[2].z = (float)self->clip;
        v[2].w = 1.0f;
        v[3].x = x;
        v[3].y = y;
        v[3].z = (float)self->clip;
        v[3].w = 1.0f;
        break;
    }
    for (i = 0; i < 4; i++) {
        v[i].x = v[i].x * scale + D_003C1184 * (1.0f - scale) * 0.5f;
    }
    cfg.mode = 1;
    cfg.u0 = u0;
    cfg.v0 = v0;
    cfg.u1 = u1;
    cfg.v1 = v1;
    a = scrChanToByte((float)(color >> 24 & 0xFF) * self->alphaScale);
    b = scrChanToByte((float)(color >> 16 & 0xFF) * self->blueScale);
    g = scrChanToByte((float)(color >> 8 & 0xFF) * self->greenScale);
    r = scrChanToByte((float)(color & 0xFF) * self->redScale);
    pkt = Gp_draw_polyFT4(v, (a << 24) | (b << 16) | (g << 8) | r, 1, tex, D_003C11B0, 0x1CF0, &cfg,
                          self->colorNo, self->fontNo);
    if (pkt != 0) *(long *)((char *)pkt + 0x1A0) = SCR_PKT_TAG;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002C5EA8);
#endif
