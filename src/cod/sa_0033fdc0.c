/* func_0033FDC0: CRI stream DMA transfer kick (cygnus-2.96, drop-reorder) */
typedef struct {
    char *addr;
    int len;
} Buf33F;

typedef struct Strm33F Strm33F;
typedef struct {
    char pad0[0x18];
    void (*get)(Strm33F *s, int id, int max, Buf33F *b);
    void (*put)(Strm33F *s, int id, Buf33F *b);
    void (*reset)(Strm33F *s, int id, Buf33F *b);
} StrmVt33F;
struct Strm33F {
    StrmVt33F *vt;
};

typedef struct {
    signed char f0;
    signed char active;
    signed char busy;
    char pad3;
    Strm33F *src;
    Strm33F *dst;
    Buf33F cur0;
    Buf33F cur1;
    int dma[5];
    char pad30[8];
    int unit;
    int total;
} Xfer33F;

extern char D_00456A10[];
extern char D_00456A30[];
extern char D_00456A58[];
extern char D_00456A88[];
extern char D_00456AB0[];
extern void func_003260C8(char *fmt, ...);
extern void func_0033ACA0(Buf33F *in, int n, Buf33F *out, Buf33F *rest);
extern void SyncDCache(void *start, void *end);
extern int func_003B2148(int *dma, int ch);

__attribute__((section(".text.func_0033FDC0")))
void func_0033FDC0(Xfer33F *x)
{
    Buf33F b0;
    Buf33F t0;
    Buf33F b1;
    Buf33F t1;
    int n;

    if (x->active != 1)
        return;
    if (x->busy == 1) {
        x->src->vt->reset(x->src, 0, &x->cur0);
        x->cur0.addr = 0;
        x->cur0.len = 0;
        x->dst->vt->reset(x->dst, 1, &x->cur1);
        x->cur1.addr = 0;
        x->cur1.len = 0;
        x->total += x->cur0.len;
        x->busy = 0;
        if (x->cur0.len != 0) {
            func_003260C8(D_00456A10);
            for (;;)
                ;
        }
    }
    if (x->busy != 0)
        return;
    x->src->vt->get(x->src, 1, 0x7FFFFFFF, &b0);
    x->dst->vt->get(x->dst, 0, 0x7FFFFFFF, &b1);
    n = b1.len;
    if (b0.len < n)
        n = b0.len;
    n = (n / x->unit) * x->unit;
    func_0033ACA0(&b0, n, &b0, &t0);
    x->src->vt->put(x->src, 1, &t0);
    func_0033ACA0(&b1, n, &b1, &t1);
    x->dst->vt->put(x->dst, 0, &t1);
    if (n <= 0)
        return;
    if (b0.len & 0x3F) {
        func_003260C8(D_00456A30);
        func_003260C8(D_00456A58, b0.addr, b1.addr, b0.len);
        for (;;)
            ;
    }
    if ((int)b0.addr & 0x3F) {
        func_003260C8(D_00456A88);
        func_003260C8(D_00456A58, b0.addr, b1.addr, b0.len);
        for (;;)
            ;
    }
    if ((int)b1.addr & 0x3F) {
        func_003260C8(D_00456AB0);
        func_003260C8(D_00456A58, b0.addr, b1.addr, b0.len);
        for (;;)
            ;
    }
    SyncDCache(b0.addr, b0.addr + b0.len - 1);
    x->dma[0] = (int)b0.addr & 0x0FFFFFFF;
    x->dma[1] = (int)b1.addr;
    x->dma[2] = b0.len;
    x->dma[3] = 0;
    x->dma[4] = func_003B2148(x->dma, 1);
    if (x->dma[4] == 0) {
        x->src->vt->put(x->src, 1, &b0);
        x->dst->vt->put(x->dst, 0, &b1);
        return;
    }
    x->cur0 = b0;
    x->cur1 = b1;
    x->busy = 1;
}
