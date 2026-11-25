/* TU: PokerId [casino] - recovered C++ class. */
#include "godhand/Poker.h"
extern void func_001DD1A0(Poker *self);
extern void func_001DEDC8(void *ui);

__attribute__((section(".text.PokerId_Move")))
void PokerId_Move(Poker *self) {
    func_001DD1A0(self);
    func_001DEDC8(POKER_UI(self));
}

