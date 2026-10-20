/* NON_MATCHING func_00386DE0 (sn-2.95.3-136;
 * PARK 65): fetch request idx of bank into out (0x60-byte copy), then fill its 0x18-byte sub-record from the bank's sub table and stamp bank/idx; reports and returns -1 for a bad index or a disabled request.
 * Logic matches; retail assigns bank=a3/idx=t0 and copies the request pointer into v1 for the block move (src v1, dst a0), ours swaps both pairs. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Sub386DE0 {
    int w[6];
} Sub386DE0;

typedef struct Req386DE0 {
    short bank;                         /* 0x00 */
    short idx;                          /* 0x02 */
    short sub;                          /* 0x04 */
    unsigned char kind;                 /* 0x06 */
    char pad7[7];
    unsigned short flags;               /* 0x0E */
    char pad10[0x30];
    Sub386DE0 subdata;                  /* 0x40 */
    char pad58[8];
} Req386DE0;

typedef struct Bank386DE0 {
    short count;                        /* 0x00 */
    char pad2[2];
    Req386DE0 *reqs;                    /* 0x04 */
    char pad8[4];
    Sub386DE0 *subs;                    /* 0x0C */
    char pad10[0x10];
} Bank386DE0;

extern Bank386DE0 D_0076E510[];

extern void func_00386F38(short bank, short idx);

int func_00386DE0(short bank, short idx, Req386DE0 *out)
{
    Bank386DE0 *b = &D_0076E510[bank];
    Req386DE0 *r;

    if (idx >= b->count || ((r = &b->reqs[idx])->flags & 0x8000)) {
        func_00386F38(bank, idx);
        return -1;
    }
    *out = *r;
    out->subdata = b->subs[out->sub];
    out->idx = idx;
    out->bank = bank;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00386DE0);
#endif
