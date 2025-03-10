#include QMK_KEYBOARD_H

#include "macros.h"
#include "unicode.inc"

// Layer names
#define _BASE 0
#define _FN1  1
#define _LED  2

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
    KC_MUTE,  MO(_LED),  QK_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   _______,  KC_BSPC, _______,  \
    KC_MMUTE, KC_MPTT,   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  C(KC_PSCR),  \
    KC_MUTE,  KC_MPLY,   KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   KC_PGUP,  \
    GIT_ADD_P,GIT_COM_M, KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN,  \
    GIT_PULL, GIT_PUSH,  MO(_FN1), KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC,             KC_SPC,   KC_RALT,  KC_RGUI,  KC_RCTL,  MO(_FN1), KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [_FN1] = LAYOUT_65_with_macro(
    _______,  _______,   KC_GRAVE, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  KC_DEL,  _______,  \
    _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  UP(ue,UE),_______,  UP(oe,OE),_______,  _______,  KC_GRAVE, _______,  _______,  \
    _______,  _______,   _______,  UP(ae,AE),_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    _______,  _______,   _______,  TMX_ZOOM, _______,  TMX_CRTE, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PGUP,  _______,  \
    _______,  _______,   _______,  _______,  _______,  _______,  BL_STEP,            BL_STEP,  _______,  _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_END
  ),

  [_LED] = LAYOUT_65_with_macro(
    _______,  _______,   UG_TOGG,  UG_PREV,  UG_NEXT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,   _______,  _______,  _______,  \
    UG_HUED,  UG_HUEU,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    UG_SATD,  UG_SATU,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    UG_VALD,  UG_VALU,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    BL_STEP,  _______,   _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  )
};

enum encoder_names {
  _LEFT = 0,
  _RIGHT = 1,
};

bool encoder_update_user(const uint8_t index, const bool clockwise) {
  // Left encoder
  if (index == _LEFT) {
    // Seems to be the other way around
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
  }
  // Right encoder
  else if (index == _RIGHT) {
    // Seems to be the other way around
    if (clockwise) {
        tap_code(KC_WH_U);
    } else {
        tap_code(KC_WH_D);
    }
  }
  return false;
}
