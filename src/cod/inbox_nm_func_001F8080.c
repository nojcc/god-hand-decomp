#ifdef NON_MATCHING
__attribute__((section(".text.func_001F8080")))
void func_001F8080(float fparg0) {
    int var_a3;

    if (fparg0 < 0.0f) {
        var_a3 = 1;
    } else {
        var_a3 = 0;
    }
    M2C_ERROR(/* unknown instruction: qmtc2.ni $t0, $vf6 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($t0) */);
    M2C_ERROR(/* unknown instruction: vmr32.w $vf6, $vf6 */);
    M2C_ERROR(/* unknown instruction: vaddx.x $vf4, $vf0, $vf6x */);
    M2C_ERROR(/* unknown instruction: vmul.x $vf6, $vf6, $vf6 */);
    M2C_ERROR(/* unknown instruction: vmulx.yzw $vf4, $vf4, $vf0x */);
    M2C_ERROR(/* unknown instruction: vmulw.xyzw $vf8, $vf5, $vf6w */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf5, $vf0, $vf0 */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf8, $vf8, $vf6x */);
    M2C_ERROR(/* unknown instruction: vmulx.xyz $vf8, $vf8, $vf6x */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf4, $vf8w */);
    M2C_ERROR(/* unknown instruction: vmulx.xy $vf8, $vf8, $vf6x */);
    M2C_ERROR(/* unknown instruction: vaddz.x $vf4, $vf4, $vf8z */);
    M2C_ERROR(/* unknown instruction: vmulx.x $vf8, $vf8, $vf6x */);
    M2C_ERROR(/* unknown instruction: vaddy.x $vf4, $vf4, $vf8y */);
    M2C_ERROR(/* unknown instruction: vaddx.x $vf4, $vf4, $vf8x */);
    M2C_ERROR(/* unknown instruction: vaddx.xy $vf4, $vf5, $vf4x */);
    M2C_ERROR(/* unknown instruction: vmul.x $vf7, $vf4, $vf4 */);
    M2C_ERROR(/* unknown instruction: vsubx.w $vf7, $vf0, $vf7x */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf7, $vf0, $q */);
    if (var_a3 == 0) {
        M2C_ERROR(/* unknown instruction: vaddx.x $vf4, $vf5, $vf7x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($a0) */);
        return;
    }
    M2C_ERROR(/* unknown instruction: vsubx.x $vf4, $vf5, $vf7x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($a0) */);
}

#else
INCLUDE_ASM("nonmatching", func_001F8080);
#endif
