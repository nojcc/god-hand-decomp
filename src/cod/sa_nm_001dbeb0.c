/* NM, not registered. sn-2.95.3-136: card table setup and poker hands (0x1DBEB0..).
 * func_001DBEB0: retail loops look un-optimized by loop.c (constant 9 re-made
 *   each pass, work copied to a3, pointer anchored on ent[i].state and both
 *   loops end-padded); a goto-loop reproduces all but the +4 anchor and the
 *   pad.  24 differing insns (24 vs 26 words).
 * func_001DBFB8: 5 insns, ours narrows the five rank loads to lhu where retail
 *   keeps lw.  Declaring BjCardObj.rank volatile matches exactly, but the same
 *   qualifier pushes func_001DC4C0 from 2 to 6 diffs, so it was not adopted.
 * func_001DC4C0: 2 insns, outer-loop i copy/compare order at the back edge. */
#include "include_asm.h"
#include "godhand/Poker.h"

#ifdef NON_MATCHING

void func_001DBEB0(Poker *work)
{
    int i;

    for (i = 0; i < 52; i++) {
        work->deck[i].obj->flags |= 2;
        work->deck[i].flags = 9;
        work->deck[i].obj->unk104 = 0;
    }
    for (i = 4; i >= 0; i--) {
        work->hand[i] = 0;
    }
}

void func_001DBFB8(Poker *work, unsigned short *rank0, unsigned short *num0,
                   unsigned short *rank1, unsigned short *num1,
                   unsigned short *rank2, unsigned short *num2,
                   unsigned short *rank3, unsigned short *num3,
                   unsigned short *rank4, unsigned short *num4)
{
    unsigned short rank[5];
    unsigned short num[5];
    unsigned short tmp[2];
    int i;
    int j;
    int k;
    int m;

    rank[0] = work->hand[0]->obj->rank;
    rank[1] = work->hand[1]->obj->rank;
    rank[2] = work->hand[2]->obj->rank;
    rank[3] = work->hand[3]->obj->rank;
    rank[4] = work->hand[4]->obj->rank;
    num[0] = 1;
    num[1] = 1;
    num[2] = 1;
    num[3] = 1;
    num[4] = 1;

    for (k = 0; k < 4; k++) {
        for (m = k + 1; m < 5; m++) {
            if (rank[k] != 14 && rank[k] == rank[m]) {
                num[k]++;
                rank[m] = 14;
                num[m]--;
            }
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 5; j++) {
            if (rank[j] < rank[i]) {
                tmp[0] = rank[j];
                rank[j] = rank[i];
                rank[i] = tmp[0];
                tmp[1] = num[j];
                num[j] = num[i];
                num[i] = tmp[1];
            }
        }
    }

    *rank0 = rank[0];
    *rank1 = rank[1];
    *rank2 = rank[2];
    *rank3 = rank[3];
    *rank4 = rank[4];
    *num0 = num[0];
    *num1 = num[1];
    *num2 = num[2];
    *num3 = num[3];
    *num4 = num[4];
}

int func_001DC4C0(Poker *work)
{
    unsigned short rank[5];
    unsigned short num[5];
    unsigned short nSame;
    int i;
    int j;
    int n;

    func_001DBFB8(work, &rank[0], &num[0], &rank[1], &num[1], &rank[2], &num[2],
                  &rank[3], &num[3], &rank[4], &num[4]);
    if (num[0] != 4 && num[1] != 4) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        for (n = 0; n < 5; n++) {
            work->hand[n]->flags &= ~4;
        }
        nSame = 0;
        for (j = i + 1; j < 5; j++) {
            if (work->hand[i]->obj->rank == work->hand[j]->obj->rank) {
                nSame++;
                work->hand[i]->flags |= 4;
                work->hand[j]->flags |= 4;
            }
        }
        if (nSame == 3) {
            break;
        }
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001DBEB0);
INCLUDE_ASM("asm/nonmatching", func_001DBFB8);
INCLUDE_ASM("asm/nonmatching", func_001DC4C0);
#endif
