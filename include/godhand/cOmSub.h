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

typedef struct cOmSub {
    unsigned char mode;                 /* 0x00 cleared by setReverse */
    unsigned char reverse;              /* 0x01 1 while the path runs backwards */
    unsigned char type;                 /* 0x02 index into the move table */
    char unk03;
    void *obj;                          /* 0x04 the object the record is bound to */
    void *ent;                          /* 0x08 the entry of obj it follows */
    void *part[COMSUB_PART_COUNT];      /* 0x0C model parts to recompute, 0 ends a slot */
    char unk2C[0x70 - 0x2C];
    cVec posA;                          /* 0x70 the two base points */
    cVec posB;                          /* 0x80 */
    cVec moveA;                         /* 0x90 how far each point travels */
    cVec moveB;                         /* 0xA0 */
    cVec startA;                        /* 0xB0 where the walk starts */
    cVec startB;                        /* 0xC0 */
    cVec goalA;                         /* 0xD0 where it ends */
    cVec goalB;                         /* 0xE0 */
    char unkF0[0x130 - 0xF0];
    float curA;                         /* 0x130 current pair */
    float curB;                         /* 0x134 */
    float endA;                         /* 0x138 end pair */
    float endB;                         /* 0x13C */
} cOmSub;

#endif
