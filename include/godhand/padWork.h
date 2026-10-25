/* include/godhand/padWork.h - the controller work (classPAD_WORK). */
#ifndef GODHAND_PADWORK_H
#define GODHAND_PADWORK_H

/* The pad work object; its vibration requests queue at +0x160. */
extern unsigned char D_005E8140[];

#define PAD_WORK_VIBRATION  0x4B8       /* byte: pad vibration on (the options setting, 1 by default) */

/* Queues vibration request v (motor and power in the top bytes) with
 * timing w (definition in 001d0090.c). */
void classPAD_WORK_Pad_act_set(char *o, unsigned int v, unsigned int w);

#endif
