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

/* The same quad from a raw (non-TIM2) texture image. */
void *func_0015D168(struct cScrVtx *v, unsigned int color, int screen, void *tex, unsigned int tbp, int cbp,
                    struct cScrTexCfg *cfg, int kind, int prio);

/* The same quad from a TIM2 texture file, with the arguments func_0015D168 takes. */
void *func_0015D6E8(struct cScrVtx *v, unsigned int color, int screen, void *tex, unsigned int tbp, int cbp,
                    struct cScrTexCfg *cfg, int kind, int prio);

/* Draw a line strip through n world-space points (cVec) in one colour. */
extern void Draw_Line2(void *pts, int n, unsigned int color, int flag);

/* Draw one flat quad from four screen-space vertices. */
extern void Draw_Poly_sc(void *v, int color);

/* A textured four-point polygon into the packet (assembly); returns the next packet position. */
void *Gp_draw_polyFT4(void *v, unsigned int col, int n, void *tex,
                      int t0, int t1, void *cfg, int t3, int extra);

#endif /* GODHAND_DRAWPRIM_H */
