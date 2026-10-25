/* sn-2.95.3-136 */

#include "godhand/newlibStdio.h"
#include "godhand/newlibStdlib.h"

/* strtod on the global reent block. */
__attribute__((section(".text.func_003A8FE0")))
double func_003A8FE0(const char *s, char **endptr)
{
  return func_003A80E8 (_REENT, s, endptr);
}
