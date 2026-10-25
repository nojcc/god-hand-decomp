/* sn-2.95.3-136 */
#include "godhand/cMessDrawFontCode.h"

/* 1 if text reaches a control code of kind (its high byte) before its end or
 * another 0x80xx code, scanning up to the first wait code; self is not read. */
__attribute__((section(".text.func_002B45F8")))
int func_002B45F8(struct MessWin *self, unsigned short *text, unsigned short kind)
{
    unsigned short code;

    while (func_002AF218(text) == 0) {
        code = *text;
        if (code >> 15) {
            if ((code & 0xFF00) == kind) {
                return 1;
            }
            if ((code & 0xFF00) == 0x8000) {
                return 0;
            }
        }
        text += cMessCommon_getCodeSize(*text);
    }
    return 0;
}
