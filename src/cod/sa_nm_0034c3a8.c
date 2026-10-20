/* NON_MATCHING func_0034C3A8 (cygnus-2.96, -freorder-blocks dropped; STOP, best 60): push n bytes through the 0x74-byte slot at 0x1310 and fold the count into the running total. Separate early returns give retail's prologue exactly (v0 = 0 hoisted). Only the three exit tests differ: retail loads on into v0, re-zeroes v0 in the beqz delay, then bnez obj jumps forward to the body with b epilogue as the fallthrough; everything after 0x88 is the same code four words later. Untried lead: if (obj != 0) { body; return err; } return 0; */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Obj4C680 Obj4C680;

typedef struct Slot4C3A8 {
    char pad0[4];
    int on;                  /* 0x04 */
    char pad8[0x14 - 0x8];
    Obj4C680 *obj;           /* 0x14 */
    char pad18[0x30 - 0x18];
    int total20;             /* 0x30, addressed as 0x20(slot+0x10) */
    int total24;             /* 0x34 */
} Slot4C3A8;

typedef struct Work4C3A8 {
    char pad0[0x44];
    int unk44;
} Work4C3A8;

extern int Obj0000_Call_Vtbl6_Vtbl8_Field_1_0034C680(Obj4C680 *o, int mode, int n);
extern int func_0034DD70(Work4C3A8 *w, int code);
extern void sfbuf_ResetConti(void *buf);

int func_0034C3A8(Work4C3A8 *w, int idx, int n, int mode)
{
    char *base = (char *)w + 0x1310;
    Slot4C3A8 *s = (Slot4C3A8 *)(base + idx * 0x74);
    char *buf = (char *)s + 0x10;
    Obj4C680 *obj = *(Obj4C680 **)(buf + 4);
    int err = 0;
    int got;

    if (n == 0)
        return 0;
    if (s->on == 0)
        return 0;
    if (obj == 0)
        return 0;
    got = Obj0000_Call_Vtbl6_Vtbl8_Field_1_0034C680(obj, mode, n);
    if (got < n) {
        int left = n - got;
        if (Obj0000_Call_Vtbl6_Vtbl8_Field_1_0034C680(obj, mode, left) < left)
            err = func_0034DD70(w, (int)0xFF00040Bu);
    }
    if (mode == 1) {
        if (idx == mode)
            sfbuf_ResetConti(buf);
        if (*(int *)(buf + 0x24) >= 0)
            *(int *)(buf + 0x24) += n;
    } else if (*(int *)(buf + 0x20) >= 0) {
        *(int *)(buf + 0x20) += n;
    }
    w->unk44 = 1;
    return err;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0034C3A8);
#endif
