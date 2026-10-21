/* NON_MATCHING func_00352298 (cygnus-2.96): ring-table
 * update.
* Retail's reset loop carries 3 short-loop pad nops (assembler-padded reorder loop)
 * that our cygnus pipeline never emits; most remaining diffs are that shift plus the
 * pkt->0x164 / ->0x70 load order in the gap-fill branch. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Ent {
    short key;
    unsigned short val;
} Ent;

extern void func_00352DC0(char *pkt, char *dst);
extern void func_00352520(char *self, char *o);
extern void func_00354128(char *self, char *o);

__attribute__((section(".text.func_00352298")))
void func_00352298(char *self, char *pkt, int reset)
{
    char *d = self + 0xD30;
    Ent *tbl = (Ent *)(self + 0x11E0);
    char *s3 = *(char **)(self + 0x1FC0);
    int n;
    int type;
    int idx;
    int i;
    int k;

    func_00352DC0(pkt, self + 0xD4C);
    if (reset) {
        for (i = 0; i < 64; i++)
            tbl[i].key = -1;
        tbl[0].val = -1;
        type = *(int *)(pkt + 0x18);
        n = *(int *)(pkt + 0x14);
    } else {
        type = *(int *)(pkt + 0x18);
        n = *(int *)(pkt + 0x14);
        if ((unsigned int)(type - 1) < 2) {
            int last = *(int *)(*(char **)(s3 + 0x164) + 0x70);
            int end = n;
            if (n < last)
                end = n + 0x400;
            for (i = last + 1; i < end; i++)
                tbl[i % 64].key = -1;
        }
    }
    idx = n % 64;
    tbl[idx].key = *(unsigned short *)(d + 0x38);
    if (reset) {
        tbl[idx].val = 0;
    } else if (n == 0 && (short)tbl[0].val == -1) {
        tbl[0].val = 0;
    } else {
        k = 0;
        do {
            Ent *e = &tbl[(idx - k + 63) % 64];
            k++;
            if (e->key != -1) {
                tbl[idx].val = (unsigned short)e->key + e->val;
                break;
            }
        } while (k < 64);
    }
    *(unsigned short *)(d + 0x3A) = tbl[idx].val;
    if (type == 3 && tbl[idx].key != 0) {
        char *o = *(char **)(s3 + 0x164);
        unsigned short v = (unsigned short)tbl[idx].key + tbl[idx].val;
        tbl[*(int *)(o + 0x70) % 64].val = v;
        *(unsigned short *)(o + 0x2E) = v;
        func_00352520(self, o);
        func_00354128(self, *(char **)(s3 + 0x164));
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00352298);
#endif
