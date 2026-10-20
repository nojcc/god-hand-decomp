/* NON_MATCHING func_003090F8 (sn-2.95.3-136;
 * PARK, 29 diffs): ch and start swap s3/s4; the 0x13 rate switch keeps its constants in a1/v1 with plain beq (ours beql with the 0xE reload hoisted); the channel-record stores are scheduled differently (retail bumps ch and i before them). */
#include "include_asm.h"

#ifdef NON_MATCHING
/* func_003090F8: set up consecutive sound channels from a chunked bank header: one 0xB0 channel
 * record per chunk, with the data address and the SPU block index advanced by the two helpers. */
typedef struct {
    unsigned char active;               /* 0x00 */
    unsigned char unk01;
    unsigned char rate;                 /* 0x02 */
    unsigned char block;                /* 0x03 */
    unsigned short f4;                  /* 0x04 */
    unsigned short f6;                  /* 0x06 */
    char *chunk;                        /* 0x08 */
    int pad0C;
    short f10;                          /* 0x10 */
    short len;                          /* 0x12 */
    int pad14;
    long param[2];                      /* 0x18 */
    char pad28[0x88];
} SndChan3090F8;

extern SndChan3090F8 D_00747BA0[];
extern char *func_003092E0(char *chunk, char *addr);
extern unsigned int func_00309568(char *chunk, unsigned int block);

__attribute__((section(".text.func_003090F8")))
void func_003090F8(unsigned char ch, char *hdr, char *addr, unsigned int spu)
{
    char *chunk;
    char *start;
    SndChan3090F8 *c;
    unsigned int block;
    unsigned int i;

    chunk = hdr + 0x80;
    if (((unsigned char *)hdr)[5] == 0)
        chunk = hdr + 0x10;
    if (spu < 0x1C00) {
        unsigned int v = spu - 0x1C00;

        block = v >> 5;
        block += ((v & 0x1F) - 4) >> 3;
    } else {
        block = ((spu - 0x1C00) >> 2) + 0x20;
    }
    for (i = 0; i < *(unsigned short *)(hdr + 6); i++) {
        start = addr;
        c = &D_00747BA0[ch];
        addr = func_003092E0(chunk, start);
        c->block = block;
        block = func_00309568(chunk, block);
        c->unk01 = 0;
        c->active = 1;
        c->rate = 0;
        if (*(unsigned short *)(chunk + 0xE) != 0) {
            switch (*(unsigned char *)(chunk + 0x13)) {
            case 4:
                c->rate = (*(unsigned short *)(chunk + 0xE) + 15) / 16;
                break;
            case 5:
                c->rate = (*(unsigned short *)(chunk + 0xE) + 255) / 256;
                break;
            }
        }
        D_00747BA0[ch].len = addr - start;
        D_00747BA0[ch].chunk = chunk;
        D_00747BA0[ch].f10 = 1;
        D_00747BA0[ch].f4 = *(unsigned short *)(chunk + 0x14);
        D_00747BA0[ch].f6 = *(unsigned short *)(chunk + 0x16);
        D_00747BA0[ch].param[0] = *(long *)(chunk + 0x18);
        D_00747BA0[ch].param[1] = *(long *)(chunk + 0x20);
        ch++;
        chunk = chunk + *(int *)chunk;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_003090F8);
#endif
