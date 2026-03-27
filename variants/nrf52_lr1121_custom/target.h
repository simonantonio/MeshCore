#pragma once

#include <RadioLib.h>
#include <helpers/radiolib/RadioLibWrappers.h>
#include <Nrf52CarrierBoard.h>
#include <helpers/radiolib/CustomLR1110Wrapper.h>
#include <helpers/AutoDiscoverRTCClock.h>

// nice!nano v2 + CDSENT E80-900M2213S (LR1121 TCXO)
// Adafruit BSP: P1.xx = 32+xx

#include <helpers/sensors/EnvironmentSensorManager.h>

extern Nrf52CarrierBoard board;
extern WRAPPER_CLASS radio_driver;
extern AutoDiscoverRTCClock rtc_clock;
extern EnvironmentSensorManager sensors;

bool radio_init();
uint32_t radio_get_rng_seed();
void radio_set_params(float freq, float bw, uint8_t sf, uint8_t cr);
void radio_set_tx_power(int8_t dbm);
mesh::LocalIdentity radio_new_identity();