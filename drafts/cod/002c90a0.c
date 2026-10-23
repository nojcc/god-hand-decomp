/* NON_MATCHING func_002C90A0 (sn-2.95.3-136, extern_jtbl D_0044CC50): same length as retail. Two things differ:
 * self and the &D_00569B70 temporaries swap s1/s2 throughout, and retail tests bit 0 of the record flags with
 * lbu in the value-context test (an unsigned char bitfield view gives it) where an int field gives lw. */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cCoreSave.h"
#include "godhand/cRecordIndex.h"
#include "godhand/criStm.h"

extern int func_002C97C8(void *a0, int x);
extern void func_002C9818(char *a0, int a1, int *a2, int a3, unsigned char t0);

#define cRecordIndex_entry(self, id) (&(self)->table[id])

/* Records owned from the start get level 0 the first time they are seen. */
static __inline__ void cRecordIndex_grantInitial(cRecordIndex *self, int id)
{
    if (cRecordIndex_entry(self, id)->flags & 1) {
        if (cCoreSave_getSkill(&D_00569B70, id) == -1)
            cCoreSave_setSkill(&D_00569B70, id, 0);
    }
}

static __inline__ int cRecordIndex_isBought(cRecordIndex *self, int id)
{
    return (cRecordIndex_entry(self, id)->flags & 1) == 0;
}

/* Rebuild the index of skills shown in list mode `mode`; modes 3 and 4 also copy the combos from and back to the
 * save record. */
__attribute__((section(".text.func_002C90A0")))
void func_002C90A0(cRecordIndex *self, unsigned char mode)
{
    unsigned int i;
    int num;

    num = 0;
    func_003A52F0(self->index, 0, RECORDINDEX_INDEX_NUM);
    if (self->table == 0)
        return;
    for (i = 0; i < self->count; i++) {
        switch (mode) {
        case 0:
            cRecordIndex_grantInitial(self, i);
            if (cCoreSave_getSkill(&D_00569B70, i) >= 0)
                self->index[num++] = i;
            break;
        case 1:
            cRecordIndex_grantInitial(self, i);
            if (func_002C97C8(self, i))
                break;
            if (!cRecordIndex_isBought(self, i))
                break;
            if (cCoreSave_ckClearStage(&D_00569B70, cRecordIndex_entry(self, i)->stage) || cCoreSave_getClearNum(&D_00569B70)
                || cRecordIndex_entry(self, i)->stage == 0) {
                if (cRecordIndex_entry(self, i)->needSkill == -1
                    || cCoreSave_getSkill(&D_00569B70, cRecordIndex_entry(self, i)->needSkill) != -1)
                    self->index[num++] = i;
            }
            break;
        case 2:
            cRecordIndex_grantInitial(self, i);
            if (func_002C97C8(self, i))
                break;
            if (!cRecordIndex_isBought(self, i) && cCoreSave_getSkill(&D_00569B70, i) != -1)
                break;
            if (cCoreSave_getSkill(&D_00569B70, i) == 1 || cCoreSave_getSkill(&D_00569B70, i) == 0)
                self->index[num++] = i;
            break;
        case 3:
            cRecordIndex_grantInitial(self, i);
            if (func_002C97C8(self, i))
                break;
            if (cCoreSave_ckClearStage(&D_00569B70, cRecordIndex_entry(self, i)->stage)
                || cRecordIndex_entry(self, i)->stage == 0 || cCoreSave_getClearNum(&D_00569B70)) {
                if (cCoreSave_getSkill(&D_00569B70, i) == -1)
                    cCoreSave_setSkill(&D_00569B70, i, 2);
            }
            if (cCoreSave_getSkill(&D_00569B70, i) >= 0)
                self->index[num++] = i;
            break;
        case 4:
            cRecordIndex_grantInitial(self, i);
            if (cCoreSave_getSkill(&D_00569B70, i) == 2)
                cCoreSave_setSkill(&D_00569B70, i, -1);
            break;
        case 5:
            func_002C9818((char *)self, i, &num, 2, 1);
            break;
        case 6:
            func_002C9818((char *)self, i, &num, 2, 0);
            break;
        case 7:
            func_002C9818((char *)self, i, &num, 0x8, 1);
            break;
        case 8:
            func_002C9818((char *)self, i, &num, 0x10, 1);
            break;
        case 9:
            func_002C9818((char *)self, i, &num, 0x20, 1);
            break;
        case 10:
            func_002C9818((char *)self, i, &num, 0x40, 1);
            break;
        case 11:
            func_002C9818((char *)self, i, &num, 0x80, 1);
            break;
        case 12:
            func_002C9818((char *)self, i, &num, 0x100, 1);
            break;
        case 13:
            func_002C9818((char *)self, i, &num, 0x200, 1);
            break;
        case 14:
            func_002C9818((char *)self, i, &num, 0x400, 1);
            break;
        case 15:
            func_002C9818((char *)self, i, &num, 0x800, 1);
            break;
        case 16:
            func_002C9818((char *)self, i, &num, 0x1000, 1);
            break;
        }
    }
    switch (mode) {
    case 3:
        memcpy(self->combo, D_00569B70.data->combo, sizeof(self->combo));
        break;
    case 4:
        memcpy(D_00569B70.data->combo, self->combo, sizeof(self->combo));
        break;
    }
    self->limit = num;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002C90A0);
#endif
