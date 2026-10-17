/* NON_MATCHING func_003552D0 (regalloc): cygnus dr: only s0/s1 swap for sfd/mpv (18 insns); tried struct/int/void types, single-exit, nested, decl order */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct PicHdr3552D0 {
    int w[11];
} PicHdr3552D0;

typedef struct PicEnt3552D0 {
    int valid;                  /* 0x00 */
    int unk04[2];
    PicHdr3552D0 hdr;           /* 0x0C */
    char data[0x200];           /* 0x38 */
    int len;                    /* 0x238 */
} PicEnt3552D0;

typedef struct PicBuf3552D0 {
    void *data;
    int len;
} PicBuf3552D0;

extern PicEnt3552D0 *func_003553C8(void *sfd);
extern int MPV_DecodePicAtr(int mpv, PicBuf3552D0 *buf, void *atr);
extern int func_0034DD70(void *sfd, int err);

int func_003552D0(char *sfd, int *mpv, int *done)
{
    PicBuf3552D0 buf;
    char atr[0x10];
    PicEnt3552D0 *e;

    *done = 0;
    e = func_003553C8(sfd);
    if (e == 0)
        return 0;
    if (e->valid == 0)
        return 0;
    *(PicHdr3552D0 *)(sfd + 0xD6C) = e->hdr;
    buf.data = e->data;
    buf.len = e->len;
    if (MPV_DecodePicAtr(*mpv, &buf, atr) != 0)
        return func_0034DD70(sfd, 0xFF000F1B);
    *done = 1;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003552D0);
#endif
