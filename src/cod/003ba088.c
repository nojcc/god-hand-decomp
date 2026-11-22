/* cygnus-2.96 */

extern void func_003B9DE0(void *);
extern char D_00460928[];

__attribute__((section(".text.AC3CNV_TermSupply")))
void AC3CNV_TermSupply(char *self)
{
    if (self == 0) {
        func_003B9DE0(D_00460928);
        return;
    }
    *(int *)(self + 0x24) = 1;
}
