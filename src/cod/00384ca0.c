/* sn-2.95.3-136: func_00384CA0, menu page update (same family as func_00382D30): show the "no data" prompt when
 * there is no list, otherwise run cursor input and page handlers, refresh the selected entry's model info and redraw
 * the window frame. */
extern void func_002E0DE8(int a0, int a1, int a2, void *a3);
extern void func_00380DC0(void *a0);
extern void func_00380D68(void *a0, void *a1);
extern int func_00380F80(void *a0, void *a1, void *a2);
extern void func_00380F10(void *a0, void *a1, void *a2);
extern void func_00380E88(void *a0, void *a1, void *a2);
extern void func_00381010(void *a0, void *a1, int a2);
extern void func_00380678(void *a0, int a1, int a2, int a3, int a4);
extern int func_00384EC8(void *a0, void *a1);
extern void func_00384FA8(void *a0, void *a1);
extern void func_003854B0(void *a0);
extern int GuardedCall_00329FD0_329F98(int a0);
extern void func_0032A160(int a0, void *a1, void *a2);
extern int func_0032B6E0(int a0);
extern float func_0032AE10(int a0);
extern int func_0032D0C0(int a0);
extern char D_0045CD90[];
extern char D_0045CDB0[];

__attribute__((section(".text.func_00384CA0")))
int func_00384CA0(char *self, char *arg)
{
    char buf[16];
    char *s1 = self + 0x470;
    char *s2 = self + 0x484;
    int v;

    if (*(int *)(s1 + 0x84) == 0) {
        if ((*(int *)(arg + 0x34) & 0xF0) != 0) {
            *(char *)self = 0;
            return 1;
        }
        func_002E0DE8(0xE, 0xA, 0xE, D_0045CD90);
        func_002E0DE8(0xD, 0xC, 8, D_0045CDB0);
        return 1;
    }
    if (*(unsigned char *)(s1 + 1) != 0) {
        if ((*(int *)(arg + 0x34) & 0xF0) != 0)
            *(char *)(s1 + 1) = 0;
    } else {
        func_00380D68(self, s2);
        if (*(unsigned char *)(self + 4) != 0 || *(unsigned char *)(self + 2) == 0) {
            if ((*(int *)(arg + 0x34) & 0x40) != 0) {
                *(char *)self = 0;
                *(int *)(s1 + 0xC) = 0;
                return 1;
            }
            if ((*(int *)(arg + 0x34) & 0x20) != 0) {
                if ((*(int *)(arg + 0x2C) & 2) != 0)
                    func_00380DC0(self);
                if (func_00384EC8(self, s1) != 0) {
                    func_003854B0(self);
                    func_00380678(self, 0x18, *(unsigned char *)(self + 4) * 8 + 0xA0, 0x80006060, 0xFFF8);
                    return 1;
                }
            }
            v = func_00380F80(self, s2, s1);
            if (v != 0)
                *(char *)(s1 + 1) = v;
            if ((*(int *)(arg + 0x34) & 0x80) != 0)
                func_00380F10(self, s2, s1);
            if ((*(int *)(arg + 0x34) & 0x10) != 0)
                func_00380E88(self, s2, s1);
            func_00381010(self, arg, 4);
        }
        func_00384FA8(self, arg);
        if (*(int *)(s2 + 0x30) != 0)
            *(int *)(s1 + 0xC) = GuardedCall_00329FD0_329F98(*(int *)(s2 + 0x30));
        else
            *(int *)(s1 + 0xC) = -1;
        if (*(int *)(s1 + 0xC) >= 0) {
            func_0032A160(*(int *)(s2 + 0x30), s2 + 0x10, buf);
            *(int *)(s2 + 0x14) = func_0032B6E0(*(int *)(s2 + 0x30));
            *(float *)(s2 + 0x18) = func_0032AE10(*(int *)(s2 + 0x30));
            *(int *)(s2 + 0x1C) = func_0032D0C0(*(int *)(s2 + 0x30));
        }
    }
    func_003854B0(self);
    func_00380678(self, 0x18, *(unsigned char *)(self + 4) * 8 + 0xA0, 0x80006060, 0xFFF8);
    return 1;
}
