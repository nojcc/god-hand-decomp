/* include/godhand/pl00.h - pl00, the player object.
 *
 * pl00 derives from cGameObj. Past the base part it keeps the objects that
 * fight beside the player: three of them sit in a row of pointers at 0x698,
 * 0x6A0 and 0x6A8, and the player forwards the state changes that concern
 * them (suspend, for one) through their method table at 0x214.
 *
 * Only the fields the methods drawn so far touch are named. Offsets are
 * exact; a span nobody has named stays unkNNN padding.
 */
#ifndef GODHAND_PL00_H
#define GODHAND_PL00_H

#include "godhand/cGameObj.h"

/* A method table entry of the objects the player forwards to: a g++ 2.x
 * this-adjust, the index, and the function. */
typedef struct pl00VtEnt {
    short delta;
    short index;
    void (*pfn)(void *self, int arg);
} pl00VtEnt;

/* Entry 12 of the table at 0x214 (offset 0x60) is setSuspend. */
#define PL00_VT_SETSUSPEND  12

struct cEm00;

typedef struct pl00 {
    cGameObj base;
    char unk5B0[0x5D8 - 0x5B0];
    int unk5D8;                         /* 0x5D8 */
    float unk5DC;                       /* 0x5DC */
    unsigned short unk5E0;                     /* 0x5E0 cleared with unk5E2 when a state starts */
    short unk5E2;                       /* 0x5E2 */
    char unk5E4[0x5F0 - 0x5E4];
    short unk5F0;                       /* 0x5F0 */
    unsigned short unk5F2;              /* 0x5F2 */
    char unk5F4[0x600 - 0x5F4];
    float unk600;                       /* 0x600 */
    float unk604;                       /* 0x604 */
    float unk608;                       /* 0x608 */
    float unk60C;                       /* 0x60C */
    char unk610[0x61E - 0x610];
    unsigned char unk61E;               /* 0x61E */
    unsigned char unk61F;               /* 0x61F */
    char unk620;
    unsigned char unk621;               /* 0x621 */
    unsigned char unk622;               /* 0x622 */
    unsigned char unk623;               /* 0x623 */
    char unk624[2];
    signed char unk626;                 /* 0x626 */
    char unk627[0x630 - 0x627];
    cVec unk630;                        /* 0x630 func_0012A578 scales the player's offset from this point */
    cGameObj *unk640;                   /* 0x640 the enemy func_00124540 picks to catch */
    char unk644[0x648 - 0x644];
    signed char unk648;                 /* 0x648 */
    unsigned char unk649;               /* 0x649 */
    char unk64A[0x660 - 0x64A];
    cVec unk660;                        /* 0x660 x and z copied back into pos */
    float unk670;                       /* 0x670 heading copied back into rot.y */
    float unk674;                       /* 0x674 */
    char *unk678;                       /* 0x678 */
    char unk67C[0x68C - 0x67C];
    cGameObj *unk68C;                   /* 0x68C object flagged always-drawn with the player */
    char unk690[0x694 - 0x690];
    struct cEm00 *unk694;               /* 0x694 the enemy the player holds; cEm00_GetPlMotion runs its motions */
    cGameObj *sub698;                   /* 0x698 */
    cGameObj *unk69C;                   /* 0x69C */
    cGameObj *sub6A0;                   /* 0x6A0 */
    char unk6A4[4];
    cGameObj *sub6A8;                   /* 0x6A8 */
    char unk6AC[0x76C - 0x6AC];
    float unk76C;                       /* 0x76C */
    char unk770[0x1588 - 0x770];
    float unk1588;                      /* 0x1588 */
    char unk158C[0x15B0 - 0x158C];
    int unk15B0;                        /* 0x15B0 */
    int unk15B4;                        /* 0x15B4 */
    int unk15B8;                        /* 0x15B8 */
    int unk15BC;                        /* 0x15BC */
    float unk15C0;                      /* 0x15C0 */
    float unk15C4;                      /* 0x15C4 */
    char unk15C8[0x15F0 - 0x15C8];
    float unk15F0;                      /* 0x15F0 */
    int flags15F4;                      /* 0x15F4 */
    char unk15F8[0x15FC - 0x15F8];
    float unk15FC;                      /* 0x15FC */
    char unk1600;
    char unk1601;                       /* 0x1601 */
    char unk1602;
    char unk1603;                       /* 0x1603 */
    char unk1604[0x160C - 0x1604];
    int unk160C;                        /* 0x160C */
    float unk1610;                      /* 0x1610 */
    unsigned char unk1614;              /* 0x1614 */
    signed char comboCount;             /* 0x1615 hits in the current combo */
    short comboTimer;                   /* 0x1616 frames left before the combo ends */
    short unk1618;                      /* 0x1618 cleared when mode 1 starts */
    char unk161A[0x161C - 0x161A];
    int unk161C;                        /* 0x161C */
    int unk1620;                        /* 0x1620 sound handle, stopped with cSnd_SeStop */
    char unk1624[0x165C - 0x1624];
    int unk165C;                        /* 0x165C */
    char unk1660[0x1684 - 0x1660];
    char unk1684;                       /* 0x1684 */
} pl00;

