/* ee-2.9-991111 matched TU. */
#include "godhand/libpad.h"

/* ee-2.9-991111 */

__attribute__((section(".text.func_00397ED0")))
int func_00397ED0(int port, int slot)
{
    PadData *p;

    if (D_0077C110[port][slot].open == 0)
        return 0;
    p = func_00397BC8(port, slot, 0);
    return p->reqState;
}
