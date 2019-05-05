#include QMK_KEYBOARD_H
#include "petrichor.h"

extern keymap_config_t keymap_config;

enum layers { _DVORAK, /* _QWERTY, */ _FN1, _FN2, _FN3 };

#define KC_FN1 MO(_FN1)
#define KC_FN2 MO(_FN2)
#define KC_FN3 MO(_FN3)
#define SP_FN1 LT(_FN1, KC_SPACE)
#define SP_FN2 LT(_FN2, KC_SPACE)
#define BS_FN1 LT(_FN1, KC_BSPC)
#define BS_FN2 LT(_FN2, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT_ortho_5x14(
    KC_INS,  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, KC_DEL ,
    KC_MINS, KC_TAB , KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   ,     KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_SLSH, KC_EQL,
    KC_EQL,  KC_LCTL, KC_A   , KC_O   , KC_E   , KC_U   , KC_I   ,     KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_MINS, KC_ENT ,
    KC_PGUP, KC_LSPO, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   ,     KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , KC_RSPC, KC_HOME,
    KC_PGDN, KC_ESC , KC_FN3 , KC_LGUI, KC_LALT, BS_FN1 , BS_FN1 ,     SP_FN2 , SP_FN2 , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_END
  ),

  [_FN1] = LAYOUT_ortho_5x14(
    _______, KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     _______, KC_P7  , KC_P8  , KC_P9  , _______, _______, _______,
    KC_UNDS, _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,     _______, KC_P4  , KC_P5  , KC_P6  , _______, KC_LCBR, KC_RCBR,
    KC_PLUS, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     _______, KC_P1  , KC_P2  , KC_P3  , _______, KC_LBRC, KC_RBRC,
    _______, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,     _______, KC_P0  , KC_P0  , KC_PDOT, _______, KC_LPRN, KC_RPRN,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE
  ),

  [_FN2] = LAYOUT_ortho_5x14(
    _______, KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    KC_UNDS, _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_LCBR, KC_RCBR,
    KC_PLUS, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, _______, _______,
    _______, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,     KC_F12 , KC_NUHS, KC_NUBS, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE
  ),

  [_FN3] = LAYOUT_ortho_5x14(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,     RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_DEL,  _______,
    _______, _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,     AG_SWAP, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  )

  /* [_QWERTY] = LAYOUT_ortho_5x14( */
  /*   KC_INS,  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, KC_DEL , */
  /*   KC_MINS, KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, */
  /*   KC_EQL,  KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT , */
  /*   KC_PGUP, KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_HOME, KC_END , */
  /*   KC_PGDN, FN3 , KC_LCTL, KC_LALT, KC_LGUI, FN1  , KC_SPC ,     KC_SPC , FN2  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_BSLS */
  /* ), */

};
