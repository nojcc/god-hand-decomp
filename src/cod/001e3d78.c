/* sn-2.95.3-136 matched TU. */
#include "godhand/Slot1.h"
#include "godhand/cSnd.h"
#include "godhand/scrollLayer.h"

extern void func_003735E0(void *a0, int a1, float f12, float f13);

/* Set markFlag[6] (bit 15 start lit, bit 14 shown) and show or hide its layer. */
__attribute__((section(".text.func_001E3D78")))
void func_001E3D78(Slot1 *self, int show, int startLit) {
    self->markFlag[6] = 0;
    if (startLit) {
        self->markFlag[6] = SLOT1_MARK_F_START_LIT;
    }
    if (show) {
        self->markFlag[6] = self->markFlag[6] | SLOT1_MARK_F_ON;
        displayScrollLayer(self->scrollLayer[SLOT1_MARK6_LAYER], 1);
    } else {
        displayScrollLayer(self->scrollLayer[SLOT1_MARK6_LAYER], 0);
    }
}

/* Slot2 line mark 1: set its flag word (bit 15 = start lit, bit 14 = on) and
 * show or hide the line layer. */
__attribute__((section(".text.func_001E6C80")))
void func_001E6C80(Slot2 *self, int on, int lit) {
    self->markFlag[1] = 0;
    if (lit) {
        self->markFlag[1] = 0x8000;
    }
    if (on) {
        self->markFlag[1] = self->markFlag[1] | 0x4000;
        displayScrollLayer(self->lineLayer, 1);
    } else {
        displayScrollLayer(self->lineLayer, 0);
    }
}

/* Slot2 line mark 2, same as mark 1 for the next flag word. */
__attribute__((section(".text.func_001E6D48")))
void func_001E6D48(Slot2 *self, int on, int lit) {
    self->markFlag[2] = 0;
    if (lit) {
        self->markFlag[2] = 0x8000;
    }
    if (on) {
        self->markFlag[2] = self->markFlag[2] | 0x4000;
        displayScrollLayer(self->lineLayer, 1);
    } else {
        displayScrollLayer(self->lineLayer, 0);
    }
}

/* Slot2 line mark 3, same again for the next flag word. */
__attribute__((section(".text.func_001E6E10")))
void func_001E6E10(Slot2 *self, int on, int lit) {
    self->markFlag[3] = 0;
    if (lit) {
        self->markFlag[3] = 0x8000;
    }
    if (on) {
        self->markFlag[3] = self->markFlag[3] | 0x4000;
        displayScrollLayer(self->lineLayer, 1);
    } else {
        displayScrollLayer(self->lineLayer, 0);
    }
}

__attribute__((section(".text.func_003AE188")))
int func_003AE188(int a0, int a1, ...) {
    return func_003AB158(a0, a1, (char*)__builtin_next_arg(a1) - 0x30);
}

/* Sets flag bits on a node, stores a fade time, and starts a short fade. */
__attribute__((section(".text.cSndBgmNode_SetFlagsFadeOut")))
void cSndBgmNode_SetFlagsFadeOut(cSndBgmNode *node, int setBits, float time) {
    node->flags |= setBits;
    node->fadeTime = time;
    func_003735E0(node, -1, 0.01f, time);
}
