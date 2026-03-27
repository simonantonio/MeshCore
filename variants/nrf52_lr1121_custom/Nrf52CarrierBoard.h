#pragma once

#include <MeshCore.h>
#include <Arduino.h>
#include <helpers/NRF52Board.h>

#define P_LORA_MISO     36    // P1.04 = D8
#define P_LORA_MOSI     11    // P0.11 = D7
#define P_LORA_SCLK     32    // P1.00 = D6
#define P_LORA_NSS      38    // P1.06 = D9
#define P_LORA_BUSY     24    // P0.24 = D5
#define P_LORA_DIO_1    20    // P0.20 = D3  (LR1121 DIO7)
#define P_LORA_RESET    22    // P0.22 = D4

// RF switch pins (E80 module uses DIO5/DIO6 internally via LR1121)
// DIO2 and DIO3 wired but not needed for RF switch — handled by RF_SWITCH_TABLE
#define P_LORA_DIO_2    17    // P0.17 = D2  (available, not required for init)
#define P_LORA_DIO_3    9     // P0.09 = D10 (available, not required for init)



#define  PIN_VBAT_READ 17
#define  ADC_MULTIPLIER   (1.815f) // dependent on voltage divider resistors. TODO: more accurate battery tracking

class Nrf52CarrierBoard : public NRF52BoardDCDC {
protected:
  float adc_mult = ADC_MULTIPLIER;

public:
  Nrf52CarrierBoard() : NRF52Board("Nrf52CustomCarrier_OTA") {}
  void begin();

  #define BATTERY_SAMPLES 8

  uint16_t getBattMilliVolts() override {
    analogReadResolution(12);

    uint32_t raw = 0;
    for (int i = 0; i < BATTERY_SAMPLES; i++) {
      raw += analogRead(PIN_VBAT_READ);
    }
    raw = raw / BATTERY_SAMPLES;
    return (adc_mult * raw);
  }

  bool setAdcMultiplier(float multiplier) override {
    if (multiplier == 0.0f) {
      adc_mult = ADC_MULTIPLIER;}
    else {
      adc_mult = multiplier;
    }
    return true;
  }
  float getAdcMultiplier() const override {
    if (adc_mult == 0.0f) {
      return ADC_MULTIPLIER;
    } else {
      return adc_mult;
    }
  }

  const char* getManufacturerName() const override {
    return "Nrf52 Custom Carrier Board";
  }

  void powerOff() override {
    sd_power_system_off();
  }
};
