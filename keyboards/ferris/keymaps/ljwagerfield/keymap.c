// clang-format off
#include QMK_KEYBOARD_H

enum layers { _ALPHA, _NUM, _SCROLL, _GOTO_LINE, _ARR, _SYM, _FN };

enum custom_keycodes {
    LOCK_NUM = SAFE_RANGE,
    LOCK_SCROLL_SPC,
    UNLOCK_SCROLL,
    UNLOCK_SCROLL_ESC,
    GOTO_LINE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Alpha (Hands Down Prometheus)
    [_ALPHA] = LAYOUT_split_3x5_2(
        KC_B      , KC_P      , KC_D      , KC_L      , KC_J      ,
        KC_QUOT     , KC_U      , KC_O      , KC_Y      , KC_Q      ,
        LOPT_T(KC_S) , LCTL_T(KC_N) , LT(_ARR, KC_T) , LCMD_T(KC_H) , KC_K      ,
        KC_Z    , LCMD_T(KC_A) , LT(_NUM, KC_E) , LCTL_T(KC_I) , LOPT_T(KC_C) ,
        KC_F      , KC_W      , KC_G      , KC_M      , LOPT(KC_3)     ,
        KC_AT  , KC_ENT    , KC_BSPC   , KC_TAB      , KC_V    ,
        LT(_FN, KC_X)    , LSFT_T(KC_R)   , 
        LT(_SYM, KC_SPC)  , KC_ESC
    ),
    [_NUM] = LAYOUT_split_3x5_2(
        LSFT(KC_3)     , KC_1      , KC_2      , KC_3      , KC_NO     ,
        KC_LPRN   ,    KC_CIRC, KC_SLSH  ,    KC_PERC     ,KC_RPRN,
        KC_DOT  , KC_4   , LT(_ARR, KC_5)  , KC_6    , KC_NO   ,
        KC_TILDE     , RCMD_T(LOCK_NUM)      ,KC_KP_ASTERISK       , LCTL_T(KC_PLUS)      , LOPT_T(KC_MINUS)      ,
        KC_DOLLAR     , KC_7      , KC_8      , KC_9      , KC_NO   ,
        KC_NO     , KC_TRNS   , KC_TRNS   , KC_TRNS   , KC_EQL   ,
        KC_TRNS     , KC_0     ,
        LSFT_T(KC_SPC)  , KC_TRNS
    ),
    [_SCROLL] = LAYOUT_split_3x5_2(
        KC_NO     , KC_1      , KC_2      , KC_3      , KC_NO     ,
        KC_NO   ,    KC_NO, KC_K  ,    KC_NO      ,KC_U,
        GOTO_LINE  , KC_4   , KC_5  , KC_6    , KC_NO   ,
        KC_NO     , KC_H      ,KC_J       , KC_L      , KC_D      ,
        KC_NO     , KC_7      , KC_8      , KC_9      , KC_NO   ,
        KC_NO     , KC_TRNS   , KC_TRNS   , KC_TRNS   , KC_EQL   ,
        KC_TRNS     , KC_LSFT     ,
        UNLOCK_SCROLL  , UNLOCK_SCROLL_ESC
    ),
    [_GOTO_LINE] = LAYOUT_split_3x5_2(
        KC_NO     , KC_1      , KC_2      , KC_3      , KC_NO     ,
        KC_NO   ,    KC_NO, KC_NO  ,    KC_NO     ,KC_NO,
        KC_NO  , KC_4   , KC_5  , KC_6    , KC_NO   ,
        KC_NO     , KC_COLN      ,KC_NO       , KC_NO      , KC_NO      ,
        KC_NO     , KC_7      , KC_8      , KC_9      , KC_NO   ,
        KC_NO     , KC_TRNS   , KC_TRNS   , KC_TRNS   , KC_NO   ,
        KC_TRNS     , KC_0     ,
        KC_ESC  , KC_ESC
    ),
    [_ARR] = LAYOUT_split_3x5_2(
        KC_NO   , KC_NO      , KC_NO      , KC_NO      , KC_NO   ,
        KC_LPRN   , KC_LEFT      , KC_UP      , KC_RIGHT      , KC_RPRN   ,
        LCMD(KC_X), LCMD(KC_C), KC_NO, QK_LAYER_LOCK, KC_NO,
        LCMD(KC_LEFT) , LOPT(KC_LEFT) , KC_DOWN , LOPT(KC_RIGHT) , LCMD(KC_RIGHT)  ,
        KC_NO   , KC_NO   , KC_NO     , LCMD(KC_V)  , KC_NO  ,
        KC_NO  , KC_TRNS      , KC_TRNS      , KC_TRNS      , LCMD(KC_Z)  ,
        KC_TRNS  , KC_LSFT ,
        LOCK_SCROLL_SPC     , KC_TRNS
    ),
    [_SYM] = LAYOUT_split_3x5_2(
        KC_EXLM         , KC_GRAVE, KC_DOLLAR      , KC_LCBR      , KC_RCBR   ,
        KC_NO      , KC_AMPERSAND, KC_COLN            , KC_PIPE, KC_PLUS   ,
        LOPT_T(KC_LPRN)   , LCTL_T(KC_RPRN)   , KC_DQUO     , LCMD_T(KC_COMMA)   , KC_LBRC   ,
        KC_TILDE , LCMD_T(KC_RABK) , KC_EQL , LOPT_T(KC_LABK) , LCTL_T(KC_MINUS)  ,
        KC_QUES   , KC_KP_ASTERISK   , KC_SLSH     , KC_DOT  , KC_RBRC  ,
        KC_NO  , KC_SEMICOLON      , KC_CIRC      , KC_PERC      , KC_UNDERSCORE  ,
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
    )
};

