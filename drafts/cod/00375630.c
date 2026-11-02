/* sn-2.95.3-136 */
#include "godhand/sndTiming.h"

/* Sets the system volumes and works out each sub-volume's level, scaled by its master. */
__attribute__((section(".text.SdeSystemVolSet")))
void SdeSystemVolSet(SndSystemVol *vol)
{
    SndTiming *p = &D_0076A790;

    p->vol = *vol;
    p->level[0] = 0;
    p->level[1] = (p->vol.master[1] << 8) * p->vol.sub[0] / 127;
    p->level[2] = (p->vol.master[0] << 8) * p->vol.sub[1] / 127;
    p->level[3] = (p->vol.master[1] << 8) * p->vol.sub[2] / 127;
    p->level[4] = (p->vol.master[0] << 8) * p->vol.sub[3] / 127;
    p->level[5] = (p->vol.master[1] << 8) * p->vol.sub[4] / 127;
}
