/* cygnus-2.96 (drop-reorder): func_00337728, DTX init (work buffers, IOP heap, RMT server, urpc open). */
extern int D_003E0710;
extern int D_003E0708;
extern volatile int D_003DF760;
extern int D_003E0754;
extern char D_003E31B0[];
extern int D_003E075C;
extern int D_003E31AC;
extern int D_003E0758;
extern int D_003E0760;
extern int D_003E31A8;
extern int D_003E0720;
extern int D_003E0724;
extern int D_003E0728;
extern int D_003E072C;
extern char D_004555B8[];
extern char D_00455480[];
extern char D_00455600[];
extern char D_00455628[];

extern void SJRMT_Init(void);
extern void func_0033B218(void);
extern void func_00332508(void);
extern void func_00337A00(void);
extern void func_00336F48(void);
extern void func_003A52F0(void *d, int c, int n);
extern int sceSifAllocIopHeap(int size);
extern void func_003260C8(char *fmt, ...);
extern int func_00332178(int n, int a, int b, int c);
extern void func_00332378(int h, void *fn, int arg);
extern void func_00332388(int h, void *fn, int arg);
extern void func_003373A0(void);
extern void func_00337400(void);
extern void DTX_CallUrpc(int fn, int *args, int n, int a3, int t0);

__attribute__((section(".text.func_00337728")))
void func_00337728(void)
{
    int args[3];

    D_003DF760;
    if (D_003E0710 == 1 && D_003E0708 <= 0)
        return;
    if (D_003E0754 == 0) {
        SJRMT_Init();
        func_0033B218();
        func_00332508();
        func_00337A00();
        func_00336F48();
        func_003A52F0(D_003E31B0, 0, 0x8D0);
        D_003E31AC = 0x880;
        D_003E0758 = ((int)D_003E31B0 + 0x40) & ~0x3F;
        if (D_003E075C == 0) {
            if ((D_003E075C = sceSifAllocIopHeap(0x8D0)) == 0) {
                func_003260C8(D_004555B8, 0x8D0);
                for (;;)
                    ;
            }
        }
        func_003260C8(D_00455480, 0x8D0, D_003E075C);
        D_003E0760 = (D_003E075C + 0x40) & ~0x3F;
        if ((D_003E31A8 = func_00332178(1, D_003E0758, D_003E0760, D_003E31AC)) == 0) {
            func_003260C8(D_00455600);
            for (;;)
                ;
        }
        func_00332378(D_003E31A8, func_003373A0, 0);
        func_00332388(D_003E31A8, func_00337400, 0);
        if (D_003E0724 == 0) {
            D_003E072C = D_003E0708;
            D_003E0720 = (D_003E0708 << 10) + 0x40;
            if ((D_003E0724 = sceSifAllocIopHeap(D_003E0720)) == 0) {
                func_003260C8(D_00455628, D_003E0720);
                for (;;)
                    ;
            }
            func_003260C8(D_00455480, D_003E0720, D_003E0724);
        }
        D_003E0728 = (D_003E0724 + 0x3F) & ~0x3F;
        args[0] = D_003E072C;
        args[1] = D_003E0728;
        args[2] = D_003E0720;
        DTX_CallUrpc(10, args, 3, 0, 0);
    }
    D_003E0754++;
}
