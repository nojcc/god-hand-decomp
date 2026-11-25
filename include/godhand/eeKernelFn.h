/* include/godhand/eeKernelFn.h - EE kernel calls more than one unit makes.
 *
 * eeKernel.h holds the rest. Older units declare these themselves with their own
 * types, so the prototypes live here for the units that take them from a
 * header.
 */
#ifndef GODHAND_EEKERNELFN_H
#define GODHAND_EEKERNELFN_H

#include "godhand/eeKernel.h"

/* Signal a semaphore from an interrupt handler. */
int iSignalSema(int sema);
/* scePrintf: print to the debug console with interrupts disabled. */
void func_003B1F28(const char *fmt, ...);

#endif /* GODHAND_EEKERNELFN_H */
