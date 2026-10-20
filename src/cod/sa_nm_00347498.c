/* NON_MATCHING func_00347498: query the joint, search the tag, and either copy it into the buffer at 0x188 or hand the tag span to func_00347698.
 * Registers and prologue match.
 * Retail places the failure stores right after the search (bnez to the success block) and keeps the copy path's stores interleaved with the GetChunk setup; this form puts the failure block last. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef signed char Sint8;
typedef int Sint32;
typedef struct { Sint8 *data; Sint32 len; } SJCK;
typedef struct { Sint8 *data; Sint32 len; } SJTAG;

typedef struct Sj47498 Sj47498;

typedef struct SjIf47498 {
    void *fn[5];
    void (*fn14)(Sj47498 *sj);
    void (*GetChunk)(Sj47498 *sj, int id, int n, SJCK *ck);
    void *fn1C;
    void (*PutChunk)(Sj47498 *sj, int id, SJCK *ck);
    int (*Query)(Sj47498 *sj, int id);
} SjIf47498;

struct Sj47498 {
    SjIf47498 *vt;
};

typedef struct Rec47498 {
    int flag;          /* 0x194 */
    Sint8 *data;       /* 0x198 */
    int len;           /* 0x19C */
} Rec47498;

typedef struct Work47498 {
    char pad0[0x17C];
    Sj47498 *sj;                 /* 0x17C */
    Sint8 *buf;                  /* 0x180 */
    char pad184[4];
    void *copy;                  /* 0x188 */
    char pad18C[8];
    Rec47498 rec;                /* 0x194 */
} Work47498;

extern Sint8 D_00458C98[];
extern Sint8 D_00458CA0[];
extern Sint8 *SJ_SearchTag(SJCK *ck, Sint8 *tag, Sint8 *endtag, SJTAG *tagck);
extern void func_003A5148(void *dst, void *src, int n);
extern void func_00347698(Work47498 *w);

void func_00347498(Work47498 *w)
{
    Rec47498 *rec = &w->rec;
    Sj47498 *sj = w->sj;
    SJCK ck;
    SJTAG tag;
    SJCK got;
    int n;
    void **cp;

    n = sj->vt->Query(sj, 1);
    if (n != 0) {
        ck.data = w->buf;
        ck.len = n;
        if (SJ_SearchTag(&ck, D_00458C98, D_00458CA0, &tag) != 0) {
            cp = &w->copy;
            if (*cp != 0) {
                func_003A5148(*cp, tag.data, tag.len);
                rec->flag = 1;
                rec->data = *cp;
                rec->len = tag.len;
                sj->vt->GetChunk(sj, 1, 0x7FFFFFFF, &got);
                sj->vt->PutChunk(sj, 0, &got);
                sj->vt->fn14(sj);
                return;
            }
            rec->flag = 1;
            rec->data = tag.data;
            rec->len = tag.len;
            func_00347698(w);
            return;
        }
    }
    rec->data = 0;
    rec->flag = 1;
    rec->len = 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00347498);
#endif
