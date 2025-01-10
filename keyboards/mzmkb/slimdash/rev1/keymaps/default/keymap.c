/* Copyright 2025 mizma (@mizma)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _GAMEMODE,
    _LOWER,
    _RAISE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define GAMEM TG(_GAMEMODE)

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
   * ,------------------------------------------------.                    .------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   -  |                    |   =  |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * | LCTL |   A  |   S  |   D  |   F  |   G  |  Del |                    |  Ins |   H  |   J  |   K  |   L  |   ;  |   '  |
   * |------+------+------+------+------+------+------.                    .------+------+------+------+------+------+------|
   * | LSFT |   Z  |   X  |   C  |   V  |   B  |                                  |   N  |   M  |   ,  |   .  |   /  | RSFT |
   * |------+------+------+------+------+--+---+--+------.              .------+--+---+--+------+------+------+------+------|
   * | RM_DN| RM_UP| GAMEM|  GUI |         |      | LALT |              | RALT |      |         | HOME |  END |PageUp|PageDn|
   * .---------------------------.  .------| Space|------|              |------| Enter|------.  .---------------------------.
   *                                | Lower|      | LSFT |              | RCTL |      | Raise|
   *                                .--------------------.              .--------------------.
   */
    [_QWERTY] = LAYOUT_ortho_5x14(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,            KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,            KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_DEL ,            KC_INS,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT,            KC_RALT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        RM_VALD, RM_VALU, GAMEM,   KC_LGUI, LOWER,   KC_SPC,  KC_LSFT,            KC_RCTL, KC_ENT,  RAISE,   KC_HOME, KC_END,  KC_PGUP, KC_PGDN
    ),

    /* Game Mode Toggle: sample toggle layer.  turn off GUI key and add arrows
   * ,------------------------------------------------.                    .------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------.                    .------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |                                  |      |      |      |      |      |      |
   * |------+------+------+------+------+--+---+--+------.              .------+--+---+--+------+------+------+------+------|
   * |      |      |      | NOOP |         |      |      |              |      |      |         |   ←  |   ↓  |   ↑  |   →  |
   * .---------------------------.  .------|      |------|              |------|      |------.  .---------------------------.
   *                                |      |      |      |              |      |      |      |
   *                                .--------------------.              .--------------------.
   */
    [_GAMEMODE] = LAYOUT_ortho_5x14(
        _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_NO,   _______, _______, _______,            _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    /* Lower: NUMPAD, App/Media keys and RGM Matrix
   * ,------------------------------------------------.                    .------------------------------------------------.
   * |   `  |      |      |      |      | Mute | Vol- |                    | Vol+ |      | NumL |   /  |   *  |   -  |      |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |      |      |      |RGBTGL|      | BrDn |                    | BrUp |      |   7  |   8  |   9  |   +  |      |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * | CAPS |      |      |RM_HUD|RM_HUU|      |RM_PRV|                    |RM_NXT|      |   4  |   5  |   6  |   ,  |      |
   * |------+------+------+------+------+------+------.                    .------+------+------+------+------+------+------|
   * |      |      |      |RM_SPD|RM_SPU|      |                                  |      |   1  |   2  |   3  |   =  |      |
   * |------+------+------+------+------+--+---+--+------.              .------+--+---+--+------+------+------+------+------|
   * |      |      |      |      |         |      |      |              |      |      |         |   0  |   .  |      |      |
   * .---------------------------.  .------|      |------|              |------| PENT |------.  .---------------------------.
   *                                |      |      |      |              |      |      |      |
   *                                .--------------------.              .--------------------.
   */
    [_LOWER] = LAYOUT_ortho_5x14(
        KC_GRV,  _______, _______, _______, _______, KC_MUTE, KC_VOLD,            KC_VOLU, _______, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, _______,
        _______, _______, _______, _______, RM_TOGG, _______, KC_BRID,            KC_BRIU, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
        KC_CAPS, _______, _______, RM_HUED, RM_HUEU, _______, RM_PREV,            RM_NEXT, _______, KC_P4,   KC_P5,   KC_P6,   KC_PCMM, _______,
        _______, _______, _______, RM_SPDD, RM_SPDU, _______, _______,            _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, _______,
        _______, _______, _______, _______, _______, _______, _______,            _______, KC_PENT, _______, KC_P0,   KC_PDOT, _______, _______
    ),

    /* Raise: Functions and Mouse
   * ,------------------------------------------------.                    .------------------------------------------------.
   * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |      |                    |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * |      |      |      |WheelL|WheelR|      |      |                    |      |      |      | Pause|ScrolL| PrnSc|  F12 |
   * |------+------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
   * | CAPS |      |Mouse3|Mouse2|Mouse1|WheelU|      |                    |      |   ←  |   ↓  |   ↑  |   →  |      |      |
   * |------+------+------+------+------+------+------.                    .------+------+------+------+------+------+------|
   * |      |Accel0|Accel1|Accel2|      |WheelD|                                  |MouseL|MouseD|MouseU|MouseR|      |      |
   * |------+------+------+------+------+--+---+--+------.              .------+--+---+--+------+------+------+------+------|
   * |      |      |      |      |         |      |      |              |      |      |         |      |      |      |      |
   * .---------------------------.  .------|      |------|              |------|      |------.  .---------------------------.
   *                                |      |      |      |              |      |      |      |
   *                                .--------------------.              .--------------------.
   */
    [_RAISE] = LAYOUT_ortho_5x14(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,            _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, KC_WH_L, KC_WH_R, _______, _______,            _______, _______, _______, KC_PAUS, KC_SCRL, KC_PSCR, KC_F12,
        KC_CAPS, _______, KC_BTN3, KC_BTN2, KC_BTN1, KC_WH_U, _______,            _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, KC_WH_D, _______,            _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______
    )
};

