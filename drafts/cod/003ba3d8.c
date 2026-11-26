/* NON_MATCHING func_003BA3D8 (cygnus-2.96, -freorder-blocks dropped): 2 instructions off. Retail fills the
 * fscod < 3 branch's delay slot without annulling (bnez) and annuls the frmsizecod < 38 one (bnel); this
 * C gives the opposite pair, with the same instructions in the slots. */
#include "include_asm.h"
#include "godhand/sjFeedCtl.h"
#include "godhand/ac3Hdr.h"

#ifdef NON_MATCHING
/* Parse the AC-3 sync word and the sample-rate and frame-size codes of the header at hdr into the
 * feed. Returns 0, or -1 for a bad sync word or code. */
__attribute__((section(".text.func_003BA3D8")))
int func_003BA3D8(SjFeedCtl *feed, unsigned char *hdr)
{
    unsigned int fscod;
    unsigned int frmsizecod;
    int off;

    if (hdr[0] == AC3_SYNC_HI && hdr[1] == AC3_SYNC_LO) {
        feed->copyMode = 1;
        off = 4;
    } else if (hdr[0] == AC3_SYNC_LO && hdr[1] == AC3_SYNC_HI) {
        feed->copyMode = 2;
        off = 5;
    } else {
        func_003B9DE0(D_00460978);
        return -1;
    }
    hdr += off;
    fscod = *hdr >> 6;
    if (fscod >= AC3_FSCOD_NUM) {
        func_003B9DE0(D_004609A8);
        return -1;
    }
    feed->sampleRate = D_003FC518[fscod];
    frmsizecod = *hdr & 0x3F;
    if (frmsizecod >= AC3_FRMSIZ_NUM) {
        func_003B9DE0(D_004609D8);
        return -1;
    }
    feed->bitRate = D_003FC528[frmsizecod];
    feed->step = D_003FC5C8[fscod * AC3_FRMSIZ_STRIDE + frmsizecod] * 2;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003BA3D8);
#endif
