// clang-format off
#include QMK_KEYBOARD_H

enum layers { _ALPHA, _NUM, _ARR, _SYM, _FN, _HYP1 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Alpha (Hands Down Prometheus)
    [_ALPHA] = LAYOUT_split_3x5_2(
        KC_B      , KC_P      , KC_D      , KC_L      , KC_J      ,
        KC_QUOT     , KC_U      , KC_O      , KC_Y      , KC_Q      ,
        LOPT_T(KC_S) , LCTL_T(KC_N) , LT(_ARR, KC_T) , LCMD_T(KC_H) , KC_K      ,
        KC_Z    , LCMD_T(KC_A) , LT(_NUM, KC_E) , LCTL_T(KC_I) , LOPT_T(KC_C) ,
        KC_F      , KC_W      , KC_G      , KC_M      , KC_PERC     ,
        KC_CIRC  , KC_ENT    , KC_BSPC   , KC_TAB      , KC_V    ,
        LT(_FN, KC_X)    , LSFT_T(KC_R)   , 
        LT(_SYM, KC_SPC)  , LT(_HYP1, KC_ESC)
    ),
    [_NUM] = LAYOUT_split_3x5_2(
        KC_NO     , KC_1      , KC_2      , KC_3      , KC_NO     ,
        KC_NO   , KC_CIRC   , KC_MINUS  , KC_DOLLAR   , KC_POUND     ,
        LCTL(LSFT(KC_BSPC))  , KC_4   , LT(_ARR, KC_5)  , KC_6    , KC_NO   ,
        KC_NO     , QK_LAYER_LOCK      , KC_SLSH      , LCTL_T(KC_KP_ASTERISK)      , LOPT_T(KC_PLUS)      ,
        KC_TRNS     , KC_7      , KC_8      , KC_9      , KC_NO   ,
        KC_NO     , KC_TRNS   , KC_TRNS   , KC_TRNS   , KC_TRNS   ,
        LT(_FN, KC_PERC)     , LSFT_T(KC_0)     ,
        KC_TRNS  , KC_TRNS
    ),
    [_ARR] = LAYOUT_split_3x5_2(
        KC_NO   , KC_NO      , KC_NO      , KC_NO      , KC_NO   ,
        KC_NO   , KC_LEFT      , KC_UP      , KC_RIGHT      , KC_NO   ,
        LCMD(KC_X), LCMD(KC_C), KC_NO, QK_LAYER_LOCK, KC_NO,
        LCMD(KC_LEFT) , LOPT(KC_LEFT) , KC_DOWN , LOPT(KC_RIGHT) , LCMD(KC_RIGHT)  ,
        KC_NO   , KC_NO   , KC_NO     , LCMD(KC_V)  , KC_NO  ,
        KC_NO  , KC_TRNS      , KC_TRNS      , KC_TRNS      , LCMD(KC_Z)  ,
        KC_TRNS  , KC_LSFT , // TODO: KC_LSFT must also be shift on hold
        KC_SPC     , KC_TRNS
    ),
    [_SYM] = LAYOUT_split_3x5_2(
        KC_EXLM         , KC_GRAVE, KC_DOLLAR      , KC_LCBR      , KC_RCBR   ,
        KC_NO      , KC_AMPERSAND, KC_COLN            , KC_PIPE, KC_PLUS   ,
        LOPT_T(KC_LPRN)   , LCTL_T(KC_RPRN)   , KC_DQUO     , LCMD_T(KC_COMMA)   , KC_LBRC   ,
        KC_TILDE , LCMD_T(KC_RABK) , KC_EQL , LOPT_T(KC_LABK) , LCTL_T(KC_MINUS)  ,
        KC_QUES   , KC_KP_ASTERISK   , KC_SLSH     , KC_DOT  , KC_RBRC  ,
        KC_NO  , KC_SEMICOLON      , KC_NO      , KC_NO      , KC_UNDERSCORE  ,
        KC_BSLS  , LSFT(KC_R) ,
        KC_NO    , KC_NO
    ),
    [_FN] = LAYOUT_split_3x5_2(
        KC_NO , KC_NO     , LCTL(LCMD(KC_Q))     , KC_NO     , KC_NO     ,
        KC_NO , KC_F1   , KC_F2   , KC_F3   , KC_F4   , 
        KC_NO , KC_MPRV   , KC_MPLY   , KC_MNXT   , KC_NO   ,
        KC_NO , KC_F5 , KC_F6 , KC_F7  , KC_F8  ,
        KC_NO , KC_VOLD     , KC_MUTE    , KC_VOLU    , KC_NO    ,
        KC_NO , KC_F9 , KC_F10   , KC_F11   , KC_F12   , 
        KC_NO   , KC_NO   ,
        KC_NO   , QK_BOOT
    ),
    [_HYP1] = LAYOUT_split_3x5_2(
        HYPR(KC_B) , HYPR(KC_P) ,  HYPR(KC_D) , HYPR(KC_L) , HYPR(KC_J) ,
        KC_NO , HYPR(KC_U) , HYPR(KC_O) , HYPR(KC_Y) , HYPR(KC_Q) ,
        HYPR(KC_S) , HYPR(KC_N) , HYPR(KC_T) , HYPR(KC_H) , HYPR(KC_K) ,
        HYPR(KC_Z) , HYPR(KC_A) , HYPR(KC_E) , HYPR(KC_I) , HYPR(KC_C) ,
        HYPR(KC_F) , HYPR(KC_W) , HYPR(KC_G) , HYPR(KC_M) , KC_NO ,
        KC_NO , HYPR(KC_ENT) , HYPR(KC_BSPC) , HYPR(KC_TAB) , HYPR(KC_V) ,
        HYPR(KC_X) , HYPR(KC_R) ,
        KC_NO , KC_NO
    )
};

