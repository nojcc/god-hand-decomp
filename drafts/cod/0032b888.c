/* NON_MATCHING func_0032B888 (cygnus-2.96) */
#include "godhand/criSj.h"
#include "include_asm.h"
#include "godhand/criStm.h"

#ifdef NON_MATCHING
/* func_0032B888, write up to nsmpl samples of ADX silence (18 bytes per channel per 32-sample block) into the output stream joint, in whole blocks across the ring wrap.
* Returns the number of samples written. */

typedef struct AdxEnc {
    char pad00[0x14];
    SjObj *sj;                       /* 0x14 */
} AdxEnc;

extern void func_0033ACA0(SjChunk *ck, int len, SjChunk *head, SjChunk *tail);

__attribute__((section(".text.func_0032B888")))
int func_0032B888(AdxEnc *enc, int nch, int nsmpl)
{
    SjObj *sj;
    SjChunk ck;
    SjChunk rest;
    int unit;
    int size;
    int len;
    int total;

    unit = nch * 18;
    sj = enc->sj;
    if (sj == 0)
        return 0;
    size = nsmpl / 32 * unit;
    sj->vt->getChunk(sj, 0, size, &ck);
    len = ck.len / unit * unit;
    total = len;
    func_003A52F0(ck.data, 0, len);
    func_0033ACA0(&ck, len, &ck, &rest);
    sj->vt->putChunk(sj, 1, &ck);
    sj->vt->ungetChunk(sj, 0, &rest);
    sj->vt->getChunk(sj, 0, size - total, &ck);
    len = ck.len / unit * unit;
    func_003A52F0(ck.data, 0, len);
    total += len;
    func_0033ACA0(&ck, len, &ck, &rest);
    sj->vt->putChunk(sj, 1, &ck);
    sj->vt->ungetChunk(sj, 0, &rest);
    return total / unit * 32;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0032B888);
#endif
