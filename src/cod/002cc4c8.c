/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"

/* Returns voice idx of the voice pool. */
__attribute__((section(".text.cSnd_GetVoice")))
cSndSeVoice *cSnd_GetVoice(cSnd *self, int idx) {
    return &self->voicePool[idx];
}

__attribute__((section(".text.func_002D2DB0")))
cSndBgmNode *func_002D2DB0(cSnd *self, int idx) {
    return &self->bgmPool[idx];
}
