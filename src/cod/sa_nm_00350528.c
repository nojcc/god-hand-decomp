/* NON_MATCHING func_00350528 (cyg,near-miss,regalloc): best 2 (cyg dr): the only difference is the loop body's base registers; retail stores used=0 through v1 and ptr through the v0 copy, ours the other way round. A pointer-local entry form scores worse (31). */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int ptr;
    int used;
} RingEnt;

typedef struct {
    int base;
    int num;
    int size;
    RingEnt ent[18];
} RingCtx;

typedef struct {
    char unk0[0x2C];
    int minNum;
    char unk30[0x1F90];
    char *work;
} RingSys;

extern void func_00354B40(RingCtx *ctx);
extern int func_0034DD70(RingSys *sys, int err);

int func_00350528(RingSys *sys, int buf, int num, int size)
{
    RingCtx *ctx = (RingCtx *)(sys->work + 0x1080);
    int i;

    if (buf == 0 || num == 0 || size == 0) {
        func_00354B40(ctx);
        return 0;
    }
    if (num < sys->minNum + 4)
        return func_0034DD70(sys, 0xFF000F1D);
    ctx->base = buf;
    ctx->ent[0].ptr = buf;
    buf += size;
    ctx->num = num;
    num -= 2;
    ctx->ent[1].ptr = buf;
    buf += size;
    ctx->size = size;
    ctx->ent[0].used = 0;
    ctx->ent[1].used = 0;
    for (i = 0; i < (num <= 16 ? num : 16); i++) {
        ctx->ent[i + 2].used = 0;
        ctx->ent[i + 2].ptr = buf;
        buf += size;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00350528);
#endif
