/* cygnus-2.96. stat at 0x2D4; MWSFSVM_Error is noreturn so the
 * failing path is an if/else-if tail. */
typedef struct Mwsf3448B0 {
    char pad[0x2D4];
    int stat;
} Mwsf3448B0;

extern char D_00457830[];
extern void MWSFSVM_Error(char *s) __attribute__((noreturn));

__attribute__((section(".text.func_003448B0")))
void func_003448B0(Mwsf3448B0 *m, int stat)
{
    if (m->stat == 0)
        m->stat = stat;
    else if (m->stat != stat)
        MWSFSVM_Error(D_00457830);
}
