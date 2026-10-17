#include "include_asm.h"
/* NM, not registered. sn-2.95.3-136: CustomID panel helpers (offset slides, scale/colour pulses on 0x7C-byte works at +0x60). */
#include "godhand/CustomIDPanel.h"

typedef union { unsigned int v; struct { unsigned int r:8, g:8, b:8, a:8; } c; } CustomIDRGBA;

extern CustomIDSlotTbl D_0042B5D0;

#ifdef NON_MATCHING
/* Same length; retail schedules the colour build before the table index and puts the table base in $t3. */
__attribute__((section(".text.func_001DEB08")))
void func_001DEB08(char *self, unsigned char slot, int on, int base)
{
    CustomIDSlotTbl buf;
    CustomIDRGBA from, to;
    if (slot < 5) {
        buf = D_0042B5D0;
        if (on) {
            from.v = base & 0xFFFF;
            from.c.a = 0x80;
            from.c.b = 0x80;
            from.c.g = 0x80;
            from.c.r = 0x80;
            to.v = from.v | 0xFFFFFF;
            CustomIDWork_SetColorAnimSin(self + (buf.w[slot] * 0x7C + 0x60), from.v, to.v, 0xC);
        } else {
            CustomIDWork_ResetColorAnim(self + (buf.w[slot] * 0x7C + 0x60));
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001DEB08);
#endif
