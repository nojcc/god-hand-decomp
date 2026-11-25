/* include/godhand/cDamageUnitFn.h - cDamageUnit methods more than one unit calls.
 *
 * cDamageUnit.h holds the records. Older units declare these themselves with
 * their own types, so the prototypes live here for the units that take them
 * from a header.
 */
#ifndef GODHAND_CDAMAGEUNITFN_H
#define GODHAND_CDAMAGEUNITFN_H

#include "godhand/cDamageUnit.h"

/* cDamageUnit_SetDamageCollActive for the node with the given id (first match only). */
void cDamageUnit_SetDamageCollActive_1FD610(cDamageUnit *self, int id, int active);
/* Turn every node on (active == 1) or off and store its flash value. */
void cDamageUnit_SetDamageCollFlashActive(cDamageUnit *self, int active, short flash);
/* cDamageUnit_SetDamageCollActive for the node with the given id (first match only). */
void cDamageUnit_SetDamageCollFlashActiveById(cDamageUnit *self, int id, int active, short flash);
/* Step the flash of every node. */
void cDamageUnit_UpdateDamageCollFlash(cDamageUnit *self);
/* Set the radius of the hit volume with the given id (first match only). */
void cDamageUnit_SetDamageCollRadius(cDamageUnit *self, int id, float radius);
/* Move the hit volume of every node by the given offset. */
void cDamageUnit_SetDamageCollOffset(cDamageUnit *self, void *offset);

#endif /* GODHAND_CDAMAGEUNITFN_H */
