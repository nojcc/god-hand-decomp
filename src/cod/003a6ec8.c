/* sn-2.95.3-136 matched TU. */

#include "godhand/newlibStdio.h"

extern int func_003ADF50(int *a0, int a1);     /* _close_r */

/* __sclose: close the stream's file descriptor. */
__attribute__((section(".text.func_003A6EC8")))
int func_003A6EC8(void *cookie)
{
  FILE *fp = cookie;

  return func_003ADF50(&fp->_data->_errno, fp->_file);
}
