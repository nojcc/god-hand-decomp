/* sn-2.95.3-136 matched TU. */
#include "godhand/BlackJack.h"


__attribute__((section(".text.func_001D4AA8")))
void func_001D4AA8(BlackJack *self, unsigned char mode)
{
    func_001D69E8(self, 0);
    func_001D6C70(self, 0);
    func_001D6C90(self, 0);
    func_001D6CD8(self, 0);
    switch (mode) {
    case 1:
        func_001D69E8(self, 1);
        break;
    case 2:
        func_001D6C70(self, 1);
        break;
    case 3:
        func_001D6C90(self, 1);
        break;
    case 4:
        func_001D6CD8(self, 1);
        break;
    case 0:
    default:
        break;
    }
}
