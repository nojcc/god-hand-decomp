/* ee-2.9-991111 */
/* __deregister_frame_info: unlink the registered EH frame object whose FDE table starts at begin, free its
 * sorted FDE array and return it; abort if it was never registered (libgcc frame.c, ee-2.9-991111) */

struct dwarf_fde;

struct object {
    void *pc_begin;
    void *pc_end;
    struct dwarf_fde *fde_begin;
    struct dwarf_fde **fde_array;
    unsigned int count;
    struct object *next;
};

extern struct object *D_00755C18;

extern void UpdateGlobalPtrWithParam_3A7CC0(void *);
extern void func_003A7B48(void) __attribute__((noreturn));

__attribute__((section(".text.__deregister_frame_info")))
void *__deregister_frame_info(void *begin)
{
    struct object **ob;

    ob = &D_00755C18;
    while (*ob) {
        if ((*ob)->fde_begin == begin) {
            struct object *r = *ob;
            *ob = (*ob)->next;

            if (r->pc_begin)
                UpdateGlobalPtrWithParam_3A7CC0(r->fde_array);

            return (void *)r;
        }
        ob = &(*ob)->next;
    }

    func_003A7B48();
}
