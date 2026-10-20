/* func_0030A5D0 */
#ifdef NON_MATCHING

__attribute__((section(".text.func_0030A5D0")))
void func_0030A5D0(int arg3) {
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
    if (arg3 == 0) {
        M2C_ERROR(/* unknown instruction: vaddx.x $vf4, $vf5, $vf7x */);
        return;
    }
    M2C_ERROR(/* unknown instruction: vsubx.x $vf4, $vf5, $vf7x */);
}

#else
INCLUDE_ASM("nonmatching", func_0030A5D0);
#endif
