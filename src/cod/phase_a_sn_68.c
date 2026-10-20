/* Three SN clones of func_002ABCE8.
 * The inline `(unsigned char)(s < 2)`
 * form is one instruction short (the andi is deleted).
 * Hiding the slti
 * result so the andi survives also pulls slti out of the bnez delay. */
#define PHASE_A_68(name, lh_off, sh_off, lb_off, bit)                  \
    __attribute__((section(".text." #name)))                           \
    void name(int unused, char *self)                                  \
    {                                                                  \
        char *obj;                                                     \
        short s;                                                       \
        unsigned char cond;                                            \
        int flags;                                                     \
                                                                       \
        obj = *(char **)(self + 0x1C);                                 \
        s = *(short *)(obj + (lh_off));                                \
        *(short *)(self + (sh_off)) = 0;                               \
        cond = s < 2;                                                  \
        if (*(char *)(obj + (lb_off)) != 0)                            \
            return;                                                    \
        flags = *(int *)(self + 0x2C);                                 \
        if (cond)                                                      \
            *(int *)(self + 0x2C) = flags | (bit);                     \
        else                                                           \
            *(int *)(self + 0x2C) = flags & ~(bit);                    \
    }

PHASE_A_68(func_002ABCE8, 0x1B0, 0xA4, 0x5E, 0x1000)
PHASE_A_68(func_002ABD30, 0x214, 0xA6, 0x5F, 0x800)
PHASE_A_68(func_002ABD78, 0x278, 0xA8, 0x64, 0x400)
