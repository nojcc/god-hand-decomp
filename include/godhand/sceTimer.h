/* include/godhand/sceTimer.h - libkernel timer counters and alarms on EE timer 2 (0x3B6xxx-0x3B7xxx).
 *
 * One control block (D_003FBE90) and a pool of 128 counters. A counter id is
 * the counter address shifted left by 4 with the counter's serial (id field)
 * in the low 10 bits.
 */
#ifndef GODHAND_SCETIMER_H
#define GODHAND_SCETIMER_H

#define T2_COUNT (*(volatile unsigned int *)0x10001000)
#define T2_MODE  (*(volatile unsigned int *)0x10001010)

#define T2_MODE_CLKS  0x003             /* clock select: bus clock, /16, /256, h-blank */
#define T2_MODE_OVFF  0x800             /* overflow flag, set until acknowledged */

#define KE_NO_TIMER   0x80008005        /* no free counter */

typedef struct sceTimerCounter {
    struct sceTimerCounter *next;       /* 0x00 */
    struct sceTimerCounter *prev;       /* 0x04 */
    int id;                             /* 0x08 serial, odd, in the low 10 bits of the counter id */
    int mode;                           /* 0x0C bit 0 set while counting */
    unsigned long baseCount;            /* 0x10 */
    unsigned long baseTime;             /* 0x18 */
    unsigned long schedule;             /* 0x20 */
    int unk28;                          /* 0x28 cleared on allocation */
    char unk2C[0x14];
} sceTimerCounter;                      /* 0x40 */

typedef struct sceTimerCtl {
    unsigned long overflow;             /* 0x00 timer 2 overflows since set-up */
    int handlerId;                      /* 0x08 interrupt handler id, negative before set-up */
    int serial;                         /* 0x0C last serial handed out */
    int used;                           /* 0x10 counters allocated */
    sceTimerCounter *free;              /* 0x14 free list */
    sceTimerCounter *alarms;            /* 0x18 pending alarms, earliest first */
    int handling;                       /* 0x1C id of the alarm being handled, -1 when none */
} sceTimerCtl;

/* The timer 2 interrupt handler updates the control block and the counters. */
extern volatile sceTimerCtl D_003FBE90;

unsigned long iGetTimerSystemTime(void);
unsigned long GetTimerSystemTime(void);
int iAllocTimerCounter(void);

#endif
