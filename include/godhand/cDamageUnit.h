/* include/godhand/cDamageUnit.h - cDamageUnit, the damage hit volumes of one actor.
 *
 * The unit keeps a singly linked list of nodes at 0x3C. Each node carries a
 * numeric id and points at a data record whose word at 0x34 is the
 * cCollisionShape. Methods walk the list and either touch every node
 * (SetDamageCollActive, SetDamageCollOffset) or look one up by id
 * (SetDamageCollRadius). The shape's virtual call uses the g++ 2.x
 * delta/index/pfn table entry. Offsets are exact; unknown spans stay unkNNN.
 */
#ifndef GODHAND_CDAMAGEUNIT_H
#define GODHAND_CDAMAGEUNIT_H

#include "godhand/cOmBase.h"
#include "godhand/keySlot.h"

typedef struct cDamageVtEnt {
    short delta;                /* added to this before the call */
    short index;
    void *pfn;
} cDamageVtEnt;

typedef struct cCollisionShape {
    char unk000[0x100];
    cDamageVtEnt *vt;           /* 0x100 */
} cCollisionShape;

typedef struct cDamageData {
    int flags;                  /* 0x00 bit 1 = active */
    char unk04[0x10];
    KeySlot keys[KEYSLOT_NUM];  /* 0x14 key 1 holds its cDamageTake */
    cCollisionShape *shape;     /* 0x34 */
} cDamageData;

typedef struct cDamageNode {
    cVec pos;                   /* 0x00 centre of the volume */
    char unk10[0x14];
    struct cDamageNode *next;   /* 0x24 */
    cDamageData *data;          /* 0x28 */
    short id;                   /* 0x2C */
    unsigned char used;         /* 0x2E nonzero while the node is taken from its pool */
    char unk2F[0x40 - 0x2F];
} cDamageNode;                  /* 0x40 */

typedef struct cDamageUnit {
    char unk00[0x3C];
    cDamageNode *nodes;         /* 0x3C list head, 0 when empty */
} cDamageUnit;

/* The two volume node pools (func_001FE5A8 and func_001FE660 take the first unused node). */
extern cDamageNode D_00569B80[160];
extern cDamageNode D_0056C380[512];

#define CDAMAGE_SHAPE_SETRADIUS  3      /* vt[3] of cCollisionShape */
#define CDAMAGE_SHAPE_GETPOS     8      /* vt[8]: returns the shape's position */
#define CDAMAGE_KEY_TAKE         1      /* cDamageData.keys: the volume's cDamageTake */

/* Stores the unit's active flag and copies the resulting hit state to every node's shape. */
void func_001FD988(cDamageUnit *self, unsigned char active);

/* Copies up to max of the active volumes touching node's volume into out, in ascending key order. */
void func_001FC810(cDamageNode *node, cDamageData **out, unsigned short max);


/* Moves the hit volume of every node by the given offset. */
void cDamageUnit_SetDamageCollOffset(cDamageUnit *self, void *offset);

/* Sets the radius of the node with the given id. */
void cDamageUnit_SetDamageCollRadius(cDamageUnit *self, int id, float radius);

#endif
