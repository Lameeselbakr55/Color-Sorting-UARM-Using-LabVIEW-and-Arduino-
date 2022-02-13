#include <VarSpeedServo.h>

int redPin=10;
int bluePin=9;
int greenPin=8;



VarSpeedServo gripper ;

void setup() {  
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
  
  }

void loop() {

  if(Serial.available()>0)
    {
      char data=((byte)Serial.read());
      if (data=='7') 
        {
          digitalWrite(greenPin, HIGH);
          digitalWrite(redPin, LOW);
          digitalWrite(bluePin, LOW);
          Serial.print(data);
         delay(100); 
  
        }
     if (data=='6')
 
        {
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
          digitalWrite(bluePin, LOW);
         delay(100);     
        }
      if (data=='5')
       { 
       digitalWrite(bluePin, HIGH);
       digitalWrite(redPin, LOW);
          digitalWrite(greenPin, LOW);
   delay(100); 
  }
    }
}
