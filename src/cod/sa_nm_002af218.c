/* NON_MATCHING func_002AF218 (NEAR-MISS): sn; switch on code & 0xFF00 with unsigned short return (andi 0xFFFE/0xFFFC from zero-extend + known low bits). Compare tree matches; retail keeps the explicit-zero case block after case 0xA900 while ours merges it with the post-switch return 0; 720 case-order permutations, default/break/ret-accumulator forms tried, best 27 */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Msg2AF218 {
    char pad0[0xBDC];
    int tbl[4];
    char padBEC[2];
    unsigned short num;
} Msg2AF218;

extern Msg2AF218 *D_003C23A4;
extern unsigned short D_003C23A8;
extern int func_002AF348(int);
extern int func_002AF380(int);

unsigned short func_002AF218(unsigned short *text)
{
    unsigned short c = *text;

    if (c >> 15) {
        switch (c & 0xFF00) {
        case 0xA400:
            return text[1] * 900;
        case 0xA900:
            return D_003C23A8 * 900;
        case 0x8000:
        case 0xA000:
        case 0xA100:
        case 0xA300:
        case 0xA500:
            return 0;
        case 0x8700:
            D_003C23A8 = text[1];
            return 0;
        case 0x9400:
            return func_002AF380(D_003C23A4->num) * 30;
        case 0x9300:
            return func_002AF348(D_003C23A4->tbl[text[1]]) * 30;
        }
        return 0;
    }
    return 30;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002AF218);
#endif
