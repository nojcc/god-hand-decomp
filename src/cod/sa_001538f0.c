/* sn-2.95.3-136: Trans_Clipmatrix_set, build the clip matrix: the inverse of the camera view matrix, then a unit
 * matrix scaled by the clip window (from the field of view, the screen aspect and width) with the depth range
 * mapped to 0..1 and the 2048 GS offset. */
typedef struct Cam1538F0 {
    char pad000[0x40];
    float view[4][4];                   /* 0x040 */
    char pad080[0x1D0];
    float fov;                          /* 0x250 */
} Cam1538F0;

extern Cam1538F0 *D_005CAFF0;
extern float D_00586B88;
extern float D_003C1190;
extern int D_003C1180;
extern float D_004A6900[4][4];
extern float D_004A6940[4][4];
extern float func_003A1AE8(float x);
extern void func_0030A548(float (*dst)[4], float (*src)[4]);
extern void sceVu0InversMatrix(float (*dst)[4], float (*src)[4]);
extern void sceVu0UnitMatrix(float (*m)[4]);

__attribute__((section(".text.Trans_Clipmatrix_set")))
void Trans_Clipmatrix_set(void)
{
    float t;
    float asp;
    float w;
    float a;
    float d;
    float sx;
    float sy;
    float half;
    float one;
    float near;
    float ofs;
    float nd;

    half = 0.5f;
    one = 1.0f;
    near = 0.1f;
    ofs = 2048.0f;
    t = func_003A1AE8(D_005CAFF0->fov * 3.1415927f / 360.0f);
    asp = D_00586B88;
    a = D_003C1190 / asp * half / t;
    w = (float)D_003C1180 / 640.0f;
    d = 2.0f * (2031585.0f / (2.0f * D_005CAFF0->fov));
    sx = 51.2f / a;
    sy = 44.8f / a;
    func_0030A548(D_004A6900, D_005CAFF0->view);
    nd = -d;
    sceVu0InversMatrix(D_004A6940, D_004A6900);
    sceVu0UnitMatrix(D_004A6940);
    D_004A6940[0][0] = a * w * sx / near;
    D_004A6940[1][1] = a * asp * sy / near;
    D_004A6940[2][2] = (nd + one) * half;
    D_004A6940[3][0] = ofs;
    D_004A6940[3][1] = ofs;
    D_004A6940[3][2] = (d + one) * half;
    D_004A6940[3][3] = one;
}
