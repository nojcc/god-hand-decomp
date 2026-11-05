/* ee-2.9-991111 matched TU. */
#include "godhand/libpad.h"
#include "godhand/criStm.h"

/* ee-2.9-991111 */


__attribute__((section(".text.func_00397D20")))
int func_00397D20(int port, int slot, unsigned char *data)
{
    PadData buf;

    if (D_0077C110[port][slot].open == 0)
        return 0;
    func_00397BC8(port, slot, &buf);
    func_003A5148(data, &buf, buf.length);
    return buf.length;
}
