/* NON_MATCHING func_0037E4C0 (sn-2.95.3-136, 106 vs 108 words: retail keeps a second copy of the entry count (a0 copied from a1 in the cancel test delay slot) and branches with bnez rather than bnel in the page-up test) */
#include "include_asm.h"

#ifdef NON_MATCHING
/* func_0037E4C0, list menu input: cancel closes the menu; up/down wrap the cursor, page up/down jump
 * by ten entries when the list has more than ten, left/right cycle the 0-9 column, and the page top follows the
 * cursor. */
typedef struct MenuEntList {
    char pad00[0x14];
    char *begin;                        /* 0x14 8-byte entries */
    char *end;                          /* 0x18 */
} MenuEntList;

typedef struct MenuListCtl {
    char pad00[5];
    unsigned char col;                  /* 0x05 */
    char pad06[2];
    unsigned int top;                   /* 0x08 */
    unsigned int cur;                   /* 0x0C */
    MenuEntList *list;                   /* 0x10 */
} MenuListCtl;

typedef struct MenuListPad {
    char pad00[0x34];
    unsigned int trig;                  /* 0x34 */
    unsigned int rep;                   /* 0x38 */
} MenuListPad;

extern void func_0037E670(MenuListCtl *m);

__attribute__((section(".text.func_0037E4C0")))
void func_0037E4C0(MenuListCtl *m, MenuListPad *pad)
{
    unsigned int n;

    n = (m->list->end - m->list->begin) >> 3;
    if (pad->trig & 0x20) {
        func_0037E670(m);
        return;
    }
    if (pad->rep & 0x1000) {
        if (m->cur == 0)
            m->cur = n - 1;
        else
            m->cur = m->cur - 1;
    }
    if (pad->rep & 0x4000) {
        if (m->cur < n - 1)
            m->cur = m->cur + 1;
        else
            m->cur = 0;
    }
    if (n > 10) {
        if (pad->rep & 0x8000) {
            if (m->top >= 10)
                m->top = m->top - 10;
            else
                m->top = (n - 1) / 10 * 10;
            m->cur = m->top;
        }
        if (pad->rep & 0x2000) {
            if (m->top < n / 10 * 10)
                m->top = m->top + 10;
            else
                m->top = 0;
            m->cur = m->top;
        }
    }
    if (pad->rep & 4) {
        if (m->col == 0)
            m->col = 9;
        else
            m->col = m->col - 1;
    }
    if (pad->rep & 8) {
        if (m->col < 9)
            m->col = m->col + 1;
        else
            m->col = 0;
    }
    m->top = m->cur / 10 * 10;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0037E4C0);
#endif
