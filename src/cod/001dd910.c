/* sn-2.95.3-136 matched TU. */
#include "godhand/Poker.h"


__attribute__((section(".text.func_001DD910")))
void func_001DD910(Poker *self, unsigned char a1) {
    switch (a1) {
    case 0:
        SetCustomIDDispOneOrAll_1DD258(self, 9, 1);
        SetCustomIDDispOneOrAll_1DD258(self, 10, 1);
        SetCustomIDDispOneOrAll_1DD258(self, 11, 1);
        break;
    case 1:
        SetCustomIDDispOneOrAll_1DD258(self, 9, 0);
        SetCustomIDDispOneOrAll_1DD258(self, 10, 1);
        SetCustomIDDispOneOrAll_1DD258(self, 11, 1);
        break;
    case 2:
        SetCustomIDDispOneOrAll_1DD258(self, 9, 0);
        SetCustomIDDispOneOrAll_1DD258(self, 10, 0);
        SetCustomIDDispOneOrAll_1DD258(self, 11, 1);
        break;
    default:
        break;
    }
}
