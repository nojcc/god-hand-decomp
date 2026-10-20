/* NON_MATCHING func_00350D08 (cygnus-2.96 --drop-reorder;
 * PARK, 66 diffs): empty case 0x40 gives the retail 8-pivot decision tree, but retail keeps a dead addiu 0x40 delay-slot residue and an extra copy of the MPV_CheckDelim result; prologue arg copies come out s3/s1/s2 instead of s1/s2/s3 (an explicit goto dispatch reaches 54 diffs at full length);
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

extern int func_0034C2B8(char *h, int buf, MpvCur *cur);
extern char *sfmpv_SearchDelim(MpvCur *cur, int mask, int *delim);
extern int sfmpv_CalcDistance(MpvCur *cur, char *p);
extern char *sfmpv_BsearchDelim(MpvCur *cur, int mask, int *delim);
extern void func_0034C6D8(char *h, int buf, char **pos, char **end);
extern int func_00350F48(MpvCur *cur, int delim, char *pos);
extern void func_0034C748(char *h, int buf, char *pos, char *end);
extern int MPV_CheckDelim(char *p);
extern int func_00351170(char *h);

__attribute__((section(".text.func_00350D08"))) int func_00350D08(char *h, int *dist, int *code, int *flag)
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
    r = func_0034C2B8(h, buf, &cur);
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
    func_0034C6D8(h, buf, &pos, &end);
    if (func_00350F48(&cur, delim, pos)) {
        char *e;
        pos = 0;
        if (cur.len2 == 0)
            e = cur.top + cur.len;
        else
            e = cur.top2 + cur.len2;
        if (end != e) {
            end = e;
            pos = sfmpv_BsearchDelim(&cur, 0xCC, &kind);
            func_0034C748(h, buf, pos, end);
        }
    }
    if (pos == 0)
        return func_00351170(h);
    kind = MPV_CheckDelim(pos);
    switch (kind) {
    case 0x80:
        break;
    case 8:
        if (delim & 0x40) {
            p = sfmpv_SearchDelim(&cur, 8, &delim);
            if (p == 0 || p == pos)
                return func_00351170(h);
        }
        break;
    case 4:
        if (delim & 0x48) {
            p = sfmpv_SearchDelim(&cur, 4, &delim);
            if (p == 0 || p == pos)
                return func_00351170(h);
        }
        break;
    }
    *dist = sfmpv_CalcDistance(&cur, pos);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00350D08);
#endif
