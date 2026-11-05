#include "godhand/cSnd.h"
#include "godhand/heapArena.h"
extern int cIDBase_release(void *p);
extern int D_007474B0;
extern int D_003C2388;

__attribute__((section(".text.JukeBox_Release")))
void JukeBox_Release(char *self)
{
    int *mgr;
    void *block;

    D_007474B0 = 0;
    cSnd_BgmEventFade(&D_005FEE00, *(int *)(self + 0x24), 20.0f, 0.0f, -1.0f);
    cIDBase_release(self + 0x30);
    mgr = (int *)D_003C2388;
    *(int *)((char *)mgr + 0xF4) = 0;
    *(int *)((char *)mgr + 0xF0) = 0;
    block = *(void **)(self + 0x80);
    if (block != 0)
        cHeap_free(*(void **)((char *)block - 0x20), block);
}
