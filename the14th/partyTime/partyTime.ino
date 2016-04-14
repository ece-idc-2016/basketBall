
 
#include <Servo.h>                           
#include <SoftwareSerial.h>
Servo servoL;                               
Servo servoR;
int farLP = 7;
int centerLP = 6;
int centerRP = 5;
int farRP = 4;
int g1 = 75; 

const int TxPin = 9; // this is for the LCD
SoftwareSerial mySerial = SoftwareSerial(255, TxPin);

int pingPin = 2; 

int speakerOut = 3;

#define Rx 51 // DOUT to pin 10
#define Tx 53 // DIN to pin 11
SoftwareSerial Xbee (Rx, Tx);

char ledVal=' ';
int k=0;
long duration, inches, cm;
short distance=25; 

#define enablePin  11  // Connects to the RFID's ENABLE pin
#define rxPin      10  // Serial input (connects to the RFID's SOUT pin)
#define txPin      11  // Serial output (unused)
int rfidYes = 0; // "do we have RFID?" ---> NO
#define BUFSIZE    11  // Size of receive buffer (in bytes) (10-byte unique ID + null character)
#define RFID_START  0x0A  // RFID Reader Start and Stop bytes
#define RFID_STOP   0x0D
SoftwareSerial rfidSerial =  SoftwareSerial(rxPin, txPin);
char rfidData[BUFSIZE];  // Buffer for incoming data
char offset = 0;         // Offset into buffer

int ledfl = 41;
int ledml = 39;
int ledmr = 37;
int ledfr = 35;

void setup()
{
  Serial.begin(9600); // Set up Arduino Serial Monitor at 9600 baud
  servoL.attach(13);                         // Attach (programmatically connect) servos to pins on Arduino
  servoR.attach(12);
  
  pinMode(TxPin, OUTPUT);
  digitalWrite(TxPin, HIGH);
  mySerial.begin(9600);
  
  pinMode(enablePin, OUTPUT);
  pinMode(rxPin, INPUT);
  digitalWrite(enablePin, HIGH);  // disable RFID Reader
  
  Serial.begin(9600); 
  while (!Serial);   // wait until ready
  Serial.println("\n\nParallax RFID Card Reader"); // this occurs within software and it's going to be a good time

  // set the baud rate for the SoftwareSerial port
  rfidSerial.begin(2400);
  Serial.flush(); // do I need this?


  // clear RFID buffer
  char rfidData[BUFSIZE];  // Buffer for incoming data
  char offset = 0;         // Offset into buffer
  rfidData[0] = 0;

  pinMode(speakerOut, OUTPUT);//buzzer
  pinMode(ledfl, OUTPUT);//led indicator when singing a note

  pinMode(ledfl, OUTPUT);
  pinMode(ledml, OUTPUT);
  pinMode(ledmr, OUTPUT);
  pinMode(ledfr, OUTPUT);

  pinMode(farLP, OUTPUT); // set QTIs as outputs 
  pinMode(centerLP, OUTPUT);
  pinMode(centerRP, OUTPUT);
  pinMode(farRP, OUTPUT);

  digitalWrite(farLP, HIGH); 
  digitalWrite(centerLP, HIGH);
  digitalWrite(centerRP, HIGH);
  digitalWrite(farRP, HIGH);
  delayMicroseconds(230); // allow capcitor charge in QTI

  pinMode(farLP, INPUT); // set as input, get ready to read 
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
  String s = String(pin3) + String(pin2) + String(pin1) + String(pin4);
  int pins = s.toInt();


}

long RCTime(int sensorIn) {
  long duration = 0;
  pinMode(sensorIn, OUTPUT);     // Make pin OUTPUT
  digitalWrite(sensorIn, HIGH);  // Pin HIGH (discharge capacitor)
  delay(1);                      // Wait 1ms
  pinMode(sensorIn, INPUT);      // Make pin INPUT
  digitalWrite(sensorIn, LOW);   // Turn off internal pullups
  while (digitalRead(sensorIn)) { // Wait for pin to go LOW
    duration++;
  }
  return duration;
}

int isHighfR(int rctime) {
  if (rctime < 40) // was 75. Changing for yellow.
    return 0;
  else
    return 1;
}

int isHighCR(int rctime) {
  if (rctime < 20) // 50
    return 0;
  else
    return 1;
}

int isHighCL(int rctime) {
  if (rctime < 20) // was 60; replace with variable later
    return 0;
  else
    return 1;
}

int isHighfL(int rctime) {
  if (rctime < 40) // was 100
    return 0;
  else
    return 1;
}


