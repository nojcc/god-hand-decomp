/* NON_MATCHING func_0033A618 (cygnus dr, bnel vs bne): best 1: identical except retail's used!=0 branch is bnel (annulled sltiu in the slot) where ours is bne. Nested-if, single-exit and shared-goto forms push it to 37-46; -fno-gcse no change. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct SjChunk SjChunk;
struct SjChunk {
    SjChunk *next; /* 0x00 */
    char pad4[8];
    int len; /* 0x0C */
};
typedef struct {
    char pad0[4];
    signed char used; /* 0x04 */
    char pad5[0x18 - 0x5];
    SjChunk *list[4]; /* 0x18 */
    void (*errfn)(void *obj, int err); /* 0x28 */
    void *errobj; /* 0x2C */
} SjQue;
extern char D_00455BD8[];
extern char D_00455C08[];
extern char D_00455C88[];
extern char D_00455C98[];
extern void func_0033A048(char *fn, char *msg);

int func_0033A618(SjQue *sj, unsigned int id)
{
    SjChunk *ck;
    int sum;

    if (sj == 0) {
        func_0033A048(D_00455C88, D_00455BD8);
        return 0;
    }
    if (sj->used == 0) {
        func_0033A048(D_00455C98, D_00455C08);
        return 0;
    }
    if (id >= 4) {
        if (sj->errfn != 0)
            sj->errfn(sj->errobj, -3);
        return 0;
    }
    sum = 0;
    for (ck = sj->list[id]; ck != 0; ck = ck->next)
        sum += ck->len;
    return sum;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0033A618);
#endif
