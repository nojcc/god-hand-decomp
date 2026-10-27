/* include/godhand/cSnd.h - the sound manager.
 *
 * cSnd owns three things: a table of sound-effect slots, a list of voices
 * that are playing right now, and a list of BGM sequence nodes. Method names
 * are the game's own, from the symbol table in the retail ELF. Field names
 * are ours, taken from the methods that read and write them. Offsets are
 * exact: every body that uses this header builds byte-identical to retail.
 * A field nobody has named yet stays as unkNNN padding. The total size of
 * cSnd is not known, so the struct has no size check.
 *
 * Two files write here. Add fields at the right offset, and never rename or
 * move one that is already named.
 */
#ifndef GODHAND_CSND_H
#define GODHAND_CSND_H

#include "godhand/cOmBase.h"

/* A cVec on a quadword boundary: a struct assignment copies it with lq/sq. */
typedef struct cVec cVecQuad __attribute__((aligned(16)));

#define CSND_SE_ENTRY_SHIFT   6      /* slot stride is 1 << 6 = 0x40 */
#define CSND_SE_STOP_NUM      8      /* handles kept by SeStop */
#define CSND_SE_RECENT_NUM    16     /* recent-call ring */
#define CSND_VOICE_NUM        0x40   /* voices in the pool */
#define CSND_BGM_NODE_NUM     0x10   /* nodes in the BGM pool */
#define CSND_SE_ENTRY_NUM     0x34   /* sound-effect slots */

/* Flags on a BGM node (cSndBgmNode.flags). */
#define CSND_BGM_FLAG_SUSPEND 0x800
#define CSND_BGM_FLAG_PAUSE   0x1000

/* One slot of the sound-effect table (cSnd.seEntry), 0x40 bytes. */
typedef struct cSndSeEntry {
    char unk00[0x10];
    int  id;                    /* 0x10 sound id the slot plays */
    char unk14[0x28];
    int  owner;                 /* 0x3C object id, -1 when free */
} cSndSeEntry;                  /* 0x40 */

/* One playing voice. The list hangs off cSnd.voiceHead. */
typedef struct cSndSeVoice {
    struct cSndSeVoice *prev;   /* 0x00 */
    struct cSndSeVoice *next;   /* 0x04 */
    short key0;                 /* 0x08 */
    short key1;                 /* 0x0A */
    unsigned int flags;         /* 0x0C bit 0: handle is live */
    int kind;                   /* 0x10 0 = global, 2 = follows an object */
    int handle;                 /* 0x14 sound-driver handle */
    unsigned int stateFlags;    /* 0x18 bit 0x10000: quiet, bit 0x10: tracks a ratio */
    unsigned int optFlags;      /* 0x1C */
    int delay;                  /* 0x20 frames left before the sound starts */
    int pri;                    /* 0x24 */
    short idA;                  /* 0x28 -1 when unused */
    short idB;                  /* 0x2A -1 when unused */
    short curVolL;              /* 0x2C left volume last sent to the driver */
    short curVolR;              /* 0x2E right volume last sent */
    short curPitch;             /* 0x30 pitch last sent */
    short curPan;               /* 0x32 pan angle last sent, 0..719 */
    short dist;                 /* 0x34 fixed listener distance (kind 3) */
    char unk36[2];
    void *obj;                  /* 0x38 object the sound follows */
    void *part;                 /* 0x3C part of that object */
    float pos[3];               /* 0x40 */
    float scale;                /* 0x4C */
} __attribute__((aligned(16))) cSndSeVoice; /* 0x50 */

/* One call remembered by the recent-call ring. */
typedef struct cSndSeRecent {
    short a;                    /* 0x0 */
    short b;                    /* 0x2 */
    int   tick;                 /* 0x4 */
} cSndSeRecent;                 /* 8 */

/* A request to start a BGM sequence; copied into the node by the start code. */
typedef struct cSndBgmReq {
    int reqNo;                  /* 0x0 */
    int state;                  /* 0x4 */
    int param;                  /* 0x8 */
    unsigned short wordA;       /* 0xC */
    unsigned short wordB;       /* 0xE */
} cSndBgmReq;                   /* 0x10 */

