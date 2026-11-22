/* NON_MATCHING sfadxt_SupplyData (cygnus-2.96): same size, after the first call retail sets a3 = &used before the bnez and copies self into a0 in the delay slot
this does the reverse. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad00[0x3C];
    void (*feed)(char *self, int data, int len, int *used);
} Ops349;

extern int sfadxt_RingGetRead(char *self, int *data, int *len);
extern int sfadxt_RingAddRead(char *self, int used);
extern void sfadxt_UpdateFlowCnt(char *self);

int sfadxt_SupplyData(char *self, int *size)
{
    int data, len, used;
    Ops349 *ops;
    int r;

    *size = 0;
    ops = *(Ops349 **)(self + 0x2004);
    r = sfadxt_RingGetRead(self, &data, &len);
    if (r != 0)
        return r;
    *size = len;
    ops->feed(self, data, len, &used);
    r = sfadxt_RingAddRead(self, used);
    if (r != 0)
        return r;
    sfadxt_UpdateFlowCnt(self);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", sfadxt_SupplyData);
#endif
