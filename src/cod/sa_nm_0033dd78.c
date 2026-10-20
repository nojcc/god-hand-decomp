/* NON_MATCHING func_0033DD78 (cygnus-2.96 --drop-reorder;
 * PARK, 2 diffs): only the reload of the spilled rate pointer
 * (lw a0,4(sp)) lands after the channel lbu instead of before it.
 * Parse a RIFF/WAVE header: find the RIFF and data tags,
 * then report data offset, rate, channels, bits, block align, sample count and codec (0 = PCM16, 1 = PCM8, 2 = ADPCM4). */
#include "include_asm.h"

#ifdef NON_MATCHING
extern char *D_003EADA0;                /* "RIFF" */
extern char *D_003EADA4;                /* "data" */
extern int func_003A50B4(const void *a, const void *b, int n);

typedef struct WavFmt {
    short format;                       /* 0x00 */
    unsigned char channels;             /* 0x02 */
    char pad03;
    int rate;                           /* 0x04 */
    char pad08[4];
    char align;                         /* 0x0C */
    char pad0D;
    char bits;                          /* 0x0E */
} WavFmt;

__attribute__((section(".text.func_0033DD78")))
int func_0033DD78(char *buf, int len, short *dataOff, char *loop, char *bits, char *align, char *ch, int *rate,
                  int *nsamp, int *mult, short *codec)
{
    WavFmt *fmt;
    int size;
    int i;
    int r;
    int c;

    for (i = 0; i < len; i++)
        if (func_003A50B4(buf + i, D_003EADA0, 4) == 0)
            break;
    if (i == len)
        return -1;
    if (i & 3)
        return -1;
    fmt = (WavFmt *)(buf + i + 8);
    if (fmt->format >= 2)
        return -1;
    for (i = 0; i < len; i++)
        if (func_003A50B4(buf + i, D_003EADA4, 4) == 0)
            break;
    if (i == len)
        return -1;
    *dataOff = i + 8;
    size = *(int *)(buf + i + 4);
    *loop = -1;
    r = fmt->rate;
    c = fmt->channels;
    *rate = r;
    *ch = c;
    *bits = fmt->bits;
    *align = fmt->align;
    *nsamp = size / *align;
    *mult = 1;
    if (*bits == 16) {
        *codec = 0;
    } else if (*bits == 8) {
        *codec = 1;
    } else if (*bits == 4) {
        *align = *ch * 2;
        *mult = 4;
        *nsamp = size / 2 / *ch;
        *bits = 16;
        *codec = 2;
    }
    if (*bits == 0)
        return -1;
    if (*align == 0)
        return -1;
    if ((unsigned char)*ch != 1 && (unsigned char)*ch != 2)
        return -1;
    return *rate == 0 ? -1 : 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0033DD78);
#endif
