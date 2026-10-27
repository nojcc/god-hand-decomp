/* include/godhand/cGrid.h - a uniform grid over an axis-aligned box (sn code at 0x12F288..0x133948).
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_CGRID_H
#define GODHAND_CGRID_H

#include "godhand/cOmBase.h"

typedef struct cGrid {
    char unk00[0x30];
    cVec min;                           /* 0x30 */
    cVec max;                           /* 0x40 */
    cVec cell;                          /* 0x50 cell size */
    unsigned int num[3];                /* 0x60 cells per axis */
    int lo[3];                          /* 0x6C first cell the query box covers */
    int hi[3];                          /* 0x78 last cell */
    char unk84[0xC];
    cVec boxMin;                        /* 0x90 query box */
    cVec boxMax;                        /* 0xA0 */
    char unkB0[0x20];
    cVec dir;                           /* 0xD0 segment direction: faces turned towards it are skipped */
    cVec from;                          /* 0xE0 segment start */
    cVec to;                            /* 0xF0 segment end */
    char unk100[0x20];
    cVec hitPos;                        /* 0x120 nearest hit point */
    cVec hitNormal;                     /* 0x130 its face normal */
    int room;                           /* 0x140 free entries left in hitFaces */
    char unk144[0x30];
    int mask;                           /* 0x174 face kinds tested */
    int exclude;                        /* 0x178 face attributes skipped */
    int hitCount;                       /* 0x17C entries in hitFaces */
    unsigned char hit;                  /* 0x180 */
    unsigned char single;               /* 0x181 keep one hit and end the segment at the nearest */
    char unk182[2];
    float dist;                         /* 0x184 squared distance of the last hit from the start */
    float best;                         /* 0x188 squared distance of the nearest hit */
    struct cCollFace **hitFaces;        /* 0x18C */
    struct cCollBody *bodies;           /* 0x190 */
} cGrid;

/* One face of a collision body. */
typedef struct cCollFace {
    char unk0[2];
    unsigned short kind;                /* 0x2 tested against cGrid.mask */
    int attr;                           /* 0x4 skipped when it shares a bit with cGrid.exclude */
    char unk8[8];
} cCollFace;

#define CCOLLBODY_QUAD  1               /* one four-cornered face */
#define CCOLLBODY_BOX   2               /* six faces over eight corners */

/* A collision body in the grid's list. */
typedef struct cCollBody {
    struct cCollBody *next;             /* 0x00 */
    int type;                           /* 0x04 CCOLLBODY_* */
    unsigned int flags;                 /* 0x08 bit 0: active */
    char unk0C[4];
    cVec min;                           /* 0x10 bounds */
    cVec max;                           /* 0x20 */
    int id;                             /* 0x30 */
    char unk34[0x6C];
    union {
        struct {
            char unkA0[8];
            cCollFace face;             /* 0xA8 */
            char unkB8[8];
            cVec corner[4];             /* 0xC0 */
        } quad;
        struct {
            char unkA0[0x10];
            cCollFace face[6];          /* 0xB0 */
            cVec corner[8];             /* 0x110 */
        } box;
    } u;                                /* 0xA0 */
} cCollBody;

/* Corner order of a quad body's face, and of each face of a box body. */
extern int D_0041D630[4];
extern int D_0041D640[6][4];

extern void func_00133948(void *self, void *boxMin, void *boxMax);
extern int func_00133408(void *unused, float *min, float *max, float *boxMin, float *boxMax);

#endif /* GODHAND_CGRID_H */
