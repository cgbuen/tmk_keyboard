// KMAC Mini
#include "kmac_macro.h"
static const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /* 0: qwerty */
    [0] = KEYMAP_MINI(\
        VOLU, VOLD, ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL,BSLS,GRV, \
        F4, MUTE, TAB, QUOT, COMM,   DOT,   P,   Y,   F,   G,   C,   R,   L, LBRC, RBRC, BSPC, DEL, \
        HOME, END, LCTL, A,   O,   E,   U,   I,   D,   H,   T,   N,   S, MINS,     ENT,         INS, \
        PGUP, PGDN, LSFT, SCLN, Q,  J,   K,   X,   B,   M,   W,   V, Z,       RSFT,          UP, FN0, \
        FN1, FN2, LCTL,LGUI,LALT,             FN0,                     RALT,       LEFT, DOWN, RIGHT ),

    [1] = KEYMAP_MINI(\
        FN3, FN4, ESC, F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,   F11, F12 ,GRV,BSLS, \
        FN5, A, TAB, FN3, FN4,   FN5,   P,   Y,   F,   G,   C,   R,   L, LBRC, RBRC, BSPC, DEL, \
        INT5, INT6, LCTL, A,   O,   E,   U,   I,   D,   H,   T,   N,   S, MINS,     ENT,         PGDN, \
        INT7, INT8 , FN1, SCLN, Q,  J,   K,   X,   B,   M,   W,   V, Z,       RSFT,          UP, FN0, \
        INT9, J, LCTL,LGUI,LALT,             TRNS,                     RALT,       LEFT, DOWN, RIGHT ),

    [2] = KEYMAP_MINI(\
        A, B, ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL,GRV,BSLS, \
        C, D, TAB, FN6, FN7,   FN8,   P,   Y,   F,   G,   C,   R,   L, LBRC, RBRC, BSPC, DEL, \
        E, F, LCTL, A,   O,   E,   U,   I,   D,   H,   T,   N,   S, MINS,     ENT,         PGDN, \
        G, H, TRNS, SCLN, Q,  J,   K,   X,   B,   M,   W,   V, Z,       RSFT,          VOLU, FN0, \
        I, J, LCTL,LGUI,LALT,             TRNS,                     RALT,       LEFT, VOLD, MUTE )

};


#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const action_t fn_actions[] PROGMEM = {
#endif
 
    [0] = ACTION_LAYER_TAP_KEY(1, KC_SPC),
    [1] = ACTION_LAYER_MOMENTARY(2),
    [2] = ACTION_LAYER_MOMENTARY(3),
    [3] = ACTION_MACRO(AE),
    [4] = ACTION_MACRO(AA),
    [5] = ACTION_MACRO(OE),
    [6] = ACTION_MACRO(CAE),
    [7] = ACTION_MACRO(CAA),
    [8] = ACTION_MACRO(COE)
};




