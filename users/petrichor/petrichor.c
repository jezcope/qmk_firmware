#include QMK_KEYBOARD_H
#include "petrichor.h"
#include "rot13.h"

bool     is_alt_tab_active = false;
uint16_t alt_tab_timer     = 0;

char s_email[]        = "w.pbcr@renzoyre.pb.hx";
char s_email_work[]   = "wrm.pbcr@oy.hx";
char s_email_shared[] = "hf@wrmaryyl.pb.hx";
char s_email_gmail[]  = "wrm.pbcr@tznvy.pbz";

const uint32_t PROGMEM unicode_map[] = {
    [STER] = 0x00A3,  // £
    [EURO] = 0x20AC,  // €
};

void eeconfig_init_user(void) { set_unicode_input_mode(UC_LNX); }

void keyboard_post_init_user(void) {
    rot13(s_email);
    rot13(s_email_work);
    rot13(s_email_shared);
    rot13(s_email_gmail);
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

            case CPY_ALL:
                SEND_STRING(SS_LCTRL("ac"));
                break;
            case CUT_ALL:
                SEND_STRING(SS_LCTRL("ax"));
                break;

            case M_BEST:
                SEND_STRING("All the best," SS_LSFT("\n") "Jez");
                break;
            case M_RGRDS:
                SEND_STRING("Regards,\nJez");
                break;
            case M_THNKS:
                SEND_STRING("Thanks,\nJez");
                break;
            case M_MTNKS:
                SEND_STRING("Many thanks,\nJez");
                break;
            case M_CHRS:
                SEND_STRING("Cheers,\nJez");
                break;
            case M_EML_H:
                send_string(s_email);
                break;
            case M_EML_W:
                send_string(s_email_work);
                break;
            case M_EML_S:
                send_string(s_email_shared);
                break;
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

__attribute__((weak)) void matrix_scan_keymap(void) { return; }

LEADER_EXTERNS();

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1000) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }

    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_TWO_KEYS(KC_A, KC_C) { SEND_STRING("Cheers," SS_LSFT("\n") "Jez"); }
        SEQ_TWO_KEYS(KC_A, KC_T) { SEND_STRING("Thanks," SS_LSFT("\n") "Jez"); }
        SEQ_TWO_KEYS(KC_A, KC_B) { SEND_STRING("All the best," SS_LSFT("\n") "Jez"); }
        SEQ_TWO_KEYS(KC_A, KC_R) { SEND_STRING("Regards," SS_LSFT("\n") "Jez"); }
        SEQ_TWO_KEYS(KC_A, KC_M) { SEND_STRING("Many thanks," SS_LSFT("\n") "Jez"); }
        SEQ_TWO_KEYS(KC_A, KC_W) { SEND_STRING("Have a great weekend," SS_LSFT("\n") "Jez"); }
        SEQ_TWO_KEYS(KC_A, KC_H) { SEND_STRING("I hope that helps. All the best," SS_LSFT("\n") "Jez"); }

        SEQ_TWO_KEYS(KC_O, KC_R) { SEND_STRING("For reference.\n\nJez"); }
        SEQ_TWO_KEYS(KC_O, KC_T) { SEND_STRING("thanks for getting in touch.  "); }

        SEQ_TWO_KEYS(KC_E, KC_E) { send_string(s_email); }
        SEQ_TWO_KEYS(KC_E, KC_W) { send_string(s_email_work); }
        SEQ_TWO_KEYS(KC_E, KC_S) { send_string(s_email_shared); }
        SEQ_TWO_KEYS(KC_E, KC_G) { send_string(s_email_gmail); }

        SEQ_TWO_KEYS(KC_C, KC_C) { SEND_STRING(SS_LCTRL("ac")); }
        SEQ_TWO_KEYS(KC_C, KC_X) { SEND_STRING(SS_LCTRL("ax")); }

        SEQ_TWO_KEYS(KC_X, KC_R) { reset_keyboard(); }
    }
    matrix_scan_keymap();
}
