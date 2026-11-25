/* include/godhand/cNodeFn.h - cNode methods more than one unit calls, and two cNode subclasses.
 *
 * cNode.h holds the record. Older units declare several of these methods
 * themselves with their own parameter types, so the prototypes live here for
 * the units that take them from a header.
 */
#ifndef GODHAND_CNODEFN_H
#define GODHAND_CNODEFN_H

#include "godhand/cNode.h"

/* A cNode subclass that owns one model at 0x2B0; its destructors
 * (OwnerObj_destroyOwned, OwnerObj_destroyOwned2, HolderObj_destroyOwned)
 * release the model, then run func_002FBE28. */
typedef struct cNodeOwner {
    cNode base;                         /* 0x000 */
    char unkF4[0x2B0 - 0xF4];
    struct cModel *owned;               /* 0x2B0 released with ReleaseObj */
} cNodeOwner;

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

/* cNode's destructor: put back cNode's method table, then free the node
 * when flags bit 0 is set. Retail has three copies of it. */
void func_002B6568(cNode *self, int flags);
void func_002FBDD8(cNode *self, int flags);
void func_003028E8(cNode *self, int flags);
/* Destructor of the cNode subclass whose method table is D_0044FAD0. */
void func_002FBE28(cNode *self, int flags);
/* A cNode subclass that owns six heap blocks; each block's heap handle is
 * stored 0x20 bytes before it. */
typedef struct BlockOwner {
    cNode base;                         /* 0x000 */
    char unkF4[0x2BC - 0xF4];
    int *blockBC;                       /* 0x2BC */
    int *blockC0;                       /* 0x2C0 */
    int *blockC4;                       /* 0x2C4 */
    int *blockC8;                       /* 0x2C8 */
    int *blockCC;                       /* 0x2CC */
    int *blockD0;                       /* 0x2D0 */
} BlockOwner;

/* BlockOwner's destructor: free the six blocks, then run func_002FBE28. */
void BlockOwner_dtor(BlockOwner *self, int flags);

#endif /* GODHAND_CNODEFN_H */
