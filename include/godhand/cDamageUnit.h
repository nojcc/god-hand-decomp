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

struct cGameObj;

/* cDamageUnit.type: which reset ran on the record. The manager's spare
 * records keep 0, and the create calls leave them alone. */
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

/* The fields a give (cDamageGive, 0x60 bytes) and a take (cDamageTake, 0x70
 * bytes) share, 0x00..0x53: the cDamageUnit head both derive from (the type
 * info registers 11cDamageUnit before 11cDamageGive and 11cDamageTake). The
 * manager runs the same code on both kinds:
 * - The constructors store the vtable at 0x50: D_0042C4D8 for cDamageUnit
 *   (0x1FCE38, 0x1FD3D0), then D_0042C4B8 for a give (0x1FCE58) or
 *   D_0042C498 for a take (0x1FD3F8). g++ 2.x places the vptr after the
 *   members of the first class with virtuals.
 * - ActorRec_reset clears flags, both vectors, owner, unk38, nodes, unk44,
 *   kind, live and power, sets unk40 to -1 and sets unitKind (func_001FD988).
 * - SetObjTargetAndActivate_1FD2C0 and SetTarget_1FD530 read type, then store
 *   owner, clear attacker and set live.
 * - When a give hits a take, func_001FCF20 copies kind, unk40, unk44 and power
 *   from the give to the take, writes the hit's direction and position into
 *   the take, sets bits 0 and 1 of its hitFlags, and stores each side's owner
 *   in the other's attacker.
 * - func_001FDFD8 reads live on both arrays (0x60 and 0x70 strides). */
#define CDAMAGE_UNIT_FIELDS                                                     \
    unsigned int flags;         /* 0x00 bit 0 is set by the enemy setups */     \
    char unk04[0xC];                                                            \
    cVec hitVec;                /* 0x10 push direction of the hit */            \
    cVec unk20;                 /* 0x20 cleared by the reset; a hit's position */ \
    struct cGameObj *owner;     /* 0x30 the object the manager gave it to */    \
    struct cGameObj *attacker;  /* 0x34 the other side's owner in the last hit */ \
    int unk38;                  /* 0x38 cleared by the reset */                 \
    cDamageNode *nodes;         /* 0x3C list head, 0 when empty */              \
    int unk40;                  /* 0x40 -1 after the reset; cleared by the enemy setups */ \
    short unk44;                /* 0x44 */                                      \
    short kind;                 /* 0x46 attack kind: the setups store 0x2E..0x52, 0 when parked */ \
    signed char unitKind;       /* 0x48 set by func_001FD988 */                 \
    signed char type;           /* 0x49 CDAMAGE_TYPE_*, by the record's setup */ \
    unsigned char live;         /* 0x4A in use */                               \
    char unk4B;                                                                 \
    int power;                  /* 0x4C hit strength, 0 when parked */          \
    const cDamageVtEnt *vt      /* 0x50 vtable; slot CDAMAGE_UNIT_NEWNODE makes a node */

/* The head a give and a take share. */
typedef struct cDamageUnit {
    CDAMAGE_UNIT_FIELDS;
} cDamageUnit;                  /* 0x54 */

typedef char cDamageUnit_size_check[(sizeof(cDamageUnit) == 0x54) ? 1 : -1];

/* A take record: what cDamageManage_CreateDamageTake returns and
 * cOmBase_checkDamage (checkDamage__7cOmBaseP11cDamageTake) tests. */
typedef struct cDamageTake {
    CDAMAGE_UNIT_FIELDS;
    char unk54[0x60 - 0x54];
    unsigned int hitFlags;      /* 0x60 bit 0 must be set for the hit to count */
    char unk64[0x70 - 0x64];
} cDamageTake;                  /* 0x70: the manager's take array has a 0x70 stride */

typedef char cDamageTake_size_check[(sizeof(cDamageTake) == 0x70) ? 1 : -1];

/* Reset the record as a take. */
void ResetObjectFields_1FCDE8(cDamageTake *self);
/* Unless the record is a spare: owner, kind, live; returns 1. */
int SetTarget_1FD530(cDamageTake *self, void *owner, int kind);
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
