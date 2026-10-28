/* NON_MATCHING func_00161D08 (sn-2.95.3-136): 344 words vs 347 (346 with a byte slot parameter).
 * Retail indexes D_003BD938[i] in the reel scan as i*4 off the table base, reloaded after each
 * cCoreSave_getReelSlot call, and computes i + 1 at the top of the loop; this build walks a pointer
 * instead, and everything after the scan is shifted. Retail also masks the slot argument to a byte at
 * every call, so cCoreSave_getReelSlot's slot parameter is unsigned char. */
#include "include_asm.h"
#include "godhand/cIDBase.h"
#include "godhand/cCoreSave.h"

#ifdef NON_MATCHING

#define GODREEL_NUM        28      /* reels in D_003BD938 */
#define GODREEL_SLOT_NUM   10      /* equip slots */
#define GODREEL_LIST_ROWS  6       /* visible rows of the owned-reel list */
#define GODREEL_NO_SLOT    0x1F    /* cCoreSave_getReelSlot: slot is empty */

/* cGodReelMenu.ent slots */
enum {
    GODREEL_ENT_CURSOR,                 /* slot cursor */
    GODREEL_ENT_LIST_CURSOR,
    GODREEL_ENT_SLOT,                   /* GODREEL_SLOT_NUM slot icons */
    GODREEL_ENT_ROW = GODREEL_ENT_SLOT + GODREEL_SLOT_NUM,     /* GODREEL_LIST_ROWS list rows */
    GODREEL_ENT_SLOT_FRAME = GODREEL_ENT_ROW + GODREEL_LIST_ROWS + 2,
    GODREEL_ENT_LIST_FRAME,
    GODREEL_ENT_HELP_A,
    GODREEL_ENT_HELP_B,
    GODREEL_ENT_SCROLL_BAR,
    GODREEL_ENT_NAME_A,
    GODREEL_ENT_NAME_B,
    GODREEL_ENT_NUM
};

/* The God Reel equip screen: a cIDBase display plus its entry handles and cursors. */
typedef struct cGodReelMenu {
    cIDBaseObj base;                            /* 0x00 */
    char unk48[0x5A - 0x48];
    signed char mode;                           /* 0x5A 0: slot side, 1: list side */
    char unk5B[0x80 - 0x5B];
    cIDBaseEnt *ent[GODREEL_ENT_NUM];          /* 0x80 */
    signed char slotX;                          /* 0xEC -1: no slot selected */
    signed char slotY;                          /* 0xED */
    signed char row;                            /* 0xEE */
    signed char top;                            /* 0xEF first list row shown */
    signed char num;                            /* 0xF0 owned reels not in a slot */
    signed char list[GODREEL_NUM];              /* 0xF1 */
} cGodReelMenu;

extern float D_0041F3E0[];      /* cursor x per slot column */
extern float D_0041F3F8[];      /* cursor y per slot row */
extern float D_0041F400[];      /* list cursor y per row */
extern int D_003BD938[];        /* reel ids */

