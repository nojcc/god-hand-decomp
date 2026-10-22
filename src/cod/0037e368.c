/* sn-2.95.3-136: func_0037E368, sound debug menu step: the cancel button leaves page 1; otherwise run the
 * handler of the current page, then update and draw the menu. */
extern void func_0037E488(unsigned char *self);
extern void func_0037E4C0(unsigned char *self, char *pad);
extern void func_0037FAC8(unsigned char *self);
extern void func_0037FB70(char *p);
extern void func_0037FC28(unsigned char *self);
extern void func_0037FCC8(char *self);
extern void func_0037FE40(unsigned char *self);
extern void func_0037FF98(unsigned char *self);
extern void func_00380048(unsigned char *self, char *pad, unsigned char kind);
extern void func_00380138(char *self, char *other);
extern void func_00380280(char *self);
extern void func_00380638(char *object);

__attribute__((section(".text.func_0037E368")))
int func_0037E368(unsigned char *self, char *pad)
{
    if ((*(int *)(pad + 0x34) & 0x40) && self[2] == 1) {
        self[0] = 0;
        self[2] = 0;
        return 1;
    }
    switch (self[2]) {
    case 0:
        func_0037E488(self);
        break;
    case 1:
        func_0037E4C0(self, pad);
        break;
    case 2:
        func_0037FAC8(self);
        break;
    case 3:
        func_0037FB70((char *)self);
        break;
    case 4:
        func_0037FC28(self);
        break;
    case 5:
        func_0037FCC8((char *)self);
        break;
    case 6:
        func_0037FE40(self);
        break;
    case 7:
        func_0037FF98(self);
        break;
    case 8:
    case 9:
    case 10:
    case 11:
        func_00380048(self, pad, self[2]);
        break;
    case 12:
        func_00380138((char *)self, pad);
        break;
    }
    func_00380280((char *)self);
    func_00380638((char *)self);
    return 1;
}
