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
#include "godhand/cBgmData.h"

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
    char unk2C[8];
    short f34;                  /* 0x34 */
    char unk36[2];
    void *obj;                  /* 0x38 object the sound follows */
    void *part;                 /* 0x3C part of that object */
    float pos[3];               /* 0x40 */
    float scale;                /* 0x4C */
} cSndSeVoice;                  /* 0x50 */

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
    char unk62[0x1E];
    void *vt;                   /* 0x80 method table, D_0044CEE8 */
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
    cBgmData *data;             /* 0xB8 bgm data record */
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
    float unk00[3];             /* 0x00 scaled by voice index */
    float unk0C[3];             /* 0x0C */
    cSndBgmNode *bgmHead;       /* 0x18 first BGM node */
    cSndSeVoice *voiceHead;     /* 0x1C first playing voice */
    char unk20[4];
    cBgmHit *hit;               /* 0x24 BGM hit table */
    char unk28[8];
    int f30;                    /* 0x30 */
    cSndSeVoice *voicePool;     /* 0x34 CSND_VOICE_NUM voices */
    cSndBgmNode *bgmPool;       /* 0x38 CSND_BGM_NODE_NUM nodes */
    cSeData *seEntry;           /* 0x3C sound-effect slot table */
    cBgmData *bgm;              /* 0x40 the cBgmData records, one per bank */
    int f44;                    /* 0x44 */
    int f48;                    /* 0x48 */
    char unk4C[0x18];
    float f64;                  /* 0x64 volume scale for voices with stateFlags bit 2 */
    char unk68[4];
    float f6C;                  /* 0x6C weight BGM nodes are blended with */
    float f70;                  /* 0x70 volume scale for voices with stateFlags bit 0x20 */
    char unk74[0x28];
    float f9C;                  /* 0x9C fade ratio, 0..1 */
    char unkA0[4];
    int fA4;                    /* 0xA4 cleared on resume */
    int fA8;                    /* 0xA8 */
    unsigned int flagsAC;       /* 0xAC */
    unsigned int flagsB0;       /* 0xB0 */
    char unkB4[0xC];
    cVecQuad listenPos;         /* 0xC0 listener position */
    float listenMtx[16];        /* 0xD0 world to listener matrix */
    int listenMode;             /* 0x110 LISTEN_* */
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
    cSeData seTable[CSND_SE_ENTRY_NUM]; /* 0x1F0 sound-effect slots */
    cBgmData bgmData[2];        /* 0xEF0 the BGM data records, bgm points here */
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
typedef char cSndSeVoice_size_check[sizeof(cSndSeVoice) == 0x50 ? 1 : -1];
typedef char cSndBgmNode_size_check[sizeof(cSndBgmNode) == 0xDC ? 1 : -1];
typedef char cSndKindEnt_size_check[sizeof(cSndKindEnt) == 0x18 ? 1 : -1];
typedef char cSndMemHeap_size_check[sizeof(cSndMemHeap) == 0x390 ? 1 : -1];

cSndKindEnt *func_002D0B88(unsigned short id);
int cSnd_BgmReqFromEnemies(void *self);
/* Plays sound-effect slot on a free voice at the origin; 0 when the slot is dead or no voice is free. */
int cSnd_SeCall_2CBA48(cSnd *self, int slot, int key, void *obj, void *owner, void *part, int a6, int a7);
int cSnd_SeCall_2CB8A0(cSnd *self, int slot, short key1, short idA, short idB, int a5, int a6);

/* The game's one sound object. */
extern cSnd D_005FEE00;
/* Its storage, addressed by retail as separate symbols. */
extern cSeData D_005FEFF0[CSND_SE_ENTRY_NUM];        /* the sound-effect slots seEntry points at */
extern cBgmData D_005FFCF0[2];                       /* the BGM data records bgm points at */
extern cSndSeVoice D_005FFD80[CSND_VOICE_NUM];       /* the voice pool */
extern cSndBgmNode D_00601180[CSND_BGM_NODE_NUM];    /* the BGM node pool */

