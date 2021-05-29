#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4
#define _LAYER5 5
#define _LAYER6 6
#define _LAYER7 7


enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
    LAYER5,
    LAYER6,
    LAYER7,

};
void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX);
}

bool is_shift_active = false;
bool is_alt_active = false;

enum my_macro {
    KEY_E_AIG = SAFE_RANGE,
		LPAR,
    KEY_E_AIG_MAJ,
    KEY_E_GRV,
    KEY_E_GRV_MAJ,
    KEY_E_CIRC,
    KEY_E_CIRC_MAJ,
    KEY_E_TREMA,
    KEY_E_TREMA_MAJ,
    KEY_A_CIRC,
    KEY_A_CIRC_MAJ,
    KEY_A_GRV,
    KEY_A_GRV_MAJ,
    KEY_C_CEDILLE,
    KEY_C_CEDILLE_MAJ,
    KEY_CARRE,
    KEY_CUBE,
    KEY_EURO,
    KEY_BAHT,
    KEY_COPYRIGHT,
    KEY_REGISTERED,
    KEY_OMEGA,
    KEY_OMEGA_MAJ,
    KEY_O_CIRC,
    KEY_O_CIRC_MAJ,
    KEY_U_GRAV,
    KEY_U_GRAV_MAJ,
    KEY_OE,
    KEY_OE_MAJ,
    KEY_PI,
    KEY_DEGREE,
    KEY_N_TILDE,
    KEY_N_TILDE_MAJ,
    KEY_MICRO,
    KEY_SIGMA,
    KEY_INFEQ,
    KEY_SUPEQ,
    KEY_GUILL_G,
    KEY_GUILL_R,
    KEY_UNEQUAL,
    KEY_PRETTYMUCH,
    KEY_INFINIT,
    KEY_I_GRAV,
    KEY_I_GRAV_MAJ,
    KEY_SECRET,
    MAIL,
    KEY_U_CIRC,
    KEY_PARENTHESE_OUVRE,
    KEY_PARENTHESE_FERME,
    KEY_UNDER,
    KEY_FOIS,
    KEY_PLUS,
    KEY_CROCHET_OUVERT,
    KEY_CROCHET_FERME,
    KEY_TWO_POINTS,
    KEY_E_AIG_WINDOWS, 
    KEY_E_AIG_MAJ_WINDOWS,
    KEY_E_GRV_WINDOWS,
    KEY_E_GRV_MAJ_WINDOWS,
    KEY_E_CIRC_WINDOWS,
    KEY_E_CIRC_MAJ_WINDOWS,
    KEY_E_TREMA_WINDOWS,
    KEY_E_TREMA_MAJ_WINDOWS,
    KEY_A_CIRC_WINDOWS,
    KEY_A_CIRC_MAJ_WINDOWS,
    KEY_A_GRV_WINDOWS,
    KEY_A_GRV_MAJ_WINDOWS,
    KEY_I_GRAV_WINDOWS,
    KEY_C_CEDILLE_WINDOWS,
    KEY_C_CEDILLE_MAJ_WINDOWS,
    KEY_O_CIRC_WINDOWS,
    KEY_O_CIRC_MAJ_WINDOWS,
    KEY_U_CIRC_WINDOWS,
    KEY_U_GRAV_WINDOWS,
    KEY_U_GRAV_MAJ_WINDOWS,
    KEY_OE_WINDOWS,
    KEY_OE_MAJ_WINDOWS,
    KEY_PI_WINDOWS,
    KEY_DEGREE_WINDOWS,
    KEY_N_TILDE_WINDOWS,
    KEY_N_TILDE_MAJ_WINDOWS,
    KEY_GUILL_G_WINDOWS,
    KEY_GUILL_R_WINDOWS,
    KEY_INSERT,
    KEY_WINDOWS_1,
    KEY_WINDOWS_2,
    KEY_WINDOWS_3,
    KEY_WINDOWS_4,
    KEY_WINDOWS_5,
    KEY_WINDOWS_6,
    KEY_WINDOWS_7,
    KEY_WINDOWS_8,
		TMUX_KEY,
};

enum td_keycodes {
  PLACEHOLDER = SAFE_RANGE,
  TD_ESC_CAPS = 0,
  TD_COPY,
  TD_PASTE
};

