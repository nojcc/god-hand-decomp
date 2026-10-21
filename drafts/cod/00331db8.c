/* NON_MATCHING func_00331DB8: mode==1 branch: ours const-props 1 into a3 and keeps per-branch arg setup; retail loads mode straight into a3, hoists a0/(int)b/a2 above the branch and overrides a1 in the jal slot. if/else, local mode, switch all score 31. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern int D_003D8480;
extern char D_004540D0[];
extern char D_004540F0[];
extern void func_00331D40(void);
extern void func_00331D78(void);
extern int func_003B56A0(int a, long b, int c, int mode);
extern int func_003B4628(int a, int b, int c, int mode);
extern void func_003B1F28(char *fmt, int err);

int func_00331DB8(int a, long b, int c)
{
    int ret;
    int mode;

    func_00331D40();
    mode = D_003D8480;
    switch (mode) {
    case 1:
        ret = func_003B56A0(a, b, c, mode);
        if (ret < 0)
            func_003B1F28(D_004540D0, ret);
        break;
    default:
        ret = func_003B4628(a, b, c, mode);
        if (ret < 0)
            func_003B1F28(D_004540F0, ret);
        break;
    }
    func_00331D78();
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00331DB8);
#endif
