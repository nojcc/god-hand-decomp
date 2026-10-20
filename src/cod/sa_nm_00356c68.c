/* NON_MATCHING func_00356C68 (cygnus-2.96 --drop-reorder;
 * PARK, 1 diff): the last end-code-skip test comes out as bnel
 * where retail has bnez with the s0 restore in the delay slot; no condition shape or approved flag changes the reorg
 * choice.
 * Scans a video chunk for MPEG start codes (carried-over tail, then MPV_SearchDelim) and signals end of stream
 * on a sequence end code. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern unsigned char *MPV_SearchDelim(unsigned char *buf, int len, int mask);
extern int MPV_CheckDelim(unsigned char *p);
extern int SFCON_IsEndcodeSkip(void *self);
extern int SFCON_IsVideoEndcodeSkip(void *self);
extern void func_00356988(void *self, int a1);

typedef struct MovSt {
    int state;  /* 0x00 */
    int a4;     /* 0x04 */
    int a8;     /* 0x08 */
    int aC;     /* 0x0C */
    unsigned char tail[3]; /* 0x10 */
} MovSt;

__attribute__((section(".text.func_00356C68")))
void func_00356C68(char *self, unsigned char *buf, int len)
{
    MovSt *st = (MovSt *)(*(char **)(self + 0x1FC0) + 0x1128);
    unsigned char tmp[6];
    unsigned char *p;
    int i;
    int end = 0;

    st->aC += st->a4;
    st->a4 = st->a8;
    st->a8 = 0;
    tmp[0] = st->tail[0];
    tmp[1] = st->tail[1];
    tmp[2] = st->tail[2];
    tmp[3] = buf[0];
    tmp[4] = buf[1];
    tmp[5] = buf[2];
    for (i = 0; i < ((len < 4) ? len : 3); i++) {
        if (tmp[i] == 0 && tmp[i + 1] == 0 && tmp[i + 2] == 1) {
            if (tmp[i + 3] == 0) {
                st->a8++;
                break;
            }
            if (tmp[i + 3] == 0xB7) {
                end = 1;
                break;
            }
        }
    }
    if (len < 3) {
        st->tail[0] = tmp[len];
        st->tail[1] = tmp[len + 1];
        st->tail[2] = tmp[len + 2];
    } else {
        st->tail[0] = buf[len - 3];
        st->tail[1] = buf[len - 2];
        st->tail[2] = buf[len - 1];
    }
    while (len >= 4 && (p = MPV_SearchDelim(buf, len, 0x84)) != 0) {
        if (MPV_CheckDelim(p) & 4)
            st->a8++;
        else
            end = 1;
        p += 4;
        len -= p - buf;
        buf = p;
    }
    if (end == 1 && !SFCON_IsEndcodeSkip(self) && !SFCON_IsVideoEndcodeSkip(self))
        func_00356988(self, 1);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00356C68);
#endif
