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

typedef struct pl00 {
    cGameObj base;
    char unk5AC[0x5DC - 0x5AC];
    float unk5DC;                       /* 0x5DC set with base.speedRate by the combo attacks */
    unsigned short comboSlot;           /* 0x5E0 combo slot being run (ComboObj.slot) */
    unsigned short comboSet;            /* 0x5E2 combo set (ComboObj.set) */
    unsigned short comboTicks;          /* 0x5E4 (ComboObj.ticks) */
    unsigned short comboStage;          /* 0x5E6 (ComboObj.stage) */
    unsigned int combo;                 /* 0x5E8 combo id, as ComboObj_startNext returns it */
    unsigned int prevCombo;             /* 0x5EC */
    short unk5F0;                       /* 0x5F0 */
    char unk5F2[2];
    int unk5F4;                         /* 0x5F4 raised by each hit; at 0x82 the hit knocks the player down */
    int unk5F8;                         /* 0x5F8 raised by 0x96 on each hit that doesn't kill */
    char unk5FC[0x61F - 0x5FC];
    unsigned char unk61F;               /* 0x61F as in cEm00 */
    char unk620[0x630 - 0x620];
    cVec unk630;                        /* 0x630 func_0012A578 scales the player's offset from this point */
    cGameObj *unk640;                   /* 0x640 */
    char unk644[4];
    unsigned char unk648;               /* 0x648 set to 0x14 while unk640 is set */
    char unk649[0x678 - 0x649];
    cDamageTake *damage;                /* 0x678 the hit the player took this frame, 0 if none */
    char unk67C[0x698 - 0x67C];
    cGameObj *sub698;                   /* 0x698 */
    char unk69C[4];
    cGameObj *sub6A0;                   /* 0x6A0 */
    char unk6A4[4];
    cGameObj *sub6A8;                   /* 0x6A8 */
    char unk6AC[0x1588 - 0x6AC];
    float unk1588;                      /* 0x1588 forward push added to nullSpeed.z, decays by 0.9 */
    char unk158C[0x1598 - 0x158C];
    float unk1598;                      /* 0x1598 second push, decays by 0.9 */
    char unk159C[0x15B0 - 0x159C];
    int unk15B0;                        /* 0x15B0 */
    int unk15B4;                        /* 0x15B4 */
    int unk15B8;                        /* 0x15B8 */
    char unk15BC[4];
    float unk15C0;                      /* 0x15C0 */
    float unk15C4;                      /* 0x15C4 */
    char unk15C8[0x15F4 - 0x15C8];
    int flags15F4;                      /* 0x15F4 */
    char unk15F8[0x1603 - 0x15F8];
    unsigned char unk1603;              /* 0x1603 */
    char unk1604[0x160C - 0x1604];
    int unk160C;                        /* 0x160C the quarter of a hit's power some attack kinds hold back */
    float unk1610;                      /* 0x1610 copy of unk15C0 */
    char unk1614;
    signed char comboCount;             /* 0x1615 hits in the current combo */
    short comboTimer;                   /* 0x1616 frames left before the combo ends */
    short unk1618;                      /* 0x1618 */
    char unk161A[0x1620 - 0x161A];
    int seHandle;                       /* 0x1620 sound started by the player, stopped when it is hit */
    char unk1624[0x1660 - 0x1624];
    int unk1660;                        /* 0x1660 Obj0000_Set_Fields_1668_1660... writes it */
    int unk1664;                        /* 0x1664 Obj0000_Set_Fields_166C_1664... writes it */
    int moveA;                          /* 0x1668 (ComboObj.moveA) */
    int moveB;                          /* 0x166C (ComboObj.moveB) */
    char unk1670[0x1684 - 0x1670];
    unsigned char unk1684;              /* 0x1684 */
} pl00;

