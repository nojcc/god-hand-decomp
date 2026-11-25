/* sn-2.95.3-136 matched TU. */
#include "godhand/cDamageUnitFn.h"
#include "godhand/fileBuf.h"

extern unsigned int D_007476B0;

__attribute__((section(".text.cDamageUnit_SetDamageCollFlashActiveById")))
void cDamageUnit_SetDamageCollFlashActiveById(cDamageUnit *self, int id, int active, short flash) {
    cDamageNode *n = self->nodes;
    cCollisionUnit *q;
    while (n != 0) {
        if (n->id == id) {
            q = n->unit;
            if (active == 1) q->flags = q->flags | COLL_UNIT_FLAG_ACTIVE;
            else q->flags = q->flags & COLL_UNIT_FLAG_INACTIVE_MASK;
            *(short *)((char *)n + 0x30) = flash;
            return;
        }
        n = n->next;
    }
}

__attribute__((section(".text.sp_char_ck")))
int sp_char_ck(signed char c) {
    switch (c) {
    case 1: return 0x7D;
    case 2: return 0x60;
    case 3: return 0x7C;
    case 4: return 0x7B;
    }
    return c;
}

__attribute__((section(".text.func_002A4F30")))
unsigned int func_002A4F30(char *o, unsigned int amt) {
    char *b = o + 0x28000;
    unsigned int cur = *(unsigned int *)(b + 0x2054);
    unsigned int lim = *(unsigned int *)(b + 0x2058);
    unsigned int nw = cur + amt;
    unsigned int t;
    if (nw >= lim) {
        *(unsigned int *)(b + 0x2054) = lim;
        return 0;
    }
    *(unsigned int *)(b + 0x2054) = nw;
    t = nw - (unsigned int)(o + ((D_007476B0 & 1) * 0x15000 + 0x50));
    if (*(unsigned int *)(b + 0x208C) < t) *(unsigned int *)(b + 0x208C) = t;
    return cur;
}
