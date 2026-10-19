/* sn-2.95.3-136: func_001DA4E8, poker panel slide-in sequence. */
extern void Panel_slide(void *a0, int a1);
extern void func_001DE088(void *a0, int a1);
extern void func_001DE170(void *a0, int a1);
extern void func_001DE258(void *a0, int a1);
extern void func_001DE340(void *a0, int a1);
extern void CustomIDOwner_setSlideState(void *a0, int a1);
extern void PanelWork_setModeB(void *a0, int a1);
extern void CustomIDOwner_setSlideStateB(void *a0, int a1);
extern void PokerUi_slidePanel(void *a0, int a1);
extern void Panel_slideSidePanelArrows(void *a0, int a1);
extern void func_001DEE40(void *a0, int a1);
extern void UiPanel_setSlideMode(void *a0, int a1);

static inline unsigned char DecCount(int *p)
{
    if (*p == 0) {
        return 1;
    }
    *p = *p - 1;
    return 0;
}

__attribute__((section(".text.func_001DA4E8")))
void func_001DA4E8(void *a0)
{
    char *s0 = (char *)a0;

    switch (*(unsigned char *)(s0 + 0x3025)) {
    case 0:
        *(int *)(s0 + 0x3028) = 0x1E;
        *(unsigned char *)(s0 + 0x3045) = 0;
        *(unsigned char *)(s0 + 0x3025) += 1;
        break;
    case 1:
        if (DecCount((int *)(s0 + 0x3028)) == 0) {
            break;
        }
        Panel_slide(s0, 3);
        func_001DE088(s0, 3);
        func_001DE170(s0, 3);
        func_001DE258(s0, 3);
        func_001DE340(s0, 3);
        CustomIDOwner_setSlideState(s0, 3);
        PanelWork_setModeB(s0, 3);
        *(int *)(s0 + 0x3028) = 0x1E;
        *(unsigned char *)(s0 + 0x3025) += 1;
        break;
    case 2: {
        char *ui;
        int v;
        if (DecCount((int *)(s0 + 0x3028)) == 0) {
            break;
        }
        ui = s0 + 0x25B0;
        CustomIDOwner_setSlideStateB(ui, 2);
        PokerUi_slidePanel(ui, 2);
        Panel_slideSidePanelArrows(ui, 2);
        v = *(int *)(s0 + 0x3038);
        *(int *)(s0 + 0x3034) = v;
        func_001DEE40(ui, v);
        UiPanel_setSlideMode(ui, 2);
        *(unsigned char *)(s0 + 0x3025) = 0;
        *(unsigned char *)(s0 + 0x3024) = 0xD;
        break;
    }
    }
}
