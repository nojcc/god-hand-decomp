/* NON_MATCHING func_0033D870: the first test (mode == 0) is bne in ours and bnel in retail (slot loads 10 for the next compare); prototype, mode type, !mode, nesting and flag variants keep bne */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[0x98];
    short mode;
    char pad9A[0xFC - 0x9A];
    int unkFC;
} AdxbModeObj;

extern void func_0033D720(int a0);
extern void Tramp_003E9D30_0033C4C0(void);
extern void func_0033DBD8(ADXB adxb);
extern void func_00341458(AdxbModeObj *);
extern void func_00341EC0(int a0);
extern void func_0033E5C0(int a0);
extern void func_0033C2C0(AdxbModeObj *);
extern void Obj0000_Call_FnFC_Field_100_94_90_Scaled(AdxbModeObj *);

void func_0033D870(AdxbModeObj *o)
{
    short mode = o->mode;

    if (mode == 0) {
        func_0033D720();
    } else if (mode == 10) {
        Tramp_003E9D30_0033C4C0();
    } else if (mode == 2) {
        func_0033DBD8();
    } else if (mode == 3) {
        func_00341458(o);
    } else if (mode == 4) {
        func_00341EC0();
    } else if (mode == 1) {
        func_0033E5C0();
    } else if (mode == 15) {
        func_0033C2C0(o);
    }
    if (o->unkFC != 0) {
        Obj0000_Call_FnFC_Field_100_94_90_Scaled(o);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0033D870);
#endif
