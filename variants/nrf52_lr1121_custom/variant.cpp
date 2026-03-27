#include "variant.h"
#include "nrf.h"
#include "wiring_constants.h"
#include "wiring_digital.h"

const uint32_t g_ADigitalPinMap[] = {
  // D0 .. D10
  2,  // D0  is P0.02 (A0)
  3,  // D1  is P0.03 (A1)
  28, // D2  is P0.28 (A2)
  29, // D3  is P0.29 (A3)
  4,  // D4  is P0.04 (A4, SDA)
  5,  // D5  is P0.05 (A5, SCL)
  43, // D6  is P1.11 (TX)
  44, // D7  is P1.12 (RX)
  45, // D8  is P1.13
  46, // D9  is P1.14
  47, // D10 is P1.15

  // LEDs
  26, // D11 is P0.26 (LED RED)
  6,  // D12 is P0.06 (LED BLUE)
  30, // D13 is P0.30 (LED GREEN)
  14, // D14 is P0.14 (READ_BAT / VBAT_ENABLE)

  // LSM6DS3TR
  40, // D15 is P1.08 (6D_PWR)
  27, // D16 is P0.27 (6D_I2C_SCL)
  7,  // D17 is P0.07 (6D_I2C_SDA)
  11, // D18 is P0.11 (6D_INT1 / LORA_MOSI)

  // MIC
  42, // D19 is P1.10 (MIC_PWR)
  32, // D20 is P1.00 (LORA_SCK)        <-- was PDM_CLK, now LORA_SCK
  16, // D21 is P0.16 (PDM_DATA)

  // BQ25100
  13, // D22 is P0.13 (HICHG)
  17, // D23 is P0.17 (LORA_DIO2)       <-- was ~CHG

  // LoRa / SPI
  21, // D24 is P0.21
  25, // D25 is P0.25
  20, // D26 is P0.20 (LORA_DIO1)
  24, // D27 is P0.24 (LORA_BUSY)
  22, // D28 is P0.22 (LORA_RESET)
  23, // D29 is P0.23

  // NFC / DIO3
  9,  // D30 is P0.09 (LORA_DIO3)       <-- NFC1, repurposed as DIO9
  10, // D31 is P0.10 (NFC2)

  // VBAT
  31, // D32 is P0.31 (VBAT)

  // Extended — required for LR1121 SPI
  36, // D33 is P1.04 (LORA_MISO)       <-- new entry
  38, // D34 is P1.06 (LORA_NSS)        <-- new entry
};

void initVariant() {
  // VBAT protection — keep LOW to avoid overvoltage on P0.14
  //pinMode(VBAT_ENABLE, OUTPUT);
  // digitalWrite(VBAT_ENABLE, LOW);

  // High charging current (100mA)
  // pinMode(PIN_CHARGING_CURRENT, OUTPUT);
  // digitalWrite(PIN_CHARGING_CURRENT, LOW);

  // LoRa SPI CS idle high
  pinMode(LORA_NSS, OUTPUT);
  digitalWrite(LORA_NSS, HIGH);

  // LEDs off (active HIGH board, so HIGH = on, but start off = LOW)
  pinMode(LED_BLUE, OUTPUT);
  digitalWrite(LED_BLUE, HIGH);
}