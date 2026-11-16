/* include/godhand/Poker.h - the casino poker table.
 *
 * Poker is one object of about 0x3040 bytes. Its layout is the same idea as
 * BlackJack (see BlackJack.h): a cIDBase display at 0x10 with 77
 * CustomIDWork elements from 0x60, the menu panel, then the card deck of
 * 52 objects with one flag word each, a hand of 5 card slots, the state
 * machine fields and the bet. Offsets are exact; unnamed fields stay as
 * unkNNN padding.
 */
#ifndef GODHAND_POKER_H
#define GODHAND_POKER_H

#include "godhand/BlackJack.h"   /* BlackJackCard, BlackJackCardObj, BlackJackVtEnt */
#include "godhand/PanelObj.h"

#define POKER_ELEM_NUM   77     /* display elements; SetCustomIDDispOneOrAll_1DD258 takes 77 for all of them */
#define POKER_DECK_NUM   52
#define POKER_HAND_NUM   5
#define POKER_SUIT_NUM   4
#define POKER_RANK_NUM   13
#define POKER_CARD_NONE  0x34
#define POKER_CARD_RESET 0x9    /* BlackJackCard.flags of every card after a deck reset */

typedef struct Poker {
    int unk0000;                        /* 0x0000 cleared by func_001DD068 */
    char unk0004[0x10 - 4];
    cIDBaseObj id;                      /* 0x0010 the elements' display */
    char unk0058[0x60 - 0x10 - sizeof(cIDBaseObj)];
    CustomIDWork elem[POKER_ELEM_NUM];  /* 0x0060 */
    char unk25AC[0x25B0 - 0x25AC];
    PanelObj ui;                        /* 0x25B0 */
    char unk2E4C[0x2E50 - 0x2E4C];
    int unk2E50;                        /* 0x2E50 cleared by func_001DF858 */
    char unk2E54[0x2E60 - 0x2E54];
    int level;                          /* 0x2E60 table level, 0..3 */
    BlackJackCard deck[POKER_DECK_NUM]; /* 0x2E64 */
    BlackJackCard *hand[POKER_HAND_NUM]; /* 0x3004 */
    char node[8];                       /* 0x3018 display node, set up by Obj0000_Init_Fields_00_04 */
    int flags;                          /* 0x3020 */
    unsigned char state;                /* 0x3024 */
    unsigned char phase;                /* 0x3025 step inside the state */
    char unk3026[2];
    int timer;                          /* 0x3028 frames left in the current step */
    int unk302C;                        /* 0x302C */
    int betMax;                         /* 0x3030 top bet for this level */
    int bet;                            /* 0x3034 */
    int payout;                         /* 0x3038 */
    int unk303C;                        /* 0x303C */
    int choice;                         /* 0x3040 0 or 1 on the two-choice panel */
    unsigned char cursorOn;             /* 0x3044 1 while the choice is 0 */
    unsigned char unk3045;              /* 0x3045 cleared when the panels slide in */
    char unk3046[2];
    int unk3048;                        /* 0x3048 */
    int unk304C;                        /* 0x304C */
    char unk3050;                       /* 0x3050 */
    char unk3051;
    short cardId[POKER_HAND_NUM];       /* 0x3052 card ids, POKER_CARD_NONE = empty slot */
} Poker;                                /* 0x305C */

typedef char Poker_ui_check[(int)&((Poker *)0)->ui == 0x25B0 ? 1 : -1];


/* Sorted rank patterns of the nine non-royal straights (A-5 .. 9-K). */
typedef struct PokerStraightTbl {
    int rank[9][POKER_HAND_NUM];
} PokerStraightTbl;                     /* 0xB4 */

extern PokerStraightTbl D_0042B418;

/* Sorted rank patterns of all ten straights (A-5 .. 10-A). */
typedef struct PokerStraightTbl10 {
    int rank[10][POKER_HAND_NUM];
} PokerStraightTbl10;                   /* 0xC8 */

extern PokerStraightTbl10 D_0042B4D0;

/* Card positions, set up by func_001DCEF0: the origin, the deck, the five hand slots and the two-card row. */
extern cVec D_00568150;
extern cVec D_00568160;
extern cVec D_00568170[POKER_HAND_NUM];
extern cVec D_005681C0[2];

void Poker_resetDeck(Poker *self);
int Casino_randRange(void *self, int lo, int hi);

/* The hand as the hand-ranking helpers (0x1DC980..) see it, with the slot flags as an int. */
#define POKER_HAND_F_MARK   0x4         /* PokerHandSlot.flags: card belongs to the scored group */

typedef struct PokerHandCard {
    char unk000[0x604];
    int rank;                           /* 0x604 as BlackJackCardObj.rank */
} PokerHandCard;

typedef struct PokerHandSlot {
    PokerHandCard *card;                /* 0x00 */
    int flags;                          /* 0x04 */
} PokerHandSlot;

