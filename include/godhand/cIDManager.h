/* include/godhand/cIDManager.h - the resource id manager.
 *
 * cIDManager holds three things in one big object:
 *   - a table of resource pairs, 8 bytes per slot, filled by setIDData;
 *   - a queue of up to 100 pending jobs, 0x10 bytes each, with a counter at
 *     0x740;
 *   - a pool of 0xAC-byte buffers at 0x744, handed out in runs from a cursor
 *     at 0x1B544. The pool holds 0x280 buffers at most.
 * Each queued job remembers the run it took, so the last run can be given
 * back.
 *
 * Method names come from the retail symbol table. Field names are ours, taken
 * from the methods that read and write them. Offsets are exact.
 */
#ifndef GODHAND_CIDMANAGER_H
#define GODHAND_CIDMANAGER_H

#define CIDMGR_POOL_MAX    0x280        /* buffers in the pool */
#define CIDMGR_BUF_SIZE    0xAC         /* bytes per buffer */
#define CIDMGR_JOB_MAX     100

typedef struct cIDPair {
    void *data;                         /* 0x0 first lookup result */
    void *tex;                          /* 0x4 second lookup result */
} cIDPair;

typedef struct cIDJob {
    int tag;                            /* 0x00 caller key, matched on give-back */
    int arg;                            /* 0x04 */
    void *buf;                          /* 0x08 first buffer of the run */
    signed char bufNum;                 /* 0x0C buffers in the run */
    unsigned char active;               /* 0x0D */
    char pad0E[2];
} cIDJob;                               /* 0x10 */

typedef struct cIDManager {
    cIDPair pair[0x20];                 /* 0x000 indexed by slot */
    cIDJob job[CIDMGR_JOB_MAX];         /* 0x100 */
    int jobNum;                         /* 0x740 */
    char pool[0x1AE00];                 /* 0x744 */
    int poolUsed;                       /* 0x1B544 buffers handed out */
} cIDManager;

/* The manager in use: D_003C2384 points at the word after the game's own
 * manager (D_003C2388, the cIDManager at D_005CB3B0), which holds it. */
extern cIDManager **D_003C2384;
extern cIDManager *D_003C2388;

extern char D_0044AF70[];               /* name table SearchData looks in */
extern void *SearchData(void *name, void *table, int which);
extern void *func_003A52F0(void *dst, int val, int len);  /* memset */
int cIDManager_getTexAddr(cIDManager *self, int slot, unsigned int idx);
void cIDManager_setIDData(cIDManager *self, int slot, void *data);
int cIDManager_getLocalFileName(void *a0, void *a1, void *a2, signed char a3);
/* Take a run of n pool buffers, cleared, under a new job. 0 when the pool is short. */
void *cIDManager_allocBufRun(cIDManager *self, int n, int tag, int arg);
/* Give back the last run if it is `buf` and was taken under `tag`; `arg` is not read. 1 on success. */
int func_002ACF30(cIDManager *self, void *buf, int tag, int arg);

#endif
