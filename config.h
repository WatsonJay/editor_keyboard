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

#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#endif
