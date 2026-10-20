/* NON_MATCHING func_0033EBD0 (cygnus-2.96 --drop-reorder;
 * PARK, 42 diffs): ADX loop-info decode; structure and schedule match, register allocation of the byte-swap temps differs. */
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
#define SWAP32(v) ((((Uint32)(v) >> 24) | ((v) << 24)) | ((((v) << 8) & 0xFF0000) | (((v) >> 8) & 0xFF00)))

extern Sint32 ADX_DecodeInfoExVer(Sint8 *ibuf, Sint32 hdlen, Uint8 *ver, Uint8 *rev);

__attribute__((section(".text.func_0033EBD0")))
Sint32 func_0033EBD0(Sint8 *ibuf, Sint32 ibuflen, Sint32 *insttype, Uint16 *nloop, Uint16 *lptype,
                     Sint32 *lsSmpl, Sint32 *lsOfst, Sint32 *leSmpl, Sint32 *leOfst)
{
    Uint8 ver, rev;
    Sint32 ret, hdlen, pos, v;
    Sint32 n;

    *nloop = 0;
    ret = ADX_DecodeInfoExVer(ibuf, ibuflen, &ver, &rev);
    if (ret != 0)
        return ret;
    hdlen = 0x30;
    if (ver == 4)
        hdlen = 0x3C;
    if (ibuflen < hdlen)
        return -1;
    if ((Uint16)SWAP16(*(Uint16 *)(ibuf + 0)) != 0x8000)
        return -2;
    if ((Sint16)SWAP16B(ibuf + 2) < hdlen - 4)
        return -1;
    pos = (ver != 4) ? 0x14 : 0x20;
    v = (Sint16)SWAP16B(ibuf + pos);
    pos += 2;
    n = SWAP16B(ibuf + pos);
    pos += 2;
    *insttype = v;
    *nloop = n;
    if ((Sint16)n != 1)
        return -2;
    pos += 2;
    *lptype = SWAP16B(ibuf + pos);
    pos += 2;
    v = *(Sint32 *)(ibuf + pos);
    pos += 4;
    *lsSmpl = SWAP32(v);
    v = *(Sint32 *)(ibuf + pos);
    pos += 4;
    *lsOfst = SWAP32(v);
    v = *(Sint32 *)(ibuf + pos);
    pos += 4;
    *leSmpl = SWAP32(v);
    pos += 4;
    v = *(Sint32 *)(ibuf + pos);
    *leOfst = SWAP32(v);
    return 0;
}

#else
INCLUDE_ASM("asm/nonmatching", func_0033EBD0);
#endif
