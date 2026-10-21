/* NON_MATCHING func_003977C8 (ee-2.9-991111): rpc buffer word 4 = 0 store is scheduled after the arg store (retail: before cmd); insensitive to statement order, int[] buffer, volatile, call prototype */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    unsigned char pad0[0x24];
    int server;
} SifRpcClientData;

typedef struct PadSlot {
    int a;                      /* 0x00 */
    int b;                      /* 0x04 */
    int c;                      /* 0x08 */
    char unk0C[0x10];
} PadSlot;

typedef struct PadState {
    char unk00[0x10];
    PadSlot slot[2][4];   /* 0x10 */
} PadState;

typedef struct PadRpcBuf {
    int cmd;                    /* 0x00 */
    char unk04[8];
    int result;                 /* 0x0C */
    int unk10;                  /* 0x10 */
    int arg;                    /* 0x14 */
} PadRpcBuf;

extern int func_003B3128(SifRpcClientData *cd, int fno, int mode, void *send, int ssize, void *recv,
                         int rsize, void *end, void *earg);
extern int func_003B63A0(void);
extern void func_003B2488(unsigned int cause, void *handler, void *arg);
extern void EIntr(void);
extern void _pad_intr_hdr(void);
extern SifRpcClientData D_0077C0C0[2];
extern PadState D_0077C110;
extern PadRpcBuf D_0077C300;
extern int D_003F85D0;
extern int D_003F85D4;

int func_003977C8(void)
{
    int i;
    int intr;

    for (i = 0; i < 4; i++) {
        D_0077C110.slot[0][i].a = 0;
        D_0077C110.slot[0][i].c = 0;
        D_0077C110.slot[0][i].b = 0;
        D_0077C110.slot[1][i].a = 0;
        D_0077C110.slot[1][i].c = 0;
        D_0077C110.slot[1][i].b = 0;
    }
    D_0077C300.unk10 = 0;
    D_0077C300.cmd = 0x10;
    D_0077C300.arg = D_003F85D4;
    if (func_003B3128(&D_0077C0C0[0], 1, 0, &D_0077C300, 0x80, &D_0077C300, 0x80, 0, 0) < 0)
        return 0;
    D_003F85D0 = 0;
    intr = func_003B63A0();
    func_003B2488(0x80000019, _pad_intr_hdr, 0);
    if (intr == 1)
        EIntr();
    return D_0077C300.result;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003977C8);
#endif
