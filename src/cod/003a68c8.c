/* sn-2.95.3-136 matched TU. */

#include "godhand/newlibStdio.h"

/* newlib libc/stdio -- transcribed. */

__attribute__((section(".text.fwrite")))
unsigned int fwrite(const void *buf, unsigned int size, unsigned int count, FILE *fp)
{
  unsigned int n;
  struct __suio uio;
  struct __siov iov;

  iov.iov_base = buf;
  uio.uio_resid = iov.iov_len = n = count * size;
  uio.uio_iov = &iov;
  uio.uio_iovcnt = 1;

  /*
   * The usual case is success (__sfvwrite returns 0);
   * skip the divide if this happens, since divides are
   * generally slow and since this occurs whenever size==0.
   */

  if (__sfvwrite (fp, &uio) == 0)
    return count;
  return (n - uio.uio_resid) / size;
}
