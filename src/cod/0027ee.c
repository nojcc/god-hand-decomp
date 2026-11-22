/* sn-2.95.3-136 */
#include "godhand/vu0.h"
#include "godhand/cGameObj.h"
#include "godhand/vtables.h"
#include "godhand/globals.h"

extern void *func_0028EB00(void *self);

/* Enemy constructor: runs the enemy base constructor, sets the method table and
 * the kind name, clears five vectors of the derived tail. */
__attribute__((section(".text.InitObjVtableAndTypeFull_27EE68")))
struct cGameObj *InitObjVtableAndTypeFull_27EE68(struct cGameObj *self)
{
    func_0028EB00(self);
    self->vtable = D_00448598;
    VU0_SQC2_VF0(self, 0x1530);
    VU0_SQC2_VF0(self, 0x1540);
    VU0_SQC2_VF0(self, 0x1550);
    VU0_SQC2_VF0(self, 0x1590);
    VU0_SQC2_VF0(self, 0x15A0);
    self->kindName = D_004484B0;
    return self;
}
