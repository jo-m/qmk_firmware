#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Rotary encoder ideas:
// Zoom
// Arrows
// Sound
// Undo/Redo
// Application Mode Switch

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
    // umlauts
    ae, AE, oe, OE, ue, UE,
    // emojis
    THUU, EXCL, FIST, MAHN, LOL,
    SCRM, HMMM, CRY, BOX
};

const uint32_t PROGMEM unicode_map[] = {
    [ae]    =  0x00E4,  // ä
    [AE]    =  0x00C4,  // Ä
    [oe]    =  0x00F6,  // ö
    [OE]    =  0x00D6,  // Ö
    [ue]    =  0x00FC,  // ü
    [UE]    =  0x00DC,  // Ü
    [THUU]  = 0x1F44D, // 👍
    [EXCL]  = 0x1F44C, // 👌
    [FIST]  = 0x1F44A, // 👊
    [MAHN]  = 0x1F446, // 👆
    [LOL]   = 0x1F602, // 😂
    [SCRM]  = 0x1F631, // 😱
    [HMMM]  = 0x1F9D0, // 🧐
    [CRY]   = 0x1F62D, // 😭
    [BOX]   = 0x1F94A, // 🥊
};


// macros
enum custom_macro_keycodes {
    GIT_ADD_P = SAFE_RANGE,
    GIT_COM_M,
    GIT_PUSH,
    GIT_PULL,
    CD_DOWN,
    CD_BACK,
    LS_LA,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }
    switch (keycode) {
    case GIT_ADD_P:
        SEND_STRING("git add -p");
        break;
    case GIT_COM_M:
        SEND_STRING("git commit -m ''");
        tap_code(KC_LEFT);
        break;
    case GIT_PUSH:
        SEND_STRING("git push");
        break;
    case GIT_PULL:
        SEND_STRING("git pull");
        break;
    case CD_DOWN:
        SEND_STRING("cd ..\n");
        break;
    case CD_BACK:
        SEND_STRING("cd -\n");
        break;
    case LS_LA:
        SEND_STRING("ls -lah\n");
        break;
    }
    return true;
};

// keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
    KC_VOLD,  KC_VOLU,   KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   _______,  KC_BSPC,  KC_HOME,  \
    KC_BRID,  KC_BRIU,   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_END,  \
    KC_MUTE,  KC_PSCREEN,KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   KC_PGUP,  \
    GIT_ADD_P,GIT_COM_M, KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN,  \
    GIT_PUSH, GIT_PULL,  MO(_FN1), KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC,             KC_SPC,   KC_RALT,  KC_RGUI,  KC_RCTL,  MO(_FN1), KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [_FN1] = LAYOUT_65_with_macro(
    _______,  _______,   _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  KC_DEL,  _______,  \
    _______,  _______,   _______,  _______,  _______,  X(EXCL),  X(LOL),   X(THUU),  _______,  XP(ue,UE),_______,  XP(oe,OE),_______,  _______, KC_GRAVE,  _______,  _______,  \
    _______,  _______,   _______,  XP(ae,AE),X(SCRM),  _______,  X(FIST),  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,  _______,  _______,  \
    CD_BACK,  _______,   _______,  X(MAHN),  _______,  X(CRY),   _______,  X(BOX),   _______,  X(HMMM),  _______,  _______,  _______,  _______,  KC_PGUP,  _______,  \
    CD_DOWN,  LS_LA,     _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_RGHT,  KC_END
  )
};
