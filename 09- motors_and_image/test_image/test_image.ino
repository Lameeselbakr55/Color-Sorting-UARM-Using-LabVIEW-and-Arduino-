#include <VarSpeedServo.h>

// create servo object to control a servo
VarSpeedServo base; 

// variable to store the servo position
int pos = 0;    
int redPin=10;
int bluePin=11;
int greenPin=12;

// variable to store the servo position
const int basepin =5;
char data;

void setup() {
  // attaches the servo  to the servo object
  base.attach(basepin); 
  
  // serial communication and indicators
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin,OUTPUT);


}


void loop() {
 
//base 
  for (pos = 0; pos <= 180 && data != '7' ; pos += 1)
   { 
    base.write(pos,3,true);              // tell servo to go to position in variable 'pos'
     if(Serial.available()>0)
      data= Serial.read();
      delay(3);
   }
         

  for (pos = 180; pos >= 0 && data != '7' ; pos -= 1)
  { 
       base.write(pos,3,true);              // tell servo to go to position in variable 'pos'
        if(Serial.available()>0)
         data= Serial.read();
         delay(3);
  }
  if (data=='7')
  {
          digitalWrite(redPin, HIGH);
          digitalWrite(greenPin, LOW);
          digitalWrite(bluePin, LOW);
          delay(10);
     
  }
   
 

}

