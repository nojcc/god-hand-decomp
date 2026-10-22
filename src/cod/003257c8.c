/* cygnus-2.96 */
#include "godhand/adxmThread.h"

/* Raise the stop request of every ADX server thread. */
__attribute__((section(".text.func_003257C8")))
void func_003257C8(void)
{
    D_003C8158 = 1;
    D_003C8168 = 1;
    D_003C8178 = 1;
    D_003C8188 = 1;
    D_003C8198 = 1;
    D_003C81A8 = 1;
}
