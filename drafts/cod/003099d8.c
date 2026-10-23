/* NON_MATCHING func_003099D8 (sn-2.95.3-136, as sn, extern_jtbl D_004501F0): the packet stores differ. Retail writes the scratchpad packet in source order, loading each quadword's address into a register on its own, and spills bitbltbuf to the stack in a 0xB0 frame; ours keeps one base register and lets the scheduler group the stores (0xA0 frame, 134 of 149 words). */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef unsigned int  u_int;
typedef unsigned long u_long;

typedef struct {
    volatile unsigned int chcr;
} sceDmaChan;

/* The GS image upload packet, built in scratchpad: a DMA cnt tag over the A+D GIFtag and the four transfer
 * registers, then the IMAGE GIFtag and a refe tag pointing at the pixels. */
typedef struct GsLoadImagePacket {
    u_long dmatag[2];
    u_long giftag[2];
    u_long bitbltbuf;
    long   bitbltbufaddr;
    u_long trxpos;
    long   trxposaddr;
    u_long trxreg;
    long   trxregaddr;
    u_long trxdir;
    long   trxdiraddr;
    u_long imagetag[2];
    u_long reftag[2];
} GsLoadImagePacket;

extern int func_00397550(sceDmaChan *chan, int mode, int timeout);
extern void func_003973E8(int *a0, int a1);

#define DMA_GIF ((sceDmaChan *)0x1000A000)
#define SPR_PACKET ((GsLoadImagePacket *)0x70000000)

/* Upload a w x h image in pixel format psm from data to GS buffer tbp (width tbw), in chunks of up to 512 KB
 * sent through scratchpad. */
__attribute__((section(".text.func_003099D8")))
void func_003099D8(int psm, int tbp, int tbw, int w, int h, char *data)
{
    u_int stride;
    u_int left;
    u_int chunk;
    u_int n;
    u_int lines;
    u_int qwc;
    int y;
    u_long bitbltbuf;

    switch (psm) {
    case 0x00:
    case 0x01:
    case 0x30:
    case 0x31:
        stride = w * 4;
        break;
    case 0x02:
    case 0x0A:
    case 0x32:
    case 0x3A:
        stride = w * 2;
        break;
    case 0x13:
    case 0x1B:
        stride = w;
        break;
    case 0x14:
    case 0x24:
    case 0x2C:
        stride = w / 2;
        break;
    default:
        return;
    }
    left = stride * h;
    y = 0;
    chunk = (0x80000 - stride) / stride * stride;
    if (left == 0) {
        return;
    }
    bitbltbuf = ((u_long)tbp << 32) | ((u_long)tbw << 48) | ((u_long)psm << 56);
    do {
        func_00397550(DMA_GIF, 0, 0);
        if (left < chunk) {
            n = left;
            lines = (left + stride - 1) / stride;
            left = 0;
        } else {
            lines = (chunk + stride - 1) / stride;
            n = chunk;
            left -= n;
        }
        SPR_PACKET->dmatag[0] = 0x10000006;
        SPR_PACKET->dmatag[1] = 0;
        SPR_PACKET->giftag[0] = (1L << 60) | 4;
        SPR_PACKET->giftag[1] = 0xE;
        SPR_PACKET->bitbltbuf = bitbltbuf;
        SPR_PACKET->bitbltbufaddr = 0x50;
        SPR_PACKET->trxpos = (u_long)y << 48;
        SPR_PACKET->trxposaddr = 0x51;
        SPR_PACKET->trxreg = w | ((u_long)lines << 32);
        SPR_PACKET->trxregaddr = 0x52;
        SPR_PACKET->trxdir = 0;
        SPR_PACKET->trxdiraddr = 0x53;
        qwc = (n + 15) >> 4;
        SPR_PACKET->imagetag[0] = (u_long)(qwc | 0x8000) | (2L << 58);
        SPR_PACKET->imagetag[1] = 0;
        SPR_PACKET->reftag[0] = ((u_long)(u_int)data << 32) | qwc;
        SPR_PACKET->reftag[1] = 0;
        y += lines;
        data += n;
        func_003973E8((int *)DMA_GIF, 0x70000000 | 0x80000000);
    } while (left != 0);
}
#else
INCLUDE_ASM("asm/nonmatching", func_003099D8);
#endif
