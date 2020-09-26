/* Copyright 2019 Danny Nguyen <danny@keeb.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// layer names
#define _BASE 0
#define _RGB  1

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

enum custom_macro_keycodes {
    RGB_OFF = SAFE_RANGE,
    RGB_STA,
    RGB_BR_2,
    RGB_RB_2,
    RGB_KN_1,
    RGB_TW_4,

    ZOOM_0,
};

// RGB Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }
    switch (keycode) {
    case RGB_OFF:
        rgblight_disable();
        break;
    case RGB_STA:
        rgblight_enable();
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        break;
    case RGB_BR_2:
        rgblight_enable();
        rgblight_mode(RGBLIGHT_MODE_BREATHING + 2);
        break;
    case RGB_RB_2:
        rgblight_enable();
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_MOOD + 2);
        break;
    case RGB_KN_1:
        rgblight_enable();
        rgblight_mode(RGBLIGHT_MODE_KNIGHT + 1);
        break;
    case RGB_TW_4:
        rgblight_enable();
        rgblight_mode(RGBLIGHT_MODE_TWINKLE + 4);
        break;

    case ZOOM_0:
        SEND_STRING(SS_LCTL("0"));
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        Base Layer
        +--------+--------+-------+
        | Zoom 0 | Mode   | Reset |
        +--------+--------+-------+
        | Fn7    | Fn8    | Fn9   |
        +--------+--------+-------+
        | Fn10   | Fn11   | Fn12  |
        +--------+--------+-------+
     */
    [_BASE] = LAYOUT(
        ZOOM_0, MO(_RGB), RESET,
        KC_F7,  KC_F8,    KC_F9,
        KC_F10, KC_F11,   KC_F12
    ),

    /*
        RBG Settings
        +---------+---------+-----------+
        | RGB Mod | Mode    | RGB R Mod |
        +---------+---------+-----------+
        | Off     | Static  | Breathing |
        +---------+---------+-----------+
        | Knight  | Rainbow | Twinkle   |
        +---------+---------+-----------+
     */
    [_RGB] = LAYOUT(
        RGB_RMOD, _______,  RGB_MOD,
        RGB_OFF,  RGB_STA,  RGB_BR_2,
        RGB_KN_1, RGB_RB_2, RGB_TW_4
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (layer_state_is(_BASE)) {
        if (index == _LEFT) {
            // Zoom
            if (clockwise) {
                SEND_STRING(SS_LCTL("="));
                SEND_STRING(SS_LCTL("+"));
            } else {
                SEND_STRING(SS_LCTL("-"));
            }
        } else if (index == _RIGHT) {
            // Undo/Redo
            if (clockwise) {
                SEND_STRING(SS_LCTL("y"));
            } else {
                SEND_STRING(SS_LCTL("z"));
            }
        }
    } else if(layer_state_is(_RGB)) {
        if (index == _LEFT) {
            if (clockwise) {
                rgblight_increase_hue();
            } else {
                rgblight_decrease_hue();
            }
        }
        else if (index == _RIGHT) {
            if (clockwise) {
                // rgblight_increase_val();
                rgblight_increase_sat();
            } else {
                // rgblight_decrease_val();
                rgblight_decrease_sat();
            }
        }
    }
}
