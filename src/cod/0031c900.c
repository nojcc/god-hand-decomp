/* sn-2.95.3-136 matched TU. */
#include "godhand/heapArena.h"


__attribute__((section(".text.func_0031C900")))
void func_0031C900(void *self) {
    if (self != 0) {
        cHeap_free(*(void**)((char*)self - 0x20), self);
    }
}
