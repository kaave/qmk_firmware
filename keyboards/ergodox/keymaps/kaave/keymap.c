// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols

/* BASIC KEYBOARD
 *
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    ESC |   !  |   @  |   #  |   $  |   %  |  -   |           |   +  |  ^   |  &   |  *   |  (   |  )   | BKSP   |
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |   =  |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |    TAB |   Q  |   W  |   E  |   R  |   T  |      |           |      |  Y   |  U   |  I   |  O   |  P   |   |    |
 * |        |   q  |   w  |   e  |   r  |   t  |  "   |           |   {  |  y   |  u   |  i   |  o   |  p   |   \    |
 * |--------+------+------+------+------+------|  '   |           |   [  |------+------+------+------+------+--------|
 * |  LCtrl |   A  |   S  |   D  |   F  |   G  |------|           |------|  H   |  J   |  K   |  L   |  :   |   -    |
 * |        |   a  |   s  |   d  |   f  |   g  |      |           |      |  h   |  j   |  k   |  l   |  ;   |        |
 * |--------+------+------+------+------+------|  ~   |           |   }  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |  `   |           |   ]  |  N   |  M   |  <   |  >   |  ?   | RShift |
 * |        |   z  |   x  |   c  |   v  |   b  |      |           |      |  n   |  m   |  ,   |  .   |  /   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LOpt | LCtrl| LOpt | ~L1  | LCmd |                                       | RCmd | LEFT | DOWN |  UP  |RIGHT |
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | BKSP |  DEL |       | DEL  | BKSP |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | HOME |       | PGUP |      |      |
 *                                 | Space| ENTER|------|       |------|ENTER |Space |
 *                                 |      |      |  END |       | PGDN |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,   KC_1,     KC_2,    KC_3,     KC_4,     KC_5,    KC_MINS,
        KC_TAB,   KC_Q,     KC_W,    KC_E,     KC_R,     KC_T,    KC_QUOT,
        KC_LCTRL, KC_A,     KC_S,    KC_D,     KC_F,     KC_G,
        KC_LSFT,  KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,    KC_GRV,
        KC_LALT,  KC_LCTRL, KC_LALT, MO(SYMB), KC_LGUI,
                                                       KC_BSPC, KC_DELT,
                                                                KC_HOME,
                                              KC_SPC,  KC_ENT,  KC_END,

        // right hand
        KC_EQL,   KC_6,   KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_LBRC,  KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,    KC_BSLS,
                  KC_H,   KC_J,     KC_K,    KC_L,    KC_SCLN, KC_MINS,
        KC_RBRC,  KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_RGUI,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,

        KC_DELT,  KC_BSPC,
        KC_PGUP,
        KC_PGDN,  KC_ENT, KC_SPC
    ),
/* Keymap 1: Function layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |  DEL   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | F11  | F12  |      |      |      |      |           |      |      |      |      |  [{  |  }]  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |VolDp |VolUn | Mute |      |      |------|           |------| LEFT | DOWN |  UP  |RIGHT |  '"  |   +=   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |  ~`  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  DEL | BKSP |       | BKSP | DEL  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                     KC_DELT, KC_BSPC,
                                                              KC_TRNS,
                                           KC_TRNS,  KC_TRNS, KC_TRNS,

       // right hand
       KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DELT,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS,
                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, KC_EQL,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV,  KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_BSPC, KC_DELT,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)  // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case SYMB:
            ergodox_right_led_1_on();
            break;
        default:
            // none
            break;
    }
};
