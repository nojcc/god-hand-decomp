/* NON_MATCHING func_0035F418 (cygnus-2.96, -freorder-blocks dropped;
 * STOP 39): build the picture (three planes) and the output buffer records for the frame format (3 = planar: offset U/V by half the luma size;
 * 1/2 = packed) and pass them with the option record to the handle's callback.
 * Frame, block order and the hoisted plane/buffer addresses match; the case-3 loads and stores are scheduled differently (retail stores out.a/out.b between the plane updates) and the address temps land in t1-t4 instead of t2-t5. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Plane35F418 {
    int addr;           /* 0x00 */
    int width;          /* 0x04 */
    int height;         /* 0x08 */
    int pitch;          /* 0x0C */
} Plane35F418;

typedef struct Pic35F418 {
    int unk00;
    Plane35F418 pl[3];  /* 0x04 */
    char pad34[0x3C];
} Pic35F418;

typedef struct Buf35F418 {
    int addr;           /* 0x00 */
    int a;              /* 0x04 */
    int b;              /* 0x08 */
    int size;           /* 0x0C */
} Buf35F418;

typedef struct Out35F418 {
    int unk00;
    Buf35F418 buf;      /* 0x04 */
    char pad14[0x5C];
} Out35F418;

typedef struct Src35F418 {
    int unk00;
    int addr;           /* 0x04 */
    int a;              /* 0x08 */
    int b;              /* 0x0C */
} Src35F418;

typedef struct Opt35F418 {
    int arg;            /* 0x00 */
    int pad4[7];
} Opt35F418;

typedef struct Sfx35F418 {
    char pad0[8];
    int size;           /* 0x08 */
    char padC[0x38 - 0xC];
    int arg;            /* 0x38 */
    char pad3C[0x6C - 0x3C];
    void (*cb)(Pic35F418 *pic, Out35F418 *out, Opt35F418 *opt);   /* 0x6C */
} Sfx35F418;

extern char D_00459F60[];

extern void func_0035F288(Sfx35F418 *sfx, unsigned int *fmt, Pic35F418 *pic);
extern void SFXLIB_Error(Sfx35F418 *sfx, unsigned int *fmt, char *msg);
extern int Obj0000_Get_D_003EE34C_35FC28(void);

void func_0035F418(Sfx35F418 *sfx, unsigned int *fmt, Src35F418 *src)
{
    Pic35F418 pic;
    Out35F418 out;
    Opt35F418 opt;
    Plane35F418 *y;
    Plane35F418 *u;
    Plane35F418 *v;
    Buf35F418 *buf;
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
