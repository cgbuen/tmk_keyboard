// KMAC Winkeyless
#include "kmac_macro.h"
static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP_WINKEYLESS(\
        ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,       PSCR,SLCK,BRK,  \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   SLSH, EQL,BSLS,      INS, HOME,PGUP, \
        TAB,QUOT,COMM,DOT,   P,   Y,   F,   G,   C   ,R   ,L  ,LBRC,RBRC,BSPC,      DEL, END, PGDN, \
        LCTL, A,   O,   E,   U,   I,   D,   H,   T,   N,   S,  MINS,     ENT,                       \
        LSFT, SCLN,   Q,   J,   K,   X,   B,   M,   W,    V,     Z,      RSFT,           UP,        \
        LGUI,NO,LALT,               FN0,                     RALT,NO,RCTL,      LEFT,DOWN,RGHT),
    /* 1: media keys */
    KEYMAP_WINKEYLESS(\
        FN1,      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,SLEP, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,MUTE,VOLD,VOLU,TRNS,      TRNS,TRNS,TRNS, \
        TAB, FN3, FN4,   FN5,   P,   Y,   F,   G,   UP,   R,   L, LBRC, RBRC, DEL,      TRNS,TRNS,TRNS, \
        LCTL, A,   O,   E,   U,   I,   D,   LEFT,DOWN,RIGHT,   S, MINS,     ENT,                      \
        FN1,     TRNS,TRNS,CALC,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     CAPS,           TRNS,      \
        TRNS,TRNS,TRNS,               FN0,                    TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS),
    KEYMAP_WINKEYLESS(\
        FN1,      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,SLEP, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,MUTE,VOLD,VOLU,TRNS,      TRNS,TRNS,TRNS, \
        TAB, FN6, FN7,   FN8,   P,   Y,   F,   G,   UP,   R,   L, LBRC, RBRC, DEL,      TRNS,TRNS,TRNS, \
        LCTL, A,   O,   E,   U,   I,   D,   LEFT,DOWN,RIGHT,   S, MINS,     ENT,                      \
        FN1,     TRNS,TRNS,CALC,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     CAPS,           TRNS,      \
        TRNS,TRNS,TRNS,               FN0,                    TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS),
};
static const action_t PROGMEM fn_actions[] = {
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

