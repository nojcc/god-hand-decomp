/* sn-2.95.3-136 */
/* func_002F1758: retail loads 0x200 before the y clamp, sets up the memset arguments
 * before the x clamp, and loads the constant 8 of 8 - skip into $s4 in the memset delay
 * slot, subtracting skip after the call. This build loads 0x1C0 and 0x200 early and
 * computes 8 - skip before the call; 28 instructions differ, all in that stretch. */
#include "include_asm.h"
#include "godhand/cOmBase.h"
#include "godhand/criStm.h"
#include "godhand/gameWork.h"

#ifdef NON_MATCHING

typedef unsigned int  u_int;
typedef unsigned long u_long;
typedef int qword __attribute__((mode(TI)));

typedef struct {
    u_int  vifcode[4];
    u_long giftag[2];
    u_long bitbltbuf;
    long   bitbltbufaddr;
    u_long trxpos;
    long   trxposaddr;
    u_long trxreg;
    long   trxregaddr;
    u_long finish;
    long   finishaddr;
    u_long trxdir;
    long   trxdiraddr;
} sceGsStoreImage;

extern int func_00395618(sceGsStoreImage *sg, short sbp, short sbw, short spsm,
                         short ssax, short ssay, short rrw, short rrh);
extern int sceGsExecStoreImage(sceGsStoreImage *sp, qword *dstaddr);
extern u_long Tramp_GsGetIMR_3964A0(void);
extern u_long func_00396008(u_long newMask);

/* Horizontal sample offsets around the flare centre: -2, 2, -5, 5, -8, 7. */
typedef struct {
    signed char d[6];
} FlareTaps;

extern int D_003C1180;
extern FlareTaps D_0044EC60;
extern cVec D_0061B660;
extern unsigned char D_0061B670;
extern unsigned short D_0061B672;
extern int D_0061B674;
extern unsigned short D_0061B680[16];
extern unsigned char D_003C3BB0;
extern float D_003C3BB4;

/* Lens flare occlusion: reads back a row of the Z buffer around the flare's screen position,
 * brightens the flare while its centre is visible and dims it for each covered sample. */
__attribute__((section(".text.func_002F1758")))
void func_002F1758(void)
{
    sceGsStoreImage gs;
    FlareTaps taps;
    int visible = 0;
    int x, y, skip, center, n, i, k, d, ok;
    u_int imr;

    D_0061B670 = 0;
    D_003C3BB0 = 0;
    if (D_0061B660.x > 1.0f && D_0061B660.x < 511.0f && D_0061B660.y > 1.0f
        && D_0061B660.y < 447.0f && D_0061B660.z > 0.0f) {
        taps = D_0044EC60;
        y = (int)D_0061B660.y;
        if (y < 0)
            y = 0;
        if (y > 0x1C0)
            y = 0x1C0;
        x = (int)(D_0061B660.x - 16.0f);
        if (x < 0)
            skip = -x;
        else
            skip = 0;
        if (x > 0x1F0)
            skip = x - 0x1F0;
        if (x < 0)
            x = 0;
        if (x > 0x200)
            x = 0x200;
        center = 8 - skip;
        func_003A52F0(D_0061B680, 0, 0x20);
        func_00395618(&gs, 0x1F00, D_003C1180 / 64, 0x3A, x, y, 16 - skip, 1);
        FlushCache(0);
        imr = func_00396008(Tramp_GsGetIMR_3964A0() | 0x400);
        ok = sceGsExecStoreImage(&gs, (qword *)D_0061B680);
        func_00396008(imr);
        if (ok != -1) {
            if (D_0061B672 >= D_0061B680[center]) {
                D_003C3BB0 = 1;
                visible = 1;
                D_003C3BB4 += 0.2f;
                if (D_003C3BB4 > 1.0f)
                    D_003C3BB4 = 1.0f;
            }
            if (visible) {
                n = D_0061B674;
                if (n > 6)
                    n = 6;
                for (i = 0; i < n; i++) {
                    k = taps.d[i] + center;
                    d = x - k;
                    if (d >= 0) {
                        if (d <= 0x200 && (float)D_0061B680[k] > D_0061B660.z)
                            D_003C3BB4 -= 0.02f;
                    }
                }
            }
        }
    }
    D_0061B660.z = -1.0f;
}

#else
INCLUDE_ASM("asm/nonmatching", func_002F1758);
#endif
