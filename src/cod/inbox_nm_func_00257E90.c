/* halt demote func_00257E90 */
#ifdef NON_MATCHING
void Obj0000_Get_Byte_17C3_NZ_2_276468(char *);        /* extern */
void cObjBase_addNullSpeed(char *, void);                 /* extern */
void cObjBase_addNullSpeed_Rotation(char *, void);        /* extern */
void cSnd_SeCall_2CBA48(char *, void, void, void *);            /* extern */
s32 func_0026F1D8(char *);                          /* extern */
void func_002705D8(char *);                            /* extern */
void func_00270C78(char *);                            /* extern */
void func_002A8578(char *, s32, s32, void, void);            /* extern */
u32 irand();                                        /* extern */
s32 moveMotion(char *);                             /* extern */
extern void D_005FEE00;

__attribute__((section(".text.func_00257E90")))
void func_00257E90(char *arg0) {
    s32 temp_v0_3;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_v1;
    s32 var_v1_2;
    u8 temp_v1;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_4;
    void *temp_v0_5;

    temp_v1 = arg0->unk2F6;
    switch (temp_v1) {                              /* irregular */
    case 0:
        Obj0000_Get_Byte_17C3_NZ_2_276468(arg0);
        if (arg0->unk3AC & 0x200) {
            temp_v0 = arg0->unk304;
            var_v1 = temp_v0->unk1CE8;
            var_a0 = temp_v0->unk1CEC;
        } else {
            temp_v0_2 = arg0->unk304;
            var_v1 = temp_v0_2->unk1CF0;
            var_a0 = temp_v0_2->unk1CF4;
        }
        func_002A8578(arg0, var_v1 + arg0->unk304, var_a0 + arg0->unk304, 3, 0);
        if (irand() & 1) {
            arg0->unk5F0 = 5;
        } else {
            arg0->unk5F0 = (s32) ((irand() % 90U) + 0x1E);
        }
        arg0->unk2F6 = (u8) (arg0->unk2F6 + 1);
        /* fallthrough */
    case 1:
        moveMotion(arg0);
        temp_v0_3 = arg0->unk5F0;
        if (temp_v0_3 > 0) {
            arg0->unk5F0 = (s32) (temp_v0_3 - 1);
        } else {
            arg0->unk2F6 = 2U;
        }
        cObjBase_addNullSpeed_Rotation(arg0, 0x3F800000);
        cObjBase_addNullSpeed(arg0, 0x3F800000);
        return;
    case 2:
        Obj0000_Get_Byte_17C3_NZ_2_276468(arg0);
        if (arg0->unk3AC & 0x200) {
            temp_v0_4 = arg0->unk304;
            var_v1_2 = temp_v0_4->unk1D40;
            var_a0_2 = temp_v0_4->unk1D44;
        } else {
            temp_v0_5 = arg0->unk304;
            var_v1_2 = temp_v0_5->unk1D48;
            var_a0_2 = temp_v0_5->unk1D4C;
        }
        func_002A8578(arg0, var_v1_2 + arg0->unk304, var_a0_2 + arg0->unk304, 3, 0);
        arg0->unk2F6 = (u8) (arg0->unk2F6 + 1);
        /* fallthrough */
    case 3:
        if (moveMotion(arg0) != 0) {
            if (func_0026F1D8(arg0) != 0) {
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x8C, arg0);
                func_00270C78(arg0);
            } else {
                func_002705D8(arg0);
            }
        }
        cObjBase_addNullSpeed_Rotation(arg0, 0x3F800000);
        cObjBase_addNullSpeed(arg0, 0x3F800000);
        return;
    }
}

#else
INCLUDE_ASM("nonmatching", func_00257E90);
#endif
