/* sn-2.95.3-136 matched TU. */
#include "godhand/CustomIDWork.h"
#include "godhand/Poker.h"

typedef struct { int w[5]; } Blk1DE;
extern Blk1DE D_0042B5D0;

__attribute__((section(".text.func_001DEBF0")))
void func_001DEBF0(Poker *self, unsigned char a1, int a2, int a3) {
    Blk1DE buf;
    if (a1 < 5) {
        buf = D_0042B5D0;
        CustomIDWork_SetOffsetPosXY(&self->elem[buf.w[a1]], a2, a3);
    }
}
