/* A separate table-base variable fixes the address order but turns the guard into bne/b (25). */
#include "godhand/criSj.h"
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[4];
    int used;      /* 0x04 */
    char pad8[0x14 - 8];
    void *sj;      /* 0x14 */
    char pad18[0x74 - 0x18];
} SfBuf;
typedef struct {
    char *data1;   /* 0x00 */
    int len1;      /* 0x04 */
    char *data2;   /* 0x08 */
    int len2;      /* 0x0C */
    int f10;
    int f14;
    int f18;
} SfBufInfo;

extern int sfbuf_PeekChunk(void *sj, int type, SjChunk *ck1, SjChunk *ck2);

int func_0034C2D0(char *sfh, int no, SfBufInfo *info, int type)
{
    SfBuf *b;
    SjChunk ck1;
    SjChunk ck2;

    info->len1 = 0;
    info->len2 = 0;
    b = (SfBuf *)(sfh + 0x1310) + no;
    info->f14 = 0;
    info->f18 = 0;
    info->data1 = 0;
    info->data2 = 0;
    info->f10 = 0;
    if (b->used == 0 || b->sj == 0)
        return 0;
    sfbuf_PeekChunk(b->sj, type, &ck1, &ck2);
    info->data1 = ck1.data;
    info->len1 = ck1.len;
    info->data2 = ck2.data;
    info->len2 = ck2.len;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0034C2D0);
#endif
