/* cygnus-2.96: sfmpv_DecodePicAtr, Sofdec MPV picture header decode step. */
#include "godhand/sftim.h"
typedef int (*MpvCb)(void *obj, int a, int b);

extern void MPV_SetPicUsrBuf(int h, int a, int b);
extern int SJRBF_GetFlowCnt(int s, int a, int b);
extern int MPV_DecodePicAtrSj(int h, int s);
extern int sfmpv_ChkMpvErr(char *mpv, int a, int n, int code);
extern void sfmpv_AddRtotSj(char *mpv, int n);
extern int MPV_GetPicAtr(int h, int *hdr);
extern void MPV_GetPicUsr(int h, int a, void *p);
extern char *MPV_SearchDelim(char *p, int len, int kind);
extern void sfmpv_ReadPtsQue(char *mpv, int *hdr, char *p, long *a, long *b, int f);
extern void sfmpv_CalcRepeatField(char *mpv, int *hdr, int f);
extern void sfmpv_ReformTc(char *mpv, int *hdr, long a, int f);
extern void sfmpv_SetHeadTtu(char *mpv, int *hdr);
extern void SftimHn_recordLastFrame(char *mpv, int *hdr);
extern int sfmpv_FirstPicAtr(char *mpv, int h, int *hdr, char **buf);

__attribute__((section(".text.sfmpv_DecodePicAtr")))
int sfmpv_DecodePicAtr(char *mpv, char **buf, int s, unsigned int flags, int *res)
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
    MPV_SetPicUsrBuf(h, *(int *)(x + 0xC), *(int *)(x + 0x8));
    t0 = SJRBF_GetFlowCnt(s, 0, 1);
    *res = MPV_DecodePicAtrSj(h, s);
    n = SJRBF_GetFlowCnt(s, 0, 1) - t0;
    r = sfmpv_ChkMpvErr(mpv, *res, n, 0xFF000F04);
    sfmpv_AddRtotSj(mpv, n);
    if (r != 0)
        return r;
    if (*res == -2)
        return 0;
    *res = MPV_GetPicAtr(h, hdr);
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
    MPV_GetPicUsr(h, 0, x + 0x10);
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
    sfmpv_ReadPtsQue(mpv, hdr, p, &l0, &l1, *(int *)(w + 0x110));
    *(long *)(w + 0x1120) = l1;
    if (!(flags & *(unsigned int *)(w + 0x78)))
        return 0;
    sfmpv_CalcRepeatField(mpv, hdr, *(int *)(w + 0x110));
    sfmpv_ReformTc(mpv, hdr, l0, *(int *)(w + 0x110));
    sfmpv_SetHeadTtu(mpv, hdr);
    SftimHn_recordLastFrame(mpv, hdr);
    return sfmpv_FirstPicAtr(mpv, h, hdr, buf);
}
