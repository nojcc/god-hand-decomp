#include "godhand/criStm.h"
#include "godhand/cIDBaseScreen.h"
#include "godhand/cIDBaseScreenFn.h"

/* Copy listNum attribute bytes from src into the screen and mark it ready. num is not read. */
__attribute__((section(".text.func_001451A0")))
void func_001451A0(cIDBaseScreen *self, unsigned char *src, short num)
{
    func_003A5148(self->attr, src, (unsigned int)self->listNum);
    self->flags |= SCR_FLAG_READY;
}
