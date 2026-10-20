/* NON_MATCHING func_00321F48 (ee-2.9-991111,jump-thread): libgcc frame.c find_fde. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern struct object *D_00755C18;

typedef struct dwarf_fde {
  unsigned int length;
  unsigned int CIE_delta;
  void *pc_begin;
  unsigned int pc_range;
} fde;

struct object {
  void *pc_begin;
  void *pc_end;
  struct dwarf_fde *fde_begin;
  struct dwarf_fde **fde_array;
  unsigned int count;
  struct object *next;
};

extern void func_00321E08(struct object *ob);

fde *func_00321F48(void *pc)
{
  struct object *ob;
  unsigned int lo, hi;

  for (ob = D_00755C18; ob; ob = ob->next)
    {
      if (ob->pc_begin == 0)
	func_00321E08 (ob);
      if (pc >= ob->pc_begin && pc < ob->pc_end)
	break;
    }

  if (ob == 0)
    return 0;

  for (lo = 0, hi = ob->count; lo < hi; )
    {
      unsigned int i = (lo + hi) / 2;
      fde *f = ob->fde_array[i];

      if (pc < f->pc_begin)
	hi = i;
      else if (pc >= f->pc_begin + f->pc_range)
	lo = i + 1;
      else
	return f;
    }

  return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00321F48);
#endif
