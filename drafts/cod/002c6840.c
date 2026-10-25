/* sn-2.95.3-136 */
#include "godhand/cScrSpriteDraw.h"
#include "godhand/capVu0.h"
#include "godhand/drawPrim.h"
#include "include_asm.h"

#define SCR_LINE_DEPTH  65535.0f       /* vertex depth of the outline */

/* Outline of a w x h rectangle rotated by angle, anchored at (x, y) by mode
 * (0 centre, 1 top left, 2 top right, 3 bottom left, 4 bottom right), scaled
 * by scale about the screen's vertical centre line and drawn as a closed line
 * strip in the packed colour. The closing vertex is copied before the scale,
 * as retail does.
 * Same length as retail; only the setup of the closing copy differs: retail
 * loads the counter before the source pointer, ours after. */
#ifdef NON_MATCHING
__attribute__((section(".text.cScrSpriteDraw_drawRectLine")))
void cScrSpriteDraw_drawRectLine(cScrSpriteDraw *self, unsigned int color, unsigned int mode,
                                 float x, float y, float w, float h, float angle, float scale)
{
    float v[5][4];
    float px = x + self->shiftX;
    float py = y + self->shiftY;
    float c = capVu0Cos(angle);
    float s = capVu0Sin(angle);
    float wc = w * c;
    float ws = -w * s;
    float hs = h * s;
    float hc = h * c;
    unsigned int a, b, g, r;
    float *dst, *src;
    int n;
    int i;

    switch (mode) {
    case 0:
        wc *= 0.5f;
        ws *= 0.5f;
        hs *= 0.5f;
        hc *= 0.5f;
        v[0][0] = px - wc + hs;
        v[0][1] = py + ws - hc;
        v[0][2] = SCR_LINE_DEPTH;
        v[0][3] = 1.0f;
        v[1][0] = px + wc + hs;
        v[1][1] = py - ws - hc;
        v[1][2] = SCR_LINE_DEPTH;
        v[1][3] = 1.0f;
        v[3][0] = px - wc - hs;
        v[3][1] = py + ws + hc;
        v[3][2] = SCR_LINE_DEPTH;
        v[3][3] = 1.0f;
        v[2][0] = px + wc - hs;
        v[2][1] = py - ws + hc;
        v[2][2] = SCR_LINE_DEPTH;
        v[2][3] = 1.0f;
        break;
    case 1:
        v[0][0] = px;
        v[0][1] = py;
        v[0][2] = SCR_LINE_DEPTH;
        v[0][3] = 1.0f;
        v[1][0] = px + wc;
        v[1][1] = py - ws;
        v[1][2] = SCR_LINE_DEPTH;
        v[1][3] = 1.0f;
        v[3][0] = px - hs;
        v[3][1] = py + hc;
        v[3][2] = SCR_LINE_DEPTH;
        v[3][3] = 1.0f;
        v[2][0] = px + wc - hs;
        v[2][1] = py - ws + hc;
        v[2][2] = SCR_LINE_DEPTH;
        v[2][3] = 1.0f;
        break;
    case 3:
        v[0][0] = px + hs;
        v[0][1] = py - hc;
        v[0][2] = SCR_LINE_DEPTH;
        v[0][3] = 1.0f;
        v[1][0] = px + wc + hs;
        v[1][1] = py - ws - hc;
        v[1][2] = SCR_LINE_DEPTH;
        v[1][3] = 1.0f;
        v[3][0] = px;
        v[3][1] = py;
        v[3][2] = SCR_LINE_DEPTH;
        v[3][3] = 1.0f;
        v[2][0] = px + wc;
        v[2][1] = py - ws;
        v[2][2] = SCR_LINE_DEPTH;
        v[2][3] = 1.0f;
        break;
    case 2:
        v[0][0] = px - wc;
        v[0][1] = py + ws;
        v[0][2] = SCR_LINE_DEPTH;
        v[0][3] = 1.0f;
        v[1][0] = px;
        v[1][1] = py;
        v[1][2] = SCR_LINE_DEPTH;
        v[1][3] = 1.0f;
        v[3][0] = px - wc - hs;
        v[3][1] = py + ws + hc;
        v[3][2] = SCR_LINE_DEPTH;
        v[3][3] = 1.0f;
        v[2][0] = px - hs;
        v[2][1] = py + hc;
        v[2][2] = SCR_LINE_DEPTH;
        v[2][3] = 1.0f;
        break;
    case 4:
        v[0][0] = px - wc + hs;
        v[0][1] = py + ws - hc;
        v[0][2] = SCR_LINE_DEPTH;
        v[0][3] = 1.0f;
        v[1][0] = px + hs;
        v[1][1] = py - hc;
        v[1][2] = SCR_LINE_DEPTH;
        v[1][3] = 1.0f;
        v[3][0] = px - wc;
        v[3][1] = py + ws;
        v[3][2] = SCR_LINE_DEPTH;
        v[3][3] = 1.0f;
        v[2][0] = px;
        v[2][1] = py;
        v[2][2] = SCR_LINE_DEPTH;
        v[2][3] = 1.0f;
        break;
    }
    dst = v[4];
    src = v[0];
    n = 4;
    while (n--) {
        *dst++ = *src++;
    }
    for (i = 0; i < 4; i++) {
        v[i][0] = v[i][0] * scale + D_003C1184 * (1.0f - scale) * 0.5f;
    }
    a = SCR_CHAN(color, 24, self->alphaScale);
    b = SCR_CHAN(color, 16, self->blueScale);
    g = SCR_CHAN(color, 8, self->greenScale);
    r = SCR_CHAN(color, 0, self->redScale);
    Draw_Line_sc(v, 4, (a << 24) | (b << 16) | (g << 8) | r, 1);
}
#else
INCLUDE_ASM("asm/nonmatching", cScrSpriteDraw_drawRectLine);
#endif