/* The sound object, voice, BGM node API, as defined. */
int cSndBgmNode_ApplyReq(cSndBgmNode *node, cSndBgmReq *req, int flags);
void cSndBgmNode_Fade(cSndBgmNode *node);
void cSndBgmNode_FadeIn(cSndBgmNode *node, float time);
void cSndBgmNode_FadeOut(cSndBgmNode *node, float time);
void cSndBgmNode_Init(cSndBgmNode *node);
/* cSndBgmNode's method table. */
extern char D_0044CEE8[];
/* Constructor: build the SndVoiceNode part, set cSndBgmNode's method table
 * and initialise the node; returns node. */
cSndBgmNode *cSndBgmNode_Ctor(cSndBgmNode *node);
/* Destructor: put back cSndBgmNode's method table, then run SndVoiceNode's. */
void cSndBgmNode_Dtor(cSndBgmNode *node, int flags);
int cSndBgmNode_IsActive(cSndBgmNode *node);
int cSndBgmNode_IsDone(cSndBgmNode *node);
void cSndBgmNode_Link(cSndBgmNode *node);
void cSndBgmNode_Release(cSndBgmNode *node);
void cSndBgmNode_Resume(cSndBgmNode *node);
void cSndBgmNode_Run(cSndBgmNode *node);
void cSndBgmNode_SetFlagsFade(cSndBgmNode *node, unsigned int setBits, unsigned int clearBits, float time);
void cSndBgmNode_SetFlagsFadeOut(cSndBgmNode *node, int setBits, float time);
int cSndBgmNode_Setup(cSndBgmNode *node, int bank, cSndBgmReq *req, int flags);
int cSndBgmNode_Start(cSndBgmNode *node);
void cSndBgmNode_StepState(cSndBgmNode *node);
void cSndBgmNode_Unlink(cSndBgmNode *node);
void cSndBgmNode_Update(cSndBgmNode *node);
void cSndSeRecent_Clear(cSndSeRecent *r);
int cSndSeVoice_Bind(cSndSeVoice *v, short key0, short key1, char *obj, char *part, int a5, int a6);
int cSndSeVoice_BindMtx(cSndSeVoice *v, short key0, short key1, void *pos, int a5, int a6);
int cSndSeVoice_CheckEnd(cSnd *self, int idx);
void cSndSeVoice_Detach(cSndSeVoice *v, char *obj);
void cSndSeVoice_Init(cSndSeVoice *v);
int cSndSeVoice_IsActive(cSndSeVoice *v);
void cSndSeVoice_Link(cSndSeVoice *voice);
void cSndSeVoice_Release(cSndSeVoice *v, short key, int mode);
int cSndSeVoice_StartAtOrigin(cSndSeVoice *v, short key0, short key1, short idA, short idB, int a5, int a6);
void cSndSeVoice_Stop(cSndSeVoice *v);
void cSndSeVoice_Unlink(cSndSeVoice *voice);
void cSndSeVoice_Update(cSndSeVoice *voice);
cSndBgmNode *cSnd_AllocBgmNode(cSnd *self);
cSndBgmNode *cSnd_FindBgmNode(cSnd *self, int bank, int reqNo);
cBgmData *cSnd_GetBgmData(cSnd *self, int bank);
cSndBgmNode *func_002D2DB0(cSnd *self, int idx);
cSeData *cSnd_GetSeData(cSnd *self, int slot);
void cSnd_BgmEvCutSet(cSnd *self, int reqNo);
void cSnd_DieDemoStart(cSnd *self);
cSnd *func_002C9C88(cSnd *self);
void cSnd_StaticInit(int initialize, int priority);
void func_002CA040(cSnd *self);
void func_002CA690(cSnd *self);
void func_002CABE8(cSnd *self);
void cSnd_SeCallGlobal(void *unused, int id, short slot, void *obj);
int cSnd_SeLoadNo(cSnd *self, int slot, int arg);
void cSnd_SetBgmState(cSnd *self, int state);
void cSndBgmNode_FadeTo(cSndBgmNode *node, float level, float time);
cSndSeVoice *cSnd_AllocVoice(cSnd *self);
void cSnd_BattleBgmAllPause(cSnd *self, float time);
void cSnd_BgmEvAllSignal(cSnd *self, float time);
void cSnd_BgmEvAllSuspend(cSnd *self, float time);
int cSnd_BgmEvCutCheck(cSnd *self, int reqNo);
int cSnd_BgmEvDataCheck(cSnd *self);
void cSnd_BgmEvDataEnd(cSnd *self);
void cSnd_BgmEvDataInit(cSnd *self, int arg);
void cSnd_BgmEvFadeDefault(cSnd *self, int bgmPt, int reqNo);
void cSnd_BgmEvFadeSet(cSnd *self, int bgmPt, int reqNo, float time, float level, float weight);
int cSnd_BgmEvIsReady(cSnd *self, int bgmPt, int reqNo);
void cSnd_BgmEvPause(cSnd *self, int bgmPt, int reqNo);
void cSnd_BgmEvReStart(cSnd *self, int bgmPt, int reqNo, int param);
int cSnd_BgmEvSet(cSnd *self, int bgmPt, int reqNo);
int cSnd_BgmEvStart(cSnd *self, int bgmPt, int reqNo, int param);
void cSnd_BgmEventFade(cSnd *self, int reqNo, float time, float level, float weight);
void cSnd_BgmEventSet(cSnd *self, int reqNo, int wordA, int wordB);
void cSnd_BgmEventStart(cSnd *self, int reqNo, int a2, int a3);
void cSnd_BgmEventStop(cSnd *self, int keep);
void cSnd_BgmFadeOutAll(cSnd *self, int bgmPt, int keepReq, float time);
void cSnd_BgmFlaggedNodeKick(cSnd *self, float arg);
void cSnd_BgmHitBeSet(cSnd *self, int on, unsigned short id);
int cSnd_BgmNodeSet(cSndBgmNode *node, int bank, int reqNo, int state, unsigned int param, int wordA, int wordB);
int cSnd_BgmNodeStart(cSndBgmNode *node, int bank, int reqNo, int state, unsigned int param, int wordA, int wordB);
void cSnd_BgmStageChange(cSnd *self);
void cSnd_CheckSeEnd(cSnd *self, int slot);
int cSnd_EmSeCheck(cSnd *self, int objId);
int cSnd_EmSeFind(cSnd *self, int objId);
int cSnd_FindFreeSe(cSnd *self);
int cSnd_FindFreeSeSlot(cSnd *self);
int cSnd_FindSeSlotById(cSnd *self, cSeBuf *buf);
cSndSeVoice *cSnd_FindVoiceByHandle(cSnd *self, int handle);
float cSnd_GetBgmHitScale(cSnd *self);
int cSnd_GetStageBgmReq(cSnd *self, unsigned short stage);
cSndSeVoice *cSnd_GetVoice(cSnd *self, int idx);
void cSnd_GlobalCtor(void);
int cSnd_IsEnemyAlive(cSnd *self, int kind);
void cSnd_LoadStartupBanks(cSnd *self);
int cSnd_ReserveSeSlot(cSnd *self, cSeBuf *buf);
int cSnd_SeCall(cSnd *self, int slot, short key1, void *pos, int idA, int idB);
void cSnd_SeDetachObj(cSnd *self, void *obj);
int cSnd_SeEndCk(cSnd *self, int handle);
int cSnd_SeFadeOut(cSnd *self, int handle, short fade);
void cSnd_SeFadeOutHeldVoices(cSnd *self);
void cSnd_SeFadeVoicesByKey(cSnd *self, short key, short fade);
int cSnd_SeIsLoadOk(cSnd *self, int slot);
int cSnd_SeIsLoaded(cSnd *self, int slot);
int cSnd_SeLoadFile(cSnd *self, int slot, char *name);
void cSnd_SeRecentPush(cSnd *self, int a, int b, int tick);
void cSnd_SeStop(cSnd *self, int handle);
void cSnd_SeVoiceCallAll(cSnd *self, int a1, int a2);
void cSnd_SetBgmLevel(char *p, float lv, int a, int b, int c);
void cSnd_UpdateListener(cSnd *self);
void cSnd_flushPendingSe(cSnd *self);
int cSnd_getEmSeGroupOwner(cSnd *self, int id);
void cSnd_quietAll(cSnd *self);
void cSnd_releaseEmSeAll(cSnd *self);
void cSnd_resetAll(cSnd *self);
void cSnd_shutdown(cSnd *self);
void cSnd_update(cSnd *self);
void cSnd_updateLoads(cSnd *self);

#endif /* GODHAND_CSND_H */
