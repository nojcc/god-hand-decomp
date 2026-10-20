/* cygnus-2.96: func_0036CF30, fills the M2V decoder interface table (D_003F1FF4..D_003F2044) and
 * marks it initialised. */
typedef void (*M2vIfFn)(void);

extern int D_003F1FF0;
extern M2vIfFn D_003F1FF4;
extern M2vIfFn D_003F1FF8;
extern M2vIfFn D_003F1FFC;
extern M2vIfFn D_003F2000;
extern M2vIfFn D_003F2004;
extern M2vIfFn D_003F2008;
extern M2vIfFn D_003F200C;
extern M2vIfFn D_003F2010;
extern M2vIfFn D_003F2014;
extern M2vIfFn D_003F2018;
extern M2vIfFn D_003F201C;
extern M2vIfFn D_003F2020;
extern M2vIfFn D_003F2024;
extern M2vIfFn D_003F2028;
extern M2vIfFn D_003F202C;
extern M2vIfFn D_003F2030;
extern M2vIfFn D_003F2034;
extern M2vIfFn D_003F2038;
extern M2vIfFn D_003F203C;
extern M2vIfFn D_003F2040;
extern M2vIfFn D_003F2044;

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
    D_003F1FF4 = (M2vIfFn)Obj0000_Get_D_0045A478_36D0E8;
    D_003F1FF8 = (M2vIfFn)func_0036D0F8;
    D_003F1FFC = (M2vIfFn)func_0036D1A8;
    D_003F2000 = (M2vIfFn)func_0036D3D0;
    D_003F2004 = (M2vIfFn)func_0036D3D8;
    D_003F2008 = (M2vIfFn)M2V_Destroy;
    D_003F200C = (M2vIfFn)M2V_SetCond;
    D_003F2010 = (M2vIfFn)func_0036D578;
    D_003F2014 = (M2vIfFn)M2V_SetErrFunc;
    D_003F2018 = (M2vIfFn)M2V_GetErrInf;
    D_003F201C = (M2vIfFn)func_0036DA28;
    D_003F2020 = (M2vIfFn)func_0036D970;
    D_003F2024 = (M2vIfFn)Obj0000_Set_Field_11C_Triple;
    D_003F2028 = (M2vIfFn)func_0036DDC8;
    D_003F202C = (M2vIfFn)func_0036DDD8;
    D_003F2030 = (M2vIfFn)func_0036DE00;
    D_003F2034 = (M2vIfFn)func_0036DA80;
    D_003F2038 = (M2vIfFn)func_0036DB80;
    D_003F203C = (M2vIfFn)func_0036DBE0;
    D_003F2040 = (M2vIfFn)func_0036DC70;
    D_003F2044 = (M2vIfFn)func_0036DA30;
    D_003F1FF0 = 1;
}
