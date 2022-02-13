#include <VarSpeedServo.h>

// create servo objects
VarSpeedServo servo1 ;
VarSpeedServo servo2 ;
VarSpeedServo servo3 ;

// servo pins 
const int ser1 = 6;         // servo of link 1      
const int ser2 = 7;         // servo of link 2
const int ser3 = 2;         // servo of gripper

// attach servo objects to pins
void setup () {
 servo1.attach(ser1);
 servo2.attach(ser2);
 servo3.attach(ser3);
  servo1.write(40,25);
  servo2.write(0,10);
  servo3.write(100,50);
   delay(10000) ;
}

void loop () {
  servo1.write(25,25);
  servo2.write(110,10);
  servo3.write(0,50);
   
}




