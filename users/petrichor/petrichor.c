#include QMK_KEYBOARD_H
#include "petrichor.h"
#include "rot13.h"

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

char s_email[22] = "w.pbcr@renzoyre.pb.hx";
char s_email_work[15] = "wrm.pbcr@oy.hx";

const uint32_t PROGMEM unicode_map[] = {
  [STER] = 0x00A3, // £
  [EURO] = 0x20AC, // €
};

void eeconfig_init_user(void) {
  set_unicode_input_mode(UC_LNX);
}

void keyboard_post_init_user(void) {
  rot13(s_email);
  rot13(s_email_work);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
    case ALT_TAB:
	  if (!is_alt_tab_active) {
		is_alt_tab_active = true;
		register_code(KC_LALT);
	  }
	  alt_tab_timer = timer_read();
	  register_code(KC_TAB);
      break;

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
  } else {
	switch (keycode) {
	case ALT_TAB:
	  unregister_code(KC_TAB);
	  break;
	}
  }

  return true;
};

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
