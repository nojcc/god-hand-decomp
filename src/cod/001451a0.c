/* sn-2.95.3-136 */
#include "godhand/cIDBaseScreen.h"
#include "godhand/criStm.h"

/* Copy the item attributes in (listNum bytes) and mark the list ready. num is not read: the count comes from listNum. */
__attribute__((section(".text.func_001451A0")))
void func_001451A0(cIDBaseScreen *self, const unsigned char *src, short num)
{
    func_003A5148(self->attr, src, self->listNum);
    self->flags |= SCR_FLAG_READY;
}
