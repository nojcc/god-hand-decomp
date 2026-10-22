/* cygnus-2.96 */
#include "godhand/mwPly.h"

extern int func_0032E3A0(MwPly *s);

/* Pass the player's span to the decoder with its midpoint: half the span at rate 0, otherwise the
 * current position scaled by the rate. */
__attribute__((section(".text.func_0032DD70")))
void func_0032DD70(MwPly *ply)
{
    int mid;

    if (ply->rate == 0.0f) {
        func_00328C80(ply->sfd, ply->span / 2, ply->span);
    } else {
        mid = func_0032E3A0(ply) * ply->rate;
        func_00328C80(ply->sfd, mid, ply->span);
    }
}
