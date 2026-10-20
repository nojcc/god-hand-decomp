typedef struct Dec33D720 {
    char pad0[0x10];
    int n;              /* 0x10 */
    char pad14[0xC];
    short *a;           /* 0x20 */
    short *b;           /* 0x24 */
} Dec33D720;

typedef struct Adx33D720 Adx33D720;

struct Adx33D720 {
    char pad0[4];
    int stat;                                           /* 0x04 */
    Dec33D720 *dec;                                     /* 0x08 */
    char pad0C[0x68 - 0x0C];
    int hdr68;                                          /* 0x68 */
    int hdr6C;                                          /* 0x6C */
    int hdr70;                                          /* 0x70 */
    char pad74[4];
    int (*hdrcb)(int obj, int *a, int *b, int *c);      /* 0x78 */
    int hdrobj;                                         /* 0x7C */
    void (*endcb)(int obj, int a, int b);               /* 0x80 */
    int endobj;                                         /* 0x84 */
    char pad88[8];
    int end90;                                          /* 0x90 */
    int end94;                                          /* 0x94 */
    char pad98[0xE8 - 0x98];
    int replay;                                         /* 0xE8 */
};

extern int Obj33F8_GetWord_C_FA68(Dec33D720 *dec);
extern void func_0033FB78(Dec33D720 *dec);
extern void func_0033FB48(Dec33D720 *dec);
extern void func_0033D3D0(Adx33D720 *adx);
extern void func_0033D598(Adx33D720 *adx);
extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void (*D_003E9D4C)(Adx33D720 *adx, int v, short *a, short *b);

__attribute__((section(".text.func_0033D720")))
void func_0033D720(Adx33D720 *adx)
{
    Dec33D720 *dec;
    int i;

    if (adx->stat == 1 && Obj33F8_GetWord_C_FA68(adx->dec) == 0) {
        adx->hdrcb(adx->hdrobj, &adx->hdr68, &adx->hdr6C, &adx->hdr70);
        func_0033D3D0(adx);
        adx->stat = 2;
    }
    if (adx->stat != 2)
        return;
    func_0033FB78(adx->dec);
    if (Obj33F8_GetWord_C_FA68(adx->dec) != 3)
        return;
    if (adx->replay != 0) {
        dec = adx->dec;
        Forward33B658_33E678();
        for (i = 0; i < dec->n * 32; i++)
            D_003E9D4C(adx, dec->a[i], &dec->a[i], &dec->b[i]);
        Forward33B670_33E690();
    }
    func_0033D598(adx);
    func_0033FB48(adx->dec);
    adx->endcb(adx->endobj, adx->end94, adx->end90);
    adx->stat = 3;
}
