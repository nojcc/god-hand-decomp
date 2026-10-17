/* halt demote func_00208858 */
#ifdef NON_MATCHING
s32 ClearAndResetFields_1FE278(char *, s32);           /* extern */
void NoOp_208260();                                    /* extern */
void ReleaseObj(s32);                                  /* extern */
void cCollisionSolidManage_ReleaseUnit(char *, void *);   /* extern */
s32 cDamageManage_ReleaseDamageGive(char *, s32);      /* extern */
void cOmBase_dieCommon(s32);                           /* extern */
void func_002714B0(char *);                            /* extern */
extern void D_00462FC0;
extern void D_00574380;

__attribute__((section(".text.func_00208858")))
void func_00208858(char *arg0) {
    s32 *var_s0;
    s32 *var_v0;
    s32 temp_a0;
    s32 temp_a0_10;
    s32 temp_a0_11;
    s32 temp_a0_12;
    s32 temp_a0_13;
    s32 temp_a0_14;
    s32 temp_a0_15;
    s32 temp_a0_16;
    s32 temp_a0_17;
    s32 temp_a0_18;
    s32 temp_a0_19;
    s32 temp_a0_20;
    s32 temp_a0_21;
    s32 temp_a0_22;
    s32 temp_a0_23;
    s32 temp_a0_24;
    s32 temp_a0_25;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_a0_6;
    s32 temp_a0_7;
    s32 temp_a0_8;
    s32 temp_a0_9;
    s32 var_s2;
    s32 var_s2_2;

    NoOp_208260();
    func_002714B0(arg0);
    if (ClearAndResetFields_1FE278(&D_00574380, arg0->unk698) != 0) {
        arg0->unk698 = 0;
        var_s2 = 4;
        var_v0 = arg0 + 0x6AC;
        do {
            *var_v0 = -1;
            var_s2 -= 1;
            var_v0 -= 4;
        } while (var_s2 >= 0);
    }
    if (cDamageManage_ReleaseDamageGive(&D_00574380, arg0->unk670) != 0) {
        arg0->unk670 = 0;
        arg0->unk674 = -1;
    }
    if (cDamageManage_ReleaseDamageGive(&D_00574380, arg0->unk678) != 0) {
        arg0->unk678 = 0;
        arg0->unk67C = -1;
    }
    if (cDamageManage_ReleaseDamageGive(&D_00574380, arg0->unk680) != 0) {
        arg0->unk680 = 0;
        arg0->unk684 = -1;
    }
    if (cDamageManage_ReleaseDamageGive(&D_00574380, arg0->unk688) != 0) {
        arg0->unk688 = 0;
        arg0->unk68C = -1;
    }
    if (cDamageManage_ReleaseDamageGive(&D_00574380, arg0->unk690) != 0) {
        arg0->unk690 = 0;
        arg0->unk694 = -1;
    }
    temp_a0 = arg0->unk6EC;
    if (temp_a0 != 0) {
        cOmBase_dieCommon(temp_a0);
        arg0->unk6EC = 0;
    }
    temp_a0_2 = arg0->unk6F0;
    if (temp_a0_2 != 0) {
        cOmBase_dieCommon(temp_a0_2);
        arg0->unk6F0 = 0;
    }
    temp_a0_3 = arg0->unk6F8;
    if (temp_a0_3 != 0) {
        cOmBase_dieCommon(temp_a0_3);
        arg0->unk6F8 = 0;
    }
    temp_a0_4 = arg0->unk6FC;
    if (temp_a0_4 != 0) {
        cOmBase_dieCommon(temp_a0_4);
        arg0->unk6FC = 0;
    }
    temp_a0_5 = arg0->unk700;
    if (temp_a0_5 != 0) {
        cOmBase_dieCommon(temp_a0_5);
        arg0->unk700 = 0;
    }
    temp_a0_6 = arg0->unk704;
    if (temp_a0_6 != 0) {
        cOmBase_dieCommon(temp_a0_6);
        arg0->unk704 = 0;
    }
    temp_a0_7 = arg0->unk708;
    if (temp_a0_7 != 0) {
        cOmBase_dieCommon(temp_a0_7);
        arg0->unk708 = 0;
    }
    temp_a0_8 = arg0->unk734;
    if (temp_a0_8 != 0) {
        cOmBase_dieCommon(temp_a0_8);
        arg0->unk734 = 0;
    }
    temp_a0_9 = arg0->unk6F4;
    if (temp_a0_9 != 0) {
        cOmBase_dieCommon(temp_a0_9);
        arg0->unk6F4 = 0;
    }
    temp_a0_10 = arg0->unk70C;
    if (temp_a0_10 != 0) {
        cOmBase_dieCommon(temp_a0_10);
        arg0->unk70C = 0;
    }
    temp_a0_11 = arg0->unk730;
    if (temp_a0_11 != 0) {
        cOmBase_dieCommon(temp_a0_11);
        arg0->unk730 = 0;
    }
    temp_a0_12 = arg0->unk738;
    if (temp_a0_12 != 0) {
        cOmBase_dieCommon(temp_a0_12);
        arg0->unk738 = 0;
    }
    temp_a0_13 = arg0->unk1964;
    if (temp_a0_13 != 0) {
        ReleaseObj(temp_a0_13);
        arg0->unk1964 = 0;
    }
    temp_a0_14 = arg0->unk1968;
    if (temp_a0_14 != 0) {
        ReleaseObj(temp_a0_14);
        arg0->unk1968 = 0;
    }
    temp_a0_15 = arg0->unk196C;
    if (temp_a0_15 != 0) {
        ReleaseObj(temp_a0_15);
        arg0->unk196C = 0;
    }
    temp_a0_16 = arg0->unk1970;
    if (temp_a0_16 != 0) {
        ReleaseObj(temp_a0_16);
        arg0->unk196C = 0;
    }
    temp_a0_17 = arg0->unk1974;
    if (temp_a0_17 != 0) {
        ReleaseObj(temp_a0_17);
        arg0->unk196C = 0;
    }
    temp_a0_18 = arg0->unk196C;
    if (temp_a0_18 != 0) {
        ReleaseObj(temp_a0_18);
        arg0->unk196C = 0;
    }
    temp_a0_19 = arg0->unk73C;
    if (temp_a0_19 != 0) {
        ReleaseObj(temp_a0_19);
        arg0->unk73C = 0;
    }
    temp_a0_20 = arg0->unk740;
    if (temp_a0_20 != 0) {
        ReleaseObj(temp_a0_20);
        arg0->unk740 = 0;
    }
    temp_a0_21 = arg0->unk744;
    if (temp_a0_21 != 0) {
        ReleaseObj(temp_a0_21);
        arg0->unk744 = 0;
    }
    temp_a0_22 = arg0->unk748;
    if (temp_a0_22 != 0) {
        ReleaseObj(temp_a0_22);
        arg0->unk748 = 0;
    }
    temp_a0_23 = arg0->unk74C;
    if (temp_a0_23 != 0) {
        ReleaseObj(temp_a0_23);
        arg0->unk74C = 0;
    }
    temp_a0_24 = arg0->unk750;
    var_s0 = arg0 + 0x754;
    if (temp_a0_24 != 0) {
        ReleaseObj(temp_a0_24);
        arg0->unk750 = 0;
    }
    var_s2_2 = 1;
    do {
        temp_a0_25 = *var_s0;
        var_s2_2 -= 1;
        if (temp_a0_25 != 0) {
            ReleaseObj(temp_a0_25);
            *var_s0 = 0;
        }
        var_s0 += 4;
    } while (var_s2_2 >= 0);
    cCollisionSolidManage_ReleaseUnit(&D_00462FC0, arg0);
}

#else
INCLUDE_ASM("nonmatching", func_00208858);
#endif
