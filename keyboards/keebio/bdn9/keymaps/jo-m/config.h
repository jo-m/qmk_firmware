#pragma once

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_KEYPRESSES
#endif

// remove default animations
#undef RGBLIGHT_ANIMATIONS

// enable some
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_TWINKLE
