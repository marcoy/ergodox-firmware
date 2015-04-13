/* ----------------------------------------------------------------------------
 * ergoDOX layout : QWERTY (modified from the Kinesis layout)
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */


#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../matrix.h"
#include "../layout.h"

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

    KB_MATRIX_LAYER(  // layout: layer 0: default
// unused
0,
// left hand
    _equal,     _1,         _2,      _3,      _4,    _5, _esc,
_backslash,     _Q,         _W,      _E,      _R,    _T,    1,
      _tab,     _A,         _S,      _D,      _F,    _G,
   _shiftL,     _Z,         _X,      _C,      _V,    _B,    3,
     _ctrlL, _altL,     _grave,       1,   _guiL,
                                            _volumeD, _volumeU,
                                              0,      0, _home,
                                            _bs,   _del,  _end,
// right hand
        3, _6,      _7,      _8,      _9,         _0,     _dash,
_bracketL, _Y,      _U,      _I,      _O,         _P, _bracketR,
           _H,      _J,      _K,      _L, _semicolon,    _quote,
        1, _N,      _M,  _comma, _period,     _slash,   _shiftR,
               _arrowL, _arrowD, _arrowU,    _arrowR,     _guiR,
 _altR, _ctrlR,
_pageU,      0,      0,
_pageD, _enter, _space ),


    KB_MATRIX_LAYER(  // layout: layer 1: function and symbol keys
// unused
0,
// left hand
  0,        _F1,        _F2,       _F3,       _F4,       _F5, _F11,
  0,          0,          0,         0,         0,         0,    1,
  0,          0,          0,         0,         0,         0,
  0,          0,          0,         0,         0,         0,    2,
  0,          0,          0,         0,         0,
                                                             0,  0,
                                                         0,  0,  0,
                                                         0,  0,  0,
// right hand
_F12,       _F6,       _F7,       _F8,       _F9,         _F10,        0,
   0,         0,     _dash,    _equal,         0,            0,        0,
              0,        _9,        _0,         0,            0,        0,
   2,         0, _bracketL, _bracketR,         0,            0,        0,
                         0,         0,         0,            0,        0,
  0,  0,
  0,  0,  0,
  0,  0,  0 ),


    KB_MATRIX_LAYER(  // layout: layer 2: keyboard functions
// unused
0,
// left hand
  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,
                  0,  0,
              0,  0,  0,
              0,  0,  0,
// right hand
      0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,
          0,  0,  0,  0,  0,
  0,  0,
  0,  0,  0,
  0,  0,  0 ),


    KB_MATRIX_LAYER(  // layout: layer 3: gaming
// unused
0,
// left hand
    _equal,     _1,         _2,      _3,      _4,    _5, _esc,
_backslash,     _Q,         _W,      _E,      _R,    _T,    1,
      _tab,     _A,         _S,      _D,      _F,    _G,
   _shiftL,     _Z,         _X,      _C,      _V,    _B,    3,
     _ctrlL, _altL,     _grave,       1,  _space,
                                            _volumeD, _volumeU,
                                              0,      0, _home,
                                         _enter,    _bs,  _end,
// right hand
        3, _6,      _7,      _8,      _9,         _0,     _dash,
_bracketL, _Y,      _U,      _I,      _O,         _P, _bracketR,
           _H,      _J,      _K,      _L, _semicolon,    _quote,
        1, _N,      _M,  _comma, _period,     _slash,   _shiftR,
               _arrowL, _arrowD, _arrowU,    _arrowR,     _guiR,
 _altR, _ctrlR,
_pageU,      0,      0,
_pageD, _enter, _space ),

};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// aliases

// basic
#define  kprrel  &kbfun_press_release
#define  ktog    &kbfun_toggle
#define  ktrans  &kbfun_transparent
// --- layer push/pop functions
#define  lpush1   &kbfun_layer_push_1
#define  lpush2   &kbfun_layer_push_2
#define  lpush3   &kbfun_layer_push_3
#define  lpush4   &kbfun_layer_push_4
#define  lpush5   &kbfun_layer_push_5
#define  lpush6   &kbfun_layer_push_6
#define  lpush7   &kbfun_layer_push_7
#define  lpush8   &kbfun_layer_push_8
#define  lpush9   &kbfun_layer_push_9
#define  lpush10  &kbfun_layer_push_10
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  lpop3    &kbfun_layer_pop_3
#define  lpop4    &kbfun_layer_pop_4
#define  lpop5    &kbfun_layer_pop_5
#define  lpop6    &kbfun_layer_pop_6
#define  lpop7    &kbfun_layer_pop_7
#define  lpop8    &kbfun_layer_pop_8
#define  lpop9    &kbfun_layer_pop_9
#define  lpop10   &kbfun_layer_pop_10
// ---

