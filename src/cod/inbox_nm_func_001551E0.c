/* halt demote func_001551E0 */
#ifdef NON_MATCHING
__attribute__((section(".text.func_001551E0")))
int func_001551E0(char *a0, int a1)
{
    char hold[16];
    char *o;
    char *rec;
    unsigned short h;
    int q;
    int rem;
    int d;

    o = *((char **)(a0 + 0x388));
    *((int *)hold) = (int)o;
    d = 0x18;
    rec = (char *)(*((int *)(o + (a1 << 2) + 0x20)) + (int)o);
    *((int *)(hold + 4)) = (int)rec;
    h = *((unsigned short *)(rec + 0x14));
    q = (int)h / d;
    rem = (int)h % d;
    if (rem != 0) {
        q = q + 1;
        __asm__("");
    } else {
        __asm__("");
    }
    return q * 0x90 + 0x10;
}

#else
INCLUDE_ASM("nonmatching", func_001551E0);
#endif
