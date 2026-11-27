/* include/godhand/cEmLinked.h - an enemy that can be pushed along by a linked object. */
#ifndef GODHAND_CEMLINKED_H
#define GODHAND_CEMLINKED_H

#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"

#define EMLINK_MODE_FREE  0x100         /* no usable link */
#define EMLINK_MODE_HELD  0x500         /* pushed along by the link */

/* The push step's work (func_00104010): the tracked points and the part each rides on. */
typedef struct cEmLinkStep {
    unsigned int num;                   /* 0x00 tracked points */
    unsigned char *part;                /* 0x04 part index of each point */
    char unk08[0x30];
    int kind;                           /* 0x38 0 at init; the SetParent methods set a per-class value */
    char unk3C[0x18];
    cOmBase **parts;                    /* 0x54 part list, or 0 for the object's children */
    cGameObj *parent;                   /* 0x58 the link, also kept in cEmLinked.link */
} cEmLinkStep;

/* One tracked point (func_00107C68): its offset in the part and its world position. */
typedef struct cPtRec {
    cVec local;                         /* 0x00 point in the part's space */
    char unk10[0x20];
    cVec vel;                           /* 0x30 */
    cVec pos;                           /* 0x40 world point */
    cVec prev;                          /* 0x50 world point last frame */
    char unk60[0x40];
} cPtRec;

typedef struct cEmLinked {
    cEm00 base;                         /* 0x0000 */
    char unk1870[0x2130 - 0x1870];
    cEmLinkStep work;                   /* 0x2130 step work */
    int mode;                           /* 0x218C EMLINK_MODE_* */
    cVec push;                          /* 0x2190 */
    char unk21A0[0x10];
    cGameObj *link;                     /* 0x21B0 */
    int linkChild;                      /* 0x21B4 child of the link this enemy hangs from */
} cEmLinked;

typedef char cEmLinkStep_size_check[(sizeof(cEmLinkStep) == 0x5C) ? 1 : -1];
typedef char cPtRec_size_check[(sizeof(cPtRec) == 0xA0) ? 1 : -1];

/* Runs the push step: the step work and the model it moves. */
void func_00104010(void *self, void *work, void *model);
/* Snap each of work's points in rec to its part: world position from the part's matrix,
 * the previous position set to it and the velocity cleared. */
void func_00107C68(cOmBase *self, cEmLinkStep *work, cPtRec *rec);
/* Point the push along the heading of the link's child 2 (or of the link), then run the step. */
void func_00283AA8(cEmLinked *self);
/* Runs the push step on the enemy's model. */
void func_002844A0(cEmLinked *self);

/* Hang the enemy's first child from child idx of parent and link the enemy to it. */
void cEm12_SetParent(cEmLinked *self, cGameObj *parent, int idx);
void cEm53_SetParent(cEmLinked *self, cGameObj *parent, int idx);
void cEm57_SetParent(cEmLinked *self, cGameObj *parent, int idx);
void func_00283BE8(cEmLinked *self, cGameObj *parent, int idx);
void func_002844C0(cEmLinked *self, cGameObj *parent, int idx);

#endif
