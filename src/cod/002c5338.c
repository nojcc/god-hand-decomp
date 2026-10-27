/* sn-2.95.3-136 */
#include "godhand/cVec.h"

/* The class whose base constructor is func_002D50C0; the vtable pointer sits at 0x30. */
typedef struct StaticPart {
    char unk00[0x30];
    char *vtbl;                         /* 0x30 */
} StaticPart;

/* The file-scope object at D_005FEB00. */
typedef struct StaticObj {
    cVec unk00;                         /* 0x00 */
    char unk10[0xC];
    StaticPart part;                    /* 0x1C */
} StaticObj;

extern void *func_002D50C0(void *a0);
extern StaticObj D_005FEB00;
extern char D_0044D1A8[];

/* The derived constructor: the base constructor, then the derived vtable. */
static __inline__ void StaticPart_construct(StaticPart *self)
{
    func_002D50C0(self);
    self->vtbl = D_0044D1A8;
}

/* The object's constructor: a zeroed vector, then the part at 0x1C. */
static __inline__ void StaticObj_construct(StaticObj *self)
{
    CVEC_ZERO(self->unk00);
    StaticPart_construct(&self->part);
}

/* Static initializer: constructs D_005FEB00 at the default priority. */
__attribute__((section(".text.func_002C5338")))
void func_002C5338(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize != 0) {
        StaticObj_construct(&D_005FEB00);
    }
}
