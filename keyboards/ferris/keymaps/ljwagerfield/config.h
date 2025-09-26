// clang-format off
// #include "quantum_keycodes.h"
#define RP2040_FLASH_GD25Q64CS
#pragma once

// Tap Hold
// https://docs.qmk.fm/tap_hold
#define FLOW_TAP_TERM 500 // Max: 500 https://github.com/qmk/qmk_firmware/blob/8f728aa7311f3d66d8c7b68bf85e5da605909b4c/quantum/action_tapping.c#L871
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD

// Quick Tap
// https://docs.qmk.fm/tap_hold#quick-tap-term
#define QUICK_TAP_TERM_PER_KEY

// Caps Word
// https://docs.qmk.fm/features/caps_word
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 5000

// Custom Keycodes
#define KC_DICT LCTL(LOPT(KC_D)) // 🎙️ Dictation
#define KC_DICTATION KC_DICT     // 🎙️ Dictation

#define KC_POUND LSFT(KC_3) // 💰 £
#define KC_HSH LOPT(KC_3)