void loop()
{

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
  String s = String(pin3) + String(pin2) + String(pin1) + String(pin4);
  int pins = s.toInt();
  int vL, vR;
  int allBlack;
  
  switch (pins)                              // Compare pins to known line following states
  {
    case 1000:
      vL = -g1;                            // -100 to 100 indicate course correction values
      vR = g1;                              // -100: full reverse; 0=stopped; 100=full forward
      break;
    case 1100:
      vL = 0; //originally -g1.
      vR = 1.5 * g1; // g1 was initially 200. vr was initially 0.
      break;
    // adding another case. Hope nothing catches fire.
    case 0011:
      vL = 1.5 * g1; // note extra
      vR = 0;
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
    case 1111: // this should go someplace outside of this loop. use a while([variable)!=1) or something. 
      
      // RFID on 
      digitalWrite(enablePin, LOW);
      // delay(100); // we can find-tune this later...
      servoL.writeMicroseconds(1500);      // stop...
      servoR.writeMicroseconds(1500);
      delay(250); // wait for a bit 
      // add in an ultrasonic statement 

      // while ultrasonic distance is greater than some predetermined value...
      // ...which is 18.5
 
    
while(k<5){ // run a few test cases to make sure we're getting solid values 
     pinMode(pingPin, OUTPUT); 
      digitalWrite(pingPin, LOW);
      delayMicroseconds(2);
      digitalWrite(pingPin, HIGH);
      delayMicroseconds(5);
      digitalWrite(pingPin, LOW);
      pinMode(pingPin, INPUT);
      duration = pulseIn(pingPin, HIGH);
      k+=1;
      delay(100); // maybe we need this delay?
}
k=0;
   
      while(cm>18.5){ // turning loop now that our sensor has warmed up a bit 
          
      pinMode(pingPin, OUTPUT); 
      digitalWrite(pingPin, LOW);
      delayMicroseconds(2);
      digitalWrite(pingPin, HIGH);
      delayMicroseconds(5);
      digitalWrite(pingPin, LOW);
      pinMode(pingPin, INPUT);
      duration = pulseIn(pingPin, HIGH);
      // convert the time into a distance
      cm = microsecondsToCentimeters(duration);
      Serial.print(cm);
      Serial.print("cm");
      Serial.println();
         servoL.writeMicroseconds(1300);      // turn...
      servoR.writeMicroseconds(1300);
      delay(100);
     // keep turning 
      }


     
      servoL.writeMicroseconds(1300);      // turn...
      servoR.writeMicroseconds(1300);
      delay(670); // this is with the robot plugged in. 
      
      // allBlack=1; // tells the line following loop to terminate
      // vL=0;
      // vR=0;
      digitalWrite(enablePin, LOW);   // enable the RFID Reader
      Serial.println("RFID time");

      while(rfidSerial.available() == 0) // until we have RFID characters...
      {
        //other stuff.
        servoL.writeMicroseconds(1500);      // ...stop! 
        servoR.writeMicroseconds(1500);
        // delay(5000); // wait for a bit. 
      servoL.writeMicroseconds(1600); // move forward
      servoR.writeMicroseconds(1400); 
      delay(100);

      } // confirm this works. 
        // ...once loop is broke...
      // STOP
      servoL.writeMicroseconds(1500);      // STOP 
      servoR.writeMicroseconds(1500);
      // and now it's ultrasonic sensor time...

        // detach our servos
        servoL.detach();                     
        servoR.detach();
        Serial.println("We have detached our servos.");
        k=0;
        digitalWrite(enablePin,HIGH);
     while(k!=5){ // take a few measurements to make sure we're getting what we want 
      Serial.print("We are taking measurements.");
      pinMode(pingPin, OUTPUT); 
      digitalWrite(pingPin, LOW);
      delayMicroseconds(2);
      digitalWrite(pingPin, HIGH);
      delayMicroseconds(5);
      digitalWrite(pingPin, LOW);
      Serial.println("We made it this far!");

      // The same pin is used to read the signal from the PING))): a HIGH
      // pulse whose duration is the time (in microseconds) from the sending
      // of the ping to the reception of its echo off of an object.
      pinMode(pingPin, INPUT);
      duration = pulseIn(pingPin, HIGH);
      Serial.println("moar");
      // convert the time into a distance
      cm = microsecondsToCentimeters(duration);
      Serial.println("cm");
      Serial.print(cm);
      Serial.print("cm");
      Serial.println();
      Serial.println("We just took a measurement.");
      delay(100);
      k+=1;
     }
      Serial.println("LED TIME");
      Xbee.begin(9600);
      // communicate what we've found 
      if (cm > 30) // if 3-pointer... 
     {
         ledVal='m'; // return 0 
         // do something 
          analogWrite(A0,255); // OR DON'T
           mySerial.write(12);                 // Clear    
          mySerial.write(17);                 // Turn backlight on
          delay(5);                           // Require  d delay
          mySerial.print("GOOOOOOLLD");  // First line   
      }
      else if (cm >= 20 && cm <= 30) // if a two-pointer...
      {
       ledVal='n'; // return 1
       // do something 
       // analogWrite(A1,255); // OR DON'T 
        mySerial.write(12);                 // Clear    
          mySerial.write(17);                 // Turn backlight on
          delay(5);                           // Require  d delay
          mySerial.print("SILVER");  // First line    
      }
      else // if(cm <= 20)
      {
        ledVal='o';
        // do something 
           // analogWrite(A1,255);
           // analogWrite(A0,255);
            mySerial.write(12);                 // Clear    
          mySerial.write(17);                 // Turn backlight on
          delay(5);                           // Require  d delay
          mySerial.print("...bronze.");  // First line    
      }

    k=0;
    while(k<200){
    Xbee.print(ledVal);
    Serial.println(ledVal);
    delay(100);
    k+=1;
    }
 // wait for a bit 

 delay(1000); // wait ten seconds or so

 

      

mySerial.write(12);  
if(Xbee.available()) { // Is data a vailable from XBee?
    char incoming = Xbee.read(); // Read character,
if(incoming == 0 || incoming == 1 || incoming == 2){
    Serial.println(incoming); // send to Seria
    mySerial.write(12);; // clear 
    mySerial.write(17);
    delay(5);
    mySerial.print(incoming); // print whatever we've got 
}

if(incoming == 0); { //dance
    
}

if(incoming == 1); { //light show
    
}

if(incoming == 2); { //national anthem
   
}
}
Serial.println("the end");
delay(50000000); // our program effectively ends because time 


break; 

// the end of our case here. (not entirely sure this is the cleanest way to do this...)

        case 0000:
            vL = 0;
            vR = 0;
            break;
      }

servoL.writeMicroseconds(1500 + vL);      // Steer robot to recenter it over the line
  servoR.writeMicroseconds(1500 - vR);


  delay(25);                                // Delay for 50 milliseconds (1/20 second)
}
}
// }


long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

