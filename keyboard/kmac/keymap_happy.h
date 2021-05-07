// KMAC Winkeyless
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    [0] = KEYMAP_HAPPY(\
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL,BSLS,GRV, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC, \
        LCTL,     A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT, \
        LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,FN0, \
        LCTL,LGUI,LALT,             SPC,                     RALT,RGUI,RCTL ),
    [1] = KEYMAP_HAPPY(\
        ESC,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11,F12,INS,DEL, \
        CAPS, Q,  W,  E,  R,  T,  Y,  U,  PSCR,SLCK,PAUS,UP,  RBRC,BSPC, \
        LCTL, VOLD,VOLU,MUTE,F,  G,  PAST,PSLS,HOME,PGUP,LEFT,RIGHT,     ENT, \
        LSFT, Z,  X,  C,  V,  B,  PPLS,PMNS,END, PGDN,DOWN,RSFT,FN0, \
        LCTL,LGUI,LALT,               SPC,                     RALT,RGUI,RCTL ),

};
const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
};
