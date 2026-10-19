/* ee-2.9-991111: __start_cp_handler, gcc 2.95 exception.cc. caught is a word at 0x14
 * (int, so the store is sw) and handlers is a long at 0x20. */
struct __eh_info {
    void *match_function;
    short language;
    short version;
};

struct cp_eh_info {
    struct __eh_info eh_info;
    void *value;
    void *type;
    void (*cleanup)(void *, int);
    int caught;
    struct cp_eh_info *next;
    long handlers;
    void *original_value;
};

extern struct cp_eh_info **func_00320360(void);

__attribute__((section(".text.__start_cp_handler")))
struct cp_eh_info *__start_cp_handler(void)
{
    struct cp_eh_info *p = *func_00320360();
    p->caught = 1;
    p->handlers++;
    return p;
}
