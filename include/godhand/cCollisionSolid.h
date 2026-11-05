/* include/godhand/cCollisionSolid.h - cCollisionSolid, one solid collision body.
 *
 * The base constructor (cCollisionSolid) clears the state words, zeroes two
 * vectors, points the vtable word at the base table and sets flag bit 0. The
 * sphere constructor runs it, swaps in the sphere table, stores the owner and
 * fills the centre and the radius. The record is at least 0x74 bytes; its real
 * size is not known.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNN padding.
 */
#ifndef GODHAND_CCOLLISIONSOLID_H
#define GODHAND_CCOLLISIONSOLID_H

#include "godhand/cOmBase.h"

#define CSOLID_STATE_SPHERE  1          /* state: the sphere constructor ran */

struct cGameObj;

#define CSOLID_HIT_MAX       32         /* cCollisionSolidManage.hits */

/* The solid collision manager keeps a list of units, one per owner; each
 * unit holds the owner's solids. */
typedef struct cCollisionSolidVt {
    char unk00[0x18];
    short calcBoundsDelta;              /* 0x18 */
    short pad1A;
    void (*calcBounds)(void *self);     /* 0x1C refresh min/max */
} cCollisionSolidVt;

typedef struct cCollisionSolidBody {
    struct cCollisionSolidBody *next;   /* 0x00 next solid of the unit */
    int kind;                           /* 0x04 CSOLID_KIND_* */
    unsigned int flags;                 /* 0x08 CSOLID_FLAG_* */
    char unk0C[4];
    cVec min;                           /* 0x10 */
    cVec max;                           /* 0x20 */
    cCollisionSolidVt *vt;              /* 0x30 */
} cCollisionSolidBody;

typedef struct cCollisionSolidUnit {
    struct cGameObj *owner;             /* 0x00 */
    cCollisionSolidBody *first;         /* 0x04 */
    int priority;                       /* 0x08 set by CreateUnit and SetPriority */
    float unk0C;                        /* 0x0C */
    struct cCollisionSolidUnit *next;   /* 0x10 */
    char unk14[0xC];
    cVec min;                           /* 0x20 bounds of all its solids */
    cVec max;                           /* 0x30 */
} cCollisionSolidUnit;

typedef struct cCollisionSolidManage {
    cCollisionSolidUnit *first;         /* 0x00 */
    int unitNum;                        /* 0x04 */
    struct cGameObj *hits[CSOLID_HIT_MAX]; /* 0x08 owners hit by the last check */
    unsigned int hitNum;                /* 0x88 */
} cCollisionSolidManage;

/* The solid collision manager. */
extern cCollisionSolidManage D_00462FC0;

/* The unit of owner, or 0. */
cCollisionSolidUnit *func_001346C8(cCollisionSolidManage *self, struct cGameObj *owner);
/* Unit constructor: owner, priority and 0x0C set, no solids, bounds zeroed. */
cCollisionSolidUnit *func_00134430(cCollisionSolidUnit *self, struct cGameObj *owner, int priority, float unk0C);
/* Add a sphere around center, owned by body, at the end of unit's solids. */
void func_00134520(cCollisionSolidUnit *unit, void *body, cVec *center, float radius);
/* Mark every solid of unit active (active == 1) or inactive. */
void SetNodeListFlag_134608(cCollisionSolidUnit *unit, int active);
/* unit->priority = priority. */
void Obj0000_Set_Field_8_134648(cCollisionSolidUnit *unit, int priority);

/* Add a unit for owner at the end of the list, unless it has one. */
void cCollisionSolidManage_CreateUnit(cCollisionSolidManage *self, struct cGameObj *owner, int priority, float unk0C);
/* Add a sphere around center, owned by body, to owner's unit. */
void cCollisionSolidManage_CreateSphere(cCollisionSolidManage *self, struct cGameObj *owner, void *body, cVec *center, float radius);
/* Unlink owner's unit and delete it with its solids. */
void cCollisionSolidManage_ReleaseUnit(cCollisionSolidManage *self, struct cGameObj *owner);
/* Mark every solid of owner's unit active (active == 1) or inactive. */
void cCollisionSolidManage_SetActive(cCollisionSolidManage *self, struct cGameObj *owner, int active);
/* Set the priority of owner's unit. */
void cCollisionSolidManage_SetPriority(cCollisionSolidManage *self, struct cGameObj *owner, int priority);

/* The C function cCollisionSolid is the constructor, so the record type has
 * its own name. */
typedef struct cCollisionSolidObj {
    int unk00;                          /* 0x00 cleared by the base constructor */
    int state;                          /* 0x04 */
    unsigned int flags;                 /* 0x08 bit 0 set by the constructor */
    char unk0C[4];
    cVec unk10;                         /* 0x10 zeroed */
    cVec unk20;                         /* 0x20 zeroed */
    const void *vt;                     /* 0x30 table of the body kind */
    char unk34[0xC];
    void *owner;                        /* 0x40 the object that owns the body */
    char unk44[0xC];
    cVec center;                        /* 0x50 sphere centre, w zeroed */
    cVec unk60;                         /* 0x60 zeroed */
    float radius;                       /* 0x70 sphere radius */
} cCollisionSolidObj;

/* Sphere constructor: base constructor, sphere table, owner, centre, radius. */
cCollisionSolidObj *cCollisionSolid_constructSphere(cCollisionSolidObj *self, void *owner, cVec *center, float radius);

typedef char cCollisionSolid_radius_check[((int)&((cCollisionSolidObj *)0)->radius == 0x70) ? 1 : -1];

/* A box collision body: the solid record, then the eight corners, bottom face first. */
typedef struct cCollisionSolidBox {
    cCollisionSolidObj base;
    char unk74[0xF0 - 0x74];
    cVec corner[8];                     /* 0xF0 0..3 bottom face, 4..7 top face, in order around */
} cCollisionSolidBox;

typedef char cCollisionSolidBox_corner_check[((int)&((cCollisionSolidBox *)0)->corner == 0xF0) ? 1 : -1];

/* Nonzero when obj hits a solid of the manager. */
int cCollisionSolidManage_ChkHit(cCollisionSolidManage *self, struct cGameObj *obj);

/* The line test between two points (assembly); the parameters as its callers pass them. */
int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
            int a7, int a8, int a9, int a10, int a11, int a12);

/* The point of the triangle a b c closest to p, into out. */
void func_00135348(cVec *out, cVec *p, cVec *a, cVec *b, cVec *c);

#endif
