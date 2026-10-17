/* NM, not registered. cygnus-2.96 (no -freorder-blocks): Sofdec picture decode (0x353928..). */
#include "include_asm.h"
#include "godhand/sftim.h"




extern unsigned char *MPV_SearchDelim(unsigned char *p, int n, unsigned int mask);
extern unsigned int MPV_CheckDelim(unsigned char *p);
extern int func_00356358(SftimHn *hn);
extern int func_00356C58(SftimHn *hn);
extern int func_0036C920(int a, int b, int c);
void func_00354128(SftimHn *hn, SfdFrm *ft);
extern SfdFrm *func_003555A8(SftimHn *hn);
extern void func_003556A0(SfdFrm *frm);
extern void func_00354430(SfdUsrBuf *dst, SfdUsrBuf *src);
extern void *func_003A5148(void *d, const void *s, unsigned int n);    /* memcpy */
void func_003542B8(SjObj *sj, int *type, unsigned char **ext, int *extLen);
extern int func_0033A010(void *sj, int id, int n);
extern long long func_0035BA58(void);
extern void func_0035BB60(SfdPrf *prf, long long t);
extern void func_00356B10(void *dec, SjObj *sj, SfdOut *out, SftimHn *hn);
extern int func_00351C18(SftimHn *hn, int a1, int n, int code);
extern void func_00351B70(SftimHn *hn, int n);
extern void func_00355630(SfdFrm *frm);
extern void func_003554F8(SftimHn *hn, int a1);
extern void func_00355658(SfdFrm *frm);
extern void func_00355640(SfdFrm *frm);
extern void func_0036C3B8(void *dec, int *a, int *b);
extern void func_00358700(SftimHn *hn, int a1, unsigned int picType);
int func_00353BD8(SftimHn *hn, SfdPicInf *pic, SfdOut *out, SfdFrm **pfrm);
void func_00353EE0(SftimHn *hn, SfdWork *work, int *x, int *y);
void func_00353F68(SftimHn *hn);
void func_00354080(SftimHn *hn, SfdFrm *ft);
void func_00354210(SftimHn *hn, SfdFrm *ft, SjObj *sj);
extern int func_00353348(SftimHn *hn, int ptype);
extern int func_00353500(SftimHn *hn, unsigned int ptype);

#ifdef NON_MATCHING
/* Register allocation: retail keeps the byte delta in its own saved register and spills work->dec; frame is 0x10 larger. */
__attribute__((section(".text.func_00353928")))
int func_00353928(SftimHn *hn, SjObj *sj)
{
    SfdCnt *cnt = &hn->cnt;
    SfdWork *work = hn->work;
    SfdErr *err = &hn->errInf;
    void *dec = work->dec;
    SfdPicInf *pic = &work->pic;
    SfdOut out;
    SfdFrm *frm;
    int x;
    int y;
    long long t0;
    int before;
    int after;
    int used;
    int ret;

    if (func_00353BD8(hn, pic, &out, &frm) != 0) {
        return 0;
    }
    func_00353EE0(hn, work, &x, &y);
    func_00354430(frm->usr, &work->usr0);
    func_00353F68(hn);
    t0 = func_0035BA58();
    before = func_0033A010(sj, 0, 1);
    func_00356B10(dec, sj, &out, hn);
    after = func_0033A010(sj, 0, 1);
    used = after - before;
    func_0035BB60(&hn->prf[pic->picType], func_0035BA58() - t0);
    cnt->f0C += out.f28;
    cnt->f10 += out.f2C;
    ret = func_00351C18(hn, after, used, 0xFF000F06);
    func_00351B70(hn, used);
    if (ret != 0) {
        func_00355630(frm);
        return ret;
    }
    if (used <= 0) {
        if (work->hold == 0) {
            func_00355630(frm);
        }
        return 0;
    }
    func_003554F8(hn, 0);
    func_00354080(hn, frm);
    func_00354210(hn, frm, sj);
    frm->f48 = work->f88;
    frm->x = out.f28 + x + work->xOfs;
    frm->y = out.f2C + y;
    if (pic->f38 == 3) {
        work->hold = 0;
    } else if (work->hold != 0) {
        work->hold = 0;
    } else {
        work->hold = frm;
    }
    work->f16C = 0;
    work->f170 = 0;
    if (work->hold == 0) {
        if (hn->mode == 3 && (pic->picType == 1 || pic->picType == 2)) {
            func_00355658(frm);
        } else {
            func_00355640(frm);
        }
        func_0036C3B8(dec, &err->f08, &err->f0C);
        work->f84 = 0;
        func_00358700(hn, 1, pic->picType);
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00353928);
#endif

#ifdef NON_MATCHING
/* Retail extracts the picture coding type with an unfolded 64-bit dsrl/andi/sll; ours folds it (one word shorter). */
__attribute__((section(".text.func_003542B8")))
void func_003542B8(SjObj *sj, int *type, unsigned char **ext, int *extLen)
{
    SjChunk ck;
    unsigned char *p;
    unsigned char *q;
    unsigned char *r;
    int n;
    int t;

    *type = 0;
    *ext = 0;
    *extLen = 0;
    sj->vt->getChunk(sj, 1, 0x7FFFFFFF, &ck);
    p = MPV_SearchDelim(ck.ptr, ck.len, 0xCC);
    if (p == 0) {
        D_003EE2F0++;
    } else if (MPV_CheckDelim(p) & 4) {
        if (ck.len < p - ck.ptr + 6) {
            D_003EE2F0++;
        } else {
            t = D_00459730[(p[5] >> 3) & 7];
            *type = t;
            if (t == 3) {
                n = ck.ptr - p + ck.len;
                q = MPV_SearchDelim(p, n, 0x22);
                if (q != 0 && (MPV_CheckDelim(q) & 0x20)) {
                    r = MPV_SearchDelim(p, n, 2);
                    if (r == 0) {
                        D_003EE2F0++;
                    } else {
                        *ext = q;
                        *extLen = r - q;
                    }
                }
            }
        }
    }
    sj->vt->ungetChunk(sj, 1, &ck);
}
#else
INCLUDE_ASM("asm/nonmatching", func_003542B8);
#endif
