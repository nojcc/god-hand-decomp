/* include/godhand/espSys.h - effect system resource tables and memory pool (0x305858..0x307140).
 *
 * func_003058D8 finds the resource entry for an effect kind. entry[1] points
 * at a 1-based offset table, entry[2] at the 0-based T32 table; both start
 * with a count and hold offsets from the table start (0 = no resource).
 * The pool keeps a free list of MemNode blocks with its head node at
 * self + 0x4200; adjacent blocks are merged on free.
 */
#ifndef GODHAND_ESPSYS_H
#define GODHAND_ESPSYS_H

#include "godhand/cModel.h"           /* cVtEnt */
#include "godhand/cNode.h"
#include "godhand/cGameObj.h"

typedef struct espMemNode {
    struct espMemNode *prev;    /* 0x00 */
    struct espMemNode *next;    /* 0x04 */
    char unk08[4];
    char *base;                 /* 0x0C */
    unsigned short size;        /* 0x10 in 16-byte units */
} espMemNode;

#define ESP_MEM_HEAD_OFS 0x4200

extern int func_00305858(int *entry, int force);
extern int *func_003058D8(void *sys, int kind);
extern int FindAndForwardEntry_3059A8(void *sys, int kind, void *arg);
extern void *func_00305FB0(void *sys, int idx);
extern void *espSys_getEffT32Addr(void *sys, int kind, int idx);
extern void *func_00306030(void *sys, int kind, int idx);
extern int EffEventIsCutDataExist(unsigned int id);
extern char D_007419A0[];               /* the effect system */

/* Print an effect error: the message at msg with the effect's kind and number
 * (the extra arguments are not read). */
extern void func_002D9F68(void *self, int msg, ...);
extern void func_00306FC0(char *self, espMemNode *node);

/* A frame-driven effect steps its frame timer each tick, by one or through
 * the clock function func_002FA350, and runs its indexed update when the
 * frame index reaches the end. */
#define ESP_DATA_PAUSE   0x2000         /* EspData.flags: advance through the clock function */
#define ESP_DATA_HIDE_WHEN_CLEAR 0x800  /* EspData.flags: hidden while D_00741DB8 is 0 */
#define ESP_DATA_HIDE_WHEN_SET   0x400  /* EspData.flags: hidden while D_00741DB8 is set */
#define ESP_ANIM_CLOCK   0x100          /* EspAnim.flags (byte 0x11D bit 0): advance by the clock function */
#define ESP_ANIM_HIDE    0x800000       /* EspAnim.flags: not drawn */
#define ESP_ANIM_SKIP_METHOD2 0x10000   /* EspAnim.flags: func_002FBE88 does not call virtual method 2 */
#define ESP_ANIM_KEEP_HOOK_BIT 7    /* EspAnim.flags bit 7: the hook still runs when the owner has CMODEL_F_SHOWN */
#define SYSFLAG_SLOWMO   0x20000        /* bit of GameWork.flags5E4 */

typedef struct EspData {
    int unk00;
    unsigned int flags;                 /* 0x04 ESP_DATA_PAUSE */
} EspData;

typedef struct EspAnim {
    char unk000[0xF0];
    cVtEnt *vtable;                     /* 0x0F0 */
    char unk0F4[0x108 - 0xF4];
    int unk108;                         /* 0x108 */
    int unk10C;                         /* 0x10C */
    EspData *data;                      /* 0x110 */
    cGameObj *owner;                    /* 0x114 the object the effect belongs to */
    char unk118[0x11C - 0x118];
    int flags;                          /* 0x11C ESP_ANIM_CLOCK, ESP_ANIM_KEEP_HOOK_BIT, ESP_ANIM_HIDE */
    char unk120[0x124 - 0x120];
    float pos[3];                       /* 0x124 */
    float unk130;
    float vel[3];                       /* 0x134 */
    char unk140[0x224 - 0x140];
    unsigned short frameIdx;            /* 0x224 */
    char unk226[2];
    float frameT;                       /* 0x228 */
    unsigned short frameEnd;            /* 0x22C 0: no end */
    short key;                          /* 0x22E */
    short keyPrev;                      /* 0x230 */
    char unk232[0x24C - 0x232];
    unsigned char frameNum;             /* 0x24C */
    unsigned char frameNo;              /* 0x24D */
    char unk24E[2];
    float frame;                        /* 0x250 */
} EspAnim;

/* An emitter: one of the 0x100 slots MoveEmitter moves, spawning particles of kind rec->espNo. */
typedef struct espEmitRec {
    unsigned char flags0;               /* 0x00 bit 7: the emitter follows nothing */
    char unk01[3];
    unsigned int flags;                 /* 0x04 */
    char unk08[0x133 - 0x8];
    unsigned char espNo;                /* 0x133 the particle kind it emits */
} espEmitRec;

/* The node an emitter rides on. */
typedef struct espAnchor {
    char unk00[0x80];
    float mtx[4][4];                    /* 0x80 world matrix, translation in row 3 */
} espAnchor;

typedef struct espEmitter {
    cNode base;                         /* 0x000 */
    char unk0F4[0x100 - 0xF4];
    espEmitRec *rec;                    /* 0x100 */
    espAnchor *parent;                  /* 0x104 */
    cGameObj *owner;                    /* 0x108 */
    char unk10C[0x114 - 0x10C];
    unsigned int flags;                 /* 0x114 */
    unsigned int flags2;                /* 0x118 */
    char unk11C[0x180 - 0x11C];
    float time;                         /* 0x180 */
    char unk184[2];
    short delay;                        /* 0x186 frames before it starts */
    char unk188[2];
    short unk18A;
    char unk18C[0x1A0 - 0x18C];
    cVec emitPos;                       /* 0x1A0 */
    cVec rot;                           /* 0x1B0 */
    cVec trans;                         /* 0x1C0 */
    char unk1D0[0x224 - 0x1D0];
    unsigned short life;                /* 0x224 0: no limit */
    char unk226[2];
    float age;                          /* 0x228 */
    char unk22C[0x260 - 0x22C];
} espEmitter;                           /* 0x260, the slots at D_0071B940 */
typedef char espEmitter_size_check[sizeof(espEmitter) == 0x260 ? 1 : -1];

void func_002FA350(float *frame);
int EspAnim_step(EspAnim *self);
/* Run the indexed update when the owner has been released (the sign bit of
 * its objFlags), step the frame timer (func_002FBFB0), then hide or show the
 * effect by D_00741DB8 as its data asks. */
void func_002FBED0(EspAnim *self);
void func_002FBFB0(EspAnim *self);
/* Hand the effect's children to its parent and unlink it, then PushEsp it. */
void UpdateObjByIndexedOp_2FBE50(EspAnim *self);
/* UpdateObjByIndexedOp_2FBE50 when a and b are the effect's words at 0x108 and 0x10C. */
void func_002FEB80(EspAnim *self, int a, int b);
/* Call vtable entry 16 (the lock-on hook) unless the effect is hidden, or its
 * owner has CMODEL_F_SHOWN and the effect lacks ESP_ANIM_KEEP_HOOK_BIT. */
void LinkObj_callLockOn(EspAnim *self);
/* Call virtual method 2 unless the effect has ESP_ANIM_SKIP_METHOD2. */
void func_002FBE88(EspAnim *self);
void func_002FEBE8(EspAnim *self, unsigned short len, int mode);

#endif