/* One BGM sequence node. The sequence state sits first, then our fields. */
typedef struct cSndBgmNode {
    char unk00[0x5E];
    unsigned char started;      /* 0x5E */
    unsigned char unk5F;        /* 0x5F */
    unsigned char started60;    /* 0x60 */
    unsigned char unk61;        /* 0x61 */
    char unk62[0x22];
    struct cSndBgmNode *prev;   /* 0x84 */
    struct cSndBgmNode *next;   /* 0x88 */
    int bank;                   /* 0x8C bgm bank, biased by 0x80 */
    int reqNo;                  /* 0x90 request number */
    int state;                  /* 0x94 */
    unsigned int flags;         /* 0x98 */
    int param;                  /* 0x9C */
    short wordA;                /* 0xA0 */
    short wordB;                /* 0xA2 */
    int *link;                  /* 0xA4 */
    int *entry;                 /* 0xA8 */
    int matchWt;                /* 0xAC saveWt must equal this before the node may start */
    int state2;                 /* 0xB0 2 = finished */
    int wait;                   /* 0xB4 countdown, frames */
    int data;                   /* 0xB8 bgm data record */
    int saveWt;                 /* 0xBC */
    int prevWt;                 /* 0xC0 */
    float volume;               /* 0xC4 */
    float fadeTime;             /* 0xC8 */
    char unkCC[0x10];
} cSndBgmNode;                  /* 0xDC */

/* The sound memory heap hands out chunks tracked by a doubly linked list of blocks.
   Three heaps sit in a row (D_00602F80, D_00603310, D_006036A0), 0x390 bytes apart. */
#define CSND_HEAP_BLK_NUM 0x20
typedef struct cSndMemHeap cSndMemHeap;
typedef struct cSndMemBlk {
    cSndMemHeap *owner;         /* 0x00 */
    struct cSndMemBlk *next;    /* 0x04 */
    struct cSndMemBlk *prev;    /* 0x08 */
    int freeSize;               /* 0x0C bytes still free behind this block */
    int top;                    /* 0x10 first free address */
    int base;                   /* 0x14 address of the chunk, 0 = block unused */
    int size;                   /* 0x18 chunk size */
} cSndMemBlk;                   /* 0x1C */

struct cSndMemHeap {
    cSndMemBlk blk[CSND_HEAP_BLK_NUM];  /* 0x000 block 0 is the whole heap */
    cSndMemHeap *self;          /* 0x380 non-zero while the heap is set up */
    int size;                   /* 0x384 */
    int base;                   /* 0x388 chunk taken from the parent, 0 = none */
    cSndMemHeap *parent;        /* 0x38C */
};                              /* 0x390 */

typedef struct cSnd {
    char unk00[0x18];
    cSndBgmNode *bgmHead;       /* 0x18 first BGM node */
    cSndSeVoice *voiceHead;     /* 0x1C first playing voice */
    struct HitHost *seHit;      /* 0x20 hit set voices with stateFlags bit 1 are checked against */
    struct cBgmHit *hit;        /* 0x24 BGM hit table */
    char unk28[0xC];
    cSndSeVoice *voicePool;     /* 0x34 CSND_VOICE_NUM voices */
    cSndBgmNode *bgmPool;       /* 0x38 CSND_BGM_NODE_NUM nodes */
    cSndSeEntry *seEntry;       /* 0x3C sound-effect slot table */
    char unk40[4];
    int f44;                    /* 0x44 */
    int f48;                    /* 0x48 */
    char unk4C[4];
    int bgmAttr;                /* 0x50 BGM attribute bits now in force */
    int bgmAttrPrev;            /* 0x54 last frame's bgmAttr */
    int bgmDefAttr;             /* 0x58 attribute bits bgmAttr returns to each frame */
    char unk5C[4];
    float f60;                  /* 0x60 volume scale for voices with stateFlags bit 2 */
    float f64;                  /* 0x64 volume scale for voices with stateFlags bit 2 */
    float f68;                  /* 0x68 volume scale for object voices started while system bit 0x8000000 is set */
    float f6C;                  /* 0x6C weight BGM nodes are blended with */
    float f70;                  /* 0x70 volume scale for voices with stateFlags bit 0x20 */
    float f74;                  /* 0x74 f9C each frame unless a BGM area sets it */
    char unk78[0x10];
    float f88;                  /* 0x88 fA0 each frame unless a BGM area sets it */
    char unk8C[0x10];
    float f9C;                  /* 0x9C fade ratio, 0..1 */
    float fA0;                  /* 0xA0 */
    int fA4;                    /* 0xA4 cleared on resume */
    char unkA8[4];
    unsigned int flagsAC;       /* 0xAC */
    unsigned int flagsB0;       /* 0xB0 */
    char unkB4[0xC];
    cVecQuad listenPos;         /* 0xC0 listener position */
    float listenMtx[16];        /* 0xD0 world to listener matrix */
    int f110;                   /* 0x110 */
    char unk114[4];
    int curBank;                /* 0x118 bank of the BGM now playing, unbiased */
    int curReq;                 /* 0x11C its request number */
    int curWt;                  /* 0x120 its stored weight */
    char unk124[4];
    int f128;                   /* 0x128 */
    char unk12C[8];
    int f134;                   /* 0x134 countdown frames */
    int f138;                   /* 0x138 */
    int bgmState;               /* 0x13C eBgmState */
    int seStop[CSND_SE_STOP_NUM];       /* 0x140 */
    cSndSeRecent recent[CSND_SE_RECENT_NUM]; /* 0x160 */
    int recentPos;              /* 0x1E0 */
    char unk1E4[0xC];
    cSndSeEntry seTable[CSND_SE_ENTRY_NUM]; /* 0x1F0 sound-effect slots */
    char bgmData[0x88];         /* 0xEF0 two cBgmData records, 0x44 bytes each */
    char unkF78[8];
    cSndSeVoice voice[CSND_VOICE_NUM];      /* 0xF80 voice pool, voicePool points here */
    cSndBgmNode node[CSND_BGM_NODE_NUM];    /* 0x2380 BGM node pool, bgmPool points here */
} cSnd;

