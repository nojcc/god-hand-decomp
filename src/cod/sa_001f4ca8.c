extern int D_00747A0C;
extern void func_002D65F8(void *w, float a, float b, float c, float d);
extern void func_002D6578(void *w, int v);
extern void CustomIDWork_SetLocalPosX(void *a0, int x);
extern void SetCustomIDDispOneOrAll_1F4778(void *self, int id, int on);

static inline void setItem(char *self, int idx, float a, float b, float c, float d, int v, int x)
{
    char *w = self + (idx * 0x7C + 0xF64);

    func_002D65F8(w, a, b, c, d);
    func_002D6578(w, v);
    CustomIDWork_SetLocalPosX(w, x);
}

__attribute__((section(".text.func_001F4CA8")))
void func_001F4CA8(char *self, unsigned short idx, int mode, int on)
{

    if (idx >= 7)
        return;
    if (D_00747A0C == 0) {
        switch (mode) {
        case 1:
        default:
            setItem(self, idx, 0.17f, 0.35f, 0.27f, 0.46f, 0x2F, 0xAC);
            break;
        case 2:
            setItem(self, idx, 0.3f, 0.36f, 0.41f, 0.46f, 0x32, 0xAE);
            break;
        case 3:
            setItem(self, idx, 0.17f, 0.48f, 0.27f, 0.58f, 0x2F, 0xAC);
            break;
        case 5:
            setItem(self, idx, 0.3f, 0.48f, 0.41f, 0.59f, 0x2F, 0xAC);
            break;
        }
    } else {
        switch (mode) {
        case 1:
        default:
            setItem(self, idx, 0.17f, 0.35f, 0.27f, 0.46f, 0x2F, 0xA5);
            break;
        case 2:
            setItem(self, idx, 0.3f, 0.36f, 0.41f, 0.46f, 0x32, 0xA7);
            break;
        case 3:
            setItem(self, idx, 0.17f, 0.48f, 0.27f, 0.58f, 0x2F, 0xA5);
            break;
        case 5:
            setItem(self, idx, 0.3f, 0.48f, 0.41f, 0.59f, 0x2F, 0xA5);
            break;
        }
    }
    SetCustomIDDispOneOrAll_1F4778(self, idx + 0x1F, on);
}
