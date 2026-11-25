/* include/godhand/cObjBaseFn.h - cObjBase methods more than one unit calls.
 *
 * cObjBase.h holds the rest. Older units declare these themselves with their own
 * types, so the prototypes live here for the units that take them from a
 * header.
 */
#ifndef GODHAND_COBJBASEFN_H
#define GODHAND_COBJBASEFN_H

#include "godhand/cObjBase.h"

void cObjBase_KageInit(struct cObjBase *self, char *work, void *shadowData);
/* Draw the object's shadow. */
void cObjBase_KageDraw(struct cObjBase *self);
/* Run the object's scenario step. */
void cObjBase_R0_scenario(struct cObjBase *self);
/* cObjBase's own method table, which its destructor stores at 0x214. */
extern cVtEnt D_0041EBE8[];

#endif /* GODHAND_COBJBASEFN_H */
