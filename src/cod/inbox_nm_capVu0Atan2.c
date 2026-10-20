#ifdef NON_MATCHING
__attribute__((section(".text.capVu0Atan2")))
float capVu0Atan2(float fparg0, float fparg1) {
    float temp_f0;
    float var_f0;
    float var_f1;

    temp_f0 = fabsf(fparg0);
    if (fabsf(fparg1) < 0.00001f) {
        if (temp_f0 < 0.00001f) {
            return 0.0f;
        }
        var_f0 = -1.5707964f;
        if (!(fparg0 < 0.0f)) {
            return 1.5707964f;
        }
        /* Duplicate return node #16.
 * Try simplifying control flow for better match */
        return var_f0;
    }
    if (temp_f0 < 0.00001f) {
        var_f0 = 0.0f;
        if (fparg1 < 0.0f) {
            var_f0 = -3.1415927f;
            if (!(fparg0 < 0.0f)) {
                return 3.1415927f;
            }
        }
        /* Duplicate return node #16.
 * Try simplifying control flow for better match */
        return var_f0;
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x20($v0) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $t0, $vf7 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $t1, $vf8 */);
    M2C_ERROR(/* unknown instruction: vadd.x $vf9, $vf7, $vf8 */);
    M2C_ERROR(/* unknown instruction: vsub.x $vf8, $vf8, $vf7 */);
    M2C_ERROR(/* unknown instruction: vdiv $q, $vf8x, $vf9x */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf7, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: vmul.x $vf8, $vf7, $vf7 */);
    M2C_ERROR(/* unknown instruction: vmulax.x $acc, $vf7, $vf4x */);
    M2C_ERROR(/* unknown instruction: vmul.x $vf7, $vf7, $vf8 */);
    M2C_ERROR(/* unknown instruction: vmadday.x $acc, $vf7, $vf4y */);
    M2C_ERROR(/* unknown instruction: vmul.x $vf7, $vf7, $vf8 */);
    M2C_ERROR(/* unknown instruction: vmaddaz.x $acc, $vf7, $vf4z */);
    M2C_ERROR(/* unknown instruction: vmul.x $vf7, $vf7, $vf8 */);
    M2C_ERROR(/* unknown instruction: vmaddaw.x $acc, $vf7, $vf4w */);
    M2C_ERROR(/* unknown instruction: vmul.x $vf7, $vf7, $vf8 */);
    M2C_ERROR(/* unknown instruction: vmaddax.x $acc, $vf7, $vf5x */);
    M2C_ERROR(/* unknown instruction: vmul.x $vf7, $vf7, $vf8 */);
    M2C_ERROR(/* unknown instruction: vmadday.x $acc, $vf7, $vf5y */);
    M2C_ERROR(/* unknown instruction: vmul.x $vf7, $vf7, $vf8 */);
    M2C_ERROR(/* unknown instruction: vmaddaz.x $acc, $vf7, $vf5z */);
    M2C_ERROR(/* unknown instruction: vmul.x $vf7, $vf7, $vf8 */);
    M2C_ERROR(/* unknown instruction: vmaddaw.x $acc, $vf7, $vf5w */);
    M2C_ERROR(/* unknown instruction: vmaddw.x $vf7, $vf6, $vf0w */);
    var_f1 = M2C_ERROR(/* unknown instruction: qmfc2.ni $t0, $vf7 */);
    if (fparg1 < 0.0f) {
        if (fparg0 < 0.0f) {
            var_f1 -= 3.1415927f;
        } else {
            var_f1 = 3.1415927f - var_f1;
        }
    } else if (fparg0 < 0.0f) {
        var_f1 = -var_f1;
    }
    var_f0 = var_f1;
    return var_f0;
}

#else
INCLUDE_ASM("nonmatching", capVu0Atan2);
#endif
