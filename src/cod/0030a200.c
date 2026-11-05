/* sn-2.95.3-136: func_0030A200, when entry n is ready, sync and send its two GIF packets (+0x8, +0xC). */
#include "godhand/sceDma.h"

extern int func_00397550(sceDmaChan *chan, int mode, int timeout);

typedef struct {
    unsigned char pad0;
    unsigned char ready;
    char pad2[0x08 - 0x02];
    void *pkt0;
    void *pkt1;
    char pad10[0xB0 - 0x10];
} GifPktEnt;

extern GifPktEnt D_00747BA0[];

__attribute__((section(".text.func_0030A200")))
void func_0030A200(int n)
{
    GifPktEnt *e = &D_00747BA0[n];

    if (e->ready == 1) {
        func_00397550(SCE_DMA_GIF, 0, 0);
        func_003973E8(SCE_DMA_GIF, e->pkt0);
        func_00397550(SCE_DMA_GIF, 0, 0);
        func_003973E8(SCE_DMA_GIF, e->pkt1);
    }
}
