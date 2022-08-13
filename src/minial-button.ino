/*
 * Steering Wheel Software
 * Version: Minimal +Button
 *
 * (c) Leander Seige, 2022, GPL V3
 */

#include "Joystick.h"

Joystick_ Joystick;

int off = 0;

void setup() {
  Serial.begin(9600);

  Joystick.setRxAxisRange(0, 1023);
  Joystick.setRyAxisRange(0, 1023);
  Joystick.setRzAxisRange(-512, 512);
  Joystick.begin();

  pinMode(13, INPUT);

}

void loop() {
  int b = digitalRead(13);
  int z = analogRead(A0)-512;
  if(b==1) {
    off = z;
  }
  z = z - off;
  Joystick.setRxAxis(0);
  Joystick.setRyAxis(0);
  Joystick.setRzAxis(z);
  Serial.println(String(z)+" "+String(b)+" "+String(off));
}
