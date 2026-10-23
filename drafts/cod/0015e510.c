/* sn-2.95.3-136 (as=sn, extern_jtbl): func_0015E510.
 * Differs from retail: retail has a zero-division trap in both arms of the size clamp, the leftover of a row count
 * it computes and never uses, and keeps the A+D address 0x3F of TEXFLUSH in an earlier register; the argument copies differ. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/gsLoadImage.h"

/* Build the DMA chain that uploads a w x h image of pixel format psm to tbp/tbw in GS memory,
 * capped at the largest whole number of rows that fits under 512 KB. Unknown formats build nothing. */
__attribute__((section(".text.func_0015E510")))
void func_0015E510(GsLoadImagePacket *pkt, int psm, int tbp, int tbw, int w, int h, char *data)
{
    unsigned int row;
    unsigned int total;
    unsigned int size;
    unsigned int qwc;

    switch (psm) {
    case 0x00:
    case 0x01:
    case 0x30:
    case 0x31:
        row = w * 4;
        break;
    case 0x02:
    case 0x0A:
    case 0x32:
    case 0x3A:
        row = w * 2;
        break;
    case 0x13:
    case 0x1B:
        row = w;
        break;
    case 0x14:
    case 0x24:
    case 0x2C:
        row = w / 2;
        break;
    default:
        return;
    }
    total = row * h;
    size = total;
    if (total >= (0x80000 - row) / row * row)
        size = (0x80000 - row) / row * row;
    qwc = (size + 15) >> 4;

    pkt->dmaTag = 0x10000006;
    pkt->vifFlush = 0x11000000;
    pkt->vifDirect = 0x50000006;
    pkt->gifTag[0] = 0x1000000000008004L;
    pkt->gifTag[1] = 0xE;
    pkt->bitbltbuf = (unsigned long)tbp << 32 | (unsigned long)tbw << 48 | (unsigned long)psm << 56;
    pkt->bitbltbufAddr = 0x50;
    pkt->trxpos = 0;
    pkt->trxposAddr = 0x51;
    pkt->trxreg = (unsigned long)w | (unsigned long)h << 32;
    pkt->trxregAddr = 0x52;
    pkt->trxdir = 0;
    pkt->trxdirAddr = 0x53;
    pkt->imageTag[0] = (unsigned long)(qwc | 0x8000) | (unsigned long)0x8000 << 44;
    pkt->imageTag[1] = 0;
    pkt->refTag = (unsigned long)(qwc | 0x30000000) | (unsigned long)((int)data & 0x0FFFFFFF) << 32;
    pkt->vifNop = 0;
    pkt->vifDirectImage = qwc | 0x50000000;
    pkt->endTag = 0x10000002;
    pkt->endVifFlush = 0x11000000;
    pkt->endVifDirect = 0x50000002;
    pkt->endGifTag[0] = 0x1000000000008001L;
    pkt->endGifTag[1] = 0xE;
    pkt->texflush = 0xFF;
    pkt->texflushAddr = 0x3F;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0015E510);
#endif
