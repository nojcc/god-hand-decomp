/* cygnus-2.96 */
#include "godhand/sfxlib.h"

/* View of SfxCtx with the two decoder handles; the 0x30 handle is the
 * pointer func_0036CBC0 takes. */
typedef struct SfxOpenView {
    char pad0[0x24];
    int dec24;                  /* 0x24 */
    char pad28[0x8];
    int *dec30;                 /* 0x30 */
} SfxOpenView;

extern unsigned char D_003EE338[];
extern char D_00459FE0[];
extern char D_0045A010[];
extern char D_0045A030[];
extern void *func_0035FA88(void);
extern int func_0035FB78(int ver, int a1, int a2);
extern void func_0035FAD8(void *w, int work, int size);
extern int func_0035FEF0(void);
extern int func_0036CAB0(void);
extern void func_0035FB88(int a0);

/* Open an SFX handle: take a free slot, check the version and create its two decoders. */
__attribute__((section(".text.func_0035F970")))
SfxOpenView *func_0035F970(int work, int ver, int a2, int a3)
{
    SfxOpenView *s;
    int h;
    int h2;

    s = func_0035FA88();
    if (s == 0)
        return 0;
    if (func_0035FB78(ver, a2, a3) != 1) {
        SFXLIB_Error(0, 0, D_00459FE0);
        return 0;
    }
    func_0035FAD8(s, work, ver);
    h = func_0035FEF0();
    if (h == 0) {
        SFXLIB_Error(0, 0, D_0045A010);
        func_0035FB88((int)s);
        return 0;
    }
    s->dec24 = h;
    h2 = func_0036CAB0();
    if (h2 == 0) {
        SFXLIB_Error(0, 0, D_0045A030);
        func_0035FB88((int)s);
        return 0;
    }
    (*(int *)D_003EE338)++;
    s->dec30 = (int *)h2;
    return s;
}
