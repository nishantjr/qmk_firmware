// Copyright 2022 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layer {
    _BS, // Base
    _VI, // vi input
    _MS, // mouse
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BS] = LAYOUT_all(
      _______, _______, KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_INS,  KC_PSCR, _______, _______, _______,
                        KC_TAB,  KC_Q,    KC_W   , KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, _______, _______, _______,
                        KC_ESC,  KC_A,    KC_S   , KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, _______, KC_ENT,  KC_PGUP, _______, _______,
                        _______, KC_LSFT, KC_Z   , KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN, _______, _______,
                        KC_LCTL, KC_LALT, TT(_MS), TT(_VI), KC_LGUI, KC_SPC,  KC_SPC,  KC_BSLS, _______, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [_VI] = LAYOUT_all(
      _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______, _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_MS] = LAYOUT_all(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______, _______, _______, _______, _______,
                        KC_BTN1, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BS:
        rgblight_setrgb(0x00,  0x00, 0x00);
        break;
    case _VI:
        rgblight_setrgb(0x80,  0x00, 0x00);
        break;
    case _MS:
        rgblight_setrgb(0x40,  0x40, 0x00);
        break;
    }
  return state;
}
