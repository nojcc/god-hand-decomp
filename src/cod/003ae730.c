/* sn-2.95.3-136 matched TU. */

#include "godhand/newlibStdio.h"

/* newlib libc/stdio/wsetup.c -- __swsetup. */
__attribute__((section(".text.__swsetup")))
int __swsetup(register FILE *fp)
{
    /* make sure stdio is set up */
    CHECK_INIT (fp);

    /*
     * If we are not writing, we had better be reading and writing.
     */
    if ((fp->_flags & __SWR) == 0) {
        if ((fp->_flags & __SRW) == 0) {
            return EOF;
        }
        if (fp->_flags & __SRD) {
            fp->_flags &= ~(__SRD | __SEOF);
            fp->_r = 0;
            fp->_p = fp->_bf._base;
        }
        fp->_flags |= __SWR;
    }

    /*
     * Make a buffer if necessary, then set _w.
     */
    if (fp->_bf._base == NULL) {
        __smakebuf (fp);
    }

    if (fp->_flags & __SLBF) {
        fp->_w = 0;
        fp->_lbfsize = -fp->_bf._size;
    } else {
        fp->_w = fp->_flags & __SNBF ? 0 : fp->_bf._size;
    }

    return 0;
}
