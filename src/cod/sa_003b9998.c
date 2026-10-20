/* cygnus-2.96: func_003B9998, set up the ADX decoder for the handle (same shape as
 * func_00336BA8): reset and configure, create the decoder under the lock, then install the five callbacks. */
typedef struct Work3B9998 {
    char pad0[0xC0];
    int dec;                /* 0xC0 */
} Work3B9998;

typedef struct Inner3B9998 {
    char pad0[4];
    Work3B9998 *work;       /* 0x04 */
} Inner3B9998;

typedef struct Adxt3B9998 {
    char pad0[4];
    Inner3B9998 *obj;       /* 0x04 */
    char pad8[8];
    int nch;                /* 0x10 */
    char pad14[4];
    int sfreq;              /* 0x18 */
} Adxt3B9998;

extern char D_00460818[];
extern char D_00460840[];
extern void *D_003D141C;
extern void *D_003E9D20;
extern void *D_003D1420;
extern void *D_003E9D18;
extern void *D_003E9D1C;

extern void func_00329EA8(Adxt3B9998 *adxt);
extern void func_003B9AF8(Adxt3B9998 *adxt);
extern void Obj3260_TrampVia0C_00337B30_D220(Adxt3B9998 *adxt, int v);
extern void Obj3260_TrampVia0C_00337B80_D238(Adxt3B9998 *adxt, int v);
extern void func_003B9E10(void);
extern void Obj0000_Set_D_003FC7AC_D_003FC7B0_3B9D98(void (*fn)(), int arg);
extern void func_003B9D48();
extern void Forward33B658_325C60(void);
extern void Forward33B670_325C78(void);
extern int func_003B9EB0(int a, int b);
extern void func_0033F1A8(char *a, char *b);
extern void func_003BA8C0(int dec, int nch, int sfreq);
extern void func_003BA900(int dec, int v);
extern void func_003B9B20();
extern void func_003B9BF0();
extern void func_003B9BB8();
extern void func_003B9CE8();
extern void func_003B9D30();

__attribute__((section(".text.func_003B9998")))
void func_003B9998(Adxt3B9998 *adxt, int a1, int a2)
{
    int *sfreq = &adxt->sfreq;
    Work3B9998 *w;
    int nch;
    int dec;

    func_00329EA8(adxt);
    func_003B9AF8(adxt);
    Obj3260_TrampVia0C_00337B30_D220(adxt, 1);
    Obj3260_TrampVia0C_00337B80_D238(adxt, 0);
    func_003B9E10();
    Obj0000_Set_D_003FC7AC_D_003FC7B0_3B9D98(func_003B9D48, 0);
    w = adxt->obj->work;
    nch = adxt->nch;
    Forward33B658_325C60();
    dec = func_003B9EB0(a1, a2);
    if (dec == 0) {
        func_0033F1A8(D_00460818, D_00460840);
        return;
    }
    func_003BA8C0(dec, nch, *sfreq);
    func_003BA900(dec, 0x14);
    w->dec = dec;
    D_003D141C = func_003B9B20;
    D_003E9D20 = func_003B9BF0;
    D_003D1420 = func_003B9BB8;
    D_003E9D18 = func_003B9CE8;
    D_003E9D1C = func_003B9D30;
    Forward33B670_325C78();
}
