/* NON_MATCHING func_0034AC60: open the ADX stream for a handle: create the ADXT on the work at 0x35B0, map its buffer, fill the callback table at 0x365C, then start it.
 * The inline setter gives retail's register for every callback address.
 * Left: retail forms cb (s1+0x365C) between the low halves and loads adxt->id only after the 0x2114 and 0x14 stores; int-typed fields keep the load late but reshuffle the registers. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Info34AC60 {
    int a;      /* 0x00 */
    int b;      /* 0x04 */
    int c;      /* 0x08 */
} Info34AC60;

typedef struct Rec34AC60 {
    void *adxt; /* 0x00 */
    int span;   /* 0x04 */
} Rec34AC60;

typedef struct Adxt34AC60 {
    char pad0[0xC];
    int id;     /* 0x0C */
} Adxt34AC60;

typedef struct Cb34AC60 {
    int id;
    void *fn[5];
} Cb34AC60;

typedef struct Hn34AC60 {
    char pad0[0x2004];
    Rec34AC60 *rec;             /* 0x2004 */
    char pad2008[0x2114 - 0x2008];
    Cb34AC60 *cb;               /* 0x2114 */
    char pad2118[0x35A8 - 0x2118];
    Rec34AC60 recbuf;           /* 0x35A8 */
    Info34AC60 info;            /* 0x35B0 */
    char pad35BC[0x365C - 0x35BC];
    Cb34AC60 cbbuf;             /* 0x365C */
} Hn34AC60;

extern int GetArrayElemA0C_35A1C8(Hn34AC60 *hn, int idx);
extern int func_0034ADB8(Hn34AC60 *hn, Rec34AC60 *rec);
extern Adxt34AC60 *sfadxt_CreateEx(Info34AC60 *info);
extern int func_003395A0(int a, int b, int c);
extern int func_0034DD70(Hn34AC60 *hn, int code);
extern void func_00329D38(Adxt34AC60 *adxt, int span);
extern void func_0034B3E0(Hn34AC60 *hn, int on);
extern void func_0034AFF0(Hn34AC60 *hn);
extern void func_00349BA8(void);
extern void func_00349BC8(void);
extern void func_00349BE8(void);
extern void func_00349C08(void);
extern void func_00349C28(void);

static inline void SetCb34AC60(Cb34AC60 *cb, int id, void *f0, void *f1, void *f2, void *f3, void *f4)
{
    cb->id = id;
    cb->fn[0] = f0;
    cb->fn[1] = f1;
    cb->fn[2] = f2;
    cb->fn[3] = f3;
    cb->fn[4] = f4;
}

int func_0034AC60(Hn34AC60 *hn)
{
    Info34AC60 *info = &hn->info;
    Rec34AC60 *rec = &hn->recbuf;
    Adxt34AC60 *adxt;
    Cb34AC60 *cb;
    int span;
    int r;

    if (GetArrayElemA0C_35A1C8(hn, 6) == 0)
        return 0;
    hn->rec = rec;
    r = func_0034ADB8(hn, rec);
    if (r != 0)
        return r;
    adxt = sfadxt_CreateEx(info);
    if (adxt == 0)
        return func_0034DD70(0, (int)0xFF000C04u);
    span = func_003395A0(info->c, info->a, info->b);
    cb = &hn->cbbuf;
    if (span == 0)
        return func_0034DD70(0, (int)0xFF000C05u);
    rec->span = span;
    rec->adxt = adxt;
    hn->cb = cb;
    SetCb34AC60(cb, adxt->id, func_00349BA8, func_00349BC8, func_00349BE8, func_00349C08, func_00349C28);
    func_00329D38(adxt, span);
    func_0034B3E0(hn, 1);
    func_0034AFF0(hn);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0034AC60);
#endif
