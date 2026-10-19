/* sn-2.95.3-136: debug menu page select (0x37E200). */

typedef struct {
    unsigned char next;
    unsigned char sel;
    char pad2[2];
    unsigned char b4;
    unsigned char b5;
} Menu37E200;

typedef struct {
    char pad0[0x34];
    int trig;
    int rep;
} Pad37E200;

extern char D_0045C1B8[];
extern char D_0045C1C8[];
extern char *D_003F2888[];
extern void func_002E0DE8(int, int, int, char *, ...);

__attribute__((section(".text.func_0037E200")))
int func_0037E200(Menu37E200 *m, Pad37E200 *pad)
{
    signed char i;

    if (pad->trig & 0x40) {
        return 0;
    }
    if (pad->rep & 0x1000) {
        m->sel = m->sel ? m->sel - 1 : 4;
    }
    if (pad->rep & 0x4000) {
        if (m->sel < 4) {
            m->sel++;
        } else {
            m->sel = 0;
        }
    }
    if (pad->trig & 0x20) {
        m->b5 = 0;
        m->b4 = 0;
        m->next = m->sel + 1;
        return 1;
    }
    func_002E0DE8(0x15, 3, 0xD, D_0045C1B8);
    for (i = 0; i < 5; i++) {
        func_002E0DE8(0x14, (short)(i + 5), (i == m->sel) ? 0xE : 8, D_0045C1C8, D_003F2888[i]);
    }
    return 1;
}
