#ifdef NON_MATCHING
? cDamageUnit_SetDamageCollActive(int, ?);          /* extern */
__attribute__((section(".text.cOl0e_setFake")))

void cOl0e_setFake(void *arg0, signed char arg1) {
    int temp_4;
    int temp_4_3;
    int var_2;
    void *temp_3;
    void *temp_4_2;

    if ((((s64) arg0->unk5B0 >> 1) & 1) != 1) {
        arg0->unkD9B = arg1;
        if (arg1 == 1) {
            temp_4 = arg0->unk600;
            if (temp_4 != 0) {
                cDamageUnit_SetDamageCollActive(temp_4, 0);
            }
            temp_4_2 = arg0->unkDA8;
            if (temp_4_2 != NULL) {
                temp_4_2->unk8 = (int) (temp_4_2->unk8 & ~1);
            }
            arg0->unk2F4 = arg1;
            var_2 = arg0->unk5B8 & ~0x100;
        } else {
            temp_4_3 = arg0->unk600;
            if (temp_4_3 != 0) {
                cDamageUnit_SetDamageCollActive(temp_4_3, 1);
            }
            temp_3 = arg0->unkDA8;
            if (temp_3 != NULL) {
                temp_3->unk8 = (int) (temp_3->unk8 | 1);
            }
            arg0->unk2F4 = 0;
            var_2 = arg0->unk5B8 | 0x100;
        }
        arg0->unk2F5 = 0;
        arg0->unk5B8 = var_2;
        arg0->unk2F6 = 0;
        arg0->unk2F7 = 0;
        arg0->unk24C = 1.0f;
    }
}

#else
INCLUDE_ASM("nonmatching", cOl0e_setFake);
#endif
