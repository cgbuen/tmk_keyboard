// KMAC Winkeyless
static const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /* 0: qwerty */
    [0] = KEYMAP_HAPPY(\
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   SLSH,EQL,GRV,BSLS, \
        TAB, QUOT, COMM,   DOT,   P,   Y,   F,   G,   C,   R,   L, LBRC, RBRC, BSPC,\
        LCTL, A,   O,   E,   U,   I,   D,   H,   T,   N,   S, MINS,     ENT, \
        LSFT, SCLN, Q,  J,   K,   X,   B,   M,   W,   V, Z,       RSFT, FN0, \
        LGUI,NO,LALT,             FN0,                     RALT,NO,RGUI  ),
    [1] = KEYMAP_HAPPY(\
        ESC, F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,   F11, F12 ,GRV,BSLS, \
        TAB, FN3, FN4,   FN5,   P,   Y,   F,   G,   UP,   R,   L, LBRC, RBRC, DEL,\
        LCTL, A,   O,   E,   U,   I,   D,   LEFT,DOWN,RIGHT,   S, MINS,     ENT,         \
        FN1, SCLN, Q,  J,   K,   X,   B,   M,   W,   V, Z,       RSFT,          FN0, \
        LGUI,NO,LALT,             FN0,                     RALT,NO,RGUI  ),

    [2] = KEYMAP_HAPPY(\
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   SLSH,EQL,GRV,BSLS, \
        TAB, FN6, FN7,   FN8,   P,   Y,   F,   G,   PGUP,   R,   L, LBRC, RBRC, BSPC, \
        LCTL, A,   O,   E,   U,   I,   D,   HOME,   PGDN,   END,   S, MINS,     ENT,       \
        TRNS, SCLN, Q,  J,   K,   X,   B,   M,   W,   V, Z,       RSFT,    FN0, \
        LGUI,NO,LALT,             FN0,                     RALT,NO,RGUI  ),

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
    [2] = ACTION_LAYER_MOMENTARY(3),
    [3] = ACTION_MACRO(AE),
    [4] = ACTION_MACRO(AA),
    [5] = ACTION_MACRO(OE),
    [6] = ACTION_MACRO(CAE),
    [7] = ACTION_MACRO(CAA),
    [8] = ACTION_MACRO(COE)
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