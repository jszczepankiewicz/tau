#ifndef _MEMORY_H
#define _MEMORY_H

#include <Arduino.h>

struct Settings {
  byte volumeLevel;
  boolean isMuted;
  byte selectedInputIndex;
};

class Memory {

  private:
   
    boolean checkError(byte endTransmission);

  public:
   void writeByte(unsigned int address, byte data);
    byte readByte(unsigned int address);
    Settings retrieveSettings();
    void writeSettings(Settings settings);
};

#endif
