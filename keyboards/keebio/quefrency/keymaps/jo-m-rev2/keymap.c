#include QMK_KEYBOARD_H

#include "unicode.c"
#include "macros.c"

// layer names
#define _BASE 0
#define _FN1  1
#define _LED  2

// keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
    _______,  MO(_LED),  KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   _______,  KC_BSPC,  _______,  \
    KC_MMUTE, KC_MPTT,   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PSCR,  \
    KC_MUTE,  KC_MPLY,   KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   KC_PGUP,  \
    GIT_ADD_P,GIT_COM_M, KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN,  \
    GIT_PULL, GIT_PUSH,  MO(_FN1), KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC,             KC_SPC,   KC_RALT,  KC_RGUI,  KC_RCTL,  MO(_FN1), KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [_FN1] = LAYOUT_65_with_macro(
    _______,  _______,   KC_GRAVE, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  KC_DEL,  _______,  \
    _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  XP(ue,UE),_______,  XP(oe,OE),_______,  _______,  KC_GRAVE, _______,  _______,  \
    _______,  _______,   _______,  XP(ae,AE),_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    _______,  _______,   _______,  TMX_ZOOM, _______,  TMX_CRTE, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PGUP,  _______,  \
    _______,  _______,   _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_END
  ),

  [_LED] = LAYOUT_65_with_macro(
    _______,  _______,   RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW, RGB_M_SN, RGB_M_K,  RGB_M_G,  _______,  _______,  _______,  _______,  _______, _______,   _______,  _______,  _______,  \
    BL_STEP,  BL_BRTG,   RGB_TOG,  RGB_RMOD, RGB_MOD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    RGB_HUD,  RGB_HUI,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    RGB_SAD,  RGB_SAI,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    RGB_VAD,  RGB_VAI,   _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  )
};

enum encoder_names {
  _LEFT,
  _RIGHT,
};

void encoder_update_user(uint8_t index, bool clockwise) {
  // left encoder
  if (index == _LEFT) {
    if (clockwise) {
        tap_code(KC_VOLD);
    } else {
        tap_code(KC_VOLU);
    }
  }
  // right encoder
  else if (index == _RIGHT) {
    if (clockwise) {
        tap_code(KC_PGUP);
    } else {
        tap_code(KC_PGDN);
    }
  }
}
