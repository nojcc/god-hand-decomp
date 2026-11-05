/* ee-2.9-991111 matched TU. */
#include "godhand/libio.h"

extern int D_00755BC8;
extern void __do_global_ctors(void);
extern void _sceMpegWaitIpuIdle(int);

__attribute__((section(".text.func_0031DB50")))
void func_0031DB50(void) {
    if (D_00755BC8 == 0) {
        D_00755BC8 = 1;
        __do_global_ctors();
    }
}

/* libio genops.c :: _IO_unsave_markers */
__attribute__((section(".text.func_0038D140")))
void func_0038D140(struct _IO_FILE *fp) {
    if (fp->_markers != 0) {
        fp->_markers = 0;
    }
    if (fp->_IO_save_base != 0) {
        _IO_free_backup_area(fp);
    }
}

__attribute__((section(".text.func_003A0DE8")))
void func_003A0DE8(int a0) {
    if ((*(volatile unsigned int *)0x10002010 & 0x80004000) == 0x80000000) {
        _sceMpegWaitIpuIdle(a0);
    }
}
