#ifndef KB_H
#define KB_H

#include "quantum.h"

#define KEYMAP( \
	K00, K01, K02, K03,      \
	K10, K11, K12, K13, K14, \
	K20, K21, K22, K23, K24, \
	     K31, K32, K33, K34  \
) { \
	{ K00,   K01,   K02,   K03,   KC_NO }, \
	{ K10,   K11,   K12,   K13,   K14 }, \
	{ K20,   K21,   K22,   K23,   K24 }, \
	{ KC_NO, K31,   K32,   K33,   K34 }  \
}

#endif