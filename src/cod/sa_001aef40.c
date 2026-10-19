/* sn-2.95.3-136: count the timer at 0x986 down; while it runs, set the position from the model
 * position with z = 0x988 jittered by fRand1_1 (2 degrees), and on the last tick without it. */
typedef struct {
    short delta;
    short index;
    void *(*fn)();
} Vt1AEF40;

extern float fRand1_1(void);

#define VT_ENT(p, off) ((Vt1AEF40 *)(*(char **)((p) + 0x214) + (off)))

static inline void SetV1AEF40(float *v, float x, float y, float z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = 1.0f;
}

__attribute__((section(".text.func_001AEF40")))
void func_001AEF40(char *p)
{
    float v[4];

    if (*(short *)(p + 0x986) <= 0)
        return;
    if (--*(short *)(p + 0x986) != 0) {
        Vt1AEF40 *set = VT_ENT(p, 0x78);
        char *self = p + set->delta;
        Vt1AEF40 *get = VT_ENT(p, 0x88);
        float *a = (float *)get->fn(p + get->delta);
        float *b;

        get = VT_ENT(p, 0x88);
        b = (float *)get->fn(p + get->delta);
        SetV1AEF40(v, a[0], b[1], *(float *)(p + 0x988) + fRand1_1() * 0.034906585f);
        set->fn(self, v);
    } else {
        Vt1AEF40 *set = VT_ENT(p, 0x78);
        char *self = p + set->delta;
        Vt1AEF40 *get = VT_ENT(p, 0x88);
        float *a = (float *)get->fn(p + get->delta);
        float *b;

        get = VT_ENT(p, 0x88);
        b = (float *)get->fn(p + get->delta);
        SetV1AEF40(v, a[0], b[1], *(float *)(p + 0x988));
        set->fn(self, v);
    }
}