/* One entry of the sound-kind table (D_003C3138, 44 entries; D_003C3120 is
   the fallback entry filled in for ids the table does not list). */
typedef struct cSndKindEnt {
    unsigned short id;          /* 0x00 */
    char unk02[2];
    int param[5];               /* 0x04 */
} cSndKindEnt;                  /* 0x18 */

/* Size checks: a negative array size stops the build if a layout drifts. */
typedef char cSndSeEntry_size_check[sizeof(cSndSeEntry) == 0x40 ? 1 : -1];
typedef char cSndSeVoice_size_check[sizeof(cSndSeVoice) == 0x50 ? 1 : -1];
typedef char cSndBgmNode_size_check[sizeof(cSndBgmNode) == 0xDC ? 1 : -1];
typedef char cSndKindEnt_size_check[sizeof(cSndKindEnt) == 0x18 ? 1 : -1];
typedef char cSndMemHeap_size_check[sizeof(cSndMemHeap) == 0x390 ? 1 : -1];

cSndMemBlk *cSndMemHeap_FindBlk(cSndMemHeap *heap, int addr);
cSndMemBlk *cSndMemHeap_FindUnusedBlk(cSndMemHeap *heap);
cSndMemBlk *cSndMemHeap_FindFitBlk(cSndMemHeap *heap, unsigned int size);

cSndKindEnt *func_002D0B88(unsigned short id);
int cSnd_BgmReqFromEnemies(void *self);

extern cSnd D_005FEE00;
void cSnd_BgmEventFade(cSnd *self, int reqNo, float time, float level, float weight);

/* Plays sound effect se for an object; kind 1 picks the enemy's sound group. */
int cSnd_SeCall_2CB8A0(cSnd *self, int slot, short key1, short idA, short idB, int a5, int a6);
void cSnd_SetBgmState(cSnd *self, int state);
void cSnd_SeStop(cSnd *self, int handle);
/* The object's first sound-effect number (its word at 0x424). */
int GetSeqSEBase(int *obj);

/* Nonzero when pos is inside the hit set at self+0x20 (definition in
 * 00137cb8.c, whose HitHost is a view of cSnd). */
int cSndSeVoice_ckHitSet(struct HitHost *self, float *pos);

/* Pan angle and distance of a sound at pos (definition in 002cf058.c). */
void cSnd_CalcListenerPanDist(void *self, cVec *pos, short *dist, short *pan);

/* Starts sound effect key1 of slot at the position mtx (definition in sound/cSnd.c). */
int cSnd_SeCall(cSnd *self, int slot, short key1, int mtx, int idA, int idB);

int cSnd_AddBgmAttr(cSnd *self, int bits);
int cSnd_ClearBgmAttr(cSnd *self, int bits);
int cSnd_AddBgmDefAttr(cSnd *self, int bits);
int cSnd_ClearBgmDefAttr(cSnd *self, int bits);

void cSnd_BgmHitBeSet(cSnd *self, int on, unsigned short id);
void cSnd_SetBgmLevel(char *p, float lv, int a, int b, int c);
/* 1 when a live, non-boss enemy of the given kind is on the field; self is not read. */
int cSnd_IsEnemyAlive(cSnd *self, int kind);

#endif /* GODHAND_CSND_H */
