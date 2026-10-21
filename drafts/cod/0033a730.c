/* NON_MATCHING func_0033A730: take a chunk of at least len bytes from free list id
an exact fit is unlinked and its node goes to the spare list, a larger one is split in mode 1.
* One insn: the used test is bnel here, retail bnez with the sltiu id<4 in the slot (the reverse of func_0033ABD0). */
#include "godhand/criSj.h"
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct DtxNode {
    struct DtxNode *next;
    int unk4;
    SjChunk ck;
} DtxNode;

typedef struct {
    char unk0[4];
    signed char used;
    signed char mode;
    char unk6[0xE];
    DtxNode *spare;              /* 0x14 */
    DtxNode *list[4];            /* 0x18 */
    void (*cb)(int obj, int err);   /* 0x28 */
    int cbobj;                      /* 0x2C */
} DtxPool;

extern char D_00455CA8[];
extern char D_00455BD8[];
extern char D_00455CB8[];
extern char D_00455C08[];
extern void func_0033A048(char *a, char *b);
extern void func_0033ACA0(SjChunk *ck, int len, SjChunk *head, SjChunk *tail);

void func_0033A730(DtxPool *obj, int id, int len, SjChunk *out)
{
    DtxNode *n;
    SjChunk *src;
    SjChunk ck;
    SjChunk rest;

    if (obj == 0) {
        func_0033A048(D_00455CA8, D_00455BD8);
        return;
    }
    if (obj->used == 0) {
        func_0033A048(D_00455CB8, D_00455C08);
        return;
    }
    if ((unsigned int)id >= 4) {
        if (obj->cb != 0)
            obj->cb(obj->cbobj, -3);
    } else {
        n = obj->list[id];
        if (n != 0) {
            src = &n->ck;
            ck = *src;
            if (len >= ck.len) {
                *out = ck;
                obj->list[id] = n->next;
                n->next = obj->spare;
                obj->spare = n;
                return;
            }
            if (obj->mode == 1) {
                func_0033ACA0(&ck, len, &ck, &rest);
                *out = ck;
                *src = rest;
                return;
            }
        }
    }
    out->data = 0;
    out->len = 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0033A730);
#endif
