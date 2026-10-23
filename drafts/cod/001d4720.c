/* NON_MATCHING func_001D4720, func_001D47E8 (sn-2.95.3-136): same code as retail but for the
 * register assignment: retail gives the ace counter and the second loop's pointer different
 * registers. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/BlackJack.h"

#define BJ_ACE_EXTRA  10
#define BJ_BUST       21

/* Total of hand A: number cards count their value, faces 10 and aces 1, and
 * the last ace counts 11 when that doesn't go over 21. */
__attribute__((section(".text.func_001D4720")))
int func_001D4720(BlackJack *self)
{
    int total = 0;
    unsigned short aces = 0;
    int i;

    for (i = 0; i < self->dealSlot; i++) {
        int rank = self->handA[i]->obj->rank;

        if (rank != 0) {
            if ((unsigned int)(rank - 1) < 9) {
                total += rank + 1;
            } else {
                total += 10;
            }
        }
    }
    for (i = 0; i < self->dealSlot; i++) {
        if (self->handA[i]->obj->rank == 0) {
            aces++;
        }
    }
    while (aces != 0) {
        aces--;
        if (aces == 0 && total + 1 + BJ_ACE_EXTRA <= BJ_BUST) {
            total += 1 + BJ_ACE_EXTRA;
        } else {
            total++;
        }
    }
    return total;
}

/* Total of hand B: number cards count their value, faces 10 and aces 1, and
 * the last ace counts 11 when that doesn't go over 21. */
__attribute__((section(".text.func_001D47E8")))
int func_001D47E8(BlackJack *self)
{
    int total = 0;
    unsigned short aces = 0;
    int i;

    for (i = 0; i < self->dealSlotB; i++) {
        int rank = self->handB[i]->obj->rank;

        if (rank != 0) {
            if ((unsigned int)(rank - 1) < 9) {
                total += rank + 1;
            } else {
                total += 10;
            }
        }
    }
    for (i = 0; i < self->dealSlotB; i++) {
        if (self->handB[i]->obj->rank == 0) {
            aces++;
        }
    }
    while (aces != 0) {
        aces--;
        if (aces == 0 && total + 1 + BJ_ACE_EXTRA <= BJ_BUST) {
            total += 1 + BJ_ACE_EXTRA;
        } else {
            total++;
        }
    }
    return total;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001D4720);
INCLUDE_ASM("asm/nonmatching", func_001D47E8);
#endif
