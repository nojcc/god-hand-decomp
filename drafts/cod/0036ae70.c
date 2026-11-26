/* cygnus-2.96. NON_MATCHING mpvhdec_DecGscSj: 156 words vs retail 159. Retail skips the start
 * code with a movn (acc = bitpos ? nxt << bitpos : nxt); here combine folds that to one sllv.
 * Reading the start code into a local that is never used keeps the movn (14 instructions off,
 * all in the prologue's scheduling), which the dead-store rule doesn't allow. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/criAix.h"
#include "godhand/MpvHandle.h"

/* Load the next big-endian word of the stream into w. */
#define MPV_LOADW(w)                    \
    w = *p++;                           \
    w <<= 8;                            \
    w |= (unsigned char)*p++;           \
    w <<= 8;                            \
    w |= (unsigned char)*p++;           \
    w <<= 8;                            \
    w |= (unsigned char)*p++

/* v = the next n bits (n > 0). */
#define MPV_GETBITS(v, n)                       \
    if (bitpos >= 32 - (n)) {                   \
        bitpos -= 32 - (n);                     \
        if (bitpos != 0) {                      \
            acc |= nxt >> ((n) - bitpos);       \
            v = acc >> (32 - (n));              \
            acc = nxt << bitpos;                \
        } else {                                \
            v = acc >> (32 - (n));              \
            acc = nxt;                          \
        }                                       \
        MPV_LOADW(nxt);                         \
    } else {                                    \
        v = acc >> (32 - (n));                  \
        acc <<= (n);                            \
        bitpos += (n);                          \
    }

/* v = the next bit. */
#define MPV_GETBIT(v)                           \
    v = acc >> 31;                              \
    if (bitpos == 31) {                         \
        acc = nxt;                              \
        bitpos = 0;                             \
        MPV_LOADW(nxt);                         \
    } else {                                    \
        bitpos++;                               \
        acc <<= 1;                              \
    }

/* Decodes a group of pictures header: the time code and the closed GOP
 * and broken link flags. */
__attribute__((section(".text.mpvhdec_DecGscSj")))
int mpvhdec_DecGscSj(MpvHandle *hn, SjObj *sj)
{
    SjChunk tail;
    MpvPicAtr *atr;
    SjChunk *ck;
    char *p;
    unsigned int acc;
    unsigned int nxt;
    int bitpos;
    unsigned int tc;

    atr = &hn->picAtr;
    ck = &hn->ck;
    hn->cur = 2;
    atr->f30++;
    hn->unk3FC = 0;
    hn->unk400 = 0;
    atr->unk68 = 0;
    sj->vt->getChunk(sj, 1, 0x7FFFFFFF, ck);

    p = (char *)((int)ck->data & ~3);
    bitpos = ((int)ck->data - (int)p) * 8;
    p += 4;
    MPV_LOADW(nxt);
    if (bitpos == 0)
        acc = nxt;
    else
        acc = nxt << bitpos;
    MPV_LOADW(nxt);

    MPV_GETBITS(tc, 25);
    atr->tcPic = tc & 0x3F;
    tc >>= 6;
    atr->tcSec = tc & 0x3F;
    tc >>= 7;
    atr->tcMin = tc & 0x3F;
    tc >>= 6;
    atr->tcHour = tc & 0x1F;
    atr->drop = tc >> 5;
    MPV_GETBIT(hn->d);
    MPV_GETBIT(hn->e);

    SJ_SplitChunk(ck, (int)(p + ((bitpos + 7) >> 3) - 8) - (int)hn->ck.data, ck, &tail);
    sj->vt->putChunk(sj, 0, ck);
    sj->vt->ungetChunk(sj, 1, &tail);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", mpvhdec_DecGscSj);
#endif
