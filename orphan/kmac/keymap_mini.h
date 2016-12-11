// KMAC Winkeyless
static const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /* 0: qwerty */
    [0] = KEYMAP_MINI(\
        A, B, ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL,GRV,BSLS, \
        C, D, TAB, QUOT, COMM,   DOT,   P,   Y,   F,   G,   C,   R,   L, LBRC, RBRC, BSPC, DEL, \
        E, F, LCTL, A,   O,   E,   U,   I,   D,   H,   T,   N,   S, MINS,     ENT,         PGDN, \
        G, H, LSFT, SCLN, Q,  J,   K,   X,   B,   M,   W,   V, Z,       RSFT,          UP, FN0, \
        I, J, LCTL,LGUI,LALT,             SPC,                     RALT,       LEFT, DOWN, RIGHT )

};
static const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_LAYER_MOMENTARY(2),
    [2] = ACTION_LAYER_MOMENTARY(3),
};
