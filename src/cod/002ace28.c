/* sn-2.95.3-136 matched TU. */
#include "godhand/heapArena.h"

extern int (*D_003C490C)(void *);

__attribute__((section(".text.func_00320360")))
int func_00320360(void *a0) {
    return D_003C490C(a0) + 8;
}

__attribute__((section(".text.cIDManager_getTexAddr_2ACE28")))
int cIDManager_getTexAddr_2ACE28(void *a0, void *a1) {
    return cIDManager_getTexAddr(a0, 1, a1);
}

__attribute__((section(".text.func_0030F550")))
void *func_0030F550(unsigned int size) {
    return _MemoryAlloc(size, 0x10, D_003C3CF0);
}
