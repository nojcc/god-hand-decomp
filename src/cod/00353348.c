/* cygnus-2.96 */
#include "godhand/sftim.h"

/* Whether a picture of type ptype is skipped at the work area's skip level. */
__attribute__((section(".text.func_00353348")))
int func_00353348(SftimHn *hn, int ptype)
{
    int ret = 0;

    switch (hn->work->skipLevel) {
    case 2:
        if (ptype == 2 || ptype == 3)
            ret = 1;
        break;
    case 3:
        if (ptype == 3)
            ret = 1;
        break;
    case 4:
        break;
    }
    return ret;
}
