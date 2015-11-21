
#include "display.h"
#include "driver.h"
#include "controls.h"
#include <Wire.h>

//  main objects
Display display;
Memory memory;
Driver driver(display, memory);
Controls controls(driver);

void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }

  display.init();
  controls.init();

  Serial.println("Controls initialized.");
  driver.init();
  Serial.println("Driver initialized.");
  
}

void loop() {
  //controls.poll();
  
}


