#ifdef NON_MATCHING
int Getplayer(void);                                  /* extern */
s32 Obj0000_Get_Byte_17C3_NZ_2_276468(char *);      /* extern */
float Turn_dest(s32, s32, float, int);                    /* extern */
void cGameObj_SetTgtTurn(char *, void *, float);         /* extern */
void cObjBase_addNullSpeed(char *, int);                 /* extern */
void cObjBase_addNullSpeed_Rotation(char *, int);        /* extern */
void func_00262AA8(char *);                            /* extern */
s32 func_0026AA30(char *, int);                       /* extern */
void func_0026B240(char *, s32, int, int);                 /* extern */
void func_002705D8(char *);                            /* extern */
void func_002A8578(char *, void *, void *, int, int);      /* extern */
s32 moveMotion(char *);                             /* extern */

__attribute__((section(".text.func_00217560")))
void func_00217560(char *arg0) {
    float temp_f0;
    float temp_f1;
    float temp_f2;
    float var_f3;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s2;
    s32 temp_v0_10;
    s32 temp_v0_7;
    s32 temp_v0_9;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_a0;
    s32 var_v1;
    s8 var_v0;
    u8 temp_v0;
    u8 temp_v0_4;
    u8 temp_v1;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_8;

    temp_v1 = arg0->unk2F6;
    switch (temp_v1) {                              /* irregular */
    case 0:
        temp_s2 = Obj0000_Get_Byte_17C3_NZ_2_276468(arg0) & 0xFFFF;
        temp_s0 = Getplayer()->unkF0;
        temp_v1_2 = arg0->unk564;
        temp_f2 = Turn_dest(temp_s0, arg0->unkF0, Getplayer()->unk104, 0x40490FDB);
        if ((temp_v1_2 != 0x256) && (temp_v1_2 != 0x27E)) {
            temp_v0 = arg0->unk17C3;
            if (temp_f2 > 0.0f) {
                temp_v0_2 = arg0->unk304;
                if (temp_v0 != 0) {
                    var_v1 = temp_v0_2->unk1670;
                    var_a0 = temp_v0_2->unk1674;
                } else {
                    var_v1 = temp_v0_2->unk1660;
                    var_a0 = temp_v0_2->unk1664;
                }
            } else {
                temp_v0_3 = arg0->unk304;
                if (temp_v0 != 0) {
                    var_v1 = temp_v0_3->unk1660;
                    var_a0 = temp_v0_3->unk1664;
                } else {
                    var_v1 = temp_v0_3->unk1670;
                    var_a0 = temp_v0_3->unk1674;
                }
            }
        } else {
            temp_v0_4 = arg0->unk17C3;
            if (temp_f2 > 0.0f) {
                temp_v0_5 = arg0->unk304;
                if (temp_v0_4 == 0) {
                    var_v1 = temp_v0_5->unk25C4;
                    var_a0 = temp_v0_5->unk25C8;
                } else {
                    goto block_23;
                }
            } else {
                temp_v0_6 = arg0->unk304;
                if (temp_v0_4 != 0) {
                    var_v1 = temp_v0_6->unk25C4;
                    var_a0 = temp_v0_6->unk25C8;
                } else {
block_23:
                    var_v1 = arg0->unk304->unk25BC;
                    var_a0 = arg0->unk304->unk25C0;
                }
            }
        }
        func_002A8578(arg0, var_v1 + arg0->unk304, var_a0 + arg0->unk304, 3, 0);
        arg0->unk54C = 5.0f;
        arg0->unk2F6 = (u8) (arg0->unk2F6 + 1);
        /* fallthrough */
    case 1:
        cGameObj_SetTgtTurn(arg0, arg0 + 0x16A0, arg0->unk5A8 * 0.09817477f);
        if (moveMotion(arg0) != 0) {
            func_002705D8(arg0);
        }
        cObjBase_addNullSpeed_Rotation(arg0, 0x3F800000);
        cObjBase_addNullSpeed(arg0, 0x3F800000);
        if (arg0->unk3AC & 0x10) {
            temp_v1_3 = arg0->unk564;
            if ((temp_v1_3 != 0x256) && (temp_v1_3 != 0x27E)) {
                temp_s0_2 = Getplayer()->unkF0;
                temp_f0 = Turn_dest(temp_s0_2, arg0->unkF0, Getplayer()->unk104, 0x40490FDB);
                var_f3 = temp_f0;
                if (temp_f0 < 0.0f) {
                    var_f3 = -temp_f0;
                }
                if (var_f3 < 0.5235988f) {
                    arg0->unk2F6 = 2U;
                }
            } else {
                temp_f1 = arg0->unk618;
                var_v0 = 0x16;
                if ((temp_f1 < 4.0f) || (var_v0 = 0x17, (temp_f1 < 25.0f))) {
                    arg0->unk2F7 = 0;
                    arg0->unk2F5 = var_v0;
                    arg0->unk2F4 = 0;
                    arg0->unk2F6 = 0U;
                } else {
                    func_00262AA8(arg0);
                }
            }
        }
        return;
    case 2:
        temp_v0_7 = Obj0000_Get_Byte_17C3_NZ_2_276468(arg0);
        arg0->unk1864 = 0U;
        temp_s0_3 = Getplayer()->unkF0;
        Turn_dest(temp_s0_3, arg0->unkF0, Getplayer()->unk104, 0x40490FDB);
        temp_v0_8 = arg0->unk304;
        func_002A8578(arg0, temp_v0_8->unk1668 + temp_v0_8, temp_v0_8->unk166C + temp_v0_8, 3, 0);
        arg0->unk2F6 = (u8) (arg0->unk2F6 + 1);
        /* fallthrough */
    case 3:
        cGameObj_SetTgtTurn(arg0, arg0 + 0x16A0, arg0->unk5A8 * 0.09817477f);
        if (moveMotion(arg0) != 0) {
            func_002705D8(arg0);
        }
        cObjBase_addNullSpeed_Rotation(arg0, 0x3F800000);
        cObjBase_addNullSpeed(arg0, 0x3F800000);
        if ((arg0->unk3AC & 3) && (arg0->unk1864 == 0)) {
            arg0->unk1864 = 1U;
            temp_v0_9 = func_0026AA30(arg0, 0x365);
            if (temp_v0_9 != 0) {
                func_0026B240(arg0, temp_v0_9, 0x365, 0xA);
            }
            temp_v0_10 = func_0026AA30(arg0, 0x365);
            if (temp_v0_10 != 0) {
                func_0026B240(arg0, temp_v0_10, 0x365, 0x10);
            }
        }
        break;
    }
}

#else
INCLUDE_ASM("nonmatching", func_00217560);
#endif
