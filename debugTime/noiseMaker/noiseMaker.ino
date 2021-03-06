//**************************************************
//
// Test of playtune library for Arduino MEGA 2560
//
// L. Shustek, 31 Jan 2011; initial release.
// L. Shustek, 27 Feb 2011; new score data
// L. Shustek, 6 April 2015; change for compatibility with Arduino IDE v1.6.x
//
// moar fun by Jeffrey Wubbenhorst 
//**************************************************

#include <Playtune.h>

//------------------------------------------------
//   scores are put in program space memory
//------------------------------------------------

// Playtune bytestream for file "sweetChildOMine.mid" created by MIDITONES V1.9 on Thu Apr  7 11:57:17 2016
// command line: ./miditones sweetChildOMine 
#ifdef __AVR__
#include <avr/pgmspace.h>
#else
#define PROGMEM
#endif
const unsigned char PROGMEM score [] = {
// Sequenced by P.J. Barnes
0x90,76, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 0x90,79, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,67, 0,0, 0x80, 0,0, 0x90,64, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,71, 0,0, 0x80, 0,0, 0x90,70, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,67, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 
0x90,79, 0,0, 0x80, 0,0, 0x90,81, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 
0x90,79, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,74, 0,0, 0x80, 0,0, 0x90,71, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,67, 0,0, 0x80, 0,0, 0x90,64, 0,0, 0x80, 0,0, 0x90,69, 0,0, 0x80, 0,0, 
0x90,71, 0,0, 0x80, 0,0, 0x90,70, 0,0, 0x80, 0,0, 0x90,69, 0,0, 0x80, 0,0, 
0x90,67, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 0x90,79, 0,0, 0x80, 0,0, 
0x90,81, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 0x90,79, 0,0, 0x80, 0,0, 
0x90,76, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 0x90,74, 0,0, 0x80, 0,0, 
0x90,71, 0,0, 0x80, 0,0, 0x90,79, 0,0, 0x80, 0,0, 0x90,78, 0,0, 0x80, 0,0, 
0x90,77, 0,0, 0x80, 0,0, 0x90,75, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 
0x90,68, 0,0, 0x80, 0,0, 0x90,69, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 0x90,74, 0,0, 0x80, 0,0, 
0x90,79, 0,0, 0x80, 0,0, 0x90,78, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 
0x90,75, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 0x90,84, 0,0, 0x80, 0,0, 
0x90,84, 0,0, 0x80, 0,0, 0x90,84, 0,0, 0x80, 0,0, 0x90,79, 0,0, 0x80, 0,0, 
0x90,78, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 0x90,75, 0,0, 0x80, 0,0, 
0x90,76, 0,0, 0x80, 0,0, 0x90,68, 0,0, 0x80, 0,0, 0x90,69, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,69, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,74, 0,0, 0x80, 0,0, 0x90,75, 0,0, 0x80, 0,0, 0x90,74, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,79, 0,0, 0x80, 0,0, 0x90,78, 0,0, 0x80, 0,0, 
0x90,77, 0,0, 0x80, 0,0, 0x90,75, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 
0x90,68, 0,0, 0x80, 0,0, 0x90,69, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 0x90,74, 0,0, 0x80, 0,0, 
0x90,79, 0,0, 0x80, 0,0, 0x90,78, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 
0x90,75, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 0x90,84, 0,0, 0x80, 0,0, 
0x90,84, 0,0, 0x80, 0,0, 0x90,84, 0,0, 0x80, 0,0, 0x90,79, 0,0, 0x80, 0,0, 
0x90,78, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 0x90,75, 0,0, 0x80, 0,0, 
0x90,76, 0,0, 0x80, 0,0, 0x90,68, 0,0, 0x80, 0,0, 0x90,69, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,69, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,74, 0,0, 0x80, 0,0, 0x90,75, 0,0, 0x80, 0,0, 0x90,74, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 0x90,74, 0,0, 0x80, 0,0, 
0x90,76, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 0x90,69, 0,0, 0x80, 0,0, 
0x90,67, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 0x90,74, 0,0, 0x80, 0,0, 
0x90,76, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 0x90,74, 0,0, 0x80, 0,0, 
0x90,76, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 0x90,69, 0,0, 0x80, 0,0, 
0x90,67, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 
0x90,76, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 
0x90,79, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 0x90,67, 0,0, 0x80, 0,0, 
0x90,64, 0,0, 0x80, 0,0, 0x90,69, 0,0, 0x80, 0,0, 0x90,71, 0,0, 0x80, 0,0, 
0x90,70, 0,0, 0x80, 0,0, 0x90,69, 0,0, 0x80, 0,0, 0x90,67, 0,0, 0x80, 0,0, 
0x90,76, 0,0, 0x80, 0,0, 0x90,79, 0,0, 0x80, 0,0, 0x90,81, 0,0, 0x80, 0,0, 
0x90,77, 0,0, 0x80, 0,0, 0x90,79, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,74, 0,0, 0x80, 0,0, 0x90,71, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,67, 0,0, 0x80, 0,0, 0x90,64, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,71, 0,0, 0x80, 0,0, 0x90,70, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,67, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 
0x90,79, 0,0, 0x80, 0,0, 0x90,81, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 
0x90,79, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,74, 0,0, 0x80, 0,0, 0x90,71, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,67, 0,0, 0x80, 0,0, 0x90,68, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,71, 0,0, 0x80, 0,0, 0x90,81, 0,0, 0x80, 0,0, 
0x90,81, 0,0, 0x80, 0,0, 0x90,81, 0,0, 0x80, 0,0, 0x90,79, 0,0, 0x80, 0,0, 
0x90,77, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,67, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,67, 0,0, 0x80, 0,0, 0x90,68, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,71, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 
0x90,77, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 
0x90,74, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,67, 0,0, 0x80, 0,0, 0x90,68, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,71, 0,0, 0x80, 0,0, 0x90,81, 0,0, 0x80, 0,0, 
0x90,81, 0,0, 0x80, 0,0, 0x90,81, 0,0, 0x80, 0,0, 0x90,79, 0,0, 0x80, 0,0, 
0x90,77, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,67, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,67, 0,0, 0x80, 0,0, 0x90,68, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,71, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 
0x90,77, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 
0x90,74, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,74, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,67, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,74, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,74, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,67, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 
0x90,76, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,76, 0,0, 0x80, 0,0, 0x90,79, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,67, 0,0, 0x80, 0,0, 0x90,68, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,71, 0,0, 0x80, 0,0, 0x90,81, 0,0, 0x80, 0,0, 
0x90,81, 0,0, 0x80, 0,0, 0x90,81, 0,0, 0x80, 0,0, 0x90,79, 0,0, 0x80, 0,0, 
0x90,77, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,67, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 
0x90,72, 0,0, 0x80, 0,0, 0x90,67, 0,0, 0x80, 0,0, 0x90,68, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 
0x90,69, 0,0, 0x80, 0,0, 0x90,71, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 
0x90,77, 0,0, 0x80, 0,0, 0x90,77, 0,0, 0x80, 0,0, 0x90,76, 0,0, 0x80, 0,0, 
0x90,74, 0,0, 0x80, 0,0, 0x90,72, 0,0, 0x80, 0xf0};
// This score contains 2091 bytes, and 1 tone generator is used.

Playtune pt;

void setup() {

  // Enable all 6 MEGA timers for notes that are output on digital pins 43, 45, 47, 49, 51, and 53.
  // Those pins should be wired to 500-ohm resistors, the other ends of which should be connected together
  // to one terminal of an 8-ohm speaker.  The other terminal of the speaker should be connected to ground.  
  // No other hardware is needed!

  //pt.tune_initchan (43);
  //pt.tune_initchan (45);
  pt.tune_initchan (47);
  //pt.tune_initchan (49);
  // pt.tune_initchan (51);
  // pt.tune_initchan (53);

#define DBUG 0
#if DBUG
  Serial.begin(9600);
  Serial.println("Debug");
#endif
}

void loop () {
  
  pt.tune_playscore (score); /* start playing */
  while (pt.tune_playing) ;   /* wait here until playing stops */
  pt.tune_delay(1000);        /* wait a second */
  
}


