/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"

/* The sound object's own storage, addressed by retail as separate symbols. */
extern cSndSeEntry D_005FEFF0[];        /* the sound-effect slots seEntry points at */
extern cBgmData D_005FFCF0[];           /* the BGM data records bgm points at */
extern cSndSeVoice D_005FFD80[];        /* the voice pool */
extern cSndBgmNode D_00601180[];        /* the BGM node pool */


/* sn-2.95.3-136 matched TU. One CALL-loop -> one errata pad nop
   (needs --call-loop-pad). */







/* Points the pools at the sound object's own storage, empties both lists and clears the recent-sound ring. */
__attribute__((section(".text.func_002C9C88")))
cSnd *func_002C9C88(cSnd *self) {
    cSndSeRecent *p;
    int i;

    self->voicePool = D_005FFD80;
    self->bgmPool = D_00601180;
    self->seEntry = D_005FEFF0;
    self->bgm = D_005FFCF0;
    self->bgmHead = 0;
    self->voiceHead = 0;

    p = self->recent;
    /* `i != -1`, not `i >= 0`: retail materialises -1 and closes with bne. */
    for (i = 0xF; i != -1; i--) {
        cSndSeRecent_Clear(p);
        p++;
    }

    return self;
}
