/* include/godhand/cObjGround.h - the ground effect object (esp04).
 *
 * The object places an effect model on the ground or a wall below it. Its
 * set-up (func_002E64B0) copies the settings from its parameter block at
 * 0x110 and checks the effect numbers against the EST data; its step
 * (func_002E6868) follows the ground and fades the model in. Field names
 * are ours; offsets are exact.
 */
#ifndef GODHAND_COBJGROUND_H
#define GODHAND_COBJGROUND_H

#include "godhand/cObjSimple.h"
#include "godhand/cOmBase.h"

#define GROUND_EST_MAGIC  0x545345      /* "EST": first word of a valid effect data block */
#define GROUND_NONE       (-1)          /* cObjGround.gndKind/wallKind: no effect */

/* The low bits of the ground word at 0x2DC. */
typedef struct ObjFlags {
    unsigned char b0 : 1;               /* on the ground */
    unsigned char b1 : 1;
    unsigned char b2 : 1;
} ObjFlags;

/* The object a link at 0x120 points to. */
typedef struct cObjLink {
    char unk00[8];
    float factor;                       /* 0x08 */
    cObjSimple *owner;                  /* 0x0C */
    int flags;                          /* 0x10 LINK_* */
} cObjLink;

/* The parameter block at cObjGround.param. */
typedef struct cObjGroundParam {
    char unk000[0x12E];
    unsigned char modelNo;              /* 0x12E */
    char unk12F[0x13C - 0x12F];
    float ofsX;                         /* 0x13C */
    float ofsY;                         /* 0x140 */
    char unk144[0x16C - 0x144];
    unsigned int groundMode;            /* 0x16C */
    unsigned int wallMode;              /* 0x170 */
    unsigned char disabled;             /* 0x174 */
    char unk175[0x18C - 0x175];
    signed char gndKind;                /* 0x18C */
    unsigned char gndNo;                /* 0x18D */
    signed char wallKind;               /* 0x18E */
    unsigned char wallNo;               /* 0x18F */
    unsigned char fadeInit;             /* 0x190 */
    unsigned char c5;                   /* 0x191 */
    unsigned char c6;                   /* 0x192 */
    char unk193[0x293 - 0x193];
    unsigned char keepAlpha;            /* 0x293 nonzero: don't start at full alpha */
} cObjGroundParam;

/* The object itself: its ground mode, a fade counter and the motion node it syncs. */
typedef struct cObjGround {
    char unk000[0x110];
    cObjGroundParam *param;             /* 0x110 */
    char unk114[0x11C - 0x114];
    unsigned int flags;                 /* 0x11C */
    cObjLink *link;                     /* 0x120 0 when none */
    char unk124[0x188 - 0x124];
    float color[4];                     /* 0x188 copied to the motion node's vec240 and f24C */
    char unk198[0x238 - 0x198];
    short alpha;                        /* 0x238 */
    char unk23A[0x24C - 0x23A];
    unsigned char fadeLen;              /* 0x24C */
    unsigned char fadePos;              /* 0x24D */
    char unk24E[0x2B0 - 0x24E];
    cObjSimple *mot;                    /* 0x2B0 motion node, 0 when none */
    int modelNo;                        /* 0x2B4 */
    char unk2B8[0x2C0 - 0x2B8];
    cVec ofs;                           /* 0x2C0 */
    signed char gndKind;                /* 0x2D0 GROUND_NONE or the ground effect kind */
    unsigned char gndNo;                /* 0x2D1 */
    signed char wallKind;               /* 0x2D2 GROUND_NONE or the wall effect kind */
    unsigned char wallNo;               /* 0x2D3 */
    unsigned int groundMode;            /* 0x2D4 */
    unsigned int wallMode;              /* 0x2D8 */
    unsigned int ground;                /* 0x2DC bit 0 on the ground (read as ObjFlags), bit 2 start the fade */
    char unk2E0[0x2E4 - 0x2E0];
    unsigned char disabled;             /* 0x2E4 */
    unsigned char fadeInit;             /* 0x2E5 fade length, 0 for the default */
    unsigned char c5;                   /* 0x2E6 */
    unsigned char c6;                   /* 0x2E7 */
    float f2E8;                         /* 0x2E8 */
} cObjGround;

#define COBJGROUND_OFS(f) ((int)&((cObjGround *)0)->f)
typedef char cObjGround_chk_mot[COBJGROUND_OFS(mot) == 0x2B0 ? 1 : -1];
typedef char cObjGround_chk_ofs[COBJGROUND_OFS(ofs) == 0x2C0 ? 1 : -1];
typedef char cObjGround_chk_f2E8[COBJGROUND_OFS(f2E8) == 0x2E8 ? 1 : -1];
typedef char cObjGroundParam_chk_keep[((int)&((cObjGroundParam *)0)->keepAlpha) == 0x293 ? 1 : -1];

int func_002E63C0(char *self);

#endif
