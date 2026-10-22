/* cygnus-2.96 */

#define ADXT_MAX_OBJ        16
#define ADXT_OBJ_SIZE       0xC8

extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void func_003276A8(void);
extern void func_0032CFC8(signed char *adxt);
extern void Obj3260_Tramp_00338638_D390(void);
extern volatile int D_003D140C;
extern int D_003D1414;
extern signed char D_003C7420[];

/* ADXT server tick: unless a tick is already running, run the stream servers, then every
 * handle in use, then the file server (twice below 51), recording the stage in D_003D140C. */
__attribute__((section(".text.func_0032AFB0")))
void func_0032AFB0(void)
{
    signed char *adxt;
    int i;

    Forward33B658_33E678();
    if (D_003D140C != 0) {
        Forward33B670_33E690();
        return;
    }
    D_003D140C = 1;
    Forward33B670_33E690();
    Forward33B658_33E678();
    func_003276A8();
    D_003D140C = 2;
    for (i = 0, adxt = D_003C7420; i < ADXT_MAX_OBJ; i++, adxt += ADXT_OBJ_SIZE) {
        if (adxt[0] == 1) {
            func_0032CFC8(adxt);
        }
    }
    D_003D140C = 3;
    Obj3260_Tramp_00338638_D390();
    if (D_003D1414 < 0x33) {
        Obj3260_Tramp_00338638_D390();
    }
    D_003D140C = 0;
    Forward33B670_33E690();
}
