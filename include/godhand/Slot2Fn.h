/* include/godhand/Slot2Fn.h - Slot2 prize-board methods whose prototype
 * clashes with main units' own declarations, so Slot2.h can't carry it.
 * Included by the work units that need it.
 */
#ifndef GODHAND_SLOT2FN_H
#define GODHAND_SLOT2FN_H

#include "godhand/Slot2.h"

/* Clear a prize board's first 0x54 bytes and store id in its first word. */
void InitClearStructAndSet_1E79A8(Slot2Panel *self, int id);

#endif /* GODHAND_SLOT2FN_H */
