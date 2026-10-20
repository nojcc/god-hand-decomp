/* NON_MATCHING func_003B3F50 (ee-2.9-991111;
 * PARK, 19 diffs): code shape matches; retail computes the
 * D_00781740 address into s0/s1 before sceSifInitRpc (this swaps s0/s1), and the split asm pairs the delay loop's
 * lui 0x10 / addiu -1 as %hi/%lo of the auto symbol D_FFFFF, which no C source reproduces. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct FsCd3B3F50 {
    char pad00[0x24];
    void *server;                       /* 0x24 */
} FsCd3B3F50;

typedef struct FsFd3B3F50 {
    int f0;
    int used;                           /* 0x04 */
    int f8;
    int fC;
} FsFd3B3F50;

typedef struct FsPoff3B3F50 {
    int f0;
    int f4;
} FsPoff3B3F50;

typedef struct FsBuf3B3F50 {
    char *start;
    char *end;
} FsBuf3B3F50;

extern FsPoff3B3F50 D_00781740;
extern char D_00781700[];
extern FsCd3B3F50 D_007816C0;
extern FsFd3B3F50 D_007814C0[32];
extern int D_003FAEE8;
extern FsBuf3B3F50 D_0077FF80;
extern char D_00780C40[];
extern char D_00780C00[];
extern char D_007816E8[];
extern int D_003FAEDC;
extern int D_003FAEE0;
extern void _sceFs_Rcv_Intr(void);
extern void _sceFs_Poff_Intr(void);
extern void sceSifInitRpc(unsigned int mode);
extern int func_003B63A0(void);
extern int EIntr(void);
extern void func_003B2488(unsigned int cmd, void (*fn)(void), void *data);
extern int func_003B2F48(FsCd3B3F50 *cd, unsigned int num, int mode);
extern void func_003B3858(void);
extern int WaitSema(int sema);
extern int SignalSema(int sema);
extern int func_003B3958(FsCd3B3F50 *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize,
                         void *end, void *param, int pad);
extern void *memcpy(void *dst, const void *src, unsigned int n);

__attribute__((section(".text.func_003B3F50")))
int func_003B3F50(void)
{
    FsFd3B3F50 *fd;
    int oldei;
    int ver;
    int i;

    sceSifInitRpc(0);
    D_00781740.f0 = 0;
    D_00781740.f4 = 0;
    oldei = func_003B63A0();
    func_003B2488(0x80000011, _sceFs_Rcv_Intr, D_00781700);
    func_003B2488(0x80000013, _sceFs_Poff_Intr, &D_00781740);
    if (oldei)
        EIntr();
    for (;;) {
        if (func_003B2F48(&D_007816C0, 0x80000001, 0) < 0)
            return -22;
        if (D_007816C0.server != 0)
            break;
        for (i = 0x100000; i != -1; i--)
            ;
    }
    func_003B3858();
    WaitSema(D_003FAEE8);
    for (fd = D_007814C0; fd < D_007814C0 + 32; fd++)
        fd->used = 0;
    SignalSema(D_003FAEE8);
    D_0077FF80.start = D_00780C40;
    D_0077FF80.end = D_00780C40 + 0x440;
    if (func_003B3958(&D_007816C0, 0xFF, 0, &D_0077FF80, 8, D_00780C00, 8, 0, 0, 0) < 0)
        return 0xFFFEFFFF;
    memcpy(D_007816E8, (void *)((unsigned int)D_00780C00 | 0x20000000), 4);
    memcpy(&ver, (void *)((unsigned int)(D_00780C00 + 4) | 0x20000000), 4);
    D_003FAEDC = 1;
    D_003FAEE0 = ver == 2;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003B3F50);
#endif
