/* 
 *  
 *  
 *  We need to build in an auto-calibration case which can be entered when a button is pushed. 
 */

#include <Servo.h>                           // Use the Servo library (included with Arduino IDE)  
#include <SoftwareSerial.h>
Servo servoL;                                // Define the left and right servos
Servo servoR;

// int pingPin=*; // this needs to be something other than 7. 
int farLP = 7;
// int button=9;
int centerLP = 6;
int centerRP = 5;
int farRP = 4;
long duration, inches, cm;
int g1=75; // worked at 25. 
// int led=3; 
// We need to free up a pin. 

// code for RFID: 
#define enablePin  11  // Connects to the RFID's ENABLE pin
#define rxPin      10  // Serial input (connects to the RFID's SOUT pin)
#define txPin      11  // Serial output (unused)
int rfidYes=0; // "do we have RFID?"
#define BUFSIZE    11  // Size of receive buffer (in bytes) (10-byte unique ID + null character)

#define RFID_START  0x0A  // RFID Reader Start and Stop bytes
#define RFID_STOP   0x0D
SoftwareSerial rfidSerial =  SoftwareSerial(rxPin, txPin);


// int tonePin= *; 


// Perform these steps with the Arduino is first powered on
void setup()
{
  Serial.begin(9600);                        // Set up Arduino Serial Monitor at 9600 baud
  servoL.attach(13);                         // Attach (programmatically connect) servos to pins on Arduino
  servoR.attach(12);
  pinMode(enablePin, OUTPUT);
  pinMode(rxPin, INPUT);

  digitalWrite(enablePin, HIGH);  // disable RFID Reader
  
  // setup Arduino Serial Monitor
   Serial.begin(9600); // we already did this which is why it's commented out 
  while (!Serial);   // wait until ready
  Serial.println("\n\nParallax RFID Card Reader"); // this occurs within software and it's going to be a good time 
  
  // set the baud rate for the SoftwareSerial port
  rfidSerial.begin(2400);
    Serial.flush(); // do I need this? 

    // clear RFID buffer 
      char rfidData[BUFSIZE];  // Buffer for incoming data
  char offset = 0;         // Offset into buffer
  rfidData[0] = 0;  

/*
 * 
 *  Here is where the auto-calibrate code is going to be. 
 *  tone(2,100
 *  wait(2000);
 *  
 */

 
}

long RCTime(int sensorIn){
   long duration = 0;
   pinMode(sensorIn, OUTPUT);     // Make pin OUTPUT
   digitalWrite(sensorIn, HIGH);  // Pin HIGH (discharge capacitor)
   delay(1);                      // Wait 1ms
   pinMode(sensorIn, INPUT);      // Make pin INPUT
   digitalWrite(sensorIn, LOW);   // Turn off internal pullups
   while(digitalRead(sensorIn)){  // Wait for pin to go LOW
      duration++;
   }
   return duration;
}

int isHighfR(int rctime) {
  if(rctime < 40) // was 75. Changing for yellow.
    return 0;
  else
    return 1;
}

int isHighCR(int rctime) {
  if(rctime < 20) // 50 
    return 0;
  else
    return 1;
}

int isHighCL(int rctime) {
  if(rctime < 20) // was 60; replace with variable later
    return 0;
  else
    return 1;
}

int isHighfL(int rctime) {
  if(rctime < 40) // was 100 
    return 0;
  else
    return 1;
}