static bool tap(uint16_t keycode) {
    tap_code16(keycode);
    return false;
}

static inline bool unlock_all_layer_locks(void) {
    bool had_lock = false;
    // Adjust upper bound if you use many layers; 32 is plenty for most keymaps
    for (uint8_t l = 0; l < 32; l++) {
        if (is_layer_locked(l)) {
            layer_lock_off(l);
            had_lock = true;
        }
    }
    return had_lock;
}

static inline void goto_lock_and_send(uint8_t target_layer, uint16_t send_keycode) {
    // If you prefer only one lock at a time, clear others first:
    unlock_all_layer_locks();

    // Move to target layer immediately
    layer_move(target_layer);

    // Lock that layer so Esc (below) can unlock it
    layer_lock_on(target_layer);

    // Send the host key
    tap_code16(send_keycode);
}

static bool handle_alt_to_hyper(uint16_t keycode) {
    // 1. Check if the key is an alpha character.
    if (!(keycode >= KC_A && keycode <= KC_Z)) {
        return true; // Not for us, process normally.
    }

    uint8_t mods = get_mods();
    bool alt_is_held = (mods & MOD_MASK_ALT) != 0;
    bool shift_is_held = (mods & MOD_MASK_SHIFT) != 0;
    bool other_mods_are_held = (mods & (MOD_MASK_CTRL | MOD_MASK_GUI)) != 0;

    // CASE 1: Alt + Shift are held (but not Ctrl or GUI)
    if (alt_is_held && shift_is_held && !other_mods_are_held) {
        uint16_t target_keycode;
        // Get the 0-indexed position of the letter in the alphabet (A=0, Z=25)
        uint8_t alpha_pos = keycode - KC_A;

        if (alpha_pos < 24) {
            // A-X (positions 0-23) map to F1-F24
            target_keycode = KC_F1 + alpha_pos;
        } else {
            // Y (position 24) -> 0
            // Z (position 25) -> 1
            target_keycode = KC_0 + (alpha_pos - 24);
        }

        tap_code16(HYPR(target_keycode));
        return false; // We handled it, stop further processing.
    }

    // CASE 2: Alt-only is held (but not Shift, Ctrl, or GUI)
    if (alt_is_held && !shift_is_held && !other_mods_are_held) {
        tap_code16(HYPR(keycode));
        return false; // We handled it, stop further processing.
    }

    // No specific Alt or Alt+Shift combo was matched, so process normally.
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // --- Re-write Alt+Alpha to Hyper+Alpha. ---
    uint16_t base_keycode = get_tap_keycode(keycode);

    if (IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) {
        // For any Mod-Tap or Layer-Tap key...
        if (record->event.pressed && record->tap.count > 0) {
            // ...on keyup, IF it was a tap, check if we should trigger the HYPR mapping.
            if (!handle_alt_to_hyper(base_keycode)) {
                return false; // Handler consumed the event.
            }
        }
    } else {
        // For any other normal key...
        if (record->event.pressed) {
            // ...on keydown, check if we should trigger the HYPR mapping.
            if (!handle_alt_to_hyper(base_keycode)) {
                return false; // Handler consumed the event.
            }
        }
    }
    // --- End of Alt -> Hyper Logic ---


    if (!record->event.pressed) {
        // On key up, perform normal QMK behaviour.
        return true;
    }

    // On key down, perform the following behavior.
    switch (keycode) {
        case GOTO_LINE:
            tap(KC_TOGGLE_SCROLL);
            goto_lock_and_send(_GOTO_LINE, LCMD(KC_G));
            return false;
        case UNLOCK_SCROLL:
            layer_lock_off(_SCROLL);
            return tap(KC_TOGGLE_SCROLL);
        case UNLOCK_SCROLL_ESC:
            layer_lock_off(_SCROLL);
            tap(KC_TOGGLE_SCROLL);
            return tap(KC_ESC);
        case KC_ENT:
            if (is_layer_locked(_GOTO_LINE)) {
                layer_lock_off(_GOTO_LINE);
            }
            break; // Let KC_ENT pass through
        case LOCK_SCROLL_SPC:
            if (is_layer_locked(_ARR)) {
                return tap(KC_SPC);
            } else {
                goto_lock_and_send(_SCROLL, KC_TOGGLE_SCROLL);
                return false;
            }
        case RCMD_T(LOCK_NUM):
             if (record->tap.count > 0) { // Ensure this is a tap
                if (is_layer_locked(_NUM)) {
                    layer_lock_off(_NUM);
                } else {
                    layer_lock_on(_NUM);
                }
                return false;
            }
            return true; // Pass through hold
    }

    if (get_tap_keycode(keycode) == KC_ESC) {
        if (unlock_all_layer_locks()) {
            return false; // Swallow ESC if a layer was unlocked.
        }
    }

    // We only want this guard for dual-function key handlers (which follow below)...
    if (record->tap.count == 0) {
        return true;
    }

    switch (keycode) {
        case LOPT_T(KC_LPRN): return tap(KC_LPRN);
        case LCTL_T(KC_RPRN): return tap(KC_RPRN);
        case LCMD_T(KC_RABK): return tap(KC_RABK);
        case LOPT_T(KC_LABK): return tap(KC_LABK);
        case LCTL_T(KC_PLUS): return tap(KC_PLUS);
        case LOPT_T(LCTL(LSFT(KC_BSPC))): return tap(LCTL(LSFT(KC_BSPC)));
    }

    // Shift + Space -> CAP WORD
    if (get_mods() & MOD_MASK_SHIFT && get_tap_keycode(keycode) == KC_SPC) {
        caps_word_toggle();
        return false;
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

            // Lower value is possible here (compared to "R" below) as space is basically never an SFB or double-tapped (unlike R) 
            // so is faster, plus requires less thinking to type space, so generally seems faster / can get away with a shorter flow 
            // tap timeout to allow the symbols layer to be more responsive.
            return 50; 
        case KC_R:
            if (get_tap_keycode(prev_keycode) == KC_SPC) {
                return 0; // Optimisation: Allows symbols and shifted chars immediately after a space 
            }

            // Seems to be the lowest number to allow us to consistently type words like "terror" -- with 2 consecutive Rs which are slower -- within a flow tap.
            // The lower the better (to make "SHIFT" more responsive, preventing unwanted "R" taps being registered mid-prose when we really wanted a shift) 
            // while still being high enough to allow slower words like "terror" with double Rs to be fully within the flow tap term for each R.
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

// Collect all overrides here
const key_override_t *key_overrides[] = {

    // Shift + BSPC  ->  DEL
    &(ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL)),
    
    NULL
};