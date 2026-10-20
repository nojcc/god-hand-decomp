/* NON_MATCHING func_00339AE8 (cygnus-2.96, -freorder-blocks dropped; PARK 69 at attempt 4): SJ ring buffer put chunk: count data (lane 1) or free space (lane 0) back in, mirroring the wrap area. Logic and loads match; retail keeps id in v1 from entry and the chunk length in t0 with a t1 copy, so off and end share v1 and the first wrap test fills its delay slot without a branch-likely (2 words). A length local and a switch on id change nothing (72). */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/criSj.h"

#define SJ_ERR_BADID  (-3)

typedef struct SjRbf339AE8 {
    char unk00[4];
    int used;                           /* 0x04 */
    char unk08[4];
    int dataLen;                        /* 0x0C */
    int freeLen;                        /* 0x10 */
    char unk14[8];
    unsigned char *buf;                 /* 0x1C */
    int bsize;                          /* 0x20 */
    int xsize;                          /* 0x24 extra area mirrored past the end */
    char unk28[4];
    int freeTotal;                      /* 0x2C */
    char unk30[4];
    int dataTotal;                      /* 0x34 */
    void (*errFn)(void *arg, int err);  /* 0x38 */
    void *errArg;                       /* 0x3C */
} SjRbf339AE8;

extern char D_00455A80[];
extern char D_00455AB0[];
extern char D_00455B38[];
extern char D_00455B48[];

extern void func_00339458(char *where, char *msg);
extern void func_003A5148(void *dst, const void *src, int n);

__attribute__((section(".text.func_00339AE8")))
void func_00339AE8(SjRbf339AE8 *sj, int id, SjChunk *ck)
{
    int off;
    int end;
    int n;

    if (sj == 0) {
        func_00339458(D_00455B38, D_00455A80);
        return;
    }
    if (sj->used == 0) {
        func_00339458(D_00455B48, D_00455AB0);
        return;
    }
    if (ck->len <= 0 || ck->ptr == 0)
        return;
    if (id == 1) {
        off = ck->ptr - sj->buf;
        if (off < sj->xsize) {
            n = sj->xsize - off;
            if (ck->len < n)
                n = ck->len;
            func_003A5148(&sj->buf[sj->bsize + off], ck->ptr, n);
        }
        end = ck->ptr - sj->buf + ck->len;
        if (sj->bsize < end) {
            n = end - sj->bsize;
            if (ck->len < n)
                n = ck->len;
            func_003A5148(sj->buf, &sj->buf[end - n], n);
        }
        sj->dataLen += ck->len;
        sj->dataTotal += ck->len;
    } else if (id == 0) {
        sj->freeLen += ck->len;
        sj->freeTotal += ck->len;
    } else {
        ck->ptr = 0;
        ck->len = 0;
        if (sj->errFn != 0)
            sj->errFn(sj->errArg, SJ_ERR_BADID);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00339AE8);
#endif
