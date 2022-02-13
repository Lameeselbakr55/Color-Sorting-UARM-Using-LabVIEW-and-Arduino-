#include <VarSpeedServo.h>

VarSpeedServo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

char data;
void setup() {
  myservo.attach(5);  // attaches the servo on pin 5 to the servo object
  Serial.begin(9600);
  pinMode(10,OUTPUT);

}


void loop() {

  for (pos = 0; pos <= 180 && data != '7' ; pos += 1)
   { 
    myservo.write(pos,10,true);              // tell servo to go to position in variable 'pos'
     if(Serial.available()>0)
      data= Serial.read();
   }
         

  for (pos = 180; pos >= 0 && data != '7' ; pos -= 1)
  { 
       myservo.write(pos,10,true);              // tell servo to go to position in variable 'pos'
        if(Serial.available()>0)
         data= Serial.read();
      
  }

}

