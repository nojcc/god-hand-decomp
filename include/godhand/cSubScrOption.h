/* include/godhand/cSubScrOption.h - the options screen of the pause menu
 * (retail class 13cSubScrOption, id resource "idsubscroption").
 *
 * An id display object (cIDObj head) with a second display (sub) that row 0
 * opens over the panel. obj.state is the panel mode: 0 picks a row, 1 fades
 * over to the second display, 2 shows it, 3 fades back, 4 asks yes/no.
 * The rows: 0 the second display, 1 a save flag (cCoreSave state bit 0),
 * 2 the sound output mode, 3 pad vibration, 4 and 7 leave with a result,
 * 5 asks the question, 6 puts the settings back to their defaults.
 *
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact.
 */
#ifndef GODHAND_CSUBSCROPTION_H
#define GODHAND_CSUBSCROPTION_H

#include "godhand/cIDObj.h"

#define SUBSCR_OPTION_RES       8       /* manager slot and resource of the panel */
#define SUBSCR_OPTION_ENT_NUM   0x18    /* entries of the main display */
#define SUBSCR_OPTION_ENT_ASK   18      /* the yes/no question */

typedef struct cSubScrOption {
    cIDObj obj;                                     /* 0x000 */
    char unk74[0x80 - sizeof(cIDObj)];
    cIDBaseEnt *ent[SUBSCR_OPTION_ENT_NUM];         /* 0x080 */
    cIDBaseObj sub;                                 /* 0x0E0 second display */
    char unk128[0x130 - 0x128];
    signed char row;                                /* 0x130 row under the cursor, 0..7 */
    signed char answer;                             /* 0x131 0 = yes, 1 = no */
} cSubScrOption;

typedef char cSubScrOption_sub_check[(int)&((cSubScrOption *)0)->sub == 0xE0 ? 1 : -1];
typedef char cSubScrOption_row_check[(int)&((cSubScrOption *)0)->row == 0x130 ? 1 : -1];

#define SUBSCR_OPTIONT_RES      0x1B    /* manager slot and resource of the variant */
#define SUBSCR_OPTIONT_ENT_NUM  0x10

/* The smaller variant (retail class 14cSubScrOptionT, id resource
 * "idsubscroptionT"): the same head, fewer entries, the second display at
 * 0xC0. Its teardown clears manager slot 8, cSubScrOption's, not its own. */
typedef struct cSubScrOptionT {
    cIDObj obj;                                     /* 0x000 */
    char unk74[0x80 - sizeof(cIDObj)];
    cIDBaseEnt *ent[SUBSCR_OPTIONT_ENT_NUM];        /* 0x080 */
    cIDBaseObj sub;                                 /* 0x0C0 second display */
    char unk108[0x110 - 0x108];
    signed char row;                                /* 0x110 row under the cursor */
    signed char answer;                             /* 0x111 0 = yes, 1 = no */
} cSubScrOptionT;

typedef char cSubScrOptionT_sub_check[(int)&((cSubScrOptionT *)0)->sub == 0xC0 ? 1 : -1];
typedef char cSubScrOptionT_row_check[(int)&((cSubScrOptionT *)0)->row == 0x110 ? 1 : -1];

/* Put the settings back to their defaults, as func_001672F0; self is not read. */
void func_00167EB0(cSubScrOptionT *self);
/* Hide every entry of the variant's main display. */
void SetFlagOnChildren_167EE8(cSubScrOptionT *self);

/* Step of cSubScrOption's fade to and from the second display. */
extern unsigned char D_003BD9E8;

/* Put the settings back to their defaults; self is not read. */
void func_001672F0(cSubScrOption *self);
/* Hide every entry of the main display. */
void func_00167328(cSubScrOption *self);

#endif
