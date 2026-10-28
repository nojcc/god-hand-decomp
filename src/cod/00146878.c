#include "godhand/cIDBase.h"
extern void IdPair_init(void *);

__attribute__((section(".text.func_00146878")))
void func_00146878(char *self)
{
    IdPair_init(self);
    *(short *)(self + 0x100) = 0;
    cIDBase_restartAnim((cIDBaseObj *)self);
    self[0x1C] = 1;
}
