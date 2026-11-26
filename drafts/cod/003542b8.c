/* cygnus-2.96, -freorder-blocks dropped. NON_MATCHING sfmpv_PeekNextPicUd: 91 words vs retail 93,
 * the picture-type index only. Retail extracts the 3 bits with dsrl/andi and then sll 2; the
 * plain C folds that to srl 1/andi 0x1C, and an unsigned long copy of the byte adds a 64-to-32
 * truncation (95 words). Its home is src/cod/00353928.c, after sfmpv_ChangePicUd, whose local
 * prototype gives ext as unsigned char ** (this takes Sint8 **, the type MPV_SearchDelim returns). */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/sftim.h"
#include "godhand/MpvHandle.h"
/* Looks ahead in sj for the next start code. If it is a picture header, type
 * gets its coding type, and for a B picture ext and extLen get the user data
 * that follows it, up to the first slice. A missing or cut-off header, or
 * user data with no slice after it, counts a delimiter search error. */
__attribute__((section(".text.sfmpv_PeekNextPicUd")))
void sfmpv_PeekNextPicUd(SjObj *sj, int *type, Sint8 **ext, int *extLen)
{
    SjChunk ck;
    Sint8 *psc;
    Sint8 *ud;
    Sint8 *end;
    int len;

    *type = 0;
    *ext = 0;
    *extLen = 0;
    sj->vt->getChunk(sj, 1, 0x7FFFFFFF, &ck);
    psc = MPV_SearchDelim(ck.data, ck.len, MPV_DLM_PSC | MPV_DLM_GSC | MPV_DLM_SHC | MPV_DLM_SEC);
    if (psc == 0) {
        D_003EE2F0++;
    } else if (MPV_CheckDelim(psc) & MPV_DLM_PSC) {
        if (ck.len < psc - ck.data + 6) {
            D_003EE2F0++;
        } else {
            *type = D_00459730[((Uint8)psc[5] >> 3) & 7];
            if (*type == 3) {
                len = ck.data - psc + ck.len;
                ud = MPV_SearchDelim(psc, len, MPV_DLM_UDSC | MPV_DLM_SLICE_TOP);
                if (ud != 0 && (MPV_CheckDelim(ud) & MPV_DLM_UDSC)) {
                    end = MPV_SearchDelim(psc, len, MPV_DLM_SLICE_TOP);
                    if (end == 0) {
                        D_003EE2F0++;
                    } else {
                        *ext = ud;
                        *extLen = end - ud;
                    }
                }
            }
        }
    }
    sj->vt->ungetChunk(sj, 1, &ck);
}
#else
INCLUDE_ASM("asm/nonmatching", sfmpv_PeekNextPicUd);
#endif
