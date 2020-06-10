#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// base settings
void keyboard_post_init_user(void) {
  debug_enable=false;
  debug_matrix=false;
  debug_keyboard=false;
  debug_mouse=false;
}
void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX);
};

// layer names
#define _BASE 0
#define _FN1  1

// unicode
enum unicode_names {
    ae,AE,oe,OE,ue,UE,
    SNEK
};
const uint32_t PROGMEM unicode_map[] = {
    [ae]    = 0x00E4,  // ä
    [AE]    = 0x00C4,  // Ä
    [oe]    = 0x00F6,  // ö
    [OE]    = 0x00D6,  // Ö
    [ue]    = 0x00FC,  // ü
    [UE]    = 0x00DC,  // Ü
    [SNEK]  = 0x1F40D, // 🐍
};

// keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
    KC_F1,    KC_F2,    KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,   KC_BSPC,  KC_HOME,  \
    KC_F3,    KC_F4,    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_END,  \
    KC_F5,    KC_F6,    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   KC_PGUP,  \
    KC_F7,    KC_F8,    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN,  \
    KC_F9,    KC_F10,   MO(_FN1), KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC,             KC_SPC,   KC_RALT,  KC_RGUI,  KC_RCTL,  MO(_FN1), KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [_FN1] = LAYOUT_65_with_macro(
    KC_BRID,  KC_BRIU,  KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_BSPC,  _______,  \
    KC_VOLD,  KC_VOLU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  XP(ue,UE),_______,  XP(oe,OE),_______,  _______,  _______,  _______,  _______,  \
    KC_MUTE,  _______,  _______,  XP(ae,AE),X(SNEK),  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,  _______,  _______,  \
 KC_PSCREEN,    RESET,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  KC_HOME,  _______,  KC_END
  )
};

// DEBUG
