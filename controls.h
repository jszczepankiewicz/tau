#ifndef _CONTROLS_H
#define _CONTROLS_H

#include <Arduino.h>
#include "driver.h"

class Controls {

  private:
    Driver driver;
    
    byte getInputs();
    boolean checkError(byte data);

  public:
    //  move to private after testing
    void setLeds(byte data);
    Controls(Driver driver);
    void init();
    // to be changed to interrupts in future
    void poll();

};
#endif
