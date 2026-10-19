/* func_00379190: status menu page draw (sn-2.95.3-136; clone of func_003794D0) */
extern void func_002E0DE8(int, int, int, const char *, ...);
extern void func_00379838(char *);
extern void func_00379910(char *);
extern char D_0045B350[];
extern char D_0045B360[];
extern char D_0045B5C0[];
extern char D_0045B5D8[];
extern char D_0045B5F0[];
extern char D_0045B4C0[];
extern char D_0045B608[];
extern char D_0045B620[];
extern char D_0045B460[];
extern char D_0045B478[];
extern char D_0045B638[];
extern char D_0045B650[];
extern char D_0045B3E8[];
extern char D_0045B400[];
extern char D_0045B668[];
extern char D_0045B680[];
extern char D_0045B550[];
extern char *D_003F2610[];
extern char D_0045B698[];
extern char D_0045B6B0[];
extern char D_0045B560[];
extern char D_0045B578[];
extern char D_0045B590[];
extern char D_0045B5A8[];

__attribute__((section(".text.func_00379190")))
void func_00379190(char *self)
{
    char *p = self + 0xCC;
    int x = 0x1B;

    if (*(unsigned short *)(p + 0xE) & 0x8000) {
        func_002E0DE8(0x1B, 3, 0xD, D_0045B350);
        func_002E0DE8(0x1B, 4, 0xD, D_0045B360);
        func_002E0DE8(0x1B, 5, 0xD, D_0045B350);
        return;
    }
    func_002E0DE8(0x1B, 3, 8, D_0045B5C0, *(short *)(p + 4));
    if (*(unsigned char *)(p + 6) & 1) {
        func_002E0DE8(0x1B, 4, 8, D_0045B5D8);
    } else {
        func_002E0DE8(0x1B, 4, 8, D_0045B5F0);
    }
    func_002E0DE8((short)x, 5, 8, D_0045B4C0, *(signed char *)(p + 7));
    if (*(unsigned short *)(p + 0xC) & 2) {
        func_002E0DE8((short)x, 6, 8, D_0045B608);
    } else {
        func_002E0DE8((short)x, 6, 8, D_0045B620);
    }
    if (*(unsigned short *)(p + 0xC) & 1) {
        func_002E0DE8((unsigned int)(x << 16) >> 16, 7, 8, D_0045B460);
    } else {
        func_002E0DE8((unsigned int)(x << 16) >> 16, 7, 8, D_0045B478);
    }
    func_002E0DE8((short)x, 8, 8, D_0045B638, *(int *)(p + 0x40));
    func_002E0DE8((short)x, 9, 8, D_0045B650, *(int *)(p + 0x44));
    func_002E0DE8((short)x, 0xB, 8, D_0045B3E8, *(short *)(p + 0x34));
    func_002E0DE8((short)x, 0xC, 8, D_0045B400, *(short *)(p + 0x36));
    func_002E0DE8((short)x, 0xD, 8, D_0045B668, *(short *)(p + 0x38));
    func_002E0DE8((short)x, 0xE, 8, D_0045B680, *(short *)(p + 0x3A));
    func_002E0DE8((short)x, 0x10, 8, D_0045B550, D_003F2610[*(signed char *)(p + 8)]);
    func_002E0DE8((short)x, 0x11, 8, D_0045B698, *(short *)(p + 0x3C));
    func_002E0DE8((short)x, 0x12, 8, D_0045B6B0, *(short *)(p + 0x3E));
    func_002E0DE8((short)x, 0x14, 8, D_0045B560, *(signed char *)(p + 0x58));
    func_002E0DE8((short)x, 0x15, 8, D_0045B578, *(signed char *)(p + 0x59));
    func_002E0DE8((short)x, 0x16, 8, D_0045B590, *(signed char *)(p + 0x5A));
    func_002E0DE8((short)x, 0x17, 8, D_0045B5A8, *(signed char *)(p + 0x5B));
    func_00379838(self);
    func_00379910(self);
}
