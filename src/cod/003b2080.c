/* NON_MATCHING func_003B2080: int buf[32][4] form.
* Only the addiu %lo(D_00460040) and the lw %lo(D_0077E520) are swapped.
* The DmaEnt-struct form sinks the data store (17); the order of the source stores makes no difference. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    void *data;
    int addr;
    int size;
    int mode;
} DmaEnt;

extern char D_00460040[];
extern int D_0077E520;
extern void *func_003A5148(void *dst, const void *src, int n);
extern int SifSetDma(DmaEnt *list, int n);
extern int isceSifSetDma(DmaEnt *list, int n);

int func_003B2080(DmaEnt *list, int n, int intr)
{
    int buf[32][4];

    if (n < 32) {
        func_003A5148(buf, list, n * 16);
        buf[n][0] = (int)D_00460040;
        buf[n][1] = D_0077E520;
        buf[n][2] = 0x10;
        buf[n][3] = 0x44;
        n++;
        if (intr == 0)
            return SifSetDma((DmaEnt *)buf, n);
        return isceSifSetDma((DmaEnt *)buf, n);
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003B2080);
#endif
