/* sn-2.95.3-136 */
#include "godhand/cDataManager.h"

/* 1 unless a slot holding kind is in any state but 8. */
__attribute__((section(".text.cDataManager_isUnload")))
int cDataManager_isUnload(cDataManager *self, int kind)
{
    int i = self->slotNum;

    while (--i != -1) {
        if (self->slot[i].kind == kind && self->slot[i].state != 8) {
            return 0;
        }
    }
    return 1;
}
