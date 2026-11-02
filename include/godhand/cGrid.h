/* include/godhand/cGrid.h - a uniform grid over an axis-aligned box (sn code at 0x12F288..0x133948).
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_CGRID_H
#define GODHAND_CGRID_H

#include "godhand/cOmBase.h"
#include "godhand/cModel.h"

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
    unsigned short unk0;                /* 0x0 picks the debug outline's colour */
    unsigned short kind;                /* 0x2 tested against cGrid.mask */
    int attr;                           /* 0x4 skipped when it shares a bit with cGrid.exclude */
    unsigned short unk8;                /* 0x8 0xFFFF after the body's constructor copies the face */
    unsigned char unkA;                 /* 0xA cleared by the constructor */
    unsigned char unkB;                 /* 0xB cleared by the constructor */
    char unkC[4];
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
    int id;                             /* 0x30 the owner object's address, stored by the constructors */
    char unk34[0x20];                   /* 0x34 cleared */
    int unk54;                          /* 0x54 cleared */
    int param;                          /* 0x58 the constructor's flags argument */
    const void *vt;                     /* 0x5C method table of the body type */
    cVec pos;                           /* 0x60 copy of the owner's position */
    cVec unk70;                         /* 0x70 */
    cVec rot;                           /* 0x80 copy of the owner's rotation */
    cVec unk90;                         /* 0x90 */
    union {
        struct {
            char unkA0[8];
            cCollFace face;             /* 0xA8 */
            char unkB8[8];
            cVec corner[4];             /* 0xC0 */
        } quad;
        struct {
            cVec extent;                /* 0xA0 the size argument, each axis made positive */
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

/* Method tables of the base body and of the box body. */
extern char D_0041D5A8[];
extern char D_0041D558[];

/* 1 << n for n = 0..31; the quad and box debug draws copy it to the stack. */
typedef struct cBitMasks {
    int bit[32];
} cBitMasks;

extern const cBitMasks D_0041D2E0;

/* Debug draw of a quad body's outline, and with fill set its face filled. */
void func_0012D3C8(cCollBody *self, int mode, int fill);

/* Debug draw of pts[0..2], or pts[0..3] when quad is set, filled in one colour. */
void func_001334A8(cVec *pts, int quad, int color);

cCollBody *func_0012D970(cCollBody *self, cModel *owner, int param, cVec *v70, cVec *v90,
                         cVec *size, cCollFace *f0, cCollFace *f1, cCollFace *f2,
                         cCollFace *f3, cCollFace *f4, cCollFace *f5);

#endif /* GODHAND_CGRID_H */
