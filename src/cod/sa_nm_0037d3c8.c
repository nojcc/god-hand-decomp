/* NON_MATCHING func_0037D3C8: voice volume update.
 * Everything except case 4 matches.
 * Retail selects the voice bus volume into a temp (v0, beql) before `r = m * pan / 0x7F00; r = r * vol / 0x7F00`; adding that temp swaps the r/g registers (a1/a2), and without it the selection loads straight into r. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct SndGlob37D3C8 {
    char pad00[0x14];
    int outMode;                        /* 0x14 2 = stereo */
    char pad18[0x3A - 0x18];
    short volSe;                        /* 0x3A */
    short volBgmA;                      /* 0x3C */
    short volBgmB;                      /* 0x3E */
    short volVoiceA;                    /* 0x40 */
    short volVoiceB;                    /* 0x42 */
} SndGlob37D3C8;

typedef struct Voice37D3C8 {
    char pad00[4];
    unsigned char flag;                 /* 0x04 bit 0 = alternate bus */
    unsigned char type;                 /* 0x05 */
    char pad06[0x26 - 0x06];
    short panMono;                      /* 0x26 */
    short panStereo;                    /* 0x28 */
    short pan;                          /* 0x2A */
    char pad2C[4];
    short gain;                         /* 0x30 */
    char pad32[6];
    short volMono;                      /* 0x38 */
    short volStereo;                    /* 0x3A */
    short vol;                          /* 0x3C */
    short out;                          /* 0x3E */
} Voice37D3C8;

extern SndGlob37D3C8 D_0076A790;

__attribute__((section(".text.func_0037D3C8")))
void func_0037D3C8(Voice37D3C8 *v)
{
    SndGlob37D3C8 *g = &D_0076A790;
    int r = 0;

    if (g->outMode == 2) {
        v->vol = v->volStereo;
        v->pan = v->panStereo;
    } else {
        v->vol = v->volMono;
        v->pan = v->panMono;
    }
    if (v->vol == 0x80)
        v->vol = 0x7FFF;
    else
        v->vol = v->vol << 8;
    switch (v->type) {
    case 9:
        r = g->volSe * v->vol / 0x7F00 * v->gain / 0x7F00;
        break;
    case 1:
        r = g->volSe * v->vol / 0x7F00 * v->gain / 0x7F00;
        break;
    case 2:
        if (v->flag & 1)
            r = g->volBgmA * v->pan / 0x7F00;
        else
            r = g->volBgmB * v->pan / 0x7F00;
        break;
    case 4:
        if (v->flag & 1)
            r = g->volVoiceA;
        else
            r = g->volVoiceB;
        r = r * v->pan / 0x7F00;
        r = r * v->vol / 0x7F00;
        break;
    }
    v->out = r;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0037D3C8);
#endif