// device
#define  dbtldr  &kbfun_jump_to_bootloader

// special
#define  sshprre  &kbfun_shift_press_release
#define  s2kcap   &kbfun_2_keys_capslock_press_release
#define  slpunum  &kbfun_layer_push_numpad
#define  slponum  &kbfun_layer_pop_numpad
#define  lsticky1 &kbfun_layer_sticky_1

// ----------------------------------------------------------------------------
// PRESS
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

    KB_MATRIX_LAYER(  // press: layer 0: default
// unused
NULL,
// left hand
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, lpush1,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 s2kcap, kprrel, kprrel, kprrel, kprrel, kprrel, lpush3,
 kprrel, kprrel, kprrel, lpush1, kprrel,
                                                 kprrel, kprrel,
                                           NULL,   NULL, kprrel,
                                         kprrel, kprrel, kprrel,
// right hand
        slpunum, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
         kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
       lsticky1, kprrel, kprrel, kprrel, kprrel, kprrel, s2kcap,
                         kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel,
 kprrel,   NULL,   NULL,
 kprrel, kprrel, kprrel ),


    KB_MATRIX_LAYER(  // press: layer 1: function and symbol keys
// unused
NULL,
// left hand
   NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,  lpop1,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, lpush2,
 ktrans, ktrans, ktrans, ktrans, ktrans,
                                                 ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
// right hand
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, ktrans,
        ktrans, ktrans, kprrel, kprrel, ktrans, ktrans, ktrans,
                ktrans,sshprre,sshprre, ktrans, ktrans, ktrans,
        lpush2, ktrans,sshprre,sshprre, ktrans, ktrans, ktrans,
                        ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans,
 ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans ),


    KB_MATRIX_LAYER(  // press: layer 2: keyboard functions
// unused
NULL,
// left hand
 dbtldr,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,
                                                   NULL,   NULL,
                                           NULL,   NULL,   NULL,
                                           NULL,   NULL,   NULL,
// right hand
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
                  NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
                          NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,
   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL ),


    KB_MATRIX_LAYER(  // press: layer 3: gaming
// unused
NULL,
// left hand
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, lpush1,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 s2kcap, kprrel, kprrel, kprrel, kprrel, kprrel,  lpop3,
 kprrel, kprrel, kprrel, lpush1, kprrel,
                                                 kprrel, kprrel,
                                           NULL,   NULL, kprrel,
                                         kprrel, kprrel, kprrel,
// right hand
        slpunum, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
         kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
       lsticky1, kprrel, kprrel, kprrel, kprrel, kprrel, s2kcap,
                         kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel,
 kprrel,   NULL,   NULL,
 kprrel, kprrel, kprrel ),
};

// ----------------------------------------------------------------------------
// RELEASE
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

    KB_MATRIX_LAYER(  // release: layer 0: default
// unused
NULL,
// left hand
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 s2kcap, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
 kprrel, kprrel, kprrel,  lpop1, kprrel,
                                                 kprrel, kprrel,
                                           NULL,   NULL, kprrel,
                                         kprrel, kprrel, kprrel,
// right hand
          NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
      lsticky1, kprrel, kprrel, kprrel, kprrel, kprrel, s2kcap,
                        kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel,
 kprrel,   NULL,   NULL,
 kprrel, kprrel, kprrel ),


    KB_MATRIX_LAYER(  // release: layer 1: function and symbol keys
// unused
NULL,
// left hand
   NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,   NULL,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,  lpop2,
 ktrans, ktrans, ktrans, ktrans, ktrans,
                                                 ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
// right hand
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, ktrans,
        ktrans, ktrans, kprrel, kprrel, ktrans, ktrans, ktrans,
                ktrans,sshprre,sshprre, ktrans, ktrans, ktrans,
         lpop2, ktrans,sshprre,sshprre, ktrans, ktrans, ktrans,
                        ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans,
 ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans ),


    KB_MATRIX_LAYER(  // release: layer 2: keyboard functions
// unused
NULL,
// left hand
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,
                                                   NULL,   NULL,
                                           NULL,   NULL,   NULL,
                                           NULL,   NULL,   NULL,
// right hand
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
                  NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
                          NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,
   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL ),


    KB_MATRIX_LAYER(  // release: layer 3: gaming
// unused
NULL,
// left hand
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 s2kcap, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
 kprrel, kprrel, kprrel,  lpop1, kprrel,
                                                 kprrel, kprrel,
                                           NULL,   NULL, kprrel,
                                         kprrel, kprrel, kprrel,
// right hand
          NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
      lsticky1, kprrel, kprrel, kprrel, kprrel, kprrel, s2kcap,
                        kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel,
 kprrel,   NULL,   NULL,
 kprrel, kprrel, kprrel ),

};

