/* NON_MATCHING sfmpv_ReprocessShc: cygnus-2.96: only s0/s1 swap for sfd/mpv (18 insns) */
#include "include_asm.h"
#include "godhand/sftim.h"

#ifdef NON_MATCHING
typedef struct PicHdr {
    int w[11];
} PicHdr;

typedef struct PicEnt {
    int valid;                  /* 0x00 */
    int unk04[2];
    PicHdr hdr;           /* 0x0C */
    char data[0x200];           /* 0x38 */
    int len;                    /* 0x238 */
} PicEnt;

typedef struct PicBuf {
    void *data;
    int len;
} PicBuf;

extern PicEnt *sfmpv_GetHd(void *sfd);
extern int MPV_DecodePicAtr(int mpv, PicBuf *buf, void *atr);

int sfmpv_ReprocessShc(char *sfd, int *mpv, int *done)
{
    PicBuf buf;
    char atr[0x10];
    PicEnt *e;

    *done = 0;
    e = sfmpv_GetHd(sfd);
    if (e == 0)
        return 0;
    if (e->valid == 0)
        return 0;
    *(PicHdr *)(sfd + 0xD6C) = e->hdr;
    buf.data = e->data;
    buf.len = e->len;
    if (MPV_DecodePicAtr(*mpv, &buf, atr) != 0)
        return func_0034DD70(sfd, 0xFF000F1B);
    *done = 1;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", sfmpv_ReprocessShc);
#endif
