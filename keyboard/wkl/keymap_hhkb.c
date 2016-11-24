/*
 * HHKB Layout
 */
#include "keymap_common.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    KEYMAP( \
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, PSCR,HOME,END, \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     DEL, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   O,   P,   LBRC,RBRC,     FN2, \
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,           PGUP,\
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,          UP,  PGDN,\
        FN0, LALT,LGUI,          SPC,                     RGUI,RALT,RCTL,LEFT,DOWN,RGHT \
    )
};

const action_t fn_actions[] PROGMEM = {
};
