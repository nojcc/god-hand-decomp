/* NON_MATCHING func_00347498: query the joint, search the tag, and either copy it into the buffer at 0x188 or hand the tag span to func_00347698.
* Registers and prologue match.
* Retail places the failure stores right after the search (bnez to the success block) and keeps the copy path's stores interleaved with the GetChunk setup; this form puts the failure block last. */
#include "godhand/criSj.h"
#include "include_asm.h"

#ifdef NON_MATCHING
typedef signed char Sint8;
typedef int Sint32;
typedef struct { Sint8 *data; Sint32 len; } SjChunk;
typedef struct { Sint8 *data; Sint32 len; } SJTAG;

typedef struct TagRec {
    int flag;          /* 0x194 */
    Sint8 *data;       /* 0x198 */
    int len;           /* 0x19C */
} TagRec;

typedef struct TagWork {
    char pad0[0x17C];
    SjObj *sj;                 /* 0x17C */
    Sint8 *buf;                  /* 0x180 */
    char pad184[4];
    void *copy;                  /* 0x188 */
    char pad18C[8];
    TagRec rec;                /* 0x194 */
} TagWork;

extern Sint8 D_00458C98[];
extern Sint8 D_00458CA0[];
extern Sint8 *SJ_SearchTag(SjChunk *ck, Sint8 *tag, Sint8 *endtag, SJTAG *tagck);
extern void *func_003A5148(void *d, const void *s, unsigned int n);
extern void func_00347698(TagWork *w);

void func_00347498(TagWork *w)
{
    TagRec *rec = &w->rec;
    SjObj *sj = w->sj;
    SjChunk ck;
    SJTAG tag;
    SjChunk got;
    int n;
    void **cp;

    n = sj->vt->getNumData(sj, 1);
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
                sj->vt->getChunk(sj, 1, 0x7FFFFFFF, &got);
                sj->vt->putChunk(sj, 0, &got);
                sj->vt->reset(sj);
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
