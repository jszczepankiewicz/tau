#include <Arduino.h>
#include "controls.h"
#include "circuit.h"
#include <Wire.h>

Controls::Controls(Driver driver): driver(driver) {}

boolean Controls::checkError(byte result){
  /*   
    0:success
    1:data too long to fit in transmit buffer
    2:received NACK on transmit of address
    3:received NACK on transmit of data
    4:other error
   */
  if(result == 0){
     return false;
  }

  if(result == 1){
    Serial.println("ERR: expander i2c data too long to fit in transmit buffer");
  }
  if(result == 2){
    Serial.println("ERR: expander i2c received NACK on transmit of address");
  }
  if(result == 3){
    Serial.println("ERR: expander i2c received NACK on transmit of data");
  }
  if(result == 4){
    Serial.println("ERR: expander i2c other error");
  }

  return true;
}

void Controls::setLeds(byte data) {
  Wire.beginTransmission(EXPANDER_CONTROLS_ADDRESS);
  Wire.write(0x12); // address port A
  Wire.write(data);  // value to send
  byte results = Wire.endTransmission();
  checkError(results);
}

byte Controls::getInputs(){

}

/**
 * Set port A as output and B as input.
 */
void Controls::init() {
  Serial.println("Expander: setting port A as out");
  //  setting port A as output
  Wire.beginTransmission(EXPANDER_CONTROLS_ADDRESS);
  Wire.write(0x00); // IODIRA register
  Wire.write(0x00); // set all of port A to outputs
  byte results = Wire.endTransmission();
  checkError(results);

  Serial.println("Expander: setting port B as out");
  //  setting port B as input
  Wire.beginTransmission(EXPANDER_CONTROLS_ADDRESS);
  Wire.write(0x01); // IODIRB register
  Wire.write(0x00); // set all of port B to outputs
  results = Wire.endTransmission();
  checkError(results);

  Serial.println("Expander: setting leds");
  setLeds(0xAA);

  Serial.println("Controls initialized.");
}


void Controls::poll() {
  Serial.println("Polling.");
  
}

