#include "keymap_common.h"
#include "backlight.h"


    /* Layer 0: QWERTY */
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    [0] = KEYMAP_WINKEYLESS(\
        ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,       PSCR,SLCK,BRK, \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,      INS, HOME,PGUP, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,      DEL, END, PGDN, \
        LCTL, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,                       \
        LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,           UP,        \
        LCTL,LGUI,LALT,               SPC,                     RALT,FN0,RCTL,      LEFT,DOWN,RGHT),
};


#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const action_t fn_actions[] PROGMEM = {
#endif
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_BACKLIGHT_TOGGLE(),
    [2] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_SWITCH),
    [3] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_RGBRED),
    [4] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_RGBGREEN),
    [5] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_RGBBLUE)
};
