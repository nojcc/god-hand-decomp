/* include/godhand/cDvd.h - the disc read queue.
 *
 * cDvd owns 32 read jobs of 0x88 bytes each, one running job pointer in front
 * of them, and a counter that hands out job ids. A caller gets an id back from
 * ReadAlloc and later asks Check or CheckWait whether that id is still
 * pending. State 1 on a job means it is queued.
 *
 * Method names come from the retail symbol table. Field names are ours, taken
 * from the methods that read and write them. Offsets are exact. A field we
 * can't name yet stays as unkNN padding.
 */
#ifndef GODHAND_CDVD_H
#define GODHAND_CDVD_H

#define CDVD_JOB_NUM   32

/* One entry of the disc's file table: a directory (child is its first entry)
 * or a file (fileNo is its index; its size in bytes is
 * ((sizeHi << 16) + sizeLo) << 4). */
typedef struct PathNode {
    unsigned char type;                 /* 0x0 1 = directory, 2 = file, 3 = end of list, 0 = none */
    unsigned char sizeHi;               /* 0x1 */
    unsigned short sizeLo;              /* 0x2 */
    char *name;                         /* 0x4 */
    union {
        struct PathNode *child;         /* 0x8 directory: its first entry */
        int fileNo;                     /* 0x8 file: its index on the disc */
    } u;
} PathNode;                             /* 0xC */

typedef struct PathTable {
    PathNode *root;                     /* 0x00 */
    char unk04[0x15];
    char alias[1];                      /* 0x19 */
} PathTable;

extern PathTable D_00580D40;                             /* the disc's file table */

/* The table entry for path, or 0. */
PathNode *func_001FFA68(PathTable *self, const char *path);
/* The file number of name, or -1; its size in bytes goes in *size when size
 * is not 0 (key is not read). */
int FindEntryValue_1FF9C0(PathTable *table, const char *name, int *size, char *key);
/* A file entry's size in bytes (table is not read). */
int BuildPackedAddr_1FFD98(PathTable *table, PathNode *node);
/* The size in bytes of the file at path, 0 when it is missing. */
int GetBuiltPackedAddr_1FFA28(PathTable *table, const char *path);
/* Read the named file into dest and wait for it (table is not read). */
int LoadEntryByValue_1FFD00(PathTable *table, const char *name, void *dest);

typedef struct cDvdJob {
    int state;                          /* 0x00 0 = free, 1 = queued */
    int id;                             /* 0x04 handed back to the caller */
    int fileNo;                         /* 0x08 index of the file on the disc */
    char unk0C[0x60];                   /* 0x0C file lookup key */
    int arg6C;                          /* 0x6C */
    int arg70;                          /* 0x70 */
    int blockNum;                       /* 0x74 size in 0x800-byte blocks */
    int size;                           /* 0x78 size in bytes */
    struct HeapArena *align;            /* 0x7C the arena buf is allocated from */
    void *buf;                          /* 0x80 where the data lands */
    void *heap;                         /* 0x84 owner of buf, 0 if none */
} cDvdJob;                              /* 0x88 */

typedef struct cDvd {
    cDvdJob *cur;                       /* 0x000 job being read, 0 = idle */
    cDvdJob job[CDVD_JOB_NUM];          /* 0x004 */
    int idCounter;                      /* 0x1104 last id handed out */
    int queueNum;                       /* 0x1108 */
} cDvd;

extern cDvdJob *cDvd_takeFreeJob(cDvd *self);            /* take a free job */
extern int func_00201788(cDvd *self);                    /* next job id */
extern void func_00201228(cDvd *self, cDvdJob *job);     /* give a job back */
extern void func_00201290(cDvd *self);                   /* start the next job */
extern void func_00324008(void *heap);                   /* free the heap block */
extern void FreeObjectSlot_2018F0(cDvd *self);

extern cDvd D_00583F20;                                  /* the disc read queue */

/* Queue a read of a named file into a new block from heap; the pointer at
 * outBuf gets the block. Returns the job id, 0 on failure. size, when not 0,
 * overrides the file's size in bytes. */
int cDvd_ReadAlloc(cDvd *self, const char *name, void *outBuf, struct HeapArena *heap, int id, int size, int arg70, int arg6C);
/* cDvd_ReadAlloc that also returns the block's size in *outSize when not 0. */
int cDvd_ReadAllocSized(cDvd *self, const char *name, void *outBuf, struct HeapArena *heap, int id, unsigned int *outSize, int arg70, int arg6C);
/* Queue a read of a named file into buf (rounded up to 0x40). Returns the job id, 0 on failure. */
int cDvd_ReadToBuffer(cDvd *self, const char *name, unsigned int buf, int id, int size, int arg70, int arg6C);
/* Nonzero while the job with the given id is still pending. */
int cDvd_Check(cDvd *self, int id);
/* Wait until the job with the given id is no longer pending. */
void cDvd_CheckWait(cDvd *self, int id);
/* cDvd_Check once a frame until the job is done, then one more frame. */
void cDvd_CheckWaitFrame(cDvd *self, int id);
/* Advance the read queue by one step. */
void cDvd_step(cDvd *self);
/* Drop the job with the given id; nonzero when one was found. */
int cDvd_cancel(cDvd *self, int id);
/* Drop every job, freeing the running one's heap block. */
void cDvd_cancelAll(cDvd *self);
/* Nonzero when the named file is on the disc (self is not read). */
int cDvd_FileExist(cDvd *self, const char *name);

#endif
