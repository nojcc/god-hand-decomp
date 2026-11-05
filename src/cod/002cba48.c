/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/cNode.h"
#include "godhand/espSys.h"

extern int D_0044CE48[];
extern int D_00741DB8;
extern unsigned char D_0044D3B0[];
extern void getEffTypeString(void *a0, int a1);
extern void func_003A6C58(void *a0, void *a1, void *a2, int a3, int t0);

/* Plays key on a free voice bound to obj (or part); slot 1 means the emergency slot that the group of
   owner (or of obj, when owner is 0) holds. */
__attribute__((section(".text.cSnd_SeCall_2CBA48")))
int cSnd_SeCall_2CBA48(cSnd *self, int slot, int key, void *obj, void *owner, void *part, int a6, int a7) {
    int no = (short)slot;
    int k = (short)key;
    int group;
    cSndSeVoice *v;

    if (no == 1) {
        int *p;
        unsigned int i;
        if (owner != 0) {
            group = cSnd_getEmSeGroupOwner(self, *(int *)((char *)owner + 0x564));
            if (group <= 0)
                group = *(unsigned short *)((char *)owner + 0x300);
        } else {
            group = cSnd_getEmSeGroupOwner(self, *(int *)((char *)obj + 0x564));
            if (group <= 0)
                group = *(unsigned short *)((char *)obj + 0x300);
        }
        p = D_0044CE48;
        i = 0;
        do {
            if (cSnd_GetSeData(self, *p)->owner == group)
                no = *(short *)p;
            i++;
            p++;
        } while (i < 0xC);
    }

    if (cSeData_IsAlive(cSnd_GetSeData(self, no)) == 0)
        return 0;
    v = cSnd_AllocVoice(self);
    if (v == 0)
        return 0;
    return cSndSeVoice_Bind(v, no, k, obj, part, a6, a7);
}

__attribute__((section(".text.func_002FBED0")))
void func_002FBED0(EspAnim *self) {
    if (func_002B5E50((cNode *)self)) {
        cGameObj *owner = self->owner;
        if (owner) {
            if (owner->objFlags < 0) {
                UpdateObjByIndexedOp_2FBE50(self);
            }
        }
    }
    func_002FBFB0(self);
    if (self->data->flags & ESP_DATA_HIDE_WHEN_CLEAR) {
        if (D_00741DB8 == 0) {
            self->flags = self->flags | ESP_ANIM_HIDE;
        } else {
            self->flags = self->flags & ~ESP_ANIM_HIDE;
        }
    }
    if (self->data->flags & ESP_DATA_HIDE_WHEN_SET) {
        if (D_00741DB8 != 0) {
            self->flags = self->flags | ESP_ANIM_HIDE;
        } else {
            self->flags = self->flags & ~ESP_ANIM_HIDE;
        }
    }
}

__attribute__((section(".text.func_002D9F68")))
void func_002D9F68(void *a0, int a1, ...) {
    char buf0[0x100];
    char localbuf[0x40];
    getEffTypeString(localbuf, *(short*)((char*)a0 + 0x23A));
    func_003A6C58(buf0, D_0044D3B0, localbuf, (int)((unsigned short)*(unsigned short*)((char*)a0 + 0x23C) - 1), a1);
}
