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


char data;

void setup() {
  // attaches the servo  to the servo object
  base.attach(basepin); 
  link1.attach(ser1);
  link2.attach(ser2);
  gripper.attach(ser3);
  scanner.attach(ser4);
  
  // serial communication and indicators
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }

  // input, output 
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin,OUTPUT);

// initial positions 
  base.write(20,5 ,true);
  link1.write(40, 10 ,true);
  link2.write(0, 10 , true);
  gripper.write(100,20,true);
  scanner.write(180,30,true);
  delay(5); 

}


void loop() {
   loop: data='0';
  
   digitalWrite(redPin, LOW);
   digitalWrite(greenPin, LOW);
   digitalWrite(bluePin, LOW);
  
   
   scanner.write(180,30,true);
   base.write(143,7 ,true);
   link1.write(42, 15 ,true);
   link2.write(0,20 , true);
   gripper.write(150,40,true);
   delay(350);

   
   scanner.write(70,30,true);
   base.write(144,30 ,true);
   link1.write(42, 15 ,true);
   link2.write(0,20, true);
   gripper.write(150,50,true);
   delay(2000);    
while(1)
{
   if(Serial.available())
      data = Serial.read();
   if (data=='5')
  {
          digitalWrite(redPin, LOW);
          digitalWrite(greenPin, HIGH);
          digitalWrite(bluePin, LOW);
// down to reach object
          scanner.write(0,30,true);
          link1.write(42, 30,true);
          link2.write(45,20,true);
          gripper.write(150,50,true);
          base.write(143,7,true);
          delay(600);
// pick object
          gripper.write(0,70,true);
          delay(500);

// up and put       
          link1.write(45, 30,true);
          link2.write(15,15,true);
          base.write(170,25,true);  
          gripper.write(150,50,true);
          scanner.write(180,30,true);
          delay(250);
        goto loop;
 
  }

  // red

   else if (data=='6')
  {
          digitalWrite(redPin, HIGH);
          digitalWrite(greenPin, LOW);
          digitalWrite(bluePin, LOW);
// down to reach object
          scanner.write(0,30,true);
          link1.write(42,30,true);
          link2.write(45,20,true);
          gripper.write(150,50,true);
          base.write(144,true);
          delay(600);
// pick object
          gripper.write(0,70,true);
          delay(500);

// up and put       
          link1.write(45,30,true);
          link2.write(20,25,true);
          base.write(117,15,true);  
          gripper.write(150,50,true);
          scanner.write(180,30,true);
          delay(250);
         
       goto loop;
 
  }
}
}
