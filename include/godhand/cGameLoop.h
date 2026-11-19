/* include/godhand/cGameLoop.h - the game loop object D_005CAC90: its mode
 * byte and the stage path lines and points.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_CGAMELOOP_H
#define GODHAND_CGAMELOOP_H

#include "godhand/cOmBase.h"

/* One point of the stage path lines. */
typedef struct PathLinePt {
    cVec pos;                           /* 0x00 */
    char unk10[0x10];
} PathLinePt;                           /* 0x20 */

/* One line between two path points. Bit 31 of flags turns the line off
 * unless bit 30 is set too. */
typedef struct PathLine {
    unsigned short a;                   /* 0x0 first point */
    unsigned short b;                   /* 0x2 second point */
    char unk4[0x4];
    int flags;                          /* 0x8 */
} PathLine;                             /* 0xC */

/* The stage path lines kept by the game loop object. */
typedef struct PathLineSet {
    char unk0[0x4];
    PathLine *lines;                    /* 0x04 */
    int lineNum;                        /* 0x08 */
    PathLinePt *pts;                    /* 0x0C */
    int ptNum;                          /* 0x10 */
} PathLineSet;

/* The game loop object: its mode byte and the path lines. */
typedef struct cGameLoop {
    unsigned char mode;                 /* 0x000 */
    char unk001[0x18B];
    PathLineSet lines;                  /* 0x18C */
} cGameLoop;

extern cGameLoop D_005CAC90;

/* Point i of the set, or 0 when i is out of range. */
static __inline__ PathLinePt *PathLineSet_point(PathLineSet *set, int i)
{
    long in = 0;

    if (i > -1) {
        int below = i < set->ptNum;

        in = below;
    }
    if ((in & 0xFF) == 0) {
        return 0;
    }
    return &set->pts[i];
}

#endif /* GODHAND_CGAMELOOP_H */
