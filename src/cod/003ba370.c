/* cygnus-2.96 */
#include "godhand/sjFeedCtl.h"

/* Even offset of the first AC-3 sync word (0B 77 or 77 0B) in the n bytes at p: 0 when n < 3, and
 * n or more when there is none. */
__attribute__((section(".text.ac3cnv_search_header")))
int ac3cnv_search_header(unsigned char *p, int n)
{
    int i;

    if (n < 3)
        return 0;
    for (i = 0; i < n; i += 2) {
        if (p[i] == 0x0B && p[i + 1] == 0x77)
            break;
        if (p[i] == 0x77 && p[i + 1] == 0x0B)
            break;
    }
    return i;
}
