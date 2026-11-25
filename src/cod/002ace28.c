/* sn-2.95.3-136 matched TU. */
#include "godhand/eh.h"
#include "godhand/heapArenaFn.h"

/* __get_eh_info: the address of the current thread's exception info. */
__attribute__((section(".text.__get_eh_info")))
cp_eh_info **__get_eh_info(void) {
    return &(*get_eh_context)()->info;
}

__attribute__((section(".text.cIDManager_getTexAddr_2ACE28")))
int cIDManager_getTexAddr_2ACE28(void *a0, void *a1) {
    return cIDManager_getTexAddr(a0, 1, a1);
}

__attribute__((section(".text.func_0030F550")))
void *func_0030F550(unsigned int size) {
    return _MemoryAlloc(size, 0x10, D_003C3CF0);
}
