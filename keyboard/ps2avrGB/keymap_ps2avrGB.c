#include "keymap_common.h"
#include "macro.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    KEYMAP_BFACE( \
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   SLSH,EQL,GRV,BSLS,       \
        TAB, QUOT, COMM,   DOT,   P,   Y,   F,   G,   C,   R,   L, LBRC, RBRC, BSPC,    \
        LCTL, A,   O,   E,   U,   I,   D,   H,   T,   N,   S, MINS,     ENT,            \
        LSFT, DEL, SCLN, Q,  J,   K,   X,   B,   M,   W,   V, Z,       RSFT, FN0,\
        NO, LGUI,LALT,          FN0,                     RGUI,RALT,NO\
    ),
    KEYMAP_BFACE( \
        ESC, F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,   F11, F12 ,GRV,BSLS, \
        TAB, FN3, FN4,   FN5,   P,   Y,   F,   G,   UP,   R,   L, LBRC, RBRC, DEL,\
        LCTL, A,   O,   E,   U,   I,   D,   LEFT,DOWN,RIGHT,   S, MINS,     ENT,         \
        LSFT, FN1,SCLN, Q,  J,   K,   X,   B,   M,   W,   V, Z,       RSFT,          FN0, \
        TRNS,TRNS,TRNS,          FN0,                      TRNS,TRNS,TRNS \
    ),
    KEYMAP_BFACE( \
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   SLSH,EQL,GRV,BSLS, \
        TAB, FN6, FN7,   FN8,   P,   Y,   F,   G,   PGUP,   R,   L, LBRC, RBRC, BSPC, \
        LCTL, A,   O,   E,   U,   I,   D,   HOME,   PGDN,   END,   S, MINS,     ENT,       \
        LSFT, FN1,SCLN, Q,  J,   K,   X,   B,   M,   W,   V, Z,       RSFT,    FN0,\
        TRNS,TRNS,TRNS,          FN0,                      TRNS,TRNS,TRNS\
    ),
};



const action_t fn_actions[] PROGMEM = {
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
