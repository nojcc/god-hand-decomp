/* sn-2.95.3-136 (as=sn, extern_jtbl): func_0015E8B8.
 * Differs from retail: in the size clamp retail keeps the total in the h register and the cap in a2 and copies
 * them to the size register last; the argument copies (tbp to t6, data left in t2) and the TEXFLUSH address register differ. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/gsLoadImage.h"

/* Build the DMA chain that uploads a w x h image of pixel format psm to tbp/tbw in GS memory,
 * capped at the largest whole number of rows that fits under 512 KB. Unknown formats build nothing. */
__attribute__((section(".text.func_0015E8B8")))
void func_0015E8B8(GsLoadImagePacket *pkt, int psm, int tbp, int tbw, int w, int h, char *data)
{
    unsigned int row;
    unsigned int total;
    unsigned int size;
    unsigned int qwc;
    unsigned int rows;

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
    if (total < (0x80000 - row) / row * row) {
        size = total;
        rows = (size + row - 1) / row;
    } else {
        size = (0x80000 - row) / row * row;
        rows = (size + row - 1) / row;
    }
    qwc = (size + 15) >> 4;

    pkt[1].dmaTag = 0x10000006;
    pkt[1].vifFlush = 0x11000000;
    pkt[1].vifDirect = 0x50000006;
    pkt[1].gifTag[0] = 0x1000000000008004L;
    pkt[1].gifTag[1] = 0xE;
    pkt[1].bitbltbuf = (unsigned long)tbp << 32 | (unsigned long)tbw << 48 | (unsigned long)psm << 56;
    pkt[1].bitbltbufAddr = 0x50;
    pkt[1].trxpos = 0;
    pkt[1].trxposAddr = 0x51;
    pkt[1].trxreg = (unsigned long)w | (unsigned long)rows << 32;
    pkt[1].trxregAddr = 0x52;
    pkt[1].trxdir = 0;
    pkt[1].trxdirAddr = 0x53;
    pkt[1].imageTag[0] = (unsigned long)(qwc | 0x8000) | (unsigned long)0x8000 << 44;
    pkt[1].imageTag[1] = 0;
    pkt[1].refTag = (unsigned long)(qwc | 0x30000000) | (unsigned long)((int)data & 0x0FFFFFFF) << 32;
    pkt[1].vifNop = 0;
    pkt[1].vifDirectImage = qwc | 0x50000000;
    pkt[1].endTag = 0x10000002;
    pkt[1].endVifFlush = 0x11000000;
    pkt[1].endVifDirect = 0x50000002;
    pkt[1].endGifTag[0] = 0x1000000000008001L;
    pkt[1].endGifTag[1] = 0xE;
    pkt[1].texflush = 0xFF;
    pkt[1].texflushAddr = 0x3F;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0015E8B8);
#endif
