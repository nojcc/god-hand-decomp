/* cygnus-2.96 matched TU. */

extern void MWSFSVM_Error(char *s);
extern char D_004571D8[];



__attribute__((section(".text.mwPlyCalcWorkCprmSfd")))
int mwPlyCalcWorkCprmSfd(void *p)
{
    if (p == 0) {
        MWSFSVM_Error(D_004571D8);
        return 0;
    }
    return mwPlyCalcWorkSfd() + mwPlyCalcWorkCompo(p);
}
