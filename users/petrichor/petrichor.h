#pragma once

enum custom_keycodes {
  M_BEST = SAFE_RANGE,
  M_RGRDS, M_THNKS, M_MTNKS, M_CHRS,
  M_EML_H, M_EML_W, M_EML_S,
  ALT_TAB,
  CPY_ALL, CUT_ALL,
  SAFE_RANGE_KEYMAP
};

enum unicode_names { STER, EURO };

#define ALT_F4 LALT(KC_F4)
#define GUI_F4 LGUI(KC_F4)
#define KC_TBAK LCTL(KC_PGUP)
#define KC_TFWD LCTL(KC_PGDN)
