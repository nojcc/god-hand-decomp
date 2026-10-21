/* sn-2.95.3-136: func_003808A0, menu page update (same family as func_00384CA0): run cursor input and page handlers
 * for the current 0x48-byte page, then refresh the selected entry's model info (and the ADX stream counters when the
 * 0x3 toggle is on) and redraw the window frame. */
extern void func_00380DC0(void *a0);
extern void func_00380D68(void *a0, void *a1);
extern int func_00380B70(void *a0, void *a1);
extern int func_00380F80(void *a0, void *a1, void *a2);
extern void func_00380F10(void *a0, void *a1, void *a2);
extern void func_00380E88(void *a0, void *a1, void *a2);
extern void func_00380E10(void *a0);
extern void func_00381010(void *a0, void *a1, int a2);
extern void func_00381070(void *a0, void *a1);
extern void func_00381478(void *a0);
extern void func_00380678(void *a0, int a1, int a2, int a3, int a4);
extern int GuardedCall_00329FD0_329F98(int a0);
extern void func_0032A160(int a0, void *a1, void *a2);
extern int func_0032B6E0(int a0);
extern float func_0032AE10(int a0);
extern int func_0032D0C0(int a0);
extern int func_0032AD10(int a0);
extern int ADXPS2_GetNumDataSjtmp(int a0, int a1);
extern int func_003261A8(int a0, int a1);

__attribute__((section(".text.func_003808A0")))
int func_003808A0(char *self, char *arg)
{
    char buf[16];
    char *slot = self + (*(unsigned char *)(self + 5) * 0x48 + 0x48);
    char *snd = slot + 0x10;
    int v;

    if (*(unsigned char *)(slot + 1) != 0) {
        if ((*(int *)(arg + 0x34) & 0xF0) != 0)
            *(char *)(slot + 1) = 0;
    } else {
        func_00380D68(self, snd);
        if ((*(int *)(arg + 0x34) & 0x40) != 0) {
            *(char *)self = 0;
            *(int *)(slot + 0xC) = 0;
            return 1;
        }
        if ((*(int *)(arg + 0x34) & 4) != 0)
            *(char *)(self + 3) ^= 1;
        if ((*(int *)(arg + 0x34) & 0x20) != 0) {
            if ((*(int *)(arg + 0x2C) & 2) != 0)
                func_00380DC0(self);
            if (func_00380B70(self, slot) != 0) {
                func_00381478(self);
                func_00380678(self, 0x18, *(unsigned char *)(self + 4) * 8 + 0x78, 0x80006060, 0xFFF8);
                return 1;
            }
        }
        v = func_00380F80(self, snd, slot);
        if (v != 0)
            *(char *)(slot + 1) = v;
        if ((*(int *)(arg + 0x34) & 0x80) != 0)
            func_00380F10(self, snd, slot);
        if ((*(int *)(arg + 0x34) & 0x10) != 0)
            func_00380E88(self, snd, slot);
        if ((*(int *)(arg + 0x34) & 1) != 0)
            func_00380E10(self);
        func_00381010(self, arg, 4);
        func_00381070(self, arg);
        slot = self + (*(unsigned char *)(self + 5) * 0x48 + 0x48);
        if (*(int *)(snd + 0x30) != 0)
            *(int *)(slot + 0xC) = GuardedCall_00329FD0_329F98(*(int *)(snd + 0x30));
        else
            *(int *)(slot + 0xC) = -1;
        if (*(int *)(slot + 0xC) >= 0) {
            func_0032A160(*(int *)(snd + 0x30), snd + 0x10, buf);
            *(int *)(snd + 0x14) = func_0032B6E0(*(int *)(snd + 0x30));
            *(float *)(snd + 0x18) = func_0032AE10(*(int *)(snd + 0x30));
            *(int *)(snd + 0x1C) = func_0032D0C0(*(int *)(snd + 0x30));
            if (*(unsigned char *)(self + 3) != 0) {
                *(int *)(snd + 0x24) = func_0032AD10(*(int *)(snd + 0x30));
                *(int *)(snd + 0x28) = ADXPS2_GetNumDataSjtmp(*(int *)(snd + 0x30), 0);
                *(int *)(snd + 0x2C) = func_003261A8(*(int *)(snd + 0x30), 0);
            }
        }
    }
    func_00381478(self);
    func_00380678(self, 0x18, *(unsigned char *)(self + 4) * 8 + 0x78, 0x80006060, 0xFFF8);
    return 1;
}
