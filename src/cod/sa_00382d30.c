/* sn-2.95.3-136: func_00382D30, menu page update: show the "no data" prompt when there is no
 * list, otherwise run cursor input, page/scroll handlers and redraw the window frame. */
extern void func_002E0DE8(int a0, int a1, int a2, void *a3);
extern void func_00380DC0(void *a0);
extern void func_00381010(void *a0, void *a1, int a2);
extern void func_00380678(void *a0, int a1, int a2, int a3, int a4);
extern void func_00382F00(void *a0, void *a1);
extern int func_00382F40(void *a0, void *a1);
extern void func_003833B0(void *a0, void *a1);
extern void func_003833F8(void *a0, void *a1);
extern void func_00383438(void *a0, void *a1);
extern void func_00383478(void *a0, void *a1);
extern void func_00383518(void *a0, void *a1);
extern void func_003835A0(void *a0, void *a1);
extern void func_00384198(void *a0);
extern char D_0045CA00[];
extern char D_0045CA20[];

__attribute__((section(".text.func_00382D30")))
int func_00382D30(char *a0, char *a1)
{
    char *s0 = a0;
    char *s1 = a1;
    char *s2 = s0 + 0x370;

    if (*(int *)(s2 + 0xFC) == 0) {
        if ((*(int *)(s1 + 0x34) & 0xF0) != 0) {
            *(char *)s0 = 0;
            return 1;
        }
        func_002E0DE8(0xE, 0xA, 0xE, D_0045CA00);
        func_002E0DE8(0xD, 0xC, 8, D_0045CA20);
        return 1;
    }
    if (*(unsigned char *)(s2 + 1) != 0) {
        if ((*(int *)(s1 + 0x34) & 0xF0) != 0)
            *(char *)(s2 + 1) = 0;
    } else {
        func_00382F00(s0, s2);
        if (*(unsigned char *)(s0 + 4) != 0 || *(unsigned char *)(s0 + 2) == 0) {
            if ((*(int *)(s1 + 0x34) & 0x40) != 0 && *(unsigned char *)(s0 + 2) == 0) {
                *(char *)s0 = 0;
                *(int *)(s2 + 0x30) = 0;
                return 1;
            }
            if ((*(int *)(s1 + 0x34) & 0x20) != 0) {
                if ((*(int *)(s1 + 0x2C) & 2) != 0)
                    func_00380DC0(s0);
                if (func_00382F40(s0, s2) != 0)
                    goto done;
            }
            func_003833B0(s0, s2);
            if ((*(int *)(s1 + 0x34) & 0x80) != 0)
                func_003833F8(s0, s2);
            if ((*(int *)(s1 + 0x34) & 0x10) != 0)
                func_00383438(s0, s2);
            func_00381010(s0, s1, 4);
            func_00383478(s0, s1);
        }
        func_00383518(s0, s1);
        func_003835A0(s0, s2);
    }
done:
    func_00384198(s0);
    func_00380678(s0, 0x18, *(unsigned char *)(s0 + 4) * 8 + 0xA0, 0x80006060, 0xFFF8);
    return 1;
}
