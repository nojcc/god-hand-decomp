/* Cygnus exception helper requiring original non-reordered block layout. */

typedef struct {
    int words[5];
    int caught;
} PhaseAEhInfo;

extern PhaseAEhInfo **func_00320360(void);
extern void terminate(void) __attribute__((noreturn));

__attribute__((section(".text.__uncatch_exception")))
void __uncatch_exception(void)
{
    PhaseAEhInfo *info = *func_00320360();
    if (info == 0)
        terminate();
    info->caught = 0;
}
