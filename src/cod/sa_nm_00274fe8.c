/* NON_MATCHING func_00274FE8 (sn-2.95.3-136, as sn; PARK, 103 diffs): the logic is complete, but cross-jumping differs. Retail keeps two unmerged copies of the (2, 2) phase stores in the dying branch and routes every other phase set through one register tail; ours merges the copies and lays the 0x100000 case out as a taken branch. */
#include "include_asm.h"

#ifdef NON_MATCHING
/* func_00274FE8: enemy think: pick the next phase (0x2F4/0x2F5) from the hit points, the current
 * action id at 0x564 and the player distance at 0x618. */
extern int func_0025FE30(char *self, int flag, int a2);
extern int cEm00_startHitUnitAim(char *self);
extern int func_00274150(char *self);
extern int func_0026F1D8(char *self);
extern int irand(void);

static inline void SetPhase274FE8(char *p, int phase, int sub)
{
    *(unsigned char *)(p + 0x2F4) = phase;
    *(unsigned char *)(p + 0x2F5) = sub;
    *(unsigned char *)(p + 0x2F7) = 0;
    *(unsigned char *)(p + 0x2F6) = 0;
}

__attribute__((section(".text.func_00274FE8")))
void func_00274FE8(char *p)
{
    if (*(short *)(p + 0x54A) <= 0) {
        int sub;

        if (*(unsigned int *)(p + 0x16D4) & 0x100000) {
            SetPhase274FE8(p, 2, 2);
            return;
        }
        if (*(unsigned int *)(p + 0x1644) & 0x800000) {
            sub = 3;
        } else {
            if (func_0025FE30(p, 0x1000000, 0)) {
                SetPhase274FE8(p, 2, 2);
                return;
            }
            sub = 1;
        }
        SetPhase274FE8(p, 2, sub);
        return;
    }
    if (cEm00_startHitUnitAim(p))
        return;
    if (func_00274150(p) == 0 && !(0.0f < *(float *)(p + 0x1734))) {
        switch (*(int *)(p + 0x564)) {
        case 0x220:
        case 0x221:
        case 0x222:
            if (func_0026F1D8(p))
                SetPhase274FE8(p, 1, 0xD);
            else
                SetPhase274FE8(p, 1, 0xE);
            return;
        case 0x223:
        case 0x260:
        case 0x264:
        case 0x265:
        case 0x26A:
            SetPhase274FE8(p, 1, 0xD);
            return;
        }
        if (*(unsigned char *)(p + 0x17C1) == 0 || func_0026F1D8(p)) {
            SetPhase274FE8(p, 1, 0xD);
            return;
        }
        if (!(*(float *)(p + 0x618) < 6.25f)) {
            SetPhase274FE8(p, 1, 0xD);
            return;
        }
        if ((irand() & 3) == 0) {
            SetPhase274FE8(p, 1, 0xD);
            return;
        }
    }
    *(unsigned char *)(p + 0x2F4) = 1;
    *(float *)(p + 0x54C) = 5.0f;
    *(unsigned char *)(p + 0x2F5) = 0x14;
    *(unsigned char *)(p + 0x2F6) = 0;
    *(unsigned char *)(p + 0x2F7) = 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00274FE8);
#endif
