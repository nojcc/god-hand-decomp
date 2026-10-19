/* sn-2.95.3-136: func_001BF8C8, tutorial gimmick task: show the tutorial page for this object, wait for the confirm buttons and the page close, clear the scenario hold flags and advance the object mode. */
extern char *D_003BD6E8;
extern char *D_003C2F84;
typedef struct GameWork1BF8C8 {
    char pad0[0x1A0];
    long pad;                           /* 0x1A0 held buttons */
} GameWork1BF8C8;

extern GameWork1BF8C8 D_007474A0;
extern char D_00747A78[];

extern void cCockTutorial_TutorialON(void *tut, unsigned short id);
extern void cTaskWork_sleep(void *task, int frames);
extern void cTaskWork_exit(void *task);
extern void func_003A52F0(void *p, int c, int n);

__attribute__((section(".text.func_001BF8C8")))
void func_001BF8C8(char *p)
{
    char *tut;
    char *sc;
    int idx;

    cCockTutorial_TutorialON(D_003BD6E8 + 0x1A20, *(signed char *)(p + 0x600) + 0x2000);
    cTaskWork_sleep(*(void **)(D_003C2F84 + 0x20), 10);
    while ((D_007474A0.pad & 0x30000000) == 0)
        cTaskWork_sleep(*(void **)(D_003C2F84 + 0x20), 1);
    tut = D_003BD6E8 + 0x1A20;
    if (*(unsigned char *)(tut + 0xB8) == 2 || *(unsigned char *)(tut + 0xB8) == 3)
        *(unsigned char *)(tut + 0xB8) = 4;
    do {
        cTaskWork_sleep(*(void **)(D_003C2F84 + 0x20), 1);
    } while (*(signed char *)(D_003BD6E8 + 0x1AD8) != 0);
    func_003A52F0(D_00747A78, 0, 8);
    func_003A52F0(D_00747A78 + 8, 0, 4);
    sc = D_003C2F84;
    idx = *(int *)(sc + 0x24);
    if (idx >= 0)
        *(unsigned char *)(*(char **)(sc + 0x1C) + idx * 0x58 + 0x50) &= ~1;
    *(int *)(D_003C2F84 + 0x48) &= ~1;
    *(short *)(p + 0x602) = 10;
    *(unsigned char *)(p + 0x2F5) += 1;
    cTaskWork_exit(*(void **)(D_003C2F84 + 0x20));
}
