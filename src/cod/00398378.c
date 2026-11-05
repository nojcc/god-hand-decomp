/* ee-2.9-991111 matched TU. */
#include "godhand/libpad.h"

/* ee-2.9-991111. Donor libpad.o scePadInfoPressMode. */

__attribute__((section(".text.func_00398378")))
int func_00398378(int port, int slot)
{
    PadData buf;

    if (D_0077C110[port][slot].open == 0)
        goto ng;
    func_00397BC8(port, slot, &buf);
    if (buf.ok == 1)
        goto ok;
ng:
    return 0;
ok:
    if (buf.modeConfig < 2)
        goto ng;
    if (buf.model & 2)
        return 1;
    goto ng;
}
