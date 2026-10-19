/* sn-2.95.3-136: count the timer at 0xDA0 down; while it runs, set the position from the
 * model position with height 0xDA4 jittered by fRand1_1, and on the last tick without it. */
typedef struct {
    short delta;
    short index;
    void *(*fn)();
} Vt173258;

extern float fRand1_1(void);

#define VT_ENT(p, off) ((Vt173258 *)(*(char **)((p) + 0x214) + (off)))

static inline void SetV173258(float *v, float x, float y, float z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = 1.0f;
}

__attribute__((section(".text.func_00173258")))
void func_00173258(char *p)
{
    float v[4];

    if (*(short *)(p + 0xDA0) <= 0)
        return;
    if (--*(short *)(p + 0xDA0) != 0) {
        Vt173258 *set = VT_ENT(p, 0x70);
        char *self = p + set->delta;
        Vt173258 *get = VT_ENT(p, 0x80);
        float *a = (float *)get->fn(p + get->delta);
        float y = *(float *)(p + 0xDA4) + fRand1_1() * 0.02617994f;
        float *b;

        get = VT_ENT(p, 0x80);
        b = (float *)get->fn(p + get->delta);
        SetV173258(v, a[0], y, b[2]);
        set->fn(self, v);
    } else {
        Vt173258 *set = VT_ENT(p, 0x70);
        char *self = p + set->delta;
        Vt173258 *get = VT_ENT(p, 0x80);
        float *a = (float *)get->fn(p + get->delta);
        float *b;

        get = VT_ENT(p, 0x80);
        b = (float *)get->fn(p + get->delta);
        SetV173258(v, a[0], *(float *)(p + 0xDA4), b[2]);
        set->fn(self, v);
    }
}
