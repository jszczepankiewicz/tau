#ifndef _DISPLAY_H
#define _DISPLAY_H

#include <Arduino.h>

class Display {
  
    
  public:
    void init();
    void setMuted(boolean muted);

    void switchToInput0();
    void switchToInput1();
    void switchToInput2();
    void switchToInput3();

    void setVolumeLevel(byte volume);

};

#endif
