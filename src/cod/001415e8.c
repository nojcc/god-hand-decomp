/* sn-2.95.3-136 matched TU. */
#include "godhand/DispMgr.h"

/* Set unk75 and unk76 = value on every registered sub-record. */
__attribute__((section(".text.func_001415E8")))
void func_001415E8(DispMgr *mgr, int value)
{
    int i;
    for (i = 0; i < DISPMGR_SLOT_NUM; i++) {
        DispMgrSub *obj = mgr->slot[i].obj;
        if (obj != 0) {
            obj->unk75 = 1;
            obj->unk76 = value;
        }
    }
}
