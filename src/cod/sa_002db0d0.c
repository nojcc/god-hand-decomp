/* sn-2.95.3-136: find a live enemy with the given id in the enemy list. Without a position, the
 * first one; with a position, the nearest one within range (a negative range means unlimited). */
typedef struct {
    int unk00;
    char **begin;                       /* 0x04 */
    char **end;                         /* 0x08 */
} EmList2DB0D0;

extern EmList2DB0D0 *D_00754C30;
extern float capVu0LengthAB(void *a, void *b);

__attribute__((section(".text.func_002DB0D0")))
char *func_002DB0D0(int id, void *pos, float range)
{
    char **it;
    float best;
    float d;

    if (pos == 0) {
        for (it = D_00754C30->begin; it != D_00754C30->end; it++) {
            char *e = *it;

            if (*(unsigned short *)(e + 0x2FE) == id && !(*(unsigned int *)(e + 0x250) & 0xE0000000))
                return e;
        }
        return 0;
    }
    if (0.0f <= range) {
        char *found = 0;

        best = range;
        for (it = D_00754C30->begin; it != D_00754C30->end; it++) {
            char *e = *it;

            if (*(unsigned short *)(e + 0x2FE) == id && !(*(unsigned int *)(e + 0x250) & 0xE0000000)) {
                d = capVu0LengthAB(pos, *(void **)(e + 0xF0));
                if (d < best) {
                    found = *it;
                    best = d;
                }
            }
        }
        return found;
    }
    best = -1.0f;
    {
        char *found = 0;

        for (it = D_00754C30->begin; it != D_00754C30->end; it++) {
            char *e = *it;

            if (*(unsigned short *)(e + 0x2FE) == id && !(*(unsigned int *)(e + 0x250) & 0xE0000000)) {
                d = capVu0LengthAB(pos, *(void **)(e + 0xF0));
                if (best < 0.0f || d < best) {
                    found = *it;
                    best = d;
                }
            }
        }
        return found;
    }
}
