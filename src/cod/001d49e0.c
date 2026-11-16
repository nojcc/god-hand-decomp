/* sn-2.95.3-136 matched TU. */
#include "godhand/BlackJack.h"


__attribute__((section(".text.func_001D49E0")))
void func_001D49E0(BlackJack *self, unsigned char n)
{
    func_001D69A0(self, 0);
    func_001D6BC0(self, 0);
    func_001D6BE0(self, 0);
    func_001D6C28(self, 0);
    switch (n) {
    case 1:
        func_001D69A0(self, 1);
        break;
    case 2:
        func_001D6BC0(self, 1);
        break;
    case 3:
        func_001D6BE0(self, 1);
        break;
    case 4:
        func_001D6C28(self, 1);
        break;
    case 0:
    default:
        break;
    }
}
