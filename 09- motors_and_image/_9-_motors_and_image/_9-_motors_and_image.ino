#include <VarSpeedServo.h>

// create servo object to control a servo
VarSpeedServo base; 
VarSpeedServo link1;
VarSpeedServo link2;
VarSpeedServo gripper;

// variable to store the servo position
int pos = 0;    
int redPin=10;
int bluePin=9;
int greenPin=8;

// variable to store the servo position
const int basepin =5;
const int ser1 =6;
const int ser2 =7;
const int ser3 =2;

char data;

void setup() {
  // attaches the servo  to the servo object
  base.attach(basepin); 
  link1.attach(ser1);
  link2.attach(ser2);
  gripper.attach(ser3);
  
  // serial communication and indicators
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin,OUTPUT);

// initial positions 
   link1.write(40, 10 ,true);
  link2.write(0, 10 , true);
  gripper.write(100, 20 , true);
  delay(5); 

}


void loop() {
  //  scanning mode
 loop: data='0';
          digitalWrite(redPin, LOW);
          digitalWrite(greenPin, LOW);
          digitalWrite(bluePin, LOW);
          link1.write(40, 10 ,true);
          link2.write(0, 10 , true);
          gripper.write(100, 20 , true);
//base 
  for (pos = 0; pos <= 180 && data != '7' ; pos += 1)
   { 
    Serial.println(pos);
     base.write(pos,2,true);              // tell servo to go to position in variable 'pos'
     if(Serial.available()>0)
      data= Serial.read();
      delay(7);
   }
   if (data=='7')
   {
   goto s;
   }       

  for (pos = 180; pos >= 0 && data != '7' ; pos -= 1)
  {
        Serial.println(pos);
       base.write(pos,2,true);              // tell servo to go to position in variable 'pos'
        if(Serial.available()>0)
         data= Serial.read();
         delay(7);

  }
  
  s: if (data=='7')
  {
    
          digitalWrite(redPin, LOW);
          digitalWrite(greenPin, HIGH);
          digitalWrite(bluePin, LOW);
          link1.write(20, 10);
          link2.write(110, 10);
          gripper.write(30, 5);
          Serial.print("pos at base =" ); 
          Serial.print(pos);
          base.write(pos, 10);
          delay(10000);
          link1.write(40, 10);
          link2.write(20, 10);
          gripper.write(150, 5);
          base.write(90, 5);
          digitalWrite(redPin, HIGH);
          digitalWrite(greenPin, LOW);
          digitalWrite(bluePin, LOW);
          delay(10000);
          goto loop;
             
     
  }
   
}

