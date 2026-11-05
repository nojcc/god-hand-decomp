/* ee-2.9-991111 matched TU. */
#include "godhand/newlibMalloc.h"
#include "godhand/libio.h"
#include "godhand/sceDma.h"

__attribute__((section(".text.func_003974D0")))
void func_003974D0(sceDmaChan *chan, void *addr, int qwc) {
    unsigned int dst = func_003970A0((unsigned int)addr);
    int chcr;
    WaitDma(chan);
    if ((unsigned int)chan->madr != 0xFFFFFFFFU)
        chan->madr = (void *)dst;
    chan->qwc = qwc;
    chcr = chan->chcr & ~0xC;   /* normal mode */
    chan->chcr = (chcr & ~1) | 0x100; /* into memory, start */
}

__attribute__((section(".text._IO_seekoff")))
int _IO_seekoff(struct _IO_FILE *fp, long offset, int dir, int mode) {
    if (fp->_IO_save_base != 0) {
        if (dir == 1 && (fp->_flags & _IO_IN_BACKUP))
            offset -= fp->_IO_read_end - fp->_IO_read_ptr;
        _IO_free_backup_area(fp);
    }
    return ((int (*)(struct _IO_FILE *, long, int, int))fp->vtable->__seekoff.pfn)(fp, offset, dir, mode);
}

__attribute__((section(".text.func_0038C768")))
void func_0038C768(struct _IO_FILE *f, char *b, char *eb, int a) {
    if (f->_IO_buf_base && !(f->_flags & _IO_USER_BUF))
        UpdateGlobalPtrWithParam_3A7CC0(f->_IO_buf_base);
    f->_IO_buf_base = b;
    f->_IO_buf_end = eb;
    if (a)
        f->_flags &= ~_IO_USER_BUF;
    else
        f->_flags |= _IO_USER_BUF;
}
