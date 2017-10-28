#pragma once

#include <Arduino.h>

#define HARDWARE_IMPLEMENTATION Atreus
#include "AtmegaScanner.h"

#define COLS 11
#define ROWS 4

#define CRGB(r,g,b) (cRGB){b, g, r}

class Atreus {
 public:
  Atreus(void);
  void syncLeds(void);
  void setCrgbAt(byte row, byte col, cRGB color);
  void setCrgbAt(uint8_t i, cRGB crgb);
  cRGB getCrgbAt(uint8_t i);
  uint8_t getLedIndex(byte row, byte col);

  void scanMatrix(void);
  void readMatrix(void);
  void actOnMatrixScan(void);
  void setup();
  void enableHighPowerLeds(void);
  void enableScannerPower(void);
  void rebootBootloader();

  boolean ledPowerFault(void);

  /* Key masking
   * -----------
   *
   * There are situations when one wants to ignore key events for a while, and
   * mask them out. These functions help do that. In isolation, they do nothing,
   * plugins and the core firmware is expected to make use of these.
   *
   * See `handleKeyswitchEvent` in the Kaleidoscope sources for a use-case.
   */
  void maskKey(byte row, byte col);
  void unMaskKey(byte row, byte col);
  bool isKeyMasked(byte row, byte col);
  void maskHeldKeys(void);

  keydata_t leftHandState;
  keydata_t rightHandState;
  keydata_t previousLeftHandState;
  keydata_t previousRightHandState;

 private:
  static bool isLEDChanged;
  static KeyboardioScanner leftHand;
  static KeyboardioScanner rightHand;

  static keydata_t leftHandMask;
  static keydata_t rightHandMask;
};

#define SCANBIT(row,col) ((uint32_t)1 << ((row) * 8 + (7 - (col))))


#ifndef DOXYGEN_SHOULD_SKIP_THIS


#define R0C0  SCANBIT(0, 0)
#define R0C1  SCANBIT(0, 1)
#define R0C2  SCANBIT(0, 2)
#define R0C3  SCANBIT(0, 3)
#define R0C4  SCANBIT(0, 4)
#define R0C5  SCANBIT(0, 5)
#define R0C6  SCANBIT(0, 6)
#define R0C7  SCANBIT(0, 7)
#define R1C0  SCANBIT(1, 0)
#define R1C1  SCANBIT(1, 1)
#define R1C2  SCANBIT(1, 2)
#define R1C3  SCANBIT(1, 3)
#define R1C4  SCANBIT(1, 4)
#define R1C5  SCANBIT(1, 5)
#define R1C6  SCANBIT(1, 6)
#define R1C7  SCANBIT(1, 7)
#define R2C0  SCANBIT(2, 0)
#define R2C1  SCANBIT(2, 1)
#define R2C2  SCANBIT(2, 2)
#define R2C3  SCANBIT(2, 3)
#define R2C4  SCANBIT(2, 4)
#define R2C5  SCANBIT(2, 5)
#define R2C6  SCANBIT(2, 6)
#define R2C7  SCANBIT(2, 7)
#define R3C0  SCANBIT(3, 0)
#define R3C1  SCANBIT(3, 1)
#define R3C2  SCANBIT(3, 2)
#define R3C3  SCANBIT(3, 3)
#define R3C4  SCANBIT(3, 4)
#define R3C5  SCANBIT(3, 5)
#define R3C6  SCANBIT(3, 6)
#define R3C7  SCANBIT(3, 7)

#define R0C8  SCANBIT(0, 0)
#define R0C9  SCANBIT(0, 1)
#define R0C10 SCANBIT(0, 2)
#define R0C11 SCANBIT(0, 3)
#define R0C12 SCANBIT(0, 4)
#define R0C13 SCANBIT(0, 5)
#define R0C14 SCANBIT(0, 6)
#define R0C15 SCANBIT(0, 7)
#define R1C8  SCANBIT(1, 0)
#define R1C9  SCANBIT(1, 1)
#define R1C10 SCANBIT(1, 2)
#define R1C11 SCANBIT(1, 3)
#define R1C12 SCANBIT(1, 4)
#define R1C13 SCANBIT(1, 5)
#define R1C14 SCANBIT(1, 6)
#define R1C15 SCANBIT(1, 7)
#define R2C8  SCANBIT(2, 0)
#define R2C9  SCANBIT(2, 1)
#define R2C10 SCANBIT(2, 2)
#define R2C11 SCANBIT(2, 3)
#define R2C12 SCANBIT(2, 4)
#define R2C13 SCANBIT(2, 5)
#define R2C14 SCANBIT(2, 6)
#define R2C15 SCANBIT(2, 7)
#define R3C8  SCANBIT(3, 0)
#define R3C9  SCANBIT(3, 1)
#define R3C10 SCANBIT(3, 2)
#define R3C11 SCANBIT(3, 3)
#define R3C12 SCANBIT(3, 4)
#define R3C13 SCANBIT(3, 5)
#define R3C14 SCANBIT(3, 6)
#define R3C15 SCANBIT(3, 7)


#define LED_COUNT 0


#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#define KEYMAP_STACKED(                                                     \
  r0c0, r0c1, r0c2, r0c3, r0c4,       \
  r1c0, r1c1, r1c2, r1c3, r1c4,       \
  r2c0, r2c1, r2c2, r2c3, r2c4,       \
  r3c0, r3c1, r3c2, r3c3, r3c4, r3c5, \
  \
  r0c5, r0c6, r0c7, r0c8,  r0c9, \
  r1c5, r1c6, r1c7, r1c8,  r1c9, \
  r2c5, r2c6, r2c7, r2c8,  r2c9, \
  r3c6, r3c7, r3c8, r3c9, r3c10, r3c11, \
  {                                                                         \
    {r0c0, r0c1, r0c2, r0c3, r0c4,  XXX, r0c5, r0c6, r0c7,  r0c8,  r0c9},   \
    {r1c0, r1c1, r1c2, r1c3, r1c4,  XXX, r1c5, r1c6, r1c7,  r1c8,  r1c9},   \
    {r2c0, r2c1, r2c2, r2c3, r2c4, r3c5, r2c5, r2c6, r2c7,  r2c8,  r2c9},   \
    {r3c0, r3c1, r3c2, r3c3, r3c4, r3c6, r3c7, r3c8, r3c9, r3c10, r3c11},   \
  }

#define KEYMAP(                                                             \
  r0c0, r0c1, r0c2, r0c3, r0c4,             r0c5, r0c6, r0c7,  r0c8,  r0c9, \
  r1c0, r1c1, r1c2, r1c3, r1c4,             r1c5, r1c6, r1c7,  r1c8,  r1c9, \
  r2c0, r2c1, r2c2, r2c3, r2c4,             r2c5, r2c6, r2c7,  r2c8,  r2c9, \
  r3c0, r3c1, r3c2, r3c3, r3c4, r3c5, r3c6, r3c7, r3c8, r3c9, r3c10, r3c11, \
  {                                                                         \
    {r0c0, r0c1, r0c2, r0c3, r0c4,  XXX, r0c5, r0c6, r0c7,  r0c8,  r0c9},   \
    {r1c0, r1c1, r1c2, r1c3, r1c4,  XXX, r1c5, r1c6, r1c7,  r1c8,  r1c9},   \
    {r2c0, r2c1, r2c2, r2c3, r2c4, r3c5, r2c5, r2c6, r2c7,  r2c8,  r2c9},   \
    {r3c0, r3c1, r3c2, r3c3, r3c4, r3c6, r3c7, r3c8, r3c9, r3c10, r3c11},   \
  }
