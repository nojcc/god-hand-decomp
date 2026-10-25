/* NON_MATCHING func_003A79F8 (sn-2.95.3-136): __sccl from newlib vfscanf.c, 62 vs 60 words. Retail stores
 * tab[c] in one block that the default case, the '-' fallback and the start of the loop share, and after a
 * range it reads the next character without storing; here each case keeps its own store. */
#include "include_asm.h"

#ifdef NON_MATCHING
/* __sccl: fill tab from the scanset after `[' (1 = in the set) and return the character past the closing `]'. */
__attribute__((section(".text.func_003A79F8")))
char *func_003A79F8(char *tab, char *fmt)
{
  int c, n, v;

  c = *fmt++;                   /* a leading ^ negates the set */
  if (c == '^')
    {
      v = 1;
      c = *fmt++;
    }
  else
    v = 0;
  for (n = 0; n < 256; n++)
    tab[n] = v;
  if (c == 0)
    return fmt - 1;             /* the format ended before the closing ] */

  /* The first character may be ']' or '-' without being special; the last may be '-'. */
  v = 1 - v;
  tab[c] = v;
  for (;;)
    {
      n = *fmt++;
      switch (n)
        {
        case 0:                 /* the format ended too soon */
          return fmt - 1;

        case '-':
          /* a-z is a range only if the next character is not ] and not below the last one stored;
             after a range, the next character is examined without storing it (V7 compatibility) */
          n = *fmt;
          if (n == ']' || n < c)
            {
              c = '-';
              tab[c] = v;
              break;
            }
          fmt++;
          do
            tab[++c] = v;
          while (c < n);
          break;

        case ']':
          return fmt;

        default:
          c = n;
          tab[c] = v;
          break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_003A79F8);
#endif
