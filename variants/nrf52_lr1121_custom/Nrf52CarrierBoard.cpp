#include <Arduino.h>
#include <Wire.h>

#include "Nrf52CarrierBoard.h"

void Nrf52CarrierBoard::begin() {    
    NRF52Board::begin();
  
    pinMode(PIN_VBAT_READ, INPUT);

    #if defined(PIN_BOARD_SDA) && defined(PIN_BOARD_SCL)
      Wire.setPins(PIN_BOARD_SDA, PIN_BOARD_SCL);
    #endif
    
    Wire.begin();

    delay(10);   // give lr1121 some time to power up
}