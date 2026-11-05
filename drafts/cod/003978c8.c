/* ee-2.9-991111. Differs from retail: retail has a 0x150 frame (0x100 bytes of locals before the saved registers, only the 16-byte DMA record used) and recomputes the [port][slot] address after SifDmaStat; ours has a 0x60 frame and keeps the address in a saved register. */
#include "godhand/eeKernel.h"
#ifdef NON_MATCHING
#include "godhand/libpad.h"

typedef struct {
    unsigned int  data;
    unsigned int  addr;
    unsigned int  size;
    unsigned int  mode;
} PadDma;

extern int D_003F85CC;
extern char D_0045E088[];
extern int SifDmaStat(unsigned int id);
extern void SyncDCache(void *start, void *end);
extern unsigned int func_003B2148(PadDma *dma, int n);

/* Sends the slot's 0x20-byte command block to the IOP, alternating between its two buffers. Returns 1 once the DMA is queued. */
__attribute__((section(".text.func_003978C8")))
int func_003978C8(int port, int slot)
{
    PadCmd *cmd = D_0077C110[port][slot].cmd;
    PadDma dma;
    unsigned int dst;
    unsigned int id;

    if (D_0077C110[port][slot].dmaid == 0 || SifDmaStat(D_0077C110[port][slot].dmaid) < 0) {
        cmd->count++;
        dst = D_0077C110[port][slot].iopCmd + ((cmd->count & 1) << 5);
        SyncDCache(cmd, (char *)cmd + 0x1F);
        dma.data = (unsigned int)cmd;
        dma.addr = dst;
        dma.size = 0x20;
        dma.mode = 0;
        id = func_003B2148(&dma, 1);
        if (id != 0) {
            D_0077C110[port][slot].dmaid = id;
            return 1;
        }
    }
    if (D_003F85CC) {
        func_003B1F28(D_0045E088);
    }
    return 0;
}
#else
#include "include_asm.h"
INCLUDE_ASM("nonmatching", func_003978C8);
#endif
