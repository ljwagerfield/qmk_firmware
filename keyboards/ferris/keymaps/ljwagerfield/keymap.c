// clang-format off
#include QMK_KEYBOARD_H

enum layers { _ALPHA, _NUM, _ARR, _SYM, _FN, _HYP1 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Alpha (Hands Down Prometheus)
    [_ALPHA] = LAYOUT_split_3x5_2(
        KC_F      , KC_P      , KC_D      , KC_L      , KC_B      ,
        KC_Q     , KC_U      , KC_O      , KC_Y      , KC_V      ,
        LOPT_T(KC_S) , LCTL_T(KC_N) , LT(_ARR, KC_T) , LCMD_T(KC_H) , KC_K      ,
        KC_TAB    , LCMD_T(KC_A) , LT(_NUM, KC_E) , LCTL_T(KC_I) , LOPT_T(KC_C) ,
        KC_BSPC      , KC_W      , KC_G      , KC_M      , KC_J     ,
        KC_Z  , KC_DOT    , KC_COMMA   , KC_DQUO      , KC_ENT    ,
        LT(_FN, KC_X)    , LSFT_T(KC_R)   , 
        LT(_SYM, KC_SPC)  , LT(_HYP1, KC_ESC)
    ),
    [_NUM] = LAYOUT_split_3x5_2(
        KC_NO     , KC_1      , KC_2      , KC_3      , KC_NO     ,
        KC_NO   , KC_PERC   , KC_CIRC  , KC_DOLLAR   , KC_POUND     ,
        LOPT_T(KC_MINUS)  , LCTL_T(KC_4)   , LT(_ARR, KC_5)  , LCMD_T(KC_6)    , KC_NO   ,
        KC_NO     , QK_LAYER_LOCK      , KC_SLSH      , LCTL_T(KC_KP_ASTERISK)      , LOPT_T(KC_PLUS)      ,
        KC_TRNS     , KC_7      , KC_8      , KC_9      , KC_NO   ,
        KC_NO     , KC_TRNS   , KC_TRNS   , KC_TRNS   , KC_TRNS   ,
        KC_TRNS     , LSFT_T(KC_0)     ,
        KC_SPC  , KC_TRNS // 'KC_SPC' without 'LT(_SYM,_)' because encouraging access to other symbol layers from non-base layers gives the illusion you can access any symbol from any layer, which you can't (as supporting this is problematic and leads to a confusing design). We make exception to allowing access to arrows from the num layer, as these aren't typable symbols.
    ),
    [_ARR] = LAYOUT_split_3x5_2(
        KC_NO   , KC_NO      , KC_NO      , KC_NO      , KC_NO   ,
        KC_NO   , LCTL(KC_LEFT)      , KC_UP      , LCTL(KC_RIGHT)      , KC_NO   ,
        LCMD(KC_X), LCMD(KC_C), KC_NO, QK_LAYER_LOCK, KC_NO,
        LCMD(KC_LEFT) , LOPT(KC_LEFT) , KC_DOWN , LOPT(KC_RIGHT) , LCMD(KC_RIGHT)  ,
        KC_TRNS   , KC_NO   , KC_NO     , LCMD(KC_V)  , KC_NO  ,
        KC_NO  , KC_LEFT      , LCMD(KC_Z)      , KC_RIGHT      , KC_TRNS  ,
        KC_TRNS  , KC_LSFT , // TODO: KC_LSFT must also be shift on hold
        KC_SPC     , KC_TRNS
    ),
    [_SYM] = LAYOUT_split_3x5_2(
        KC_AT   , KC_AMPR      , KC_SLSH      , KC_QUOT      , KC_NO   ,
        KC_NO      , KC_KP_ASTERISK, KC_GRAVE      , KC_PLUS      , KC_PIPE   ,
        LOPT_T(KC_MINUS)   , LCTL_T(KC_LABK)   , KC_EQL     , LCMD_T(KC_RABK)   , KC_TILDE   ,
        KC_HSH , LCMD_T(KC_RCBR) , KC_LCBR , LOPT_T(KC_DOLLAR) , LCTL_T(KC_EXLM)  ,
        KC_QUES   , KC_UNDS   , KC_LBRC     , KC_RBRC  , KC_POUND  ,
        KC_CIRC  , KC_SEMICOLON      , KC_NO      , KC_NO      , KC_PERC  ,
        KC_BSLS  , LSFT(KC_R) ,
        KC_NO    , KC_NO
    ),
    [_FN] = LAYOUT_split_3x5_2(
        KC_NO , KC_NO     , LCTL(LCMD(KC_Q))     , KC_NO     , KC_NO     ,
        KC_NO , KC_F1   , KC_F2   , KC_F3   , KC_F4   , 
        KC_NO , KC_MPRV   , KC_MPLY   , KC_MNXT   , KC_NO   ,
        KC_NO , KC_F5 , KC_F6 , KC_F7  , KC_F8  ,
        KC_NO , KC_NO     , KC_VOLD    , KC_VOLU    , KC_NO    ,
        KC_NO , KC_F9 , KC_F10   , KC_F11   , KC_F12   , 
        KC_NO   , KC_NO   ,
        KC_NO   , QK_BOOT
    ),
    [_HYP1] = LAYOUT_split_3x5_2(
        HYPR(KC_F) , HYPR(KC_P) ,  HYPR(KC_D) , HYPR(KC_L) , HYPR(KC_B) ,
        HYPR(KC_Q) , HYPR(KC_U) , HYPR(KC_O) , HYPR(KC_Y) , HYPR(KC_V) ,
        HYPR(KC_S) , HYPR(KC_N) , HYPR(KC_T) , HYPR(KC_H) , HYPR(KC_K) ,
        HYPR(KC_TAB) , HYPR(KC_A) , HYPR(KC_E) , HYPR(KC_I) , HYPR(KC_C) ,
        HYPR(KC_BSPC) , HYPR(KC_W) , HYPR(KC_G) , HYPR(KC_M) , HYPR(KC_J) ,
        HYPR(KC_Z) , HYPR(KC_DOT) , HYPR(KC_COMMA) , HYPR(KC_QUOT) , HYPR(KC_ENT) ,
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

// Shift + .  ->  :
const key_override_t sh_dot__to__colon =
  ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);

// Shift + ,  ->  )
const key_override_t sh_comm__to__rparen =
  ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_RPRN);

// Shift + "  ->  (
const key_override_t sh_dquo__to__lparen =
  ko_make_basic(MOD_MASK_SHIFT, KC_DQUO, KC_LPRN);

const key_override_t *key_overrides[] = {
  &sh_spc_to_caps,
  &sh_dot__to__colon,
  &sh_comm__to__rparen,
  &sh_dquo__to__lparen,
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
        case LCMD_T(KC_RCBR): return tap(KC_RCBR);
        case LCTL_T(KC_LABK): return tap(KC_LABK);
        case LCMD_T(KC_RABK): return tap(KC_RABK);
        case LOPT_T(KC_DOLLAR): return tap(KC_DOLLAR);
        case LCTL_T(KC_EXLM): return tap(KC_EXLM);
    }

    return true;
}

// https://docs.qmk.fm/tap_hold#flow-tap
bool is_flow_tap_key(uint16_t keycode) {
    if (get_mods() & MOD_MASK_CAG) return false;

    switch (get_tap_keycode(keycode)) {
        case KC_A ... KC_Z:
            return true;
    }

    return false;
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