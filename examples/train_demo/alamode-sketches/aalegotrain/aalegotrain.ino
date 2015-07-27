// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motor(1,MOTOR12_64KHZ);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  // turn on motor
  motor.setSpeed(180);
 
  motor.run(RELEASE);
}

void loop() {
  char c;
  
  if (Serial.available()){
    c = Serial.read();
    if (c == 'f'){
      Serial.println("forward");
      motor.run(FORWARD);
    }
    if (c == 'b'){
      Serial.println("backward");
      motor.run(BACKWARD);
    }
    if (c == 's'){
      Serial.println("stop");
      motor.run(RELEASE); 
    } 
    if ((c >= '0') && (c <= '9')){
      int speed = (c-'0')*20;
      Serial.print("setting speed: ");
      Serial.println(speed);
      
      motor.setSpeed(speed);
    } 
    
  }
  
 
 

}
