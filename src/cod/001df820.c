#include "godhand/Poker.h"
#include "godhand/PanelObj.h"
#include "godhand/CustomIDWork.h"
extern Poker *func_001DD068(Poker *self);
extern void *func_001DEC70(void *ui);
extern void CustomIDWork_ResetMoveOffsetPos(void *);

__attribute__((section(".text.func_001DF820")))
void func_001DF820(PanelObj *self, int enabled)
{
    if (enabled)
        CustomIDWork_SetMoveOffsetPosXSin(&self->elem[8], 4, 8);
    else
        CustomIDWork_ResetMoveOffsetPos(&self->elem[8]);
}

__attribute__((section(".text.func_001DF858")))
Poker *func_001DF858(Poker *self)
{
    func_001DD068(self);
    func_001DEC70(POKER_UI(self));
    self->unk2E50 = 0;
    return self;
}
