/* NON_MATCHING cCamera_update (sn-2.95.3-136): 234 words vs 268 with no fp_hazard_rules (284 with fdiv).
 * Identical to retail through the screen matrix, view matrix and shake. Retail pads its div.s sites with
 * 0, 1 or 2 nops by context, which no fp_hazard_rules set reproduces, and holds the five depth-matrix
 * constants in f22..f26 where this build picks other registers. */
#include "include_asm.h"
#include "godhand/cCamera.h"

#ifdef NON_MATCHING

#define CAM_PI  3.14159274f

extern float func_003A1AE8(float x);                                   /* tanf */
extern void func_0030AA40(float *m, float scrz, float ax, float ay, float cx, float cy,
                          float zmin, float zmax, float nearz, float farz);   /* sceVu0ViewScreenMatrix */
extern void func_0030A2E0(float *dst, float *a, float *b);              /* sceVu0MulMatrix */
extern void MtxMultiply(float *dst, float *a, float *b);
extern void MtxCopy(float *dst, float *src);
extern void sceVu0UnitMatrix(float *m);
extern float capVu0Sin(float x);
extern void cCamera_calcViewMatrix(struct cCamera *self);

extern float D_003C1190;        /* screen width */
extern int D_003C1180;          /* frame buffer width */
extern float D_00586B88;        /* aspect */

/* Rebuild the screen, view and three fixed-depth projection matrices from fov and the shake. */
__attribute__((section(".text.cCamera_update")))
void cCamera_update(struct cCamera *self)
{
    float tmp[16];
    float scrz;
    float a, b;

    func_0030AA40(self->mtx[4],
                  D_003C1190 / D_00586B88 * 0.5f / func_003A1AE8(self->fov * CAM_PI / 360.0f),
                  D_003C1180 / 640.0f, D_00586B88, 2048.0f, 2048.0f, 1.0f,
                  2031585.0f / (self->fov + self->fov) * 2.0f, 0.1f, 600.0f);
    self->mtx[4][0] = -self->mtx[4][0];
    self->mtx[4][5] = -self->mtx[4][5];
    cCamera_calcViewMatrix(self);
    if (self->vib[1].count)
        self->mtx[5][13] += self->vib[1].amp * capVu0Sin(self->vib[1].phase);
    if (self->vib[0].count)
        self->mtx[5][12] += self->vib[0].amp * capVu0Sin(self->vib[0].phase);
    MtxMultiply(self->mtx[0], self->mtx[4], self->mtx[5]);

    MtxCopy(tmp, self->mtx[5]);
    scrz = D_003C1190 / D_00586B88 * 0.5f / func_003A1AE8(self->fov * CAM_PI / 360.0f);
    a = 44.8f / scrz;
    b = 51.2f / scrz;
    sceVu0UnitMatrix(self->mtx[1]);
    self->mtx[1][10] = 1.0003333f;
    self->mtx[1][14] = -0.20003334f;
    self->mtx[1][11] = 1.0f;
    self->mtx[1][15] = 0.0f;
    self->mtx[1][5] = -(0.2f / (a + a));
    self->mtx[1][0] = -(0.2f / (b + b));
    func_0030A2E0(self->mtx[1], self->mtx[1], tmp);

    MtxCopy(tmp, self->mtx[5]);
    scrz = D_003C1190 / D_00586B88 * 0.5f / func_003A1AE8(self->fov * CAM_PI / 360.0f);
    a = 44.8f / scrz;
    b = 51.2f / scrz;
    sceVu0UnitMatrix(self->mtx[2]);
    self->mtx[2][10] = 1.0003333f;
    self->mtx[2][14] = -0.20003334f;
    self->mtx[2][11] = 1.0f;
    self->mtx[2][15] = 0.0f;
    self->mtx[2][5] = -(0.2f / (a + a));
    self->mtx[2][0] = -(0.2f / (b + b));
    func_0030A2E0(self->mtx[2], self->mtx[2], tmp);

    MtxCopy(tmp, self->mtx[5]);
    scrz = D_003C1190 / D_00586B88 * 0.5f / func_003A1AE8(self->fov * CAM_PI / 360.0f);
    a = 160.0f / scrz;
    sceVu0UnitMatrix(self->mtx[3]);
    self->mtx[3][10] = 1.0003333f;
    self->mtx[3][14] = -0.20003334f;
    self->mtx[3][11] = 1.0f;
    self->mtx[3][15] = 0.0f;
    self->mtx[3][5] = self->mtx[3][0] = -(0.2f / (a + a));
    func_0030A2E0(self->mtx[3], self->mtx[3], tmp);
}
#else
INCLUDE_ASM("asm/nonmatching", cCamera_update);
#endif
