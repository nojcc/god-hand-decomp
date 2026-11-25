/* sn-2.95.3-136 matched TU. */
#include "godhand/heapArenaFn.h"
#include "godhand/DogRace.h"

extern void ClearObjRef_1EE9A0(void *a0);
extern void func_001EB9F8(void *a0);
extern void **D_003C2384;

__attribute__((section(".text.DogRace_Release")))
void DogRace_Release(DogRace *self) {
    DogRaceDog *q;
    int i;
    void *base;
    void *node;

    q = self->dog;
    /* closes with bgez -> i >= 0 */
    for (i = 4; i >= 0; i--) {
        ClearObjRef_1EE9A0(q);
        q++;
    }

    func_001EDF60(&self->ui2);
    func_001ED660(&self->ui1);
    func_001ECBD0(&self->result);

    base = *D_003C2384;
    ((int *)base)[0x29] = 0;
    ((int *)base)[0x28] = 0;

    node = self->fileData;
    if (node != 0) {
        cHeap_free(HEAP_OWNER(node), node);
    }
    func_001EB9F8(self);
}
