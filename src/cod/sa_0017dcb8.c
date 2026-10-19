/* sn-2.95.3-136 (fp_hazard_rules mtc1): cOl21_createShapes, build the 4+4 ring shapes and the cap shape for cOl21. */
typedef struct {
    float v[8];
} Tbl17D;

typedef struct {
    char pad0[0x80];
    char f80[0x654 - 0x80];
    int shp0[4];
    int shp1[4];
    int shp2;
} cOl21S;

extern Tbl17D D_00421F00;
extern char D_005CAE50[];
extern int func_0012E990(void *mgr, void *self, void *mtx, float *a, float *b, float *tbl, float r, float h);

static __inline__ void vset(float *v, float x, float y, float z, float w)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = w;
}

__attribute__((section(".text.cOl21_createShapes")))
void cOl21_createShapes(cOl21S *self)
{
    Tbl17D t;
    float a[4];
    float b[4];
    int *shp;
    float *t1;
    int i;
    float len;
    float half;

    shp = self->shp0;
    t1 = t.v + 4;
    t = D_00421F00;
    len = 4.2f;
    half = 1.5707963705062866f;
    for (i = 0; i < 4; i++) {
        vset(a, 0.0f, 1.0f, -1.8499999046325684f, 1.0f);
        vset(b, 0.0f, half * (float)i - 3.1415927410125732f, 0.0f, 1.0f);
        shp[i] = func_0012E990(D_005CAE50, self, self->pad0 + 0x80, a, b, t.v, len - 0.25f, 2.0f);
    }
    for (i = 0; i < 4; i++) {
        vset(a, 0.0f, 1.0f, -2.6999998092651367f, 1.0f);
        vset(b, 0.0f, half * (float)i - 3.1415927410125732f, 0.0f, 1.0f);
        shp[4 + i] = func_0012E990(D_005CAE50, self, self->pad0 + 0x80, a, b, t.v, len + 1.2f, 2.0f);
    }
    vset(a, -1.5707963705062866f, 0.0f, 0.0f, 1.0f);
    vset(b, 0.0f, 0.0f, 0.0f, 1.0f);
    self->shp2 = func_0012E990(D_005CAE50, self, self->pad0 + 0x80, b, a, t1, len - 0.5f, len - 0.5f);
}
