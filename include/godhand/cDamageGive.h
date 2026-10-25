/* include/godhand/cDamageGive.h - cDamageGive, the damage an attack hands out.
 *
 * One record per attack volume. The part that matters to the hit code is
 * the hit vector at 0x10: the direction the target is pushed. SetDmgGiveHitVec
 * copies a vector in; SetDmgGiveHitVecDir turns a facing direction into a
 * push direction by rotating the unit Z axis with it.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CDAMAGEGIVE_H
#define GODHAND_CDAMAGEGIVE_H

#include "godhand/cOmBase.h"
#include "godhand/cDamageUnit.h"

struct cGameObj;

typedef struct cDamageGive {
    unsigned int flags;                 /* 0x00 bit 0 is set by the enemy setups */
    char unk04[0xC];
    cVec hitVec;                        /* 0x10 push direction of the hit */
    char unk20[0x10];
    struct cGameObj *owner;             /* 0x30 the object that attacks with it, 0 for none */
    struct cGameObj *lastHit;           /* 0x34 the victim of the last hit handed out */
    struct cGameObj *ignore;            /* 0x38 an object it never hits besides the owner */
    cDamageNode *nodes;                 /* 0x3C its hit volumes, as cDamageUnit.nodes */
    int unk40;                          /* 0x40 cleared by the enemy setups */
    short unk44;                        /* 0x44 */
    short unk46;                        /* 0x46 cleared when the volume is parked; the setups store 0x2E..0x52 (cDamageTake.kind) */
    char unk48[0x4];
    int activeTime;                     /* 0x4C frames the volume stays active, 0 while parked */
} cDamageGive;

/* Copies dir into the hit vector. */
void cDamageGive_SetDmgGiveHitVec(cDamageGive *self, cVec *dir);

#endif
