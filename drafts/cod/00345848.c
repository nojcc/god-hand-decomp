/* NON_MATCHING func_00345848 (cygnus-2.96): code shape and block layout match; retail allocates
 * obj/err to s0/s1 and the D_00758B50 high half to a fresh s4, ours swaps obj/err and reuses obj's register. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern int func_003466F8(int);
extern char *func_003565D0(int);
extern int func_003A6C58(char *, const char *, ...);
extern char *strncat(char *, const char *, unsigned int);
extern void MWSFSVM_Error(char *);

extern int D_003EE070;
extern int D_003EE074;
extern int D_00758B08[];
extern int D_00758B48;
extern char D_00758B50[];
extern char D_00457C50[];
extern char D_00457C68[];
extern char D_00457C80[];
extern char D_00457CE0[];
extern char D_00457D38[];
extern char D_00457DA8[];
extern char D_00457E30[];
extern char D_00457E78[];

__attribute__((section(".text.func_00345848")))
void func_00345848(int obj, int err)
{
    int hn;
    char *s = 0;

    if (obj) {
        hn = func_003466F8(obj);
        D_003EE070 = obj;
        D_003EE074 = hn;
    } else {
        D_003EE070 = 0;
        hn = 0;
        D_003EE074 = 0;
    }
    if (err) {
        D_00758B08[D_00758B48] = err;
        if (D_00758B48 < 15)
            D_00758B48++;
    }
    switch (err) {
    case 0xFF000F40:
        func_003A6C58(D_00758B50, D_00457C68, err);
        if (hn)
            s = func_003565D0(hn);
        if (s)
            strncat(D_00758B50, s, 0xE9);
        break;
    case -3:
    case -2:
        func_003A6C58(D_00758B50, D_00457C50, err);
        break;
    case 0xFF000F17:
    case 0xFF000F18:
        func_003A6C58(D_00758B50, D_00457C80, err);
        break;
    case 0xFF000408:
    case 0xFF00040C:
    case 0xFF000F1C:
        func_003A6C58(D_00758B50, D_00457CE0, err);
        break;
    case 0xFF000F15:
        func_003A6C58(D_00758B50, D_00457D38, err);
        break;
    case 0xFF000C04:
        func_003A6C58(D_00758B50, D_00457DA8, err);
        break;
    case 0xFF000F1F:
        func_003A6C58(D_00758B50, D_00457E30, err);
        break;
    default:
        func_003A6C58(D_00758B50, D_00457E78, err);
        break;
    }
    MWSFSVM_Error(D_00758B50);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00345848);
#endif
