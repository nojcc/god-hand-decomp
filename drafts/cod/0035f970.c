/* NON_MATCHING func_0035F970 (cygnus-2.96: ): second-half register choice (a3/t0) and hoisted error-arg setup differ */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct SfxHn {
    char pad0[0x24];
    int h24;
    char pad28[0x30 - 0x28];
    int h30;
} SfxHn;

extern char D_00459FE0[];
extern char D_0045A010[];
extern char D_0045A030[];
extern int D_003EE338;
extern SfxHn *func_0035FA88(void);
extern int func_0035FB78(int a);
extern void func_0035FAD8(SfxHn *s, int a, int b);
extern int func_0035FEF0(void);
extern int func_0036CAB0(void);
extern void func_0035FB88(SfxHn *s);
extern void SFXLIB_Error(void *a, void *b, const char *msg);

SfxHn *func_0035F970(int a0, int a1, int a2, int a3)
{
    SfxHn *s;
    int h;
    char *msg;

    s = func_0035FA88();
    if (s == 0)
        return 0;
    if (func_0035FB78(a1, a2, a3) != 1) {
        SFXLIB_Error(0, 0, D_00459FE0);
        return 0;
    }
    func_0035FAD8(s, a0, a1);
    h = func_0035FEF0();
    msg = D_0045A010;
    if (h == 0 || (s->h24 = h, h = func_0036CAB0(), msg = D_0045A030, h == 0)) {
        SFXLIB_Error(0, 0, msg);
        func_0035FB88(s);
        return 0;
    }
    s->h30 = h;
    D_003EE338++;
    return s;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0035F970);
#endif
