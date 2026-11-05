/* include/godhand/cNode.h - cNode, one node of the scene graph.
 *
 * A node keeps a name, links to its parent, first child and the two
 * neighbouring siblings, a local scale, a local translation and rotation,
 * and two 4x4 matrices: the local one at 0x50 and the world one at 0xB0.
 * The constructor gives both matrices the identity and attaches the node to
 * its parent. The method table sits at the end of the known part.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field nobody has named yet stays as unkNN padding. The object
 * size is not known, so there is no size check, only the offsets below.
 */
#ifndef GODHAND_CNODE_H
#define GODHAND_CNODE_H

#include "godhand/cOmBase.h"

typedef struct cNode {
    int name;                           /* 0x00 */
    struct cNode *parent;               /* 0x04 */
    struct cNode *child;                /* 0x08 first child */
    struct cNode *prev;                 /* 0x0C previous sibling */
    struct cNode *next;                 /* 0x10 next sibling */
    unsigned char flagA;                /* 0x14 */
    unsigned char flagB;                /* 0x15 */
    unsigned char flagC;                /* 0x16 */
    char unk17[9];
    cVec scale;                         /* 0x20 local scale, 1.0 at construction */
    cVec rot;                           /* 0x30 local rotation, cleared at construction */
    cVec trans;                         /* 0x40 local translation, cleared at construction */
    char matLocal[0x40];                /* 0x50 local matrix */
    int unk90;                          /* 0x90 cleared at construction */
    char unk94[0xC];
    char unkA0[0x10];                   /* 0xA0 cleared at construction */
    char matWorld[0x40];                /* 0xB0 world matrix */
    void *vt;                           /* 0xF0 method table */
} cNode;

/* The node's parent. */
cNode *func_002B5E50(cNode *self);
/* Unlink the node from its parent's child list and clear its links. */
void func_002B5EC0(cNode *self);
/* Attach a node that has no parent as parent's last child. With parent 0,
 * detach the node and keep its world scale, rotation and translation as its
 * local ones. A node that already has a parent is left where it is. */
void func_002B5D58(cNode *self, cNode *parent);
/* Hand the node's children to parent, then unlink the node. */
void func_002B5CF0(cNode *self, cNode *parent);
/* The number of children. */
int func_002B5E58(cNode *self);
/* Child n, counted from the first. */
cNode *func_002B5E90(cNode *self, int n);
/* Nonzero when any unk90 flag is set. */
int func_002B6510(cNode *self);
/* Clear the active flag of an active node and of its active descendants. */
void cNode_clearActiveRecursive(cNode *self);
/* The number of children. */
int func_002B5E58(cNode *self);
/* Child n, counted from the first. */
cNode *func_002B5E90(cNode *self, int n);
/* Nonzero when any unk90 flag is set. */
int func_002B6510(cNode *self);
/* Clear the active flag of an active node and of its active descendants. */
void cNode_clearActiveRecursive(cNode *self);

/* Clear flagC, then the active flags of the node and its active descendants. */
void func_002B6400(cNode *self);
/* Set the local scale, rotation or translation to v's x, y and z, after
 * clearing the node's active flags. */
void cNode_setLocalScale(cNode *self, cVec *v);
void func_002B6230(cNode *self, cVec *v);
void cNode_setLocalTranslation(cNode *self, cVec *v);
/* Bring the world matrix up to date: the parent's world matrix times the
 * local one, or the local one for a root. */
void cNode_updateWorldMatrix(cNode *self);
/* *dst = the node's world scale or rotation, read from the updated world
 * matrix. They return dst. */
cVec *func_002B6080(cVec *dst, cNode *self);
cVec *func_002B60D0(cVec *dst, cNode *self);
/* The updated world matrix. */
float *CallThenReturnPlusB0_002B6420_2B61B0(cNode *self);

/* Sets the node's local translation to pos minus its parent's world position. */
void cNode_setTranslationFromParent(void *self, cVec *pos);

/* cNode's destructor: put back cNode's method table, then free the node
 * when flags bit 0 is set. Retail has three copies of it. */
void func_002B6568(cNode *self, int flags);
void func_002FBDD8(cNode *self, int flags);
void func_003028E8(cNode *self, int flags);
/* Destructor of the cNode subclass whose method table is D_0044FAD0. */
void func_002FBE28(cNode *self, int flags);
/* Destructor of the cNode subclass that owns six heap blocks (001468b0.c). */
struct BlockOwner;
void BlockOwner_dtor(struct BlockOwner *self, int flags);

#endif
