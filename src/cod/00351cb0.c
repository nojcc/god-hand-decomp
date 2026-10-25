/* cygnus-2.96: func_00351CB0, Sofdec MPV picture header decode step. */
#include "godhand/sftim.h"
typedef int (*MpvCb)(void *obj, int a, int b);

extern void func_0036A3A8(int h, int a, int b);
extern int func_0033A010(int s, int a, int b);
extern int func_0036A3E8(int h, int s);
extern int func_00351C18(char *mpv, int a, int n, int code);
extern void func_00351B70(char *mpv, int n);
extern int func_0036A0D0(int h, int *hdr);
extern void func_0036A3C0(int h, int a, void *p);
extern char *MPV_SearchDelim(char *p, int len, int kind);
extern void func_00352008(char *mpv, int *hdr, char *p, long *a, long *b, int f);
extern void func_00352298(char *mpv, int *hdr, int f);
extern void func_003525F0(char *mpv, int *hdr, long a, int f);
extern void func_00352B98(char *mpv, int *hdr);
extern void SftimHn_recordLastFrame(char *mpv, int *hdr);
extern int func_00352E10(char *mpv, int h, int *hdr, char **buf);

__attribute__((section(".text.func_00351CB0")))
int func_00351CB0(char *mpv, char **buf, int s, unsigned int flags, int *res)
{
    char *w = *(char **)(mpv + 0x1FC0);
    char *x = w + 0x1080;
    int *hdr = (int *)(w + 0x8C);
    int h = *(int *)w;
    int t0;
    int n;
    int r;
    unsigned int f40;
    MpvCb fn;
    void *obj;
    char *p;
    long l0;
    long l1;
    int k;
    int v;

    *(int *)(x + 0x10) = 0;
    func_0036A3A8(h, *(int *)(x + 0xC), *(int *)(x + 0x8));
    t0 = func_0033A010(s, 0, 1);
    *res = func_0036A3E8(h, s);
    n = func_0033A010(s, 0, 1) - t0;
    r = func_00351C18(mpv, *res, n, 0xFF000F04);
    func_00351B70(mpv, n);
    if (r != 0)
        return r;
    if (*res == -2)
        return 0;
    *res = func_0036A0D0(h, hdr);
    if (*res != 0)
        return func_0034DD70(mpv, 0xFF000F05);
    f40 = flags & 0x40;
    if (f40) {
        if (*(int *)(mpv + 0x90C) > 0) {
            if (*(int *)(mpv + 0x90C) != hdr[0]) {
                *res = -2;
                return 0;
            }
            if (*(int *)(mpv + 0x910) != hdr[1]) {
                *res = -2;
                return 0;
            }
        }
        {
            MpvCb cb = (MpvCb)GetArrayElemA0C_35A1C8(mpv, 0x5F);
            void *o = (void *)GetArrayElemA0C_35A1C8(mpv, 0x5F);

            if (cb != 0 && cb(o, hdr[0], hdr[1]) != 0) {
                *res = -2;
                return 0;
            }
        }
    }
    k = hdr[6];
    if (k == 1) {
        *(int *)(w + 0x174) = 0;
    } else if (*(int *)(mpv + 0x38) == 3) {
        p = *(char **)(w + 0x164);
        if (p != 0) {
            v = *(int *)(p + 0x70);
            if (k == 2) {
                if (hdr[5] < v && v < 0x200)
                    *(int *)(w + 0x174) = 1;
            } else if (k == 3) {
                if (!(hdr[5] < v))
                    *(int *)(w + 0x174) = 1;
            }
        }
    }
    func_0036A3C0(h, 0, x + 0x10);
    if (*(int *)(w + 0x10C) != hdr[12]) {
        *(int *)(w + 0x10C) = hdr[12];
        *(int *)(w + 0x110) = 1;
    } else {
        *(int *)(w + 0x110) = 0;
    }
    if (f40) {
        fn = (MpvCb)GetArrayElemA0C_35A1C8(mpv, 0x4D);
        obj = (void *)GetArrayElemA0C_35A1C8(mpv, 0x4E);
        if (fn != 0) {
            char *q = MPV_SearchDelim(buf[0], (int)buf[1], 1);

            if (q != 0)
                fn(obj, (int)buf[0], q - buf[0] + 4);
        }
    }
    p = MPV_SearchDelim(buf[0], (int)buf[1], 4);
    func_00352008(mpv, hdr, p, &l0, &l1, *(int *)(w + 0x110));
    *(long *)(w + 0x1120) = l1;
    if (!(flags & *(unsigned int *)(w + 0x78)))
        return 0;
    func_00352298(mpv, hdr, *(int *)(w + 0x110));
    func_003525F0(mpv, hdr, l0, *(int *)(w + 0x110));
    func_00352B98(mpv, hdr);
    SftimHn_recordLastFrame(mpv, hdr);
    return func_00352E10(mpv, h, hdr, buf);
}
