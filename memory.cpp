#include <Arduino.h>
#include "memory.h"
#include "circuit.h"
#include <Wire.h>

#define SETTINGS_VOLUME_OFFSET 0
#define SETTINGS_IS_MUTED_OFFSET 1
#define SETTINGS_SELECTED_INPUT_INDEX 2

byte Memory::readByte(unsigned int address) {

  byte rdata = 0xFF;
  Wire.beginTransmission(EEPROM_EXTERNAL_ADDRESS);
  Wire.write((int)(address >> 8)); // MSB
  Wire.write((int)(address & 0xFF)); // LSB
  Wire.endTransmission();
  Wire.requestFrom(EEPROM_EXTERNAL_ADDRESS, 1);
  
  if (Wire.available()) {
    rdata = Wire.read();
  }
  
  return rdata;
}

void Memory::writeByte(unsigned int address, byte data) {
  Wire.beginTransmission(EEPROM_EXTERNAL_ADDRESS);
  Wire.write((int)(address >> 8)); // MSB
  Wire.write((int)(address & 0xFF)); // LSB
  int rdata = data;
  Wire.write(data);
  Wire.endTransmission();
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


