#include <VarSpeedServo.h>

// create servo objects
VarSpeedServo scanner;

// servo pins 
const int ser3 = 4;         // servo of gripper

const int sensor = 12;
int sw;


void setup() {
 pinMode(sensor,INPUT);
 Serial.begin(9600);
 servo3.attach(ser3);

}

void loop() {
    servo3.write(70,3,true);
  sw = digitalRead(sensor);
  Serial.println(sw);
  if(sw==HIGH)
  scanner.write(70,3,true);
  else
  scanner.write(180,3,true);
    delay(100);
}




