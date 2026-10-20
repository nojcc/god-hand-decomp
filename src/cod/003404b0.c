/* func_003404B0 */
#ifdef NON_MATCHING

__attribute__((section(".text.func_003404B0")))
extern void D_003EC420(void);
extern int D_003EC450;

void func_003404B0(void) {
    func_003A50B4(&D_003EC420, &D_003EC420, 0x168);
    D_003EC450 += 1;
}

#else
INCLUDE_ASM("nonmatching", func_003404B0);
#endif
