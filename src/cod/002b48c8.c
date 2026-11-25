/* ee-2.9-991111 matched TU. */
#include "godhand/cMovie.h"
#include "godhand/globals.h"

/* FreeEntrySlot_2B5BB8 is void, but retail's hook keeps a frame and returns the call's v0:
 * declared void here, the call becomes a tail jump. */
extern int FreeEntrySlot_2B5BB8(cMovie *self, int unused, void *block);

/* The movie player's free hook: FreeEntrySlot_2B5BB8 on D_005E79D0. */
__attribute__((section(".text.func_002B48C8")))
int func_002B48C8(int unused, void *block)
{
    return FreeEntrySlot_2B5BB8((cMovie *)D_005E79D0, unused, block);
}
