/* NON_MATCHING func_0032D868: null and range checks tail-call the error.
* Prologue matches, including the dead load of D_00451AC0.
* Retail uses beql on the null test so the message lui sits in the delay and is repeated on the fallthrough; we emit beq and one lui, and the rest of the function shifts by those two words. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct AdxtRangeObj {
    char pad0;
    unsigned char unk1;
    char pad2[2];
    int unk4;
    char pad8[0x8C - 0x8];
    int unk8C;
    int unk90;
    char pad94[0x1B2 - 0x94];
    unsigned char unk1B2;
    char pad1B3[0x1CC - 0x1B3];
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
} AdxtRangeObj;

extern char D_00452A20[];
extern char D_00452A48[];
extern char D_00452A78[];
extern void Obj33F8_Tramp_0033F130_FCB0(char *msg);
extern void func_0032DBA0(MwPly *);
extern void Obj33F8_Tramp_0033B658_FC70(void);
extern void Obj33F8_Tramp_0033B670_FC88(void);
extern char *func_003A57C4(char *d, const char *s);
extern void func_0032F4B0(int, int);

void func_0032D868(AdxtRangeObj *o, char *name, int a2, int a3, int a4)
{
    if (o == 0 || name == 0) {
        Obj33F8_Tramp_0033F130_FCB0(D_00452A20);
        return;
    }
    if (a3 < 0) {
        Obj33F8_Tramp_0033F130_FCB0(D_00452A48);
        return;
    }
    if (a4 <= 0) {
        Obj33F8_Tramp_0033F130_FCB0(D_00452A78);
        return;
    }
    func_0032DBA0();
    Obj33F8_Tramp_0033B658_FC70();
    func_003A57C4((char *)o->unk1CC, name);
    o->unk1D0 = o->unk1CC;
    o->unk1D4 = a2;
    o->unk1D8 = a3;
    o->unk1DC = a4;
    o->unk90 = o->unk8C;
    func_0032F4B0(o->unk4, o->unk8C);
    o->unk1E0 = 0;
    o->unk1 = 1;
    o->unk1B2 = 1;
    Obj33F8_Tramp_0033B670_FC88();
}
#else
INCLUDE_ASM("asm/nonmatching", func_0032D868);
#endif
