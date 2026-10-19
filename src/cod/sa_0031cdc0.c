/* sn-2.95.3-136: NM closer handoff. */
__attribute__((section(".text.func_0031CDC0")))
int *func_0031CDC0(int *base, int *key, int *alt, int nth)
{
    unsigned int n;
    unsigned int i;
    int hits;
    int *p;

    if (base == 0)
        return 0;
    n = *base;
    hits = 0;
    p = &base[n];
    for (i = 1; i <= n; i++) {
        p++;
        if (*p == *key || *p == *alt) {
            if (hits == nth)
                return (int *)(base[i] + (int)base);
            hits++;
        }
    }
    return 0;
}
