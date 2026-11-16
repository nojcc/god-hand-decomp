/* sn-2.95.3-136 matched TU. */
#include "godhand/cGameObj.h"
#include "godhand/vtables.h"

extern void func_002A84A8(void *p);
extern void cCollisionSolidManage_ReleaseUnit_278368(void *p);
extern void EnemyOwner_releaseChild(void *p);
extern void ForwardDispatchByMode_27F170(void *p);

/* Destructor of the enemy with method table D_00447D48. */
__attribute__((section(".text.func_002780C0")))
void func_002780C0(struct cGameObj *self, int flags)
{
    self->vtable = D_00447D48;
    func_002A84A8(self);
    cCollisionSolidManage_ReleaseUnit_278368(self);
    func_0028EB88(self, flags);
}

/* Destructor of the enemy with method table D_004481A8: release its child first. */
__attribute__((section(".text.func_0027B7C0")))
void func_0027B7C0(struct cGameObj *self, int flags)
{
    self->vtable = D_004481A8;
    func_002A84A8(self);
    EnemyOwner_releaseChild(self);
    func_0028EB88(self, flags);
}

/* Destructor of the enemy with method table D_00448598. */
__attribute__((section(".text.func_0027EEC0")))
void func_0027EEC0(struct cGameObj *self, int flags)
{
    self->vtable = D_00448598;
    func_002A84A8(self);
    ForwardDispatchByMode_27F170(self);
    func_0028EB88(self, flags);
}