void loop()
{
  pinMode(farLP, OUTPUT);
  pinMode(centerLP, OUTPUT);
  pinMode(centerRP, OUTPUT);
  pinMode(farRP, OUTPUT);
  
  digitalWrite(farLP, HIGH);
  digitalWrite(centerLP, HIGH);
  digitalWrite(centerRP, HIGH);
  digitalWrite(farRP, HIGH);
  delayMicroseconds(230); // allow capcitor charge in QTI

  pinMode(farLP, INPUT);
  pinMode(centerLP, INPUT);
  pinMode(centerRP, INPUT);
  pinMode(farRP, INPUT);

  digitalWrite(farLP, LOW);
  digitalWrite(centerLP, LOW);
  digitalWrite(centerRP, LOW);
  digitalWrite(farRP, LOW);

  delayMicroseconds(230);
  

  int pin4 = isHighfR(RCTime(farRP));
  int pin1 = isHighCR(RCTime(centerRP));
  int pin2 = isHighCL(RCTime(centerLP));
  int pin3 = isHighfL(RCTime(farLP)); 
  Serial.println(RCTime(centerLP));
  //Serial.println(isHighCR(RCTime(farRP)));
  String s = String(pin3) + String(pin2) + String(pin1) + String(pin4);
  int pins = s.toInt();
  Serial.println(pins);
 
  // Determine how to steer based on state of the four QTI sensors
  int vL, vR;
  int allBlack;
  /*
  if (allBlack=0)
  {
    */  
  switch(pins)                               // Compare pins to known line following states
  {
    case 1000:                        
      vL = -g1;                            // -100 to 100 indicate course correction values
      vR = g1;                              // -100: full reverse; 0=stopped; 100=full forward
      break;
    case 1100:                        
      vL = 0; //originally -g1. 
      vR = 1.5*g1;   // g1 was initially 200. vr was initially 0. 
      break;
      // adding another case. Hope nothing catches fire. 
    case 0011:
      vL=1.5*g1; // note extra 
      vR=0;
      break;
    case 101:
      vL = -g1;
      vR = -g1;
      break;
    case 1010:
      vL = g1;
      vR = g1;
    case 100:                        
      vL = -g1;
      vR = g1;
      break;
    case 110:                        
      vL = 100;
      vR = 100;
      break;
    case 10:                        
      vL = g1;
      vR = -g1;
      break;
    case 11:                        
      vL = 0;
      vR = -g1;
      break;
    case 1:                        
      vL = g1;
      vR = -g1;
      break;
    case 1110:
      vL = -g1;
      vR = g1;
      break;
    case 111: 
      vL = g1;
      vR = -g1;
      break;
    case 1111:
     digitalWrite(enablePin, LOW);
       // servoL.writeMicroseconds(1500+);      // Steer robot to recenter it over the line
      // servoR.writeMicroseconds(1500-vR);
      // delay(100); // we can find-tune this later...
   servoL.writeMicroseconds(1500);      // Steer robot to recenter it over the line
       servoR.writeMicroseconds(1500);
       delay(250);
      servoL.writeMicroseconds(1300);      // Steer robot to recenter it over the line
      servoR.writeMicroseconds(1300);
      delay(750);
         servoL.writeMicroseconds(1500);      // Steer robot to recenter it over the line
       servoR.writeMicroseconds(1500); // ...I should make this terminate with the ultrasonic distance...
       delay(20);
         servoL.writeMicroseconds(1700);      // Steer robot to recenter it over the line
       servoR.writeMicroseconds(1300);
       delay(1000);
      allBlack=1; // tells the line following loop to terminate
      // vL=0;
      // vR=0;
       // while ! RFID data, move forward
       servoL.writeMicroseconds(1700);      // Steer robot to recenter it over the line
       servoR.writeMicroseconds(1300); 
       digitalWrite(enablePin, LOW);   // enable the RFID Reader
  Serial.println("RFID time"); 
  // Wait for a response from the RFID Reader
  

  
  {
     servoL.writeMicroseconds(1700);      // Steer robot to recenter it over the line
       servoR.writeMicroseconds(1300); 
       servoL.writeMicroseconds(1500);      // Steer robot to recenter it over the line
       servoR.writeMicroseconds(1500);
       delay(25);
       
  /*
    if (rfidSerial.available() > 0) // If there are any bytes available to read, then the RFID Reader has probably seen a valid tag
    {
      rfidData[offset] = rfidSerial.read();  // Get the byte and store it in our buffer
      if (rfidData[offset] == RFID_START)    // If we receive the start byte from the RFID Reader, then get ready to receive the tag's unique ID
      {
        offset = -1;     // Clear offset (will be incremented back to 0 at the end of the loop)
      }
      else if (rfidData[offset] == RFID_STOP)  // If we receive the stop byte from the RFID Reader, then the tag's entire unique ID has been sent
      {
        rfidData[offset] = 0; // Null terminate the string of bytes we just received
        break;                // Break out of the loop
      }
          
      offset++;  // Increment offset into array
      if (offset >= BUFSIZE) offset = 0; // If the incoming data string is longer than our buffer, wrap around to avoid going out-of-bounds
    }
  }

  Serial.println(rfidData);       // The rfidData string should now contain the tag's unique ID with a null termination, so display it on the Serial Monitor
  Serial.flush();                 // Wait for all bytes to be transmitted to the Serial Monitor
  */
}


      
      
      
      break;



      
    case 0000:
      vL = 0;
      vR = 0; 
      break;
  }
 
  servoL.writeMicroseconds(1500 + vL);      // Steer robot to recenter it over the line
  servoR.writeMicroseconds(1500 - vR);
/*
  }  else{
     // break our loop and proceed to our sensing
     servoL.writeMicroseconds(1500+100);
     servoR.writeMicroseconds(1500-100);
     
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  // inches = microsecondsToInches(duration); // because inches are dumb -Jeffrey 
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  

  delay(100);
}

  }
*/  
  
  delay(25);                                // Delay for 50 milliseconds (1/20 second)
}

