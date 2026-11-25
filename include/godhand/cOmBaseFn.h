/* include/godhand/cOmBaseFn.h - cOmBase methods that more than one unit calls.
 *
 * cOmBase.h holds the record; these are methods defined in their own units
 * (0x1B79E0 in 0014ff00.c, 0x1B7A78 in 001a6188.c). Both return their flag
 * as a long: callers test the whole register.
 */
#ifndef GODHAND_COMBASEFN_H
#define GODHAND_COMBASEFN_H

#include "godhand/cOmBase.h"

/* Whether the object can be picked up or targeted: not gone, not flagged
 * off (flags2 bit 13), and an item drop for an ordinary actor or flags2 bit 8. */
long func_001B79E0(cOmBase *self);
/* 1 when the object drops an item: not gone, not marked no-drop (0x9C3), and
 * an explicit item or an actor type that drops one by default. */
long cOmBase_canItemDrop(cOmBase *self);
/* The common setup step: build the model from the pack; 0 (and the object
 * released) when that fails. */
int func_001B6FB8(cOmBase *self);
/* Show (show 1) or hide (show 0) every mesh of the given layer. */
void cOmBase_setMeshDispFromLayer(cOmBase *self, int layer, int show);

/* The cOm classes' common death: release the object. */
void cOmBase_dieCommon(cOmBase *self);
/* Call the current mode's method from the mode table, then the post step
 * (skipped for actor ACTOR_NO_POST) and func_001B76D8. */
void cOmBase_tickModeTableSkip381(cOmBase *self);
/* State-table dispatchers: call the handler for the state at 0x2F4, then
 * func_001B76D8. */
void StateObj_runHandler(void *a0);
void func_001BC0A0(void *a0);
void func_001BD6B0(void *a0);

#endif /* GODHAND_COMBASEFN_H */
