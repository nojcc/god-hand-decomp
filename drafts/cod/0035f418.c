/* build the picture (three planes) and the output buffer records for the frame format (3 = planar: offset U/V by half the luma size;
* 1/2 = packed) and pass them with the option record to the handle's callback.
* Frame, block order and the hoisted plane/buffer addresses match; the case-3 loads and stores are scheduled differently (retail stores out.a/out.b between the plane updates) and the address temps land in t1-t4 instead of t2-t5. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct PicPlane {
    int addr;           /* 0x00 */
    int width;          /* 0x04 */
    int height;         /* 0x08 */
    int pitch;          /* 0x0C */
} PicPlane;

typedef struct PicRec {
    int unk00;
    PicPlane pl[3];  /* 0x04 */
    char pad34[0x3C];
} PicRec;

typedef struct OutBuf {
    int addr;           /* 0x00 */
    int a;              /* 0x04 */
    int b;              /* 0x08 */
    int size;           /* 0x0C */
} OutBuf;

typedef struct OutRec {
    int unk00;
    OutBuf buf;      /* 0x04 */
    char pad14[0x5C];
} OutRec;

typedef struct PicSrc {
    int unk00;
    int addr;           /* 0x04 */
    int a;              /* 0x08 */
    int b;              /* 0x0C */
} PicSrc;

typedef struct PicOpt {
    int arg;            /* 0x00 */
    int pad4[7];
} PicOpt;

typedef struct SfxPicHn {
    char pad0[8];
    int size;           /* 0x08 */
    char padC[0x38 - 0xC];
    int arg;            /* 0x38 */
    char pad3C[0x6C - 0x3C];
    void (*cb)(PicRec *pic, OutRec *out, PicOpt *opt);   /* 0x6C */
} SfxPicHn;

extern char D_00459F60[];

extern void func_0035F288(SfxPicHn *sfx, unsigned int *fmt, PicRec *pic);
extern void SFXLIB_Error(SfxPicHn *sfx, unsigned int *fmt, char *msg);
extern int Obj0000_Get_D_003EE34C_35FC28(void);

void func_0035F418(SfxPicHn *sfx, unsigned int *fmt, PicSrc *src)
{
    PicRec pic;
    OutRec out;
    PicOpt opt;
    PicPlane *y;
    PicPlane *u;
    PicPlane *v;
    OutBuf *buf;
    int size;

    func_0035F288(sfx, fmt, &pic);
    y = &pic.pl[0];
    u = &pic.pl[1];
    v = &pic.pl[2];
    buf = &out.buf;
    switch (*fmt) {
    case 3:
        size = y->pitch * y->height / 2;
        y->addr += size;
        u->addr += size / 2;
        v->addr += size / 2;
        buf->a = src->a;
        buf->b = src->b;
        buf->addr = src->addr;
        if (sfx->size != 0)
            buf->size = sfx->size;
        else
            buf->size = y->width * 4;
        break;
    case 1:
    case 2:
        buf->a = src->a;
        buf->addr = src->addr;
        buf->b = src->b;
        if (sfx->size != 0)
            buf->size = sfx->size;
        else
            buf->size = y->width * 4;
        break;
    default:
        SFXLIB_Error(sfx, fmt, D_00459F60);
        break;
    }
    if (Obj0000_Get_D_003EE34C_35FC28() == 1)
        opt.arg = sfx->arg;
    else
        opt.arg = 0;
    if (sfx->cb != 0)
        sfx->cb(&pic, &out, &opt);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0035F418);
#endif
