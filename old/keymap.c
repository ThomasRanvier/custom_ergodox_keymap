#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define LCGS(code) LCTL(LGUI(LSFT(code)))
#define LCS(code) LCTL(LSFT(code))

/**
 *
 * On layer 2 instead of numerical pad, put all the symbols
 *
 * On left finger instead of MO1 put Shift + MO2
 *
 **/

//https://www.reddit.com/r/olkb/comments/8qqt99/configuring_alt_codes_and_codes_on_same_keyboard/
enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,    // can always be here
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
};

bool is_linux = false;// Used to detect on what OS I type and so what kind of shortcuts should be used.
// Default set to windows since I use windows at my work.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(
    // left hand
    KC_ESC,       KC_1,         KC_2,         KC_3,         KC_4,         KC_5,         KC_NO,      
    KC_NO,        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_DEL,       
    KC_BSLS,      KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         
    KC_NO,        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_NO,      
    TG(2),        KC_GRV,       KC_QUOT,      KC_NO,        KC_NO,      
                                                                          KC_LALT,      LALT(KC_LCTL),
                                                                                        MO(1),        
                                                            KC_LSFT,      KC_TAB,       MO(2),        
        // right hand
        KC_NO,        KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         KC_NO,      
        KC_BSPC,      KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,         KC_MINS,      
                      KC_H,         KC_J,         KC_K,         KC_L,         KC_SCLN,      KC_EQL,       
        KC_NO,        KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_NO,      
        KC_NO,        KC_NO,        KC_LBRC,      KC_RBRC,      TG(1),        
        KC_LCMD,      KC_LCTL,      
        MO(1),        
        MO(2),        KC_ENT,       KC_SPC
    ),


  [1] = LAYOUT_ergodox(
    // left hand
    KC_ESC,     KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,      KC_NO,      
    KC_NO,      KC_NO,        KC_BTN1,      KC_BTN3,      KC_BTN2,      KC_NO,      KC_DEL,       
    KC_NO,      KC_MS_L,      KC_MS_D,      KC_MS_U,      KC_MS_R,      KC_NO,      
    KC_NO,      KC_WH_L,      KC_WH_D,      KC_WH_U,      KC_WH_R,      KC_NO,      KC_NO,      
    KC_NO,      KC_NO,        KC_NO,        KC_NO,        KC_NO,      
                                                                          KC_LALT,      LALT(KC_LCTL),
                                                                                        KC_NO,      
                                                            KC_LSFT,      KC_TAB,       KC_NO,      
        // right hand
        KC_NO,        KC_F6,      KC_F7,      KC_F8,        KC_F9,        KC_F10,       TOG_OS,      
        KC_BSPC,      KC_NO,      KC_NO,      KC_NO,        KC_NO,        KC_NO,        KC_F11,       
                      KC_NO,      KC_LEFT,    KC_DOWN,      KC_UP,        KC_RGHT,      KC_F12,       
        KC_NO,        KC_NO,      KC_ACL1,    KC_ACL1,      KC_ACL2,      KC_NO,        KC_NO,      
        KC_NO,        KC_NO,      KC_NO,      KC_NO,        KC_NO,      
        KC_LCMD,      KC_LCTL,      
        KC_NO,      
        KC_NO,      KC_ENT,       KC_SPC
    ),


  [2] = LAYOUT_ergodox(
    // left hand
    KC_ESC,       CS_AACUTE,    CS_AGRAVE,    CS_ACIRC,     CS_ADIAER,    KC_NO,      KC_NO,      
    KC_NO,        CS_EACUTE,    CS_EGRAVE,    CS_ECIRC,     CS_EDIAER,    KC_NO,      KC_DEL,       
    CS_CCEDI,     CS_IACUTE,    CS_IGRAVE,    CS_ICIRC,     CS_IDIAER,    KC_NO,      
    KC_NO,        CS_OACUTE,    CS_OGRAVE,    CS_OCIRC,     CS_ODIAER,    KC_NO,      KC_NO,      
    KC_NO,        CS_UACUTE,    CS_UGRAVE,    CS_UCIRC,     CS_UDIAER,      
                                                                          KC_LALT,      LALT(KC_LCTL),
                                                                                        KC_NO,      
                                                            KC_LSFT,      KC_TAB,       KC_NO,      
        // right hand
        KC_MPRV,      KC_MNXT,    KC_MUTE,      KC_VOLD,      KC_VOLU,      KC_MSTP,      KC_MPLY,      
        KC_BSPC,      KC_NO,      KC_P7,        KC_P8,        KC_P9,        KC_PSLS,      KC_NO,      
                      KC_NO,      KC_P4,        KC_P5,        KC_P6,        KC_PAST,      KC_NO,      
        KC_NO,        KC_NO,      KC_P1,        KC_P2,        KC_P3,        KC_PMNS,      KC_PENT,      
        KC_P0,        KC_NO,      KC_PDOT,      KC_PPLS,      KC_NO,      
        KC_LCMD,      KC_LCTL,      
        KC_NO,      
        KC_NO,      KC_ENT,       KC_SPC
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"E1");
        } else {
          SEND_STRING(SS_LALT("0225"));
        }
      }
      return false;
      break;
    case CS_AGRAVE:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"E0");
        } else {
          SEND_STRING(SS_LALT("0224"));
        }
      }
      return false;
      break;
    case CS_ACIRC:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"E2");
        } else {
          SEND_STRING(SS_LALT("0226"));
        }
      }
      return false;
      break;
    case CS_ADIAER:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"E4");
        } else {
          SEND_STRING(SS_LALT("0228"));
        }
      }
      return false;
      break;
    //E
    case CS_EACUTE:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"E9");
        } else {
          SEND_STRING(SS_LALT("0233"));
        }
      }
      return false;
      break;
    case CS_EGRAVE:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"E8");
        } else {
          SEND_STRING(SS_LALT("0232"));
        }
      }
      return false;
      break;
    case CS_ECIRC:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"EA");
        } else {
          SEND_STRING(SS_LALT("0234"));
        }
      }
      return false;
      break;
    case CS_EDIAER:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"EB");
        } else {
          SEND_STRING(SS_LALT("0235"));
        }
      }
      return false;
      break;
    //I
    case CS_IACUTE:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"ED");
        } else {
          SEND_STRING(SS_LALT("0237"));
        }
      }
      return false;
      break;
    case CS_IGRAVE:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"EC");
        } else {
          SEND_STRING(SS_LALT("0236"));
        }
      }
      return false;
      break;
    case CS_ICIRC:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"EE");
        } else {
          SEND_STRING(SS_LALT("0238"));
        }
      }
      return false;
      break;
    case CS_IDIAER:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"EF");
        } else {
          SEND_STRING(SS_LALT("0239"));
        }
      }
      return false;
      break;
    //O
    case CS_OACUTE:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"F3");
        } else {
          SEND_STRING(SS_LALT("0243"));
        }
      }
      return false;
      break;
    case CS_OGRAVE:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"F2");
        } else {
          SEND_STRING(SS_LALT("0242"));
        }
      }
      return false;
      break;
    case CS_OCIRC:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"F4");
        } else {
          SEND_STRING(SS_LALT("0244"));
        }
      }
      return false;
      break;
    case CS_ODIAER:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"F6");
        } else {
          SEND_STRING(SS_LALT("0246"));
        }
      }
      return false;
      break;
    //U
    case CS_UACUTE:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"FA");
        } else {
          SEND_STRING(SS_LALT("0250"));
        }
      }
      return false;
      break;
    case CS_UGRAVE:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"F9");
        } else {
          SEND_STRING(SS_LALT("0249"));
        }
      }
      return false;
      break;
    case CS_UCIRC:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"FB");
        } else {
          SEND_STRING(SS_LALT("0251"));
        }
      }
      return false;
      break;
    case CS_UDIAER:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"FC");
        } else {
          SEND_STRING(SS_LALT("0252"));
        }
      }
      return false;
      break;
    //C
    case CS_CCEDI:
      if (record->event.pressed) {
        if (is_linux) {
          SEND_STRING(SS_LCTRL(SS_LSFT("u"))"E7");
        } else {
          SEND_STRING(SS_LALT("0231"));
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
