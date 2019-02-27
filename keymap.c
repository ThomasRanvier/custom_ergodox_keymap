#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define LCGS(code) LCTL(LGUI(LSFT(code)))
#define LCS(code) LCTL(LSFT(code))

//https://www.reddit.com/r/olkb/comments/8qqt99/configuring_alt_codes_and_codes_on_same_keyboard/
enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,     // can always be here
  EPRM,          
  RGB_SLD,       
  TOG_OS,
  //A
  CS_AACUTE,//á
  CS_AGRAVE,//à
  CS_ACIRC,//â
  CS_ADIAER,//ä
  //E
  CS_EACUTE,//é
  CS_EGRAVE,//è
  CS_ECIRC,//ê
  CS_EDIAER,//ë
  //I
  CS_IACUTE,//í
  CS_IGRAVE,//ì
  CS_ICIRC,//î
  CS_IDIAER,//ï
  //O
  CS_OACUTE,//ó
  CS_OGRAVE,//ò
  CS_OCIRC,//ô
  CS_ODIAER,//ô
  //U
  CS_UACUTE,//ú
  CS_UGRAVE,//ù
  CS_UCIRC,//ü
  CS_UDIAER,//û
  //C
  CS_CCEDI,//ç
  //€
  CS_EURO,
};

bool is_linux = false;// Used to detect on what OS I type and so what kind of shortcuts should be used.
// Default set to windows since I use windows at my work.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(
    // left hand
    KC_NO,       TO(1),       TO(2),       KC_NO,         KC_NO,       KC_NO,       KC_NO,       
    KC_ESC,       KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,          KC_MINS,       
    KC_QUOT,         KC_A,          KC_S,          KC_D,          KC_F,          KC_G,          
    MO(2),       KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,          KC_TAB,       
    KC_LCTL,         LALT(KC_TAB),         KC_NO,       MO(3),         KC_DEL,        
                                                                               KC_LALT,       KC_ESC,        
                                                                                              KC_NO,       
                                                                KC_LSFT, MO(1),      KC_LCMD,       
        // right hand
        KC_NO,       KC_NO,       KC_LEFT,       KC_DOWN,       KC_UP,         KC_RGHT,       KC_NO,       
        KC_EQL,       KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,          KC_GRAVE,       
                       KC_H,          KC_J,          KC_K,          KC_L,          KC_M,       KC_ENT,         
        KC_SCLN,       KC_N,          KC_COMM,       KC_DOT,        KC_LBRC,       KC_RBRC,      MO(2),       
        KC_BSPC,       MO(3),         KC_SLSH,       KC_BSLS,       KC_LCTL,       
        LALT(KC_LCTL), KC_LCMD,       
        KC_NO,       
        LALT(KC_TAB),       KC_LALT, SFT_T(KC_SPC)
    ),


  [1] = LAYOUT_ergodox(
    // left hand
    KC_NO,       TO(0),         TO(2),         KC_NO,         KC_NO,         KC_NO,         KC_NO,       
    KC_ESC,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_NO,       
    KC_NO,       KC_EXLM,       KC_AT,         KC_HASH,       KC_DLR,        KC_PERC,       
    KC_NO,       KC_1,       KC_2,        KC_3,       KC_4,       KC_5,       KC_TAB,       
    KC_LCTL,         LALT(KC_TAB),         KC_NO,       KC_NO,       KC_DEL,        
                                                                               KC_LALT,       KC_ESC,        
                                                                                              KC_NO,       
                                                                KC_LSFT, KC_NO,       KC_LCMD,       
        // right hand
        KC_NO,       KC_NO,         KC_LEFT,       KC_DOWN,       KC_UP,         KC_RGHT,        TOG_OS,       
        KC_NO,       KC_F6,         KC_F7,         KC_F8,         KC_F9,         KC_F10,        KC_F11,       
                    KC_CIRC,       KC_AMPR,       KC_ASTR,       KC_LPRN,       KC_RPRN,       KC_ENT,       
        KC_NO,       KC_6,       KC_7,        KC_8,       KC_9,       KC_0,       KC_F12,       
        KC_BSPC,       KC_NO,       KC_NO,       KC_NO,       KC_LCTL,       
        LALT(KC_LCTL), KC_LCMD,       
        KC_NO,       
        LALT(KC_TAB),       KC_LALT, SFT_T(KC_SPC)
    ),


  [2] = LAYOUT_ergodox(
    // left hand
    KC_NO,       TO(1),         TO(0),       KC_NO,       KC_NO,       KC_NO,       KC_NO,       
    KC_ESC,       KC_NO,       KC_BTN1,       KC_BTN3,       KC_BTN2,       KC_NO,       KC_NO,       
    KC_NO,       KC_MS_L,       KC_MS_D,       KC_MS_U,       KC_MS_R,       KC_NO,       
    KC_NO,       KC_WH_L,       KC_WH_D,       KC_WH_U,       KC_WH_R,       KC_NO,       KC_TAB,       
    KC_LCTL,    LALT(KC_TAB),          KC_NO,       KC_NO,       KC_DEL,        
                                                                               KC_LALT,       KC_ESC,        
                                                                                              KC_NO,       
                                                                KC_LSFT, KC_NO,       KC_LCMD,       
        // right hand
        KC_MPRV,       KC_MNXT,       KC_MUTE,       KC_VOLD,       KC_VOLU,       KC_MSTP,       KC_MPLY,       
        KC_NO,       KC_NO,       KC_HOME,       KC_PGDN,       KC_PGUP,       KC_END,        KC_NO,       
                       KC_NO,       KC_LEFT,       KC_DOWN,       KC_UP,         KC_RGHT,       KC_ENT,       
        KC_NO,       KC_NO,       KC_ACL0,       KC_ACL1,       KC_ACL2,       KC_NO,       KC_NO,       
        KC_BSPC,       KC_NO,       KC_NO,       KC_NO,       KC_LCTL,       
        LALT(KC_LCTL), KC_LCMD,       
        KC_NO,       
        LALT(KC_TAB),       KC_LALT, SFT_T(KC_SPC)
    ),


  [3] = LAYOUT_ergodox(
    // left hand
    KC_NO,        CS_AACUTE,    CS_AGRAVE,    CS_ACIRC,     CS_ADIAER,    CS_UACUTE,      KC_NO,      
    KC_ESC,        CS_EACUTE,    CS_EGRAVE,    CS_ECIRC,     CS_EDIAER,    CS_UGRAVE,      KC_NO,       
    CS_CCEDI,     CS_IACUTE,    CS_IGRAVE,    CS_ICIRC,     CS_IDIAER,    CS_UCIRC,      
    CS_EURO,      CS_OACUTE,    CS_OGRAVE,    CS_OCIRC,     CS_ODIAER,    CS_UDIAER,      KC_TAB,      
    KC_LCTL,         LALT(KC_TAB),         KC_NO,        KC_NO,        KC_DEL,      
                                                                               KC_LALT,       KC_ESC,        
                                                                                              KC_NO,       
                                                                KC_LSFT, KC_NO,       KC_LCMD,       
        // right hand
        KC_NO,       KC_NO,       KC_LEFT,       KC_DOWN,       KC_UP,         KC_RGHT,       KC_NO,       
        KC_NO,       KC_NO,       KC_P7,         KC_P8,         KC_P9,         KC_PSLS,       KC_NO,       
                       KC_NO,       KC_P4,         KC_P5,         KC_P6,         KC_PAST,       KC_ENT,       
        KC_NO,       KC_P0,         KC_P1,         KC_P2,         KC_P3,         KC_PMNS,       KC_NO,       
        KC_BSPC,       KC_NO,       KC_PDOT,       KC_PPLS,       KC_LCTL,       
        LALT(KC_LCTL), KC_LCMD,       
        KC_NO,       
        LALT(KC_TAB),       KC_LALT, SFT_T(KC_SPC)
    ),


};

