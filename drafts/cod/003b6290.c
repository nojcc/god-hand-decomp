/* NON_MATCHING sceSifRebootIop (ee-2.9-991111): retail strlen loop carries R5900 short-loop 3-nop pad that our ee-as path omits; also name-11 hoist folded */
#include "godhand/eeKernel.h"
#include "include_asm.h"

#ifdef NON_MATCHING
extern char D_00460340[];
extern char D_00460350[];
extern void sceSifInitRpc(unsigned int mode);
extern void sceSifExitRpc(void);
extern int sceSifResetIop(const char *path, int a1);

int sceSifRebootIop(const char *name)
{
    char buf[80];
    const char *p = name;
    const char *q = D_00460340;
    char *d;

    while (*p) p++;
    if ((unsigned int)(p - (name - 11)) > 80) {
        func_003B1F28(D_00460350, name);
        return 0;
    }
    sceSifInitRpc(0);
    sceSifExitRpc();
    d = buf;
    while (*q) *d++ = *q++;
    while (*name) *d++ = *name++;
    *d = 0;
    return sceSifResetIop(buf, 0);
}
#else
INCLUDE_ASM("asm/nonmatching", sceSifRebootIop);
#endif
