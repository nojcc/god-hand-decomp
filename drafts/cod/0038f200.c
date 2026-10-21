/* NON_MATCHING func_0038F200 (ee-2.9-991111): frame and saved regs match, but retail reads D_003FA62C after the field stores and walks the dest pointer itself in the 0x60-byte copy loop. */
#include "include_asm.h"
#include "godhand/criStm.h"

#ifdef NON_MATCHING
/* func_0038F200: libio standard file setup: build the stdin/stdout/stderr
 * FILE records (chained 0 <- 1 <- 2) bound to the reent's std streams. */
typedef struct File38F200 {
    int flags;                          /* 0x00 */
    char pad04[0x34 - 0x04];
    struct File38F200 *chain;           /* 0x34 */
    int fileno;                         /* 0x38 */
    char pad3C[0x50 - 0x3C];
    void *jumps;                        /* 0x50 */
    char pad54[0x58 - 0x54];
    int stream;                         /* 0x58 */
    char pad5C[0x60 - 0x5C];
} __attribute__((aligned(8))) File38F200;

extern File38F200 D_003F4F80;
extern File38F200 D_003F4FD8;
extern File38F200 D_003F5038;
extern File38F200 D_003F5098;
extern char D_0045DAE8[];
extern int *D_003FA62C;

__attribute__((section(".text.func_0038F200")))
void func_0038F200(void)
{
    File38F200 f;
    File38F200 *d;

    func_003A52F0(&f, 0, sizeof(f));
    f.flags = 0xFBAD208A;
    f.chain = &D_003F4F80;
    f.jumps = D_0045DAE8;
    f.stream = D_003FA62C[1];
    D_003F4FD8 = f;
    d = &D_003F5038;
    func_003A52F0(&f, 0, sizeof(f));
    f.chain = &D_003F4FD8;
    f.fileno = 1;
    f.flags = 0xFBAD2086;
    f.jumps = D_0045DAE8;
    f.stream = D_003FA62C[2];
    *d = f;
    d = &D_003F5098;
    func_003A52F0(&f, 0, sizeof(f));
    f.fileno = 2;
    f.flags = 0xFBAD2086;
    f.chain = &D_003F5038;
    f.jumps = D_0045DAE8;
    f.stream = D_003FA62C[3];
    *d = f;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0038F200);
#endif
