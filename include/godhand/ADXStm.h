/* include/godhand/ADXStm.h - the ADX stream object (ADXSTM, CRI).
 *
 * An ADXSTM reads a source through a stream joint (SJ) in 0x800-byte
 * sectors. ADXSTMF_SetupHandleMember fills it in between the lock and unlock
 * trampolines. Names are ours, from CRI's ADXSTM. Offsets are exact. A field
 * we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_ADXSTM_H
#define GODHAND_ADXSTM_H

#include "godhand/criSj.h"

#define ADXSTM_SECTOR_SIZE  0x800
#define ADXSTM_SECTOR_SHIFT 11

/* ADXStm.stat */
#define ADXSTM_STAT_EOF     3
#define ADXSTM_STAT_ERR     4

/* ADXStm.limit when no sector limit is set. */
#define ADXSTM_NO_LIMIT     0xFFFFF

/* One of the pool of ADX streams (0x60 bytes each, from D_003D04D0). */
typedef struct ADXStm {
    Sint8 used;                 /* 0x00 */
    Sint8 stat;                 /* 0x01 */
    Sint8 reading;              /* 0x02 1 while a read request is out */
    Sint8 unk03;
    SjObj *sj;                  /* 0x04 */
    int *fd;                    /* 0x08 the cvFs handle */
    int ofst;                   /* 0x0C first sector of the source in the file */
    int size;                   /* 0x10 source size in bytes */
    int nsct;                   /* 0x14 size in sectors, rounded up */
    int ndata0;                 /* 0x18 bytes asked of the SJ for each read */
    int ndata1;                 /* 0x1C a read starts only while the SJ holds fewer bytes */
    int reqsct;                 /* 0x20 sectors the pending read asked for */
    SjChunk ck;                 /* 0x24 the SJ chunk the pending read fills */
    int sctsize;                /* 0x2C most sectors read at a time */
    int nsct2;                  /* 0x30 the sector that runs the end callback */
    unsigned int rdbytes;       /* 0x34 bytes read so far */
    void (*eosfn)(void *obj, int sct);  /* 0x38 */
    void *eosobj;               /* 0x3C */
    int ndata2;                 /* 0x40 the SJ's size in bytes */
    Sint8 unk44;                /* 0x44 */
    char unk45[0x48 - 0x45];
    Sint8 unk48;                /* 0x48 */
    char unk49[0x4C - 0x49];
    int retry;                  /* 0x4C read errors in a row */
    char unk50[0x58 - 0x50];
    int cursct;                 /* 0x58 sectors read so far */
    unsigned int limit;         /* 0x5C last sector to read, or ADXSTM_NO_LIMIT */
} ADXStm;
typedef char ADXStm_size_check[(sizeof(ADXStm) == 0x60) ? 1 : -1];

extern int D_003D04C8;          /* read errors before a stream gives up; negative retries forever */
extern int D_003D8498;
extern Sint8 D_003D849C;

/* Count a read that found no SJ to read into (adds one to D_003D04CC). */
int Obj0000_PostInc_D_003D04CC_3284A0(void);
/* One step of a stream's read: hand a finished read to the SJ, then start the next. */
void adxstmf_stat_exec(ADXStm *stm);

#endif /* GODHAND_ADXSTM_H */
