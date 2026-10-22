/* sn-2.95.3-136 */
/*
 * NON_MATCHING: 66 vs 69 words. Retail walks item[] with two pointers that
 * both start at the record base (stage test, serial test and first store)
 * and rebuilds each later store address as (data + i * 0x10) + 0x28A with
 * the field offset kept separate; the typed index folds 0x28A into the field.
 */
#include "include_asm.h"
#include "godhand/cCoreSave.h"

#ifdef NON_MATCHING
extern unsigned char D_00747A50[];

/* Store the position, yaw and state of the remembered object with serial `serial`. */
__attribute__((section(".text.func_001FB1C0")))
void func_001FB1C0(cCoreSave *self, unsigned short serial, float *pos, float *rot,
                   int extra, unsigned char *flag)
{
    unsigned int i;

    if (D_00747A50[1] == 0) return;
    if (self->data == 0) return;
    for (i = 0; i < CORESAVE_ITEM_NUM; i++) {
        if (self->data->item[i].stage != 0xFFFF && self->data->item[i].serial == serial) {
            self->data->item[i].pos[0] = pos[0] * 10.0f;
            self->data->item[i].pos[1] = pos[1] * 10.0f;
            self->data->item[i].pos[2] = pos[2] * 10.0f;
            self->data->item[i].yaw = rot[1] * 57.2957764f * 0.5f;
            self->data->item[i].extra = extra;
            self->data->item[i].flag = *flag;
            return;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001FB1C0);
#endif
