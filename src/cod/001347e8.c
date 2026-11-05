/* sn-2.95.3-136 matched TU. */
#include "godhand/CustomIDWork.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cNode.h"
#include "godhand/cMessCommon.h"
#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"

extern int D_0044FAD0;
extern unsigned int D_007476B0;
extern int D_00568288;
extern void cActionButton_set(int *a0, int a1, int a2, int a3, int t0, int t1, int t2);
extern int cModel_getMeshPtr(int a0, int a1);
extern void NodeList_clear(int *a0);
extern void NodeList_deletingDtor(int *a0, int a1);

__attribute__((section(".text.cSnd_GetBgmData")))
struct cBgmData *cSnd_GetBgmData(cSnd *self, int bank) {
    return &self->bgm[bank];
}

/* Size in 16-bit codes of the code at the stream head: 1 for a printable
 * code, the low nibble for a control code. */
__attribute__((section(".text.cMessCommon_getCodeSize")))
int cMessCommon_getCodeSize(unsigned int code) {
    code = code & 0xFFFF;
    if (code >> 15) {
        return code & 0xF;
    }
    return 1;
}

__attribute__((section(".text.func_002FBE28")))
void func_002FBE28(cNode *self, int flags) {
    self->vt = &D_0044FAD0;
    func_002FBDD8(self, flags);
}

__attribute__((section(".text.func_00151368")))
long func_00151368(int a0, int a1) {
    int v0 = D_007476B0 & 0x1;
    a0 = a0 + 0x3DC88;
    a0 = a0 + ((v0 << 3) + (a1 << 4));
    return *(long*)((char*)a0);
}

__attribute__((section(".text.func_002DB7A8")))
void func_002DB7A8(void) {
    cActionButton_set(&D_00568288, 0xB, 0x14, 0x11, 0, 0, 0);
}

/* Blends the colour back and forth between `from` and `to` over `frames` frames. */
__attribute__((section(".text.CustomIDWork_SetColorAnimSin")))
void CustomIDWork_SetColorAnimSin(CustomIDWork *self, int from, int to, int frames) {
    if (self->obj != 0) {
        frames = frames & 0xFFFF;
        *(int *)self->colorFrom = from;
        self->colorFlags = CIDW_ANIM_ON | CIDW_ANIM_SINE;
        *(int *)self->colorTo = to;
        self->colorTotal = frames;
        if (frames == 0) {
            self->colorTotal = 1;
        }
        self->colorCount = 0;
    }
}

__attribute__((section(".text.func_001E8E48")))
int func_001E8E48(int a0, int a1) {
    int p = *(int*)a0;
    if (p != 0) {
        return 0;
    }
    a0 = *(int*)((char*)p + 0xF0);
    if (a1 != a0) {
        *(float*)((char*)a1 + 0x0) = *(float*)((char*)a0 + 0x0);
        *(float*)((char*)a1 + 0x4) = *(float*)((char*)a0 + 0x4);
        *(float*)((char*)a1 + 0x8) = *(float*)((char*)a0 + 0x8);
    }
    return 1;
}

__attribute__((section(".text.func_001BFB28")))
int func_001BFB28(int a0){
    int *v0;
    int *v1;
    v0 = (int *)cModel_getMeshPtr(a0, 0);
    *(int *)((char *)v0 + 0x380) = *(int *)((char *)v0 + 0x380) & 0xFFFFFFFE;
    v1 = *(int **)((char *)a0 + 0x600);
    if (v1 != 0) {
        *v1 = *v1 | 1;
    }
    return 1;
}

__attribute__((section(".text.cCollisionSolidManage_ReleaseUnit")))
void cCollisionSolidManage_ReleaseUnit(cCollisionSolidManage *self, struct cGameObj *owner){
    cCollisionSolidUnit *node;
    cCollisionSolidUnit *prev;
    cCollisionSolidUnit *head;
    cCollisionSolidUnit *next;

    prev = 0;
    if (owner == 0) {
        return;
    }
    head = self->first;
    node = head;
    while (node != 0) {
        if (node->owner == owner) {
            break;
        }
        prev = node;
        node = node->next;
    }
    if (node == 0) {
        return;
    }
    next = node->next;
    if (node != head) {
        prev->next = next;
    } else {
        self->first = next;
    }
    NodeList_clear((int *)node);
    if (node != 0) {
        NodeList_deletingDtor((int *)node, 3);
    }
    self->unitNum = self->unitNum - 1;
}
