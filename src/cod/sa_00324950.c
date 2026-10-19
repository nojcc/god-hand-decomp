/* cygnus-2.96 | drop-freorder-blocks: middleware init with reference count (0x324950). */

extern int D_003C7400;
extern int D_003C7408;
extern int D_003C7410;
extern int D_003C7414;
extern volatile int D_003C7418;
extern char D_003C7420[];
extern char *volatile D_00755C1C;
extern char D_00451AC0[];
extern char D_00451B10[];
extern char D_00451B20[];
extern char D_00451B30[];

extern void func_0033E618(void);
extern void Forward33B658_33E678(void);
extern void func_0033A090(void);
extern void func_003394A0(void);
extern void func_00338A90(void);
extern void func_0033F0B8(void);
extern void func_003279B8(void);
extern void func_003264C8(void);
extern void func_0033F3F0(void);
extern void Obj3260_Tramp_00337728_D288(void);
extern void func_00335DE0(void);
extern void func_0033BE80(void);
extern void Forward33F130_3248C0(void);
extern void Forward33F130_3248D8(void);
extern void Obj3260_NoOp_D2B8(void (*fn)(void), int arg);
extern void func_00335D18(void (*fn)(void), int arg);
extern void *func_003A52F0(void *d, int c, unsigned int n);
extern void func_00324910(void);
extern void func_00324930(void);
extern void func_003248F0(void);
extern void func_0033BA10(int a, int b, void (*fn)(void), int arg, char *name);
extern int func_0033B810(int id, void (*fn)(void), int arg, char *name);
extern void func_0032AB28(int n);
extern void Forward33B670_33E690(void);

__attribute__((section(".text.func_00324950")))
void func_00324950(void)
{
    D_00755C1C = D_00451AC0;
    if (D_003C7400 == 0) {
        func_0033E618();
        Forward33B658_33E678();
        func_0033A090();
        func_003394A0();
        func_00338A90();
        func_0033F0B8();
        func_003279B8();
        func_003264C8();
        func_0033F3F0();
        Obj3260_Tramp_00337728_D288();
        func_00335DE0();
        func_0033BE80();
        Obj3260_NoOp_D2B8(Forward33F130_3248C0, 0);
        func_00335D18(Forward33F130_3248D8, 0);
        func_003A52F0(D_003C7420, 0, 0xC80);
        func_0033BA10(2, 1, func_00324910, 0, D_00451B10);
        D_003C7414 = func_0033B810(4, func_00324930, 0, D_00451B20);
        D_003C7408 = func_0033B810(5, func_003248F0, 0, D_00451B30);
        D_003C7418 = 0;
        D_003C7410 = 0;
        func_0032AB28(0x3C);
        Forward33B670_33E690();
    }
    D_003C7400++;
}
