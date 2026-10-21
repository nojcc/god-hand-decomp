/* NON_MATCHING func_0033ABD0: matches except (1) retail uses bnel at the used!=0 test, with sltiu id<4 in the slot, while ours uses bne; (2) retail's tail shares one sltiu for both modes (bnel xor / slt -> sltiu), while ours emits xori+sltiu with a separate branch.
* A shared t-variable form if-converts to movz. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int unk0;
    int val;
} DtxCond;

typedef struct {
    char unk0[8];
    DtxCond cond;
} DtxSlot;

typedef struct {
    char unk0[4];
    signed char used;
    signed char mode;
    char unk6[0x12];
    DtxSlot *slot[4];
    void (*cb)(int obj, int err);
    int cbobj;
} DtxObj;

extern char D_00455D08[];
extern char D_00455BD8[];
extern char D_00455D18[];
extern char D_00455C08[];
extern void func_0033A048(char *a, char *b);

int func_0033ABD0(DtxObj *obj, unsigned int id, int ref, int *out)
{
    DtxSlot *s;
    DtxCond c;
    int t;

    if (obj == 0) {
        func_0033A048(D_00455D08, D_00455BD8);
        return 0;
    }
    if (obj->used == 0) {
        func_0033A048(D_00455D18, D_00455C08);
        return 0;
    }
    *out = 0;
    if (id >= 4) {
        if (obj->cb != 0) {
            obj->cb(obj->cbobj, -3);
        }
        return 0;
    }
    s = obj->slot[id];
    if (s == 0) {
        return 0;
    }
    c = s->cond;
    *out = c.val;
    if (obj->mode == 1) {
        return !(c.val < ref);
    }
    return !(c.val ^ ref);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0033ABD0);
#endif
