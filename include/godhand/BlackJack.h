/* include/godhand/BlackJack.h - the casino blackjack table.
 *
 * BlackJack is one object of 0x1836 bytes. Its first 0x1630 bytes
 * are the cIDBase display at 0x10 and its 45 CustomIDWork elements from 0x60
 * (the BlackJackId methods work on them). From 0x1630 on come the game fields named here: the card deck
 * (52 objects, each with a flag word), two hands of 5 card slots, a small
 * state machine (state, phase) and the bet.
 *
 * Offsets are exact. A field nobody has named yet stays as unkNNN padding.
 * Field names are ours, taken from the methods that read and write them.
 */
#ifndef GODHAND_BLACKJACK_H
#define GODHAND_BLACKJACK_H

#include "godhand/cVecType.h"
#include "godhand/CustomIDWork.h"

#define BLACKJACK_ELEM_NUM   45     /* display elements; SetFlagOnEntries7C_1D51B8 takes 45 for all of them */
#define BLACKJACK_DECK_NUM   52
#define BLACKJACK_HAND_NUM   5      /* card slots per hand */
#define BLACKJACK_SUIT_NUM   4
#define BLACKJACK_RANK_NUM   13
#define BLACKJACK_CARD_FACE_DOWN 0x2   /* BlackJackCardObj.flags */
#define BLACKJACK_CARD_NONE      0x34  /* cardIdA/B entry for an empty slot */

/* flags word at +0x1800 */
#define BLACKJACK_FLAG_SETUP     0x1    /* phase 0 ran once */
#define BLACKJACK_FLAG_BET_STEP  0x8    /* bet was changed this frame */

/* states at +0x1804 */
enum {
    BLACKJACK_STATE_BET = 1,
    BLACKJACK_STATE_DEAL = 2
};

/* One g++ 2.x virtual table entry: `this` adjust, then the function. */
typedef struct BlackJackVtEnt {
    short delta;
    short index;
    void (*pfn)(void *self, float *pos);
} BlackJackVtEnt;

/* The cOmTrump object behind one card. Only the fields BlackJack touches. */
typedef struct BlackJackCardObj {
    char unk000[0xF0];
    float *pos;                         /* 0x0F0 -> x of the card position */
    char unk0F4[0xC];
    cVec rot;                           /* 0x100 x pitch, y heading: 0 face up, pi face down */
    float scale[3];                     /* 0x110 */
    char unk11C[0xF8];
    BlackJackVtEnt *vtbl;               /* 0x214 g++ 2.x vtable pointer */
    char unk218[0x38];
    unsigned int flags;                 /* 0x250 bit 1 = card is face down */
    char unk254[0x600 - 0x254];
    int suit;                           /* 0x600 0..3 */
    int rank;                           /* 0x604 0 = ace .. 12 = king */
} BlackJackCardObj;

typedef struct BlackJackCard {
    BlackJackCardObj *obj;              /* 0x0 cOmTrump object */
    int flags;                          /* 0x4 bit 0 = card is out of the deck, bit 1 = card is on screen,
                                           bit 3 = face up, bit 4 = turning face up */
} BlackJackCard;                        /* 0x8 */

typedef struct BlackJack {
    int unk0000;                        /* 0x0000 cleared by func_001D4D80 */
    char unk0004[0x10 - 4];
    cIDBaseObj id;                      /* 0x0010 the elements' display */
    char unk0058[0x60 - 0x10 - sizeof(cIDBaseObj)];
    CustomIDWork elem[BLACKJACK_ELEM_NUM]; /* 0x0060 */
    char unk162C[0x1630 - 0x162C];
    int level;                          /* 0x1630 table level, 0..3 */
    BlackJackCard deck[BLACKJACK_DECK_NUM]; /* 0x1634 */
    BlackJackCard *handA[BLACKJACK_HAND_NUM];  /* 0x17D4 */
    BlackJackCard *handB[BLACKJACK_HAND_NUM];  /* 0x17E8 */
    unsigned short dealSlot;            /* 0x17FC hand slot being dealt */
    unsigned short dealSlotB;           /* 0x17FE hand B slot being dealt */
    int flags;                          /* 0x1800 BLACKJACK_FLAG_* */
    int state;                          /* 0x1804 */
    int phase;                          /* 0x1808 step inside the state */
    int timer;                          /* 0x180C frames left in the current step */
    int betMax;                         /* 0x1810 top bet for this level */
    int bet;                            /* 0x1814 */
    int payout;                         /* 0x1818 winnings being paid out, in gold */
    char *camera;                       /* 0x181C */
    char unk1820[2];
    short cardIdA[BLACKJACK_HAND_NUM];  /* 0x1822 card ids dealt to hand A */
    short cardIdB[BLACKJACK_HAND_NUM];  /* 0x182C card ids dealt to hand B */
} BlackJack;                            /* 0x1836 */

typedef char BlackJack_level_check[(int)&((BlackJack *)0)->level == 0x1630 ? 1 : -1];

