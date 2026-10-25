/* include/godhand/cEmLinked.h - an enemy that rides on a linked object.
 *
 * A linked enemy follows a part of another object (the link): the SetParent
 * methods (cEm12_SetParent and its siblings in 00276e90.c) store the link
 * and the number of its child part, and hang the enemy's first child on
 * that part. Each frame the enemy is pushed along by the link or copies its
 * position, then runs its step work.
 */
#ifndef GODHAND_CEMLINKED_H
#define GODHAND_CEMLINKED_H

#include "godhand/cEm00.h"

#define EMLINK_MODE_FREE  0x100         /* no usable link */
#define EMLINK_MODE_HELD  0x500         /* pushed along by the link */

typedef struct cEmLinked {
    cEm00 base;                         /* 0x0000 */
    char unk1870[0x2130 - 0x1870];
    char work[0x5C];                    /* 0x2130 step work */
    int mode;                           /* 0x218C EMLINK_MODE_* */
    cVec push;                          /* 0x2190 */
    char unk21A0[0x10];
    cEm00 *link;                        /* 0x21B0 the object this enemy rides on, or 0 */
    int linkPart;                       /* 0x21B4 number of the link's child the enemy hangs on */
} cEmLinked;

#endif /* GODHAND_CEMLINKED_H */
