/* sn-2.95.3-136 */
#include "godhand/cDvd.h"


/* Nonzero when the disc's file table (D_00580D40) has the named file (self is not read). */
__attribute__((section(".text.cDvd_FileExist")))
int cDvd_FileExist(cDvd *self, const char *name) {
    return func_001FFA68(&D_00580D40, name) != 0;
}
