// clang-format off
// #include "quantum_keycodes.h"
#define RP2040_FLASH_GD25Q64CS
#pragma once

// Tap Hold
// https://docs.qmk.fm/tap_hold
// FLOW_TAP_TERM MAX: 500 https://github.com/qmk/qmk_firmware/blob/8f728aa7311f3d66d8c7b68bf85e5da605909b4c/quantum/action_tapping.c#L871
// - We use a LONG flow tap term, as we don't care so much about accessing shortcuts (CMD, ALT, CTRL) mid-prose, and are
//   more interested in a snappier feel. We heavily optimise our layer modifiers with lower per-key flow tap terms.
#define FLOW_TAP_TERM 500 
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD

// Quick Tap
// https://docs.qmk.fm/tap_hold#quick-tap-term
#define QUICK_TAP_TERM 0 // Disable so we can access the symbols layer quickly after pressing the spacebar without it registering as a quick tap for doing repeated spaces.

// Caps Word
// https://docs.qmk.fm/features/caps_word
#define CAPS_WORD_IDLE_TIMEOUT 5000

#define KC_POUND LSFT(KC_3) // 💰 £
#define KC_HSH LOPT(KC_3)
#define KC_TOGGLE_SCROLL LCTL(LSFT(KC_BSPC))