
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
                    MACRO( D(LCTL), D(LSFT),D(U), U(LCTL),U(LSFT), U(U),D(0), U(0),D(0),U(0), D(E), U(E),D(4),U(4), D(ENT), U(ENT), END) :
                    MACRO_NONE );
        case AA:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(LSFT),D(U), U(LCTL),U(LSFT), U(U),D(0), U(0),D(0),U(0), D(E), U(E),D(5),U(5), D(ENT), U(ENT), END) :
                    MACRO_NONE );
        case OE:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(LSFT),D(U), U(LCTL),U(LSFT), U(U),D(0), U(0),D(0),U(0), D(F), U(F),D(6),U(6), D(ENT), U(ENT), END) :
                    MACRO_NONE );
        case CAE:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(LSFT),D(U), U(LCTL),U(LSFT), U(U),D(0), U(0),D(0),U(0), D(C), U(C),D(4),U(4), D(ENT), U(ENT), END) :
                    MACRO_NONE );
        case CAA:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(LSFT),D(U), U(LCTL),U(LSFT), U(U),D(0), U(0),D(0),U(0), D(C), U(C),D(5),U(5), D(ENT), U(ENT), END) :
                    MACRO_NONE );
        case COE:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(LSFT),D(U), U(LCTL),U(LSFT), U(U),D(0), U(0),D(0),U(0), D(D), U(D),D(6),U(6), D(ENT), U(ENT), END) :
                    MACRO_NONE );
    }
    return MACRO_NONE;
}