/* include/godhand/PokerFn.h - Poker methods.
 *
 * Work's prototypes that Poker.h on main does not carry: some clash with
 * main units' own declarations. Included by the work units that need them.
 */
#ifndef GODHAND_POKERFN_H
#define GODHAND_POKERFN_H

#include "godhand/Poker.h"

/* Release the table's display ID and its ID screen, then clear the host's words at 0x90 and 0x94. */
void Poker_releaseIds(Poker *self);
/* Load the table's ID data file (set 0x12) from disc, then set up the ID screen and the panel. */
void IdScreen_loadIdData(Poker *self);
/* Move the display and the panel. */
void PokerId_Move(Poker *self);
/* Draw the panel and the display, then the table's sprites. */
void PokerId__Trans(Poker *self);
/* Show the default elements and the payout of each hand with no bet. */
void Poker_SetDefaultDisp(Poker *self);
/* Start a new round: clear the bet and payout, reset the deck and the display. */
void func_001D7450(Poker *self);
/* The methods on the display at the start of the table. */
/* Clear word 0, construct the ID base and the 77 elements; returns self. */
Poker *func_001DD068(Poker *self);
/* Construct the display and the panel, clear word 0x2E50; returns self. */
Poker *func_001DF858(Poker *self);
/* Release, move or draw the ID base (func_001DD1A0 runs the elements first). */
void func_001DD180(Poker *self);
void func_001DD1A0(Poker *self);
void func_001DD1F8(Poker *self);
/* Set element 0x12's (CustomIDWork_SetNumber_1DD218) or element 0x10's (func_001DD238) number. */
void CustomIDWork_SetNumber_1DD218(Poker *self, int a1);
void func_001DD238(Poker *self, int number);
/* Show (a2 set) or hide element a1; a1 POKER_ELEM_NUM means every element but 0. */
void SetCustomIDDispOneOrAll_1DD258(Poker *self, int a1, int a2);
/* Hide every element, then show the default set. */
void func_001DD340(Poker *self);
/* Show or hide elements 0x25..0x2C. */
void func_001DD5A0(Poker *self, int a1);
/* Set the number of the element table D_0042B5B0 maps slot a1 (0..7) to. */
void SetCustomIDNumberIndexed_1DD648(Poker *self, unsigned int a1, int a2);
/* Set the score element's number and shift it left by its digit count. */
void CustomIDOwner_setScoreNumber(Poker *self, int number);
/* Switch three entry groups for menu state a1. */
void func_001DD770(Poker *self, unsigned char a1);
void func_001DD840(Poker *self, unsigned char a1);
void func_001DD910(Poker *self, unsigned char a1);
void func_001DD9E0(Poker *self, unsigned char a1);
/* Show or hide the element D_0042B5D0 maps slot a1 (0..4) to. */
void func_001DDAB0(Poker *self, unsigned char a1, int a2);
/* Switch the two elements D_0042B600 gives slot a1 (0..4) for state a2. */
void func_001DDDB0(Poker *self, unsigned char a1, unsigned char a2);
/* Place the two card-kind elements (0x2D, 0x2E) for kind and show or hide them. */
void CustomIDOwner_placeCardKind(Poker *self, unsigned char kind, int on);
/* Start or stop the sideways wobble of element 0x2D. */
void func_001DE050(Poker *self, int enabled);
/* Slide element 3 (func_001DE088), 6, 9 or 0xC (func_001DE340) in or out for mode 0..3. */
void func_001DE088(Poker *self, unsigned char mode);
void func_001DE170(Poker *self, unsigned char mode);
void func_001DE258(Poker *self, unsigned char mode);
void func_001DE340(Poker *self, unsigned char mode);
/* Slide element 1 vertically for state sel and show or hide entry 1. */
void CustomIDOwner_setSlideState(Poker *self, unsigned char sel);
/* Slide element 0x11 vertically for mode 0..3. */
void PanelWork_setModeB(Poker *self, unsigned char mode);
/* Slide element 0x3E for state mode of panel sel. */
void func_001DE5F8(Poker *self, unsigned char sel, unsigned char mode);
/* Slide element 0x13 in or out for mode 0..3. */
void Panel_slide(Poker *self, unsigned char mode);
/* Highlight the element D_0042B698 maps sel (0..7) to and move the marker element 0x1C to it. */
void func_001DE858(Poker *self, unsigned char sel);
/* Start or reset the scale pulse of the element D_0042B5D0 maps slot to. */
void CustomIDWork_pulseSlot(Poker *self, unsigned char slot, int on);
/* Set the offset of the element D_0042B5D0 maps slot a1 (0..4) to. */
void func_001DEBF0(Poker *self, unsigned char a1, int a2, int a3);
/* Set the display's draw mode (cIDBaseObj.mode). */
void SetField_56_1DEBE8(Poker *self, int mode);

#endif /* GODHAND_POKERFN_H */
