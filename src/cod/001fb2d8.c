/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cNode.h"

extern unsigned char D_00747A50[];

__attribute__((section(".text.cCoreSave_freeItem")))
/* Free the remembered object with serial `id`. */
void cCoreSave_freeItem(cCoreSave *self, unsigned short id)
{
    cCoreSaveItem *item;
    cCoreSaveItem *w;
    unsigned short val;
    unsigned int i;

    if (D_00747A50[1] == 0) return;
    if (self->data == 0) return;
    item = self->data->item;
    i = 0;
    val = 0xFFFF;
    w = item;
    for (; i < CORESAVE_ITEM_NUM; i++) {
        if (item->serial == id) {
            w->stage = val;
            return;
        }
        w++;
        item++;
    }
}

__attribute__((section(".text.func_0027DBF8")))
void func_0027DBF8(char *obj, unsigned int mode)
{
    switch (mode) {
    case 0:
    default:
        obj[0x2F4] = 0;
        obj[0x2F5] = 7;
        obj[0x2F6] = 0;
        obj[0x2F7] = 0;
        break;
    case 1:
        obj[0x2F4] = 0;
        obj[0x2F5] = 7;
        obj[0x2F6] = 2;
        obj[0x2F7] = 0;
        break;
    case 2:
        obj[0x2F4] = 0;
        obj[0x2F5] = 7;
        obj[0x2F6] = 4;
        obj[0x2F7] = 0;
        break;
    }
}

__attribute__((section(".text.func_002832A0")))
void func_002832A0(char *obj, unsigned int mode)
{
    switch (mode) {
    case 0:
    default:
        obj[0x2F4] = 0;
        obj[0x2F5] = 6;
        obj[0x2F6] = 0;
        obj[0x2F7] = 0;
        break;
    case 1:
        obj[0x2F4] = 0;
        obj[0x2F5] = 6;
        obj[0x2F6] = 2;
        obj[0x2F7] = 0;
        break;
    case 2:
        obj[0x2F4] = 0;
        obj[0x2F5] = 6;
        obj[0x2F6] = 4;
        obj[0x2F7] = 0;
        break;
    }
}

extern struct D007474A0 {
    char pad[0x210];
    int f210;
} D_007474A0;

__attribute__((section(".text.func_002A4ED8")))
void func_002A4ED8(char *base)
{
    char *p;

    p = base + 0x28000;
    *(char **)(p + 0x2054) = base + ((D_007474A0.f210 & 1) * 0x15000 + 0x50);
    base = base + ((D_007474A0.f210 & 1) * 0x15000 + 0x50);
    base = base + 0x15000;
    *(char **)(p + 0x2058) = base;
}

__attribute__((section(".text.func_002B5EC0")))
void func_002B5EC0(cNode *self)
{
    cNode *q;

    if (self->parent == 0) return;
    q = self->next;
    if (q != 0) {
        q->prev = self->prev;
    }
    q = self->prev;
    if (q != 0) {
        q->next = self->next;
    } else {
        self->parent->child = self->next;
    }
    self->next = 0;
    self->prev = 0;
    self->parent = 0;
}
