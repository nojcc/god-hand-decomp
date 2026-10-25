/* sn-2.95.3-136 matched TU. */

#include "godhand/regTbl.h"

extern int func_003A5678(int a0, int a1);
extern int func_003943D0(RegEnt *a0);

/* Apply the relocations whose entry index is key, each relative to base; 0 if one fails. */
__attribute__((section(".text.func_00394290")))
int func_00394290(RegReloc *rel, int count, int key, int base) {
    unsigned int i; unsigned int info;
    i = count - 1;
    if (count != 0) {
        do {
            info = rel->info;
            if ((info >> 8) == (unsigned)key) {
                if (patch((unsigned char *)rel->where, info & 0xFF, base + rel->addend) == 0) return 0;
            }
            rel++; i--;
        } while (i != 0xFFFFFFFFu);
    }
    return 1;
}

/* Return 1 if an active entry with the same id and name is already registered, else run the fallback pass. */
__attribute__((section(".text.func_003945C0")))
int func_003945C0(RegEnt *ent) {
    RegTbl *node;
    RegEnt *elem;
    int cnt;
    node = D_003F852C;
    if (node != 0) {
        do {
            cnt = node->count;
            elem = node->ents;
            if (cnt != 0) {
                do {
                    if (elem->active != 0 && elem->id == ent->id &&
                        func_003A5678(elem->name, ent->name) == 0) {
                        return 1;
                    }
                    elem++;
                } while (--cnt != 0);
            }
            node = node->next;
        } while (node != 0);
    }
    return func_003943D0(ent);
}
