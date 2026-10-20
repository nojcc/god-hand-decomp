/* sn-2.95.3-136: func_00148420, set up a motion/stream object from a data header and allocate its work buffer. */
#include "godhand/cModel.h"
extern void *D_003C3CF0;
extern void cHeap_free(void *heap, void *p);
extern void *EnsureInitThenForward_2A9538_30EE08(int size, int align, void *region);
extern int func_00155138(cModelNode *self);
extern int func_00155248(cModelNode *self);
extern void func_00154A90(cModelNode *self, void *buf, void *heap);
extern void func_00155358(cModelNode *self, void *buf, void *heap);
extern void func_00148F50(cModelNode *self, cMeshData **data, int a2);
extern void func_001490B0(cModelNode *self, cMeshData **data, int a2);

__attribute__((section(".text.func_00148420")))
int func_00148420(cModelNode *self, cMeshData *data, int a2, unsigned int flags,
                  int a4, int a5, void *heap)
{
    void *p;
    int n;
    int multi;
    cMeshData *d;

    self->unk400 = a2;
    self->unk384 = 0;
    self->dispFlags = flags;
    self->tag = 0;
    self->data = data;
    n = data->num;
    self->meshNum = n;
    d = data;
    if (self->pktBuf != 0)
        cHeap_free(((void **)self->pktBuf)[-8], (void *)self->pktBuf);

    multi = d->num >= 2;
    if (multi) {
        int size = func_00155138(self);
        if (heap == 0) {
            p = EnsureInitThenForward_2A9538_30EE08(size, 0x10, D_003C3CF0);
            self->pktBuf = (int)p;
            if (p == 0)
                return 0;
            func_00154A90(self, p, 0);
        } else {
            p = EnsureInitThenForward_2A9538_30EE08(size, 0x10, heap);
            self->pktBuf = (int)p;
            if (p == 0)
                return 0;
            func_00154A90(self, p, heap);
        }
    } else {
        int size = func_00155248(self);
        if (heap == 0)
            self->pktBuf = EnsureInitThenForward_2A9538_30EE08(size, 0x10, D_003C3CF0);
        else
            self->pktBuf = EnsureInitThenForward_2A9538_30EE08(size, 0x10, heap);
        if (self->pktBuf == 0)
            return 0;
        func_00155358(self, self->pktBuf, 0);
    }

    if (flags & 0x1000000)
        func_00148F50(self, &d, a5);
    else
        func_001490B0(self, &d, a5);
    return 1;
}
