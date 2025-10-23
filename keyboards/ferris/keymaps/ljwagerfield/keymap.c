// clang-format off
#include QMK_KEYBOARD_H

enum layers { _ALPHA, _NUM, _ARR, _SCROLL, _GOTO_LINE, _SYM, _FN };

enum custom_keycodes {
    LOCK_NUM = SAFE_RANGE,
    LOCK_ARR,
    LOCK_SCROLL,
    UNLOCK_SCROLL,
    UNLOCK_SCROLL_ESC,
    GOTO_LINE
};

// Records the modifiers that were active for the last key press.
static uint8_t last_press_mods = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Alpha (Hands Down Prometheus)
    [_ALPHA] = LAYOUT_split_3x5_2(
        KC_F      , KC_P      , KC_D      , KC_L      , KC_J      ,
        KC_QUOT     , KC_U      , KC_O      , KC_Y      , KC_Q      ,
        LOPT_T(KC_S) , LCTL_T(KC_N) , LT(_ARR, KC_T) , LCMD_T(KC_H) , KC_K      ,
        KC_Z    , LCMD_T(KC_A) , LT(_NUM, KC_E) , LCTL_T(KC_I) , LOPT_T(KC_C) ,
        KC_B      , KC_W      , KC_G      , KC_M      , LOPT(KC_3)     ,
        KC_AT  , KC_ENT    , KC_BSPC   , KC_TAB      , KC_V    ,
        LT(_FN, KC_X)    , LSFT_T(KC_R)   , 
        LT(_SYM, KC_SPC)  , KC_ESC
    ),
    [_NUM] = LAYOUT_split_3x5_2(
        LSFT(KC_3)     , KC_1      , KC_2      , KC_3      , KC_NO     ,
        KC_LPRN   ,    KC_CIRC, KC_SLSH  ,    KC_PERC     ,KC_RPRN,
        LOPT_T(KC_DOT)  , LCTL_T(KC_4)   , LT(_ARR, KC_5)  , LCMD_T(KC_6)    , KC_NO   ,
        KC_TILDE     , RCMD_T(LOCK_NUM)      ,KC_KP_ASTERISK       , LCTL_T(KC_PLUS)      , LOPT_T(KC_MINUS)      ,
        KC_DOLLAR     , KC_7      , KC_8      , KC_9      , KC_NO   ,
        KC_NO     , KC_TRNS   , KC_TRNS   , KC_TRNS   , KC_EQL   ,
        KC_TRNS     , KC_0     ,
        LSFT_T(KC_SPC)  , KC_TRNS
    ),
    [_ARR] = LAYOUT_split_3x5_2(
        // LCMD(KC_B) Added for code navigation because Command + B is used a lot with arrow keys when navigating around code.
        KC_NO   , KC_NO      , LCMD(KC_B)      , KC_NO      , KC_NO   ,
        KC_NO   , KC_LEFT      , KC_UP      , KC_RIGHT      , LOCK_SCROLL   ,
        LOPT_T(LCMD(KC_X)) , LCTL_T(LCMD(KC_C)), KC_NO, LCMD_T(LOCK_ARR), KC_NO,
        LCMD(KC_LEFT) , LOPT(KC_LEFT) , KC_DOWN , LOPT(KC_RIGHT) , LCMD(KC_RIGHT)  ,
        KC_NO   , KC_NO   , GOTO_LINE     , LCMD(KC_V)  , KC_NO  ,
        KC_NO  , KC_TRNS      , KC_TRNS      , KC_TRNS      , LCMD(KC_Z)  ,
        KC_TRNS  , KC_LSFT ,
        KC_TRNS     , KC_TRNS
    ),
    [_SCROLL] = LAYOUT_split_3x5_2(
        KC_NO     , KC_1      , KC_2      , KC_3      , KC_NO     ,
        KC_NO   ,    KC_NO, KC_K  ,    KC_NO      ,KC_U,
        GOTO_LINE  , KC_4   , KC_5  , KC_6    , KC_NO   ,
        KC_NO     , KC_H      ,KC_J       , KC_L      , KC_D      ,
        KC_NO     , KC_7      , KC_8      , KC_9      , KC_NO   ,
        KC_NO     , UNLOCK_SCROLL   , KC_TRNS   , KC_TRNS   , KC_EQL   ,
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

// Shift + BSPC  ->  DEL (Remove Shift)
const key_override_t del_override = {
    .trigger_mods       = MOD_MASK_SHIFT,   // must be held
    .layers             = ~0,               // all layers
    .suppressed_mods    = MOD_MASK_SHIFT,   // don't send Shift to host
    .options            = 0,                // defaults fine
    .negative_mod_mask  = 0,                // no extra forbidden mods
    .custom_action      = NULL,
    .context            = NULL,
    .trigger            = KC_BSPC,          // when Backspace is the key
    .replacement        = KC_DEL,           // send Delete
    .enabled            = NULL
};

// Basic key overrides.
const key_override_t *key_overrides[] = {

    &del_override,

    // CMD + + -> CMD + =
    &(ko_make_basic(MOD_MASK_GUI, KC_PLUS, RCMD(KC_EQL))),
    
    NULL
};

static bool tap(uint16_t keycode) {
    tap_code16(keycode);
    return false;
}

// Removes all layer locks and returns you to the base layer.
static inline bool unlock_all_layer_locks(void) {
    bool had_lock = false;
    // Adjust upper bound if you use many layers; 32 is plenty for most keymaps
    for (uint8_t l = 1; l < 32; l++) {
        if (is_layer_locked(l)) {
            layer_lock_off(l);
            had_lock = true;
        }
        if (layer_state_is(l)) {
            layer_off(l);
            had_lock = true;
        }
    }
    return had_lock;
}

static inline void goto_lock_and_send(uint8_t target_layer, uint16_t send_keycode) {
    layer_on(target_layer);

    // Send the host key
    tap_code16(send_keycode);
}

// Rewrites Alt+Alpha to Hyper+Alpha.
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

static inline void lock_layer(uint8_t target_layer) {
    if (is_layer_locked(target_layer)) {
        layer_lock_off(target_layer);
    } else {
        layer_lock_on(target_layer);
    }
}

// Returns the tap key code for a dual function key. (These are clipped due to the 16-bit size of the key codes in QMK, so we need to do the mapping here.)
static inline uint16_t get_tap_keycode_from_mod_tap(uint16_t keycode) {
    switch (keycode) {
        case LCMD_T(QK_LAYER_LOCK): return QK_LAYER_LOCK;
        case LOPT_T(KC_LPRN): return KC_LPRN;
        case LCTL_T(KC_RPRN): return KC_RPRN;
        case LCMD_T(KC_RABK): return KC_RABK;
        case LOPT_T(KC_LABK): return KC_LABK;
        case LCTL_T(KC_PLUS): return KC_PLUS;
        case LOPT_T(LCTL(LSFT(KC_BSPC))): return LCTL(LSFT(KC_BSPC));
        case LOPT_T(LCMD(KC_X)): return LCMD(KC_X);
        case LCTL_T(LCMD(KC_C)): return LCMD(KC_C);
    }

    return 0;
}

// Returns the modifiers that will be active when this key code is tapped, e.g. LCMD from LCMD(KC_Z), LSFT from LOPT_T(LSFT(KC_A)), etc.
static inline uint8_t encoded_mods_if_pure_wrapper(uint16_t keycode, uint16_t keycode_from_mod_tap) {
    if (keycode_from_mod_tap) {
        // This will be a key code like LCTL_T(LCMD(KC_C)) or LOPT_T(KC_LPRN) ... The former will return LCMD, whereas the latter will return 0.
        return QK_MODS_GET_MODS(keycode_from_mod_tap);
    }
    if (IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) {
         // Return 0 as this will be a key code like LCMD_T(KC_H)
        return 0;
    }
    // Handle keycodes like LCMD(KC_Z) on the arrows layer.
    return QK_MODS_GET_MODS(keycode);
}

// Called on every key down and up.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // --- Re-write Alt+Alpha to Hyper+Alpha. ---
    uint16_t base_keycode = get_tap_keycode(keycode);

    if (IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) {
        // For any Mod-Tap or Layer-Tap key...
        if (record->event.pressed && record->tap.count > 0) {
            // ...on keyup, IF it was a tap, check if we should trigger the HYPR mapping.
            if (!handle_alt_to_hyper(base_keycode)) {
                last_press_mods = MOD_MASK_CSAG; // CSAG = Hyper
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

    uint16_t keycode_from_mod_tap = get_tap_keycode_from_mod_tap(keycode);

    // Record all the modifiers that are active as this information is used when determining whether the flow tap should be applied to the next key.
    last_press_mods = encoded_mods_if_pure_wrapper(keycode, keycode_from_mod_tap) | get_mods() | get_weak_mods() | get_oneshot_mods();
    
    // On key down, perform the following behavior.
    switch (keycode) {
        case KC_G:
            if (get_mods() == MOD_BIT(KC_LGUI)) {
                // When user presses Command + G, automatically lock the _GOTO_LINE layer for them, so they can easily type in numbers.
                goto_lock_and_send(_GOTO_LINE, LCMD(KC_G));    
                return false;
            }
            break;
        case GOTO_LINE:
            if (layer_state_is(_SCROLL)) {
                tap(KC_TOGGLE_SCROLL);
                layer_off(_SCROLL);
            }
            goto_lock_and_send(_GOTO_LINE, LCMD(KC_G));
            return false;
        case LOCK_SCROLL:
            goto_lock_and_send(_SCROLL, KC_TOGGLE_SCROLL);
            return false;
        case UNLOCK_SCROLL:
            layer_off(_SCROLL);
            return tap(KC_TOGGLE_SCROLL);
        case UNLOCK_SCROLL_ESC:
            layer_off(_SCROLL);
            tap(KC_TOGGLE_SCROLL);
            wait_ms(300); // Allow some time for Homerow to deactivate the scroll overlay before sending the escape command so that it is captured by the underlying application.
            return tap(KC_ESC);
        case KC_ENT:
            if (layer_state_is(_GOTO_LINE)) {
                tap(KC_ENT);
                layer_off(_GOTO_LINE);
                return false;
            }
            break; 
        case RCMD_T(LOCK_NUM):
             if (record->tap.count > 0) { // Ensure this is a tap
                lock_layer(_NUM);
                return false;
            }
            return true; // Pass through hold
        case LCMD_T(LOCK_ARR):
             if (record->tap.count > 0) { // Ensure this is a tap
                lock_layer(_ARR);
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

    // If this is a dual function key, then send the tap on key down.
    if (keycode_from_mod_tap) {
        return tap(keycode_from_mod_tap);
    }

    // Shift + Space -> CAP WORD
    if (get_mods() & MOD_MASK_SHIFT && get_tap_keycode(keycode) == KC_SPC) {
        caps_word_toggle();
        return false;
    }

    return true;
}

// Return if this key code should be included in a FlowTap session.
bool is_flow_tap_keycode(uint16_t keycode) {
    switch (get_tap_keycode(keycode)) {
        // TODO: Add all symbols here.
        case KC_SPC:
        case KC_A ... KC_Z:
            return true;
    }

    return false;
}

// Return the time in milliseconds that this key needs to have been from the previous key in order for it to be considered to be part of the FlowTap session.
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
    // Tap/holds where the tap never needs to be part of a flow tap session.
    switch (get_tap_keycode(keycode)) {
        case KC_ESC:
            return 0;
    }

    // If previous key or current key have Ctrl, Alt, or Cmd pressed, then disable flow tap.
    // We do this for the previous key too because performing Command + C and then Alt + Alpha 
    // (for a hyper shortcut) is a common workflow for us. We found that without checking the 
    // previous key's modifiers, the hyper shortcut just gets registered as alphas.
    if ((last_press_mods | get_mods()) & MOD_MASK_CAG) {
        return 0;
    }

    // Prevents non-prose keys like Enter or Escape from starting a FlowTap session for the next key press.
    // Else, if you hit enter multiple times and then quickly go to press the up arrow, then you'll actually 
    // get the tap action on the key that takes you into the arrows layer. Whereas instead, if we remove 
    // enter from the flow tap, then you'll instantly access the arrows layer after hitting a load of enter keys.
    if (!is_flow_tap_keycode(prev_keycode)) {
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