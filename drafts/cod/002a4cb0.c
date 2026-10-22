/* NON_MATCHING cFont_setTextureAddr (sn-2.95.3-136):
 * Retail moves font to v1 at entry, builds the slot address in a0 and stores info through a copy in v0; this build
 * forms the slot address in v0 directly, one instruction shorter, so everything after the slot stores is shifted. */
#include "include_asm.h"
#include "godhand/cFont.h"
#include "godhand/cFontTex.h"

#ifdef NON_MATCHING

/* Install a font texture in a slot once the resource and its info record are both complete: keep both pointers and
 * the info sizes, and the first time through turn the offsets of the two entry lists into addresses. */
__attribute__((section(".text.cFont_setTextureAddr")))
void cFont_setTextureAddr(cFont *font, int slot, cFontTexRes *res, cFontTexInfo *info)
{
    cFontTexSlot *s;
    cFontTexEnt *ent;
    char *base;
    unsigned int i;

    if (res == 0 || info == 0) {
        return;
    }
    if (info->h0 == 0 || info->h2 == 0 || info->h4 == 0 || info->b6 == 0 || info->b7 == 0) {
        return;
    }
    if (res->flags == 0 || res->w4 == 0 || res->w6 == 0 || res->offA == 0 || res->offB == 0) {
        return;
    }
    s = (cFontTexSlot *)font + slot;
    s->res = res;
    s->info = info;
    s->h8 = info->h2;
    s->hA = info->h4;
    s->hC = info->b6;
    s->hE = info->b7;
    if (res->flags & CFONTTEX_FIXED) {
        return;
    }
    base = (char *)res + res->offA;
    ent = (cFontTexEnt *)base;
    for (i = 0; i < res->numA; i++) {
        ent->addr += (int)base;
        ent++;
    }
    base = (char *)res + res->offB;
    ent = (cFontTexEnt *)base;
    for (i = 0; i < res->numB; i++) {
        ent->addr += (int)base;
        ent++;
    }
    res->flags |= CFONTTEX_FIXED;
}
#else
INCLUDE_ASM("asm/nonmatching", cFont_setTextureAddr);
#endif
