#include "godhand/cOm53.h"
#include "godhand/cDamageManage.h"
#include "godhand/libio.h"

/* sn-2.95.3-136 matched TU. */

/* libio genops.c :: _IO_switch_to_backup_area */
__attribute__((section(".text._IO_switch_to_backup_area")))
void _IO_switch_to_backup_area(struct _IO_FILE *fp) {
    char *tmp;
    fp->_flags |= _IO_IN_BACKUP;
    tmp = fp->_IO_read_end;
    fp->_IO_read_end = fp->_IO_save_end;
    fp->_IO_save_end = tmp;
    tmp = fp->_IO_read_base;
    fp->_IO_read_base = fp->_IO_save_base;
    fp->_IO_save_base = tmp;
    fp->_IO_read_ptr = fp->_IO_read_end;
}

/* Count n more riders as off the lift. 0 when nobody rides or n is 0. */
__attribute__((section(".text.cOm53_setGetOffEm")))
int cOm53_setGetOffEm(cOm53 *self, int n) {
    if (self->riderNum == 0) {
        return 0;
    }
    if (n == 0) {
        return 0;
    }
    self->getOffNum = self->getOffNum + n;
    return 1;
}

__attribute__((section(".text.func_001FE310")))
cDamageUnit *func_001FE310(cDamageManage *self) {
    unsigned int i = 0;
    cDamageUnit *q = self->take;
loop:
    if (q->live == 0) {
        return q;
    }
    i++;
    if (i < CDAMAGE_TAKE_MAX) {
        q++;
        goto loop;
    }
    return &self->takeSpare;
}

/* libio genops.c :: _IO_switch_to_main_get_area */
__attribute__((section(".text._IO_switch_to_main_get_area")))
void _IO_switch_to_main_get_area(struct _IO_FILE *fp) {
    char *tmp;
    fp->_flags &= ~_IO_IN_BACKUP;
    tmp = fp->_IO_read_end;
    fp->_IO_read_end = fp->_IO_save_end;
    fp->_IO_save_end = tmp;
    tmp = fp->_IO_read_base;
    fp->_IO_read_base = fp->_IO_save_base;
    fp->_IO_save_base = tmp;
    fp->_IO_read_ptr = fp->_IO_read_base;
}
