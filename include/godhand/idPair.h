/* include/godhand/idPair.h - the message banner: two cIDBase parts and two short message queues
 * (sn code from 0x1467E8). */
#ifndef GODHAND_IDPAIR_H
#define GODHAND_IDPAIR_H

#include "godhand/cIDBase.h"

#define IDPAIR_WORK_NUM  4

/* A banner display with two cIDBase parts, at 0 and 0xA0, and two short message queues. */
typedef struct IdPair {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0x79 - 0x48];
    signed char state[4];               /* 0x79 state[0] is the banner step; IdPair_init clears all four */
    char unk7D[0x90 - 0x7D];
    cIDBaseEnt *work[IDPAIR_WORK_NUM];  /* 0x90 the entries of the part on show */
    cIDBaseObj part2;                   /* 0xA0 */
    char unkE8[0xF0 - 0xE8];
    unsigned short msgQueue[4];         /* 0xF0 */
    unsigned short altQueue[4];         /* 0xF8 nonzero: the second part is shown */
    short count;                        /* 0x100 queued messages */
    short timer;                        /* 0x102 */
    unsigned char flags;                /* 0x104 IDPAIR_FLAG_* */
} IdPair;

#define IDPAIR_FLAG_LOW  0x01           /* flags: entry 0 stops 50 lower */
#define IDPAIR_SHOW_TIME 0x5A           /* frames the queued message stays up */

void IdPair_init(IdPair *self);

#endif /* GODHAND_IDPAIR_H */
