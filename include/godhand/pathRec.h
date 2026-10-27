/* include/godhand/pathRec.h - a path record and the object that follows it
 * (PathHost_calcTurn and the cone factor at 0x137E70).
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_PATHREC_H
#define GODHAND_PATHREC_H

#include "godhand/cOmBase.h"
#include "godhand/cArea.h"

typedef struct PathRec {
    cArea area;                         /* 0x00 where the record applies */
    float holdScale;                    /* 0x30 band scale of the area test while this is the active record */
    float rate;                         /* 0x34 easing rate toward this record's camera pose */
    float endY;                         /* 0x38 */
    char unk3C[2];
    unsigned char priority;             /* 0x3E the lowest wins where areas overlap */
    unsigned char kind;                 /* 0x3F PATH_KIND_* */
    char unk40[0x10];
    char dir[0xC];                      /* 0x50 direction vector, copied with ofsY as one quadword */
    float ofsY;                         /* 0x5C camera height offset for kind 2 */
    float coneAngle;                    /* 0x60 */
    char unk64[0x8];
} PathRec;                              /* 0x6C */

typedef char PathRec_size_check[sizeof(PathRec) == 0x6C ? 1 : -1];

typedef struct PathHost {
    PathRec *recs;                      /* 0x00 0 when the stage has none */
    char unk04[0x8];
    unsigned int recNum;                /* 0x0C */
    float startY;                       /* 0x10 */
    float turn;                         /* 0x14 camera turn when no record is active */
    float rate;                         /* 0x18 easing rate when no record is active */
    float ofsY;                         /* 0x1C camera height offset */
    char unk20[0x10];
    PathRec *rec;                       /* 0x30 the active record, 0 when none */
} PathHost;

/* Turn angle and height toward the active record (kind 1). */
extern void PathHost_calcTurn(PathHost *self, float *turn, float *height, cVec *ref, cVec *target);
/* Makes the record whose area holds pos the active one; 0 when there is none. */
int func_00137BB8(PathHost *self, cVec *pos);

#endif /* GODHAND_PATHREC_H */
