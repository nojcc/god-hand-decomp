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
} cGrid;

/* One face of a collision body. */
typedef struct cCollFace {
    unsigned short unk0;                /* 0x0 picks the debug outline's colour */
    unsigned short kind;                /* 0x2 face kind bits */
    int attr;                           /* 0x4 face attribute bits */
    unsigned short unk8;                /* 0x8 */
    unsigned char unkA;                 /* 0xA */
    unsigned char unkB;                 /* 0xB */
    char unkC[4];
} cCollFace;                            /* 0x10 */

/* A collision body in the grid's list. */
typedef struct cCollBody {
    struct cCollBody *next;             /* 0x00 */
    int type;                           /* 0x04 */
    unsigned int flags;                 /* 0x08 */
    char unk0C[4];
    cVec min;                           /* 0x10 bounds */
    cVec max;                           /* 0x20 */
    void *owner;                        /* 0x30 the object the body follows */
    char unk34[0x20];                   /* 0x34 cleared */
    int unk54;                          /* 0x54 cleared */
    float *mtx;                         /* 0x58 the owner's matrix */
    const void *vt;                     /* 0x5C method table of the body type */
    cVec pos;                           /* 0x60 */
    cVec unk70;                         /* 0x70 */
    cVec rot;                           /* 0x80 */
    cVec unk90;                         /* 0x90 */
    union {
        struct {
            char unkA0[8];
            cCollFace face;             /* 0xA8 */
            char unkB8[8];
            cVec corner[4];             /* 0xC0 */
        } quad;                         /* a body with one four-cornered face */
        struct {
            cVec extent;                /* 0xA0 the size argument, each axis made positive */
            cCollFace face[6];          /* 0xB0 */
            cVec corner[8];             /* 0x110 */
        } box;                          /* a box: six faces over eight corners */
    } u;                                /* 0xA0 */
} cCollBody;

#define CCOLLBODY_BOX   2               /* cCollBody.type of a box body */

/* Method tables of the base body and of the box body. */
extern unsigned char D_0041D5A8[];
extern unsigned char D_0041D558[];

/* Construct a box body for owner (its position and rotation copied, mtx its
 * matrix) with the two vectors, the size and the six faces. */
cCollBody *func_0012D970(cCollBody *self, cModel *owner, float *mtx, cVec *v70, cVec *v90,
                         cVec *size, cCollFace *f0, cCollFace *f1, cCollFace *f2,
                         cCollFace *f3, cCollFace *f4, cCollFace *f5);

/* 1 << n for n = 0..31; the quad debug draw copies it to the stack. */
typedef struct cBitMasks {
    int bit[32];
} cBitMasks;

extern const cBitMasks D_0041D2E0;

/* Debug draw of a quad body's outline, and with fill set its face filled. */
void func_0012D3C8(cCollBody *self, int mode, int fill);

/* Debug draw of pts[0..2], or pts[0..3] when quad is set, filled in one colour. */
void func_001334A8(cVec *pts, int quad, unsigned int color);

extern void func_00133948(void *self, void *boxMin, void *boxMax);
extern int func_00133408(void *unused, float *min, float *max, float *boxMin, float *boxMax);

#endif /* GODHAND_CGRID_H */
