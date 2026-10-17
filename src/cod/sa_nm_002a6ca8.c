/* NON_MATCHING func_002A6CA8 (sched): sn best 16: only the order of the 16 vertex float stores and f0/f2 numbering differ; searched store/decl/init orders, inline helper */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct { float x, y, z, w; } Vtx2A6CA8;
typedef struct {
    int mode;      /* 0x00 */
    char pad04[0x30 - 4];
    long prim;     /* 0x30 */
    char pad38[0x48 - 0x38];
} PolyCtx2A6CA8;

extern char D_00583F20[];
extern float D_003C1184;
extern float D_003C1190;
extern int D_00752C04;
extern int cDvd_stepState(void *p);
extern void func_003A52F0(void *p, int c, int n);
extern void *Gp_draw_poly4(Vtx2A6CA8 *v, int col, int n, PolyCtx2A6CA8 *ctx, int e, int f);
extern void cTaskWork_sleep(int task, int frames);

void func_002A6CA8(void *task)
{
    Vtx2A6CA8 vt[4];
    PolyCtx2A6CA8 ctx;
    float x0, y0, x1, y1, z, w;

    while (cDvd_stepState(D_00583F20) == 1) {
        ctx.mode = 0;
        func_003A52F0(&ctx, 0, sizeof(ctx));
        ctx.mode |= 0x20;
        ctx.prim = 0x30000;
        x0 = 0.0f;
        y0 = 0.0f;
        x1 = D_003C1184;
        y1 = D_003C1190;
        z = 65535.0f;
        w = 1.0f;
        vt[0].y = y0;
        vt[2].x = x1;
        vt[1].y = y1;
        vt[0].z = z;
        vt[0].w = w;
        vt[1].x = x0;
        vt[0].x = x0;
        vt[2].y = y0;
        vt[3].x = x1;
        vt[3].y = y1;
        vt[3].z = z;
        vt[2].z = z;
        vt[1].z = z;
        vt[3].w = w;
        vt[2].w = w;
        vt[1].w = w;
        Gp_draw_poly4(vt, 0x80000000, 1, &ctx, 6, 5);
        cTaskWork_sleep(D_00752C04, 1);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002A6CA8);
#endif