typedef char pl00_chk_sub698[((int)&((pl00 *)0)->sub698 == 0x698) ? 1 : -1];
typedef char pl00_chk_sub6A0[((int)&((pl00 *)0)->sub6A0 == 0x6A0) ? 1 : -1];
typedef char pl00_chk_sub6A8[((int)&((pl00 *)0)->sub6A8 == 0x6A8) ? 1 : -1];
typedef char pl00_chk_combo[((int)&((pl00 *)0)->comboCount == 0x1615) ? 1 : -1];
typedef char pl00_chk_timer[((int)&((pl00 *)0)->comboTimer == 0x1616) ? 1 : -1];
typedef char pl00_chk_damage[((int)&((pl00 *)0)->damage == 0x678) ? 1 : -1];
typedef char pl00_chk_se[((int)&((pl00 *)0)->seHandle == 0x1620) ? 1 : -1];
typedef char pl00_chk_combo5e0[((int)&((pl00 *)0)->comboSlot == 0x5E0) ? 1 : -1];
typedef char pl00_chk_640[((int)&((pl00 *)0)->unk640 == 0x640) ? 1 : -1];
typedef char pl00_chk_648[((int)&((pl00 *)0)->unk648 == 0x648) ? 1 : -1];
typedef char pl00_chk_15b0[((int)&((pl00 *)0)->unk15B0 == 0x15B0) ? 1 : -1];
typedef char pl00_chk_1684[((int)&((pl00 *)0)->unk1684 == 0x1684) ? 1 : -1];
typedef char pl00_chk_15f4[((int)&((pl00 *)0)->flags15F4 == 0x15F4) ? 1 : -1];
typedef char pl00_chk_5f4[((int)&((pl00 *)0)->unk5F4 == 0x5F4) ? 1 : -1];
typedef char pl00_chk_5dc[((int)&((pl00 *)0)->unk5DC == 0x5DC) ? 1 : -1];
typedef char pl00_chk_combo5e8[((int)&((pl00 *)0)->combo == 0x5E8) ? 1 : -1];
typedef char pl00_chk_5f0[((int)&((pl00 *)0)->unk5F0 == 0x5F0) ? 1 : -1];
typedef char pl00_chk_61f[((int)&((pl00 *)0)->unk61F == 0x61F) ? 1 : -1];
typedef char pl00_chk_1588[((int)&((pl00 *)0)->unk1588 == 0x1588) ? 1 : -1];
typedef char pl00_chk_1598[((int)&((pl00 *)0)->unk1598 == 0x1598) ? 1 : -1];
typedef char pl00_chk_15c4[((int)&((pl00 *)0)->unk15C4 == 0x15C4) ? 1 : -1];
typedef char pl00_chk_1603[((int)&((pl00 *)0)->unk1603 == 0x1603) ? 1 : -1];
typedef char pl00_chk_1610[((int)&((pl00 *)0)->unk1610 == 0x1610) ? 1 : -1];
typedef char pl00_chk_1618[((int)&((pl00 *)0)->unk1618 == 0x1618) ? 1 : -1];
typedef char pl00_chk_1660[((int)&((pl00 *)0)->unk1660 == 0x1660) ? 1 : -1];
typedef char pl00_chk_1668[((int)&((pl00 *)0)->moveA == 0x1668) ? 1 : -1];

/* Store a1..a5 at 0x1668, 0x1660, 0x1670, 0x1678 and (short) 0x1680. */
void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
/* Store a1..a5 at 0x166C, 0x1664, 0x1674, 0x167C and (short) 0x1682. */
void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);

/* Put the player model into (mode != 0) or out of the subscreen pose. */
void pl00_SubscreenMode(void *a0, int a1);
/* Play motion a1 on the player model in the subscreen. */
void pl00_SubscreenMotSet(void *a0, int a1);

/* Write one attack's parameters to both of the player's attack slots. */
static __inline__ void pl00_setSwing(pl00 *self, int a1, int a2, int a3, int a5)
{
    Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(self, a1, a2, a3, 0, a5);
    Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(self, a1, a2, a3, 0, a5);
}

#endif
