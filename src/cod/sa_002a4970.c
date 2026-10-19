/* sn-2.95.3-136: func_002A4970, binds the font textures from the game data pack: three texture/palette pairs
 * (slots 0, 1, 4) for language 0, two (slots 0, 4) for languages 1-6, then clears the font's pending count. */
typedef struct GameWork2A4970 {
    char pad000[0x558];
    void *pack;                         /* 0x558 */
    char pad55C[0x56C - 0x55C];
    int lang;                           /* 0x56C */
} GameWork2A4970;

typedef struct Font2A4970 {
    char pad00000[0x2A08C];
    int pending;                        /* 0x2A08C */
} Font2A4970;

extern GameWork2A4970 D_007474A0;
extern char D_0044ACE0[];
extern char D_0044ACE8[];
extern void *SearchData(void *pack, char *name, int index);
extern void cFont_setTextureAddr(Font2A4970 *font, int slot, void *tex, void *clut);

__attribute__((section(".text.func_002A4970")))
void func_002A4970(Font2A4970 *font)
{
    GameWork2A4970 *gw;

    gw = &D_007474A0;
    switch (gw->lang) {
    case 0:
        cFont_setTextureAddr(font, 0, SearchData(gw->pack, D_0044ACE0, 0), SearchData(gw->pack, D_0044ACE8, 0));
        cFont_setTextureAddr(font, 1, SearchData(gw->pack, D_0044ACE0, 1), SearchData(gw->pack, D_0044ACE8, 1));
        cFont_setTextureAddr(font, 4, SearchData(gw->pack, D_0044ACE0, 2), SearchData(gw->pack, D_0044ACE8, 2));
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        cFont_setTextureAddr(font, 0, SearchData(gw->pack, D_0044ACE0, 0), SearchData(gw->pack, D_0044ACE8, 0));
        cFont_setTextureAddr(font, 4, SearchData(gw->pack, D_0044ACE0, 0), SearchData(gw->pack, D_0044ACE8, 1));
        break;
    }
    font->pending = 0;
}
