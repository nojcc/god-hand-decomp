/* NON_MATCHING cFont_setTextureAddr: sn;
 * 20 diffs: retail copies self to v1 at entry and stores info through a second copy of the slot pointer (pointer-copy chain), and swaps base/cursor registers in the first relocation loop; slot pointer, per-field self[idx], inline setter, self+=idx and indexed-loop forms tried */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int pad0;
    char *ptr;            /* 0x4 */
    char pad8[0x8];
} RelA4D00;

typedef struct {
    int flags;            /* 0x0, bit 31 = relocated */
    unsigned short w;     /* 0x4 */
    unsigned short h;     /* 0x6 */
    int ofs1;             /* 0x8 */
    int ofs2;             /* 0xC */
    unsigned short n1;    /* 0x10 */
    unsigned short n2;    /* 0x12 */
} TexA4D00;

typedef struct {
    unsigned short num;   /* 0x0 */
    unsigned short cw;    /* 0x2 */
    unsigned short ch;    /* 0x4 */
    unsigned char sx;     /* 0x6 */
    unsigned char sy;     /* 0x7 */
} InfoA4D00;

typedef struct {
    TexA4D00 *tex;        /* 0x0 */
    InfoA4D00 *info;      /* 0x4 */
    unsigned short cw;    /* 0x8 */
    unsigned short ch;    /* 0xA */
    short sx;             /* 0xC */
    short sy;             /* 0xE */
} SlotA4D00;

void cFont_setTextureAddr(SlotA4D00 *self, int idx, TexA4D00 *tex, InfoA4D00 *info)
{
    SlotA4D00 *s;
    RelA4D00 *r;
    char *base;
    unsigned int i;

    if (tex == 0 || info == 0 || info->num == 0 || info->cw == 0 || info->ch == 0 ||
        info->sx == 0 || info->sy == 0 || tex->flags == 0 || tex->w == 0 || tex->h == 0 ||
        tex->ofs1 == 0 || tex->ofs2 == 0)
        return;

    self += idx;
    self->tex = tex;
    self->info = info;
    self->cw = info->cw;
    self->ch = info->ch;
    self->sx = info->sx;
    self->sy = info->sy;

    if (tex->flags < 0)
        return;

    base = (char *)tex + tex->ofs1;
    r = (RelA4D00 *)base;
    for (i = 0; i < tex->n1; i++, r++)
        r->ptr += (int)base;

    base = (char *)tex + tex->ofs2;
    r = (RelA4D00 *)base;
    for (i = 0; i < tex->n2; i++, r++)
        r->ptr += (int)base;

    tex->flags |= 0x80000000;
}
#else
INCLUDE_ASM("asm/nonmatching", cFont_setTextureAddr);
#endif
