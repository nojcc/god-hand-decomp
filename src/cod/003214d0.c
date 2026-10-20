/* cygnus-2.96: __uncatch_exception (exception.cc). */
#include "godhand/eh.h"

extern cp_eh_info **func_00320360(void);
extern void terminate(void) __attribute__((noreturn));

__attribute__((section(".text.__uncatch_exception")))
void __uncatch_exception(void)
{
    cp_eh_info *info = *func_00320360();
    if (info == 0)
        terminate();
    info->caught = 0;
}
