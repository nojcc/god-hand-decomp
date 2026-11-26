/* ee-2.9-991111 matched TU. */
#include "godhand/ehFrameObj.h"
#include "godhand/newlibMalloc.h"
#include "godhand/newlibStdlib.h"

/* DWARF call-frame opcodes (dwarf2.h). */
#define DW_CFA_advance_loc        0x40
#define DW_CFA_offset             0x80
#define DW_CFA_restore            0xC0
#define DW_CFA_nop                0x00
#define DW_CFA_set_loc            0x01
#define DW_CFA_advance_loc1       0x02
#define DW_CFA_advance_loc2       0x03
#define DW_CFA_advance_loc4       0x04
#define DW_CFA_offset_extended    0x05
#define DW_CFA_restore_extended   0x06
#define DW_CFA_undefined          0x07
#define DW_CFA_same_value         0x08
#define DW_CFA_register           0x09
#define DW_CFA_remember_state     0x0A
#define DW_CFA_restore_state      0x0B
#define DW_CFA_def_cfa            0x0C
#define DW_CFA_def_cfa_register   0x0D
#define DW_CFA_def_cfa_offset     0x0E
#define DW_CFA_GNU_window_save    0x2D
#define DW_CFA_GNU_args_size      0x2E

/* frame_state.saved[] values (frame.h). */
#define REG_UNSAVED      0
#define REG_SAVED_OFFSET 1
#define REG_SAVED_REG    2

union unaligned {
    void *p;
    unsigned short b2;
    unsigned int b4;
} __attribute__((packed));

/* gcc frame.c execute_cfa_insn: run the call-frame instruction at p on state, advancing *pc
 * by the location ops; returns the next instruction. */
__attribute__((section(".text.execute_cfa_insn")))
void *execute_cfa_insn(void *p, FrameStateInternal *state, CieInfo *info, void **pc)
{
    unsigned int insn = *(unsigned char *)p;
    unsigned int reg;
    int offset;

    p = (unsigned char *)p + 1;
    if (insn & DW_CFA_advance_loc)
        *pc = (char *)*pc + (insn & 0x3F) * info->code_align;
    else if (insn & DW_CFA_offset) {
        reg = insn & 0x3F;
        p = decode_uleb128(p, &offset);
        offset *= info->data_align;
        state->s.saved[reg] = REG_SAVED_OFFSET;
        state->s.reg_or_offset[reg] = offset;
    } else if (insn & DW_CFA_restore) {
        reg = insn & 0x3F;
        state->s.saved[reg] = REG_UNSAVED;
    } else
        switch (insn) {
        case DW_CFA_set_loc:
            *pc = ((union unaligned *)p)->p;
            p = (unsigned char *)p + sizeof(void *);
            break;
        case DW_CFA_advance_loc1:
            *pc = (char *)*pc + *(unsigned char *)p;
            p = (unsigned char *)p + 1;
            break;
        case DW_CFA_advance_loc2:
            *pc = (char *)*pc + ((union unaligned *)p)->b2;
            p = (unsigned char *)p + 2;
            break;
        case DW_CFA_advance_loc4:
            *pc = (char *)*pc + ((union unaligned *)p)->b4;
            p = (unsigned char *)p + 4;
            break;

        case DW_CFA_offset_extended:
            p = decode_uleb128(p, &reg);
            p = decode_uleb128(p, &offset);
            offset *= info->data_align;
            state->s.saved[reg] = REG_SAVED_OFFSET;
            state->s.reg_or_offset[reg] = offset;
            break;
        case DW_CFA_restore_extended:
            p = decode_uleb128(p, &reg);
            state->s.saved[reg] = REG_UNSAVED;
            break;

        case DW_CFA_undefined:
        case DW_CFA_same_value:
        case DW_CFA_nop:
            break;

        case DW_CFA_register: {
            unsigned int reg2;
            p = decode_uleb128(p, &reg);
            p = decode_uleb128(p, &reg2);
            state->s.saved[reg] = REG_SAVED_REG;
            state->s.reg_or_offset[reg] = reg2;
        } break;

        case DW_CFA_def_cfa:
            p = decode_uleb128(p, &reg);
            p = decode_uleb128(p, &offset);
            state->s.cfa_reg = reg;
            state->s.cfa_offset = offset;
            break;
        case DW_CFA_def_cfa_register:
            p = decode_uleb128(p, &reg);
            state->s.cfa_reg = reg;
            break;
        case DW_CFA_def_cfa_offset:
            p = decode_uleb128(p, &offset);
            state->s.cfa_offset = offset;
            break;

        case DW_CFA_remember_state: {
            FrameStateInternal *save = func_003A7C70(sizeof(FrameStateInternal));
            *save = *state;
            state->saved_state = save;
        } break;
        case DW_CFA_restore_state: {
            FrameStateInternal *save = state->saved_state;
            *state = *save;
            UpdateGlobalPtrWithParam_3A7CC0(save);
        } break;

        case DW_CFA_GNU_window_save:
            for (reg = 16; reg < 32; ++reg) {
                state->s.saved[reg] = REG_SAVED_OFFSET;
                state->s.reg_or_offset[reg] = (reg - 16) * sizeof(void *);
            }
            break;

        case DW_CFA_GNU_args_size:
            p = decode_uleb128(p, &offset);
            state->s.args_size = offset;
            break;

        default:
            func_003A7B48();
        }
    return p;
}
