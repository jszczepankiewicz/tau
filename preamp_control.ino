
#include "display.h"
#include "driver.h"
#include "controls.h"
//#include "i2cmaster.h"
#include <Wire.h>


//  main collaborators
Display display;
Memory memory;
Driver driver(display, memory);
Controls controls(driver);

void setup() {

  Serial.begin(9600);  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }

  Wire.begin();
  
  display.init();
  controls.init();  
  driver.init();
  Serial.println("Hardware initialized, going to test expander");  
  
  controls.setLeds(0b10101010);
  Serial.println("Expander set");
}

void loop() {
  //controls.poll();
  
}


