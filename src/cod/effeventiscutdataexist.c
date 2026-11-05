/* EffEventIsCutDataExist — return whether cut-event data (group 6) is registered
 * for id+1 in the effect manager D_007419A0.  sn-2.95.3-136. */

#include "godhand/espSys.h"

__attribute__((section(".text.EffEventIsCutDataExist")))
int EffEventIsCutDataExist(unsigned int id) {
    return func_00306030(D_007419A0, 6, id + 1) != 0;
}
