#include "godhand/heapArena.h"
typedef struct SndStm {
    void *handle;                       /* 0x00 */
    void *mem;                          /* 0x04 */
    int size;                           /* 0x08 */
    int unk0C;
    int nch;                            /* 0x10 */
} SndStm;

extern void *func_0031C8E0(int size, int align, void *heap);
extern void func_0031C928(void *mem, void *heap);
extern void *func_00329438(int nch, void *mem, int size);
extern void *func_003297A8(void *mem, int size);

__attribute__((section(".text.func_00373BA8")))
int func_00373BA8(SndStm *s, int freq, int nblk, int mode, int flag)
{
    int nch = s->nch;

    if (nch >= 2 || flag == 0) {
        if (mode == 1)
            s->size = nch * 0x40C0 + 0x40;
        else {
            int hdr = nch * 0x40C0 + 0x24;

            s->size = ((25000 * nch * (freq / 1000) / 44 * (nblk + 1) + 0x800) / 0x800 * 0x800) + hdr + 0x40;
        }
        s->mem = func_0031C8E0(s->size, 0x40, &D_00754210);
        if (s->mem == 0)
            return 0;
        s->handle = func_00329438(s->nch, s->mem, s->size);
    } else {
        if (mode == 1)
            s->size = 0x85C0;
        else
            s->size = (((freq / 1000) * 25000 / 44 * (nblk + 1) + 0x800) / 0x800 * 0x800) + 0x85E4;
        s->mem = func_0031C8E0(s->size, 0x40, &D_00754210);
        if (s->mem == 0)
            return 0;
        s->handle = func_003297A8(s->mem, s->size);
    }
    if (s->handle == 0) {
        func_0031C928(s->mem, &D_00754210);
        s->mem = 0;
        return 0;
    }
    return 1;
}
