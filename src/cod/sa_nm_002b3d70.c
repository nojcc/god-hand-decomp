/* NON_MATCHING func_002B3D70 (sn-2.95.3-136;
 * STOP 11): step 0 waits for hold to clear and arms bit 0x80; step 1 counts, and once the 90-frame wait or the skip buttons fire, resets the counter, clears the flags, rewinds the step and clears the cut entry if asked.
 * Only the schedule differs: retail keeps D_003C2550 = 0 first in the join block (reorg then copies it into the three branch delay slots); ours moves the flags load above it.
 * Splitting the store into each branch changes register allocation instead (score 61).
 * The bit-4 test needs the long widening idiom (lw + dsrl). */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct StepObj2B3D70 {
    char unk00[0xC];
    unsigned char mode;                 /* 0xC */
    unsigned char state;                /* 0xD */
    unsigned char sub;                  /* 0xE */
    unsigned char subE;                 /* 0xF */
    char unk10[4];
    int flags;                          /* 0x14 */
    char unk18[0x16];
    unsigned short hold;                /* 0x2E */
    char unk30[4];
    int wait;                           /* 0x34 */
    char unk38[0x8C - 0x38];
    char f8C[4];                        /* 0x8C */
    char f90[0x22];                     /* 0x90 */
    unsigned char count;                /* 0xB2 */
} StepObj2B3D70;

extern int D_00747A84;
extern long D_003C3D48;
extern int D_003C2550;
extern char D_00586AF0[];

extern void func_002B4768(void *self, void *a, void *b);
extern void cEvent_clearCutEntry(void *cut);

void func_002B3D70(StepObj2B3D70 *self)
{
    long t;

    switch (self->state) {
    case 0:
        if (self->hold != 0)
            return;
        self->flags |= 0x80;
        self->count = 0;
        self->state = self->state + 1;
    case 1:
        self->count++;
        D_003C2550++;
        t = D_00747A84;
        if ((((unsigned long)t >> 4) & 1UL) == 1UL)
            return;
        if (self->wait == 1) {
            if (D_003C2550 < 90)
                return;
        } else {
            char *g = (char *)&D_00747A84 - 0x5E4;

            if ((*(long *)(g + 0x178) & D_003C3D48) == 0 && (*(long *)(g + 0x1A0) & 0x10000000) == 0)
                return;
        }
        D_003C2550 = 0;
        self->flags &= ~0x80;
        self->flags &= ~1;
        func_002B4768(self, self->f90, self->f8C);
        self->mode = 2;
        self->state = 0;
        self->sub = 0;
        self->subE = 0;
        if (D_00747A84 & 0x20000000)
            cEvent_clearCutEntry(D_00586AF0);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002B3D70);
#endif
