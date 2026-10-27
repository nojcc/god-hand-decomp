/* ee-2.9-991111 */
/* func_0039C5B8 (libmpeg form_predictions): 447 of 449 words. Retail keeps
 * the constant 1 in s3 from entry and the average flag in s0; this C swaps
 * the two registers and sets the 1 again later in the backward block. */
#include "include_asm.h"

#ifdef NON_MATCHING

extern void _getRef0(void *s, void *ref, int top, int dstRow, int row, int rows,
                     int left, int col, int mvx, int mvy, int field, int avg);
extern void _dualPrimeVector(void *pic, int DMV[][2], int *dmvector, int mvx, int mvy);
extern void func_0039C3E8(void *mp, char *msg, int type);
extern char D_0045E640[];
extern char D_0045E660[];
extern char D_0045E680[];

/* Queue the forward and backward predictions of one macroblock (form_predictions). */
__attribute__((section(".text.func_0039C5B8")))
void func_0039C5B8(char *c, int bx, int by, int mbType, int motionType,
                   int PMV[2][2][2], int mvfs[2][2], int *dmvector)
{
    int DMV[2][2];
    int avg;

    avg = 0;
    *(int *)(c + *(int *)(c + 0x820) * 0x140 + 0x6CC) = 0;
    if ((mbType & 8) || *(int *)(c + 0x160) == 2) {
        if (*(int *)(c + 0x184) == 3) {
            if (motionType == 2 || !(mbType & 8)) {
                _getRef0(c, *(void **)(c + 0x1C8), 0, 0, 0, 16, bx, by,
                         PMV[0][0][0], PMV[0][0][1], 0, 0);
            } else if (motionType == 1) {
                _getRef0(c, *(void **)(c + 0x1C8), mvfs[0][0], 0, 0, 8, bx, by,
                         PMV[0][0][0], PMV[0][0][1] >> 1, 1, 0);
                _getRef0(c, *(void **)(c + 0x1C8), mvfs[1][0], 1, 0, 8, bx, by,
                         PMV[1][0][0], PMV[1][0][1] >> 1, 1, 0);
            } else if (motionType == 3) {
                _dualPrimeVector(c, DMV, dmvector, PMV[0][0][0], PMV[0][0][1] >> 1);
                _getRef0(c, *(void **)(c + 0x1C8), 0, 0, 0, 8, bx, by,
                         PMV[0][0][0], PMV[0][0][1] >> 1, 1, 0);
                _getRef0(c, *(void **)(c + 0x1C8), 1, 0, 0, 8, bx, by,
                         DMV[0][0], DMV[0][1], 1, 1);
                _getRef0(c, *(void **)(c + 0x1C8), 1, 1, 0, 8, bx, by,
                         PMV[0][0][0], PMV[0][0][1] >> 1, 1, 0);
                _getRef0(c, *(void **)(c + 0x1C8), 0, 1, 0, 8, bx, by,
                         DMV[1][0], DMV[1][1], 1, 1);
            } else {
                func_0039C3E8(c, D_0045E640, motionType);
            }
        } else {
            int field = *(int *)(c + 0x184) == 2;
            void *ref[2][2];
            int same;

            ref[0][0] = *(void **)(c + 0x1D8);
            ref[0][1] = *(void **)(c + 0x1E8);
            ref[1][0] = *(void **)(c + 0x1DC);
            ref[1][1] = *(void **)(c + 0x1EC);
            same = 0;
            if (*(int *)(c + 0x160) == 2 && *(int *)(c + 0x130) != 0)
                same = field != mvfs[0][0];
            if (motionType == 1 || !(mbType & 8)) {
                _getRef0(c, ref[same][mvfs[0][0]], 0, 0, 0, 16, bx, by,
                         PMV[0][0][0], PMV[0][0][1], 0, 0);
            } else if (motionType == 2) {
                _getRef0(c, ref[same][mvfs[0][0]], 0, 0, 0, 8, bx, by,
                         PMV[0][0][0], PMV[0][0][1], 0, 0);
                same = 0;
                if (*(int *)(c + 0x160) == 2 && *(int *)(c + 0x130) != 0
                    && field != mvfs[1][0])
                    same = 1;
                _getRef0(c, ref[same][mvfs[1][0]], 0, 0, 8, 8, bx, by,
                         PMV[1][0][0], PMV[1][0][1], 0, 0);
            } else if (motionType == 3) {
                same = 0;
                if (*(int *)(c + 0x130) != 0)
                    same = 1;
                _dualPrimeVector(c, DMV, dmvector, PMV[0][0][0], PMV[0][0][1]);
                _getRef0(c, ref[0][field], 0, 0, 0, 16, bx, by,
                         PMV[0][0][0], PMV[0][0][1], 0, 0);
                _getRef0(c, ref[same][!field], 0, 0, 0, 16, bx, by,
                         DMV[0][0], DMV[0][1], 0, 1);
            } else {
                func_0039C3E8(c, D_0045E660, motionType);
            }
        }
        avg = 1;
    }
    if (mbType & 4) {
        if (*(int *)(c + 0x184) == 3) {
            if (motionType == 2) {
                _getRef0(c, *(void **)(c + 0x1CC), 0, 0, 0, 16, bx, by,
                         PMV[0][1][0], PMV[0][1][1], 0, avg);
            } else {
                _getRef0(c, *(void **)(c + 0x1CC), mvfs[0][1], 0, 0, 8, bx, by,
                         PMV[0][1][0], PMV[0][1][1] >> 1, 1, avg);
                _getRef0(c, *(void **)(c + 0x1CC), mvfs[1][1], 1, 0, 8, bx, by,
                         PMV[1][1][0], PMV[1][1][1] >> 1, 1, avg);
            }
        } else if (motionType == 1) {
            _getRef0(c, mvfs[0][1] ? *(void **)(c + 0x1EC) : *(void **)(c + 0x1DC),
                     0, 0, 0, 16, bx, by, PMV[0][1][0], PMV[0][1][1], 0, avg);
        } else if (motionType == 2) {
            _getRef0(c, mvfs[0][1] ? *(void **)(c + 0x1EC) : *(void **)(c + 0x1DC),
                     0, 0, 0, 8, bx, by, PMV[0][1][0], PMV[0][1][1], 0, avg);
            _getRef0(c, mvfs[1][1] ? *(void **)(c + 0x1EC) : *(void **)(c + 0x1DC),
                     0, 0, 8, 8, bx, by, PMV[1][1][0], PMV[1][1][1], 0, avg);
        } else {
            func_0039C3E8(c, D_0045E680, motionType);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0039C5B8);
#endif
