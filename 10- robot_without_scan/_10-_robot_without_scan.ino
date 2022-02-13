#include <VarSpeedServo.h>

// create servo object to control a servo
VarSpeedServo base; 
VarSpeedServo link1;
VarSpeedServo link2;
VarSpeedServo gripper;
VarSpeedServo scanner;


// Leds as indicators
int redPin=10;
int bluePin=9;
int greenPin=8;

// servo pins
const int ser3 =2;
const int ser4 =4;
const int basepin =5;
const int ser1 =6;
const int ser2 =7;
const int sensor =12;


char data;
int sw;

void setup() {
  // attaches the servo  to the servo object
  base.attach(basepin); 
  link1.attach(ser1);
  link2.attach(ser2);
  gripper.attach(ser3);
  scanner.attach(ser4);
  
  // serial communication and indicators
  Serial.begin(9600);

  // input, output 
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(sensor,INPUT);

// initial positions 
  base.write(62,10 ,true);
  link1.write(40, 10 ,true);
  link2.write(0, 10 , true);
  gripper.write(100,20,true);
  scanner.write(70,3,true);
  delay(5); 

}


void loop() {
   data='0';
   digitalWrite(redPin, LOW);
   digitalWrite(greenPin, LOW);
   digitalWrite(bluePin, LOW);
   
   
   scanner.write(70,3,true);
   base.write(55,10 ,true);
   link1.write(40, 10 ,true);
   link2.write(0, 10 , true);
   gripper.write(150,20,true);
   
  sw=digitalRead(sensor);
  if(Serial.available()>0)
  data= Serial.read();
  
  if(sw==HIGH)
  scanner.write(70,3,true);
  else
  {
  scanner.write(180,3,true);
  delay(1000);  
  }
  
   if (data=='7')
  {
          digitalWrite(redPin, LOW);
          digitalWrite(greenPin, HIGH);
          digitalWrite(bluePin, LOW);
         
          link1.write(63, 7);
          link2.write(77, 5);
          gripper.write(30, 5);
          base.write(55, 5);
          delay(10000);
          
          link1.write(40, 10);
          link2.write(20, 10);
          gripper.write(150, 5);
          base.write(90, 5);
          
          digitalWrite(redPin, HIGH);
          digitalWrite(greenPin, LOW);
          digitalWrite(bluePin, LOW);
          delay(10000);
 
  }
}