typedef struct PokerHandView {
    char unk0000[0x3004];
    PokerHandSlot *slot[POKER_HAND_NUM]; /* 0x3004 Poker.hand */
} PokerHandView;

/* Release the table's display ID and its ID screen, then clear the host's words at 0x90 and 0x94. */
void Poker_releaseIds(Poker *self);
/* Load the table's ID data file (set 0x12) from disc, then set up the ID screen and the panel. */
void IdScreen_loadIdData(Poker *self);
/* Move the display and the panel. */
void PokerId_Move(Poker *self);
/* Draw the panel and the display, then the table's sprites. */
void PokerId__Trans(Poker *self);
/* Show the default elements and the payout of each hand with no bet. */
void Poker_SetDefaultDisp(Poker *self);
/* Start a new round: clear the bet and payout, reset the deck and the display. */
void func_001D7450(Poker *self);

/* The methods on the display at the start of the table. */
/* Clear word 0, construct the ID base and the 77 elements; returns self. */
Poker *func_001DD068(Poker *self);
/* Construct the display and the panel, clear word 0x2E50; returns self. */
Poker *func_001DF858(Poker *self);
/* Set up the ID base and the 77 elements, hide element 0, zero elements 0x12 and 0x10. */
void func_001DD0D8(Poker *self);
/* Release, move or draw the ID base (func_001DD1A0 runs the elements first). */
void func_001DD180(Poker *self);
void func_001DD1A0(Poker *self);
void func_001DD1F8(Poker *self);
/* Set element 0x12's (CustomIDWork_SetNumber_1DD218) or element 0x10's (func_001DD238) number. */
void CustomIDWork_SetNumber_1DD218(Poker *self, int a1);
void func_001DD238(Poker *self, int number);
/* Show (a2 set) or hide element a1; a1 POKER_ELEM_NUM means every element but 0. */
void SetCustomIDDispOneOrAll_1DD258(Poker *self, int a1, int a2);
/* Hide every element, then show the default set. */
void func_001DD340(Poker *self);
/* Show or hide elements 0x25..0x2C. */
void func_001DD5A0(Poker *self, int a1);
/* Set the number of the element table D_0042B5B0 maps slot a1 (0..7) to. */
void SetCustomIDNumberIndexed_1DD648(Poker *self, unsigned int a1, int a2);
/* Set the score element's number and shift it left by its digit count. */
void CustomIDOwner_setScoreNumber(Poker *self, int number);
/* Switch three entry groups for menu state a1. */
void func_001DD770(Poker *self, unsigned char a1);
void func_001DD840(Poker *self, unsigned char a1);
void func_001DD910(Poker *self, unsigned char a1);
void func_001DD9E0(Poker *self, unsigned char a1);
/* Show or hide the element D_0042B5D0 maps slot a1 (0..4) to. */
void func_001DDAB0(Poker *self, unsigned char a1, int a2);
/* Switch the two elements D_0042B600 gives slot a1 (0..4) for state a2. */
void func_001DDDB0(Poker *self, unsigned char a1, unsigned char a2);
/* Place the two card-kind elements (0x2D, 0x2E) for kind and show or hide them. */
void CustomIDOwner_placeCardKind(Poker *self, unsigned char kind, int on);
/* Start or stop the sideways wobble of element 0x2D. */
void func_001DE050(Poker *self, int enabled);
/* Slide element 3 (func_001DE088), 6, 9 or 0xC (func_001DE340) in or out for mode 0..3. */
void func_001DE088(Poker *self, unsigned char mode);
void func_001DE170(Poker *self, unsigned char mode);
void func_001DE258(Poker *self, unsigned char mode);
void func_001DE340(Poker *self, unsigned char mode);
/* Slide element 1 vertically for state sel and show or hide entry 1. */
void CustomIDOwner_setSlideState(Poker *self, unsigned char sel);
/* Slide element 0x11 vertically for mode 0..3. */
void PanelWork_setModeB(Poker *self, unsigned char mode);
/* Slide element 0x3E for state mode of panel sel. */
void func_001DE5F8(Poker *self, unsigned char sel, unsigned char mode);
/* Slide element 0x13 in or out for mode 0..3. */
void Panel_slide(Poker *self, unsigned char mode);
/* Highlight the element D_0042B698 maps sel (0..7) to and move the marker element 0x1C to it. */
void func_001DE858(Poker *self, unsigned char sel);
/* Start or reset the scale pulse of the element D_0042B5D0 maps slot to. */
void CustomIDWork_pulseSlot(Poker *self, unsigned char slot, int on);
/* Set the offset of the element D_0042B5D0 maps slot a1 (0..4) to. */
void func_001DEBF0(Poker *self, unsigned char a1, int a2, int a3);
/* Set the display's draw mode (cIDBaseObj.mode). */
void SetField_56_1DEBE8(Poker *self, int mode);

#endif
