/* include/godhand/cDamageUnit.h - cDamageUnit, the damage hit volumes of one actor.
 *
 * The unit keeps a doubly linked list of nodes at 0x3C. Each node carries a
 * numeric id and points at a data record whose word at 0x34 is the
 * cCollisionShape. Methods walk the list and either touch every node
 * (SetDamageCollActive, SetDamageCollOffset) or look one up by id
 * (SetDamageCollRadius). The shape's virtual call uses the g++ 2.x
 * delta/index/pfn table entry. Offsets are exact; unknown spans stay unkNNN.
 */
#ifndef GODHAND_CDAMAGEUNIT_H
#define GODHAND_CDAMAGEUNIT_H

#include "godhand/cVecType.h"

/* cDamageGive.type and cDamageUnit.type: which reset ran on the record. The
 * manager's spare records keep 0, and the create calls leave them alone. */
#define CDAMAGE_TYPE_SPARE  0
#define CDAMAGE_TYPE_GIVE   1
#define CDAMAGE_TYPE_TAKE   2

typedef struct cDamageVtEnt {
    short delta;                /* added to this before the call */
    short index;
    void *pfn;
} cDamageVtEnt;

typedef struct cCollisionShape {
    char unk000[0x100];
    cDamageVtEnt *vt;           /* 0x100 */
} cCollisionShape;

#define DAMAGE_FLAG_ACTIVE   2          /* cDamageData.flags */
#define DAMAGE_MASK_INACTIVE 0xFFFFFFFD /* written out: ~2 compiles to a different insn */

typedef struct cDamageData {
    int flags;                  /* 0x00 DAMAGE_FLAG_ACTIVE */
    char unk04[0xC];
    int group;                  /* 0x10 the unit's hit group (func_001FD908) */
    char unk14[0x20];
    cCollisionShape *shape;     /* 0x34 */
} cDamageData;

typedef struct cDamageNode {
    char unk00[0x20];
    struct cDamageNode *prev;   /* 0x20 */
    struct cDamageNode *next;   /* 0x24 */
    cDamageData *data;          /* 0x28 */
    short id;                   /* 0x2C */
    short unk2E;
    short flash;                /* 0x30 set with the flash state */
} cDamageNode;

/* The damage take record (0x70 bytes). A cDamageGive has the same words up
 * to 0x4A (owner, node list, type, live), so the unit methods also take gives. */
typedef struct cDamageUnit {
    char unk00[0x30];
    void *owner;                /* 0x30 the object the manager gave it to */
    int unk34;                  /* 0x34 cleared by the setup and the reset */
    char unk38[0x4];
    cDamageNode *nodes;         /* 0x3C list head, 0 when empty */
    char unk40[0x8];
    signed char kind;           /* 0x48 set with the owner */
    signed char type;           /* 0x49 CDAMAGE_TYPE_* */
    unsigned char live;         /* 0x4A in use */
    char unk4B[0x5];
    const cDamageVtEnt *vt;     /* 0x50 slot CDAMAGE_UNIT_NEWNODE makes a node */
    char unk54[0xC];
    int unk60;                  /* 0x60 cleared by the reset */
    char unk64[0xC];
} cDamageUnit;

typedef char cDamageUnit_size_check[(sizeof(cDamageUnit) == 0x70) ? 1 : -1];

/* Reset the record as a take. */
void ResetObjectFields_1FCDE8(cDamageUnit *self);
/* Unless the record is a spare: owner, kind, live; returns 1. */
int SetTarget_1FD530(cDamageUnit *self, void *owner, int kind);
/* Store kind and give every node's data the new hit group. */
void func_001FD988(cDamageUnit *self, int kind);
/* Unlink and clear every node of the list; 0 when one can't be released. */
int cDvd_releaseAll(cDamageUnit *self);

#define CDAMAGE_SHAPE_SETRADIUS  3      /* vt[3] of cCollisionShape */
#define CDAMAGE_UNIT_NEWNODE     2      /* vt[2] of cDamageUnit */

/* The hit group of the record, from its kind and type. */
int func_001FD908(cDamageUnit *self);
/* Turn the hit volume of every node on (active == 1) or off. */
void cDamageUnit_SetDamageCollActive(cDamageUnit *self, int active);
/* The same for the node with the given id (first match only). */
void cDamageUnit_SetDamageCollActive_1FD610(cDamageUnit *self, int id, int active);
/* Turn every node on (active == 1) or off and store its flash value. */
void cDamageUnit_SetDamageCollFlashActive(cDamageUnit *self, int active, short flash);
/* The same for the node with the given id (first match only). */
void cDamageUnit_SetDamageCollFlashActiveById(cDamageUnit *self, int id, int active, short flash);
/* Step the flash of every node. */
void cDamageUnit_UpdateDamageCollFlash(cDamageUnit *self);
/* Set the radius of the hit volume with the given id (first match only). */
void cDamageUnit_SetDamageCollRadius(cDamageUnit *self, int id, float radius);
/* Move the hit volume of every node by the given offset. */
void cDamageUnit_SetDamageCollOffset(cDamageUnit *self, void *offset);
/* Append a sphere volume at ofs in mtx's space; its id, or -1. */
int cDamageUnit_AddDamageCollSphere(cDamageUnit *self, void *mtx, cVec *ofs, float radius);
/* Append a box volume at ofs in mtx's space; its id, or -1. */
int func_001FD9D8(cDamageUnit *self, void *mtx, cVec *ofs, cVec *rot, cVec *size);
/* Append a cylinder volume from pos along dir; its id, or -1. */
int cDamageUnit_AddDamageCollCylinder(cDamageUnit *self, void *mtx, cVec *pos, cVec *dir, float height, float radius);

#endif
