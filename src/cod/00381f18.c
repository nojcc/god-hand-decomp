/* sn-2.95.3-136 matched TU. */
#include "godhand/menuCtl.h"

/* sn-2.95.3-136: MixChan_stepPad, applies one pad step to the selected channel of a mixer record:
 * a negative flag word and bit 30 move the volume entry down and up by the step, bits 15 and 13
 * move the table index instead and reload the volume from the table. */
typedef struct MixPad {
    char unk00[0x2C];
    unsigned int flags;                 /* 0x2C bit 1: coarse step */
    char unk30[8];
    int btn;                            /* 0x38 button word */
} MixPad;

#define MIX_CHAN_OFFSET     0x318

extern short D_003F2060[];

__attribute__((section(".text.MixChan_stepPad")))
void MixChan_stepPad(char *mix, MixPad *pad)
{
    MenuSnd *c = (MenuSnd *)(mix + MIX_CHAN_OFFSET);
    short step = 1;
    int btn;

    if ((pad->flags & 2) != 0)
        step = 10;
    btn = pad->btn;
    if (btn < 0) {
        if (c->level[c->slot] >= step - 0x3C0)
            c->level[c->slot] = c->level[c->slot] - step;
        else
            c->level[c->slot] = -0x3C0;
        goto reidx;
    }
    if ((btn & 0x40000000) != 0) {
        if (c->level[c->slot] <= -step)
            c->level[c->slot] = c->level[c->slot] + step;
        else
            c->level[c->slot] = 0;
reidx: /* shared by the negative-flag and bit-30 arms, as in the matched sibling func_003851C0 */
        c->index[c->slot] = func_003807E0(mix, c->level[c->slot]);
    } else if ((btn & 0x8000) != 0) {
        if (c->index[c->slot] >= step)
            c->index[c->slot] = c->index[c->slot] - step;
        else
            c->index[c->slot] = 0;
        c->level[c->slot] = D_003F2060[c->index[c->slot]];
    } else {
        if ((btn & 0x2000) == 0)
            return;
        if (c->index[c->slot] <= 0x7F - step)
            c->index[c->slot] = c->index[c->slot] + step;
        else
            c->index[c->slot] = 0x7F;
        c->level[c->slot] = D_003F2060[c->index[c->slot]];
    }
    func_003820C0((MenuCtl *)mix, c);
}
