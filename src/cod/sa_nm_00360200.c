/* NON_MATCHING func_00360200 (cygnus-2.96, -freorder-blocks dropped): 30 words vs 32; block layout matches, but retail aligns the success label with a nop, duplicates *data = 0 into a bnel delay slot, and moves the t0 copy above the ra save.
 * Next lead: as=sn (alignment nop), then the per-field ck copy order.
 * Tried: combined && test, early return, inverted test. */
#include "godhand/criSj.h"
#include "include_asm.h"

#ifdef NON_MATCHING
typedef signed char Sint8;
typedef int Sint32;
typedef struct { Sint8 *data; Sint32 len; } SjChunk;
typedef struct { Sint8 *data; Sint32 len; } SJTAG;

typedef struct {
    Sint32 loaded;
    SjChunk ck;
} ChunkSrc360;

extern Sint8 *SJ_SearchTag(SjChunk *ck, Sint8 *tag, Sint8 *endtag, SJTAG *tagck);

void func_00360200(char *self, Sint8 *tag, Sint8 *endtag, Sint8 **data, Sint32 *len)
{
    ChunkSrc360 *src = (ChunkSrc360 *)(self + 0x28);
    SjChunk ck;
    SJTAG out;

    if (src->loaded != 1 || src->ck.data == 0) {
        *data = 0;
        *len = 0;
    } else {
        ck.data = src->ck.data;
        ck.len = src->ck.len;
        SJ_SearchTag(&ck, tag, endtag, &out);
        *data = out.data;
        *len = out.len;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00360200);
#endif
