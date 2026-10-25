/* sn-2.95.3-136 */
#include "godhand/cIDManager.h"
#include "godhand/cScrSpriteDraw.h"

extern cIDManager *D_003C2388;

/* Draw glyph digit of the digit sheet: digits 0-9 and the signs -1..-3 sit in
 * a 4x4 grid of quarter cells; a missing sheet falls back to sheet 0x1C. */
__attribute__((section(".text.func_002C6D48")))
void func_002C6D48(cScrSpriteDraw *self, int digit, float x, float y, float w, float h,
                   unsigned int color, short texNo, unsigned short slot)
{
    unsigned int tex;

    if (texNo == 0) {
        tex = cIDManager_getTexAddr(D_003C2388, 1, 0x1C);
    } else {
        tex = cIDManager_getTexAddr(D_003C2388, slot, texNo + 1);
    }
    if (tex == 0) {
        tex = cIDManager_getTexAddr(D_003C2388, 1, 0x1C);
    }
    switch (digit) {
    case 0:
        cScrSpriteDraw_drawTexCentered(self, tex, x, y, w, h, 0.0f, 0.0f, 0.25f, 0.25f, color);
        break;
    case 1:
        cScrSpriteDraw_drawTexCentered(self, tex, x, y, w, h, 0.25f, 0.0f, 0.5f, 0.25f, color);
        break;
    case 2:
        cScrSpriteDraw_drawTexCentered(self, tex, x, y, w, h, 0.5f, 0.0f, 0.75f, 0.25f, color);
        break;
    case 3:
        cScrSpriteDraw_drawTexCentered(self, tex, x, y, w, h, 0.75f, 0.0f, 1.0f, 0.25f, color);
        break;
    case 4:
        cScrSpriteDraw_drawTexCentered(self, tex, x, y, w, h, 0.0f, 0.25f, 0.25f, 0.5f, color);
        break;
    case 5:
        cScrSpriteDraw_drawTexCentered(self, tex, x, y, w, h, 0.25f, 0.25f, 0.5f, 0.5f, color);
        break;
    case 6:
        cScrSpriteDraw_drawTexCentered(self, tex, x, y, w, h, 0.5f, 0.25f, 0.75f, 0.5f, color);
        break;
    case 7:
        cScrSpriteDraw_drawTexCentered(self, tex, x, y, w, h, 0.75f, 0.25f, 1.0f, 0.5f, color);
        break;
    case 8:
        cScrSpriteDraw_drawTexCentered(self, tex, x, y, w, h, 0.0f, 0.5f, 0.25f, 0.75f, color);
        break;
    case 9:
        cScrSpriteDraw_drawTexCentered(self, tex, x, y, w, h, 0.25f, 0.5f, 0.5f, 0.75f, color);
        break;
    case -1:
        cScrSpriteDraw_drawTexCentered(self, tex, x, y, w, h, 0.5f, 0.75f, 0.75f, 1.0f, color);
        break;
    case -2:
        cScrSpriteDraw_drawTexCentered(self, tex, x, y, w, h, 0.5f, 0.5f, 0.75f, 0.75f, color);
        break;
    case -3: /* retail keeps this call apart from default: sharing it changes the code */
        cScrSpriteDraw_drawTexCentered(self, tex, x, y, w, h, 0.75f, 0.5f, 1.0f, 0.75f, color);
        break;
    default:
        cScrSpriteDraw_drawTexCentered(self, tex, x, y, w, h, 0.75f, 0.5f, 1.0f, 0.75f, color);
        break;
    }
}
