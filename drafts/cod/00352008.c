#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[8];
    char *hdr; /* 0x08 */
    char padC[4];
    int index; /* 0x10 */
} SfdSeek;
typedef struct {
    char pad0[0x1FB8];
    SfdSeek seek; /* 0x1FB8 */
} SfdHn;
extern int SFPTS_ReadPtsQue(char *p0, int index, unsigned int p2, long long *p3);
extern long long sfmpv_ComplementPts(void *tim, void *tbl, int a, long long *pos, int b, long long *out2);

void sfmpv_ReadPtsQue(SfdHn *hn, int a, unsigned int ofs, long long *out1, long long *out2, int b)
{
    SfdSeek *seek = &hn->seek;
    long long pos;
    int index;
    char *hdr;

    index = seek->index;
    hdr = seek->hdr;

    *out1 = -1;
    *out2 = -1;
    if (ofs != 0) {
        SFPTS_ReadPtsQue((char *)hn, index, ofs, &pos);
        if (pos >= 0)
            *out1 = sfmpv_ComplementPts((char *)hn + 0xD30, hdr + 0x118, a, &pos, b, out2);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", sfmpv_ReadPtsQue);
#endif
