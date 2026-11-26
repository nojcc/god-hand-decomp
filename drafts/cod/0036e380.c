/* cygnus-2.96 (-freorder-blocks dropped) */
#include "include_asm.h"

/* Parse an MPEG-1 sequence_header() into the decoder state at ctx+0x160 (size,
 * aspect, frame rate, bit rate, VBV size, flags), skip any loaded quantiser
 * matrices, derive the macroblock sizes and count the invalid fields.
 * Still differs from retail (504 words against 502): cc1's R5900 loop
 * lengthening pads the non-intra matrix skip loop with two nops and leaves the
 * beqz delay slot empty; retail has neither there (parseEsc's last skip loop does
 * get both). Everything before that loop and after it is exact. */

#ifdef NON_MATCHING
void func_0036E200(void *a0);
void calcHvSize(int *s);
void func_0036E378(void *a0);

#define REFILL()                                    \
    nxt = *p++;                                     \
    nxt <<= 8;                                      \
    nxt |= (unsigned char)*p++;                     \
    nxt <<= 8;                                      \
    nxt |= (unsigned char)*p++;                     \
    nxt <<= 8;                                      \
    nxt |= (unsigned char)*p++

#define GETBITS(n, off)                                             \
    if (bitpos >= 32 - (n)) {                                       \
        bitpos -= 32 - (n);                                         \
        if (bitpos != 0) {                                          \
            acc |= nxt >> ((n) - bitpos);                           \
            *(int *)(d + (off)) = acc >> (32 - (n));                \
            acc = nxt << bitpos;                                    \
        } else {                                                    \
            *(int *)(d + (off)) = acc >> (32 - (n));                \
            acc = nxt;                                              \
        }                                                           \
        REFILL();                                                   \
    } else {                                                        \
        *(int *)(d + (off)) = acc >> (32 - (n));                    \
        acc <<= (n);                                                \
        bitpos += (n);                                              \
    }

#define SKIPBITS(n)                                                 \
    bitpos += (n);                                                  \
    if (bitpos >= 32) {                                             \
        bitpos -= 32;                                               \
        acc = nxt << bitpos;                                        \
        REFILL();                                                   \
    } else {                                                        \
        acc <<= (n);                                                \
    }

__attribute__((section(".text.parseShc")))
char *parseShc(char *ctx, char *start)
{
    char *d;
    char *p;
    unsigned int acc;
    unsigned int nxt;
    int bitpos;
    int state;
    int nb;

    d = ctx + 0x160;
    *(int *)(d + 0x420) = 1;
    *(int *)(d + 0x42C) = *(int *)(d + 0x42C) + 1;
    *(int *)(d + 0x4A4) = 0;
    *(int *)(d + 0x4A8) = 0;
    *(int *)(d + 0x4AC) = 0;
    state = *(int *)(d + 0x308);
    if ((state != 0 && state != 0x40) || *(int *)(d + 0x30C) != 0) {
        *(int *)(d + 0x494) = *(int *)(d + 0x494) + 1;
    }
    func_0036E200(d);

    p = (char *)((int)start & ~3);
    bitpos = ((int)start - (int)p) * 8;

    acc = *p++;
    acc <<= 8;
    acc |= (unsigned char)*p++;
    acc <<= 8;
    acc |= (unsigned char)*p++;
    acc <<= 8;
    acc |= (unsigned char)*p++;
    REFILL();

    acc <<= bitpos;
    if (bitpos != 0) {
        *(int *)(d + 0x0) = acc | (nxt >> (32 - bitpos));
        acc = nxt << bitpos;
    } else {
        *(int *)(d + 0x0) = acc;
        acc = nxt;
    }
    REFILL();

    GETBITS(12, 0x4);
    GETBITS(12, 0x8);
    GETBITS(4, 0xC);
    GETBITS(4, 0x10);
    GETBITS(18, 0x14);
    GETBITS(1, 0x18);
    GETBITS(10, 0x1C);
    GETBITS(1, 0x20);
    GETBITS(1, 0x24);
    if (*(int *)(d + 0x24) != 0) {
        int k;

        for (k = 0; k < 64; k++) {
            SKIPBITS(8);
        }
    }
    GETBITS(1, 0x28);
    if (*(int *)(d + 0x28) != 0) {
        int k;

        for (k = 0; k < 64; k++) {
            SKIPBITS(8);
        }
    }
    calcHvSize((int *)d);
    func_0036E378(d);
    if (*(int *)(d + 0x2C4) == 0) {
        *(int *)(d + 0x494) = *(int *)(d + 0x494) + 1;
    }
    if (*(int *)(d + 0x2C8) == 0) {
        *(int *)(d + 0x494) = *(int *)(d + 0x494) + 1;
    }
    if ((unsigned int)(*(int *)(d + 0xC) - 1) >= 4) {
        *(int *)(d + 0x494) = *(int *)(d + 0x494) + 1;
    }
    if ((unsigned int)(*(int *)(d + 0x10) - 1) >= 8) {
        *(int *)(d + 0x494) = *(int *)(d + 0x494) + 1;
    }
    nb = bitpos + (p - start) * 8;
    *(int *)(d + 0x308) = 0x10;
    *(int *)(d + 0x30C) = 1;
    return start + (nb - 57) / 8;
}
#else
INCLUDE_ASM("asm/nonmatching", parseShc);
#endif
