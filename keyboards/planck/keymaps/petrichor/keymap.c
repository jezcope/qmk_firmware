/* Copyright 2015-2017 Jack Humbert
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
#include "petrichor.h"

extern keymap_config_t keymap_config;

enum layers {_DVORAK, _FN1, _FN2, _FN3, _MACRO, _MOUSE};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define KC_FN1 MO(_FN1)
#define KC_FN2 MO(_FN2)
#define KC_FN3 MO(_FN3)
#define KC_MAC MO(_MACRO)
#define KC_MSE MO(_MOUSE)
#define TT_MSE TT(_MOUSE)
#define SP_FN1 LT(_FN1, KC_SPACE)
#define SP_FN2 LT(_FN2, KC_SPACE)
#define BS_FN1 LT(_FN1, KC_BSPC)
#define BS_FN2 LT(_FN2, KC_BSPC)

#define GU_FN1 LM(_FN1, MOD_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DVORAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_DEL,
    KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
    KC_LSPO, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSPC,
    KC_ESC , TT_MSE , KC_LGUI, KC_LALT, KC_FN3 , BS_FN1 , SP_FN2 , KC_RALT, KC_MAC , GU_FN1 , KC_LEAD, KC_RCTL
),

[_FN1] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_SLSH,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_FN2] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_QUES,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_FN3] = LAYOUT_planck_grid(
    _______, _______, _______, X(STER), X(EURO), _______, _______, KC_WBAK, KC_WFWD, KC_TBAK, KC_TFWD, _______,
    UC_M_WI, _______, _______, _______, _______, _______, KC_PGUP, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
    UC_M_WC, _______, _______, _______, _______, _______, KC_PGDN, KC_HOME, KC_END , _______, _______, _______,
    UC_M_LN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET
),

[_MACRO] = LAYOUT_planck_grid(
    _______, M_EML_H, M_EML_W, M_EML_S, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, M_CHRS , M_MTNKS, M_THNKS, M_BEST , M_RGRDS, _______, _______, _______, _______, _______, _______,
    _______, CPY_ALL, CUT_ALL, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
    _______, _______, _______, _______, _______, _______, KC_WH_D, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_BTN3, KC_BTN1, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R
),

/* [_TEMPLATE] = LAYOUT_planck_grid( */
/*     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ */
/* ) */

};

LEADER_EXTERNS();

void matrix_scan_keymap(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_TWO_KEYS(KC_M, KC_C) {
            SEND_STRING("Cheers,\nJez");

        }
        SEQ_TWO_KEYS(KC_M, KC_T) {
            SEND_STRING("Thanks,\nJez");
        }

        SEQ_TWO_KEYS(KC_X, KC_R) {
            reset_keyboard();
        }
    }
}
