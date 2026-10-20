/* NON_MATCHING func_002E0DE8: sn;
 * 14 diffs: retail's div-by-zero trap tests a fresh constant 8 (v0) while div uses a long-lived s4=8, quotient reuses room's v1; ours tests the divisor reg directly and swaps s3/s4. int/short/register/inline-helper divisor variants no change */
#include "include_asm.h"

#ifdef NON_MATCHING
extern char D_0061B298[];
extern int D_003C1180;
extern int D_003C118C;
extern int func_003A7AE8(char *buf, const char *fmt, char *args);
extern void func_002E0F18(char *buf, int, int, int, int);

void func_002E0DE8(int x, int y, int color, const char *fmt, ...)
{
    int w = 8;
    short py = y * 8;
    short px = x * 8;
    int n, room;

    if (py < -8 || py > D_003C118C * 2 + 8 || px >= D_003C1180)
        return;
    n = func_003A7AE8(D_0061B298, fmt, (char *)__builtin_next_arg(fmt) - 0x20);
    if (n + 1 >= 0x200) {
        *(int *)0x11111111 = 0;
    }
    room = D_003C1180 - px;
    if (room < n * 8) {
        room /= w;
        if (room < 0)
            return;
        D_0061B298[room] = 0;
    }
    func_002E0F18(D_0061B298, px, py, color, 0);
}
#else
INCLUDE_ASM("asm/nonmatching", func_002E0DE8);
#endif
