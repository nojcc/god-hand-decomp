/* NON_MATCHING func_003B3650 (ee-2.9-991111): req and pkt get s1/s0 swapped versus retail
 * (no declaration order or register keyword moves them); the final DMA slot stores schedule differently. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct RpcPkt {
    char unk00[0x10];
    int f10;                            /* 0x10 */
    char unk14[4];
    int f18;                            /* 0x18 */
    int f1C;                            /* 0x1C */
    int cmd;                            /* 0x20 */
} RpcPkt;

typedef struct RpcReq {
    char unk00[4];
    void *(*pack)(int arg, void *buf, int size);    /* 0x04 */
    void *buf;                          /* 0x08 */
    int size;                           /* 0x0C */
    char unk10[0xC];
    int f1C;                            /* 0x1C */
    void *pktDest;                      /* 0x20 */
    int arg;                            /* 0x24 */
    void *dest;                         /* 0x28 */
    int destSize;                       /* 0x2C */
    int direct;                         /* 0x30 */
    unsigned int mode;                  /* 0x34 */
} RpcReq;

typedef struct SifDmaT {
    void *src;
    void *dest;
    int size;
    int attr;
} SifDmaT;

extern char D_0077FF40[];
extern void func_003B2850(void *addr, int size);
extern int func_003B63A0(void);
extern void *_sceRpcGetFPacket2(void *data, int rid);
extern void *func_003B2B90(void *data);
extern int EIntr(void);
extern int sceSifSendCmd(unsigned int cmd, void *pkt, int size, void *src, void *dest, int dsize);
extern unsigned int func_003B2148(SifDmaT *dma, int n);

__attribute__((section(".text.func_003B3650")))
void func_003B3650(RpcReq *req)
{
    SifDmaT dma[2];
    RpcPkt *pkt;
    void *data;
    int size;
    int n;
    int i;
    unsigned int id;

    size = 0;
    data = req->pack(req->arg, req->buf, req->size);
    if (data != 0)
        size = req->destSize;
    if (req->size > 0)
        func_003B2850(req->buf, req->size);
    if (size > 0)
        func_003B2850(data, size);
    func_003B63A0();
    if (req->mode & 4)
        pkt = _sceRpcGetFPacket2(D_0077FF40, req->mode >> 16);
    else
        pkt = func_003B2B90(D_0077FF40);
    EIntr();
    pkt->cmd = 0x8000000A;
    pkt->f1C = req->f1C;
    if (req->direct != 0) {
        while (sceSifSendCmd(0x80000008, pkt, 0x40, data, req->dest, size) == 0)
            ;
        return;
    }
    pkt->f18 = 0;
    pkt->f10 = 0;
    n = 0;
    if (size > 0) {
        dma[0].src = data;
        dma[0].dest = req->dest;
        dma[0].size = size;
        dma[0].attr = 0;
        n = 1;
    }
    dma[n].src = pkt;
    dma[n].dest = req->pktDest;
    dma[n].size = 0x40;
    dma[n].attr = 0;
    n++;
    do {
        id = func_003B2148(dma, n);
        if (id != 0)
            break;
        for (i = 0x100000; i != -1; i--)
            ;
    } while (id == 0);
}
#else
INCLUDE_ASM("asm/nonmatching", func_003B3650);
#endif
