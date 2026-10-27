/* ee-2.9-991111 */
/* NON_MATCHING func_0039B960: retail loads the 0xFFC0 channel 3 size into v1 and the CHCR
 * address into a0; this build swaps the two registers. */
#include "include_asm.h"
#include "godhand/gameWork.h"
#include "godhand/eeKernel.h"
#include "godhand/sceMpeg.h"

#define IPU_CMD     (*(volatile unsigned int *)0x10002000)
#define IPU_CTRL    (*(volatile int *)0x10002010)
#define D3_CHCR     (*(volatile unsigned int *)0x1000B000)
#define D3_MADR     (*(volatile unsigned int *)0x1000B010)
#define D3_QWC      (*(volatile unsigned int *)0x1000B020)
#define D_STAT      (*(volatile unsigned int *)0x1000E010)

#define IPU_CMD_CSC     0x70000000
#define DMA_CH_IPU_FROM 3

extern char D_0045E5F8[];                       /* the CSC error message */

#ifdef NON_MATCHING
/* Colour-convert mbCount macroblocks into buf in 1023-macroblock commands,
 * the channel 3 handler starting each next one, and report a transfer the
 * handler found left over. */
__attribute__((section(".text.func_0039B960")))
void func_0039B960(MpegCscDec *dec, unsigned int buf, int mbCount)
{
    MpegCbData cb;
    MpegCscWork w;
    int hid;
    int oldstat;

    w.total = mbCount / 1023 + 1;
    w.rem = mbCount;
    w.madr = (buf + 0xFFC00) & 0x0FFFFFFF;
    w.err = 0;
    w.n = 0;
    while (IPU_CTRL < 0)
        ;
    hid = AddDmacHandler2(DMA_CH_IPU_FROM, (int (*)(int, void *))_ch3dmaCSC, 0, &w);
    D_STAT = 8;
    func_003B0810(DMA_CH_IPU_FROM);
    oldstat = func_003B63A0();
    D3_MADR = buf & 0x0FFFFFFF;
    D3_QWC = 0xFFC0;
    D3_CHCR = 0x100;
    if (oldstat)
        EIntr();
    IPU_CMD = IPU_CMD_CSC | 1023;
    cb.type = 4;
    func_0039AB20(dec->cbList, &cb.type);
    while (w.n < w.total)
        ;
    if (w.err)
        func_0039C390((int)dec, (int)D_0045E5F8);
    while (IPU_CTRL < 0)
        ;
    func_003B07A8(DMA_CH_IPU_FROM);
    RemoveDmacHandler(DMA_CH_IPU_FROM, hid);
}

#else
INCLUDE_ASM("asm/nonmatching", func_0039B960);
#endif
