/* include/godhand/cCameraFn.h - cCamera methods more than one unit calls.
 *
 * cCamera.h holds the rest. Older units declare these themselves with their own
 * types, so the prototypes live here for the units that take them from a
 * header.
 */
#ifndef GODHAND_CCAMERAFN_H
#define GODHAND_CCAMERAFN_H

#include "godhand/cCamera.h"

/* Aim the camera from its default eye at its default target and clear the vibration. */
void cCamera_reset(struct cCamera *self);
/* Run the vtable's move step, then stepVib, then update. */
void cCamera_move(struct cCamera *self);
/* cCamera_reset, then clear 0x1C0. */
void func_00139090(struct cCamera *self);

#endif /* GODHAND_CCAMERAFN_H */
