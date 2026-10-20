/* func_0030D190 */
#ifdef NON_MATCHING

__attribute__((section(".text.func_0030D190")))
extern void D_005FEE00(void);
extern int D_00747A18;
extern int D_00753D88;

int func_0030D190(void) {
    D_00753D88 += 1;
    if ((D_00747A18 ^ 1) == 0) {
        func_002CA690(&D_005FEE00, &D_00753D88);
    }
    *(int *)0x10000010 |= 0x400;
    M2C_SYNC();
    M2C_ERROR(/* unknown instruction: ei */);
    return 0;
}

#else
INCLUDE_ASM("nonmatching", func_0030D190);
#endif
