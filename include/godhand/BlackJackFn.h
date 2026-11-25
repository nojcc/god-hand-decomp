/* include/godhand/BlackJackFn.h - BlackJack methods.
 *
 * Work's prototypes that BlackJack.h on main does not carry: some clash with
 * main units' own declarations. Included by the work units that need them.
 */
#ifndef GODHAND_BLACKJACKFN_H
#define GODHAND_BLACKJACKFN_H

#include "godhand/BlackJack.h"

/* Turns the card face up (heading 0, bit 3), or with animate set starts the turn (bit 4) func_001D6E20 steps; nothing while either bit is set. */
void func_001D6DD0(BlackJackCard *card, int animate);
/* Turns a face-up card face down (heading pi, clears bit 3), or with animate set marks it turning (bit 4); nothing unless bit 3 is set and bit 4 clear. */
void func_001D6EC8(BlackJackCard *card, int animate);
/* Step a turning card: face up (func_001D0CE8, func_001D6E20) or face down (func_001D0DF8, func_001D6F30). */
void func_001D0CE8(BlackJackCard *card);
void func_001D0DF8(BlackJackCard *card);
/* Release the table's ID base and clear the host's words at 0x98 and 0x9C. */
void func_001D4F48(BlackJack *self);
/* BlackJackId: the methods on the display at the start of the table. */
/* Clear word 0, construct the ID base and the 45 elements; returns self. */
BlackJack *func_001D4D80(BlackJack *self);
/* Load the blackjack ID file, set up the 45 elements and the default display. */
void func_001D4DF0(BlackJack *self);
/* Run the 45 elements, then move the ID base. */
void BlackJackId_Move(BlackJack *self);
/* Draw the table background, then the ID base. */
void BlackJackId__Trans(BlackJack *self);
/* Show (flag set) or hide element idx; idx BLACKJACK_ELEM_NUM means every element but 0. */
void SetFlagOnEntries7C_1D51B8(BlackJack *self, int idx, int flag);
/* Hide every element, then show the default set. */
void BlackJackId_SetDefaultDisp(BlackJack *self);
/* Show or hide the bet menu's three entry groups (0xB, 0xC, 0x23) for menu state mode. */
void func_001D5360(BlackJack *self, unsigned char mode);
/* The same for entries 9, 0xA and 0x24. */
void func_001D5430(BlackJack *self, unsigned char mode);
/* The same for entries 0xD, 0xE and 0xF. */
void func_001D5500(BlackJack *self, unsigned char mode);
/* The same for entries 0x10, 0x11 and 0x12. */
void func_001D5690(BlackJack *self, unsigned char mode);
/* Set entry 0x21 to on and show entry 0x22. */
void SetFlagEntries21And22_1D55D0(BlackJack *self, int on);
/* Set entry 7 to on and show entry 8. */
void SetFlagEntries7And8_1D5610(BlackJack *self, int on);
/* Set entry 5 to on and show entry 6. */
void SetFlagEntries5And6_1D5650(BlackJack *self, int on);
/* Set element 4's number. */
void func_001D5780(BlackJack *self, int number);
/* Slide element 0xB (func_001D5C38) or 9 (func_001D5D20) in or out for mode 0..3. */
void func_001D5C38(BlackJack *self, unsigned short mode);
void func_001D5D20(BlackJack *self, unsigned short mode);
/* Slide the panel element 0xD in or out for mode 0..3 and switch entries 0xD..0xF. */
void IdPanel_setSlideState(BlackJack *self, unsigned short mode);
/* Slide the panel element 0x21 vertically for mode 0..3. */
void PanelWork_setMode(BlackJack *self, int mode);
/* Slide the panel element 7 in or out for mode 0..3. */
void PanelHost_slideSidePanel(BlackJack *self, unsigned short mode);
/* Slide the panel element 5 in or out for mode 0..3. */
void BlackJack_slidePanel(BlackJack *self, unsigned short mode);
/* Slide element 0x10 vertically for mode 0..4 and switch entries 0x10..0x12. */
void func_001D61C0(BlackJack *self, int mode);
/* Show or hide entries 0x1C and 0x1D (func_001D69A0), 0x1A and 0x1B (func_001D69E8),
 * 0x20 (func_001D6BC0), 0x29 and 0x2A (func_001D6BE0), 0x2B and 0x2C (func_001D6C28),
 * 0x1F (func_001D6C70), 0x25 and 0x26 (func_001D6C90) or 0x27 and 0x28 (func_001D6CD8). */
void func_001D69A0(BlackJack *self, int on);
void func_001D69E8(BlackJack *self, int on);
void func_001D6BC0(BlackJack *self, int on);
void func_001D6C28(BlackJack *self, int on);
void func_001D6C70(BlackJack *self, int on);
void func_001D6C90(BlackJack *self, int on);
void func_001D6CD8(BlackJack *self, int on);
void func_001D6BE0(BlackJack *self, int on);
/* Set element 0x1B's (func_001D6A30) or element 0x1D's (func_001D6A50) number. */
void func_001D6A30(BlackJack *self, int number);
void func_001D6A50(BlackJack *self, int number);

#endif /* GODHAND_BLACKJACKFN_H */
