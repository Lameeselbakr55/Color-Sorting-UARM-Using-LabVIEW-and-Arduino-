#include <VarSpeedServo.h>

int redPin=10;
int bluePin=11;
int greenPin=12;
const int ser1 =6;
const int ser2 =7;
const int ser3 =2;

VarSpeedServo gripper ;
VarSpeedServo link1 ;
VarSpeedServo link2 ;

void setup() {  
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
  
  link1.attach(ser1);
  link2.attach(ser2);
  gripper.attach(ser3);
  
  link1.write(40, 10);
  link2.write(0, 10);
  gripper.write(100, 20);
  delay(5);  
  }

void loop() {

  if(Serial.available()>0)
    {
      char data= Serial.read();
      if (data=='6') 
        {
          digitalWrite(greenPin, HIGH);
          digitalWrite(redPin, LOW);
          digitalWrite(bluePin, LOW);
          link1.write(40, 10);
          link2.write(0, 10);
          gripper.write(100, 20) ;
          delay(10);
  
        }
    else if (data=='7')
 
        {
          digitalWrite(redPin, HIGH);
          digitalWrite(greenPin, LOW);
          digitalWrite(bluePin, LOW);
          link1.write(20, 10);
          link2.write(110, 10);
          gripper.write(30, 30);
          delay(10);
        }
        else 
        {
          link1.write(40, 10);
          link2.write(0, 10);
          gripper.write(100, 20) ;
          delay(10);
  
        }
        
      }
}
