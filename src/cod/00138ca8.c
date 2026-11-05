/* SN ProDG ee-gcc 2.95.3: func_00138CA8, copies the selected camera state parts from src to dst: bit 0 the
 * eye at +0x210, bit 1 the target at +0x200, bit 3 the whole 0x360-byte cCamera. */
#include "godhand/cCamManager.h"
#include "godhand/vecInline.h"
typedef struct { int q[4]; } __attribute__((aligned(16))) CamQ;
typedef struct { CamQ q[0x36]; } CamBlock;


__attribute__((section(".text.func_00138CA8")))
void func_00138CA8(cCamManager *self, struct cCamera *dst, struct cCamera *src, unsigned char mask)
{
    if (mask & 1)
        vec3_copy(&dst->eye.x, &src->eye.x);
    if (mask & 2)
        vec3_copy(&dst->target.x, &src->target.x);
    if (mask & 8)
        *(CamBlock *)dst = *(CamBlock *)src;
}
