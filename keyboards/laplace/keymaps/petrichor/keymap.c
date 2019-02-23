#include QMK_KEYBOARD_H

enum layers {_DVORAK, _QWERTY, _RAISE, _LOWER};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define DF_DVORAK DF(_DVORAK)
#define DF_QWERTY DF(_QWERTY)
#define SP_RAISE LT(_RAISE, KC_SPACE)
#define SP_LOWER LT(_LOWER, KC_SPACE)
#define BS_RAISE LT(_RAISE, KC_BSPC)
#define BS_LOWER LT(_LOWER, KC_BSPC)
#define GU_RAISE LM(_RAISE, MOD_LGUI)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT(
    KC_TAB,   KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,  KC_DEL,
    KC_LCTL,    KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_D,     KC_H,     KC_T,     KC_N,     KC_S,             KC_ENT,
    KC_LSFT,         KC_SCLN,  KC_Q,     KC_J,     KC_K,     KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,        KC_RSFT,
    KC_ESC,   GU_RAISE, KC_LGUI,  KC_LALT,       BS_RAISE,           SP_LOWER,        KC_RALT,  KC_RGUI,       LOWER,       KC_RCTL
  ),

  [_QWERTY] = LAYOUT(
    KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_DEL,   KC_BSPC,
    KC_TAB,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_QUOT,          KC_ENT,
    KC_LSFT,         KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,     KC_RSFT,
    KC_LCTL,  KC_LALT,  KC_LGUI,  GU_RAISE,      BS_RAISE,           SP_LOWER,        KC_RGUI,  KC_RALT,       LOWER,       KC_RCTL
  ),

  [_RAISE] = LAYOUT(
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,
    RESET,      RGB_HUI,  RGB_SAI,  RGB_VAI,  KC_VOLU,  KC_LBRC,  KC_RBRC,  KC_4,     KC_5,     KC_6,     KC_SCLN,          _______,
    RGB_MOD,         RGB_HUD,  RGB_SAD,  RGB_VAD,  KC_VOLD,  KC_LCBR,  KC_RCBR,  KC_1,     KC_2,     KC_3,     KC_UP,       _______,
    RGB_TOG,  _______,  _______,  _______,       _______,            KC_DEL,          KC_0,     KC_LEFT,       KC_DOWN,     KC_RGHT
  ),

  [_LOWER] = LAYOUT(
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_UNDS,  KC_PLUS,
    _______,    DF_DVORAK,_______,  KC_INS,   KC_PGUP,  KC_HOME,  _______,  _______,  _______,  _______,  KC_COLN,          _______,
    _______,         DF_QWERTY,_______,  KC_DEL,   KC_PGDN,  KC_END,   _______,  _______,  _______,  _______,  _______,     _______,
    _______,  _______,  _______,  _______,       KC_DEL,             _______,         _______,  _______,       _______,     _______
  )
};
