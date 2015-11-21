#ifndef _CONTROLS_H
#define _CONTROLS_H

#include <Arduino.h>
#include "driver.h"

class Controls {

  private:
    Driver driver;
    void setLeds(byte data);
    byte getInputs();

  public:
    Controls(Driver driver);
    void init();
    // to be changed to interrupts in future
    void poll();

};
#endif
