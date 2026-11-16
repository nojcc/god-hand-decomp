/* include/godhand/DogRace.h - the dog-race casino game.
 *
 * DogRace runs five racing dogs. Each dog is a 0x40-byte DogRaceDog that
 * holds the spawned object, its stat record (copied from a table row) and
 * the rolled race values. The scene state machine and its UI sit behind
 * the dogs: a cIDWork at 0x210 and two sub-objects after it.
 *
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. Fields nobody has named stay as unkNN padding.
 */
#ifndef GODHAND_DOGRACE_H
#define GODHAND_DOGRACE_H

#include "godhand/cIDBase.h"
#include "godhand/CustomIDWork.h"
#include "godhand/cVecType.h"

#define DOGRACE_DOG_NUM     5
#define DOGRACE_ODDS_BASE   0x3E8   /* payout base, 0x7D0 after the game was cleared */
#define DOGRACE_ODDS_CLEAR  0x7D0

/* A dog's stat record, one row of the 0x24-byte table entry it spawns from. */
typedef struct DogRaceStats {
    int unk00;
    int grade;                  /* 0x04 below 16 it can be bumped to 30 */
    float speed;                /* 0x08 scaled by speedRate at spawn */
    float stamina;              /* 0x0C */
    float luck;                 /* 0x10 scaled by speedRate at spawn */
    float unk14;                /* 0x14 may be rolled again at spawn */
    unsigned int burstChance;   /* 0x18 percent */
    float rateMin;              /* 0x1C bounds of the speed roll */
    float rateMax;              /* 0x20 */
} DogRaceStats;                 /* 0x24 */

typedef struct DogRaceDog {
    void *obj;                  /* 0x00 spawned object, 0 if the spawn failed */
    unsigned char no;           /* 0x04 index of the dog */
    char pad05[3];
    DogRaceStats stats;         /* 0x08 */
    int raceTime;               /* 0x2C rolled finish value */
    int unk30;
    int unk34;
    int power;                  /* 0x38 sort key, strongest first */
    float speedRate;            /* 0x3C */
} DogRaceDog;                   /* 0x40 */

#define DOGRACE_UI_ELEM_NUM     6
#define DOGRACE_UI_F_INTRO      0x1     /* DogRaceUi.flags: the intro steps run */

/* The race's start panel at 0x1840: four icons the intro shows one after the other
 * (elements 0..3), the panel item (element 4) and element 5. */
typedef struct DogRaceUi {
    int flags;                          /* 0x000 */
    char unk004[0x10 - 4];
    cIDBaseObj id;                      /* 0x010 the elements' display */
    char unk058[0x60 - 0x10 - sizeof(cIDBaseObj)];
    CustomIDWork elem[DOGRACE_UI_ELEM_NUM]; /* 0x060 */
    int step;                           /* 0x348 intro step, 0..5 */
    int timer;                          /* 0x34C frames left in the intro step */
} DogRaceUi;                            /* 0x350 */

typedef char DogRaceUi_size_check[sizeof(DogRaceUi) == 0x350 ? 1 : -1];

#define DOGRACE_LIST_ELEM_NUM   0x1D

/* The race's list screen at 0x1B90. */
typedef struct DogRaceList {
    int unk000;                         /* 0x000 cleared by func_001EDE38 */
    char unk004[0x10 - 4];
    cIDBaseObj id;                      /* 0x010 the elements' display */
    char unk058[0x60 - 0x10 - sizeof(cIDBaseObj)];
    CustomIDWork elem[DOGRACE_LIST_ELEM_NUM]; /* 0x060 */
    char unkE6C[0xE7C - 0xE6C];
} DogRaceList;                          /* 0xE7C */

typedef char DogRaceList_size_check[sizeof(DogRaceList) == 0xE7C ? 1 : -1];

#define DOGRACE_RESULT_ELEM_NUM 0x2D

/* The race's result screen at 0x210. */
typedef struct DogRaceResult {
    int flags;                          /* 0x000 cleared by func_001ECA80 */
    char unk004[0x10 - 4];
    cIDBaseObj id;                      /* 0x010 the elements' display */
    char unk058[0x60 - 0x10 - sizeof(cIDBaseObj)];
    CustomIDWork elem[DOGRACE_RESULT_ELEM_NUM]; /* 0x060 */
    char unk162C[0x1630 - 0x162C];
} DogRaceResult;                        /* 0x1630 */

typedef char DogRaceResult_size_check[sizeof(DogRaceResult) == 0x1630 ? 1 : -1];

typedef struct DogRace {
    char unk00[4];
    int step;                   /* 0x004 index into the step table D_003BE528 */
    int unk08;                  /* 0x008 */
    int unk0C;                  /* 0x00C */
    char unk10[0x44];
    int unk54;                  /* 0x054 bit 0 ends the race loop */
    char unk58[4];
    DogRaceDog dog[DOGRACE_DOG_NUM];    /* 0x05C */
    int rank[DOGRACE_DOG_NUM];  /* 0x19C */
    unsigned short unk1B0;      /* 0x1B0 0xFFFF after construction */
    char unk1B2[2];
    int unk1B4;                 /* 0x1B4 */
    int unk1B8;                 /* 0x1B8 */
    int odds;                   /* 0x1BC */
    char unk1C0[4];
    int scroll[15];             /* 0x1C4 scroll layer ids, set by DogRace_Initialize */
    int unk200;                 /* 0x200 */
    char unk204[0xC];
    DogRaceResult result;       /* 0x210 */
    DogRaceUi ui1;              /* 0x1840 */
    DogRaceList ui2;            /* 0x1B90 */
    void *fileData;             /* 0x2A0C loaded data file, a heap block */
} DogRace;

