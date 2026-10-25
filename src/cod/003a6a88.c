/* sn-2.95.3-136 */

#include "godhand/newlibStdio.h"

/* lflush (newlib refill.c): this build flushes every stream it is handed. */
__attribute__((section(".text.func_003A6A88")))
int func_003A6A88(FILE *fp)
{
  return fflush (fp);
}
