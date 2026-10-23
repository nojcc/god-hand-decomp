#include "godhand/seqNode.h"

extern void ClearEventFlagsPending_375FA0(void);
extern void ClearPendingEntries_376008(void);
extern void func_00376370(void);

__attribute__((section(".text.func_00375F68")))
void func_00375F68(void)
{
    ClearEventFlagsPending_375FA0();
    ClearPendingEntries_376008();
    func_00376370();
    func_0037BE98();
}
