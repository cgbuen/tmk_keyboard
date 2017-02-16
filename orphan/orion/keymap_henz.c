#include "keymap_common.h"
#include "backlight.h"

    /* Layer 0: QWERTY */
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    [0] = KEYMAP_WINKEYLESS(\
        ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,       PSCR,SLCK,BRK,  \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   SLSH,EQL, BSLS,      INS, HOME,PGUP, \
        TAB, QUOT,COMM,DOT,   P,   Y,   F,   G,   C,   R,   L,   LBRC,RBRC,BSPC,    DEL, END, PGDN, \
        LCTL, A,   O,   E,   U,   I,   D,   H,   T,   N,   S,  MINS,     ENT,                       \
        LSFT, SCLN,   Q,   J,   K,   X,   B,   M,   W,   V,   Z,     RSFT,                UP,        \
        LCTL,LGUI,LALT,               FN0,                     RALT,RGUI,RCTL,      LEFT,DOWN,RGHT),
    
    [1] = KEYMAP_WINKEYLESS(\
        ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12,       FN2, FN3, FN4,  \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,    SLSH,EQL, BSPC,    FN12,FN5,  PGUP, \
        TAB, FN6,   FN7,   FN8,   P,   Y,   F,G,   UP,   R,   L,   SLSH,EQL,DEL,  DEL, END, PGDN, \
        LCTL, HOME,END,PGUP,PGDN,   I,   D,   LEFT,DOWN,RIGHT,   S,  MINS, ENT,                       \
        FN1, SCLN,   Q,   J,   K,   X,   B,   M,   W ,  V,   Z,     RSFT,                      UP,        \
        LCTL,LGUI,LALT,               TRNS,                     RALT,RGUI,RCTL,      LEFT,DOWN,RGHT),

     [2] = KEYMAP_WINKEYLESS(\
        ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,       PSCR,SLCK,BRK,  \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   SLSH,EQL, BSPC,      INS, HOME,PGUP, \
        TAB, FN9,FN10,FN11, P,   Y,   F,   G,   C,   R,   L,   LBRC,RBRC,BSLS,      DEL, END, PGDN, \
        LCTL, A,   O,   E,   U,   I,   D,   H,   T,   N,   S,  MINS,     ENT,                       \
        TRNS, SCLN,   Q,   J,   K,   X,   B,   M,   W,V, Z,     RSFT,           UP,        \
        LCTL,LGUI,LALT,               TRNS,                     RALT,RGUI,RCTL,      LEFT,DOWN,RGHT),
    
};


enum macro_id {
    AE,
    AA,
    OE,
    CAE,
    CAA,
    COE
};

#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const action_t fn_actions[] PROGMEM = {
#endif
    [0] = ACTION_LAYER_TAP_KEY(1, KC_SPC),
    [1] = ACTION_LAYER_MOMENTARY(2),
    [2] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_SWITCH),
    [3] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_RGBRED),
    [4] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_RGBGREEN),
    [5] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_RGBBLUE),
    [6] = ACTION_MACRO(AE),
    [7] = ACTION_MACRO(AA),
    [8] = ACTION_MACRO(OE),
    [9] = ACTION_MACRO(CAE),
    [10] = ACTION_MACRO(CAA),
    [11] = ACTION_MACRO(COE),
    [12] = ACTION_BACKLIGHT_TOGGLE(),
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case AE:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(LSFT),D(U), U(LCTL),U(LSFT), U(U),D(0), U(0),D(0),U(0), D(E), U(E),D(4),U(4),U(ENT),D(ENT), END) :
                    MACRO_NONE );
        case AA:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(LSFT),D(U), U(LCTL),U(LSFT), U(U),D(0), U(0),D(0),U(0), D(E), U(E),D(5),U(5),U(ENT),D(ENT), END) :
                    MACRO_NONE );
        case OE:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(LSFT),D(U), U(LCTL),U(LSFT), U(U),D(0), U(0),D(0),U(0), D(F), U(F),D(6),U(6), U(ENT),D(ENT),END) :
                    MACRO_NONE );
        case CAE:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(LSFT),D(U), U(LCTL),U(LSFT), U(U),D(0), U(0),D(0),U(0), D(C), U(C),D(4),U(4), U(ENT),D(ENT),END) :
                    MACRO_NONE );
        case CAA:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(LSFT),D(U), U(LCTL),U(LSFT), U(U),D(0), U(0),D(0),U(0), D(C), U(C),D(5),U(5), U(ENT),D(ENT),END) :
                    MACRO_NONE );
        case COE:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(LSFT),D(U), U(LCTL),U(LSFT), U(U),D(0), U(0),D(0),U(0), D(D), U(D),D(6),U(6), U(ENT),D(ENT),END) :
                    MACRO_NONE );
    }
    return MACRO_NONE;
}
