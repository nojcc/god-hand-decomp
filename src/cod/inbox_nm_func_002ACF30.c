/* halt demote func_002ACF30 */
#ifdef NON_MATCHING
__attribute__((section(".text.func_002ACF30")))
int func_002ACF30(char *a0, void *a1, int a2, int a3)
{
    char *t0;
    int t1;
    int v0;
    int t2;
    char *row;
    int v1;

    t0 = a0 + 0x18000;
    t1 = *(int *)(t0 + 0x3544);
    v0 = *(int *)(a0 + 0x740);
    if (t1 == 0)
        return 0;
    t2 = v0 - 1;
    row = a0 + (t2 << 4);
    v1 = *(int *)(row + 0x100);
    if (v1 != a2)
        return 0;
    v0 = t1 - *(char *)(row + 0x10C);
    v0 = v0 * 0xAC + 0x744;
    if (a0 + v0 != a1)
        return 1;
    *(int *)(a0 + 0x740) = t2;
    t1 = *(int *)(t0 + 0x3544);
    *(int *)(t0 + 0x3544) = t1 - *(char *)(row + 0x10C);
    return 1;
}

#else
INCLUDE_ASM("nonmatching", func_002ACF30);
#endif
