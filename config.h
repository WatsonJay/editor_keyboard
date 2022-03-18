// Copyright 2022 WatsonJay (@WatsonJay)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */

#include "config_common.h"

/* USB Device descriptor parameter */
#define DEVICE_VER      0x0001

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 5

/* key matrix pins */
#define MATRIX_ROW_PINS { D2, D4, C6, D7, F1 }
#define MATRIX_COL_PINS { E6, B4, B5, F4, F5 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

#define RGBLED_NUM 15
#define RGB_DI_PIN D3

#define DEBOUNCE 5
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#endif

#define ENCODERS_PAD_A { B2, B3, F6 }
#define ENCODERS_PAD_B { B6, B1, F7 }

#define ENCODER_RESOLUTION 4

/* define oled display*/
#define SSD1306OLED
#define OLED_DISPLAY_128X64
#define OLED_TIMEOUT 100000
