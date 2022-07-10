/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_TAP_DANCE_ENTRIES 4
#define VIAL_COMBO_ENTRIES 4

#define VIAL_KEYBOARD_UID {0xED, 0xB5, 0x12, 0x45, 0xED, 0x07, 0xCD, 0xAE}


#undef RGBLIGHT_ANIMATIONS
#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    // #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
#endif
#ifdef RGB_MATRIX_ENABLE
    #define DRIVER_LED_TOTAL 15
    #define RGB_DI_PIN D3
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    // #define RGB_MATRIX_KEYPRESSES
    #define ENABLE_RGB_MATRIX_BREATHING
    #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #define VIALRGB_NO_DIRECT
#endif
