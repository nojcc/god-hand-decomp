/* NON_MATCHING func_0031AFE0 (cygnus-2.96 drop-reorder as sn;
 * PARK, 163 diffs): pad state update; union masks make the loop reload like retail, but char sign-test reloads become lbu+sll, arg regs shift by one and retail hoists lui %hi(D_00747A78) above the loop */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef union {
    unsigned long l;
    unsigned int w[2];
} Mask64;

typedef struct {
    unsigned long out;
    unsigned int dir;
    unsigned int dirOld;
    unsigned int dirTrg;
    char pad14[4];
    Mask64 cur;
    unsigned long old;
    unsigned long trg;
    unsigned long rel;
    Mask64 f38;
    Mask64 f40;
    char pad48[0x68 - 0x48];
    char b[0x14];
    float f7C;
    float f80;
} PadSt;

typedef struct {
    unsigned int btn;
    char pad4[0x18 - 4];
    unsigned int f18;
    unsigned int f1C;
    char pad20[0x60 - 0x20];
    char b[0x14];
    float f74;
    float f78;
} PadRaw;

extern int D_00747A0C;
extern int D_00747A34;
extern int D_00747A78;
extern unsigned int D_003C3D50[];
extern unsigned int D_003C3E50[];
extern void func_0031B410(void *ctx, PadSt *st);
extern void func_0031B4B8(void *ctx, PadSt *st);
extern void func_0031B2E0(void *ctx, PadSt *st);

void func_0031AFE0(void *ctx, PadSt *st, PadRaw *raw)
{
    unsigned int *tbl;
    unsigned long bit;
    unsigned int i;
    long t;
    long u;

    st->f40.l = 0;
    st->old = st->cur.l;
    st->dirOld = st->dir;
    st->cur.l = 0;
    st->f38.l = 0;
    st->dir = 0;
    bit = 1;
    if (D_00747A0C == 0)
        tbl = D_003C3D50;
    else
        tbl = D_003C3E50;
    if (D_00747A34 & 0x800)
        tbl = D_003C3E50;
    for (i = 0; i < 64; i++) {
        if (raw->btn & *tbl)
            st->cur.l |= bit;
        if (raw->f18 & *tbl)
            st->f40.l |= bit;
        if (raw->f1C & *tbl)
            st->f38.l |= bit;
        tbl++;
        bit <<= 1;
    }
    if (raw->b[0x10] > 0)
        st->dir |= 0x80;
    if (raw->b[0x10] < 0)
        st->dir |= 0x40;
    if (raw->b[0x11] > 0)
        st->dir |= 0x10;
    if (raw->b[0x11] < 0)
        st->dir |= 0x20;
    if (raw->b[0x12] > 0)
        st->dir |= 0x8;
    if (raw->b[0x12] < 0)
        st->dir |= 0x4;
    if (raw->b[0x13] > 0)
        st->dir |= 0x1;
    if (raw->b[0x13] < 0)
        st->dir |= 0x2;
    st->trg = (st->cur.l ^ st->old) & st->cur.l;
    st->rel = (st->cur.l ^ st->old) & st->old;
    st->dirTrg = (st->dir ^ st->dirOld) & st->dir;
    t = D_00747A78;
    if ((t & 0x2000000) && !(((unsigned long)t >> 5) & 1)) {
        func_0031B410(ctx, st);
        return;
    }
    u = D_00747A78;
    if ((((unsigned long)u >> 4) & 1UL) == 1UL) {
        func_0031B4B8(ctx, st);
        return;
    }
    st->out = st->cur.l;
    st->b[0] = raw->b[0];
    st->b[1] = raw->b[1];
    st->b[2] = raw->b[2];
    st->b[3] = raw->b[3];
    st->b[7] = raw->b[7];
    st->b[6] = raw->b[6];
    st->b[4] = raw->b[4];
    st->b[5] = raw->b[5];
    st->b[8] = raw->b[8];
    st->b[11] = raw->b[11];
    st->b[9] = raw->b[9];
    st->b[10] = raw->b[10];
    st->b[12] = raw->b[12];
    st->b[13] = raw->b[13];
    st->b[14] = raw->b[14];
    st->b[15] = raw->b[15];
    st->b[16] = raw->b[16];
    st->b[17] = raw->b[17];
    st->b[18] = raw->b[18];
    st->b[19] = raw->b[19];
    st->f7C = raw->f74;
    st->f80 = raw->f78;
    func_0031B2E0(ctx, st);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0031AFE0);
#endif
