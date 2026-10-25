/* include/godhand/drawQueue.h - the per-frame packet heap and the draw
 * queue that links packets into the DMA chain by kind and priority. */
#ifndef GODHAND_DRAWQUEUE_H
#define GODHAND_DRAWQUEUE_H

extern char D_00754C80[];               /* the draw queue */

/* Take size bytes from this frame's packet heap; 0 when it is full. */
void *PostInc_D_00566E10_0015B0F0_15B0F0(int size);

/* Link the packet start..end into queue list kind at priority prio. */
void func_0031A650(void *queue, int kind, int prio, void *start, void *end);

#endif /* GODHAND_DRAWQUEUE_H */
