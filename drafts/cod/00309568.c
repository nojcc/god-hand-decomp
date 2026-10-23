/* sn-2.95.3-136 */
/* func_00309568 (TIM2 palette upload): the TEX0 setup, the format switch tree and both upload
 * loops match except for two register choices: retail builds the 256-colour step in v0 and
 * copies it to s5 after the empty-palette test, and in the 16-colour loop it computes i & 0xF
 * into s0 before the block-address call and masks it with 0xE afterwards. */
#include "include_asm.h"
#include "godhand/gameWork.h"

#ifdef NON_MATCHING

typedef struct { unsigned char data[0x60]; } sceGsLoadImage;

typedef struct GsTex0 {
    unsigned long TBP0 : 14;
    unsigned long TBW : 6;
    unsigned long PSM : 6;
    unsigned long TW : 4;
    unsigned long TH : 4;
    unsigned long TCC : 1;
    unsigned long TFX : 2;
    unsigned long CBP : 14;
    unsigned long CPSM : 4;
    unsigned long CSM : 1;
    unsigned long CSA : 5;
    unsigned long CLD : 3;
} GsTex0;

/* A TIM2 picture header. */
typedef struct Tim2Pic {
    unsigned int totalSize;     /* 0x00 */
    unsigned int clutSize;      /* 0x04 */
    unsigned int imageSize;     /* 0x08 */
    unsigned short headerSize;  /* 0x0C */
    unsigned short clutColors;  /* 0x0E */
    unsigned char picFormat;    /* 0x10 */
    unsigned char mipmaps;      /* 0x11 */
    unsigned char clutType;     /* 0x12 */
    unsigned char imageType;    /* 0x13 */
    unsigned short w;           /* 0x14 */
    unsigned short h;           /* 0x16 */
    GsTex0 tex0;                /* 0x18 */
} Tim2Pic;

extern int sceGsSetDefLoadImage(sceGsLoadImage *lp, short dbp, short dbw, short dpsm, short x, short y, short w, short h);
extern int func_00395758(void *lp, void *srcaddr);
extern int func_0030A298(int a0);

/* Upload a TIM2 picture's palette to the GS at block cbp and point its TEX0 at it;
 * returns the next free block. */
__attribute__((section(".text.func_00309568")))
int func_00309568(Tim2Pic *ph, int cbp)
{
    sceGsLoadImage li;
    int cpsm;
    char *clut;
    int i;
    int n;
    int rows;
    int step;

    if (ph->clutType == 0)
        return cbp;
    if ((ph->clutType & 0x3F) == 1)
        cpsm = 2;
    else if ((ph->clutType & 0x3F) == 2)
        cpsm = 1;
    else
        cpsm = 0;
    ph->tex0.CPSM = cpsm;
    ph->tex0.CSM = 0;
    ph->tex0.CSA = 0;
    ph->tex0.CLD = 1;
    ph->tex0.CBP = func_0030A298(cbp);
    clut = (char *)ph + ph->headerSize + ph->imageSize;
    switch ((ph->clutType << 8) | ph->imageType) {
    case 0x4104:
    case 0x4204:
    case 0x4304:
    case 0x105:
    case 0x205:
    case 0x305:
        switch (cpsm) {
        case 0:
            step = 0x400;
            break;
        case 2:
        case 10:
            step = 0x200;
            break;
        default:
            return cbp;
        }
        for (i = 0; i < ph->clutColors; i += 0x100) {
            n = ph->clutColors - i;
            if (n < 0x100)
                rows = n / 16;
            else
                rows = 16;
            sceGsSetDefLoadImage(&li, func_0030A298(cbp), 1, cpsm, 0, 0, 16, rows);
            if (!(D_00747A24 & 0x20000000))
                FlushCache(0);
            else
                iFlushCache(0);
            func_00395758(&li, clut);
            func_003950F8(0, 0);
            cbp++;
            clut += step;
        }
        break;
    case 0x104:
    case 0x204:
    case 0x304:
    case 0x8104:
    case 0x8204:
    case 0x8304:
    case 0x8105:
    case 0x8205:
    case 0x8305:
        for (i = 0; i < ph->clutColors / 16; i++) {
            sceGsSetDefLoadImage(&li, func_0030A298(cbp + i / 16), 1, cpsm, (i & 1) * 8, ((i & 0xF) >> 1) * 2, 8, 2);
            FlushCache(0);
            func_00395758(&li, clut);
            func_003950F8(0, 0);
            if ((ph->clutType & 0x3F) == 1)
                clut += 0x20;
            else if ((ph->clutType & 0x3F) == 2)
                clut += 0x30;
            else
                clut += 0x40;
        }
        cbp += (ph->clutColors + 0xFF) / 256;
        break;
    }
    return cbp;
}

#else
INCLUDE_ASM("asm/nonmatching", func_00309568);
#endif
