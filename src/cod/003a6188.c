/* sn-2.95.3-136 */

#include "godhand/newlibStdio.h"

/* newlib libc/stdio/findfp.c. */

/* Set up one of the three standard streams of a reent block. */
__attribute__((section(".text.Obj0000_Setup_Fields_00_04_08_0C_0E_10_18_1C_20_24_28_2C_54")))
void Obj0000_Setup_Fields_00_04_08_0C_0E_10_18_1C_20_24_28_2C_54(FILE *ptr, int flags, int file, struct _reent *data)
{
  ptr->_p = 0;
  ptr->_r = 0;
  ptr->_w = 0;
  ptr->_flags = flags;
  ptr->_file = file;
  ptr->_bf._base = 0;
  ptr->_lbfsize = 0;
  ptr->_cookie = ptr;
  ptr->_read = __sread;
  ptr->_write = __swrite;
  ptr->_seek = __sseek;
  ptr->_close = func_003A6EC8;
  ptr->_data = data;
}

/* __sinit: install the cleanup hook and the stdin/stdout/stderr streams. */
__attribute__((section(".text.func_003A61F0")))
void func_003A61F0(struct _reent *s)
{
  s->__cleanup = func_003A6290;
  s->__sdidinit = 1;
  Obj0000_Setup_Fields_00_04_08_0C_0E_10_18_1C_20_24_28_2C_54(s->__sf + 0, __SRD, 0, s);
  Obj0000_Setup_Fields_00_04_08_0C_0E_10_18_1C_20_24_28_2C_54(s->__sf + 1, __SWR | __SLBF, 1, s);
  Obj0000_Setup_Fields_00_04_08_0C_0E_10_18_1C_20_24_28_2C_54(s->__sf + 2, __SWR | __SNBF, 2, s);
  s->__sglue._next = NULL;
  s->__sglue._niobs = 3;
  s->__sglue._iobs = &s->__sf[0];
}

/* _cleanup_r: flush every stream of a reent block. */
__attribute__((section(".text.func_003A6290")))
void func_003A6290(struct _reent *ptr)
{
  func_003A6830 (ptr, fflush);
}

/* _cleanup: flush every stream of the global reent block. */
__attribute__((section(".text.func_003A62B0")))
void func_003A62B0(void)
{
  func_003A6290 (_REENT);
}
