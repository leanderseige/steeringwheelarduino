/*
 * Steering Wheel Software
 * Version: Minimal
 *
 * (c) Leander Seige, 2022, GPL V3
 */

#include "Joystick.h"

Joystick_ Joystick;

void setup() {
  Serial.begin(9600);

  Joystick.setRxAxisRange(0, 1023);
  Joystick.setRyAxisRange(0, 1023);
  Joystick.setRzAxisRange(-512, 512);
  Joystick.begin();
}

void loop() {
  int z = analogRead(A0)-512;
  Joystick.setRxAxis(0);
  Joystick.setRyAxis(0);
  Joystick.setRzAxis(z);
  Serial.println(z);
}
