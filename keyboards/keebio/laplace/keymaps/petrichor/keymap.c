#include QMK_KEYBOARD_H
#include "rot13.h"

enum layers {_DVORAK, _FN1, _FN2, _FN3, _MOUSE};

enum custom_keycodes {
  M_BEST = SAFE_RANGE,
  M_RGRDS, M_THNKS, M_CHRS,
  M_EML_H, M_EML_W,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define KC_FN1 MO(_FN1)
#define KC_FN2 MO(_FN2)
#define KC_FN3 MO(_FN3)
#define MOUSE MO(_MOUSE)
#define T_MOUSE TT(_MOUSE)
#define DF_DVOR DF(_DVORAK)
/* #define DF_QWER DF(_QWERTY) */
#define SP_FN1 LT(_FN1, KC_SPACE)
#define SP_FN2 LT(_FN2, KC_SPACE)
#define BS_FN1 LT(_FN1, KC_BSPC)
#define BS_FN2 LT(_FN2, KC_BSPC)

#define GU_FN1 LM(_FN1, MOD_LGUI)

#define CT_PGUP LCTL(KC_PGUP)
#define CT_PGDN LCTL(KC_PGDN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_DEL,
    KC_LCTL,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,            KC_ENT,
    KC_LSPO,        KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,       KC_RSPC,
    KC_ESC,  T_MOUSE, KC_LGUI, KC_LALT,      BS_FN1,            SP_FN2,         KC_RALT, KC_FN3,       GU_FN1,     KC_RCTL
  ),

  [_FN1] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
    _______,   _______, _______, _______, KC_VOLU, KC_LBRC, KC_RBRC, KC_4,    KC_5,    KC_6,    KC_SCLN,         KC_BSLASH,
    _______,        _______, _______, _______, KC_VOLD, KC_LCBR, KC_RCBR, KC_1,    KC_2,    KC_3,    KC_UP,      _______,
    _______, _______, _______, _______,      _______,           KC_DEL,         KC_0,    KC_LEFT,      KC_DOWN,    KC_RGHT
  ),

  [_FN2] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,
    _______,   _______, KC_WBAK, CT_PGUP, KC_PGUP, KC_HOME, _______, _______, _______, _______, KC_COLN,         KC_PIPE,
    _______,        _______, KC_WFWD, CT_PGDN, KC_PGDN, KC_END,  _______, _______, _______, _______, _______,    _______,
    _______, _______, _______, _______,      KC_DEL,            _______,        _______, _______,      _______,    RESET
  ),

  [_FN3] = LAYOUT(
    _______, M_BEST,  M_RGRDS, M_THNKS, M_CHRS,  _______, _______, _______, _______, _______, _______, _______, _______,
    _______,   M_EML_H, M_EML_W, _______, _______, _______, _______, _______, _______, _______, _______,         _______,
    _______,        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,
    _______, _______, _______, _______,      _______,           _______,        _______, _______,      _______,    _______
  ),

  [_MOUSE] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,   _______, _______, _______, _______, _______, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,         _______,
    _______,        _______, _______, _______, _______, _______, KC_WH_D, _______, _______, _______, _______,    _______,
    _______, _______, _______, _______,      KC_BTN2,           KC_BTN1,        _______, _______,      _______,    _______
  ),

  /* [_QWERTY] = LAYOUT( */
  /*   KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  KC_BSPC,*/
  /*   KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,         KC_ENT,*/
  /*   KC_LSPO,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RSPC,*/
  /*   KC_LCTL, T_MOUSE, KC_LGUI, GU_FN1,       BS_FN1,            SP_FN2,         KC_RGUI, KC_RALT,      GU_FN1,     KC_RCTL */
  /* ),*/

  /* [_TEMPLATE] = LAYOUT( */
  /*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,*/
  /*   _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______,*/
  /*   _______,        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,*/
  /*   _______, _______, _______, _______,      _______,           _______,        _______, _______,      _______,    _______ */
  /* ),*/
};

char s_email[22] = "w.pbcr@renzoyre.pb.hx";
char s_email_work[15] = "wrm.pbcr@oy.hx";

void keyboard_post_init_user(void) {
  rot13(s_email);
  rot13(s_email_work);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
    case M_BEST:
      SEND_STRING("Best wishes,\nJez"); break;
    case M_RGRDS:
      SEND_STRING("Regards,\nJez"); break;
    case M_THNKS:
      SEND_STRING("Thanks,\nJez"); break;
    case M_CHRS:
      SEND_STRING("Cheers,\nJez"); break;
    case M_EML_H:
      send_string(s_email); break;
    case M_EML_W:
      send_string(s_email_work); break;
    }
  }
  return true;
};
