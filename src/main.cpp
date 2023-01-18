#include <Arduino.h>
#include "pinLayoutESP32.cpp"


void setup() {
  Serial.begin (115200);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);

  pinMode(D13, OUTPUT);
  digitalWrite(D13, LOW);

  pinMode(D4, INPUT);

  Serial.println ("Start");


  ledcSetup(0, 5000, 8);
  ledcAttachPin(D13, 0);
}

void loop() {

  float potValue = (analogRead(D14) / 4095.0 -1) * -1;
  Serial.println(potValue);
  delay(50);

  // for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
  ledcWrite(0, potValue * 255);
  //   delay(15);
  // }

  // // decrease the LED brightness
  // for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
  //   // changing the LED brightness with PWM
  //   ledcWrite(0, dutyCycle);   
  //   delay(15);
  // }


  // if(digitalRead(D4)){
  //   digitalWrite(D13, HIGH);
  // }else{
  //   digitalWrite(D13, LOW);
  // }

  // Serial.println ("high");
  // delay(500);

  // Serial.println ("low");
  // delay(500);
}
