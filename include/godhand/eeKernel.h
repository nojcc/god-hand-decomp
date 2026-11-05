/* include/godhand/eeKernel.h - EE kernel interrupt enable and disable (0x3B63A0, 0x3B63F0), and scePrintf. */
#ifndef GODHAND_EEKERNEL_H
#define GODHAND_EEKERNEL_H

/* DIntr: disable interrupts; nonzero when they were enabled. */
int DIntr(void);
/* Enable interrupts. */
int EIntr(void);

/* scePrintf: print to the debug console with interrupts disabled. */
void func_003B1F28(const char *fmt, ...);

/* DMA controller interrupt handlers and channel interrupt masks. */
int AddDmacHandler2(int chan, int (*handler)(int, void *), int next, void *arg);
int RemoveDmacHandler(int chan, int hid);
int func_003B0810(int cause);   /* EnableDmac */
int func_003B07A8(int cause);   /* DisableDmac */

#endif
