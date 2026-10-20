/* cygnus-2.96: func_003398F8, SJ ring buffer GetChunk: take up to nbyte contiguous bytes from lane 0 (data) or lane 1 (free), advancing that lane's position modulo the buffer size. Other lanes clear the chunk and report -3 through the error callback. */
#include "godhand/criSj.h"
typedef struct SjRbf {
    int unk00;
    int used;                           /* 0x04 */
    int unk08;
    int nfree;                          /* 0x0C lane 1 bytes */
    int ndata;                          /* 0x10 lane 0 bytes */
    int rpos;                           /* 0x14 lane 0 position */
    int wpos;                           /* 0x18 lane 1 position */
    char *buf;                          /* 0x1C */
    int bsize;                          /* 0x20 */
    int xsize;                          /* 0x24 */
    int cnt0;                           /* 0x28 */
    int unk2C;
    int cnt1;                           /* 0x30 */
    int unk34;
    void (*errfn)(void *obj, int code); /* 0x38 */
    void *errobj;                       /* 0x3C */
} SjRbf;

extern char D_00455A80[];
extern char D_00455AB0[];
extern char D_00455AF0[];
extern char D_00455B00[];
extern char D_00455B10[];
extern char D_00455B20[];
extern void func_00339458(const char *msg, const char *fn);

#define MIN(a, b) ((a) < (b) ? (a) : (b))

__attribute__((section(".text.func_003398F8")))
void func_003398F8(SjRbf *sj, int id, int nbyte, SjChunk *ck)
{
    if (sj == 0) {
        func_00339458(D_00455AF0, D_00455A80);
        return;
    }
    if (sj->used == 0) {
        func_00339458(D_00455B00, D_00455AB0);
        return;
    }
    if (sj->bsize == 0) {
        func_00339458(D_00455B10, D_00455B20);
        return;
    }
    if (id == 0) {
        ck->len = MIN(MIN(sj->ndata, sj->bsize - sj->rpos + sj->xsize), nbyte);
        ck->data = sj->buf + sj->rpos;
        sj->rpos = (sj->rpos + ck->len) % sj->bsize;
        sj->ndata -= ck->len;
        sj->cnt0 += ck->len;
    } else if (id == 1) {
        ck->len = MIN(MIN(sj->nfree, sj->bsize - sj->wpos + sj->xsize), nbyte);
        ck->data = sj->buf + sj->wpos;
        sj->wpos = (sj->wpos + ck->len) % sj->bsize;
        sj->nfree -= ck->len;
        sj->cnt1 += ck->len;
    } else {
        ck->len = 0;
        ck->data = 0;
        if (sj->errfn != 0)
            sj->errfn(sj->errobj, -3);
    }
}
