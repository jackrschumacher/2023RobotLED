// ArrayOfLedArrays - see https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples for more info on
// using multiple controllers.  In this example, we're going to set up three NEOPIXEL strips on three
// different pins, each strip getting its own CRGB array to be played with, only this time they're going
// to be all parts of an array of arrays.
// Import library
#include <FastLED.h>

#define NUM_STRIPS 4
#define NUM_LEDS_PER_STRIP 81
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];
CRGB redStrip[NUM_LEDS_PER_STRIP];

#define PIN_ACTIVE  0
#define PIN_INACTIVE 1

long randNumber1;
long randNumber2;
long randNumber3;
// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setup() {
  FastLED.setBrightness(50);
  // tell FastLED there's 60 NEOPIXEL leds on pin 2
  FastLED.addLeds<NEOPIXEL, 12>(leds[0], NUM_LEDS_PER_STRIP);
    pinMode(0,INPUT_PULLUP);
    pinMode(1,INPUT_PULLUP);
    pinMode(2,INPUT_PULLUP);
    pinMode(3,INPUT_PULLUP);
}
void REDALLIANCE()
  {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            // Does take RGB
            leds[0][i] = CRGB(255,0,0);
            // (85,12.7,73.7)
            FastLED.show();
        }
  }
void CONEREQUEST()
{
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            // Does take RGB
            leds[0][i] = CRGB(230,100,1);
            // (85,12.7,73.7)
            FastLED.show();
            
            
        }
        FastLED.delay(500);
        CLEAR();
}
void CONEAQUIRED()
  {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            // Does take RGB
            leds[0][i] = CRGB(230,100,1);
            // (85,12.7,73.7)
            FastLED.show();
        }
  }
void CUBEREQUEST()
  {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            // Does take RGB
            leds[0][i] = CRGB(20,0,25);
            // (85,12.7,73.7)
            FastLED.show();
        }
        FastLED.delay(500);
        CLEAR();
  }
void CUBEAQUIRED()
  {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            // Does take RGB
            leds[0][i] = CRGB(20,0,25);
            // (85,12.7,73.7)
            FastLED.show();
        }
  }
void DISABLED()
  {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            // Does take RGB
            leds[0][i] = CRGB(235,123,98);
            // (85,12.7,73.7)
            FastLED.show();
        }
  }
void BLUEALLIANCE()
  {
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
          // Does take RGB
          leds[0][i] = CRGB(0,0,255);
          // (85,12.7,73.7)
          FastLED.show();
      }
  }
// void TEAMCOLORS()
// {
//   for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
//             // Does take RGB
//             leds[0][i] = CRGB(0,0,255);
//             delay(25);
//             FastLED.show();
//         }
//   FastLED.delay(250);
//   for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
//             // Does take RGB
//             leds[0][i] = CRGB(255,255,255);
//             delay(25);
//             FastLED.show();
//         }
//   FastLED.delay(250);
//   for(int i = 81; i >= 0; i--) {
//             // Does take RGB
//             leds[0][i] = CRGB(0,0,255);
//             delay(25);
//             FastLED.show();
//         }
//   FastLED.delay(250);
//   for(int i = 81; i >= 0; i--) {
//             // Does take RGB
//             leds[0][i] = CRGB(255,255,255);
//             delay(25);
//             FastLED.show();
//         }
//   FastLED.delay(250);
// }
void CLEAR(){
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
      // Does take RGB
      leds[0][i] = CRGB(0,0,0);
      // (85,12.7,73.7)
      FastLED.show();
    }
}
void RANDOMLIGHTS(){
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            // Does take RGB
            randNumber1 = random(0, 255);
            randNumber2 = random(0,225);
            randNumber3 = random(0,225);
            leds[0][i] = CRGB(randNumber1,randNumber2,randNumber3);
            
            FastLED.show();
        }
}
void loop() {
 
  
    int pin0 = digitalRead(0);
    int pin1 = digitalRead(1);
    int pin2 = digitalRead(2);
    int pin3 = digitalRead(3);
    
   Serial.print(pin0);
   Serial.print(pin1);
   Serial.print(pin2);
   Serial.println(pin3);
    
    // This inner loop will go over each led in the current strip, one at a time
    if(pin0 == PIN_INACTIVE && pin1 == PIN_INACTIVE && pin2 == PIN_INACTIVE && pin3 == PIN_INACTIVE){
      DISABLED();
      }
    // else if(pin0 == PIN_ACTIVE && pin1 == PIN_ACTIVE && pin2 == PIN_ACTIVE && pin3 == PIN_ACTIVE){
    //   TEAMCOLORS();
    // }
    else if(pin0 == PIN_ACTIVE && pin1 == PIN_ACTIVE && pin2 == PIN_INACTIVE && pin3 == PIN_INACTIVE){
      BLUEALLIANCE();
    }
    else if(pin0 == PIN_ACTIVE && pin1 == PIN_ACTIVE && pin2 == PIN_ACTIVE && pin3 == PIN_INACTIVE){
      REDALLIANCE();
    }
    else if(pin0 == PIN_ACTIVE && pin1 == PIN_INACTIVE && pin2 == PIN_INACTIVE && pin3 == PIN_INACTIVE){
      CONEREQUEST();
    }
    else if(pin0 == PIN_INACTIVE && pin1 == PIN_INACTIVE && pin2 == PIN_INACTIVE && pin3 == PIN_ACTIVE){
      CONEAQUIRED();
    }
    else if(pin0 == PIN_INACTIVE && pin1 == PIN_ACTIVE && pin2 == PIN_INACTIVE && pin3 == PIN_INACTIVE){
      CUBEREQUEST();
    }
    else if(pin0 == PIN_INACTIVE && pin1 == PIN_INACTIVE && pin2 == PIN_ACTIVE && pin3 == PIN_INACTIVE){
      CUBEAQUIRED();
    }
    else if(pin0 == PIN_INACTIVE && pin1 == PIN_INACTIVE && pin2 == PIN_ACTIVE && pin3 == PIN_ACTIVE){
      RANDOMLIGHTS();      
    }
    else{
      CLEAR();
    }
    // else if(pin0 == 1 && pin1 == 0 && pin2 == 1 && pin3 == 0){
    //   AUTOBALANCE();
    // }
   

    
      
      
  }

