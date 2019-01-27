
#include QMK_KEYBOARD_H

#include "process_unicode.h"

#define PAD 0
#define MOUSE 1
#define NUM 2
#define DIR 3

enum unicode_names {
    BEER,
    THINK,
    TH_UP,
    TH_DW,
};
const uint32_t PROGMEM unicode_map[]=
{
    [BEER] = 0x1f37a,
    [THINK] = 0x1f914,
    [TH_UP] = 0x1f44d,
    [TH_DW] = 0x1f44e,
};

enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Single 4x4 board only
 * .-----------------------------------.
 * |   7    |   8    |   9    |   /    |
 * |--------+--------+--------+--------|
 * |   4    |   5    |   6    |   *    |
 * |--------+--------+--------+--------|
 * |   1    |   2    |   3    |   -    |
 * |--------+--------+--------+--------|
 * |   0    | QWERTY |   .    |   +    |
 * '-----------------------------------'
 */

  [PAD] = LAYOUT_ortho_jon44(
      X(BEER), QMKBEST, X(THINK),   KC_PSLS,
      KC_D, KC_E, KC_F,   KC_PAST,
      KC_G, KC_H, KC_I,   KC_PMNS,
      KC_LSHIFT, LT(MOUSE, KC_F), KC_L, KC_M
  ),

  [MOUSE] = LAYOUT_ortho_jon44(
      KC_W, KC_W, KC_C,   KC_PSLS,
      KC_D, KC_E, KC_F,   KC_PAST,
      KC_G, KC_H, KC_I,   KC_PMNS,
      KC_K, DF(PAD), KC_L, KC_M
  ),

};


void matrix_init_user(void) {
    set_unicode_input_mode(UC_OSX);
}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING(SS_TAP(X_LGUI));
		/* send_unicode_hex_string("0028 30CE 0CA0 75CA 0CA0 0029 30CE 5F61 253B 2501 253B"); */
        send_unicode_hex_string("2665");
        /* SEND_STRING(SS_LCTRL(SS_LALT(" "))); // Select the previous input source */

        //samples
        //SEND_STRING("QMK is the best thing ever!");
        /* SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER)); */
        /* SEND_STRING(SS_LCTRL("ac")); */
      } else {
        // when keycode QMKBEST is released
      }
      break;

  }
  return true;
}

void led_set_user(uint8_t usb_led) {

}
