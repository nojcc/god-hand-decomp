/* TU: cDamageManage [battle] - recovered C++ class. */
#include "godhand/cDamageManage.h"

/* A give record for owner, set up for kind; 0 when the setup fails. */
__attribute__((section(".text.cDamageManage_CreateDamageGive")))
cDamageGive *cDamageManage_CreateDamageGive(cDamageManage *self, int kind, void *owner) {
    cDamageGive *p = func_001FE1E0(self);
    if (p == 0) return 0;
    if (SetObjTargetAndActivate_1FD2C0(p, kind, owner) == 0) p = 0;
    return p;
}

/* Release give's volumes and reset it; 0 when give is 0. */
__attribute__((section(".text.cDamageManage_ReleaseDamageGive")))
int cDamageManage_ReleaseDamageGive(cDamageManage *self, cDamageGive *give) {
    if (give == 0) {
        return 0;
    }
    cDvd_releaseAll((cDamageUnit *)give);
    func_001FCDB8(give);
    return 1;
}
