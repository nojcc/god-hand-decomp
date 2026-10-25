/* include/godhand/newlibStdlib.h - newlib string conversions, multibyte decoding and ctype table (sn code at 0x3A7C28..).
 *
 * Names are newlib's.
 */
#ifndef GODHAND_NEWLIBSTDLIB_H
#define GODHAND_NEWLIBSTDLIB_H

struct _reent;

extern unsigned char D_0045F039[];      /* _ctype_ + 1: bit 1 upper, 2 lower, 4 digit, 8 space */
extern int D_003FAE28;                  /* __mb_cur_max */

double func_003A7C28(const char *s);                                                    /* atof */
int func_003A7D08(struct _reent *r, int *pwc, const char *s, unsigned int n, int *state);  /* _mbtowc_r */
double func_003A80E8(struct _reent *ptr, const char *s, char **endptr);                 /* _strtod_r */
double func_003A8FE0(const char *s, char **endptr);                                     /* strtod */
unsigned long func_003A9018(struct _reent *rptr, const char *nptr, char **endptr, int base);  /* _strtoul_r */
unsigned long func_003A9228(const char *nptr, char **endptr, int base);                 /* strtoul */
long func_003ACE90(struct _reent *rptr, const char *nptr, char **endptr, int base);     /* _strtol_r */
long func_003AD0C0(const char *nptr, char **endptr, int base);                          /* strtol */

#endif /* GODHAND_NEWLIBSTDLIB_H */
