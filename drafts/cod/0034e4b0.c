/* NON_MATCHING sfmps_DecodeOneUnit (cygnus-2.96): Sofdec MPS demux step.
* Control flow matches;
* retail ranks nskip/nread/len/buf differently in s2-s7 and keeps the hl<=0 clamp as blezl (ours folds to movz). */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int mps;
    char pad4[0x158 - 4];
    int pos;
} MpsWk;

extern int sfmps_ChkSupply(char *sfd, char *buf, int len, int p6);
extern int MPS_CheckDelim(char *buf);
extern int GetArrayElemA0C_35A1C8(char *sfd, int id);
extern void MPS_SetPsMapFn(int mps, int a, int b);
extern void MPS_SetPesFn(int mps, void *fn, void *arg);
extern int sfmps_pesfn(int a0, int a1, long long a2);
extern int MPS_DecHd(int mps, char *buf, int len, int *hl, int *flags);
extern int func_0034DD70(char *sfd, int code);
extern void sfmps_SetMpsRaw(char *sfd, int mps, char *buf, int len);
extern int SFCON_IsEndcodeSkip(char *sfd);
extern int SFCON_IsSystemEndcodeSkip(char *sfd);
extern void sfmps_Concat(char *sfd);
extern void sfmps_SkipNext(char *sfd, char *buf, int len, int *nskip);
extern void sfmps_ShortSupply(char *sfd, int *st);
extern int StreamReadBlock(char *sfd, char *buf, int len, int *n, int *st);

__attribute__((section(".text.sfmps_DecodeOneUnit")))
int sfmps_DecodeOneUnit(char *sfd, char *buf, int len, int *nread, int *nskip, int p6)
{
    MpsWk *w;
    int mps;
    int dec;
    int a;
    struct {
        int hl;
        int flags;
        int st;
        int n2;
        int st2;
        int ret;
    } v;
    int n;
    int pos;
    int total;

    *nread = 0;
    *nskip = 0;
    w = *(MpsWk **)(sfd + 0x1F7C);
    v.ret = 0;
    mps = w->mps;
    if (sfmps_ChkSupply(sfd, buf, len, p6) == 0)
        return 0;
    if (len < 4)
        dec = 0;
    else
        dec = MPS_CheckDelim(buf);
    a = GetArrayElemA0C_35A1C8(sfd, 0x57);
    MPS_SetPsMapFn(mps, a, GetArrayElemA0C_35A1C8(sfd, 0x58));
    if (GetArrayElemA0C_35A1C8(sfd, 0x5B))
        MPS_SetPesFn(mps, sfmps_pesfn, sfd);
    else
        MPS_SetPesFn(mps, 0, 0);
    if (MPS_DecHd(mps, buf, len, &v.hl, &v.flags))
        v.ret = func_0034DD70(sfd, 0xFF000D03);
    if (v.flags & 0x20000)
        sfmps_SetMpsRaw(sfd, mps, buf, len);
    if (v.flags == 0x80000 && SFCON_IsEndcodeSkip(sfd)) {
        sfmps_Concat(sfd);
        *nread = 0x800;
        w->pos = 0x800;
        return v.ret;
    }
    if (v.flags == 0x80000 && SFCON_IsSystemEndcodeSkip(sfd)) {
        *nread = 0x800;
        w->pos = 0x800;
        return v.ret;
    }
    if (dec == 0) {
        sfmps_SkipNext(sfd, buf, len, nskip);
        *nread = *nskip;
        n = *nskip;
        if (n <= 0)
            return v.ret;
        pos = w->pos;
        if (pos < 0)
            return v.ret;
        total = *(int *)(sfd + 0x28);
        if (pos >= total) {
            w->pos = pos + n;
            return v.ret;
        }
        if (pos + n > total) {
            *nskip = n - (total - pos);
            w->pos = *(int *)(sfd + 0x28) + *nskip;
            return v.ret;
        }
        w->pos = pos + n;
        *nskip = 0;
        return v.ret;
    }
    if (!(v.flags & 0x40000)) {
        sfmps_ShortSupply(sfd, &v.st);
        if (v.st != 0)
            return v.ret;
        if (*(int *)(sfd + 0x28) >= len)
            return v.ret;
        n = (v.hl > 0) ? v.hl : 1;
        *nread = n;
        *nskip = n;
        return v.ret;
    }
    v.ret = StreamReadBlock(sfd, buf + v.hl, len - v.hl, &v.n2, &v.st2);
    if (v.st2 == 1)
        *nread = v.hl + v.n2;
    w->pos = -1;
    return v.ret;
}
#else
INCLUDE_ASM("asm/nonmatching", sfmps_DecodeOneUnit);
#endif
