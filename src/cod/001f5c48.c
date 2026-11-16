/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/JukeBox.h"
#include "godhand/gameWork.h"
#include "godhand/heapArena.h"
extern int cIDBase_release(void *p);
extern int D_003C2388;

/* Fade the BGM out, release the ID object, clear the manager's slot pair and free the data file. */
__attribute__((section(".text.JukeBox_Release")))
void JukeBox_Release(JukeBoxObj *self)
{
    int *mgr;
    void *block;

    D_007474A0.unk10 = 0;
    cSnd_BgmEventFade(&D_005FEE00, self->bgmEvent, 20.0f, 0.0f, -1.0f);
    cIDBase_release(&self->idBase);
    mgr = (int *)D_003C2388;
    *(int *)((char *)mgr + 0xF4) = 0;
    *(int *)((char *)mgr + 0xF0) = 0;
    block = self->dataFile;
    if (block != 0)
        cHeap_free(*(void **)((char *)block - 0x20), block);
}
