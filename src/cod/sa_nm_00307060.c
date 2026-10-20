/* func_00307060: 5 insns, register allocation only - retail loads node->base
 * into a0 and nx->base into v1 (ours v0/a0) for the adjacency compare. */
#include "include_asm.h"

#ifdef NON_MATCHING

#include "godhand/espSys.h"

void func_00307060(char *self)
{
    espMemNode *node;
    espMemNode *nx;

    node = (espMemNode *)(self + ESP_MEM_HEAD_OFS);
    if (node->next != 0) {
        do {
            nx = node->next;
            if (node->base + node->size * 16 == nx->base) {
                node->size += nx->size;
                if (nx->next != 0) {
                    nx->next->prev = nx->prev;
                }
                node->next = nx->next;
                func_00306FC0(self, nx);
                node = (espMemNode *)(self + ESP_MEM_HEAD_OFS);
            }
            node = node->next;
        } while (node != 0 && node->next != 0);
    }
}

#else

INCLUDE_ASM("asm/nonmatching", func_00307060);

#endif
