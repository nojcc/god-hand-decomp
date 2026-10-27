/* include/godhand/cOl40.h - the breakable six-sided object (sn code at 0x1842B0..0x186738).
 *
 * Each side breaks on its own (broken[]); a broken side throws loose pieces
 * that fly off and fall. A hit shakes the object: func_00186598 sets the
 * shake amplitudes from the hit strength, func_00186398 applies them to
 * part 5 and lets them decay. Names are ours. Offsets are exact.
 */
#ifndef GODHAND_COL40_H
#define GODHAND_COL40_H

#include "godhand/cOmBase.h"

/* One loose piece of the object: it flies off with its velocities and falls. */
typedef struct cOl40Piece {
    cVec pos;                           /* 0x00 */
    cVec rot;                           /* 0x10 */
    cVec vel;                           /* 0x20 */
    cVec rotVel;                        /* 0x30 */
    cVec scale;                         /* 0x40 */
    float *mtx;                         /* 0x50 matrix the piece is drawn with */
    unsigned char active;               /* 0x54 GetField_54_173900 / Obj0000_Set_Byte_54 */
    char unk55[3];
    float gravity;                      /* 0x58 */
    char unk5C[4];
} cOl40Piece;

typedef struct cOl40 {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x65C - 0x5E0];
    unsigned char broken[6];            /* 0x65C nonzero once that side is broken */
    char unk662[0x670 - 0x662];
    cOl40Piece piece[20];               /* 0x670 */
    cVec shakePos;                      /* 0xDF0 rest position of the shaken part */
    cVec shakeRot;                      /* 0xE00 rest rotation of the shaken part */
    float shakeY;                       /* 0xE10 height amplitude */
    float shakeRotX;                    /* 0xE14 x rotation amplitude */
    float shakeRotZ;                    /* 0xE18 z rotation amplitude */
    float shakePhase;                   /* 0xE1C 0 or pi at the hit, steps by pi/4 */
} cOl40;

typedef char cOl40_chk[(int)&((cOl40 *)0)->shakePos == 0xDF0 ? 1 : -1];

/* The part the shake moves. */
#define OL40_SHAKE_PART 5

void func_00186398(cOl40 *self);

#endif /* GODHAND_COL40_H */
