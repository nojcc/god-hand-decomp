extern char D_005E79D0[];
extern void *func_002B5AF8(void *a0, int a1, unsigned int size);

/* The movie player's malloc hook: func_002B5AF8 on D_005E79D0. */
__attribute__((section(".text.func_002B48A0")))
void *func_002B48A0(int a0, unsigned int size)
{
    return func_002B5AF8(D_005E79D0, a0, size);
}