/* One entry of the race's step table: `this` adjust, then the handler. */
typedef struct DogRaceStepEnt {
    short delta;
    short pad;
    void (*fn)(void *self);
} DogRaceStepEnt;

extern DogRaceStepEnt D_003BE528[];

/* Call the handler of the current step, then run the shared update func_001EC088. */
void Slot2_dispatchStep(DogRace *self);
/* Release the dogs, the three displays and the data file. */
void DogRace_Release(DogRace *self);

/* DogRaceUi methods. */
/* Clear the flags, construct the ID base and the 6 elements; returns self. */
DogRaceUi *func_001ED548(DogRaceUi *self);
/* Set up the ID base (set 0x14, entry 2) and the elements, hide the icons and the panel item. */
void InitDogRaceUiIdWorks(DogRaceUi *self);
/* Release, move (after the intro step) or draw the ID base. */
void func_001ED660(DogRaceUi *self);
void func_001ED680(DogRaceUi *self);
void func_001ED6E0(DogRaceUi *self);
/* Show (on set) or hide element id; id DOGRACE_UI_ELEM_NUM means every element. */
void func_001ED700(DogRaceUi *self, int id, int on);
/* Start the intro: set DOGRACE_UI_F_INTRO and go back to step 0. */
void Obj0000_Or_Field_0_Bit_1_Clear_Field_348_1ED7C8(DogRaceUi *self);
/* Hide the four icons, clear DOGRACE_UI_F_INTRO and the intro step. */
void Panel_hideIcons(DogRaceUi *self);
/* One frame of the intro: show the icons one after the other with a colour and scale pulse. */
void func_001ED848(DogRaceUi *self);
/* Move element 5 to the screen position of a world point, then show (on set) or hide it. */
void ScreenMarker_moveToWorldPos(DogRaceUi *self, cVec *world, int on);
/* Slide the panel item (element 4) in or out for step 0..3. */
void func_001EDC28(DogRaceUi *self, unsigned char step);

/* DogRaceList methods. */
/* Clear word 0, construct the ID base and the 29 elements; returns self. */
DogRaceList *func_001EDE38(DogRaceList *self);
/* Set up the ID base (set 0x14, entry 1) and the elements, zero elements 0x12 and 0x14, hide them all. */
void InitDogRaceListIdWorks(DogRaceList *self);
/* Release or move the ID base (func_001EDF80 runs the elements first). */
void func_001EDF60(DogRaceList *self);
void func_001EDF80(DogRaceList *self);
/* Draw the background quad, then the ID base. */
void func_001EDFD8(DogRaceList *self);
/* Show (on set) or hide element id; id DOGRACE_LIST_ELEM_NUM means every element but 0. */
void SetCustomIDDispOneOrAll_1EE1C0(DogRaceList *self, int id, int on);
/* Set element 0x12's (func_001EE2A8) or element 0x14's (func_001EE2C8) number. */
void func_001EE2A8(DogRaceList *self, int number);
void func_001EE2C8(DogRaceList *self, int number);
/* Show or hide elements 1..0x1C, then pulse and show or hide element 0x15 (sel set) or 0x16. */
void func_001EE2E8(DogRaceList *self, int on, int sel);
/* Place element 28 at the row of slot 0..4. */
void func_001EE6C8(DogRaceList *self, unsigned short slot);
/* Start (enabled set) or stop the sideways bob of element 28. */
void func_001EE730(DogRaceList *self, int enabled);

/* DogRaceResult methods. */
/* Clear the flags, construct the ID base and the 45 elements; returns self. */
DogRaceResult *func_001ECA80(DogRaceResult *self);
/* Set up the ID base (set 0x14, entry 0) and the elements, set four messages and hide every element. */
void InitDogRaceResultIdWorks(DogRaceResult *self);
/* Release, or run the elements and move, the ID base. */
void func_001ECBD0(DogRaceResult *self);
void func_001ECBF0(DogRaceResult *self);
/* Draw the full-screen backing polygon of the result screen, then transform the ID base. */
void func_001ECC48(DogRaceResult *self);
/* Set slot 0..4's two number elements to n / 10 and n % 10 (n capped at 999). */
void func_001ED050(DogRaceResult *self, unsigned short slot, int n);
/* Show the elements of result layout 0 or 1. */
void func_001ED178(DogRaceResult *self, unsigned char mode);
/* Set element 37's number. */
void func_001ED490(DogRaceResult *self, int number);
/* Start (enabled set) or stop the sideways bob of element 36. */
void func_001ED4B0(DogRaceResult *self, int enabled);
/* Show (on set) or hide element id; id DOGRACE_RESULT_ELEM_NUM means every element but 8. */
void CustomIDWork_setDispAllButEight(DogRaceResult *self, int id, int on);
/* Set message messNo on row `slot` (0..4) of both message columns. */
void CustomIDWork_setSlotMessNo(DogRaceResult *self, unsigned short slot, int messNo);
/* Start (sel set) or stop the vertical bob of elements 34 and 35. */
void CustomIDOwner_setBob(DogRaceResult *self, int sel);

#endif
