/* sn-2.95.3-136 -ffast-math, fp_hazard_rules fdiv: func_00135040, push two overlapping collision spheres apart: the first body moves by the overlap along x/z, scaled by who has the higher push priority. */
typedef struct Body135040 {
    char pad000[0xF0];
    float *pos;                         /* 0xF0 */
} Body135040;

typedef struct Push135040 {
    Body135040 *body;                   /* 0x0 */
    int pad04;
    int prio;                           /* 0x8 */
    float ratio;                        /* 0xC share taken when priorities tie */
} Push135040;

extern int func_00136A88(float *a, float *b, float *range);
extern void sceVu0SubVector(float *out, float *a, float *b);
extern void sceVu0Normalize(float *out, float *in);
extern void sceVu0ScaleVector(float *out, float *in, float s);

__attribute__((section(".text.func_00135040")))
int func_00135040(void *self, Push135040 *a, char *ca, Push135040 *b, char *cb)
{
    float dir[4] __attribute__((aligned(16)));
    float range;
    float *pa;
    float *pb;
    float dx, dy, dz;
    float depth;
    float w;
    float k;

    pa = (float *)(ca + 0x180);
    pb = (float *)(cb + 0x180);
    if (func_00136A88(pa, pb, &range) == 0)
        return 0;
    dx = pb[0] - pa[0];
    dy = pb[1] - pa[1];
    dz = pb[2] - pa[2];
    dx = __builtin_sqrtf(dx * dx + dy * dy + dz * dz);
    __asm__ volatile(""); /* retail loads range only after sqrt.s */
    depth = range - dx;
    if (depth <= 0.0f)
        return 0;
    if (a->prio == 0)
        return 1;
    sceVu0SubVector(dir, pa, pb);
    sceVu0Normalize(dir, dir);
    sceVu0ScaleVector(dir, dir, depth);
    if (a->prio == b->prio)
        w = b->ratio;
    else if (b->prio < a->prio)
        w = 1.0f;
    else
        w = 0.0f;
    k = 1.0f - w;
    a->body->pos[0] += dir[0] - dir[0] * k;
    a->body->pos[2] += dir[2] - dir[2] * k;
    return 1;
}
