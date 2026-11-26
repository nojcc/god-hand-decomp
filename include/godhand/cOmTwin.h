/* include/godhand/cOmTwin.h - cOmTwin, a cOmBase object that owns a damage-take volume and two
 * helper objects of kind 0x3B6 (sn code at 0x1B57E8).
 *
 * The setup routine creates the two helpers, clears bit 31 of their state word (0x62C), makes
 * the damage-take box and cuts children 1 to 5 loose from the local and parent transforms.
 * Offsets are exact; unknown spans stay unkNNN padding.
 */
#ifndef GODHAND_COMTWIN_H
#define GODHAND_COMTWIN_H

#include "godhand/cOmBase.h"
#include "godhand/cGameObj.h"
#include "godhand/cDamageUnit.h"

#define COMTWIN_KIND            0x3B6
#define COMTWIN_PART_LIVE       0x80000000      /* part state word bit cleared at setup */
#define COMTWIN_MAX_CHILDREN    6

/* A helper object as the setup sees it: a cGameObj with a state word. */
typedef struct cOmTwinPart {
    cGameObj base;                      /* 0x000 */
    char unk5B0[0x62C - 0x5B0];
    unsigned int state;                 /* 0x62C */
} cOmTwinPart;

typedef struct cOmTwin {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    cDamageTake *damageTake;            /* 0x600 damage-take volume, 0 when none */
    cOmTwinPart *partA;                 /* 0x604 first helper object */
    cOmTwinPart *partB;                 /* 0x608 second helper object */
} cOmTwin;

#endif
