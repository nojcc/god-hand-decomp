/* VU Adjust_theta_vec; bitfield decode schedule; list scan; ld/sd slot;
* float copy beql/const;
* ID release lui/v0 vs v1 (1 word); flag dsrl
 * const order (2 words); beql task exit;
* FP-frame thunk;
* RNG nibble;
* dispatch beql.
* Closest: SlotUi_release (1), func_002BF420 (2). */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cRoomSave.h"
#include "godhand/cDoor.h"
extern char D_0076A790[];

__attribute__((section(".text.Adjust_theta_vec")))
void Adjust_theta_vec(void *a0)
{
}

__attribute__((section(".text.func_002A4BA0")))
int func_002A4BA0(char *base, unsigned int id)
{
    char *a2 = base;
    unsigned int a0 = id & 0xFFFF;
    unsigned int hi;
    char *row;
    int v;
    int *tbl;
    unsigned short lim;
    int w;

    if (a0 == 0)
        return 0;
    hi = a0 >> 12;
    hi <<= 4;
    a0 &= 0xFFF;
    row = a2 + hi;
    a0 <<= 2;
    tbl = *(int **)(row + 4);
    lim = *(unsigned short *)(row + 0xE);
    w = *(int *)((char *)tbl + a0 + 8);
    w = (unsigned)w >> 14;
    w &= 0x3F;
    v = (int)lim - w;
    v = (short)v;
    return v;
}

__attribute__((section(".text.func_002BEAA8")))
cRoomJumpGroup *func_002BEAA8(cRoomJump *self, unsigned short id)
{
    cRoomJumpTbl *tbl = (cRoomJumpTbl *)self->tbl;
    cRoomJumpGroup *g;
    unsigned int n;
    unsigned int i;

    if (tbl == 0) {
        return 0;
    }
    n = tbl->groupNum;
    if (n == 0) {
        return 0;
    }
    g = tbl->group;
    for (i = 0; i < n; i++) {
        if (g[i].id == id) {
            return &g[i];
        }
    }
    return 0;
}

/* Mark the one-shot slot `key` used: store the key in the first empty slot
 * of the page. Retail walks the slots with two pointers (one for the test,
 * one for the store); this keeps one, a word shorter. */
__attribute__((section(".text.func_002BECB0")))
void func_002BECB0(cRoomSave *self, long key)
{
    cRoomSaveSlot *t;
    unsigned int i;

    if (key == 0) {
        return;
    }
    t = self->data->slot;
    for (i = 0; i < ROOMSAVE_SLOT_NUM; i++) {
        if (t[i].key == 0) {
            t[i].key = key;
            self->data->slot[i].used = 1;
            return;
        }
    }
}

__attribute__((section(".text.func_00377FA0")))
int func_00377FA0(void)
{
    char *p = D_0076A790;
    short v = *(short *)(p + 0x20);
    unsigned short u = *(unsigned short *)(p + 0x20);
    unsigned short u2 = *(unsigned short *)(p + 0x20);
    int t = (int)v * 3;
    int b;
    int r;

    t <<= 16;
    t >>= 24;
    b = (u + t) & 0xFF;
    t &= 0xFF;
    r = b | (t << 8);
    if (u2 == (short)r)
        r = u2 + 1;
    *(unsigned short *)(p + 0x20) = (unsigned short)r;
    return r & 0xFF;
}

#else
INCLUDE_ASM("asm/nonmatching", Adjust_theta_vec);
INCLUDE_ASM("asm/nonmatching", func_002A4BA0);
INCLUDE_ASM("asm/nonmatching", func_002BEAA8);
INCLUDE_ASM("asm/nonmatching", func_002BECB0);
INCLUDE_ASM("asm/nonmatching", func_00377FA0);
#endif
