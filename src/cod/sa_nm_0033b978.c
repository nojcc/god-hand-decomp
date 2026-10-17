/* NON_MATCHING func_0033B978 (cygnus-2.96, as=sn): 36 words vs 37: retail copies a0 into a2 at entry (so the error paths can load the message into a0) and builds the entry address three ways (a0 = off + base, a1 = base + off, v0 = a1 copy); this keeps a0 as the index and shares one address. Byte-offset form gets the separate lui/addiu base. Tried: IVec3 [8][6] table, mixed indexed/pointer stores, byte offsets. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct { int x, y, z; } IVec3;

extern void func_0033B790(char *msg);
extern IVec3 D_00758620[8][6];
extern char D_00455F28[];
extern char D_00455F48[];

void func_0033B978(unsigned int a0, unsigned int a1)
{
    int off;
    char *v;

    if (a1 >= 6) {
        func_0033B790(D_00455F28);
        return;
    }
    if (a0 >= 8) {
        func_0033B790(D_00455F48);
        return;
    }
    off = a1 * 12 + a0 * 0x48;
    v = (char *)D_00758620 + off;
    *(int *)(off + (char *)D_00758620) = 0;
    *(int *)(v + 4) = 0;
    *(int *)(v + 8) = 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0033B978);
#endif
