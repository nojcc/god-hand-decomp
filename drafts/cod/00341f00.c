/* cygnus-2.96, as sn */
#include "include_asm.h"
#include "godhand/adxHdr.h"

extern Sint32 D_00457060[];           /* the low nibble, sign-extended */

#define ADX_CLIP16(v) \
    if ((Uint32)((v) + 0x8000) > 0xFFFF) { \
        if ((v) < -0x8000) \
            (v) = -0x8000; \
        else if ((v) > 0x7FFF) \
            (v) = 0x7FFF; \
    }

/* Decode nblk 18-byte ADX blocks (a big-endian scale word, then 32 4-bit samples) into
 * obuf through the two-tap predictor k0/k1, keeping the history in dly. The scale is
 * unmasked with *key, which steps as key * kmul + kadd. Stops early at a block whose
 * scale has bit 15 set and returns the blocks decoded.
 * Still differs from retail (68 instructions, same length): retail computes the nibble
 * table's low half inside the block loop and keeps k1 in s0; this C hoists the whole
 * table address out of both loops, so one t register is left over and k1 lands in t2. */
#ifdef NON_MATCHING
__attribute__((section(".text.ADX_DecodeMono4")))
Sint32 ADX_DecodeMono4(Uint8 *ibuf, Sint32 nblk, Sint16 *obuf, Sint16 *dly, Sint16 k0, Sint16 k1,
                       Uint16 *key, Sint16 kmul, Sint16 kadd)
{
    Sint32 i, j, scale, v;
    Sint16 hdr;
    Sint32 d1, d2;
    Sint8 b;

    d1 = dly[0];
    d2 = dly[1];
    for (i = 0; i < nblk; i++) {
        hdr = ((*(Uint16 *)ibuf << 8) & ~0xFF) | ibuf[1];
        if (hdr & 0x8000)
            return i;
        ibuf += 2;
        scale = ((hdr ^ *key) & 0x1FFF) + 1;
        *key = (*key * kmul + kadd) & 0x7FFF;
        for (j = 0; j < 32; j += 2) {
            b = *ibuf++;
            v = ((k0 * d1 + k1 * d2) >> 12) + (b >> 4) * scale;
            ADX_CLIP16(v);
            *obuf++ = v;
            d2 = d1;
            d1 = v;
            v = ((k0 * d1 + k1 * d2) >> 12) + D_00457060[b & 0xF] * scale;
            ADX_CLIP16(v);
            *obuf++ = v;
            d2 = d1;
            d1 = v;
        }
    }
    dly[1] = d2;
    dly[0] = d1;
    return nblk;
}
#else
INCLUDE_ASM("asm/nonmatching", ADX_DecodeMono4);
#endif
