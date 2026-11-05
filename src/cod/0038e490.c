/* ee-2.9-991111 matched TU. */
#include "godhand/libio.h"
#include "godhand/eeKernel.h"
#include "godhand/sceDma.h"


/* MATCH via ee-2.9-991111. */


__attribute__((section(".text._IO_seekpos")))
void _IO_seekpos(struct _IO_FILE *fp, int pos, int mode)
{
    if (fp->_IO_save_base != 0)
        _IO_free_backup_area(fp);
    ((void (*)(struct _IO_FILE *, int, int))fp->vtable->__seekpos.pfn)(fp, pos, mode);
}

/* MATCH via ee-2.9-991111. */



__attribute__((section(".text.func_003973E8")))
void func_003973E8(sceDmaChan *chan, void *tag)
{
    unsigned int addr = func_003970A0((unsigned int)tag);
    WaitDma(chan);
    if ((unsigned int)chan->tadr != 0xFFFFFFFFU)
        chan->tadr = (void *)addr;
    chan->qwc = 0;
    chan->chcr = (chan->chcr & ~0xC) | 0x105;
}

/* MATCH via ee-2.9-991111. */



__attribute__((section(".text.func_003B35F8")))
int func_003B35F8(int *a0)
{
    int p;
    DIntr();
    p = a0[3];
    if (p == 0) {
        a0[1] = 0;
    } else {
        a0[3] = ((int *)p)[0xF];
        a0[1] = 1;
    }
    EIntr();
    return p;
}
