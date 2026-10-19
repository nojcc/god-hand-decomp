/* sn-2.95.3-136, as=sn: NM closer handoff. */
/* Draw_Line_sc: draw a screen-space polyline: offset each point into GS window coordinates,
 * flag points outside the 0..4095.9 window and draw a segment only when both ends are inside. */
typedef struct {
    int flags;                          /* 0x00 */
    int pad04[11];
    long tex1;                          /* 0x30 */
    long pad38[3];
} LineAttrSc;

extern int D_00747A2C;
extern int D_00586B80;
extern int D_003C1180;
extern void sceVu0DivVector(float *v0, float *v1, float q);
extern void Gp_draw_line(float (*pts)[4], int color, int a2, int a3, int t0, LineAttrSc *attr);

__attribute__((section(".text.Draw_Line_sc")))
void Draw_Line_sc(float (*pts)[4], unsigned int count, int color, int flat)
{
    LineAttrSc attr;
    float v[4];
    unsigned int i;
    int out;
    int prev;
    int ofs = 0x800;

    if (D_00747A2C & 0x40000000)
        return;
    attr.flags = 0;
    if (!flat) {
        attr.flags = 0x20;
        attr.tex1 = 0x30000;
    }
    count++;
    prev = 0;
    for (i = 0; i < count; i++) {
        v[0] = pts[i][0] + (float)(ofs - D_003C1180 / 2);
        v[1] = pts[i][1] + (float)D_00586B80;
        v[2] = pts[i][2];
        v[3] = 1.0f;
        sceVu0DivVector(v, v, 1.0f);
        out = 0;
        if (v[0] < 0.0f || 4095.9f < v[0] || v[1] < 0.0f || 4095.9f < v[1])
            out = 0x80;
        if (i != 0 && out == 0 && prev == 0)
            Gp_draw_line(&pts[i - 1], color, 1, 8, 2, &attr);
        prev = out;
    }
}
