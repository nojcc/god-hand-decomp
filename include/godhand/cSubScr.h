/* include/godhand/cSubScr.h - the sub screen manager and its menu screens (sn code at 0x160000..0x16Cxxx).
 *
 * D_003BD930 points at the one cSubScr. It runs a stack of sub screens (the
 * pause menu, the shop, and so on); each screen is a MenuScreen embedded in
 * it, and the selN fields are those screens' selection bytes (each at 0x64 in
 * its screen). Field names are ours; offsets are exact.
 */
#ifndef GODHAND_CSUBSCR_H
#define GODHAND_CSUBSCR_H

#include "godhand/cModel.h"

/* A menu screen run by the phase dispatcher ModeObj_updatePhase. */
typedef struct MenuScreen {
    char unk00[0x58];
    unsigned char busy;                 /* 0x58 nonzero: the manager waits for the screen */
    char unk59;
    unsigned char unk5A;                /* 0x5A..0x5D cleared when the sub screens open */
    unsigned char unk5B;
    unsigned char unk5C;
    unsigned char unk5D;
    char unk5E[2];
    int next;                           /* 0x60 screen to go to, -1 = stay */
    unsigned char sel;                  /* 0x64 selection */
    char unk65[0x70 - 0x65];
    cVtEnt *vtable;                     /* 0x70 g++ 2.x vtable: 2 opens, 3 closes, 4 and 5 run the screen */
    char unk74[0x130 - 0x74];
    short cursor;                       /* 0x130 0..3 */
    char unk132[2];
    unsigned short result;              /* 0x134 0 restarts the stage at choice's start point */
    short choice;                       /* 0x136 */
} MenuScreen;

/* One screen of the manager's table: its kind and the screen. */
typedef struct SubScrEnt {
    int kind;
    MenuScreen *screen;
} SubScrEnt;

typedef struct cSubScr {
    SubScrEnt ent[9];           /* 0x00 looked up by kind (func_0015FD18) */
    int kind;                   /* 0x48 open screen, -1 when closed */
    int nextKind;               /* 0x4C screen the manager switches to next */
    short open;                 /* 0x50 manager state, 0 when no sub screen runs */
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
    char padCA5[0xED0 - 0xCA5];
    unsigned int fadeColor;     /* 0xED0 overlay colour, alpha in the top byte (FadeOverlay_tick) */
    unsigned char fade;         /* 0xED4 overlay state; the manager also counts its fade steps in it */
    char padED5[3];
    int fadeTick;               /* 0xED8 */
    unsigned char unkEDC;       /* 0xEDC */
    signed char mode;           /* 0xEDD panel layout of the menus: 0 = four rows, 1 = two */
    char padEDE[2];
    unsigned int saved5D8;      /* 0xEE0 GameWork flags5D8 while open */
    unsigned int saved5E0;      /* 0xEE4 GameWork flags5E0 while open */
    int stack[11];              /* 0xEE8 kinds opened, innermost last */
    char padF14;
    unsigned char depth;        /* 0xF15 */
} cSubScr;

/* The screen of kinds 0 and 3 (its selection byte is sel794). The screens are
 * not laid out in cSubScr yet, so this one is reached by its offset. */
#define SUBSCR_SCREEN03(ss)  ((MenuScreen *)((char *)(ss) + 0x730))

extern cSubScr *D_003BD930;
extern void cSubScr_SubScrOn(cSubScr *self, int kind, unsigned char sel, unsigned char arg);

/* The open screen: func_0015FD18(self, self->kind). */
extern MenuScreen *Obj0000_Call_func_0015FD18_Field_48_161288(cSubScr *self);
extern void func_0015FF10(cSubScr *self);
extern int func_00160E78(cSubScr *self);
extern int func_00160F38(cSubScr *self);
extern int func_00160FF0(cSubScr *self);
extern void FadeOverlay_tick(cSubScr *self);

#endif /* GODHAND_CSUBSCR_H */
