#include "godhand/vu0.h"
#include "godhand/cModel.h"

extern void IK_InverseKinematics(void *, void *);

__attribute__((section(".text.func_00318468")))
void func_00318468(char *self)
{
    if ((*(int *)(self + 0x250) & 2) != 0)
        return;
    cModel_calcParts((cModel *)self);
    if (*(int *)(self + 0x258) < 0)
        return;
    IK_InverseKinematics(self + 0x448, self);
    cModel_calcWorldParts((cModel *)self);
}
