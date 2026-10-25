/* sn-2.95.3-136 matched TU. */

#include "godhand/newlibStdio.h"

/* newlib libc/stdio/fvwrite.c -- __sfvwrite. */

extern void *func_003A51F4(void *dst, const void *src, unsigned int n);	/* memmove */
extern void *func_003A4FC8(const void *s, int c, unsigned int n);	/* memchr */

/*
 * Return true if the given FILE cannot be written now.
 */
#define	cantwrite(fp) \
	((((fp)->_flags & __SWR) == 0 || (fp)->_bf._base == 0) && \
	 __swsetup(fp))

#define	MIN(a, b) ((a) < (b) ? (a) : (b))
#define	COPY(n)	  (void)func_003A51F4((void *)fp->_p, (void *)p, (unsigned int)(n))

#define GETIOV(extra_work) \
	while (len == 0) { \
		extra_work; \
		p = iov->iov_base; \
		len = iov->iov_len; \
		iov++; \
	}

__attribute__((section(".text.__sfvwrite")))
int __sfvwrite(register FILE *fp, register struct __suio *uio)
{
	register unsigned int len;
	register const char *p;
	register struct __siov *iov;
	register int w, s;
	char *nl;
	int nlknown, nldist;

	if ((len = uio->uio_resid) == 0)
		return 0;

	/* make sure we can write */
	if (cantwrite (fp))
		return EOF;

	iov = uio->uio_iov;
	/* retail drops the dead initial p; GETIOV always runs first. */
	len = 0;

	if (fp->_flags & __SNBF) {
		/*
		 * Unbuffered: write up to BUFSIZ bytes at a time.
		 */
		do {
			GETIOV (;);
			w = (*fp->_write) (fp->_cookie, p, MIN (len, BUFSIZ));
			if (w <= 0)
				goto err;
			p += w;
			len -= w;
		} while ((uio->uio_resid -= w) != 0);
	} else if (nlknown = 0, (fp->_flags & __SLBF) == 0) {
		/*
		 * Fully buffered: fill partially full buffer, if any,
		 * and then flush.  If there is no partial buffer, write
		 * one _bf._size byte chunk directly (without copying).
		 */
		do {
			GETIOV (;);
			w = fp->_w;
			if (fp->_flags & __SSTR) {
				if (len < w)
					w = len;
				COPY (w);
				fp->_w -= w;
				fp->_p += w;
				w = len;
			} else if (fp->_p > fp->_bf._base && len > w) {
				/* fill and flush */
				COPY (w);
				fp->_p += w;
				if (fflush (fp))
					goto err;
			} else if (len >= (w = fp->_bf._size)) {
				/* write directly */
				w = (*fp->_write) (fp->_cookie, p, w);
				if (w <= 0)
					goto err;
			} else {
				/* fill and done */
				w = len;
				COPY (w);
				fp->_w -= w;
				fp->_p += w;
			}
			p += w;
			len -= w;
		} while ((uio->uio_resid -= w) != 0);
	} else {
		/*
		 * Line buffered: like fully buffered, but we
		 * must check for newlines.
		 */
		/* retail has no `nldist = 0` initialiser here. */
		do {
			GETIOV (nlknown = 0);
			if (!nlknown) {
				nl = (char *) func_003A4FC8 ((void *) p, '\n', len);
				nldist = nl ? nl + 1 - p : len + 1;
				nlknown = 1;
			}
			s = MIN (len, nldist);
			w = fp->_w + fp->_bf._size;
			if (fp->_p > fp->_bf._base && s > w) {
				COPY (w);
				fp->_p += w;
				if (fflush (fp))
					goto err;
			} else if (s >= (w = fp->_bf._size)) {
				w = (*fp->_write) (fp->_cookie, p, w);
				if (w <= 0)
					goto err;
			} else {
				w = s;
				COPY (w);
				fp->_w -= w;
				fp->_p += w;
			}
			if ((nldist -= w) == 0) {
				/* copied the newline: flush and forget */
				if (fflush (fp))
					goto err;
				nlknown = 0;
			}
			p += w;
			len -= w;
		} while ((uio->uio_resid -= w) != 0);
	}
	return 0;

err:
	fp->_flags |= __SERR;
	return EOF;
}
