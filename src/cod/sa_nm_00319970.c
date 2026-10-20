/* NON_MATCHING func_00319970 (sn-2.95.3-136; PARK, 168 diffs): retail hoists &D_007474A0 into s0 for both 0x574 and the frame counter, applies andi 0xFF on both paths of the scroll test, and reuses the loaded speed for the wrap compare and stored sum */
#include "include_asm.h"

#ifdef NON_MATCHING
extern char D_007474A0[];
extern float D_00754C48;
extern int GetField_2B1_14B638(void *self);
extern char *cModel_getMeshPtr(void *self, int i);
extern float Adjust_theta(float a);
extern float capVu0Cos(float a);

#define HDR(self) (*(char **)((self) + 0x320))
#define SPDU(self) (*(float *)((self) + 0x324))
#define SPDV(self) (*(float *)((self) + 0x328))
#define FRAME (*(unsigned int *)(D_007474A0 + 0x210))

static inline unsigned char isScroll(char *self)
{
    return SPDU(self) != 0.0f || SPDV(self) != 0.0f;
}

void func_00319970(char *self)
{
    float sp;
    int i;
    int n;
    char *m;

    if (!isScroll(self))
        return;
    sp = *(float *)(D_007474A0 + 0x574) * D_00754C48;
    if (!(*(unsigned int *)(HDR(self) + 0x34) & 0x10000)) {
        n = GetField_2B1_14B638(self);
        for (i = 0; i < n; i++) {
            m = cModel_getMeshPtr(self, i);
            if (!(*(unsigned int *)(HDR(self) + 0x34) & 0x800)) {
                *(float *)(m + 0x38C) += SPDU(self) * sp;
                if (SPDU(self) < 0.0f) {
                    if (*(float *)(m + 0x38C) < -1.0f)
                        *(float *)(m + 0x38C) += 1.0f;
                } else {
                    if (1.0f < *(float *)(m + 0x38C))
                        *(float *)(m + 0x38C) -= 1.0f;
                }
            } else {
                *(float *)(m + 0x38C) = capVu0Cos(Adjust_theta((float)(FRAME % 3600) * 0.017453292f * (SPDU(self) * sp))) * 0.5f;
            }
            if (!(*(unsigned int *)(HDR(self) + 0x34) & 0x400)) {
                *(float *)(m + 0x390) += SPDV(self) * sp;
                if (SPDV(self) < 0.0f) {
                    if (*(float *)(m + 0x390) < -1.0f)
                        *(float *)(m + 0x390) += 1.0f;
                } else {
                    if (1.0f < *(float *)(m + 0x390))
                        *(float *)(m + 0x390) -= 1.0f;
                }
            } else {
                *(float *)(m + 0x390) = capVu0Cos(Adjust_theta((float)((FRAME + 180) % 3600) * 0.017453292f * (SPDV(self) * sp))) * 0.5f;
            }
        }
    } else {
        n = GetField_2B1_14B638(self);
        for (i = 0; i < n; i++) {
            m = cModel_getMeshPtr(self, i);
            *(float *)(m + 0x38C) += SPDU(self) * sp;
            *(float *)(m + 0x390) += SPDV(self) * sp;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00319970);
#endif
