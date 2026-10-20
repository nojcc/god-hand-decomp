/* NON_MATCHING func_0036AE70 (cygnus-2.96 dr;
 * PARK, 120 diffs): MPV GOP header parse.
 * Prologue
 * matches up to the start-code skip; retail keeps `bitpos ? nxt << bitpos : nxt` as xori/movn
 * while ours combines it to a bare sllv, and the time-code/bit reads schedule differently. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Sj { unsigned char *f0; int f4; } Sj;

typedef struct SjIf {
    int pad[6];
    void (*getChunk)(void *sj, int id, unsigned int len, Sj *out);   /* +0x18 */
    void (*ungetChunk)(void *sj, int id, Sj *ck);                    /* +0x1C */
    void (*putChunk)(void *sj, int id, Sj *ck);                      /* +0x20 */
} SjIf;

typedef struct SjObj { SjIf *vt; } SjObj;

extern void func_0033ACA0(Sj *ck, int n, Sj *a, Sj *b);

#define LOADW(w)                                    \
    w = *p++;                                       \
    w <<= 8;                                        \
    w |= (unsigned char)*p++;                       \
    w <<= 8;                                        \
    w |= (unsigned char)*p++;                       \
    w <<= 8;                                        \
    w |= (unsigned char)*p++

#define GETBIT1(dst)                                \
    dst = acc >> 31;                                \
    if (bitpos == 31) {                             \
        acc = nxt;                                  \
        bitpos = 0;                                 \
        LOADW(nxt);                                 \
    } else {                                        \
        bitpos++;                                   \
        acc <<= 1;                                  \
    }

__attribute__((section(".text.func_0036AE70")))
int func_0036AE70(char *h, SjObj *sj)
{
    Sj tail;
    Sj *ck;
    char *d;
    char *p;
    unsigned int acc;
    unsigned int nxt;
    unsigned int tc;
    unsigned int sc;
    int bitpos;

    d = h + 0x1D0;
    ck = (Sj *)(h + 0x38C);
    *(int *)(h + 0x3B8) = 2;
    *(int *)(d + 0x30) = *(int *)(d + 0x30) + 1;
    *(int *)(h + 0x3FC) = 0;
    *(int *)(h + 0x400) = 0;
    *(int *)(d + 0x68) = 0;
    sj->vt->getChunk(sj, 1, 0x7FFFFFFF, ck);

    p = (char *)((int)ck->f0 & ~3);
    bitpos = ((int)ck->f0 - (int)p) * 8;
    LOADW(acc);
    LOADW(nxt);
    acc <<= bitpos;
    if (bitpos != 0) {
        sc = acc | (nxt >> (32 - bitpos));
        acc = nxt << bitpos;
    } else {
        sc = acc;
        acc = nxt;
    }
    LOADW(nxt);

    if (bitpos >= 7) {
        bitpos -= 7;
        if (bitpos != 0) {
            acc |= nxt >> (25 - bitpos);
            tc = acc >> 7;
            acc = nxt << bitpos;
        } else {
            tc = acc >> 7;
            acc = nxt;
        }
        LOADW(nxt);
    } else {
        tc = acc >> 7;
        acc <<= 25;
        bitpos += 25;
    }
    *(int *)(d + 0x2C) = tc & 0x3F;
    tc >>= 6;
    *(int *)(d + 0x28) = tc & 0x3F;
    tc >>= 7;
    *(int *)(d + 0x24) = tc & 0x3F;
    tc >>= 6;
    *(int *)(d + 0x20) = tc & 0x1F;
    *(int *)(d + 0x1C) = tc >> 5;
    GETBIT1(*(int *)(h + 0x2B4));
    GETBIT1(*(int *)(h + 0x2B8));

    func_0033ACA0(ck, (int)p + ((bitpos + 7) >> 3) - 8 - *(int *)(h + 0x38C), ck, &tail);
    sj->vt->putChunk(sj, 0, ck);
    sj->vt->ungetChunk(sj, 1, &tail);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0036AE70);
#endif
