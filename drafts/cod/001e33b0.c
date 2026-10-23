/* sn-2.95.3-136 (as=sn): func_001E33B0, the Slot1 debug menu.
 * Differs from retail: the block after the switch schedules the name-table copy before the dsra of the forced-result
 * bit and loads the D_0042B860 address after it; retail computes both ahead of the copy. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/Slot1.h"
#include "godhand/gameWork.h"

extern void func_002E0D60(int a, int b, int c, int d, int e, int f, char *format, ...);

/* The reel results the debug menu can force, by name. */
typedef struct Slot1DebugNames {
    char *name[8];
} Slot1DebugNames;

extern Slot1DebugNames D_0042B840;
extern char D_0042B7F0[];       /* "OFF" */
extern char D_0042B860[];
extern char D_0042B870[];
extern char D_0042B878[];
extern char D_0042B888[];

/* Slot1 debug menu: up and down pick a row, left and right toggle the forced result (row 0) or step through the
 * results (row 1); then print both rows and the cursor. */
__attribute__((section(".text.func_001E33B0")))
void func_001E33B0(Slot1 *self)
{
    Slot1DebugNames names;

    if (D_007474A0.rep & 0x1100001000000L) {
        if (--self->debugRow < 0) {
            self->debugRow = 1;
        }
    } else if (D_007474A0.rep & 0x2200002000000L) {
        if (++self->debugRow >= 2) {
            self->debugRow = 0;
        }
    }
    switch (self->debugRow) {
    case 0:
        if (D_007474A0.rep & 0xCC0000C000000L) {
            long v = (unsigned int)self->endFlag;
            long forced = v >> 4 & 1;

            if (forced != 0) {
                self->endFlag &= ~0x10;
            } else {
                self->endFlag |= 0x10;
            }
        }
        break;
    case 1:
        if (D_007474A0.rep & 0x4400008000000L) {
            if (--self->debugReel < 0) {
                self->debugReel = 7;
            }
        } else if (D_007474A0.rep & 0x8800004000000L) {
            if (++self->debugReel >= 8) {
                self->debugReel = 0;
            }
        }
        break;
    }
    names = D_0042B840;
    {
        long v = (unsigned int)self->endFlag;
        long forced = v >> 4 & 1;

        func_002E0D60(8, 0x10, 0x20, 0x20, 0, 0, D_0042B860, forced != 0 ? D_0042B870 : D_0042B7F0);
    }
    func_002E0D60(8, 0x10, 0x20, 0x30, 0, 0, D_0042B878, names.name[self->debugReel]);
    func_002E0D60(8, 0x10, 0x15, self->debugRow * 0x10 + 0x20, 0, 0, D_0042B888);
}
#else
INCLUDE_ASM("asm/nonmatching", func_001E33B0);
#endif
