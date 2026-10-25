/* sn-2.95.3-136 */
#include "godhand/cSubScrOption.h"
#include "godhand/cCoreSave.h"
#include "godhand/padWork.h"

extern void SetGlobalToggle_375700(int mode);

/* Put the settings back to their defaults: save flag off, sound output 1, vibration on. self is not read. */
__attribute__((section(".text.func_00167EB0")))
void func_00167EB0(cSubScrOptionT *self)
{
    cCoreSave_clearStateBit0(&D_00569B70);
    SdeSystemOutModeSet(1);
    D_005E8140[PAD_WORK_VIBRATION] = 1;
}
