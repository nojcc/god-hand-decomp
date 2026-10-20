/* func_00331070 (SRD_Destroy): retail fills the third stat test's delay slot with the
 * lui of the warning string; ours leaves a nop (a0 treated as live at the reset call).
* func_00331110 (SRD_ReqRdCd): 3 insns - stat/devtype stores scheduled after d_lsn. */
#include "include_asm.h"

#ifdef NON_MATCHING

typedef signed char Sint8;
typedef char Char8;
typedef int Sint32;
typedef unsigned int Uint32;
typedef unsigned long long Uint64;
typedef Sint32 Bool;
typedef unsigned char u_char;

typedef struct {
    u_char trycount;
    u_char spindlctrl;
    u_char datapattern;
    u_char pad;
} sceCdRMode;

typedef struct srd_obj {
    Sint8 used;
    Sint8 devtype;
    Sint8 stat;
    Char8 rsv;
    Sint32 break_flg;
    Uint32 d_lsn;
    Uint32 d_sct;
    void *d_buf;
    sceCdRMode d_mode;
    void *h_buf;
    Uint64 h_byte;
    Uint64 h_skpos;
    int h_fd;
    int err_code;
} SRD_OBJ, *SRD;

extern int Forward33B568_33B688(void);
extern int Forward33B5C8_33B6B8(void);
extern int func_003B1F28(const char *fmt, ...);
extern void func_00330FB8(void);

extern SRD_OBJ D_003D8410;              /* srd_obj */
extern Sint32 D_003D8474;      /* destroy count */
extern char D_00453E30[];               /* "SRD: SRD_Destroy, invalidate srd handle..." */
extern char D_00453E70[];

__attribute__((section(".text.func_00331070")))
void func_00331070(SRD srd)
{
    Forward33B568_33B688();
    if (srd != &D_003D8410) {
        func_003B1F28(D_00453E30, srd, &D_003D8410);
    } else {
        if (srd->stat != 0 && srd->stat != 3 && srd->stat != 9) {
            func_003B1F28(D_00453E70);
        }
        func_00330FB8();
        D_003D8410.used = 0;
        D_003D8474++;
    }
    Forward33B5C8_33B6B8();
}

#else

INCLUDE_ASM("asm/nonmatching", func_00331070);

#endif
