/* sn-2.95.3-136 */
#include "godhand/cCockGetPoint.h"
#include "godhand/cIDBaseFn.h"

/* Restart every marker display and set it playing, then mark every slot unused. */
__attribute__((section(".text.func_0013E010")))
void func_0013E010(cCockGetPoint *self) {
    unsigned short i;
    unsigned short j;

    for (i = 0; i < MARKER_NUM; i++) {
        cIDBase_restartAnim(&self->rec[i].id);
        (self->rec + i)->id.playing = 1;
    }

    for (j = 0; j < MARKER_NUM; j++) {
        self->id[j] = MARKER_NONE;
    }
}
