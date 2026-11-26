/* cygnus-2.96 (-freorder-blocks dropped, extern_jtbl D_0045A5A0) */
#include "include_asm.h"

/* Parse an MPEG-2 extension (sequence, display, quantiser matrix, copyright,
 * scalable, picture display, picture coding, spatial and temporal scalable) into
 * the decoder state at ctx+0x160, counting extensions that arrive after the wrong
 * header and ending the header run.
 * Still differs from retail (7 instructions, same length): retail sets up the two
 * frame-centre offset pointers of the picture display extension after the count
 * test, as reduced loop variables (v first); this C initialises them before it.
 * Indexing both arrays by n instead makes cc1 fold them into one register. */

#ifdef NON_MATCHING
extern int D_0045A560[];
void calcHvSize(int *s);
void func_0036E378(void *a0);
void calcNumberOfFrameCentreOffsets(void *o);
void calcPictureCodingExt(void *o);

#define REFILL()                                    \
    nxt = *p++;                                     \
    nxt <<= 8;                                      \
    nxt |= (unsigned char)*p++;                     \
    nxt <<= 8;                                      \
    nxt |= (unsigned char)*p++;                     \
    nxt <<= 8;                                      \
    nxt |= (unsigned char)*p++

#define GETBITS_TO(n, dst)                                          \
    if (bitpos >= 32 - (n)) {                                       \
        bitpos -= 32 - (n);                                         \
        if (bitpos != 0) {                                          \
            acc |= nxt >> ((n) - bitpos);                           \
            (dst) = acc >> (32 - (n));                              \
            acc = nxt << bitpos;                                    \
        } else {                                                    \
            (dst) = acc >> (32 - (n));                              \
            acc = nxt;                                              \
        }                                                           \
        REFILL();                                                   \
    } else {                                                        \
        (dst) = acc >> (32 - (n));                                  \
        acc <<= (n);                                                \
        bitpos += (n);                                              \
    }

#define GETBITS(n, off) GETBITS_TO(n, *(int *)(d + (off)))

#define SKIPBITS(n)                                                 \
    bitpos += (n);                                                  \
    if (bitpos >= 32) {                                             \
        bitpos -= 32;                                               \
        acc = nxt << bitpos;                                        \
        REFILL();                                                   \
    } else {                                                        \
        acc <<= (n);                                                \
    }

#define SKIPMATRIX()                                                \
    {                                                               \
        int k;                                                      \
        for (k = 0; k < 64; k++) {                                  \
            SKIPBITS(8);                                            \
        }                                                           \
    }

