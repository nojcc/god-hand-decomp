/* NM, not registered. cygnus-2.96 (drop-reorder): CRI AIX demux.
 * func_0032F988: retail keeps a 0x10 frame saving ra (inlined BE32 helpers); ours is frameless.
 * func_0032FC38: control flow matches; register allocation differs (retail spills out/n/i/ret and
 *   keeps &ck in fp/s4; ours gives out s8), 277 vs 274 words. */
#include "include_asm.h"

#ifdef NON_MATCHING

#include "godhand/criAix.h"

extern void Obj33F8_Tramp_0033F130_FCB0(const char *msg);
extern char D_00453078[];
extern char D_004530A0[];
extern char D_004530C8[];
extern void *func_003A5148(void *dst, const void *src, int n);

extern inline int aix_be32(const unsigned char *p)
{
    return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
}

extern inline int aix_be16(const unsigned char *p)
{
    return (p[0] << 8) | p[1];
}

__attribute__((section(".text.func_0032F988")))
int func_0032F988(unsigned char *p, unsigned int size, AixHdr *h)
{
    if (size < 16) {
        return 0;
    }
    h->f0 = aix_be32(p);
    h->f4 = aix_be32(p + 4);
    h->f8 = p[8];
    h->f9 = p[9];
    h->fA = aix_be16(p + 10);
    h->fC = aix_be32(p + 12);
    return 16;
}

__attribute__((section(".text.func_0032FC38")))
int func_0032FC38(AixDmx *d)
{
    int pos;
    SjObj *sj;
    int off;
    AixHdr hdr;
    SjChunk ck, rest, dst, skip;
    SjObj **out;
    int n;
    int i;
    int ret;
    int idx;

    ret = -3;
    out = d->out;
    n = d->info.nOut;
    sj = d->sj;
    for (i = 0; i < n; i++) {
        sj->vt->getChunk(sj, 1, 0x7FFFFFFF, &ck);
        for (pos = 0; pos < ck.len; pos++) {
            if (func_0032FA68((unsigned char *)ck.ptr + pos)) {
                break;
            }
        }
        if (pos > 0) {
            func_0033ACA0(&ck, pos, &ck, &skip);
            sj->vt->ungetChunk(sj, 1, &skip);
            sj->vt->putChunk(sj, 0, &ck);
            sj->vt->getChunk(sj, 1, 0x7FFFFFFF, &ck);
        }
        if ((unsigned int)ck.len < 16 ||
            func_0032F988((unsigned char *)ck.ptr, ck.len, &hdr) == 0) {
        unget:
            sj->vt->ungetChunk(sj, 1, &ck);
            return ret;
        }
        if (hdr.f0 == 0x41495845) {
            for (pos = 8; pos < ck.len; pos++) {
                if (func_0032FA68((unsigned char *)ck.ptr + pos)) {
                    break;
                }
            }
            func_0033ACA0(&ck, pos, &ck, &rest);
            sj->vt->putChunk(sj, 0, &ck);
            sj->vt->ungetChunk(sj, 1, &rest);
            if (sj->vt->getNumData(sj, 1) <= 0) {
                d->more = 0;
            }
            if (d->more == 0) {
                d->stat = 3;
            }
            return ret;
        }
        if (ck.len < hdr.f4 + 8) {
            goto unget;
        }
        idx = hdr.f8;
        if (idx >= d->nOutMax) {
            Obj33F8_Tramp_0033F130_FCB0(D_004530A0);
            sj->vt->ungetChunk(sj, 1, &ck);
            d->stat = 4;
            return ret;
        }
        if (out[idx]->vt->getNumData(out[idx], 0) < hdr.fA) {
            goto unget;
        }
        ret = hdr.fC;
        func_0033ACA0(&ck, hdr.f4 + 8, &ck, &rest);
        sj->vt->ungetChunk(sj, 1, &rest);
        func_0033ACA0(&ck, 16, &ck, &rest);
        sj->vt->putChunk(sj, 0, &ck);
        if (rest.len < hdr.fA) {
            Obj33F8_Tramp_0033F130_FCB0(D_004530C8);
            sj->vt->ungetChunk(sj, 1, &rest);
            sj->vt->ungetChunk(sj, 1, &ck);
            d->stat = 4;
            return ret;
        }
        for (off = 0; off < hdr.fA; off += dst.len) {
            out[idx]->vt->getChunk(out[idx], 0, rest.len - off, &dst);
            func_003A5148(dst.ptr, rest.ptr + off, dst.len);
            out[idx]->vt->putChunk(out[idx], 1, &dst);
        }
        sj->vt->putChunk(sj, 0, &rest);
        d->total += rest.len + 16;
    }
    return ret;
}

#else

INCLUDE_ASM("asm/nonmatching", func_0032F988);
INCLUDE_ASM("asm/nonmatching", func_0032FC38);

#endif
