/* NON_MATCHING sfmpv_GetActiveSize (cygnus-2.96): empty case 0x40 gives the retail 8-pivot decision tree, but retail keeps a dead addiu 0x40 delay-slot residue and an extra copy of the MPV_CheckDelim result; prologue arg copies come out s3/s1/s2 instead of s1/s2/s3 (an explicit goto dispatch reaches 54 diffs at full length);
* Sofdec MPV delimiter scan */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char *top;
    int len;
    char *top2;
    int len2;
    int pad[4];
} MpvCur;

extern int SFBUF_RingGetRead(char *h, int buf, MpvCur *cur);
extern char *sfmpv_SearchDelim(MpvCur *cur, int mask, int *delim);
extern int sfmpv_CalcDistance(MpvCur *cur, char *p);
extern char *sfmpv_BsearchDelim(MpvCur *cur, int mask, int *delim);
extern void SFBUF_RingGetDlm(char *h, int buf, char **pos, char **end);
extern int sfmpv_NeedSafeDlmRefresh(MpvCur *cur, int delim, char *pos);
extern void SFBUF_RingSetDlm(char *h, int buf, char *pos, char *end);
extern int MPV_CheckDelim(char *p);
extern int sfmpv_CheckViBufSiz(char *h);

__attribute__((section(".text.sfmpv_GetActiveSize"))) int sfmpv_GetActiveSize(char *h, int *dist, int *code, int *flag)
{
    MpvCur cur;
    int delim;
    char *pos;
    char *end;
    int kind;
    int buf;
    int r;
    int d;
    char *p;

    *dist = 0;
    buf = *(int *)(h + 0x1FC8);
    *code = 0;
    *flag = 0;
    r = SFBUF_RingGetRead(h, buf, &cur);
    if (r != 0)
        return r;
    if (cur.len == 0)
        return 0;
    p = sfmpv_SearchDelim(&cur, 0xCE, &delim);
    if (p != cur.top) {
        if (p != 0) {
            *dist = sfmpv_CalcDistance(&cur, p);
        } else {
            d = cur.len + cur.len2 - 3;
            if (d < 0)
                d = 0;
            *dist = d;
        }
        if (*dist <= 0)
            return 0;
        *flag = 1;
        return 0;
    }
    *dist = 4;
    *code = delim;
    if (delim & 0x80)
        return 0;
    SFBUF_RingGetDlm(h, buf, &pos, &end);
    if (sfmpv_NeedSafeDlmRefresh(&cur, delim, pos)) {
        char *e;
        pos = 0;
        if (cur.len2 == 0)
            e = cur.top + cur.len;
        else
            e = cur.top2 + cur.len2;
        if (end != e) {
            end = e;
            pos = sfmpv_BsearchDelim(&cur, 0xCC, &kind);
            SFBUF_RingSetDlm(h, buf, pos, end);
        }
    }
    if (pos == 0)
        return sfmpv_CheckViBufSiz(h);
    kind = MPV_CheckDelim(pos);
    switch (kind) {
    case 0x80:
        break;
    case 8:
        if (delim & 0x40) {
            p = sfmpv_SearchDelim(&cur, 8, &delim);
            if (p == 0 || p == pos)
                return sfmpv_CheckViBufSiz(h);
        }
        break;
    case 4:
        if (delim & 0x48) {
            p = sfmpv_SearchDelim(&cur, 4, &delim);
            if (p == 0 || p == pos)
                return sfmpv_CheckViBufSiz(h);
        }
        break;
    }
    *dist = sfmpv_CalcDistance(&cur, pos);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", sfmpv_GetActiveSize);
#endif
