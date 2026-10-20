/* ee-2.9-991111: SCE libmpeg CSC transfer: push the image through the IPU on DMA channel 3 in
 * 0xFFC0-quadword chunks, chained by _ch3dmaCSC, and wait for the last chunk. */

typedef unsigned int u_int;

#define D_STAT   (*(volatile u_int *)0x1000E010)
#define D3_CHCR  (*(volatile u_int *)0x1000B000)
#define D3_MADR  (*(volatile u_int *)0x1000B010)
#define D3_QWC   (*(volatile u_int *)0x1000B020)
#define IPU_CMD  (*(volatile u_int *)0x10002000)
#define IPU_CTRL (*(volatile int *)0x10002010)

typedef struct IpuDmaCh {
    volatile int n;
    int          done;
    unsigned int rem;
    unsigned int madr;
    int          total;
} IpuDmaCh;

struct cbp { int reason; int pad[7]; };

extern char D_0045E5F8[];
extern int _ch3dmaCSC(int chan, IpuDmaCh *p);
extern int AddDmacHandler2(int chan, int (*fn)(int, IpuDmaCh *), int next, void *arg);
extern int RemoveDmacHandler(int chan, int id);
extern int func_003B0810(int chan);                    /* EnableDmac */
extern int func_003B07A8(int chan);                    /* DisableDmac */
extern int func_003B63A0(void);                        /* DIntr */
extern int EIntr(void);
extern int func_0039AB20(void *p, struct cbp *q);      /* _sceMpegDispatchMpegCallback */
extern void func_0039C390(void *m, const char *msg);   /* _sceMpegError */

__attribute__((section(".text.func_0039B960")))
void func_0039B960(void *m, u_int src, int nqw)
{
    struct cbp cb;
    IpuDmaCh ch;
    int id;
    int oldstat;
    u_int qwc = 0xFFC0;

    ch.total = nqw / 1023 + 1;
    ch.done = 0;
    ch.n = 0;
    ch.rem = nqw;
    ch.madr = (src + 0xFFC00) & 0x0FFFFFFF;
    while (IPU_CTRL < 0)
        ;
    id = AddDmacHandler2(3, _ch3dmaCSC, 0, &ch);
    D_STAT = 8;
    func_003B0810(3);
    oldstat = func_003B63A0();
    D3_MADR = src & 0x0FFFFFFF;
    D3_QWC = qwc;
    D3_CHCR = 0x100;
    if (oldstat)
        EIntr();
    IPU_CMD = 0x700003FF;
    cb.reason = 4;
    func_0039AB20(*(void **)((char *)m + 0x868), &cb);
    while (ch.n < ch.total)
        ;
    if (ch.done)
        func_0039C390(m, D_0045E5F8);
    while (IPU_CTRL < 0)
        ;
    func_003B07A8(3);
    RemoveDmacHandler(3, id);
}
