/* halt demote func_001EDC28 */
#ifdef NON_MATCHING
extern CustomIDWork_ResetColorAnim(s32, s32);            /* extern */

__attribute__((section(".text.func_001EDC28")))

void func_001EDC28(int arg0, int arg1, int arg2) {
    int temp_a1;
    int temp_s0;
    int temp_s0_2;
    int temp_s0_3;

    temp_a1 = arg1 & 0xFF;
    if (temp_a1 != 1) {
        temp_s0 = arg0 + 0x250;
        switch (temp_a1) {                          /* irregular */
        default:
            CustomIDWork_ResetColorAnim(temp_s0, temp_a1);
            CustomIDWork_SetOffsetPosX(temp_s0, -0x190);
            func_001ED700(arg0, 4, 0);
            return;
        case 2:
            temp_s0_2 = arg0 + 0x250;
            CustomIDWork_SetColorAnimSin(temp_s0_2, (((((((M2C_ERROR(/* Read from unset register $v1 */) & 0xFFFFFF) | 0x80000000) & 0xFF00FFFF) | 0x800000) & 0xFFFF00FF) | 0x8000) & ~0xFF) | 0x80, (((((((arg2 & ~0xFF) | 0xD0) & 0xFFFF00FF) | 0xD000) & 0xFF00FFFF) | 0xD00000) & 0xFFFFFF) | 0x80000000, 6);
            CustomIDWork_SetMoveOffsetPosX(temp_s0_2, -0x190, 0, 0xC);
            goto block_7;
        case 3:
            CustomIDWork_SetMoveOffsetPosX(arg0 + 0x250, 0, 0x190, 8);
            func_001ED700(arg0, 4, 1);
            return;
        }
    } else {
        temp_s0_3 = arg0 + 0x250;
        CustomIDWork_ResetColorAnim(temp_s0_3, temp_a1);
        CustomIDWork_SetOffsetPosX(temp_s0_3, 0);
block_7:
        func_001ED700(arg0, 4, 1);
    }
}

#else
INCLUDE_ASM("nonmatching", func_001EDC28);
#endif
