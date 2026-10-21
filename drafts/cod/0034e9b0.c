/* NON_MATCHING func_0034E9B0: read one chunk header from the SFD input and hand the chunk to its stream object or its type handler.
* Only the callee-saved registers of self and in are swapped (retail s2/s1); header fields copied to locals and an 8-aligned chunk type give the hoisted ld/t0 by-value pass, and moving in = s->in first changes nothing. */
#include "include_asm.h"
#include "godhand/sftim.h"

#ifdef NON_MATCHING
#define SFD_ERR_HDR     0xFF000D06
#define SFD_ERR_LEN     0xFF000D0E
#define SFD_ID_BASE     0xAC            /* first stream id with an object slot */

/* The SJ chunk as the header reader hands it over: one 8-byte register. */
typedef struct Ck34E9B0 {
    unsigned char *ptr;                 /* 0x00 */
    int len;                            /* 0x04 */
} __attribute__((aligned(8))) Ck34E9B0;

typedef struct SfdChunkHdr {
    Ck34E9B0 ck;                         /* 0x00 */
    char pad08[8];
    int id;                             /* 0x10 */
    int type;                           /* 0x14 */
    int arg;                            /* 0x18 */
    char pad1C[8];
    int len;                            /* 0x24 */
} SfdChunkHdr;

typedef struct SfdChunkIn {
    void *obj[0x54];                    /* 0x000 by id - SFD_ID_BASE */
    int unk150;                         /* 0x150 */
    int unk154;                         /* 0x154 */
} SfdChunkIn;

typedef struct SfdChunkHn {
    char pad0[0x1F7C];
    SfdChunkIn *in;                       /* 0x1F7C */
} SfdChunkHn;

typedef int (*ChunkFn34E9B0)(SfdChunkHn *s, int arg, int a1, int len, Ck34E9B0 ck);

extern ChunkFn34E9B0 D_00459680[];

extern int func_00368C60(void *sj, SfdChunkHdr *h);
extern void func_0034F658(SfdChunkHn *s, int a1);
extern int func_0034EB28(void *obj, int a1, int a2, int id, int arg, int len);

__attribute__((section(".text.func_0034E9B0")))
int func_0034E9B0(SfdChunkHn *s, int a1, int max, int *outLen, int *outSt)
{
    SfdChunkIn *in;
    SfdChunkHdr h;
    int err;
    int len;
    int st;
    int id;
    int type;
    int arg;
    Ck34E9B0 ck;

    err = 0;
    *outLen = 0;
    *outSt = 0;
    in = s->in;
    if (func_00368C60(in->obj[0], &h) != 0)
        err = func_0034DD70(s, SFD_ERR_HDR);
    len = h.len;
    id = h.id;
    type = h.type;
    arg = h.arg;
    ck = h.ck;
    if (len < 0)
        return func_0034DD70(s, SFD_ERR_LEN);
    if (len == 0) {
        *outLen = 0;
        *outSt = 1;
        return 0;
    }
    if (max < len) {
        func_0034F658(s, 0);
        return 0;
    }
    if (in->obj[id - SFD_ID_BASE] != 0)
        *outSt = func_0034EB28(in->obj[id - SFD_ID_BASE], in->unk150, in->unk154, id, a1, len);
    else
        *outSt = D_00459680[type](s, arg, a1, len, ck);
    st = *outSt;
    if (st != 0) {
        if (st == 1)
            *outLen = len;
        else
            err = st;
    }
    return err;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0034E9B0);
#endif
