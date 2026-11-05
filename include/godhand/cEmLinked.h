/* include/godhand/cEmLinked.h - an enemy that can be pushed along by a linked object. */
#ifndef GODHAND_CEMLINKED_H
#define GODHAND_CEMLINKED_H

#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"

#define EMLINK_MODE_FREE  0x100         /* no usable link */
#define EMLINK_MODE_HELD  0x500         /* pushed along by the link */

/* The push step's work (func_00104010). */
typedef struct cEmLinkStep {
    char unk00[0x38];
    int kind;                           /* 0x38 0 at init; the SetParent methods set a per-class value */
    char unk3C[0x1C];
    cGameObj *parent;                   /* 0x58 the link, also kept in cEmLinked.link */
} cEmLinkStep;

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

/* Runs the push step: the step work and the model it moves. */
void func_00104010(void *self, void *work, void *model);

/* Hang the enemy's first child from child idx of parent and link the enemy to it. */
void cEm12_SetParent(cEmLinked *self, cGameObj *parent, int idx);
void cEm53_SetParent(cEmLinked *self, cGameObj *parent, int idx);
void cEm57_SetParent(cEmLinked *self, cGameObj *parent, int idx);
void func_00283BE8(cEmLinked *self, cGameObj *parent, int idx);
void func_002844C0(cEmLinked *self, cGameObj *parent, int idx);

#endif
