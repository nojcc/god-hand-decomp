/* include/godhand/cFxTrail.h - cFxTrail, an effect node that draws a ribbon behind a moving point (sn code at 0x2EBF98).
 *
 * A trail keeps one point per segment (up to 0x78, 16 by default) and two
 * arrays of 0x40-byte segment records that carry the ribbon's width and
 * end weights. The setup fills every segment with the start point and a
 * width that fades along the trail, and picks the ribbon's two end weights
 * from the direction flags.
 *
 * Field names are ours; offsets are exact. The object size is not known.
 */
#ifndef GODHAND_CFXTRAIL_H
#define GODHAND_CFXTRAIL_H

#include "godhand/cNode.h"

#define FXTRAIL_SEG_MAX      0x78
#define FXTRAIL_SEG_DEF      0x10
#define FXTRAIL_FLIP_A       0x10000000   /* flags: first end weight is -1 */
#define FXTRAIL_FLIP_B       0x08000000   /* flags: second end weight is +1 */
#define FXTRAIL_LIFE_SET     0x2          /* flags2: the trail has a fixed life */

/* The shared trail parameters, seen from the trail node. */
typedef struct FxTrailParam {
    char unk00[0x13C];
    cVec ofs;                           /* 0x13C attach offset, in hundredths */
    char unk14C[0x20];
    int attach;                         /* 0x16C nonzero: follow one of the owner's parts */
    int partIdx;                        /* 0x170 */
    char unk174[0x18];
    unsigned char life;                 /* 0x18C */
    unsigned char segNum;               /* 0x18D */
    signed char fixedLife;              /* 0x18E */
} FxTrailParam;

/* One segment record. */
typedef struct FxTrailSeg {
    char unk00[0x60];
    long k60;                           /* 0x60 */
    long k68;                           /* 0x68 */
    char unk70[0x30];
    int a0;                             /* 0xA0 */
    float fade;                         /* 0xA4 width fade of this segment */
    long k0A8;                          /* 0xA8 */
    char unkB0[0x10];
    float end0;                           /* 0xC0 end weight */
    float end1;                           /* 0xC4 */
    long kC8;                           /* 0xC8 */
    char unkD0[0x10];
} FxTrailSeg;                           /* 0x40 apart, see segStride */

typedef struct cFxTrail {
    cNode base;                         /* 0x000 */
    char unkF4[0x10];
    unsigned int nodeFlags;             /* 0x104 */
    char unk108[8];
    FxTrailParam *param;                /* 0x110 */
    cOmBase *owner;                     /* 0x114 the object whose part the trail follows */
    char unk118[4];
    unsigned int flags;                 /* 0x11C */
    char unk120[0x129];
    signed char segNum;                 /* 0x249 */
    char unk24A[0x72];
    cVec *pts;                          /* 0x2BC one point per segment */
    cVec *pts2;                         /* 0x2C0 second point per segment, at the offset */
    char *segA;                         /* 0x2C4 first segment array, 0x40 apart */
    char *segB;                         /* 0x2C8 second segment array */
    char unk2CC[8];
    float width;                        /* 0x2D4 */
    char unk2D8[8];
    unsigned int flags2;                /* 0x2E0 */
    int life;                           /* 0x2E4 */
    char unk2E8[8];
    cVec ofs;                           /* 0x2F0 attach offset, from the parameters */
    float unk300;                       /* 0x300 1 - the parameter at 0x148 */
    int attach;                         /* 0x304 */
    int partIdx;                        /* 0x308 owner part the trail follows */
} cFxTrail;

typedef char cFxTrail_chk_pts[((int)&((cFxTrail *)0)->pts == 0x2BC) ? 1 : -1];
typedef char cFxTrail_chk_flags[((int)&((cFxTrail *)0)->flags == 0x11C) ? 1 : -1];

#define FXTRAIL_SEG(base, i)  ((FxTrailSeg *)((base) + ((i) << 6)))
#define FXTRAIL_K60   0x3F80000080808080L   /* segment constant at 0x60 */
#define FXTRAIL_K68   1L
#define FXTRAIL_K0A8  2L

/* Allocate the trail's n segments (definition in 001212d0.c); 0 when it fails. */
int func_002EBD10(void *a0, int a1, int n);
/* The node's position moved by add, into out (definition in 002f6258.c). */
void *func_002F6258(void *out, void *node, void *add);

#endif