/* Refresh the God Reel screen: slot icons, the owned-reel list, cursors, scroll bar and names. */
__attribute__((section(".text.func_00161D08")))
void func_00161D08(cGodReelMenu *self)
{
    unsigned int i;
    unsigned char j;
    int found;
    unsigned short slot;
    unsigned short msg;

    self->ent[GODREEL_ENT_CURSOR]->posX = D_0041F3F8[self->slotY];
    if (self->slotX != -1)
        self->ent[GODREEL_ENT_CURSOR]->posY = D_0041F3E0[self->slotX];
    self->ent[GODREEL_ENT_LIST_CURSOR]->posY = D_0041F400[self->row];
    self->ent[GODREEL_ENT_HELP_A]->msg = 0x20BB;
    self->ent[GODREEL_ENT_HELP_B]->msg = 0x20BB;

    self->num = 0;
    for (i = 0; i < GODREEL_NUM; i++) {
        if (cCoreSave_ckGodReel(&D_00569B70, D_003BD938[i])) {
            found = 0;
            for (j = 0; j < GODREEL_SLOT_NUM; j++) {
                if (cCoreSave_getReelSlot(&D_00569B70, j) == D_003BD938[i]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                self->list[self->num] = i;
                self->num++;
            }
        }
    }

    for (i = 0; i < GODREEL_SLOT_NUM; i++) {
        if (cCoreSave_getReelSlot(&D_00569B70, i) == GODREEL_NO_SLOT) {
            self->ent[GODREEL_ENT_SLOT + i]->b8B = 7;
            self->ent[GODREEL_ENT_SLOT + i]->msg = 0x30C1;
        } else {
            self->ent[GODREEL_ENT_SLOT + i]->b8B = 6;
            self->ent[GODREEL_ENT_SLOT + i]->msg = cCoreSave_getReelSlot(&D_00569B70, i) + 0x30D1;
        }
    }

    for (i = 0; i < GODREEL_LIST_ROWS; i++) {
        if (i + self->top < self->num) {
            self->ent[GODREEL_ENT_ROW + i]->msg = D_003BD938[self->list[i + self->top]] + 0x30D1;
            self->ent[GODREEL_ENT_ROW + i]->b8B = 6;
        } else {
            self->ent[GODREEL_ENT_ROW + i]->b8B = 7;
            self->ent[GODREEL_ENT_ROW + i]->msg = 0x30C1;
        }
    }

    if (self->slotX == -1) {
        self->ent[GODREEL_ENT_SLOT_FRAME]->flags &= ~IDENT_FLAG_NO_DRAW;
        self->ent[GODREEL_ENT_CURSOR]->flags |= IDENT_FLAG_NO_DRAW;
        self->ent[GODREEL_ENT_CURSOR]->flags |= IDENT_FLAG_CHILD;
        self->ent[GODREEL_ENT_LIST_CURSOR]->flags |= IDENT_FLAG_NO_DRAW;
    } else {
        self->ent[GODREEL_ENT_SLOT_FRAME]->flags |= IDENT_FLAG_NO_DRAW;
        self->ent[GODREEL_ENT_CURSOR]->flags &= ~IDENT_FLAG_CHILD;
        if (self->mode == 0) {
            self->ent[GODREEL_ENT_CURSOR]->flags &= ~IDENT_FLAG_NO_DRAW;
            self->ent[GODREEL_ENT_LIST_FRAME]->flags &= ~IDENT_FLAG_CHILD;
            self->ent[GODREEL_ENT_LIST_CURSOR]->flags |= IDENT_FLAG_NO_DRAW;
        } else if (self->mode == 1) {
            self->ent[GODREEL_ENT_CURSOR]->flags |= IDENT_FLAG_NO_DRAW;
            self->ent[GODREEL_ENT_LIST_FRAME]->flags &= ~IDENT_FLAG_CHILD;
            self->ent[GODREEL_ENT_LIST_CURSOR]->flags &= ~IDENT_FLAG_NO_DRAW;
            msg = self->ent[GODREEL_ENT_ROW + self->row]->b8B == 6 ? 0x20BB : 0x20BC;
            self->ent[GODREEL_ENT_HELP_A]->msg = msg;
            self->ent[GODREEL_ENT_HELP_B]->msg = msg;
        }
    }

    if (self->num >= 7) {
        self->ent[GODREEL_ENT_SCROLL_BAR]->sclY = 6.0f / self->num;
        self->ent[GODREEL_ENT_SCROLL_BAR]->posY = self->ent[GODREEL_ENT_SCROLL_BAR]->src->posY
            + self->ent[GODREEL_ENT_SCROLL_BAR]->src->f18 * (1.0f - self->ent[GODREEL_ENT_SCROLL_BAR]->sclY)
              * (self->top / (self->num - 6.0f));
    } else {
        self->ent[GODREEL_ENT_SCROLL_BAR]->sclY = 1.0f;
        self->ent[GODREEL_ENT_SCROLL_BAR]->posY = self->ent[GODREEL_ENT_SCROLL_BAR]->src->posY;
    }

    if (self->slotX != -1) {
        slot = cCoreSave_getReelSlot(&D_00569B70, self->slotX + self->slotY * 5);
        if (self->mode == 0) {
            msg = slot == GODREEL_NO_SLOT ? 0x2000 : slot + 0x2085;
            self->ent[GODREEL_ENT_NAME_A]->msg = msg;
            self->ent[GODREEL_ENT_NAME_B]->msg = msg;
        } else if (self->mode == 1) {
            if (slot != 0 && self->row + self->top < slot) {
                self->ent[GODREEL_ENT_NAME_A]->msg = D_003BD938[self->list[self->row + self->top]] + 0x2085;
                self->ent[GODREEL_ENT_NAME_B]->msg = D_003BD938[self->list[self->row + self->top]] + 0x2085;
            } else {
                self->ent[GODREEL_ENT_NAME_A]->msg = 0x2000;
                self->ent[GODREEL_ENT_NAME_B]->msg = 0x2000;
            }
        }
    } else {
        self->ent[GODREEL_ENT_NAME_A]->msg = 0x2000;
        self->ent[GODREEL_ENT_NAME_B]->msg = 0x2000;
    }
    cIDBase_move(&self->base);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00161D08);
#endif
