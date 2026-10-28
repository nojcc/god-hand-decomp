#include "godhand/cModel.h"

/* sn-2.95.3-136 matched TU. */

extern int D_0041EA80;
extern void func_003A52F0(void *dst, int val, int n);


extern int func_00152340(void *tex, long key);
__attribute__((section(".text.cModel_setTextureExchange")))
int cModel_setTextureExchange(cModel *self, void *tex, cTexTable *tbl, int n) {
    long *keys;
    unsigned char *slot;
    unsigned char *group;
    int count;
    int pairs;
    int idx;
    int minusOne;

    if (tex == 0 || tbl == 0) {
        return 0;
    }
    if (tbl->magic != D_0041EA80) {
        return 0;
    }
    if (n >= tbl->groupNum) {
        return 0;
    }

    keys = tbl->key;
    slot = self->texSlot;
    group = (unsigned char *)(keys + tbl->keyNum);

    if (n > 0) {
        do {
            group += group[0] * 2 + 1;
            n--;
        } while (n != 0);
    }

    func_003A52F0(slot, 0xFF, 0x10);

    count = group[0];
    group++;
    if (count == 0) {
        return 1;
    }
    pairs = count;
    minusOne = -1;
    do {
        idx = func_00152340(tex, keys[group[1]]);
        if (idx != minusOne) {
            slot[idx] = group[0];
        }
        group += 2;
        pairs--;
    } while (pairs != 0);
    return 1;
}
