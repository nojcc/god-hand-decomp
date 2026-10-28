/* NON_MATCHING func_001AA510 (sn-2.95.3-136, 13 insns differ in the hit-sound call: retail stores the stack arg first and tests the kind with li 5 / slt on the unsigned byte, this source reloads it signed) */
#include "include_asm.h"
#include "godhand/cSnd.h"

#ifdef NON_MATCHING
/* func_001AA510, enemy damage-phase update: on a confirmed hit either kill (guard at zero) or flag the
 * hit and play the hit sound (with the attacker's sound id for hit kinds above 5); then run the current phase
 * handler from a local copy of the phase table and sync the motion. */
typedef struct HitPhaseEnt {
    short adjust;                       /* 0x00 */
    short index;                        /* 0x02 */
    short tableOff;                     /* 0x04 */
    short unk06;
} HitPhaseEnt;

typedef struct HitPhaseTable {
    HitPhaseEnt e[5];
} HitPhaseTable;

extern HitPhaseTable D_00427C68;
extern int cOmBase_checkDamage(void *, void *);
extern void SetField_9E0_1AA500(char *self);
extern void func_001B7EE0(void *, float);

__attribute__((section(".text.func_001AA510")))
void func_001AA510(char *s0)
{
    HitPhaseTable tbl;
    char *e;
    int i8;
    int f0;
    int type; int arg; void (*fp)(int); long entry;
    int kind;

    if (cOmBase_checkDamage(s0, *(void **)(s0 + 0x604)) == 1) {
        if (*(short *)(s0 + 0x54A) <= 0) {
            *(unsigned char *)(s0 + 0x2F4) = 1;
            *(unsigned int *)(s0 + 0x5B0) |= 1;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            return;
        }
        SetField_9E0_1AA500(s0);
        kind = *(unsigned char *)(s0 + 0x2B4);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x8C, s0, 0, (signed char)kind > 5 ? *(int *)(*(char **)(s0 + 0x278) + 0x14) : 0, 0, 0, kind);
    }

    tbl = D_00427C68;
    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = (char *)&tbl + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (void (*)(int))(int)(entry >> 32);
    } else {
        fp = *(void (**)(int))((char *)&tbl + i8 + 4);
    }
    f0 = tbl.e[*(unsigned char *)(s0 + 0x2F5)].adjust;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_001B7EE0(s0, 3.0f);
}
#else
INCLUDE_ASM("asm/nonmatching", func_001AA510);
#endif
