/* sn-2.95.3-136 */
#include "include_asm.h"
/* NON_MATCHING: the record lookup keeps the found record in v0 (retail copies it to s0), and the slot's row is set through an idx == 0 branch retail has. Needs extern_jtbl D_0041FF00 and as: sn. */
#include "godhand/gameWork.h"
#include "godhand/cSnd.h"
#include "godhand/cCoreSave.h"
#include "godhand/cRecordIndex.h"
#include "godhand/cIDBase.h"
#include "godhand/cIDMenuPanel.h"
#include "godhand/menuKey.h"

#ifdef NON_MATCHING

#define COMBOEDIT_ROWS      8           /* technique rows shown at once */
#define COMBOEDIT_ROW_ENT   9           /* ent[] index of the first row */
#define COMBOEDIT_CAT_ENT   21          /* ent[] index of the category title */
#define COMBOEDIT_CAT_NUM   11
#define COMBOEDIT_KIND_SET  0xD         /* entry kind of a technique already in a combo */
#define MENU_KEY_SLOTS      0x40000000L /* trg bit: set the combo slot count to 4 or 5 */

/* The combo editor panel: picks a combo slot (cursor, or a special-move set
 * when toggle is set), then a technique for it from the record index list. */
typedef struct cComboEdit {
    cIDPanelHead head;                  /* 0x00 */
    char unk64[0x1C0 - 0x64];
    cIDBaseEnt *ent[22];                /* 0x1C0 */
    char unk218[0x25C - 0x218];
    signed char cursor;                 /* 0x25C combo slot, -1 = the slot count entry */
    signed char slotNum;                /* 0x25D */
    short row;                          /* 0x25E list row on the page */
    short top;                          /* 0x260 first record of the page */
    signed char category;               /* 0x262 */
    char unk263[0x284 - 0x263];
    signed char toggle;                 /* 0x284 1: edit the special-move sets */
} cComboEdit;

/* Category title scale per language, as 0016ee10.c reads it. */
typedef struct cComboEditScl {
    float f[10];
} cComboEditScl;

extern cComboEditScl D_0041F250[];

extern int GetTypeDefaultValue_16EDE0(int a0);
extern void cRecordIndex_clearSkillIfLevel1(cRecordIndex *self, int i);

/* Records the list shows. */
static __inline__ unsigned int ComboEdit_recNum(void)
{
    return D_005FEC58.limit;
}

/* List position of technique id: the first record that is missing or has
 * that id, or the record count. */
static __inline__ int ComboEdit_findRec(int id)
{
    cRecordIndexEntry *r;
    int idx;

    for (idx = 0; idx < ComboEdit_recNum(); idx++) {
        r = func_002C9008(&D_005FEC58, idx);
        if (r == 0 || id == r->id) {
            break;
        }
    }
    return idx;
}

/* Input step of the combo editor. State 0 picks the slot, state 1 the
 * technique from the list (pages of 8, 11 categories); CLOSE leaves. */
