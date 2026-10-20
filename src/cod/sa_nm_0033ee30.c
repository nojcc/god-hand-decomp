/* NON_MATCHING func_0033EE30 (cygnus-2.96 --drop-reorder;
 * PARK, 51 diffs): header checks and offsets match; retail
 * schedules all field-address computations ahead of the AINF length store and the 16-byte data-id copy (and keeps a
 * second register for the pan[1] address), and uses beq (not beql) on the AINF tag test.
 * ADX AINF chunk decode:
 * AINF length, 16-byte data id, volume, two pan values. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef signed char Sint8;
typedef unsigned char Uint8;
typedef short Sint16;
typedef unsigned short Uint16;
typedef int Sint32;
typedef unsigned int Uint32;

#define SWAP16(x) ((((Uint16)(x)) >> 8) | ((((Uint16)(x)) << 8) & ~0xff))
#define SWAP16B(p) (((Uint8 *)(p))[1] | ((*(Uint16 *)(p) << 8) & ~0xff))
#define GB(p, i)  ((Uint8)(p)[i])
#define GET32(p)  ((GB(p, 0) << 24) | (GB(p, 1) << 16) | (GB(p, 2) << 8) | GB(p, 3))

extern Sint32 ADX_DecodeInfoExVer(Sint8 *ibuf, Sint32 hdlen, Uint8 *ver, Uint8 *rev);
extern void *memcpy(void *d, const void *s, unsigned int n);

__attribute__((section(".text.func_0033EE30")))
Sint32 func_0033EE30(Sint8 *ibuf, Sint32 ibuflen, Sint32 *ainflen, Sint8 *dataid, Sint16 *vol, Sint16 *pan)
{
    Uint8 ver, rev;
    Sint32 ret, hdlen, pos, v;

    *ainflen = 0;
    ret = ADX_DecodeInfoExVer(ibuf, ibuflen, &ver, &rev);
    if (ret != 0)
        return ret;
    hdlen = 0x3C;
    if (ver == 4)
        hdlen = 0x48;
    if (ibuflen < hdlen)
        return -1;
    if ((Uint16)SWAP16(*(Uint16 *)(ibuf + 0)) != 0x8000)
        return -2;
    if ((Sint16)SWAP16B(ibuf + 2) < hdlen - 4)
        return -1;
    pos = (ver != 4) ? 0x14 : 0x20;
    pos += 2;
    v = (Sint16)SWAP16B(ibuf + pos);
    pos += 2;
    if (v != 0)
        pos += 0x14;
    if (GET32(ibuf + pos) != 0x41494E46)
        return -2;
    pos += 4;
    v = *(Sint32 *)(ibuf + pos);
    pos += 4;
    *ainflen = (((Uint32)v >> 24) | (v << 24)) | (((v << 8) & 0xFF0000) | ((v >> 8) & 0xFF00));
    memcpy(dataid, ibuf + pos, 16);
    pos += 16;
    *vol = SWAP16B(ibuf + pos);
    pos += 4;
    pan[0] = SWAP16B(ibuf + pos);
    pan[1] = SWAP16B(ibuf + pos + 2);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0033EE30);
#endif
