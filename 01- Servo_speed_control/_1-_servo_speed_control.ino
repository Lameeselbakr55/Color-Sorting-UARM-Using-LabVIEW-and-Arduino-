
#include <VarSpeedServo.h> 

VarSpeedServo myservo1;

const int servoPin1 = 9;  // the digital pin used for the servo


void setup() {
  myservo1.attach(servoPin1);
}



void loop() {
  
 
    myservo1.write(50, 20);     
    myservo1.wait();
 
      
    myservo1.write(180, 10);     
    myservo1.wait();

    myservo1.write(0, 100);     
    myservo1.wait();
   
    
  }
  


