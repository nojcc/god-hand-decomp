/* include/godhand/cOmSub.h - cOmSub, the move record a map object follows.
 *
 * An object owns one record. initMove1_pos and initMove1_ang bind it to an
 * object (obj) and one of that object's entries (ent) and copy two vectors
 * in. setReverse picks the direction the path is walked and swaps which of
 * the two end values (0x138, 0x13C) is the current pair (0x130, 0x134), then
 * recomputes the model parts: obj first, then the up to eight parts held at
 * 0xC.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_COMSUB_H
#define GODHAND_COMSUB_H

#include "godhand/cOmBase.h"

#define COMSUB_PART_COUNT   8
#define COMSUB_REVERSED     1           /* setReverse argument and state */
#define COMSUB_HOLD         0x2         /* flags: the object and its parts are not moved */
#define COMSUB_SHAKE        0x8         /* flags: push and turn get a random shake */
#define COMSUB_LAND         0x10        /* flags: a fall stops at the start height */

typedef struct cOmSub {
    unsigned char mode;                 /* 0x00 cleared by setReverse */
    unsigned char reverse;              /* 0x01 1 while the path runs backwards */
    unsigned char type;                 /* 0x02 index into the move table */
    unsigned char flags;                /* 0x03 COMSUB_SHAKE: the record shakes */
    void *obj;                          /* 0x04 the object the record is bound to */
    void *ent;                          /* 0x08 the entry of obj it follows */
    struct cGameObj *part[COMSUB_PART_COUNT]; /* 0x0C objects moved with the record, 0 ends a slot */
    float time;                         /* 0x2C time into the move, advanced by the speed rate */
    float length;                       /* 0x30 length of the move */
    char unk34[0x40 - 0x34];
    cVec *target;                       /* 0x40 the point the record moves: ent's 0xD0 or 0xF0 vector */
    char unk44[0x50 - 0x44];
    cVec vel;                           /* 0x50 velocity of a falling record */
    char unk60[0x70 - 0x60];
    cVec posA;                          /* 0x70 the two base points */
    cVec posB;                          /* 0x80 */
    cVec moveA;                         /* 0x90 how far each point travels */
    cVec moveB;                         /* 0xA0 */
    cVec startA;                        /* 0xB0 where the walk starts */
    cVec startB;                        /* 0xC0 */
    cVec goalA;                         /* 0xD0 where it ends */
    cVec goalB;                         /* 0xE0 */
    cVec accel;                         /* 0xF0 acceleration of a falling record */
    char unk100[0x130 - 0x100];
    float curA;                         /* 0x130 current pair */
    float curB;                         /* 0x134 */
    float endA;                         /* 0x138 end pair */
    float endB;                         /* 0x13C */
} cOmSub;

/* A cOmSub with a random shake: its strength fades in over fadeIn, holds,
 * and fades out over the last fadeOut of the move. */
typedef struct cOmSubShake {
    cOmSub base;                        /* 0x000 */
    float fadeIn;                       /* 0x140 */
    float fadeOut;                      /* 0x144 */
    float inAmp;                        /* 0x148 strength while fading in */
    float midAmp;                       /* 0x14C */
    float outAmp;                       /* 0x150 strength while fading out */
} cOmSubShake;

/* A cOmSub that falls under accel and bounces on the start height: each
 * bounce turns the vertical speed round and scales it by bounce. */
typedef struct cOmSubFall {
    cOmSub base;                        /* 0x000 */
    char unk140[0x154 - 0x140];
    float bounce;                       /* 0x154 */
} cOmSubFall;

extern void func_001C7310(cOmSub *self);

#endif
