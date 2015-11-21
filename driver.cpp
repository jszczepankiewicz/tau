#include <Arduino.h>
#include "driver.h"

Driver::Driver(Display display, Memory memory): display(display),memory(memory) {}

void Driver::init(){
  
}

void Driver::switchToInput0() {
  Serial.println("Switching to input 0");
  display.switchToInput0();
}

void Driver::switchToInput1() {
  Serial.println("Switching to input 1");
  display.switchToInput1();
}

void Driver::switchToInput2() {
  Serial.println("Switching to input 2");
  display.switchToInput2();
}

void Driver::switchToInput3() {
  Serial.println("Switching to input 3");
  display.switchToInput3();
}
