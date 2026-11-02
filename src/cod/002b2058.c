/* sn-2.95.3-136 */
#include "godhand/cScrSpriteDraw.h"

/* Draws cell idx of a sprite sheet at (x, y) with size (w, h). */
__attribute__((section(".text.func_002B2058")))
void func_002B2058(cScrSheet *sheet, int idx, unsigned int color, float x, float y, float w, float h)
{
    func_002B1F80(sheet, idx, color, x, y, x + w, y + h);
}
