/* sn-2.95.3-136 matched TU. */
#include "godhand/cRelSys.h"
#include "godhand/cEm00.h"
#include "godhand/cSnd.h"
#include "godhand/seqNode.h"
#include "godhand/cNode.h"
#include "godhand/heapArena.h"
#include "godhand/cScenario.h"
#include "godhand/mtx.h"

extern char D_0044A408[];
extern int cTaskManager_execute_2D54F0(cTaskManager *task, void *entry, void *arg, int slot);
extern char D_0044E090[];

/* clone */




__attribute__((section(".text.func_0028B148")))
void func_0028B148(cEm00 *self, int flags) {
    self->vtable = (cVtEnt *)D_0044A408;
    func_0028BEA8(self);
    func_0028EB88((struct cGameObj *)self, flags);
}

/* clone */


__attribute__((section(".text.func_0028CE70")))
void func_0028CE70(cEm00 *self) {
    void *v = self->unk1630;
    if (v) {
        __builtin_vec_delete(v);
        self->unk1630 = 0;
    }
}

/* clone */

__attribute__((section(".text.func_002AF6B8")))
void func_002AF6B8(char *arg0, int arg1) {
    if (arg1) {
        *(int *)(arg0 + 0x0) |= 1;
    } else {
        *(int *)(arg0 + 0x0) &= ~1;
    }
}

/* clone */

__attribute__((section(".text.func_002AF6E0")))
void func_002AF6E0(char *arg0, int arg1) {
    if (arg1) {
        *(int *)(arg0 + 0x0) |= 2;
    } else {
        *(int *)(arg0 + 0x0) &= ~2;
    }
}

/* clone */


__attribute__((section(".text.func_002B6350")))
void func_002B6350(void *node, void *src) { MtxCopy((char *)node + 0xB0, src); }

/* clone */


__attribute__((section(".text.func_002BDBD0")))
void func_002BDBD0(int *a0) {
    unsigned char x = *(unsigned char *)((char *)a0 + 0x10);
    if (((x ^ 1) & 1) == 0) {
        func_002BDC00();
    }
}

/* clone */


__attribute__((section(".text.func_002BE858")))
void func_002BE858(cRelSlot *slots, int idx) {
    /* an int sum: &slots[idx] adds the two operands the other way round */
    cRelSlot *p = (cRelSlot *)(idx * 8 + (int)slots);
    if (p->ok == 1)
        HeapBuf_release(p);
}

/* clone */



__attribute__((section(".text.cScenario_taskExec_2C38D8")))
/* Start entry(arg) as a script task in `slot`; returns its index or -1. */
int cScenario_taskExec_2C38D8(cScenario *self, void *entry, void *arg, int slot) {
    int no = cTaskManager_execute_2D54F0(&self->task, entry, arg, slot);
    do {
        cScenario_clearTaskData(self, no);
        return no;
    } while (0);
}

/* clone */



__attribute__((section(".text.cSndBgmNode_Dtor")))
void cSndBgmNode_Dtor(cSndBgmNode *node, int flags) {
    node->vt = D_0044CEE8;
    func_00372C80((SndVoiceNode *)node, flags);
}

/* clone */



__attribute__((section(".text.func_002E16B0")))
void func_002E16B0(cNode *self, int flags) {
    self->vt = D_0044E090;
    func_002FBE28(self, flags);
}
