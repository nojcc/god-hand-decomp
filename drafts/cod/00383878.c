/* sn-2.95.3-136: func_00383878, clone of func_00381F18 for the second sound block: sound option input: left/right step the selected slot's level (by 10 with the
 * fast bit held, clamped to [-960, 0]) and convert it, up/down step the raw index (clamped to [0, 127]) and look
 * the level up in D_003F2060, then refresh the slots. */
/* NON_MATCHING func_00383878 (sn-2.95.3-136): 106 vs 105 words. Retail runs the level branches into a
 * shared tail that the index branches jump past, a layout that only a jump into the middle of
 * the function reproduces. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/menuCtl.h"
extern unsigned short D_003F2060[];
extern short func_003807E0(SndOptMenu2 *o, int level);
extern void func_00383A20(SndOptMenu2 *o, SndOptLevels2 *p);

__attribute__((section(".text.func_00383878")))
void func_00383878(SndOptMenu2 *o, SndOptPad *pad)
{
    SndOptLevels2 *p;
    short step;
    int trig;

    p = &o->snd;
    step = 1;
    if (pad->hold & 2)
        step = 10;
    trig = pad->trig;
    if (trig < 0 || (trig & 0x40000000)) {
        if (trig < 0) {
            if (o->snd.level[p->slot] >= step - 960)
                o->snd.level[p->slot] -= step;
            else
                o->snd.level[p->slot] = -960;
        } else {
            if (o->snd.level[p->slot] <= -step)
                o->snd.level[p->slot] += step;
            else
                o->snd.level[p->slot] = 0;
        }
        p->index[p->slot] = func_003807E0(o, p->level[p->slot]);
    } else {
        if (trig & 0x8000) {
            if (o->snd.index[p->slot] >= step)
                o->snd.index[p->slot] -= step;
            else
                o->snd.index[p->slot] = 0;
        } else if (trig & 0x2000) {
            if (o->snd.index[p->slot] <= 127 - step)
                o->snd.index[p->slot] += step;
            else
                o->snd.index[p->slot] = 127;
        } else {
            return;
        }
        p->level[p->slot] = D_003F2060[p->index[p->slot]];
    }
    func_00383A20(o, p);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00383878);
#endif
