/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/CustomIDWork.h"


__attribute__((section(".text.SetCustomIDDispOneOrAll_1F29C0")))
void SetCustomIDDispOneOrAll_1F29C0(char *a0, int a1, int a2)
{
	char *p;
	int i;

	if (a2 != 0) {
		if (a1 == 0x12) {
			p = a0 + 0x60;
			for (i = 0x11; i >= 0; i--) {
				CustomIDWork_SetDisp((CustomIDWork *)p, 1);
				p += 0x7C;
			}
		} else {
			CustomIDWork_SetDisp((CustomIDWork *)(a0 + (a1 * 0x7C + 0x60)), 1);
		}
	} else {
		if (a1 == 0x12) {
			p = a0 + 0x60;
			for (i = 0x11; i >= 0; i--) {
				CustomIDWork_SetDisp((CustomIDWork *)p, 0);
				p += 0x7C;
			}
		} else {
			CustomIDWork_SetDisp((CustomIDWork *)(a0 + (a1 * 0x7C + 0x60)), 0);
		}
	}
}
