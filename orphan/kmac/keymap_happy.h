// KMAC Winkeyless
static const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /* 0: qwerty */
    [0] = KEYMAP_HAPPY(\
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL,GRV,BSLS, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC, \
        LCTL,     A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT, \
        LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,FN0, \
        FN2,LGUI,LALT,             SPC,                     RALT,FN1,RCTL ),
    [1] = KEYMAP_HAPPY(\
        ESC,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11,F12,GRV,BSLS, \
        CAPS, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   UP,RBRC,DEL, \
        LCTL, A,   S,   D,   F,   G,   H,   J,   K,   L,   LEFT,RIGHT,     ENT, \
        LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, DOWN,RSFT,FN0, \
        FN2,LGUI,LALT,               SPC,                     RALT,FN1,RCTL ),
    [2] = KEYMAP_HAPPY(\
        ESC,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11,F12,GRV,BSLS, \
        CAPS, NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS,PGUP,  RBRC,DEL, \
        LCTL, VOLD,VOLU,MUTE,NO,  NO,  PAST,PSLS,HOME,PGUP,HOME,END,     ENT, \
        LSFT, NO,  NO,  NO,  NO,  NO,  PPLS,PMNS,END, PGDN,PGDN,RSFT,FN0, \
        FN2,LGUI,LALT,               SPC,                     RALT,FN1,RCTL ),
    [3] = KEYMAP_HAPPY(\
        ESC,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11,F12,GRV,BSLS, \
        CAPS, NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS,PGUP,  RBRC,DEL, \
        LCTL, VOLD,VOLU,MUTE,NO,  NO,  PAST,PSLS,HOME,PGUP,HOME,END,     ENT, \
        LSFT, NO,  NO,  NO,  NO,  NO,  PPLS,PMNS,END, PGDN,PGDN,RSFT,FN0, \
        FN2,LGUI,LALT,               SPC,                     RALT,FN1,RCTL ),

};
static const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_LAYER_MOMENTARY(2),
    [2] = ACTION_LAYER_MOMENTARY(3),
};
