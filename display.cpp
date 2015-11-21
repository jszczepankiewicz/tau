#include <Arduino.h>
#include "display.h"
#include "circuit.h"

void Display::init() {
  pinMode(DISPLAY_LED_INPUT0_PIN, OUTPUT);
  pinMode(DISPLAY_LED_INPUT1_PIN, OUTPUT);
  pinMode(DISPLAY_LED_INPUT2_PIN, OUTPUT);
  pinMode(DISPLAY_LED_INPUT3_PIN, OUTPUT);
}


void Display::setMuted(boolean muted) {

}

void Display::switchToInput0() {
  digitalWrite(DISPLAY_LED_INPUT0_PIN, HIGH);  // turn LED ON
  digitalWrite(DISPLAY_LED_INPUT1_PIN, LOW);  // turn LED OFF
  digitalWrite(DISPLAY_LED_INPUT2_PIN, LOW);  // turn LED OFF
  digitalWrite(DISPLAY_LED_INPUT3_PIN, LOW);  // turn LED OFF
}

void Display::switchToInput1() {
  digitalWrite(DISPLAY_LED_INPUT0_PIN, LOW);  // turn LED OFF
  digitalWrite(DISPLAY_LED_INPUT1_PIN, HIGH);  // turn LED ON
  digitalWrite(DISPLAY_LED_INPUT2_PIN, LOW);  // turn LED OFF
  digitalWrite(DISPLAY_LED_INPUT3_PIN, LOW);  // turn LED OFF
}

void Display::switchToInput2() {
  digitalWrite(DISPLAY_LED_INPUT0_PIN, LOW);  // turn LED OFF
  digitalWrite(DISPLAY_LED_INPUT1_PIN, LOW);  // turn LED OFF
  digitalWrite(DISPLAY_LED_INPUT2_PIN, HIGH);  // turn LED ON
  digitalWrite(DISPLAY_LED_INPUT3_PIN, LOW);  // turn LED OFF
}

void Display::switchToInput3() {
  digitalWrite(DISPLAY_LED_INPUT0_PIN, LOW);  // turn LED OFF
  digitalWrite(DISPLAY_LED_INPUT1_PIN, LOW);  // turn LED OFF
  digitalWrite(DISPLAY_LED_INPUT2_PIN, LOW);  // turn LED OFF
  digitalWrite(DISPLAY_LED_INPUT3_PIN, HIGH);  // turn LED ON
}

void Display::setVolumeLevel(byte muted) {

}


