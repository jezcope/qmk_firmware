#include QMK_KEYBOARD_H
#include "petrichor.h"

extern keymap_config_t keymap_config;

enum layers { _DVORAK, _QWERTY, _FN1, _FN2, _FN3, _FN4, _MOUSE };

#define KC_FN1 MO(_FN1)
#define KC_FN2 MO(_FN2)
#define KC_FN3 MO(_FN3)
#define BS_FN1 LT(_FN1, KC_BSPC)
#define SP_FN2 LT(_FN2, KC_SPACE)
#define MOUSE MO(_MOUSE)
#define T_MOUSE TT(_MOUSE)
#define T_FN4 TT(_FN4)
#define DF_DVOR DF(_DVORAK)
#define DF_QWER DF(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT_ortho_5x14(
    ALT_TAB, KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, KC_DEL ,
    KC_WBAK, KC_TAB , KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   ,     KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_SLSH, KC_EQL,
    KC_WFWD, KC_LCTL, KC_A   , KC_O   , KC_E   , KC_U   , KC_I   ,     KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_MINS, KC_ENT ,
    KC_PGUP, KC_LSPO, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   ,     KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , KC_RSPC, KC_BSLS,
    KC_PGDN, KC_ESC , T_MOUSE, KC_LGUI, KC_LALT, KC_FN3 , BS_FN1 ,     SP_FN2 , KC_RALT, KC_LEAD, KC_RGUI, _______, T_FN4  , KC_RCTL
  ),

  [_QWERTY] = LAYOUT_ortho_5x14(
    KC_INS,  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, KC_DEL ,
    KC_MINS, KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC,
    KC_EQL,  KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
    KC_PGUP, KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_HOME, KC_END ,
    KC_PGDN, KC_ESC , KC_LCTL, KC_LALT, KC_LGUI, KC_FN3 , BS_FN1 ,     SP_FN2 , KC_FN3 , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_BSLS
  ),

  [_FN1] = LAYOUT_ortho_5x14(
	KC_INS , KC_TILD, _______, _______, _______, ALT_F4 , _______,     _______, _______, _______, _______, _______, _______, _______,
    KC_TBAK, _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,     _______, KC_WBAK, KC_WFWD, KC_TBAK, KC_TFWD, KC_LCBR, KC_RCBR,
    KC_TFWD, _______, _______, _______, _______, _______, _______,     KC_PGUP, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_LBRC, KC_RBRC,
    KC_HOME, _______, _______, _______, _______, _______, _______,     KC_PGDN, KC_HOME, KC_END , _______, _______, KC_LPRN, KC_RPRN,
    KC_END , _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  ),

  [_FN2] = LAYOUT_ortho_5x14(
    M_BEST , M_EML_H, KC_F1  , KC_F2  , X(STER), X(EURO), KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    M_RGRDS, M_EML_W, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_LCBR, KC_RCBR,
    M_MTNKS, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, _______, _______,
    M_THNKS, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,     KC_F12 , KC_NUHS, KC_NUBS, _______, _______, _______, _______,
    M_CHRS , _______, _______, _______, _______, _______, _______,     _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE
  ),

  [_FN3] = LAYOUT_ortho_5x14(
    KC_PWR , KC_SLEP, KC_WAKE, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, GUI_F4 ,
    _______, _______, _______, _______, _______, _______, _______,     _______, CUT_ALL, CPY_ALL, _______, _______, KC_DEL,  _______,
    UC_M_WI, DF_QWER, _______, _______, _______, _______, _______,     KC_VOLU, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, _______, _______,
    UC_M_WC, DF_DVOR, _______, _______, _______, _______, _______,     KC_VOLD, _______, _______, _______, _______, _______, _______,
    UC_M_LN, RESET  , _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  ),

  [_FN4] = LAYOUT_ortho_5x14(
    KC_INS , KC_TILD, KC_F1  , KC_F2  , KC_F3  , ALT_F4 , KC_F5  ,     _______, _______, KC_PSLS, KC_PAST, KC_PMNS, KC_NLCK, _______,
    KC_TBAK, _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,     _______, KC_P7  , KC_P8  , KC_P9  , KC_PPLS, KC_LCBR, KC_RCBR,
    KC_TFWD, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     _______, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, KC_LBRC, KC_RBRC,
    KC_HOME, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,     _______, KC_P1  , KC_P2  , KC_P3  , KC_PENT, KC_LPRN, KC_RPRN,
    KC_END , _______, _______, _______, _______, _______, _______,     _______, KC_P0  , KC_P0  , KC_PDOT, KC_PENT, _______, _______
  ),

  [_MOUSE] = LAYOUT_ortho_5x14(
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
    KC_WH_U, _______, _______, _______, _______, _______, _______,     KC_WH_D, _______, _______, _______, _______, _______, _______,
    KC_WH_D, _______, _______, _______, _______, _______, KC_BTN3,     KC_BTN1, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______
  ),

  /* [_TEMPLATE] = LAYOUT_ortho_5x14( */
  /*   _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, */
  /*   _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, */
  /*   _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, */
  /*   _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, */
  /*   _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______ */
  /* ), */

};
