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
 */

#include QMK_KEYBOARD_H
#include "os_detection.h"

enum planck_layers { _QWERTY, _COLEMAK, _DVORAK, _LOWER, _RAISE, _FUNC, _ADJUST };

#define LOWER    OSL(_LOWER)
#define LOWER2   TG(_LOWER)
#define RAISE    OSL(_RAISE)
#define FUNC     OSL(_FUNC)
#define QWERTY   TO(_QWERTY)
#define COLEMAK  TO(_COLEMAK)

enum swedish_keycodes {
    ARING = SAFE_RANGE,
    AUML,
    OUML,
    ANY
};

#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_TAB LCTL(KC_TAB)
#define GUI_GRV LGUI(KC_GRV)
#define GUI_HME LGUI(KC_HOME)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |EscCtl|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   .  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   Å  |   Ä  |   Ö  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Func | LAlt | RAlt | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ARING,
    CTL_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    OUML,    AUML,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT,
    FUNC,     KC_LALT, KC_RALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Colemak DH
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   .  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |EscCtl|   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   Å  |   Ä  |   Ö  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Func | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    OUML,    ARING,
    CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    AUML,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT,
    FUNC,    KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   1  |   2  |   3  |   4  |  5   |  6   |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  (   |   1  |  =   |  -   |   4  |   5  |   6  |   *  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  )   |   0  |      |  +   |   1  |   2  |   3  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |   0  |   .  |  ,   |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
   KC_TILD,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,       KC_8,       KC_9,    KC_0,    KC_BSPC,
   _______,  XXXXXXX, XXXXXXX, KC_LPRN, KC_1,    KC_PEQL, KC_PMNS, KC_4,       KC_5,       KC_6,    KC_PAST, KC_PENT,
   _______,  XXXXXXX, XXXXXXX, KC_RPRN, KC_0,    XXXXXXX, KC_PPLS, KC_1,       KC_2,       KC_3,    KC_PSLS, KC_PENT,
   _______,  _______, _______, _______, _______, KC_SPC,  KC_ENT,  _______,    KC_P0,      KC_PDOT, KC_COMM, XXXXXXX
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  ~   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_UNDS, KC_PIPE, KC_BSLS, KC_BSPC,
    _______, KC_LT,   KC_LBRC, KC_LPRN, KC_LCBR, KC_EQL,  KC_MINS, KC_SCLN, KC_DQUO, KC_QUOT, KC_ASTR, KC_ENT,
    _______, KC_GT,   KC_RBRC, KC_RPRN, KC_RCBR, KC_QUES, KC_PLUS, KC_COLN, KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    _______, _______, _______, _______, _______, KC_BSPC, KC_SPC,  KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Func layer
 * ,-----------------------------------------------------------------------------------.
 * |CtlTab|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  | Ins  | Home | PgUp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |GuiGrv|  F9  | F10  | F11  |  F12 | F13  | F14  | F15  | F16  | Del  | End  | PgDn |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Mute  | Vol- | Vol+ |GuiHme|PrntSc|ScrlLk| Paus |NumLck|      |  Up  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |ToLwr |             |      |      | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = LAYOUT_planck_grid(
    CTL_TAB, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, KC_INS,  KC_DEL,
    GUI_GRV, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, GUI_HME, KC_PSCR, KC_SCRL, KC_PAUS, KC_NUM,  XXXXXXX, KC_PGUP, _______,
    _______, _______, _______, _______, LOWER2,  _______, _______, _______, ANY,     KC_HOME, KC_PGDN, KC_END
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, _______, _______, _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};
/* clang-format on */

void keyboard_post_init_user(void) {
    rgblight_setrgb (0x00, 0xFF, 0xFF);
}
     

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _COLEMAK:
        rgblight_setrgb (0xFF, 0xFF, 0x00);
        break;
    case _RAISE:
        rgblight_setrgb (0xFF, 0x00, 0x00);
        break;
    case _LOWER:
        rgblight_setrgb (0x00, 0xFF, 0x00);
        break;
    case _FUNC:
        rgblight_setrgb (0x00, 0x00, 0xFF);
        break;
    case _ADJUST:
        rgblight_setrgb (0x7A, 0x00, 0xFF);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00, 0xFF, 0xFF);
        break;
    }

    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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

const key_override_t **key_overrides = (const key_override_t *[]) {
    &dot_key_override,
    &comma_key_override,
    &delete_key_override,
    NULL
};
