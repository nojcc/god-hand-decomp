#ifndef GODHAND_SCEDMA_H
#define GODHAND_SCEDMA_H

/* An EE DMA channel's registers (libdma sceDmaChan); each register sits in its own 16-byte slot.
 * The transfer setups write them as plain memory; the waits read them through a volatile pointer. */
typedef struct {
    int chcr;                   /* 0x00 */
    unsigned int pad04[3];
    void *madr;                 /* 0x10 */
    unsigned int pad14[3];
    int qwc;                    /* 0x20 */
    unsigned int pad24[3];
    void *tadr;                 /* 0x30 */
} sceDmaChan;

#define SCE_DMA_GIF ((sceDmaChan *)0x1000A000)

/* Spin until the channel stops; pause it if that takes too long. */
void WaitDma(volatile sceDmaChan *chan);
/* Stop the channel; returns CHCR as it was. */
unsigned int sceDmaPause(volatile sceDmaChan *chan);
/* Turn a scratchpad address (0x7xxxxxxx) into the DMA's scratchpad form (bit 31 set). */
unsigned int func_003970A0(unsigned int addr);
/* sceDmaSend: start a chain transfer at the tag. */
void func_003973E8(sceDmaChan *chan, void *tag);
/* sceDmaSendN: send qwc quadwords from addr. */
void func_00397450(sceDmaChan *chan, void *addr, int qwc);
/* sceDmaRecvN: receive qwc quadwords into addr. */
void func_003974D0(sceDmaChan *chan, void *addr, int qwc);

#endif
