#include "godhand/PanelObj.h"
#include "godhand/CustomIDWork.h"
extern void *func_001DD068(void *);
extern void *func_001DEC70(void *);
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
void *func_001DF858(char *p)
{
    func_001DD068(p);
    func_001DEC70(p + 0x25B0);
    *(int *)(p + 0x2E50) = 0;
    return p;
}