bool suspended = false;
const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void cs_send_unicode(void) {
  SEND_STRING(SS_DOWN(X_LCTRL));
  SEND_STRING(SS_DOWN(X_LSHIFT));
  SEND_STRING(SS_TAP(X_U));
  SEND_STRING(SS_UP(X_LCTRL));
  SEND_STRING(SS_UP(X_LSHIFT));
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    //Custom macros
    case TOG_OS:
      if (record->event.pressed) {
        is_linux = !is_linux;
      }
      return false;
      break;
    //A
    case CS_AACUTE:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("e1 ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_5));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    case CS_AGRAVE:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("e0 ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_4));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    case CS_ACIRC:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("e2 ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_6));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    case CS_ADIAER:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("e4 ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_8));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    //E
    case CS_EACUTE:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("e9 ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_3));
          SEND_STRING(SS_TAP(X_KP_3));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    case CS_EGRAVE:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("e8 ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_3));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    case CS_ECIRC:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("ea ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_3));
          SEND_STRING(SS_TAP(X_KP_4));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    case CS_EDIAER:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("eb ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_3));
          SEND_STRING(SS_TAP(X_KP_5));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    //I
    case CS_IACUTE:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("ed ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_3));
          SEND_STRING(SS_TAP(X_KP_7));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    case CS_IGRAVE:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("ec ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_3));
          SEND_STRING(SS_TAP(X_KP_6));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    case CS_ICIRC:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("ee ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_3));
          SEND_STRING(SS_TAP(X_KP_8));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    case CS_IDIAER:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("ef ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_3));
          SEND_STRING(SS_TAP(X_KP_9));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    //O
    case CS_OACUTE:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("f3 ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_4));
          SEND_STRING(SS_TAP(X_KP_3));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    case CS_OGRAVE:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("f2 ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_4));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    case CS_OCIRC:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("f4 ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_4));
          SEND_STRING(SS_TAP(X_KP_4));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    case CS_ODIAER:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("f6 ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_4));
          SEND_STRING(SS_TAP(X_KP_6));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    //U
    case CS_UACUTE:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("fa ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_5));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    case CS_UGRAVE:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("f9 ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_4));
          SEND_STRING(SS_TAP(X_KP_9));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    case CS_UCIRC:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("fb ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_5));
          SEND_STRING(SS_TAP(X_KP_1));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    case CS_UDIAER:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("fc ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_5));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    //C
    case CS_CCEDI:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("e7 ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_3));
          SEND_STRING(SS_TAP(X_KP_1));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
    //€
    case CS_EURO:
      if (record->event.pressed) {
        if (is_linux) {
          cs_send_unicode();
          SEND_STRING("20ac ");
        } else {
          SEND_STRING(SS_DOWN(X_LALT));
          SEND_STRING(SS_TAP(X_KP_0));
          SEND_STRING(SS_TAP(X_KP_1));
          SEND_STRING(SS_TAP(X_KP_2));
          SEND_STRING(SS_TAP(X_KP_8));
          SEND_STRING(SS_UP(X_LALT));
        }
      }
      return false;
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
