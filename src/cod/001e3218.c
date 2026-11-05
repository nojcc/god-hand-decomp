/* sn-2.95.3-136 matched TU. */
#include "godhand/cNode.h"

__attribute__((section(".text.Slot1_SetSlotLayer")))
void Slot1_SetSlotLayer(int *dst, int *src) {
    int i;

    dst += 0x100;
    for (i = 34; i >= 0; i--) {
        *dst++ = *src++;
    }
}

__attribute__((section(".text.func_001E8E88")))
void func_001E8E88(int *p) {
    int i;
    int v;

    v = 9;
    for (i = 20; i >= 0; i--) {
        p[i + 21] = v;
    }
}

__attribute__((section(".text.func_002B5E90")))
cNode *func_002B5E90(cNode *self, int n) {
    cNode *p;

    p = self->child;
    while (n-- != 0) {
        p = p->next;
    }
    return p;
}
