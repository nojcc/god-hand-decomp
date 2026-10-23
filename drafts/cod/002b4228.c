/* retail has mtc1 / nop / div.s, ours mtc1 / div.s (7 insns of shift).
* func_002B42F0: 35 vs 39 words - the flag test and clear now match; retail keeps the
 * bit-6 arm and the 0x8000 case as two copies of the state-7 stores where ours cross-jumps them. */
#include "include_asm.h"

#ifdef NON_MATCHING

typedef struct MsgWinAnim {
    char unk00[0xC];
    unsigned char state;        /* 0x0C */
    unsigned char unk0D;        /* 0x0D */
    unsigned char unk0E;        /* 0x0E */
    unsigned char unk0F;        /* 0x0F */
    int step;                   /* 0x10 */
    int flags;                  /* 0x14 */
    char unk18[0x8C - 0x18];
    unsigned short *text;       /* 0x8C */
    char unk90[0x98 - 0x90];
    float scaleX;               /* 0x98 */
    float scaleY;               /* 0x9C */
    float alpha;                /* 0xA0 */
} MsgWinAnim;

extern void func_002B21F0(void *self, unsigned short id);

__attribute__((section(".text.func_002B4228")))
int func_002B4228(MsgWinAnim *win)
{
    unsigned int rest;
    float t, t2;

    win->step++;
    rest = 6 - win->step;
    t = (float)rest / 6.0f;
    t2 = (float)(rest * rest) / 36.0f;
    win->alpha = t2;
    win->scaleY = win->scaleX = 2.0f * t - t2;
    return win->step == 6;
}

__attribute__((section(".text.func_002B42F0")))
void func_002B42F0(MsgWinAnim *win)
{
    int flags = win->flags;
    unsigned long f;
    unsigned long bit;

    win->flags = flags & ~8;
    f = flags;
    bit = (f >> 6) & 1;
    if (bit != 0) {
        win->unk0F = 0;
        win->state = 7;
    } else {
        switch (*win->text & 0xFF00) {
        case 0x8000:
            win->unk0F = 0;
            win->state = 7;
            break;
        case 0x9000:
            func_002B21F0(win, win->text[1]);
        default:
            win->unk0F = 0;
            win->state = 0;
            break;
        }
    }
    win->unk0D = 0;
    win->unk0E = 0;
}

#else

INCLUDE_ASM("asm/nonmatching", func_002B4228);
INCLUDE_ASM("asm/nonmatching", func_002B42F0);

#endif
