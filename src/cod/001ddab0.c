/* sn-2.95.3-136 matched TU. */
#include "godhand/Poker.h"

typedef struct { int w[5]; } Blk1DD;
extern Blk1DD D_0042B5D0;

__attribute__((section(".text.func_001DDAB0")))
void func_001DDAB0(Poker *self, unsigned char a1, int a2) {
    Blk1DD buf;
    if (a1 < 5) {
        buf = D_0042B5D0;
        SetCustomIDDispOneOrAll_1DD258(self, buf.w[a1], a2);
    }
}
