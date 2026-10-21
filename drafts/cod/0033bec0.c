/* func_0033BEC0 */
#ifdef NON_MATCHING
#include "godhand/criStm.h"
extern void func_0033BDD8(void);

__attribute__((section(".text.func_0033BEC0")))
extern int D_003E9944;
extern void D_007588B0(void);

void func_0033BEC0(void) {
    D_003E9944 -= 1;
    if (D_003E9944 == 0) {
        func_0033BDD8(D_003E9944);
        func_003A52F0(&D_007588B0, 0, 8);
    }
}

#else
INCLUDE_ASM("nonmatching", func_0033BEC0);
#endif
