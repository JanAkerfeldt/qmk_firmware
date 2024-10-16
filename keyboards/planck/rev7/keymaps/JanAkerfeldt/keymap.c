 /* Copyright 2015-2023 Jack Humbert
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

 hej
 */

#include QMK_KEYBOARD_H
#include "os_detection.h"

enum planck_layers { _QWERTY, _COLEMAK, _DVORAK, _LOWER, _RAISE, _FUNC, _ADJUST };

#define LOWER    MO(_LOWER)
#define RAISE    MO(_RAISE)
#define FUNC     MO(_FUNC)
#define QWERTY   TO(_QWERTY)
#define COLEMAK  TO(_COLEMAK)
#define ADJUST   MO(_ADJUST)

enum swedish_keycodes {
    ARING = SAFE_RANGE,
    AUML,
    OUML,
    ANY
};

#define CTL_ESC LCTL_T(KC_ESC)
#define ALT_ESC LALT_T(KC_ESC)
#define CTL_BSP LCTL_T(KC_BSPC)
#define GUI_GRV LGUI(KC_GRV)

/* clang-format off */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ARING,
    CTL_BSP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    OUML,    AUML,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
    FUNC,    CTL_ESC, ALT_ESC, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_ENT,  KC_RALT, KC_DOWN, KC_RGHT),

[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    OUML,    ARING,
    CTL_BSP, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    AUML,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
    FUNC,    CTL_ESC, ALT_ESC, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_ENT,  KC_RALT, KC_DOWN, KC_RGHT),

[_LOWER] = LAYOUT_planck_grid(
   KC_TILD,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
   _______,  KC_LT,   KC_LBRC, KC_LPRN, KC_LCBR, KC_PERC, KC_AT,   KC_DQUO, KC_EQL,  KC_EXLM, KC_ASTR, KC_PLUS,
   _______,  KC_GT,   KC_RBRC, KC_RPRN, KC_RCBR, KC_DLR,  KC_CIRC, KC_QUOT, KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
   _______,  _______, _______, _______, _______, _______, _______, ADJUST,  _______, _______, _______, _______),

[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE,
    _______, KC_LT,   KC_LBRC, KC_LPRN, KC_LCBR, KC_PERC, KC_HASH, KC_DQUO, KC_EQL,  KC_EXLM, KC_ASTR, KC_PLUS,
    _______, KC_GT,   KC_RBRC, KC_RPRN, KC_RCBR, KC_DLR,  KC_AMPR, KC_QUOT, KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
    _______, _______, _______, _______, ADJUST,  _______, _______, _______, _______, _______, _______, _______),

[_FUNC] = LAYOUT_planck_grid(
    GUI_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU,
    KC_DEL,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP,
    _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_NUM,  KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,  KC_PGDN,
    _______, _______, _______, _______, _______, _______, _______, _______, ANY,     _______, KC_UP,   KC_LEFT),

[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______,
    _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, _______, _______, _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  CK_TOGG, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
};

/* clang-format on */

void keyboard_post_init_user(void) {
    rgblight_setrgb(0x00, 0xFF, 0xFF);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _QWERTY:
        rgblight_setrgb(0x00, 0x00, 0xFF);
        break;
    case _RAISE:
        rgblight_setrgb(0xFF, 0x00, 0x00);
        break;
    case _LOWER:
        rgblight_setrgb(0x00, 0xFF, 0x00);
        break;
    case _FUNC:
        rgblight_setrgb(0x00, 0x00, 0xFF);
        break;
    case _ADJUST:
        rgblight_setrgb(0x7A, 0x00, 0xFF);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb(0x00, 0xFF, 0xFF);
        break;
    }

    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
	return true;
    }

    switch(keycode) {
    case ARING:
	if (detected_host_os() == OS_WINDOWS) {
	    tap_code16(RALT(KC_W));
	}
	else {
	    tap_code16(RALT(KC_A));
	}
	return false;
    case AUML:
	if (detected_host_os() == OS_WINDOWS) {
	    tap_code16(RALT(KC_Q));
	}
	else {
	    if (get_mods() & MOD_BIT_LSHIFT) {
            del_mods(MOD_BIT_LSHIFT);
            tap_code16(RALT(KC_U));
            set_mods(MOD_BIT_LSHIFT);
            tap_code16(KC_A);
	    }
	    else {
            tap_code16(RALT(KC_U));
            tap_code16(KC_A);
	    }
	}
	return false;
    case OUML:
	if (detected_host_os() == OS_WINDOWS) {
	    tap_code16(RALT(KC_P));
	}
	else {
	    if (get_mods() & MOD_BIT_LSHIFT) {
		del_mods(MOD_BIT_LSHIFT);
		tap_code16(RALT(KC_U));
		set_mods(MOD_BIT_LSHIFT);
		tap_code16(KC_O);
	    }
	    else {
		tap_code16(RALT(KC_U));
		tap_code16(KC_O);
	    }
	}
	return false;
    case KC_GRV:
    case KC_TILD:
    case KC_QUOT:
    case KC_DQUO:
	if (detected_host_os() == OS_WINDOWS) {
	    tap_code16(keycode);
	    tap_code16(KC_SPC);
	    return false;
	}
	break;
    case KC_6:
	if (detected_host_os() == OS_WINDOWS && get_mods() & MOD_MASK_SHIFT) {
	    tap_code16(keycode);
	    tap_code16(KC_SPC);
	    return false;
	}
	break;
    case ANY:
	tap_random_base64();
	return false;
    }

    return true;
}

const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t alt_down_key_override = ko_make_basic(MOD_BIT(KC_RALT), KC_DOWN, KC_UP);
const key_override_t alt_right_key_override = ko_make_basic(MOD_BIT(KC_RALT), KC_RIGHT, KC_LEFT);

const key_override_t **key_overrides = (const key_override_t *[]) {
    &dot_key_override,
    &comma_key_override,
    &delete_key_override,
    &alt_down_key_override,
    &alt_right_key_override,
    NULL
};
