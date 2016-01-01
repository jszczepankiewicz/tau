#include <Arduino.h>
#include "memory.h"
#include "circuit.h"
#include <Wire.h>

#define SETTINGS_VOLUME_OFFSET 0
#define SETTINGS_IS_MUTED_OFFSET 1
#define SETTINGS_SELECTED_INPUT_INDEX 2

/**
 * @return false no error
 */
boolean Memory::checkError(byte result){
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
    Serial.println("ERR: memory i2c data too long to fit in transmit buffer");
  }
  if(result == 2){
    Serial.println("ERR: memory i2c received NACK on transmit of address");
  }
  if(result == 3){
    Serial.println("ERR: memory i2c received NACK on transmit of data");
  }
  if(result == 4){
    Serial.println("ERR: memory i2c other error");
  }

  return true;
}

byte Memory::readByte(unsigned int address) {

  Serial.println("I2C EEPROM readByte");
  byte rdata = 0xFF;
  Wire.beginTransmission(EEPROM_EXTERNAL_ADDRESS);
  Wire.write((int)(address >> 8)); // MSB
  Wire.write((int)(address & 0xFF)); // LSB
  byte err = Wire.endTransmission();
  checkError(err);
  
  Wire.requestFrom(EEPROM_EXTERNAL_ADDRESS, 1);
  
  if (Wire.available()) {
    rdata = Wire.read();
  }

  
  return rdata;
}

void Memory::writeByte(unsigned int address, byte data) {
  Serial.println("I2C EEPROM writeByte");
  
  Wire.beginTransmission(EEPROM_EXTERNAL_ADDRESS);
  Wire.write((int)(address >> 8)); // MSB
  Wire.write((int)(address & 0xFF)); // LSB
  int rdata = data;
  Wire.write(data);
  byte err = Wire.endTransmission();
  checkError(err);
  //  yes this is strange and ugly but without that there is risk of NACK if immediate read will follow
  delay(10);
}

Settings Memory::retrieveSettings() {

  int memoryOffset = 0;
  Settings settings;
  settings.volumeLevel = readByte(memoryOffset + SETTINGS_VOLUME_OFFSET);
  
  if (readByte(memoryOffset + SETTINGS_IS_MUTED_OFFSET) > 0) {
    settings.isMuted = true;
  }
  else {
    settings.isMuted = false;
  }

  settings.selectedInputIndex = readByte(memoryOffset + SETTINGS_SELECTED_INPUT_INDEX);
  return settings;
}

/**
 * TODO: change to write page to speedup / optimise
 */
void Memory::writeSettings(Settings settings) {
  
  int memoryOffset = 0;
  writeByte(memoryOffset + SETTINGS_VOLUME_OFFSET, settings.volumeLevel);
  
  if (settings.volumeLevel == true) {
    writeByte(memoryOffset + SETTINGS_IS_MUTED_OFFSET, 1);
  }
  else {
    writeByte(memoryOffset + SETTINGS_IS_MUTED_OFFSET, 0);
  }
  
  writeByte(memoryOffset + SETTINGS_SELECTED_INPUT_INDEX, settings.selectedInputIndex);  
}


