/* include/godhand/drawPrim.h - the screen-space primitive drawers (sn code at 0x15B880..0x15F2D8). */
#ifndef GODHAND_DRAWPRIM_H
#define GODHAND_DRAWPRIM_H

/* Queue a four-vertex polygon packet; returns the packet, or 0 when the queue is full. */
extern void *Gp_draw_poly4(void *v, int color, int count, void *ctx, int a5, int a6);
struct Tim2FileHdr;
struct cScrVtx;
struct cScrTexCfg;

/* Textured quad: four vertices (screen positions when screen is set, else
 * world positions), the packed colour, the texture file loaded at tbp/cbp
 * and its draw config; queued in list kind at priority prio. */
void *Gp_draw_polyFT4(struct cScrVtx *v, unsigned int color, int screen, struct Tim2FileHdr *tex, unsigned int tbp, int cbp,
                      struct cScrTexCfg *cfg, int kind, int prio);

/* Draw one flat quad from four screen-space vertices. */
extern void Draw_Poly_sc(void *v, int color);

/* Draw a line strip through n + 1 screen-space vertices in one colour. */
extern void Draw_Line_sc(void *v, int n, unsigned int color, int a3);

/* Draw a line strip through n world-space points in one colour. */
void Draw_Line2(void *pts, unsigned int n, unsigned int color, int flag);

#endif /* GODHAND_DRAWPRIM_H */