__attribute__((section(".text.func_0016DF38")))
void func_0016DF38(cComboEdit *self)
{
    cRecordIndexEntry *r;
    unsigned int i;
    int idx;
    int id;
    int found;

    switch (self->head.state) {
    case 0:
        if (D_007474A0.rep & MENU_KEY_DOWN) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->cursor++;
        } else if (D_007474A0.rep & MENU_KEY_UP) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->cursor--;
        } else if (D_007474A0.trg & MENU_KEY_LEFTRIGHT) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->toggle ^= 1;
        }
        if (self->toggle == 0) {
            signed char cursor = self->cursor;

            if (cursor < -1) {
                if (cCoreSave_getComboMax(&D_00569B70, 0) < self->slotNum) {
                    self->cursor = cCoreSave_getComboMax(&D_00569B70, 0);
                } else {
                    self->cursor = self->slotNum - 1;
                }
            } else if (self->slotNum - 1 < cursor || cCoreSave_getComboMax(&D_00569B70, 0) < cursor) {
                self->cursor = -1;
            }
        } else if (self->cursor < -1) {
            self->cursor = 4;
        } else if (self->cursor >= 5) {
            self->cursor = -1;
        }
        if ((D_007474A0.trg & MENU_KEY_SLOTS) && self->cursor >= 4 && self->toggle == 0) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
            switch (self->cursor) {
            case 4:
                cCoreSave_setComboMax(&D_00569B70, 0, 4);
                break;
            case 5:
                if (cCoreSave_getComboMax(&D_00569B70, 0) != 4) {
                    cCoreSave_setComboMax(&D_00569B70, 0, 5);
                }
                break;
            }
        }
        if (D_007474A0.trg & MENU_KEY_OK) {
            if (self->cursor != -1) {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
                if (self->toggle == 1) {
                    id = cCoreSave_getCombo(&D_00569B70, self->cursor + 1, 0);
                } else {
                    id = cCoreSave_getCombo(&D_00569B70, 0, self->cursor);
                }
                idx = ComboEdit_findRec(id);
                if (idx < ComboEdit_recNum()) {
                    if (idx >= COMBOEDIT_ROWS) {
                        self->top = idx - (COMBOEDIT_ROWS - 1);
                        self->row = idx - self->top;
                    } else {
                        if (idx != 0) {
                            self->row = idx;
                        } else {
                            self->row = 0;
                        }
                        self->top = 0;
                    }
                } else {
                    self->row = 0;
                    self->top = 0;
                }
                self->head.state = 1;
            } else {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
                self->head.result = 10;
                self->head.state = 2;
            }
        } else if (D_007474A0.trg & MENU_KEY_BACK) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
            self->head.result = 10;
            self->head.state = 2;
        }
        break;
    case 1:
        if (D_007474A0.trg & (MENU_KEY_PAGE_PREV | MENU_KEY_PAGE_NEXT)) {
            if (D_007474A0.trg & MENU_KEY_PAGE_NEXT) {
                self->category++;
            } else {
                self->category--;
            }
            self->category = self->category < 0 ? COMBOEDIT_CAT_NUM - 1 : self->category < COMBOEDIT_CAT_NUM ? self->category : 0;
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            switch (self->category) {
            case 0:
                func_002C90A0(&D_005FEC58, 0);
                self->ent[COMBOEDIT_CAT_ENT]->msg = 0x30F9;
                self->ent[COMBOEDIT_CAT_ENT]->sclX = self->ent[COMBOEDIT_CAT_ENT]->src->sclX;
                break;
            case 1:
                func_002C90A0(&D_005FEC58, 5);
                self->ent[COMBOEDIT_CAT_ENT]->msg = 0x30FA;
                self->ent[COMBOEDIT_CAT_ENT]->sclX = self->ent[COMBOEDIT_CAT_ENT]->src->sclX;
                break;
            case 2:
                func_002C90A0(&D_005FEC58, 6);
                self->ent[COMBOEDIT_CAT_ENT]->msg = 0x30FB;
                self->ent[COMBOEDIT_CAT_ENT]->sclX = self->ent[COMBOEDIT_CAT_ENT]->src->sclX;
                break;
            case 3:
                func_002C90A0(&D_005FEC58, 7);
                self->ent[COMBOEDIT_CAT_ENT]->msg = 0x30C6;
                self->ent[COMBOEDIT_CAT_ENT]->sclX = D_0041F250[D_007474A0.language].f[0];
                break;
            case 4:
                func_002C90A0(&D_005FEC58, 8);
                self->ent[COMBOEDIT_CAT_ENT]->msg = 0x30C7;
                self->ent[COMBOEDIT_CAT_ENT]->sclX = D_0041F250[D_007474A0.language].f[1];
                break;
            case 5:
                func_002C90A0(&D_005FEC58, 9);
                self->ent[COMBOEDIT_CAT_ENT]->msg = 0x30C8;
                self->ent[COMBOEDIT_CAT_ENT]->sclX = D_0041F250[D_007474A0.language].f[2];
                break;
            case 6:
                func_002C90A0(&D_005FEC58, 10);
                self->ent[COMBOEDIT_CAT_ENT]->msg = 0x30C9;
                self->ent[COMBOEDIT_CAT_ENT]->sclX = D_0041F250[D_007474A0.language].f[3];
                break;
            case 7:
                func_002C90A0(&D_005FEC58, 13);
                self->ent[COMBOEDIT_CAT_ENT]->msg = 0x30CC;
                self->ent[COMBOEDIT_CAT_ENT]->sclX = D_0041F250[D_007474A0.language].f[6];
                break;
            case 8:
                func_002C90A0(&D_005FEC58, 14);
                self->ent[COMBOEDIT_CAT_ENT]->msg = 0x30CD;
                self->ent[COMBOEDIT_CAT_ENT]->sclX = D_0041F250[D_007474A0.language].f[7];
                break;
            case 9:
                func_002C90A0(&D_005FEC58, 15);
                self->ent[COMBOEDIT_CAT_ENT]->msg = 0x30CE;
                self->ent[COMBOEDIT_CAT_ENT]->sclX = D_0041F250[D_007474A0.language].f[8];
                break;
            case 10:
                func_002C90A0(&D_005FEC58, 16);
                self->ent[COMBOEDIT_CAT_ENT]->msg = 0x30CF;
                self->ent[COMBOEDIT_CAT_ENT]->sclX = D_0041F250[D_007474A0.language].f[9];
                break;
            }
            func_002C9950(&D_005FEC58);
            self->row = 0;
            self->top = 0;
        }
        if (D_007474A0.rep & MENU_KEY_DOWN) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->row++;
            if (self->row >= COMBOEDIT_ROWS || self->row >= ComboEdit_recNum()) {
                self->row = COMBOEDIT_ROWS - 1;
                self->top++;
                if (ComboEdit_recNum() < self->top + COMBOEDIT_ROWS) {
                    self->row = 0;
                    self->top = 0;
                }
            }
        }
        if (D_007474A0.rep & MENU_KEY_UP) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->row--;
            if (self->row < 0) {
                self->row = 0;
                self->top--;
                if (self->top < 0) {
                    self->row = COMBOEDIT_ROWS - 1;
                    self->top = ComboEdit_recNum() - COMBOEDIT_ROWS;
                    if (self->row >= ComboEdit_recNum()) {
                        self->row = ComboEdit_recNum() - 1;
                    }
                    if (self->top < 0) {
                        self->top = 0;
                    }
                    if (self->row < 0) {
                        self->row = 0;
                    }
                }
            }
        }
        if (D_007474A0.rep & MENU_KEY_RIGHT) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->top += COMBOEDIT_ROWS;
            if (ComboEdit_recNum() < self->top + COMBOEDIT_ROWS && self->row != ComboEdit_recNum() - 1
                && self->row != COMBOEDIT_ROWS - 1 && self->top - COMBOEDIT_ROWS != ComboEdit_recNum()) {
                self->row = COMBOEDIT_ROWS - 1;
                self->top = ComboEdit_recNum() - COMBOEDIT_ROWS;
                if (self->row >= ComboEdit_recNum()) {
                    self->row = ComboEdit_recNum() - 1;
                } else if (ComboEdit_recNum() <= COMBOEDIT_ROWS) {
                    self->row = 0;
                }
                if (self->top < 0) {
                    self->top = 0;
                }
            } else if (self->top + COMBOEDIT_ROWS >= ComboEdit_recNum()) {
                self->row = 0;
                self->top = 0;
            }
        }
        if (D_007474A0.rep & MENU_KEY_LEFT) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            self->top -= COMBOEDIT_ROWS;
            if (self->top < 0) {
                if (self->row != 0) {
                    self->row = 0;
                    self->top = 0;
                } else {
                    self->row = COMBOEDIT_ROWS - 1;
                    self->top = ComboEdit_recNum() - COMBOEDIT_ROWS;
                    if (self->row >= ComboEdit_recNum()) {
                        self->row = ComboEdit_recNum() - 1;
                    }
                    if (self->top < 0) {
                        self->top = 0;
                    }
                    if (self->row < 0) {
                        self->row = 0;
                    }
                }
            }
        }
        if (D_007474A0.trg & MENU_KEY_OK) {
            if (self->toggle == 0 && cCoreSave_getComboMax(&D_00569B70, 0) <= self->cursor
                && self->ent[self->row + COMBOEDIT_ROW_ENT]->b8B == COMBOEDIT_KIND_SET) {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
                break;
            }
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
            if (self->ent[self->row + COMBOEDIT_ROW_ENT]->b8B == COMBOEDIT_KIND_SET) {
                found = 0;
                for (i = 0; i < cCoreSave_getComboMax(&D_00569B70, 0); i++) {
                    r = func_002C9008(&D_005FEC58, self->top + self->row);
                    if (r == 0) {
                        break;
                    }
                    if (cCoreSave_getCombo(&D_00569B70, 0, i) == r->id) {
                        if (self->toggle == 0) {
                            cCoreSave_setCombo(&D_00569B70, 0, i, cCoreSave_getCombo(&D_00569B70, 0, self->cursor), 0);
                        } else {
                            cCoreSave_setCombo(&D_00569B70, 0, i, cCoreSave_getCombo(&D_00569B70, self->cursor + 1, 0), 0);
                        }
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    for (i = 1; i < 6; i++) {
                        r = func_002C9008(&D_005FEC58, self->top + self->row);
                        if (r == 0) {
                            break;
                        }
                        if (cCoreSave_getCombo(&D_00569B70, i, 0) == r->id) {
                            if (self->toggle == 0) {
                                cCoreSave_setCombo(&D_00569B70, i, 0, cCoreSave_getCombo(&D_00569B70, 0, self->cursor), 0);
                            } else {
                                cCoreSave_setCombo(&D_00569B70, i, 0, cCoreSave_getCombo(&D_00569B70, self->cursor + 1, 0), 0);
                            }
                            break;
                        }
                    }
                }
            }
            if (self->toggle == 0) {
                r = func_002C9008(&D_005FEC58, self->top + self->row);
                if (r == 0) {
                    break;
                }
                if (cCoreSave_getComboMax(&D_00569B70, 0) <= self->cursor) {
                    cCoreSave_setComboMax(&D_00569B70, 0, self->cursor + 1);
                }
                cCoreSave_setCombo(&D_00569B70, 0, self->cursor, r->id, 0);
                self->cursor++;
                if (self->slotNum - 1 < self->cursor) {
                    self->cursor = 0;
                    self->head.state = 0;
                }
            } else {
                r = func_002C9008(&D_005FEC58, self->top + self->row);
                if (r == 0) {
                    break;
                }
                cCoreSave_setCombo(&D_00569B70, self->cursor + 1, 0, r->id, 0);
                self->head.state = 0;
            }
            cRecordIndex_clearSkillIfLevel1(&D_005FEC58, self->top + self->row);
        }
        if (D_007474A0.trg & MENU_KEY_BACK) {
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
            self->head.state = 0;
        }
        break;
    }
    if (D_007474A0.trg & MENU_KEY_CLOSE) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
        GetTypeDefaultValue_16EDE0((int)self);
        self->head.state = 2;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0016DF38);
#endif
