#ifndef __UI_RESOURCES_H__
#define __UI_RESOURCES_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct uiWidgetColors {
    int outline;
    int inner;
    int inner_sel;
    int text;
    int text_sel;
    int shadow;
    int roundness;
    float shade;
} uiWidgetColors;

typedef struct uiStyle {
    struct uiStyle *next, *prev;
    char name[64];
    struct uiFont *font;
    int points;
    int flag;
    float panel_roundness;
    uiWidgetColors wcol_regular;
    uiWidgetColors wcol_tooltip;
    uiWidgetColors wcol_menu;
    uiWidgetColors wcol_menu_back;
    uiWidgetColors wcol_pulldown;
    uiWidgetColors wcol_slider;
    uiWidgetColors wcol_num_adv;
    uiWidgetColors wcol_scroll;
} uiStyle;

extern uiStyle *UISTYLE_GetStyle(void);

#ifdef __cplusplus
}
#endif

#endif
