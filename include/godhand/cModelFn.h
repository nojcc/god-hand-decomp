/* include/godhand/cModelFn.h - cModel methods more than one unit calls.
 *
 * cModel.h holds the record. Older units declare these themselves with their
 * own parameter types (void pointers, mostly), so the prototypes live here
 * for the units that take them from a header.
 */
#ifndef GODHAND_CMODELFN_H
#define GODHAND_CMODELFN_H

#include "godhand/cModel.h"

void cModel_calcParts(struct cModel *self);
void cModel_calcWorldParts(struct cModel *self);
void cModel_calcNullPart(struct cModel *self);
cModelNode *cModel_getMeshPtr_14B730(struct cModel *self, char *name);

/* The model's part of the destructor: put cModel's method table back, free
 * the packet block, drop the meshes and parts, then run the base part. */
void cModel_destroy(cModel *self, int flags);

#endif /* GODHAND_CMODELFN_H */