__attribute__((section(".text.parseEsc")))
char *parseEsc(char *ctx, char *start)
{
    char *d;
    char *p;
    unsigned int acc;
    unsigned int nxt;
    int bitpos;
    int state;
    int prev;
    int id;
    int i;
    int n;
    int *h;
    int *v;
    int nb;

    d = ctx + 0x160;
    p = (char *)((int)start & ~3);
    bitpos = ((int)start - (int)p) * 8;
    *(int *)(d + 0x438) = *(int *)(d + 0x438) + 1;

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
        *(int *)(d + 0x34) = acc | (nxt >> (32 - bitpos));
        acc = nxt << bitpos;
    } else {
        *(int *)(d + 0x34) = acc;
        acc = nxt;
    }
    REFILL();

    GETBITS(4, 0x40);

    if ((*(int *)(d + 0x308) != 0 && *(int *)(d + 0x308) != 0x10) ||
        (*(int *)(d + 0x30C) != 0 && *(int *)(d + 0x30C) != *(int *)(d + 0x40))) {
        *(int *)(d + 0x494) = *(int *)(d + 0x494) + 1;
    }
    if ((*(int *)(d + 0x420) != 1 &&
         (*(int *)(d + 0x40) == 1 || *(int *)(d + 0x40) == 2 || *(int *)(d + 0x40) == 5)) ||
        (*(int *)(d + 0x420) != 3 &&
         (*(int *)(d + 0x40) == 3 || (*(int *)(d + 0x40) == 4 || *(int *)(d + 0x40) == 7) ||
          *(int *)(d + 0x40) == 8 || *(int *)(d + 0x40) == 9 || *(int *)(d + 0x40) == 10))) {
        *(int *)(d + 0x494) = *(int *)(d + 0x494) + 1;
    }

    switch (*(int *)(d + 0x40)) {
    case 1:
        GETBITS(8, 0x44);
        GETBITS(1, 0x48);
        GETBITS(2, 0x4C);
        GETBITS(2, 0x50);
        GETBITS(2, 0x54);
        GETBITS(12, 0x58);
        GETBITS(1, 0x18);
        GETBITS(8, 0x5C);
        GETBITS(1, 0x60);
        GETBITS(2, 0x64);
        GETBITS(5, 0x68);
        if (*(int *)(d + 0x4C) != 1) {
            *(int *)(d + 0x4C) = 1;
            *(int *)(d + 0x494) = *(int *)(d + 0x494) + 1;
        }
        *(int *)(d + 0x318) = D_0045A560[*(int *)(d + 0x4C)];
        calcHvSize((int *)d);
        *(int *)(d + 0x2D4) = (*(int *)(d + 0x58) << 18) | *(int *)(d + 0x14);
        *(int *)(d + 0x2D8) = (*(int *)(d + 0x5C) << 10) | *(int *)(d + 0x1C);
        break;
    case 2:
        GETBITS(3, 0x6C);
        GETBITS(1, 0x70);
        if (*(int *)(d + 0x70) != 0) {
            GETBITS(8, 0x74);
            GETBITS(8, 0x78);
            GETBITS(8, 0x7C);
        }
        GETBITS(14, 0x80);
        GETBITS(1, 0x18);
        GETBITS(14, 0x84);
        break;
    case 3:
        GETBITS(1, 0x24);
        if (*(int *)(d + 0x24) != 0) {
            SKIPMATRIX();
        }
        GETBITS(1, 0x28);
        if (*(int *)(d + 0x28) != 0) {
            SKIPMATRIX();
        }
        GETBITS(1, 0x158);
        if (*(int *)(d + 0x158) != 0) {
            SKIPMATRIX();
        }
        GETBITS(1, 0x15C);
        if (*(int *)(d + 0x15C) != 0) {
            SKIPMATRIX();
        }
        func_0036E378(d);
        break;
    case 4:
        GETBITS(1, 0x19C);
        GETBITS(8, 0x1A0);
        GETBITS(1, 0x1A4);
        GETBITS(7, 0x1A8);
        GETBITS(1, 0x18);
        GETBITS(20, 0x1AC);
        GETBITS(1, 0x18);
        GETBITS(22, 0x1B0);
        GETBITS(1, 0x18);
        GETBITS(22, 0x1B4);
        break;
    case 5:
        *(int *)(d + 0x310) = 1;
        GETBITS(2, 0x88);
        GETBITS(4, 0x8C);
        if (*(int *)(d + 0x88) == 1) {
            GETBITS(14, 0x90);
            GETBITS(1, 0x18);
            GETBITS(14, 0x94);
            GETBITS(5, 0x98);
            GETBITS(5, 0x9C);
            GETBITS(5, 0xA0);
            GETBITS(5, 0xA4);
        } else if (*(int *)(d + 0x88) == 3) {
            GETBITS(1, 0xA8);
            if (*(int *)(d + 0xA8) != 0) {
                GETBITS(1, 0xAC);
            }
            GETBITS(3, 0xB0);
            GETBITS(3, 0xB4);
        }
        break;
    case 7:
        calcNumberOfFrameCentreOffsets(d);
        v = (int *)(d + 0x16C);
        h = (int *)(d + 0x160);
        for (n = 0; n < *(int *)(d + 0x38); n++) {
            GETBITS_TO(16, *h);
            GETBITS(1, 0x18);
            GETBITS_TO(16, *v);
            GETBITS(1, 0x18);
            v++;
            h++;
        }
        break;
    case 8:
        GETBITS(4, 0x104);
        GETBITS(4, 0x108);
        GETBITS(4, 0x10C);
        GETBITS(4, 0x110);
        GETBITS(2, 0x114);
        GETBITS(2, 0x118);
        GETBITS(1, 0x11C);
        GETBITS(1, 0x120);
        GETBITS(1, 0x124);
        GETBITS(1, 0x128);
        GETBITS(1, 0x12C);
        GETBITS(1, 0x130);
        GETBITS(1, 0x134);
        GETBITS(1, 0x138);
        GETBITS(1, 0x13C);
        GETBITS(1, 0x140);
        if (*(int *)(d + 0x140) != 0) {
            GETBITS(1, 0x144);
            GETBITS(3, 0x148);
            GETBITS(1, 0x14C);
            GETBITS(7, 0x150);
            GETBITS(8, 0x154);
        }
        calcHvSize((int *)d);
        calcPictureCodingExt(d);
        if (*(int *)(d + 0x3C4) == 0) {
            *(int *)(ctx + 0x154) = 0;
        }
        break;
    case 9:
        *(int *)(d + 0x314) = 1;
        GETBITS(10, 0x184);
        GETBITS(1, 0x18);
        GETBITS(15, 0x188);
        GETBITS(1, 0x18);
        GETBITS(15, 0x18C);
        GETBITS(2, 0x190);
        GETBITS(1, 0x194);
        GETBITS(1, 0x198);
        break;
    case 10:
        GETBITS(2, 0x178);
        GETBITS(10, 0x17C);
        GETBITS(1, 0x18);
        GETBITS(10, 0x180);
        break;
    default:
        *(int *)(d + 0x494) = *(int *)(d + 0x494) + 1;
        break;
    }

    nb = bitpos + (p - start) * 8;
    *(int *)(d + 0x308) = 0;
    *(int *)(d + 0x30C) = 0;
    return start + (nb - 57) / 8;
}
#else
INCLUDE_ASM("asm/nonmatching", parseEsc);
#endif
