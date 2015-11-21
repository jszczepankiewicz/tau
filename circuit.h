#ifndef _CIRCUIT_H
#define _CIRCUIT_H

//  DISPLAY LED PINS
#define DISPLAY_LED_INPUT0_PIN 5
#define DISPLAY_LED_INPUT1_PIN A3
#define DISPLAY_LED_INPUT2_PIN A1
#define DISPLAY_LED_INPUT3_PIN 3

//  BUTTON PINS
#define BTN_MUTE_PIN A7  
#define BTN_INPUT_0_PIN 4
#define BTN_INPUT_1_PIN 6
#define BTN_INPUT_2_PIN A2
#define BTN_INPUT_3_PIN A0

//  I2C devices
//  i2c address in 7bit format (lsb bit is controlled by arduino library)
//  24c04
#define EEPROM_EXTERNAL_ADDRESS 0x50

//  MCP23017
#define EXPANDER_CONTROLS_ADDRESS 0x20

#endif
