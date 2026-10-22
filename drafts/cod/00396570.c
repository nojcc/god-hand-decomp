/* NON_MATCHING sceGsSetDefDispEnv (ee-2.9-991111): 235 words vs 221. Retail computes the DISPLAY
 * x term with 64-bit adds (daddiu/daddu) and shares the tail of the NTSC and PAL paths (interlaced
 * and non-interlaced each); here every mode keeps its own copy. func_00396560 (syscall 0x80) is
 * defined as void(void) in 00396560.c; it takes (mode, &dx, &dy, &dw, &dh). */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef unsigned long u_long;

typedef struct {
    u_long FBP:9;
    u_long FBW:6;
    u_long PSM:5;
    u_long pad20:12;
    u_long DBX:11;
    u_long pad43:5;
    u_long DBY:11;
    u_long pad59:5;
} sceGsDispFb;

typedef struct {
    u_long      pmode;
    u_long      smode2;
    sceGsDispFb dispfb;
    u_long      display;
    u_long      bgcolor;
} sceGsDispEnv;

typedef struct {
    short sceGsInterMode;
    short sceGsOutMode;
    short sceGsFFMode;
    short sceGsVersion;
    int  (*sceGsVSCfunc)(int);
    int   sceGsVSCid;
} __attribute__((aligned(8))) sceGsGParam;

#define SCE_GS_NOINTERLACE  0
#define SCE_GS_INTERLACE    1
#define SCE_GS_FIELD        0
#define SCE_GS_FRAME        1
#define SCE_GS_NTSC         2
#define SCE_GS_PAL          3
#define SCE_GS_DTV480P      0x50

#define SCE_GS_SET_PMODE(en1, en2, mmod, amod, slbg, alp) \
    ((u_long)(en1)        | ((u_long)(en2) << 1) | ((u_long)1 << 2) | \
    ((u_long)(mmod) << 5) | ((u_long)(amod) << 6) | \
    ((u_long)(slbg) << 7) | ((u_long)(alp) << 8))

#define SCE_GS_SET_SMODE2(intr, ffmd, dpms) \
    ((u_long)(intr) | ((u_long)(ffmd) << 1) | ((u_long)(dpms) << 2))

#define SCE_GS_SET_DISPFB(fbp, fbw, psm, dbx, dby) \
    ((u_long)(fbp)         | ((u_long)(fbw) << 9) | \
    ((u_long)(psm) << 15)  | ((u_long)(dbx) << 32) | ((u_long)(dby) << 43))

#define SCE_GS_SET_DISPLAY(dx, dy, magh, magv, dw, dh) \
    ((u_long)(dx)          | ((u_long)(dy) << 12) | \
    ((u_long)(magh) << 23) | ((u_long)(magv) << 27) | \
    ((u_long)(dw) << 32)   | ((u_long)(dh) << 44))

extern sceGsGParam *GetD003F8560_395388(void);
extern int checkModelVersion(void);
extern void func_00396560(int mode, int *dx, int *dy, int *dw, int *dh);
extern void func_003B1F28(char *fmt);
extern char D_0045DF60[];

/* Fill a display environment for a w x h frame buffer of format psm shown at (dx, dy), using the
 * video mode in the GS parameters and, on newer units, the console's display offsets. */
__attribute__((section(".text.sceGsSetDefDispEnv")))
void sceGsSetDefDispEnv(sceGsDispEnv *disp, short psm, short w, short h, short dx, short dy)
{
    sceGsGParam *gp;
    int dxOfs;
    int dyOfs;
    int dwOfs;
    int dhOfs;
    int magh;

    gp = GetD003F8560_395388();
    if (gp->sceGsOutMode != SCE_GS_NTSC && gp->sceGsOutMode != SCE_GS_PAL && checkModelVersion()) {
        func_00396560(gp->sceGsOutMode, &dxOfs, &dyOfs, &dwOfs, &dhOfs);
    } else {
        dxOfs = dyOfs = dwOfs = dhOfs = 0;
    }
    disp->pmode = SCE_GS_SET_PMODE(0, 1, 1, 1, 0, 0);
    if (gp->sceGsInterMode != SCE_GS_NOINTERLACE) {
        if (gp->sceGsFFMode != SCE_GS_FIELD) {
            disp->smode2 = SCE_GS_SET_SMODE2(1, 1, 0);
        } else {
            disp->smode2 = SCE_GS_SET_SMODE2(1, 0, 0);
        }
    } else {
        disp->smode2 = SCE_GS_SET_SMODE2(0, 1, 0);
    }
    *(u_long *)&disp->dispfb = SCE_GS_SET_DISPFB(0, ((w + 63) >> 6) & 0x3F, psm & 0xF, 0, 0);
    if (gp->sceGsOutMode == SCE_GS_NTSC) {
        if (gp->sceGsInterMode == SCE_GS_INTERLACE) {
            magh = (w + 2559) / w;
            disp->display = SCE_GS_SET_DISPLAY((magh * dx + dxOfs + 636) & 0xFFF,
                                               (dy + dyOfs + 50) & 0xFFF,
                                               magh - 1, 0, magh * w - 1,
                                               (gp->sceGsFFMode != SCE_GS_FIELD) ? h * 2 - 1 : h - 1);
        } else {
            magh = (w + 2559) / w;
            disp->display = SCE_GS_SET_DISPLAY((magh * dx + dxOfs + 636) & 0xFFF,
                                               (dy + dyOfs + 25) & 0xFFF,
                                               magh - 1, 0, magh * w - 1, h - 1);
        }
    } else if (gp->sceGsOutMode == SCE_GS_PAL) {
        if (gp->sceGsInterMode == SCE_GS_INTERLACE) {
            magh = (w + 2559) / w;
            disp->display = SCE_GS_SET_DISPLAY((magh * dx + dxOfs + 656) & 0xFFF,
                                               (dy + dyOfs + 72) & 0xFFF,
                                               magh - 1, 0, magh * w - 1,
                                               (gp->sceGsFFMode != SCE_GS_FIELD) ? h * 2 - 1 : h - 1);
        } else {
            magh = (w + 2559) / w;
            disp->display = SCE_GS_SET_DISPLAY((magh * dx + dxOfs + 656) & 0xFFF,
                                               (dy + dyOfs + 36) & 0xFFF,
                                               magh - 1, 0, magh * w - 1, h - 1);
        }
    } else if (gp->sceGsOutMode == SCE_GS_DTV480P) {
        disp->display = SCE_GS_SET_DISPLAY(((720 - w) / 2 * 2 + dxOfs + dx * 2 + 232) & 0xFFF,
                                           (dy + dyOfs + 35) & 0xFFF,
                                           1, 0, w * 2 - 1, h - 1);
    } else {
        func_003B1F28(D_0045DF60);
    }
    disp->bgcolor = 0;
}
#else
INCLUDE_ASM("asm/nonmatching", sceGsSetDefDispEnv);
#endif
