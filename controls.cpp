#include <Arduino.h>
#include "controls.h"
#include "circuit.h"
#include <Wire.h>

Controls::Controls(Driver driver): driver(driver) {}

void Controls::setLeds(byte data) {
  Wire.beginTransmission(0x20);
  Wire.write(0x12); // address port A
  Wire.write(data);  // value to send
  Wire.endTransmission();
}

byte Controls::getInputs(){

}

/**
 * Set port A as output and B as input.
 */
void Controls::init() {

  //  setting port A as output
  Wire.beginTransmission(EXPANDER_CONTROLS_ADDRESS);
  Wire.write(0x00); // IODIRA register
  Wire.write(0x00); // set all of port A to outputs
  Wire.endTransmission();

  //  setting port B as input
  Wire.beginTransmission(EXPANDER_CONTROLS_ADDRESS);
  Wire.write(0x01); // IODIRB register
  Wire.write(0x00); // set all of port A to outputs
  Wire.endTransmission();

  setLeds(0xAA);
}


void Controls::poll() {
  Serial.println("Polling.");
  
}

