#include <Servo.h>                           // Use the Servo library (included with Arduino IDE)  
// this works. 
Servo servoL;                                // Define the left and right servos
Servo servoR;

// int pingPin=*; // this needs to be something other than 7. 
int farLP = 7;
int centerLP = 6;
int centerRP = 5;
int farRP = 4;
int turn=1400;
int g1=75; // worked at 25. 
// int led=3; 
// We need to free up a pin. 

// int tonePin= *; 


// Perform these steps with the Arduino is first powered on
void setup()
{
  Serial.begin(9600);                        // Set up Arduino Serial Monitor at 9600 baud
  servoL.attach(13);                         // Attach (programmatically connect) servos to pins on Arduino
  servoR.attach(12);
/*
 * 
 *  Here is where the auto-calibrate code is going to be. 
 *  tone(2,100
 *  wait(2000);
 *  
 */

 
}

void loop()
{
    servoL.writeMicroseconds(1500);      // Steer robot to recenter it over the line
       servoR.writeMicroseconds(1500);
       delay(250);
      servoL.writeMicroseconds(1300);      // Steer robot to recenter it over the line
      servoR.writeMicroseconds(1300);
      delay(1000);
}

