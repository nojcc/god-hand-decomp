/* sn-2.95.3-136 matched TU. */
#include "godhand/cMovie.h"
#include "godhand/globals.h"

/* The movie player's malloc hook: func_002B5AF8 on D_005E79D0. */
__attribute__((section(".text.func_002B48A0")))
void *func_002B48A0(int unused, unsigned int size)
{
    return func_002B5AF8((cMovie *)D_005E79D0, unused, size);
}