// Shift+Space -> Caps Lock
const key_override_t sh_spc_to_caps =
    ko_make_with_layers_and_negmods(
        MOD_MASK_SHIFT,     // when Shift is held…
        KC_SPC,             // …and Space is pressed…
        KC_CAPS,            // …send Caps Lock
        ~0,                 // active on all layers
        MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI   // but NOT if other mods are down
    );

// Shift + %  ->  £
const key_override_t sh_perc__to__pound =
  ko_make_basic(MOD_MASK_SHIFT, KC_PERC, KC_POUND);

// Shift + ^  ->  @
const key_override_t sh_hat__to__at =
  ko_make_basic(MOD_MASK_SHIFT, KC_CIRC, KC_AT);

// Shift + '  ->  #
const key_override_t sh_quot__to__hash =
  ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_HASH);

const key_override_t *key_overrides[] = {
  &sh_spc_to_caps,
  &sh_perc__to__pound,
  &sh_hat__to__at,
  &sh_quot__to__hash,
  NULL
};


static bool tap(uint16_t keycode) {
    tap_code16(keycode);
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    if (!record->tap.count) return true;

    switch (keycode) {
        case LT(_FN, KC_PERC): return tap(KC_PERC);
        case LOPT_T(KC_LPRN): return tap(KC_LPRN);
        case LCTL_T(KC_RPRN): return tap(KC_RPRN);
        case LCMD_T(KC_RABK): return tap(KC_RABK);
        case LOPT_T(KC_LABK): return tap(KC_LABK);
        case LCTL_T(KC_MINUS): return tap(KC_MINUS);
    }

    return true;
}

bool is_prev_flow_tap_key(uint16_t keycode) {
    switch (get_tap_keycode(keycode)) {
        // TODO: Add all symbols here.
        case KC_SPC:
        case KC_A ... KC_Z:
            return true;
    }

    return false;
}


uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
    // Tap/holds where the tap never needs to be part of a flow tap session.
    switch (get_tap_keycode(keycode)) {
        case KC_ESC:
            return 0;
    }

    // For faster shifted characters, we use CAG instead of CSAG. 
    // The trade-off is that for any shortcut combination that involves a shift, 
    // you must press shift as the last key in that shortcut combination.
    if (get_mods() & MOD_MASK_CAG) {
        return 0;
    }

    // Prevents non-prose keys like Enter or Escape from starting a FlowTap session for the next key press.
    // Else, if you hit enter multiple times and then quickly go to press the up arrow, then you'll actually 
    // get the tap action on the key that takes you into the arrows layer. Whereas instead, if we remove 
    // enter from the flow tap, then you'll instantly access the arrows layer after hitting a load of enter keys.
    if (!is_prev_flow_tap_key(prev_keycode)) {
        return 0;
    }


    // Tap/holds where the tap needs to be part of a flow tap session, but we also want quick access to the layers exposed by the holds.
    switch (get_tap_keycode(keycode)) {
        case KC_T:
        case KC_E:
            // Increase this number if we accidentally trigger holds when typing fast.
            return 100; 
        case KC_SPC:
            if (get_tap_keycode(prev_keycode) == KC_SPC) {
                return 0; // Optimisation: Allows symbols and shifted chars immediately after a space 
            }

            // Lower value is possible here as space is basically never an SFB or double-tapped (unlike R) so is faster,
            // plus requires less thinking to type space, so generally seems faster / can get away with a shorter flow 
            // tap timeout to allow the symbols layer to be more responsive.
            return 50; 
        case KC_R:
            if (get_tap_keycode(prev_keycode) == KC_SPC) {
                return 0; // Optimisation: Allows symbols and shifted chars immediately after a space 
            }

            // Seems to be the lowest number to allow us to consistently type words like "terror" -- with 2 consecutive Rs which are slower -- within a flow tap.
            // The lower the better (we still want "R" to be in flow tap), but if we get faster at typing and can make this
            // lower, then it will result in fewer accidently "r" taps when we actually wanted "shift" holds instead.
            return 90; 
    }

    return FLOW_TAP_TERM;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (get_tap_keycode(keycode)) {
        // Allows you to access the hold states of these keys, even if the previous key press was the same key. 
        // Without the below config, if you typed R and then try to shift another letter by then holding R, it 
        // would instead just type R again, because it would be registered as a tap then hold on the R key, 
        // which the "quick tap" behaviour will just start repeating R instead of taking you into the hold state for R.
        case KC_SPC:
        case KC_T:
        case KC_E:
        case KC_R:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case LSFT_OSM:
        //     return TAPPING_TERM + 50;
        // case LAY1_BSPC:
        //     return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM; 
    }
}