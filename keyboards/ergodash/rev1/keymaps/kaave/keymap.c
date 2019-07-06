#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _SYMBOL 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMBOL,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   -  |                    |   =  |   6  |   7  |   8  |   9  |   0  |  BS  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   '  |                    |   [  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | LCtrl|   A  |   S  |   D  |   F  |   G  |   `  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  |  -   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      |      |      |      |      |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |------+------+------+------+------+------+ Space| Enter|      | Enter| Space+------+------+------+------+-------------|
   * | LOpt | LCtrl| LOpt | EISU |      | LCmd |      |      |      |      |      | RCmd |      | Left | Down |  Up  | Right|
   * ,---------------------------+      +------+------+------+      +------+------+------+      +---------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,       KC_4,    KC_5,    KC_MINS,                        KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,       KC_R,    KC_T,    KC_QUOT,                        KC_LBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,       KC_F,    KC_G,    KC_GRV ,                        KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_MINS, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,       KC_V,    KC_B,    KC_SPC ,                        KC_SPC , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LALT, KC_LCTL, KC_LALT, MO(SYMBOL),          KC_LGUI, KC_SPC ,KC_ENT,          KC_ENT,KC_SPC , KC_RGUI,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),

  /* Symbol
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  ~   |  F1  |  F2  |  F3  |  F4  |  F5  |      |                    |      |  F6  |  F7  |  F8  |  F9  |  F10 |  DEL |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |  F11 |  F12 |      |      |      |      |                    |      |      |      |      |   [  |   ]  |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |VolDp |VolUn | Mute |      |      |      |                    |      | Left | Down |  Up  | Right|   '  |  =   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |   `  |      |
   * |------+------+------+------+------+------+      |      |      |      |      +------+------+------+------+-------------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * ,---------------------------+      +------+------+------+      +------+------+------+      +---------------------------.
   */
  [_SYMBOL] = LAYOUT(
    KC_GRV , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,                        KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DELT,  \
    KC_TRNS, KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, \
    KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, KC_EQL,  \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV,  KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS   \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case SYMBOL:
      if (record->event.pressed) {
        layer_on(_SYMBOL);
      } else {
        layer_off(_SYMBOL);
      }
      return false;
      break;
  }
  return true;
}
