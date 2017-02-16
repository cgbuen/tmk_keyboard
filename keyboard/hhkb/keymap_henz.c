#include "keymap_common.h"


#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif


    //LINUX
    [0] = \
    KEYMAP(ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   SLSH,EQL, BSLS,GRV, \
           TAB, QUOT,   COMM,   DOT,   P,   Y,   F,   G,   C,   R,   L,   LBRC,RBRC,BSPC, \
           LCTL,A,   O,   E,   U,   I,   D,   H,   T,   N,   S, MINS,ENT, \
           LSFT, SCLN,   Q,   J,   K,   X,   B,   M,   W, V, Z, RSFT,FN0, \
                 LALT,LGUI,          FN0,                RGUI, RALT),


    //WINDOWS
    [1] = \
    KEYMAP(ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   SLSH,EQL, BSLS,GRV, \
           TAB, QUOT,   COMM,   DOT,   P,   Y,   F,   G,   C,   R,   L,   LBRC,RBRC,BSPC, \
           LCTL,A,   O,   E,   U,   I,   D,   H,   T,   N,   S, MINS,ENT, \
           TRNS, SCLN,   Q,   J,   K,   X,   B,   M,   W, V, Z, RSFT,FN0, \
                LALT, LGUI,          TRNS,                RGUI,RALT),


    //LINUX
    [2] = \
    KEYMAP(GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, NO, NO, \
           CAPS,FN3, FN4,   FN5,  NO,  NO,  NO,  PGUP,  UP, PGDN,PAUS, PSCR,  SLCK,  DEL, \
           LCTL,VOLD,VOLU,MUTE,NO,  NO,  PAST,LEFT,DOWN,RGHT,NO,NO,ENT, \
           FN1,NO,  NO,  NO,  NO,  NO,  HOME, NO ,NO , END ,NO,RSFT,TRNS, \
                LGUI,LALT,          TRNS,               RALT,RGUI),

    //LINUX
    [3] = \
    KEYMAP(GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL, \
           TAB, FN6, FN7, FN8,  PGUP,END, HOME,PGDN,PGUP,END, NO,  NO,  NO,  BSPC, \
           LCTL,NO,  LEFT,DOWN,RGHT,NO,  LEFT,DOWN,UP,  RGHT,NO,  NO,  ENT, \
           TRNS,NO,  NO,  NO,  NO,  NO,  HOME,PGDN,PGUP,END, FN2, RSFT,TRNS, \
                LGUI,LALT,          SPC,                RALT,RGUI),

    //WINDOWS
    [4] = \
    KEYMAP(GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, NO, NO, \
           CAPS,FN3, FN4,   FN5,  NO,  NO,  NO,  PGUP,  UP, PGDN,PAUS, PSCR,  SLCK,  DEL, \
           LCTL,VOLD,VOLU,MUTE,NO,  NO,  PAST,LEFT,DOWN,RGHT,NO,NO,ENT, \
           FN1,NO,  NO,  NO,  NO,  NO,  HOME, NO ,NO , END ,NO,RSFT,TRNS, \
                LGUI,LALT,          TRNS,               RALT,RGUI),

    //WINDOWS
    [5] = \
    KEYMAP(GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL, \
           TAB, FN6, FN7, FN8,  PGUP,END, HOME,PGDN,PGUP,END, NO,  NO,  NO,  BSPC, \
           LCTL,NO,  LEFT,DOWN,RGHT,NO,  LEFT,DOWN,UP,  RGHT,NO,  NO,  ENT, \
           TRNS,NO,  NO,  NO,  NO,  NO,  HOME,PGDN,PGUP,END, FN2, RSFT,TRNS, \
                LGUI,LALT,          SPC,                RALT,RGUI),


};



/* id for user defined functions */
enum function_id {
    LSHIFT_LPAREN,
};

enum macro_id {
    AE,
    AA,
    OE,
    CAE,
    CAA,
    COE
};

/*
 * Fn action definition
 */
#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const action_t fn_actions[] PROGMEM = {
#endif
    [0] = ACTION_LAYER_TAP_KEY(2, KC_SPC),
    [1] = ACTION_LAYER_MOMENTARY(3),
    [2] = ACTION_LAYER_MOMENTARY(4),
    [3] = ACTION_MACRO(AE),
    [4] = ACTION_MACRO(AA),
    [5] = ACTION_MACRO(OE),
    [6] = ACTION_MACRO(CAE),
    [7] = ACTION_MACRO(CAA),
    [8] = ACTION_MACRO(COE),

//  [x] = ACTION_LMOD_TAP_KEY(KC_LCTL, KC_BSPC),        // LControl with tap Backspace
//  [x] = ACTION_LMOD_TAP_KEY(KC_LCTL, KC_ESC),         // LControl with tap Esc
//  [x] = ACTION_FUNCTION_TAP(LSHIFT_LPAREN),           // Function: LShift with tap '('
//  [x] = ACTION_MACRO(HELLO),                          // Macro: say hello
//  [x] = ACTION_MACRO(VOLUP),                          // Macro: media key
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



/*
 * user defined action function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    if (record->event.pressed) dprint("P"); else dprint("R");
    dprintf("%d", record->tap.count);
    if (record->tap.interrupted) dprint("i");
    dprint("\n");

    switch (id) {
        case LSHIFT_LPAREN:
            // Shift parentheses example: LShft + tap '('
            // http://stevelosh.com/blog/2012/10/a-modern-space-cadet/#shift-parentheses
            // http://geekhack.org/index.php?topic=41989.msg1304899#msg1304899
            if (record->event.pressed) {
                if (record->tap.count > 0 && !record->tap.interrupted) {
                    if (record->tap.interrupted) {
                        dprint("tap interrupted\n");
                        register_mods(MOD_BIT(KC_LSHIFT));
                    }
                } else {
                    register_mods(MOD_BIT(KC_LSHIFT));
                }
            } else {
                if (record->tap.count > 0 && !(record->tap.interrupted)) {
                    add_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                    register_code(KC_9);
                    unregister_code(KC_9);
                    del_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                    record->tap.count = 0;  // ad hoc: cancel tap
                } else {
                    unregister_mods(MOD_BIT(KC_LSHIFT));
                }
            }
            break;
    }
}






