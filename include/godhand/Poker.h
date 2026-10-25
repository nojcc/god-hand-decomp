/* include/godhand/Poker.h - the casino poker table.
 *
 * Poker is one object of about 0x3040 bytes. Its layout is the same idea as
 * BlackJack (see BlackJack.h): display entries first, then the card deck of
 * 52 objects with one flag word each, a hand of 5 card slots, the state
 * machine fields and the bet. Offsets are exact; unnamed fields stay as
 * unkNNN padding.
 */
#ifndef GODHAND_POKER_H
#define GODHAND_POKER_H

#include "godhand/BlackJack.h"   /* BlackJackCard, BlackJackCardObj, BlackJackVtEnt */

#define POKER_DECK_NUM   52
#define POKER_HAND_NUM   5
#define POKER_SUIT_NUM   4
#define POKER_RANK_NUM   13
#define POKER_CARD_NONE  0x34
#define POKER_CARD_RESET 0x9    /* BlackJackCard.flags of every card after a deck reset */

typedef struct Poker {
    char unk0000[0x2E60];
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

/* The table's UI record (a PanelObj) sits at 0x25B0 and is not typed in Poker yet. */
#define POKER_UI(self)  ((char *)(self) + 0x25B0)

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

/* Where a dealt card starts (the deck) and where each hand slot puts it, x and y used. */
extern float D_00568160[4];
extern float D_00568170[POKER_HAND_NUM][4];
/* The two card slots of the double-up game. */
extern float D_005681C0[2][4];

void Poker_resetDeck(Poker *self);
void func_001DBE18(Poker *self, BlackJackCard **slot);
void func_001D6EC8(BlackJackCard *card, int a1);
void func_001D6DD0(BlackJackCard *card, int a1);
void SetField_56_1DEBE8(void *obj, int v);
int Casino_randRange(void *self, int lo, int hi);

/* The table UI at POKER_UI. */
void func_001DEE40(void *ui, int n);
void func_001DF528(char *ui, unsigned char idx, unsigned short mode);
void func_001DF7D0(char *ui, int alt);
void func_001DF820(char *ui, int enabled);
void UiRecord_setDispSubs6to10(void *ui, int on);

#define POKER_DEAL_FRAMES 10            /* frames a card takes from the deck to its slot */

/* Puts a card object at pos through its virtual setter. */
static __inline__ void Poker_placeCard(BlackJackCardObj *obj, float *pos)
{
    obj->vtbl[14].pfn((char *)obj + obj->vtbl[14].delta, pos);
}

/* Moves hand card i one frame along its way from the deck to slot i. */
static __inline__ void Poker_moveCard(Poker *self, int i)
{
    float t = (POKER_DEAL_FRAMES - (float)self->unk302C) / POKER_DEAL_FRAMES;
    float x = t * (D_00568170[i][0] - D_00568160[0]) + D_00568160[0];
    float y = t * (D_00568170[i][1] - D_00568160[1]) + D_00568160[1];

    self->hand[i]->obj->pos[0] = x;
    self->hand[i]->obj->pos[1] = y;
}

/* Counts a step timer down one frame; 1 once it has run out. */
static __inline__ unsigned char Poker_tick(int *timer)
{
    if (*timer == 0) {
        return 1;
    }
    *timer = *timer - 1;
    return 0;
}

#endif
