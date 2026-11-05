/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/cOmBase.h"
#include "godhand/heapArena.h"

extern int D_00747A84;
extern char D_005E8658[];
extern char D_005CAE50[];
extern void func_002BECB0(void *a0, long a1);
extern void func_001331B8(void *a0, long a1, int a2);
extern void func_001B7BB8(void *a0);
extern int *D_003C2384;
extern void cIDBase_clear(int a0);
extern void cIDBase_resetAnim(int a0);

/* Retire the object: unhide it, release its model and collision, drop its item and mark it gone. */
__attribute__((section(".text.SetField5B0Bit2ClearBit8_1B7908")))
void SetField5B0Bit2ClearBit8_1B7908(cOmBase *self) {
    long v = (unsigned int)self->flags2;
    if ((v >> 9 & 1) == 0) {
        if ((D_00747A84 & 0x01000000) == 0) {
            self->flags2 = self->flags2 & ~COMBASE_FLAG_HIDDEN;
        }
    }
    func_002BECB0(D_005E8658, self->name);
    func_001331B8(D_005CAE50, self->modelHandle, 0);
    cCollisionSolidManage_ReleaseUnit(&D_00462FC0, (struct cGameObj *)self);
    func_001B7BB8(self);
    self->flags0 = (self->flags0 | COMBASE_F0_GONE) & ~8;
}


/* Give the block at p back to the block before it (heap is not read). */
__attribute__((section(".text.cHeap_free")))
void cHeap_free(HeapArena *heap, void *p) {
    HeapBlk *blk;
    HeapBlk *prev;
    if (p != 0) {
        blk = (HeapBlk *)p - 1;
        prev = blk->prev;
        prev->next = blk->next;
        prev->freeSize = prev->freeSize + (blk->usedSize + blk->freeSize);
        blk = blk->next;
        if (blk != 0) {
            blk->prev = prev;
        }
    }
}

/* Set or clear display flag bit 13 on every mesh node of one layer. */
__attribute__((section(".text.SetField380Bit2000ForTag_1B7300")))
void SetField380Bit2000ForTag_1B7300(void *model, int layer, int clear) {
    cMeshNode *node = (cMeshNode *)cModel_getMeshPtr(model, 0);
    if (node != 0) {
        do {
            if (node->layer == layer) {
                unsigned int v;
                if (clear == 1) {
                    v = node->dispFlags & 0xFFFFDFFF;
                } else {
                    v = node->dispFlags | 0x2000;
                }
                node->dispFlags = v;
            }
            node = node->next;
        } while (node != 0);
    }
}
