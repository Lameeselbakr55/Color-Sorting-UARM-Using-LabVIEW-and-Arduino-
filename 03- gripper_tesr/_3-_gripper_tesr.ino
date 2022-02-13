#include <VarSpeedServo.h>

// create servo objects
VarSpeedServo servo3 ;

// servo pins 
const int ser3 = 5;         // servo of gripper

// attach servo objects to pins
void setup () {
 servo3.attach(ser3);
}

void loop () {
  servo3.write(167,3);
}




