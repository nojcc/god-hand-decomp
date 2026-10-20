/* NON_MATCHING func_002C21A0: event flag command setting or clearing one of 64 bits in the global or stage flag words.
 * Global path matches; in the stage path retail gives the set and clear arms different bit registers (v1 / a1, bnel with a duplicated lhu), mine shares v1. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct FlagCmd2C21A0 {
    unsigned char kind;                 /* 0x00 0 = global, 2 = stage */
    unsigned char on;                   /* 0x01 1 = set, else clear */
    unsigned short bit;                 /* 0x02 */
} FlagCmd2C21A0;

typedef struct StageNode2C21A0 {
    char unk00[2];
    unsigned short id;                  /* 0x02 0xFFFF = none */
} StageNode2C21A0;

extern unsigned int D_00747A8C[];
extern unsigned short D_00747A50;
extern int D_003C2F84;
extern char *D_00569B70;

extern StageNode2C21A0 *func_002C5028(int tbl, int id);

#define SET_FLAG(w, n) \
    if ((n) < 0x40) (w)[(unsigned int)(n) >> 5] |= 0x80000000U >> ((n) & 0x1F)
#define CLR_FLAG(w, n) \
    if ((n) < 0x40) (w)[(unsigned int)(n) >> 5] &= ~(0x80000000U >> ((n) & 0x1F))

__attribute__((section(".text.func_002C21A0")))
int func_002C21A0(char *ev)
{
    FlagCmd2C21A0 *cmd = (FlagCmd2C21A0 *)(ev + 0x5C);
    StageNode2C21A0 *node;
    int n;
    int m;
    unsigned int *w;

    switch (cmd->kind) {
    case 0:
        n = cmd->bit;
        if (cmd->on == 1) {
            SET_FLAG(D_00747A8C, n);
        } else {
            CLR_FLAG(D_00747A8C, n);
        }
        break;
    case 1:
        break;
    case 2:
        node = func_002C5028(D_003C2F84, D_00747A50);
        if (node == 0)
            break;
        if (node->id == 0xFFFF)
            break;
        if (cmd->on == 1) {
            m = cmd->bit;
            if (m < 0x40) {
                w = (unsigned int *)(D_00569B70 + 0x14);
                w[(unsigned int)m >> 5] |= 0x80000000U >> (m & 0x1F);
            }
        } else {
            m = cmd->bit;
            if (m < 0x40) {
                w = (unsigned int *)(D_00569B70 + 0x14);
                w[(unsigned int)m >> 5] &= ~(0x80000000U >> (m & 0x1F));
            }
        }
        break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002C21A0);
#endif
