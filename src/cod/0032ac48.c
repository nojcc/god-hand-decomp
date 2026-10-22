/* cygnus-2.96 */
#include "godhand/criSj.h"

/* View of the ADX handle fields the decode-limit setter uses. */
typedef struct AdxDecLimitView {
    char pad00[0x8];
    void *sjd;                          /* 0x08 */
    char pad0C[0x30];
    short maxLimit;                     /* 0x3C */
    short limit;                        /* 0x3E */
} AdxDecLimitView;

extern char D_00452348[];
extern int func_00328C80(void *h, int a, int b);

/* Set the handle's decode limit from a time (seconds times rate, in 32-sample units, times channels
 * and 18-byte blocks), capped at its maximum, and pass it on to the decoder. */
__attribute__((section(".text.func_0032AC48")))
void func_0032AC48(AdxDecLimitView *adx, float sec, int nch, int rate)
{
    int n;

    if (adx == 0) {
        func_0033F130(D_00452348);
        return;
    }
    n = (int)(sec * rate) / 32 * nch * 18 / 2048;
    adx->limit = (n < adx->maxLimit) ? n : adx->maxLimit;
    if (adx->sjd != 0) {
        func_00328C80(adx->sjd, adx->limit << 11, adx->maxLimit << 11);
    }
}
