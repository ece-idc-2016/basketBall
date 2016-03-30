/* What this code is designed to do: 

 - We will push a button and send a character. Button will be connected to 
- Receive 00, 01, or 10 and light up two LEDs accordingly. [this will come later.]
- We *will* send to a serial port for troubleshooting purposes. 

   CREDITS: 

   Jeffrey Wubbenhorst
   ECE Lab Section 5 
   
 */

 
 
#include <SoftwareSerial.h>
#define Rx 10 // DOUT to pin 10
#define Tx 11 // DIN to pin 11
int button=9;  // read pushbutton from pin 9. (This may vary based on hardware configurations.)
int led=8; // write led from pin 8. (This may vary based on hardware configurations.)
bool buttonState=LOW;

SoftwareSerial Xbee (Rx, Tx);

void setup() {
  Serial.begin(9600); // Set to No line ending;
  Xbee.begin(9600); // type a char, then hit enter
  delay(500);
  pinMode(button,INPUT); // set the pre-defined pin to an input. 
  pinMode(led,OUTPUT); // set the pre-defined pin to light the LED. 
}
void loop() {
  if(Serial.available()) { // If serial data available...
    char outgoing = 'h'; // ...send a 
    // char outgoing = Serial.read(); // uncomment this line to send a character from serial data
    buttonState=digitalRead(button); // read the state of the button. 
    if(buttonState==HIGH){ // ...if the button is pushed...
         Xbee.print(outgoing); // ...print a character (in this case, 'h')
    }
   
 
}
 if(Xbee.available()) { // Is data available from XBee?
    char incoming = Xbee.read(); // Read character from xbee; 
    if(incoming=='h'){ // ...if it's an h, then...
// ...do something 
digitalWrite(led,HIGH);
    }
    Serial.println(incoming); // send to Serial Monitor
    }
      // do something
  delay(50); // run every 50 milliseconds. 
  digitalWrite(led,LOW);
}
  

