/* include/godhand/cOmScripted.h - a cOmBase object driven by a scripted sequence.
 *
 * The record is a cOmBase (0x5E0 bytes) plus a small tail: the sequence
 * state byte at 0x604, a "finished off" flag at 0x605 and the damage
 * record that cOmBase_checkDamage reads at 0x608.
 *
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_COMSCRIPTED_H
#define GODHAND_COMSCRIPTED_H

#include "godhand/cOmBase.h"

typedef struct cOmScripted {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x24];
    unsigned char seqState;             /* 0x604 OMSCRIPTED_SEQ_* */
    unsigned char dead;                 /* 0x605 set when a hit used up the hp */
    unsigned char rewarded;             /* 0x606 the reward has been given */
    char unk607;
    int hitRecord;                      /* 0x608 damage record for cOmBase_checkDamage */
} cOmScripted;

#define OMSCRIPTED_SEQ_DONE 4
#define OMSCRIPTED_SEQ_RUN  5

void func_001A6AF8(cOmScripted *self);

#endif
