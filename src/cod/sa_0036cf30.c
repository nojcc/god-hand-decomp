/* cygnus-2.96: func_0036CF30, fills the M2V decoder interface table (D_003F1FF4..D_003F2044) and
 * marks it initialised. */
typedef void (*Fn36CF30)(void);

extern int D_003F1FF0;
extern Fn36CF30 D_003F1FF4;
extern Fn36CF30 D_003F1FF8;
extern Fn36CF30 D_003F1FFC;
extern Fn36CF30 D_003F2000;
extern Fn36CF30 D_003F2004;
extern Fn36CF30 D_003F2008;
extern Fn36CF30 D_003F200C;
extern Fn36CF30 D_003F2010;
extern Fn36CF30 D_003F2014;
extern Fn36CF30 D_003F2018;
extern Fn36CF30 D_003F201C;
extern Fn36CF30 D_003F2020;
extern Fn36CF30 D_003F2024;
extern Fn36CF30 D_003F2028;
extern Fn36CF30 D_003F202C;
extern Fn36CF30 D_003F2030;
extern Fn36CF30 D_003F2034;
extern Fn36CF30 D_003F2038;
extern Fn36CF30 D_003F203C;
extern Fn36CF30 D_003F2040;
extern Fn36CF30 D_003F2044;

extern void Obj0000_Get_D_0045A478_36D0E8(void);
extern void func_0036D0F8(void);
extern void func_0036D1A8(void);
extern void func_0036D3D0(void);
extern void func_0036D3D8(void);
extern void M2V_Destroy(void);
extern void M2V_SetCond(void);
extern void func_0036D578(void);
extern void M2V_SetErrFunc(void);
extern void M2V_GetErrInf(void);
extern void func_0036DA28(void);
extern void func_0036D970(void);
extern void Obj0000_Set_Field_11C_Triple(void);
extern void func_0036DDC8(void);
extern void func_0036DDD8(void);
extern void func_0036DE00(void);
extern void func_0036DA80(void);
extern void func_0036DB80(void);
extern void func_0036DBE0(void);
extern void func_0036DC70(void);
extern void func_0036DA30(void);

__attribute__((section(".text.func_0036CF30")))
void func_0036CF30(void)
{
    D_003F1FF4 = (Fn36CF30)Obj0000_Get_D_0045A478_36D0E8;
    D_003F1FF8 = (Fn36CF30)func_0036D0F8;
    D_003F1FFC = (Fn36CF30)func_0036D1A8;
    D_003F2000 = (Fn36CF30)func_0036D3D0;
    D_003F2004 = (Fn36CF30)func_0036D3D8;
    D_003F2008 = (Fn36CF30)M2V_Destroy;
    D_003F200C = (Fn36CF30)M2V_SetCond;
    D_003F2010 = (Fn36CF30)func_0036D578;
    D_003F2014 = (Fn36CF30)M2V_SetErrFunc;
    D_003F2018 = (Fn36CF30)M2V_GetErrInf;
    D_003F201C = (Fn36CF30)func_0036DA28;
    D_003F2020 = (Fn36CF30)func_0036D970;
    D_003F2024 = (Fn36CF30)Obj0000_Set_Field_11C_Triple;
    D_003F2028 = (Fn36CF30)func_0036DDC8;
    D_003F202C = (Fn36CF30)func_0036DDD8;
    D_003F2030 = (Fn36CF30)func_0036DE00;
    D_003F2034 = (Fn36CF30)func_0036DA80;
    D_003F2038 = (Fn36CF30)func_0036DB80;
    D_003F203C = (Fn36CF30)func_0036DBE0;
    D_003F2040 = (Fn36CF30)func_0036DC70;
    D_003F2044 = (Fn36CF30)func_0036DA30;
    D_003F1FF0 = 1;
}
