/*
 * HHKB Layout
 */
#include "keymap_common.h"


#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
    /* Layer 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|
     * |-----------------------------------------------------------|
     * |Contro|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn0|
     * `-----------------------------------------------------------'
     *       |Alt|Gui  |         Space         |Gui  |Alt|
     *       `-------------------------------------------'
     */
    [0] = \
    KEYMAP(ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   SLSH,EQL, BSLS,GRV,   \
           TAB, QUOT,   COMM,   DOT,   P,   Y,   F,   G,   C,   R,   L,   LBRC,RBRC,BSPC,       \
           LCTL,A,   O,   E,   U,   I,   D,   H,   T,   N,   S,MINS,ENT,             \
           LSFT,SCLN,   Q,   J,   K,   X,   B,   M,   W, V, Z,RSFT,FN0,             \
                LALT,LGUI,          SPC,                RGUI,RALT),

    /* Layer 1: HHKB mode (HHKB Fn)
     * ,-----------------------------------------------------------.
     * |Pwr| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |LClick|MouU|RClick|   |   |   |   |Psc|Slk|Pus|Up |   |Backs|
     * |-----------------------------------------------------------|
     * |      |MouL|MouD|MouR|   |   |  *|  /|Hom|PgU|Lef|Rig|Enter   |
     * |-----------------------------------------------------------|
     * |        |VoD|VoU|Mut|   |   |  +|  -|End|PgD|Dow|      |   |
     * `-----------------------------------------------------------'
     *       |   |     |                       |     |   |
     *       `-------------------------------------------'
     */
    [1] = \
    KEYMAP(PWR, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL,   \
           CAPS,TRNS,TRNS,MS_BTN1,MS_BTN2, MS_BTN3,TRNS,TRNS,PSCR,SLCK,PAUS, UP, TRNS, DEL,      \
           TRNS,MS_LEFT,MS_DOWN,MS_UP,MS_RIGHT,TRNS,PAST,PSLS,HOME,PGUP,LEFT,RGHT,PENT,            \
           TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,PPLS,PMNS,END, PGDN,DOWN,TRNS,TRNS,            \
                TRNS,TRNS,          TRNS,               TRNS,TRNS),



    [2] = \
    KEYMAP(ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   SLSH,EQL, BSLS,GRV,   \
           TAB, QUOT,   COMM,   DOT,   P,   Y,   F,   G,   C,   R,   L,   LBRC,RBRC,BSPC,       \
           LCTL,A,   O,   E,   U,   I,   D,   H,   T,   N,   S,MINS,ENT,             \
           LSFT,SCLN,   Q,   J,   K,   X,   B,   M,   W, V, Z,RSFT,FN3,             \
                LALT,LGUI,          SPC,                RGUI,RALT),

    /* Layer 1: HHKB mode (HHKB Fn)
     * ,-----------------------------------------------------------.
     * |Pwr| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |LClick|MouU|RClick|   |   |   |   |Psc|Slk|Pus|Up |   |Backs|
     * |-----------------------------------------------------------|
     * |      |MouL|MouD|MouR|   |   |  *|  /|Hom|PgU|Lef|Rig|Enter   |
     * |-----------------------------------------------------------|
     * |        |VoD|VoU|Mut|   |   |  +|  -|End|PgD|Dow|      |   |
     * `-----------------------------------------------------------'
     *       |   |     |                       |     |   |
     *       `-------------------------------------------'
     */
    [3] = \ 
    KEYMAP(PWR, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL,   \
           CAPS,TRNS,TRNS,MS_BTN1,MS_BTN2, TRNS,TRNS,TRNS,PSCR,SLCK,PAUS, UP, TRNS, DEL,      \
           TRNS,H,J,K,L,TRNS,PAST,PSLS,HOME,PGUP,LEFT,RGHT,PENT,            \
           TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,PPLS,PMNS,END, PGDN,DOWN,TRNS,TRNS,            \
                TRNS,TRNS,          TRNS,               TRNS,TRNS),
};


#ifdef KEYMAP_SECTION_ENABLE
const uint16_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const uint16_t fn_actions[] PROGMEM = {
#endif
    [0]  = ACTION_LAYER_MOMENTARY(1),
    [1]  = ACTION_LAYER_TOGGLE(2),
    [2]  = ACTION_LAYER_TOGGLE(0),
    [3]  = ACTION_LAYER_MOMENTARY(3),

//  [x] = ACTION_LMOD_TAP_KEY(KC_LCTL, KC_BSPC),        // LControl with tap Backspace
//  [x] = ACTION_LMOD_TAP_KEY(KC_LCTL, KC_ESC),         // LControl with tap Esc
//  [x] = ACTION_FUNCTION_TAP(LSHIFT_LPAREN),           // Function: LShift with tap '('
//  [x] = ACTION_MACRO(HELLO),                          // Macro: say hello
//  [x] = ACTION_MACRO(VOLUP),                          // Macro: media key
};