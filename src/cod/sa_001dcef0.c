/* sn-2.95.3-136: static initializer (priority 0xFFFF) for two vectors, a five entry row of
 * offsets at D_00568170 and a two entry row at D_005681C0. */
typedef struct Vec1DCEF0 {
    float x;
    float y;
    float z;
    float w;
} Vec1DCEF0;

extern Vec1DCEF0 D_00568150;
extern Vec1DCEF0 D_00568160;
extern Vec1DCEF0 D_00568170[5];
extern Vec1DCEF0 D_005681C0[2];

static inline void SetV1DCEF0(Vec1DCEF0 *v, float x, float y, float z, float w)
{
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

__attribute__((section(".text.func_001DCEF0")))
void func_001DCEF0(int owner, int code)
{
    Vec1DCEF0 *p;
    Vec1DCEF0 *q;

    if (code != 0xFFFF || owner == 0)
        return;
    SetV1DCEF0(&D_00568150, 0.0f, 0.0f, 0.0f, 1.0f);
    SetV1DCEF0(&D_00568160, 0.238f, 0.184f, 0.0f, 1.0f);
    p = D_00568170;
    SetV1DCEF0(p, -0.278f, 0.024f, 0.0f, 1.0f);
    p++;
    SetV1DCEF0(p, -0.139f, 0.024f, 0.0f, 1.0f);
    p++;
    SetV1DCEF0(p, 0.0f, 0.024f, 0.0f, 1.0f);
    p++;
    SetV1DCEF0(p, 0.139f, 0.024f, 0.0f, 1.0f);
    p++;
    SetV1DCEF0(p, 0.278f, 0.024f, 0.0f, 1.0f);
    q = D_005681C0;
    SetV1DCEF0(q, -0.1112f, 0.024f, 0.0f, 1.0f);
    q++;
    SetV1DCEF0(q, 0.1112f, 0.024f, 0.0f, 1.0f);
}
