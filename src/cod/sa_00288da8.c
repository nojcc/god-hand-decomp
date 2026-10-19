/* sn-2.95.3-136: func_00288DA8, pick the 0/25/50 value from the type and subtype, look up the model and texture, swap textures for subtype 0x2A7 and set the model up. */
extern char D_00448C90[];
extern char D_00448C98[];

extern int GetEm00CharIndex(int type, int sub);
extern void Obj0000_Set_Field_424_1595E8(void *self, int v);
extern void *SearchData(void *pack, void *name, int which);
extern void cModel_setTextureExchange(void *model, void *texSet, void *tex, int arg);
extern int cModel_setupModel(void *model, void *mdl, void *tex, int a3, int t0);

__attribute__((section(".text.func_00288DA8")))
int func_00288DA8(char *self)
{
    int n;
    int idx;
    void *mdl;
    void *tex;
    char *pack;

    switch (*(unsigned short *)(self + 0x2FE)) {
    case 0x2A2:
    default:
        switch (*(int *)(self + 0x564)) {
        case 0x2A2:
        default:
            n = 0;
            break;
        case 0x2A3:
            n = 25;
            break;
        case 0x2A4:
            n = 50;
            break;
        }
        break;
    case 0x2A3:
        switch (*(int *)(self + 0x564)) {
        case 0x2A5:
        default:
            n = 0;
            break;
        case 0x2A6:
            n = 25;
            break;
        case 0x2A7:
            n = 50;
            break;
        }
        break;
    }
    idx = GetEm00CharIndex(*(unsigned short *)(self + 0x2FE), *(int *)(self + 0x564));
    Obj0000_Set_Field_424_1595E8(self, n);
    mdl = SearchData(*(void **)(self + 0x304), D_00448C90, idx);
    tex = SearchData(*(void **)(self + 0x304), D_00448C98, idx);
    if (*(int *)(self + 0x564) == 0x2A7 && (*(int *)(self + 0x155C) & 1)) {
        *(int *)(self + 0x254) |= 0x10000000;
        pack = *(char **)(self + 0x304);
        cModel_setTextureExchange(self, tex, (void *)(*(int *)(pack + 0x1C) + (int)pack), 0);
    }
    if (tex != 0)
        return cModel_setupModel(self, mdl, tex, 0, 0);
    return 0;
}
