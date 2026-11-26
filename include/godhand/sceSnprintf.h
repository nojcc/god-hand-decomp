/* include/godhand/sceSnprintf.h - the kernel library's printf core (ee code at 0x3B0268..).
 *
 * The formatter sends each character to put(arg, pn, c), where *pn counts
 * the room left in the output.
 */
#ifndef GODHAND_SCESNPRINTF_H
#define GODHAND_SCESNPRINTF_H

typedef int (*SceSnprintfPut)(void *arg, int *pn, int c);

/* Format fmt with the arguments at ap through put; n is the room in the output. */
extern int _sceSnprintf(SceSnprintfPut put, void *arg, unsigned int n, const char *fmt, void *ap);
/* put for a buffer: store c at *pp and advance; the last byte of room gets the
 * terminator, and c >= 0x100 ends the string. */
extern int snprintf_char(char **pp, int *pn, int c);
/* Format fmt with the arguments after it through put; takes the count from *pn. */
extern int _sceSnprintf_pf(SceSnprintfPut put, void *arg, int *pn, const char *fmt, ...);
/* The integer part of the double whose bits are d, clamped to 0..9999. */
extern int ftoi(unsigned long long d);
/* snprintf: format fmt into buf, writing at most n bytes with the terminator. */
extern int func_003B1EE0(char *buf, int n, const char *fmt, ...);
/* Print d as 0.dddddd followed by its decimal exponent. */
extern int printfloat(SceSnprintfPut put, void *arg, int *pn, double d);

#endif /* GODHAND_SCESNPRINTF_H */
