/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"

extern void func_002CB070(cSnd *self);
extern void func_00375050(int a, int b);
extern void sceGsSyncV(int a);
extern void cSndMemHeap_Close(void *a);
extern void func_0032D250(void);
extern void func_00324AC8(void);
extern void func_00325818(void);
extern char D_006036A0[];
extern char D_00603310[];
extern char D_00602F80[];

/* func_002CA040 — sn-2.95.3-136, --call-loop-pad */

















/* Shuts the sound object down: stops every voice and node, waits for the driver, then closes the heaps. */
__attribute__((section(".text.func_002CA040")))
void func_002CA040(cSnd *self) {
    cSndSeVoice *v;
    cSndBgmNode *node;

    v = self->voiceHead;
    if (v != 0) {
        do {
            cSndSeVoice_Stop(v);
            v = v->next;
        } while (v != 0);
    }
    node = self->bgmHead;
    if (node != 0) {
        do {
            cSndBgmNode_Release(node);
            node = node->next;
        } while (node != 0);
    }
    self->flagsAC = 0;

    self->flagsB0 = 0;
    self->f30 = 0;
    self->fA8 = 0;
    func_002CB070(self);
    func_00375050(0, 0);
    while (func_00375180() == 1) {
        cSnd_update(self);
        sceGsSyncV(0);
    }
    cSnd_resetAll(self);
    cSndMemHeap_Close(D_006036A0);
    cSndMemHeap_Close(D_00603310);
    cSndMemHeap_Close(D_00602F80);
    func_0032D250();
    func_00324AC8();
    func_00325818();
}
