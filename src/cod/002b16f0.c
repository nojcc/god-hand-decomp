/* sn-2.95.3-136 matched TU. */

#include "godhand/messPanel.h"

extern void CornerPanel_initState0(void *a0);
extern void func_002B17F8(void *a0);
extern void Panel_resetToStartPose(Panel *self);
extern void CornerPanel_setPointsState4(void *a0);
extern void CornerPanel_setPointsState5(void *a0);
extern int D_00747A2C;

__attribute__((section(".text.func_002B16F0")))
void func_002B16F0(Panel *self)
{
    char *g = (char *)&D_00747A2C;

    {
        unsigned long f = *(int *)(g + 4);
        unsigned long b = (f >> 1) & 1;
        if (b) {
            return;
        }
    }
    if ((*(int *)(g + 0x58) & 0x8000000) != 0) {
        return;
    }
    switch (self->kind) {
    case 0:
        CornerPanel_initState0(self);
        break;
    case 2:
        func_002B17F8(self);
        break;
    case 3:
        Panel_resetToStartPose(self);
        break;
    case 4:
        CornerPanel_setPointsState4(self);
        break;
    case 5:
        CornerPanel_setPointsState5(self);
        break;
    default:
        break;
    }
}
