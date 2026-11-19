/* ee-2.9-991111 */
/* NON_MATCHING: 235 of 237 words. The slot lands in a2 (retail a1) because the 0x20000000 constant
 * overlaps it, and from the dread copy on every block copy and reload temporary is one register
 * later than retail's (dread source a0 and destination a2 in retail). */
#include "include_asm.h"
#include "godhand/criStm.h"
#include "godhand/eeKernel.h"

/* A read request's unaligned head and tail, which the IOP returns separately. */
typedef struct {
    int ssize;
    int esize;
    char *sbuf;
    char *ebuf;
    char sbuffer[64];
    char ebuffer[64];
} sceFsReadData;

/* The RPC end-function argument. */
typedef struct {
    char unk0[0xC];
    int slot;           /* the reply slot, when D_003FAEE0 is set */
} sceFsRcvArg;

#define SCEFS_CMD_READ     2
#define SCEFS_CMD_DREAD    11
#define SCEFS_CMD_GETSTAT  12

#define SCEFS_UNCACHED(p)  ((char *)((unsigned int)(p) | 0x20000000))

extern int D_003FAEE0;
extern int D_003FAED8;
extern char D_00780C40[][0x440];
extern volatile int D_003FAE58[32];   /* semaphores of requests nobody waits on; this handler frees them */

#ifdef NON_MATCHING
/* File-I/O RPC reply interrupt: copies the reply's data out to the caller, then wakes it or frees its slot. */
__attribute__((section(".text._sceFs_Rcv_Intr")))
void _sceFs_Rcv_Intr(sceFsRcvArg *arg)
{
    int sema;
    int cmd;
    int *result;
    unsigned int resultSize;
    char *dst;
    unsigned int len;
    char *rcv;
    sceFsReadData *rd;
    char *buf;
    char *ubuf;
    int slot;
    int i;

    slot = 0;
    if (D_003FAEE0 != 0) {
        slot = arg->slot;
    }
    D_003FAED8 = slot;
    rcv = SCEFS_UNCACHED(D_00780C40[slot]);
    __builtin_memcpy(&sema, rcv, sizeof(sema));
    __builtin_memcpy(&cmd, rcv + 4, sizeof(cmd));
    __builtin_memcpy(&result, rcv + 8, sizeof(result));
    __builtin_memcpy(&resultSize, rcv + 0xC, sizeof(resultSize));
    if (sema >= 0) {
        func_003A5148(result, rcv + 0x10, resultSize);
    }
    switch (cmd) {
    case SCEFS_CMD_READ:
        rd = (sceFsReadData *)(rcv + 0x14);
        if (rd->ssize > 0) {
            buf = rd->sbuf;
            ubuf = SCEFS_UNCACHED(buf);
            for (i = 0; i < rd->ssize; i++) {
                buf[i] = ubuf[i] = rd->sbuffer[i];
            }
        }
        if (rd->esize > 0) {
            buf = rd->ebuf;
            ubuf = SCEFS_UNCACHED(buf);
            for (i = 0; i < rd->esize; i++) {
                buf[i] = ubuf[i] = rd->ebuffer[i];
            }
        }
        break;
    case SCEFS_CMD_DREAD:
        if (*result > 0) {
            __builtin_memcpy(&dst, rcv + 0x14, sizeof(dst));
            __builtin_memcpy(dst, rcv + 0x18, 0x144);
        }
        break;
    case SCEFS_CMD_GETSTAT:
        __builtin_memcpy(&dst, rcv + 0x14, sizeof(dst));
        __builtin_memcpy(dst, rcv + 0x18, 0x40);
        break;
    case 23:
    case 25:
    case 26:
        __builtin_memcpy(&dst, rcv + 0x14, sizeof(dst));
        __builtin_memcpy(&len, rcv + 0x18, sizeof(len));
        if (len > 0x400) {
            len = 0x400;
        }
        func_003A5148(dst, rcv + 0x1C, len);
        break;
    }
    if (sema < 0) {
        sema = -sema;
        for (i = 0; i < 32; i++) {
            if (D_003FAE58[i] == sema) {
                D_003FAE58[i] = -1;
                break;
            }
        }
    } else {
        iSignalSema(sema);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", _sceFs_Rcv_Intr);
#endif
