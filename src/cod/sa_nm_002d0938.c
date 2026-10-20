/* NON_MATCHING cSnd_BgmControl (sn-2.95.3-136 + call_loop_pad; near-miss at attempt 4): per-frame BGM node update. Everything matches except one nop: retail's assembler short-loop-padded the call-free found-loop (beqz / addiu / lw / nop / bnel) even though its body holds the exit beqz; ee-as only pads single-block loops, and no C form changes that instruction sequence. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cSnd.h"

extern unsigned int D_00747A84;
extern void cSndBgmNode_StepState(cSndBgmNode *node);
extern void cSnd_BgmEventStop(cSnd *self, int a1);
extern int func_00373A78(cSndBgmNode *node);
extern void cSndBgmNode_FadeOut(cSndBgmNode *node, float time);
extern void func_002D0EA0(cSnd *self);

__attribute__((section(".text.cSnd_BgmControl")))
void cSnd_BgmControl(cSnd *self)
{
    cSndBgmNode *node;

    for (node = self->bgmHead; node != 0; node = node->next)
        cSndBgmNode_StepState(node);

    if (self->flagsAC & 0x10000000) {
        cSndBgmNode *n;
        int found = 0;
        for (n = self->bgmHead; n != 0; n = n->next) {
            if (n->state == 5) {
                found = 1;
                break;
            }
        }
        if (!found)
            cSnd_BgmEventStop(self, 0);
    }

    if (D_00747A84 & 0x20000000)
        goto fade;
    if (D_00747A84 & 0x80000) {
fade:
        for (node = self->bgmHead; node != 0; node = node->next) {
            if (node->state2 != 2 && node->started60 && func_00373A78(node) == 0)
                cSndBgmNode_FadeOut(node, 30.0f);
        }
        self->f128 = -2;
        self->f138 = 3;
    }

    if (self->flagsAC & 0x200000) {
        if (!(self->flagsAC & 0x100000)) {
            if (!(D_00747A84 & 0x20000000)) {
                if (!(D_00747A84 & 0x80000))
                    func_002D0EA0(self);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", cSnd_BgmControl);
#endif
