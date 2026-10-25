/* NON_MATCHING func_00320AE8 (ee-2.9-991111): tree walk with 0x2F0 node copies; retail spills the save/flag locals and keeps b/first/out in s7/s6/fp, ours spills b/first; retail also keeps a dead lb/li 2 tail */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Node {
    int f0;
    unsigned int *p4;
    long f8;
    char pad10[0x28A];
    unsigned short u29A;
    signed char c29C[0x4F];
    char pad2EB[5];
} Node;

typedef struct {
    int result;
    int f4;
    int f8;
    int fC;
} TreeCtx;

extern Node *func_00320A50(int key, Node *cur, Node *prev);
extern int func_00320800(int a, unsigned int *p, int b, int flag, int *found);
extern int func_00320728(int key, unsigned int *p);
extern long *SlotTable_resolveValue(int idx, Node *n, Node *prev);
extern void func_003209D0(int i, Node *n, Node *out);
extern void func_00320AE0(void);
extern void func_00320280(void);

int func_00320AE8(TreeCtx *ctx, int key0, Node *out, Node **pp)
{
    Node tmp;
    Node save;
    int found;
    int saveRet;
    int saveKey;
    int haveSave;
    int haveSaveOk;
    Node *cur;
    Node *prev;
    Node *last;
    int key;
    int ret;
    int first;
    int b;
    int term;
    int i;

    ret = 0;
    prev = &tmp;
    key = key0;
    b = ctx->f8;
    first = ctx->fC != 0;
    cur = *pp;
    haveSaveOk = 0;
    haveSave = 0;
    found = 0;
    goto next;
body:
    {
        term = cur->p4 ? *cur->p4 == 0xFFFFFFFE : 0;
        if (first) {
            first = 0;
            ret = func_00320800(ctx->fC, cur->p4, b, 1, &found);
            ctx->fC = 0;
        } else if (term) {
            ret = func_00320800(key, cur->p4, b, 0, &found);
        } else {
            ret = func_00320728(key, cur->p4);
        }
        if (ret != 0) {
            if (found == 0) {
                haveSaveOk = 0;
                goto done;
            }
            if (haveSave == 0) {
                save = *cur;
                saveKey = key;
                saveRet = ret;
                haveSave = 1;
                haveSaveOk = 1;
            }
        }
        { long t = *SlotTable_resolveValue(cur->u29A, cur, last); key = (int)t - 1; }
    }
next:
    last = cur;
    cur = func_00320A50(key, last, prev);
    prev = last;
    if (cur != 0)
        goto body;
done:
    if (haveSave) {
        cur = &save;
        ret = saveRet;
        key = saveKey;
        if (haveSaveOk)
            func_00320AE0();
    }
    if (ret == 0)
        func_00320280();
    ctx->result = ret;
    if (key == key0) {
        cur = out;
    } else {
        int stop = key;

        *cur = *out;
        key = key0;
        if (key0 != stop) {
            last = cur;
            do {
                cur = func_00320A50(key, last, prev);
                prev = last;
                for (i = 0; i < 0x4F; i++) {
                    if (i != cur->u29A && cur->c29C[i] != 0)
                        func_003209D0(i, cur, out);
                }
                { long t = *SlotTable_resolveValue(cur->u29A, cur, last); key = (int)t - 1; }
                last = cur;
            } while (key != stop);
        }
        if (cur->c29C[cur->u29A] == 2) {
        }
    }
    *pp = cur;
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00320AE8);
#endif
