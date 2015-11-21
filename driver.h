#ifndef _DRIVER_H
#define _DRIVER_H

#include <Arduino.h>
#include "display.h"
#include "memory.h"

class Driver {
  
  private:
    Display display; 
    Memory memory;      
    
  public:
    Driver(Display display, Memory memory);

    /**
     * Initialize whole driver. Reads settings from memory and set all state on UI and underlying hardware. Should be called as some of
     * the last steps during whole firmware initialization.
     */
    void init();
    
    void switchToInput0();
    void switchToInput1();
    void switchToInput2();
    void switchToInput3();

};
#endif
