/* include/godhand/sysFlags.h - the system flag words at D_00747A78.
 *
 * They are GameWork 0x5D8 to 0x5E3 (flags5D8 and flags5E0 in gameWork.h)
 * under their own symbol. Code that reaches 0x5E0 at +8 from D_00747A78
 * reads them through this view.
 */
#ifndef GODHAND_SYSFLAGS_H
#define GODHAND_SYSFLAGS_H

/* The system flag words from D_00747A78 on: the third one is at +8. */
typedef struct SysFlagWords {
    unsigned int f78;                   /* 0x747A78 */
    unsigned int f7C;
    unsigned int f80;                   /* 0x747A80 */
} SysFlagWords;

extern SysFlagWords D_00747A78;

#endif