/* Turns the card face up (heading 0, bit 3), or with animate set starts the turn (bit 4) func_001D6E20 steps; nothing while either bit is set. */
void func_001D6DD0(BlackJackCard *card, int animate);
/* Turns a face-up card face down (heading pi, clears bit 3), or with animate set marks it turning (bit 4); nothing unless bit 3 is set and bit 4 clear. */
void func_001D6EC8(BlackJackCard *card, int animate);
/* Step a turning card: face up (func_001D0CE8, func_001D6E20) or face down (func_001D0DF8, func_001D6F30). */
void func_001D0CE8(BlackJackCard *card);
void func_001D6E20(BlackJackCard *card);
void func_001D0DF8(BlackJackCard *card);
void func_001D6F30(BlackJackCard *card);
/* Release the table's ID base and clear the host's words at 0x98 and 0x9C. */
void func_001D4F48(BlackJack *self);

/* BlackJackId: the methods on the display at the start of the table. */
/* Clear word 0, construct the ID base and the 45 elements; returns self. */
BlackJack *func_001D4D80(BlackJack *self);
/* Load the blackjack ID file, set up the 45 elements and the default display. */
void func_001D4DF0(BlackJack *self);
/* Run the 45 elements, then move the ID base. */
void BlackJackId_Move(BlackJack *self);
/* Draw the table background, then the ID base. */
void BlackJackId__Trans(BlackJack *self);
/* Show (flag set) or hide element idx; idx BLACKJACK_ELEM_NUM means every element but 0. */
void SetFlagOnEntries7C_1D51B8(BlackJack *self, int idx, int flag);
/* Hide every element, then show the default set. */
void BlackJackId_SetDefaultDisp(BlackJack *self);
/* Set element 2's number. */
void CustomIDWork_SetNumber_1D5760(BlackJack *self, int number);
/* Show or hide the bet menu's three entry groups (0xB, 0xC, 0x23) for menu state mode. */
void func_001D5360(BlackJack *self, unsigned char mode);
/* The same for entries 9, 0xA and 0x24. */
void func_001D5430(BlackJack *self, unsigned char mode);
/* The same for entries 0xD, 0xE and 0xF. */
void func_001D5500(BlackJack *self, unsigned char mode);
/* The same for entries 0x10, 0x11 and 0x12. */
void func_001D5690(BlackJack *self, unsigned char mode);
/* Set entry 0x21 to on and show entry 0x22. */
void SetFlagEntries21And22_1D55D0(BlackJack *self, int on);
/* Set entry 7 to on and show entry 8. */
void SetFlagEntries7And8_1D5610(BlackJack *self, int on);
/* Set entry 5 to on and show entry 6. */
void SetFlagEntries5And6_1D5650(BlackJack *self, int on);
/* Set element 4's number. */
void func_001D5780(BlackJack *self, int number);
/* Slide element 0xB (func_001D5C38) or 9 (func_001D5D20) in or out for mode 0..3. */
void func_001D5C38(BlackJack *self, unsigned short mode);
void func_001D5D20(BlackJack *self, unsigned short mode);
/* Slide the panel element 0xD in or out for mode 0..3 and switch entries 0xD..0xF. */
void IdPanel_setSlideState(BlackJack *self, unsigned short mode);
/* Slide the panel element 0x21 vertically for mode 0..3. */
void PanelWork_setMode(BlackJack *self, int mode);
/* Slide the panel element 7 in or out for mode 0..3. */
void PanelHost_slideSidePanel(BlackJack *self, unsigned short mode);
/* Slide the panel element 5 in or out for mode 0..3. */
void BlackJack_slidePanel(BlackJack *self, unsigned short mode);
/* Slide element 0x10 vertically for mode 0..4 and switch entries 0x10..0x12. */
void func_001D61C0(BlackJack *self, int mode);
/* Show or hide entries 0x1C and 0x1D (func_001D69A0), 0x1A and 0x1B (func_001D69E8),
 * 0x20 (func_001D6BC0), 0x29 and 0x2A (func_001D6BE0), 0x2B and 0x2C (func_001D6C28),
 * 0x1F (func_001D6C70), 0x25 and 0x26 (func_001D6C90) or 0x27 and 0x28 (func_001D6CD8). */
void func_001D69A0(BlackJack *self, int on);
void func_001D69E8(BlackJack *self, int on);
void func_001D6BC0(BlackJack *self, int on);
void func_001D6C28(BlackJack *self, int on);
void func_001D6C70(BlackJack *self, int on);
void func_001D6C90(BlackJack *self, int on);
void func_001D6CD8(BlackJack *self, int on);
void func_001D6BE0(BlackJack *self, int on);
/* Set element 0x1B's (func_001D6A30) or element 0x1D's (func_001D6A50) number. */
void func_001D6A30(BlackJack *self, int number);
void func_001D6A50(BlackJack *self, int number);

#endif
