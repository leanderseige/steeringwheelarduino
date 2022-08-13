/*
 * Steering Wheel Software
 * Version: Minimal +Button +LED-Display
 *
 * (c) Leander Seige, 2022, GPL V3
 */

#include "Joystick.h"
#include <TM1637.h> // by AKJ, https://github.com/AKJ7/TM1637

Joystick_ Joystick;

int off = 0;
TM1637 tmA(2, 3);
TM1637 tmB(4, 5);
char d[6];

void setup() {
  Serial.begin(9600);

  Joystick.setRxAxisRange(0, 1023);
  Joystick.setRyAxisRange(0, 1023);
  Joystick.setRzAxisRange(-512, 512);
  Joystick.begin();

  pinMode(13, INPUT);

  tmA.begin();
  tmB.begin();
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
  sprintf(d,"%4d",z);
  tmA.display(String(d));
  sprintf(d,"%4d",off);
  tmB.display(String(d));
  Serial.println(String(z)+" "+String(b)+" "+String(off));
}
