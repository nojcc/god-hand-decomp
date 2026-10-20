/* NON_MATCHING __deregister_frame_info (ee-2.9-991111;
* Search and free match
prologue schedule and bnel vs bne. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern struct object *D_00755C18;

struct dwarf_fde;
struct object {
    void *pc_begin;
    void *pc_end;
    struct dwarf_fde *fde_begin;
    struct dwarf_fde **fde_array;
    unsigned int count;
    struct object *next;
};

extern void UpdateGlobalPtrWithParam_3A7CC0(void *);
extern void func_003A7B48(void) __attribute__((noreturn));

void *__deregister_frame_info(void *begin)
{
    struct object **p = &D_00755C18;
    struct object *ob;

    while ((ob = *p) != 0) {
        if (ob->fde_begin == begin) {
            *p = ob->next;
            if (ob->pc_begin)
                UpdateGlobalPtrWithParam_3A7CC0(ob->fde_array);
            return ob;
        }
        p = &ob->next;
    }
    func_003A7B48();
}
#else
INCLUDE_ASM("asm/nonmatching", __deregister_frame_info);
#endif
