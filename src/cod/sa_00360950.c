/* cygnus-2.96, -freorder-blocks dropped: func_00360950, select the timer channel (config override), arm its mode and reset the tick snapshot. */
typedef struct Tm360950 {
    volatile unsigned long count;
    volatile unsigned short last;
} Tm360950;

extern char D_0045A280[];
extern char D_0045A288[];
extern volatile int D_003EEA78;
extern int D_003EEA7C;
extern unsigned int D_003EEA80;
extern volatile unsigned int *D_0045A260[];
extern volatile unsigned int *D_0045A270[];
extern volatile Tm360950 D_00766CA8;
extern volatile Tm360950 D_00766CB8;
extern Tm360950 * volatile D_00766CC8;
extern volatile int D_00766CCC;

extern int func_0033FD70(void *name, int *out);
extern void Obj0000_Set_D_003EEA70_360C80(unsigned long v);

__attribute__((section(".text.func_00360950")))
void func_00360950(int ch)
{
    int val;

    if (func_0033FD70(D_0045A280, &val) == 0)
        ch = val;
    D_003EEA78++;
    if (D_003EEA78 >= 2 && D_003EEA7C == ch)
        return;
    D_003EEA7C = ch;
    if (ch == -1) {
        Obj0000_Set_D_003EEA70_360C80(1);
        return;
    }
    Obj0000_Set_D_003EEA70_360C80(func_0033FD70(D_0045A288, &val) == 0 ? (unsigned int)val : 0x8CA00);
    D_003EEA80 = *D_0045A260[ch];
    if ((D_003EEA80 & 0xC7) != 0x82) {
        *D_0045A270[ch] = 0;
        *D_0045A260[ch] = 0x82;
    }
    D_00766CA8.last = *D_0045A270[ch];
    D_00766CA8.count = 0;
    D_00766CB8 = D_00766CA8;
    D_00766CC8 = (Tm360950 *)&D_00766CA8;
    D_00766CCC = 0;
}
