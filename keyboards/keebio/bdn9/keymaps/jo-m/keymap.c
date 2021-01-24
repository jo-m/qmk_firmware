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
#include "virtser.h"

// layer names
#define _BASE 0
#define _RGB  1

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

enum custom_macro_keycodes {
    KC_MIC_PTT = SAFE_RANGE,

    KC_RGB_OFF,
    KC_RGB_STA,
    KC_RGB_BR_1,
    KC_RGB_RB_2,
    KC_RGB_KN_1,
    KC_RGB_TW_4,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        Base Layer
        +----------+----------+----------+
        | < Vol Dn |          | < PGUP   |
        | Spk Mute | Layer    |          |
        | > Vol Up |          | > PGDN   |
        +----------+----------+----------+
        | Prv Trak | Play/Pau | Nxt Trak |
        +----------+----------+----------+
        | Mic Mute | Mic PTT  | Bl Step  |
        +----------+----------+----------+
     */
    [_BASE] = LAYOUT(
        KC_MUTE,  MO(_RGB),   _______,
        KC_MPRV,  KC_MPLY,    KC_MNXT,
        KC_F20,   KC_MIC_PTT, BL_STEP
    ),

    /*
        RBG Settings
        +---------+---------+-----------+
        | < -Hue  |         | < -Sat    |
        | RGB Mod |         | RGB R Mod |
        | > +Hue  |         | > +Sat    |
        +---------+---------+-----------+
        | Off     | Static  | Breathing |
        +---------+---------+-----------+
        | Knight  | Rainbow | Twinkle   |
        +---------+---------+-----------+
     */
    [_RGB] = LAYOUT(
        RGB_RMOD, _______,     RGB_MOD,
        KC_RGB_OFF,  KC_RGB_STA,  KC_RGB_BR_1,
        KC_RGB_KN_1, KC_RGB_RB_2, KC_RGB_TW_4
    ),
};

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Mic push to talk
    if (keycode == KC_MIC_PTT) {
        tap_code(KC_F20);
        return true;
    }

    if (!record->event.pressed) {
        return true;
    }
    switch (keycode) {
    case KC_RGB_OFF:
        rgblight_disable();
        break;
    case KC_RGB_STA:
        rgblight_enable();
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        break;
    case KC_RGB_BR_1:
        rgblight_enable();
        rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
        break;
    case KC_RGB_RB_2:
        rgblight_enable();
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_MOOD + 2);
        break;
    case KC_RGB_KN_1:
        rgblight_enable();
        rgblight_mode(RGBLIGHT_MODE_KNIGHT + 1);
        break;
    case KC_RGB_TW_4:
        rgblight_enable();
        rgblight_mode(RGBLIGHT_MODE_TWINKLE + 4);
        break;
    }
    return true;
};

// Encoder input
void encoder_update_user(uint8_t index, bool clockwise) {
    // Base layer
    if (layer_state_is(_BASE)) {
        if (index == _LEFT) {
            // Volume down/up
            if (clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
        } else if (index == _RIGHT) {
            // Scroll down/up
            if (clockwise) {
                tap_code(KC_PGUP);
            } else {
                tap_code(KC_PGDN);
            }
        }
    // RGB layer
    } else if(layer_state_is(_RGB)) {
        if (index == _LEFT) {
            if (clockwise) {
                rgblight_decrease_hue();
            } else {
                rgblight_increase_hue();
            }
        }
        else if (index == _RIGHT) {
            if (clockwise) {
                // rgblight_increase_val();
                rgblight_decrease_sat();
            } else {
                // rgblight_decrease_val();
                rgblight_increase_sat();
            }
        }
    }
}

#include "rgblib.c"
