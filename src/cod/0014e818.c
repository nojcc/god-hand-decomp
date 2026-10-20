#ifdef NON_MATCHING
float Adjust_theta(float);                              /* extern */
float capVu0Atan2(float, float);                          /* extern */
__attribute__((section(".text.func_0014E818")))

void func_0014E818(void *arg0, float fparg0) {
    ? sp10;
    float temp_f0;
    float temp_f0_2;
    float var_f1;

    M2C_ERROR(/* unknown instruction: sqc2 $vf0, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($a1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($v1) */);
    M2C_ERROR(/* unknown instruction: vsub.xyz $vf4, $vf4, $vf5 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($v0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($sp) */);
    temp_f0 = Adjust_theta(capVu0Atan2(sp0, sp8) - arg0->unk104);
    var_f1 = -fparg0;
    if (!(temp_f0 < var_f1)) {
        var_f1 = temp_f0;
        if (fparg0 < temp_f0) {
            var_f1 = fparg0;
        }
    }
    temp_f0_2 = arg0->unk104 + var_f1;
    arg0->unk104 = temp_f0_2;
    arg0->unk104 = Adjust_theta(temp_f0_2);
}

#else
INCLUDE_ASM("nonmatching", func_0014E818);
#endif