typedef char pl00_chk_sub698[((int)&((pl00 *)0)->sub698 == 0x698) ? 1 : -1];
typedef char pl00_chk_sub6A0[((int)&((pl00 *)0)->sub6A0 == 0x6A0) ? 1 : -1];
typedef char pl00_chk_sub6A8[((int)&((pl00 *)0)->sub6A8 == 0x6A8) ? 1 : -1];
typedef char pl00_chk_flags[((int)&((pl00 *)0)->flags15F4 == 0x15F4) ? 1 : -1];
typedef char pl00_chk_combo[((int)&((pl00 *)0)->comboCount == 0x1615) ? 1 : -1];
typedef char pl00_chk_timer[((int)&((pl00 *)0)->comboTimer == 0x1616) ? 1 : -1];
typedef char pl00_chk_640[((int)&((pl00 *)0)->unk640 == 0x640) ? 1 : -1];
typedef char pl00_chk_660[((int)&((pl00 *)0)->unk660 == 0x660) ? 1 : -1];
typedef char pl00_chk_68C[((int)&((pl00 *)0)->unk68C == 0x68C) ? 1 : -1];
typedef char pl00_chk_694[((int)&((pl00 *)0)->unk694 == 0x694) ? 1 : -1];
typedef char pl00_chk_15B0[((int)&((pl00 *)0)->unk15B0 == 0x15B0) ? 1 : -1];
typedef char pl00_chk_1684[((int)&((pl00 *)0)->unk1684 == 0x1684) ? 1 : -1];

/* 1 when the given bit of flags15F4 is set, else 0. */
int Obj0000_IsSet_Field_15F4_Bit_400000_10B698(pl00 *self);
/* Nonzero if the player may start an attack: no action at 0x6A0, alive, not caught, and bit 8 of flags15F4 set. */
int pl00_ckAtkActBtnEnable(pl00 *self);
int Obj0000_IsSet_Field_15F4_Bit_1000_12C530(pl00 *self);
int Obj0000_IsSet_Field_15F4_Bit_100000_12CA48(pl00 *self);
int Obj0000_IsSet_Field_15F4_Bit_1000000_12CED8(pl00 *self);

/* Spend heat gauge through cHeatSys and switch to heat mode when the flags allow; nonzero when it switched. */
int func_00123938(pl00 *self, int mode);
/* Pick the enemy the player catches (unk640); returns 1 and sets unk648 when one is found. */
int func_00124540(pl00 *self, int kind);
/* 1 when one of the five slots at 0x5B0 is in a busy motion, else 0. */
int func_0010B2E8(pl00 *self, int flag);
/* Clear the catch target (unk640) and its flag (unk648). */
void Obj0000_Clear_Fields_640_648_124E58(pl00 *self);
/* Turn toward the catch target (unk640) at the given rate, when there is one. */
void InvokeVirtualAtField214AndForward_124E68(pl00 *self, float f12);

#endif
