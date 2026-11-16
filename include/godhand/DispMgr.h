/* include/godhand/DispMgr.h - DispMgr, the registry of display sub-records.
 *
 * A DispMgr holds eleven sub-records at fixed offsets, then a table of
 * registered objects at 0x22F0 (12 bytes per slot). func_00140BF0 registers
 * a sub-record in the first free slot and DispMgr_reset (src/cod/00140c88.c)
 * walks the table to call every object's reset method.
 *
 * Field names are ours, taken from the functions that read and write them.
 * Offsets are exact. A field we can't name yet stays as unkNN padding.
 */
#ifndef GODHAND_DISPMGR_H
#define GODHAND_DISPMGR_H

#include "godhand/IDPanelScreen.h"
#include "godhand/cCockLoading.h"
#include "godhand/cCockItem.h"
#include "godhand/cCockBossBar.h"
#include "godhand/cCockLastBossBar.h"
#include "godhand/cCockTutorial.h"

#define DISPMGR_SLOT_NUM  0x11          /* FindFreeSlotIndex_140C58 stops at 0x11 */
#define DISPMGR_SLOT_OFS  0x22F0        /* byte offset of slot[0] */

/* A g++ 2.x vtable entry of a registered sub-record. */
typedef struct DispMgrSubMethod {
    short delta;                        /* added to the object before the call */
    short index;
    void (*pfn)(void *self);
} DispMgrSubMethod;

#define DISPMGR_SUB_RESET  2            /* vtable entry DispMgr_reset calls */
#define DISPMGR_SUB_HOOK   3            /* vtable entry cHookList_callAll calls */

/* The head every registered sub-record shares, as the slot walks see it. */
typedef struct DispMgrSub {
    char unk00[0x75];
    unsigned char unk75;                /* 0x75 set to 1 by func_001415E8 */
    unsigned char unk76;                /* 0x76 func_001415E8's value */
    char unk77[0x80 - 0x77];
    DispMgrSubMethod *vt;               /* 0x80 */
} DispMgrSub;

typedef struct DispMgrSlot {
    int kind;                           /* 0x0 what the sub-record is, 0 = free is judged on obj */
    DispMgrSub *obj;                    /* 0x4 the registered sub-record, 0 when the slot is free */
    int unk8;
} DispMgrSlot;                          /* 0xC */

typedef struct DispMgr {
    IDPanelScreen panel;                /* 0x0000 */
    char unk0390[0x3A0 - sizeof(IDPanelScreen)];
    cCockLoading loading;               /* 0x03A0 */
    char unk0460[0x1910 - 0x460];
    cCockItem item;                     /* 0x1910 registered as kind 16 */
    char unk1A18[0x1A20 - 0x1910 - sizeof(cCockItem)];
    cCockTutorial tutorial;             /* 0x1A20 */
    char unk1ADC[0x1DC0 - 0x1A20 - sizeof(cCockTutorial)];
    cCockBossBar bossBar;               /* 0x1DC0 */
    char unk1E90[0x2220 - 0x1E90];
    cCockLastBossBar lastBossBar;       /* 0x2220 */
    DispMgrSlot slot[DISPMGR_SLOT_NUM]; /* 0x22F0 */
    unsigned char ready;                /* 0x23BC cleared by DispMgr_reset */
} DispMgr;

typedef char DispMgr_loading_check[((int)&((DispMgr *)0)->loading == 0x3A0) ? 1 : -1];
typedef char DispMgr_item_check[((int)&((DispMgr *)0)->item == 0x1910) ? 1 : -1];
typedef char DispMgr_tutorial_check[((int)&((DispMgr *)0)->tutorial == 0x1A20) ? 1 : -1];
typedef char DispMgr_bossBar_check[((int)&((DispMgr *)0)->bossBar == 0x1DC0) ? 1 : -1];
typedef char DispMgr_lastBossBar_check[((int)&((DispMgr *)0)->lastBossBar == 0x2220) ? 1 : -1];
typedef char DispMgr_slot_check[((int)&((DispMgr *)0)->slot == DISPMGR_SLOT_OFS) ? 1 : -1];
typedef char DispMgr_ready_check[((int)&((DispMgr *)0)->ready == 0x23BC) ? 1 : -1];

/* Index of the first slot with no object, or -1 when all are taken. */
int FindFreeSlotIndex_140C58(DispMgr *mgr);
/* Register sub of the given kind in the first free slot: 1, or 0 if the table is full. */
int DispMgr_registerSub(DispMgr *mgr, void *sub, int kind);
/* Clear the slots, register and set up the sub-records, then reset every registered object. */
void DispMgr_reset(DispMgr *self);
/* Set unk75 and unk76 = value on every registered sub-record. */
void func_001415E8(DispMgr *mgr, int value);
/* Run the hook method of every registered sub-record, clear ready, then mark them all with value 0. */
void cHookList_callAll(DispMgr *self);

#endif
