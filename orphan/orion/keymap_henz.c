#include "keymap_common.h"
#include "backlight.h"

    /* Layer 0: QWERTY */
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    [0] = KEYMAP_WINKEYLESS(\
        ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,       B,C,D,  \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,      INS, HOME,PGUP, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,      DEL, END, PGDN, \
        LCTL, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,                       \
        LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,           UP,        \
        LCTL,LGUI,LALT,               FN0,                     RALT,FN0,RCTL,      LEFT,DOWN,RGHT),
    
};

#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const action_t fn_actions[] PROGMEM = {
#endif
    [0] = ACTION_LAYER_TAP_KEY(1, KC_SPC),
    [1] = ACTION_BACKLIGHT_TOGGLE(),
    [2] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_SWITCH),
    [3] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_RGBRED),
    [4] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_RGBGREEN),
    [5] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_RGBBLUE)
};

enum macro_id {
    AE,
    AA,
    OE,
    CAE,
    CAA,
    COE
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
