/* sn-2.95.3-136 */
/* sn-2.95.3-136 */
#include "godhand/gameWork.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

typedef struct cSubScr {
    char pad000[0x48];
    int kind;                   /* 0x48 open screen, -1 when closed */
    char pad04C[4];
    short open;                 /* 0x50 */
    char pad052[0x374 - 0x52];
    unsigned char sel374;       /* 0x374 screen 1 selection */
    char pad375[0x684 - 0x375];
    unsigned char sel684;       /* 0x684 screen 2 selection */
    char pad685[0x794 - 0x685];
    unsigned char sel794;       /* 0x794 screen 0/3 selection */
    char pad795[0x8E4 - 0x795];
    unsigned char sel8E4;       /* 0x8E4 screen 4 selection */
    char pad8E5[0xA24 - 0x8E5];
    unsigned char selA24;       /* 0xA24 screen 5 selection */
    char padA25[0xB44 - 0xA25];
    unsigned char selB44;       /* 0xB44 screen 6 selection */
    char padB45[0xC04 - 0xB45];
    unsigned char selC04;       /* 0xC04 screen 8 selection */
    char padC05[0xCA4 - 0xC05];
    unsigned char selCA4;       /* 0xCA4 screen 7 selection */
    char padCA5[0xEDC - 0xCA5];
    unsigned char unkEDC;       /* 0xEDC */
    char padEDD[3];
    unsigned int saved5D8;      /* 0xEE0 GameWork flags5D8 while open */
    unsigned int saved5E0;      /* 0xEE4 GameWork flags5E0 while open */
    int stack[11];              /* 0xEE8 kinds opened, innermost last */
    char padF14;
    unsigned char depth;        /* 0xF15 */
} cSubScr;

/* A GameWork field read through its constant address. Retail addresses the
 * flag words from &D_007474A0.flags5E4 and &D_007474A0.flags5D8; a plain
 * D_007474A0.field access addresses them from D_007474A0 and changes the code. */
#define GAMEWORK_AT(field) \
    (*(__typeof__(D_007474A0.field) *)((char *)&D_007474A0 + (int)&((GameWork *)0)->field))

/* Open sub screen `kind` unless the game flags block it or one is open: save the game flag words, preset the screen's selection, flash the player, set the sub-screen flags and push the kind. */
__attribute__((section(".text.cSubScr_SubScrOn")))
void cSubScr_SubScrOn(cSubScr *self, int kind, unsigned char sel, unsigned char arg)
{
    unsigned long f = GAMEWORK_AT(flags5E4);
    unsigned long g;
    unsigned long bit;

    if (f & 0x20000000)
        return;
    if (f & 0x10000000)
        return;
    bit = (f >> 6) & 1;
    if (bit != 0)
        return;
    g = GAMEWORK_AT(flags);
    bit = (g >> 3) & 1;
    if (bit != 0)
        return;
    if (f & 0x200000)
        return;
    if (self->open != 0)
        return;
    self->unkEDC = arg;
    self->saved5D8 = D_007474A0.flags5D8;
    self->saved5E0 = D_007474A0.flags5E0;
    self->kind = kind;
    self->depth = 0;
    switch (kind) {
    case 1:
        self->sel374 = sel;
        break;
    case 2:
        self->sel684 = sel;
        break;
    case 3:
        self->sel794 = sel;
        break;
    case 4:
        self->sel8E4 = 0;
        break;
    case 5:
        self->selA24 = 0;
        break;
    case 7:
        self->selCA4 = 0;
        break;
    case 8:
        self->selC04 = 0;
        break;
    case 6:
        self->selB44 = 0;
        break;
    case 0:
    default:
        self->sel794 = 0;
        break;
    }
    self->open = 1;
    Getplayer()->hitFlash = 5.0f;
    GAMEWORK_AT(flags5D8) |= 0x40000000;
    GAMEWORK_AT(flags5D8) |= 0x80000000;
    GAMEWORK_AT(flags5D8) |= 0x20000000;
    GAMEWORK_AT(flags5D8) |= 0x10000000;
    GAMEWORK_AT(flags5D8) |= 0x08000000;
    GAMEWORK_AT(flags5D8) |= 0x40000;
    GAMEWORK_AT(flags5E0) |= 0x02000000;
    GAMEWORK_AT(flags5E4) |= 0x08000000;
    self->stack[self->depth] = kind;
    self->depth++;
}
