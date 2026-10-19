/* cygnus-2.96, --f=-freorder-blocks: NM closer handoff. */
typedef struct Req3315D8 {
    char pad0[2];
    signed char kind;
    char pad3[0x34 - 3];
    int result;
} Req3315D8;

extern volatile int D_003D845C;
extern volatile int D_003D8464;
extern volatile int D_003D8458;
extern volatile int D_003D8494;
extern char D_00453EE8[];
extern void Forward33B568_33B6A0(void);
extern void Forward33B5C8_33B6D0(void);
extern void PushGlobalD8478History_331C78(int code);
extern int func_003999D0(void);
extern void func_003B1F28(void *a, int r);

__attribute__((section(".text.func_003315D8")))
int func_003315D8(Req3315D8 *req)
{
    int r;

    if (D_003D845C == 0)
        return 0;
    if (req->kind != 2)
        return 0;
    D_003D8464 = 1;
    if (D_003D8458 == 1) {
        Forward33B568_33B6A0();
        PushGlobalD8478History_331C78(0x1400);
        r = func_003999D0();
        PushGlobalD8478History_331C78(0x1401);
        Forward33B5C8_33B6D0();
    } else {
        PushGlobalD8478History_331C78(0x1500);
        r = func_003999D0();
        PushGlobalD8478History_331C78(0x1501);
    }
    D_003D8494 = r;
    D_003D8464 = 0;
    if ((unsigned int)(r + 1) >= 2 && r != 0x20) {
        req->result = r;
        func_003B1F28(D_00453EE8, r);
        return 1;
    }
    return 0;
}
