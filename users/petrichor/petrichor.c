#include QMK_KEYBOARD_H
#include "petrichor.h"
#include "rot13.h"

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