uint16_t key_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case KC_LSHIFT: // record if left shift enable
      if (record->event.pressed) {
        if (!is_shift_active) {
          is_shift_active = true;
        }

        } else {
        is_shift_active = false;
      }
    break;
    /*
    case KC_LALT: // record if left alt enable
      if (record->event.pressed) {
        if (!is_alt_active) {
          is_alt_active = true;
        }
      } else {
        is_alt_active = false;
      }
      break;
    */
    case LPAR: 
			if (record->event.pressed) {
				key_timer = timer_read(); 
				register_code(KC_LSFT); 
			} else { 
				unregister_code(KC_LSFT);
				if (timer_elapsed(key_timer) < TAPPING_TERM) {
					SEND_STRING(SS_LCTL(SS_TAP(X_B)));
				} 
			} 
			break;
    case KEY_E_AIG:// 0 é
      if (record->event.pressed) {
          if (is_shift_active) {
            SEND_STRING(SS_LCTL(SS_LSFT("U")));
          send_unicode_hex_string("0x00C9");
          SEND_STRING(SS_TAP(X_END));
          SEND_STRING(SS_TAP(X_ENTER));

          } else {

          // 0 é
            SEND_STRING(SS_LCTL(SS_LSFT("U")));
            send_unicode_hex_string("0x00E9");
            SEND_STRING(SS_TAP(X_END));
            SEND_STRING(SS_TAP(X_ENTER));

        }
      }
    break;
    case KEY_E_GRV :// 2 è
    if (record->event.pressed) {
      if (!is_shift_active) {
          // 2 è
          SEND_STRING(SS_LCTL(SS_LSFT("U")));
          send_unicode_hex_string("0x00E8");
          SEND_STRING(SS_TAP(X_END));
          SEND_STRING(SS_TAP(X_ENTER));
        } else {
          // 3 È
          SEND_STRING(SS_LCTL(SS_LSFT("U")));
          send_unicode_hex_string("0x00C8");
          SEND_STRING(SS_TAP(X_END));
          SEND_STRING(SS_TAP(X_ENTER));

        }

      }
    break;

    case KEY_E_CIRC :// 4 ê
    if (record->event.pressed) {
      if (!is_shift_active) {

        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x00EA");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      } else {
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x00CA");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      }
    }
    break;

    case KEY_A_CIRC :// 8 â
    if (record->event.pressed) {
      if (!is_shift_active) {
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x00E2");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      } else {
        // 10 Â
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x00E0");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      }
    }
    break;

    case KEY_A_GRV :// 8 à
    if (record->event.pressed) {
      if (!is_shift_active) {
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x00E0");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      } else {
        // 10 Âà
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x00C0");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      }
    }
    break;

    case KEY_C_CEDILLE :// 8 â
    if (record->event.pressed) {
      if (!is_shift_active) {
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x00E7");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      } else {
        // 10 Â
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x00C7");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      }
    }
    break;

    case KEY_EURO :// 8  €
    if (record->event.pressed) {
      if (!is_shift_active) {
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x20AC");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      } else {
        // 10 Â
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x20AC");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      }
    }
    break;

     case KEY_O_CIRC :// 8  ô
    if (record->event.pressed) {
      if (!is_shift_active) {
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x00F4");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      } else {
        // 23 Ô
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x00D4");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      }
    }
    break;

    case KEY_U_GRAV :// 24 ù
    if (record->event.pressed) {
      if (!is_shift_active) {
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x00F9");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      } else {
         // 25 Ù
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x00D9");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      }
    }
    break;
    case KEY_I_GRAV :// î
    if (record->event.pressed) {
      if (!is_shift_active) {
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x00EE");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      } else {
         // î
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x00CE");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      }
    }
    break;
    case KEY_GUILL_G :// 36 «
    if (record->event.pressed) {
      if (!is_shift_active) {
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x00AB");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      } else {
         // 37 »
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x00BB");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      }
    }
    break;
    case KEY_U_CIRC :// û
    if (record->event.pressed) {
      if (!is_shift_active) {
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x00FB");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));
      } else {
         // Û
        SEND_STRING(SS_LCTL(SS_LSFT("U")));
        send_unicode_hex_string("0x00DB");
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_ENTER));   }
    }
    break;
    case KEY_SECRET :
    if (record->event.pressed) {
        SEND_STRING("");
        SEND_STRING(SS_TAP(X_ENTER));
    }
    break;
    case TMUX_KEY :
    if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a"));
    }
    case MAIL :
    if (record->event.pressed) {
        SEND_STRING("");
    }
    break;
    case KEY_PARENTHESE_OUVRE:
    if (record->event.pressed) {
      SEND_STRING("(");
    }
    break;
    case KEY_PARENTHESE_FERME:
     if (record->event.pressed) {
      SEND_STRING(")");
    }
    break;
    case KEY_UNDER:
     if (record->event.pressed) {
      SEND_STRING("_");
    }
    break;
    case KEY_FOIS:
     if (record->event.pressed) {
      SEND_STRING("*");
    }
    break;
    case KEY_PLUS:
     if (record->event.pressed) {
      SEND_STRING("+");
    }
    break;
    case KEY_CROCHET_OUVERT:
     if (record->event.pressed) {
      SEND_STRING("[");
    }
    break;
    case KEY_CROCHET_FERME:
     if (record->event.pressed) {
      SEND_STRING("]");
    }
    break;
    case KEY_TWO_POINTS:
     if (record->event.pressed) {
      SEND_STRING(":");
    }
    break; // ============================== MICROCHIOTTE
    case KEY_E_AIG_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_3)));
       }
    break;
    case KEY_E_AIG_MAJ_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_0) SS_TAP(X_KP_1)));
    }
    break;
    case KEY_E_GRV_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_2)));
    }
    break;
    case KEY_E_GRV_MAJ_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_0) SS_TAP(X_KP_0)));
    }
    break;
    case KEY_E_CIRC_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_4)));
    }
    break;
    case KEY_E_CIRC_MAJ_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_0) SS_TAP(X_KP_2)));
    }
    break;
    case KEY_A_CIRC_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_6)));
    }
    break;
    case KEY_A_CIRC_MAJ_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_4)));
    }
    break;
    case KEY_A_GRV_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_4)));
    }
    break;
    case KEY_A_GRV_MAJ_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_2)));
    }
    break;
    case KEY_C_CEDILLE_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_1)));
    }
    break;
    case KEY_C_CEDILLE_MAJ_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_2)));
    }
    break;
    case KEY_O_CIRC_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_4)));
    }
    break;
    case KEY_O_CIRC_MAJ_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_2)));
    }
    break;
    case KEY_U_CIRC_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_1)));
    }
    break;
    case KEY_I_GRAV_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_8)));
    }
    break;
    case KEY_U_GRAV_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_1)));
    }
    break;
    case KEY_U_GRAV_MAJ_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_2)));
    }
    break;
    case KEY_OE_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_2)));
    }
    break;
    case KEY_PI_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_2)));
    }
    break;
    case KEY_DEGREE_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_8)));
    }
    break;
    case KEY_GUILL_G_WINDOWS:
     if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_4) ));
    }
    break;
    case KEY_GUILL_R_WINDOWS:
     if (record->event.pressed) {
     SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_5) ));
    }
    break;
    /* case KEY_WINDOWS_1: */
     /* if (record->event.pressed) { */
     /* SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(KC_LEFT)))); */
    /* } */
    break;
    /* case KEY_WINDOWS_2: */
    /*  if (record->event.pressed) { */
    /*  SEND_STRING(SS_LGUI(SS_LCTL(KC_RIGHT))); */
    /* } */
    /* break; */
    /* case KEY_WINDOWS_3: */
    /*  if (record->event.pressed) { */
    /*  SEND_STRING(SS_LGUI(SS_LCTL(KC_D))); */
    /* } */
    /* break; */
    /* case KEY_WINDOWS_4: */
    /*  if (record->event.pressed) { */
    /*  SEND_STRING(SS_LALT(KC_F4)); */
    /* } */
    /* break; */
    /* case KEY_WINDOWS_5: */
    /*  if (record->event.pressed) { */
    /*  SEND_STRING(SS_LGUI(SS_TAP(KC_TAB))); */
    /* } */
    /* break; */
    /* case KEY_WINDOWS_6: */
    /*  if (record->event.pressed) { */
    /*  SEND_STRING(SS_LGUI(KC_LEFT)); */
    /* } */
    /* break; */
    /* case KEY_WINDOWS_7: */
    /*  if (record->event.pressed) { */
    /*  SEND_STRING(SS_LGUI(KC_RIGHT)); */
    /* } */
    /* break; */
    /* case KEY_WINDOWS_8: */
    /*  if (record->event.pressed) { */
    /*  SEND_STRING(SS_LGUI(KC_HOME)); */
    /* } */
    /* break; */
    /* case KEY_INSERT: */
    /*  if (record->event.pressed) { */
    /*   SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(KC_INSERT)))); */
    /* } */
    /* break; */
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_LAYER0] = LAYOUT(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_4, KC_BSPC,
    LT(3, KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLASH,
    MT(MOD_LGUI, KC_ESC), KC_A, KC_S, KC_D, LT(4, KC_F), KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_4, KC_ENT,
    LPAR, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLASH, KC_SLSH, LT(2, KC_SLASH), KC_DEL,
    KC_2, KC_LCTL, KC_LALT, KC_R, LT(1, KC_SPACE), KC_5, MT(MOD_LGUI, KEY_TWO_POINTS), LT(2, KEY_TWO_POINTS), KC_RALT, MO(2), OSM(MOD_MEH)
  ),

  [_LAYER1] = LAYOUT(
    KC_PWR,   KC_F1,        KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,    KC_F12,     KC_1,    DF(5),

    KEY_SECRET,    KEY_E_CIRC,  KEY_E_GRV,  KEY_E_AIG,     KC_3,     KEY_EURO,  KEY_U_CIRC,  KEY_U_GRAV,     KEY_I_GRAV,     KEY_O_CIRC,     KC_MRWD,   KC_MFFD,   KC_NO,       DF(1),

    KC_NO,    KEY_A_GRV,     KEY_A_CIRC, KC_NO  ,  KEY_TWO_POINTS,  KEY_FOIS,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_NO,     KC_SCLN,   KC_NO,      KC_NO,

    KC_NO ,    KC_NO,      KC_WBAK,  BL_DEC,   KEY_C_CEDILLE,     KC_EQL,  KC_WWW_SEARCH,    KC_NO,    KC_NO,    KC_INS,   KC_PGUP,   KC_PGDN,   KC_END,     KC_VOLU, KC_MUTE,

    KC_NO,    KC_NO,    BL_OFF,   KC_NO,    KC_NO,    KC_NO,    MAIL,    KC_NO,    KC_BRID,  KC_VOLD,  KC_1
  ),

  [_LAYER2] = LAYOUT(
    RESET, DEBUG, EEP_RST, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WAKE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO
  ),

  [_LAYER3] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_WBAK, KC_WFWD, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
   ),

  [_LAYER4] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO , KEY_UNDER, KEY_TWO_POINTS, KC_NO, KEY_PLUS, KC_NO,   KC_NO,

    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_EQL,  KC_NO, KEY_PARENTHESE_OUVRE, KEY_PARENTHESE_FERME , KEY_CROCHET_OUVERT, KEY_CROCHET_FERME, KC_NO, KC_NO,    KC_NO,

    KC_NO, KC_NO, KC_NO, KEY_FOIS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
   ),

  [_LAYER5] = LAYOUT(
    KC_GRV,       KC_1,     KC_2,     KC_3, KC_4,         KC_5, KC_6,  KC_7,    KC_8,    KC_9,    KC_0, KC_MINS, KC_EQL, KC_4, KC_BSPC,
    LT(2, KC_TAB) , KC_Q,     KC_W,     KC_E, KC_R,         KC_T, KC_Y,  KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLASH,
    LT(7, KC_ESC), KC_A,     KC_S,     KC_D, LT(4, KC_F), KC_G, KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_4, KC_ENT,
    MT(MOD_LSFT, KC_MINS),      KC_NO,    KC_Z,     KC_X, KC_C,         KC_V, KC_B,  KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLASH, KC_SLSH,  MT(MOD_RSFT, KC_EQL), KC_DEL,
    KC_2,         KC_LCTL,  KC_LALT, KC_R,  LT(6, KC_SPACE), KC_5, KC_LCTL, KC_LGUI, KC_RALT, MO(2),  OSM(MOD_MEH)
  ),

  [_LAYER6] = LAYOUT(
    KC_PWR,   KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_5, DF(0),
    KEY_SECRET, KEY_E_CIRC_WINDOWS, KEY_E_GRV_WINDOWS, KEY_E_AIG_WINDOWS, KC_3, KC_NO, KEY_U_CIRC_WINDOWS,  KEY_U_GRAV_WINDOWS, KEY_I_GRAV_WINDOWS, KEY_O_CIRC_WINDOWS, KC_MRWD, KC_MFFD, KC_NO, DF(1),
    KC_NLCK, KEY_A_GRV_WINDOWS, KEY_A_CIRC_WINDOWS, KC_NO , KEY_TWO_POINTS,
    KEY_FOIS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_SCLN, KC_NO, KC_NO,
    KC_APPLICATION , KC_NO, KC_PSCREEN, KC_INSERT, KEY_C_CEDILLE_WINDOWS, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP , KC_NO, KC_NO, KC_INS, KC_PGUP, KC_PGDN, KC_END, KC_VOLU, KC_MUTE,

    KC_NO, KC_NO, BL_OFF, KC_NO, KC_NO, KC_NO, MAIL, KC_NO, KC_BRID, KC_VOLD, KC_5
  ),
  [_LAYER7] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  LGUI(KC_LEFT), LGUI(KC_RIGHT), KC_MS_D, KC_MS_R, KC_LBRC, KC_RBRC, KC_BSLASH,
    KC_NO, KC_NO, KC_NO, KC_NO, LT(4, KC_F), KC_NO, LGUI(LCTL(KC_LEFT)) ,KC_MS_D, KC_MS_U, LGUI(LCTL(KC_RIGHT)), KC_SCLN, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, LALT(KC_F4), KC_NO, LGUI(KC_TAB),  LGUI(LCTL(KC_D)), LGUI(KC_HOME), KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO,  LT(6, KC_SPACE), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
   )
};
