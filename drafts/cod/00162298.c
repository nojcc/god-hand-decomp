/* sn-2.95.3-136 */
/* func_00162298 (as: sn). Two instructions differ: when the reel list
 * scrolls left past the top, retail builds the 5 it stores in sel in $a0
 * where this builds it in $v1. */
#include "include_asm.h"
#include "godhand/gameWork.h"
#include "godhand/cSnd.h"
#include "godhand/cCoreSave.h"
#include "godhand/cIDBase.h"

#ifdef NON_MATCHING
#define MENU_KEY_LEFT    0x0001000001000000L  /* (pad and stick) */
#define MENU_KEY_RIGHT   0x0002000002000000L
#define MENU_KEY_UPDOWN  0x000C00000C000000L
#define MENU_KEY_OK      0x10000000L
#define MENU_KEY_BACK    0x20000000L
#define MENU_KEY_CLOSE   0x200000L

#define MENU_SE_MOVE     0x15F
#define MENU_SE_OK       0x15E
#define MENU_SE_NG       0x160
#define MENU_SE_BACK     0x161

#define REEL_ROWS        5              /* slots per reel row */
#define REEL_LIST_SHOWN  6              /* reel entries visible at once */
#define REEL_LIST_FIRST  12             /* ent[] index of the first list entry */
#define IDENT_KIND_PICKABLE 6           /* cIDBaseEnt.b8B of an entry that can be set */

/* The reel setting panel: picks a slot (row and column), then a reel from
 * a scrolling list. 001680d8.c reads the shared panel fields through raw offsets. */
typedef struct ReelPanel {
    char unk00[0x5A];
    signed char state;                  /* 0x5A 0 = pick a slot, 1 = pick a reel */
    char unk5B[0x60 - 0x5B];
    int timer;                          /* 0x60 */
    char unk64[0x80 - 0x64];
    cIDBaseEnt *ent[REEL_LIST_FIRST + REEL_LIST_SHOWN]; /* 0x80 the panel's display entries */
    char unkC8[0xEC - 0xC8];
    signed char col;                    /* 0xEC slot column, -1 = the exit button */
    signed char row;                    /* 0xED slot row, 0 or 1 */
    signed char sel;                    /* 0xEE cursor in the visible list */
    signed char top;                    /* 0xEF first visible reel */
    signed char reelNum;                /* 0xF0 reels in the list */
    signed char reel[1];                /* 0xF1 reel numbers of the list */
} ReelPanel;

extern unsigned int D_003BD938[];
extern int func_00162720(int a0);

/* Input step of the reel setting panel. */
__attribute__((section(".text.func_00162298")))
void func_00162298(ReelPanel *self)
{
    switch (self->state) {
    case 0:
        if (D_007474A0.rep & MENU_KEY_LEFT) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->col--;
        }
        if (D_007474A0.rep & MENU_KEY_RIGHT) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->col++;
        }
        if ((D_007474A0.rep & MENU_KEY_UPDOWN) && self->col != -1) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->row ^= 1;
        }
        self->col = self->col < -1 ? REEL_ROWS - 1 : self->col < REEL_ROWS ? self->col : -1;
        if (D_007474A0.trg & MENU_KEY_OK) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
            if (self->col != -1)
                self->state = 1;
            else
                func_00162720((int)self);
        }
        if (D_007474A0.trg & MENU_KEY_BACK) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
            func_00162720((int)self);
        }
        break;
    case 1:
        if (D_007474A0.rep & MENU_KEY_LEFT) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->sel--;
            if (self->sel < 0) {
                self->sel = 0;
                self->top--;
                if (self->top < 0) {
                    self->sel = REEL_LIST_SHOWN - 1;
                    self->top = self->reelNum - REEL_LIST_SHOWN;
                    if (self->top < 0)
                        self->top = 0;
                }
            }
        }
        if (D_007474A0.rep & MENU_KEY_RIGHT) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->sel++;
            if (self->sel >= REEL_LIST_SHOWN) {
                self->sel = REEL_LIST_SHOWN - 1;
                self->top++;
                if (self->top + REEL_LIST_SHOWN - 1 >= self->reelNum) {
                    self->sel = 0;
                    self->top = 0;
                }
            }
        }
        if (D_007474A0.trg & MENU_KEY_OK) {
            if (self->ent[self->sel + REEL_LIST_FIRST]->b8B == IDENT_KIND_PICKABLE) {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
                cCoreSave_setReelSlot(&D_00569B70, self->col + self->row * REEL_ROWS,
                                      D_003BD938[self->reel[self->sel + self->top]]);
            } else {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_NG, -1, -1, 0, 0);
            }
        }
        if (D_007474A0.trg & MENU_KEY_BACK) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
            self->state = 0;
        }
        break;
    }
    if (D_007474A0.trg & MENU_KEY_CLOSE) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
        self->timer = -1;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00162298);
#endif
