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
extern int func_00359518(char *p0, int index, unsigned int p2, long long *p3);
extern long long func_003520D8(void *tim, void *tbl, int a, long long *pos, int b, long long *out2);

void func_00352008(SfdHn *hn, int a, unsigned int ofs, long long *out1, long long *out2, int b)
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
        func_00359518((char *)hn, index, ofs, &pos);
        if (pos >= 0)
            *out1 = func_003520D8((char *)hn + 0xD30, hdr + 0x118, a, &pos, b, out2);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00352008);
#endif
