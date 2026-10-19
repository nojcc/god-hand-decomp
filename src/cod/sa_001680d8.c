/* sn-2.95.3-136: func_001680D8, menu panel fade in/out plus the left/right arrow highlight. */
extern char *D_003BD930;
extern void cIDBase_move(void *p);

__attribute__((section(".text.func_001680D8")))
void func_001680D8(char *p)
{
    switch (*(signed char *)(p + 0x5A)) {
    case 0:
        *(unsigned char *)(p + 0x90) += 0x10;
        if (*(unsigned char *)(p + 0x90) > 0x80) {
            *(signed char *)(p + 0x5A) = 1;
            *(unsigned char *)(p + 0x90) = 0x80;
        }
        break;
    case 1:
        *(unsigned char *)(p + 0x90) = 0x80;
        break;
    case 2: {
        int v;

        if (*(unsigned char *)(p + 0x64) == 1) {
            *(unsigned char *)(p + 0x90) = 0x80;
            *(int *)(p + 0x60) = 0xA;
            *(signed char *)(p + 0x5A) = 0;
        }
        v = *(unsigned char *)(p + 0x90) - 0x10;
        if (v < 0) {
            *(unsigned char *)(p + 0x90) = 0;
            *(int *)(p + 0x60) = -1;
            *(signed char *)(p + 0x5A) = 0;
        } else {
            *(unsigned char *)(p + 0x90) = v;
        }
        break;
    }
    }
    *(unsigned char *)(*(char **)(p + 0x80) + 0x4F) = *(unsigned char *)(p + 0x90);
    switch (*(signed char *)(p + 0x91)) {
    case -1:
        *(int *)(*(char **)(p + 0x84) + 0x2C) &= ~0x8000000;
        *(int *)(*(char **)(p + 0x88) + 0x2C) |= 0x8000000;
        D_003BD930[0xEDD] = 0;
        break;
    case 0:
        *(int *)(*(char **)(p + 0x84) + 0x2C) |= 0x8000000;
        *(int *)(*(char **)(p + 0x88) + 0x2C) &= ~0x8000000;
        *(float *)(*(char **)(p + 0x88) + 0x38) = -184.0f;
        D_003BD930[0xEDD] = 0;
        break;
    case 1:
        *(int *)(*(char **)(p + 0x84) + 0x2C) |= 0x8000000;
        *(int *)(*(char **)(p + 0x88) + 0x2C) &= ~0x8000000;
        *(float *)(*(char **)(p + 0x88) + 0x38) = 44.0f;
        D_003BD930[0xEDD] = 1;
        break;
    }
    cIDBase_move(p);
}
