/* func_003BAFD0 (ee-2.9-991111): the C matches word for word, but carving it out drops the relocations of the
 * pointer table D_003BAFE4 that follows it in .text (reseed 44 linked zeros there), so it stays in asm. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void *__deregister_frame_info(void *begin);
extern char D_003FC9B4[];

__attribute__((section(".text.func_003BAFD0")))
void func_003BAFD0(void)
{
    __deregister_frame_info(D_003FC9B4);
}
#else
INCLUDE_ASM("asm/nonmatching", func_003BAFD0);
#endif
