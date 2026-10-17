/* NON_MATCHING func_0036EB58 (cygnus-2.96 dr): 58-63 diffs: byte-read chain structure right but extra temp pseudo shifts registers; retail keeps last p++ and p+=4 as separate addiu */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Bs36EB58 {
    char pad0[0x2C];
    int word;
    char pad30[0x308 - 0x30];
    int code;
    int ext;
    char pad310[0x420 - 0x310];
    int on;
    char pad424[0xC];
    int count;
    char pad434[0x494 - 0x434];
    int skips;
} Bs36EB58;

typedef struct Dec36EB58 {
    char pad0[0x160];
    Bs36EB58 bs;
} Dec36EB58;

char *func_0036EB58(Dec36EB58 *dec, char *buf)
{
    Bs36EB58 *bs = &dec->bs;
    char *p;
    int shift;
    int hi;
    unsigned int lo;
    int bits;

    bs->on = 1;
    bs->count++;
    if ((bs->code != 0 && bs->code != 0x80) || bs->ext != 0)
        bs->skips++;
    p = (char *)((int)buf & ~3);
    shift = (buf - p) * 8;
    hi = *p++;
    hi = (hi << 8) | *(unsigned char *)p++;
    hi = (hi << 8) | *(unsigned char *)p++;
    hi = (hi << 8) | *(unsigned char *)p++;
    lo = *p++;
    lo = (lo << 8) | *(unsigned char *)p++;
    lo = (lo << 8) | *(unsigned char *)p++;
    lo = (lo << 8) | *(unsigned char *)p++;
    p += 4;
    bits = shift + (p - buf) * 8;
    if (shift != 0)
        bs->word = (hi << shift) | (lo >> (32 - shift));
    else
        bs->word = hi;
    bs->ext = 0;
    bs->code = 0;
    return buf + (bits - 57) / 8;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0036EB58);
#endif
