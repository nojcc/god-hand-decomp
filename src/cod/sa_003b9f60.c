typedef struct Slot3B9F60 {
    int word;
    char pad[0x3C - 4];
} Slot3B9F60;

extern Slot3B9F60 D_003FC7B8[];

__attribute__((section(".text.func_003B9F60")))
Slot3B9F60 *func_003B9F60(void)
{
    Slot3B9F60 *p;
    int i;

    for (i = 0; i < 1; i++) {
        p = &D_003FC7B8[i];
        if (p->word == 0)
            break;
    }
    return i != 1 ? p : 0;
}
