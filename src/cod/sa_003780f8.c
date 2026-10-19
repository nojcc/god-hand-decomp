/* sn-2.95.3-136: NM closer handoff. */
typedef struct {
    float s;
    float c;
} SinCos378;

extern SinCos378 D_0045A610[];

/* FLAG: the do-while(0) is required. It keeps both table-address adds ahead of the sine load. */
__attribute__((section(".text.func_003780F8")))
void func_003780F8(unsigned short ang, float *s, float *c)
{
    unsigned short r = ang % 360;

    if ((ang / 360) & 1) {
        float vc = -D_0045A610[360 - r].c;
        float vs = D_0045A610[360 - r].s;
        *s = vs;
        *c = vc;
        return;
    }
    {
        float ts;
        float tc;

        do {
            ts = D_0045A610[r].s;
            tc = D_0045A610[r].c;
            *s = ts;
        } while (0);
        *c = tc;
    }
}
