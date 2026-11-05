/* sn-2.95.3-136 */
#include "godhand/cEm00.h"

/* Raises the step timer to at least time. */
__attribute__((section(".text.func_0027DD10")))
void func_0027DD10(cEm00 *self, float time) {
    if (self->stepVar.time < time)
        self->stepVar.time = time;
}
