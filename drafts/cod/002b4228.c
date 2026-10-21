/* retail has mtc1 / nop / div.s, ours mtc1 / div.s (7 insns of shift).
* func_002B42F0: 7 insns - ours sign-extends the 64-bit flags test and the
 * &~8 result (dsll32/dsra32) where retail goes straight lw/dsrl/andi. */
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

extern void func_002B21F0(MsgWinAnim *win, unsigned short arg);

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

void func_002B42F0(MsgWinAnim *win)
{
    unsigned long flags;

    flags = win->flags;
    win->flags = flags & ~8;
    if (((flags >> 6) & 1) != 0) {
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
    win->unk0E = 0;
    win->unk0D = 0;
}

#else

INCLUDE_ASM("asm/nonmatching", func_002B4228);
INCLUDE_ASM("asm/nonmatching", func_002B42F0);

#endif
