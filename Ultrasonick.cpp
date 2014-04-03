/*
  Ultrasonick.cpp - Library for HC-SR04 Ultrasonic Ranging Module.library in a minimalist way
*/

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Ultrasonick.h"

Ultrasonick::Ultrasonick(int TP, int EP) {
   pinMode(TP,OUTPUT);
   pinMode(EP,INPUT);
   Trig_pin=TP;
   Echo_pin=EP;
}

long Ultrasonick::Timing() {
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  return pulseIn(Echo_pin,HIGH); // duration
}

long Ultrasonick::Ranging(int und) {
  if (und)
    return Timing() /29 / 2 ; //CM
  else
    return Timing() / 74 / 2; //INC
}