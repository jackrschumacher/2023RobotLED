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


long randNumber1;
long randNumber2;
long randNumber3;
// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setup() {
  FastLED.setBrightness(50);
  // tell FastLED there's 60 NEOPIXEL leds on pin 2
  FastLED.addLeds<NEOPIXEL, 12>(leds[0], NUM_LEDS_PER_STRIP);
  

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
            leds[0][i] = CRGB(255,20,0);
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
void TEAMCOLORS()
{
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            // Does take RGB
            leds[0][i] = CRGB(0,0,255);
            delay(25);
            FastLED.show();
        }
  FastLED.delay(250);
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            // Does take RGB
            leds[0][i] = CRGB(255,255,255);
            delay(25);
            FastLED.show();
        }
  FastLED.delay(250);
  for(int i = 81; i >= 0; i--) {
            // Does take RGB
            leds[0][i] = CRGB(0,0,255);
            delay(25);
            FastLED.show();
        }
  FastLED.delay(250);
  for(int i = 81; i >= 0; i--) {
            // Does take RGB
            leds[0][i] = CRGB(255,255,255);
            delay(25);
            FastLED.show();
        }
  FastLED.delay(250);
}
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

    
    // This inner loop will go over each led in the current strip, one at a time
    if(pin0 == 0 && pin1 == 0 && pin2 == 0 && pin3 == 0){
      DISABLED();
    }
    else if(pin0 == 1 && pin1 == 1 && pin2 == 1 && pin3 == 1){
      TEAMCOLORS();
    }
    else if(pin0 == 1 && pin1 == 1 && pin2 == 0 && pin3 == 0){
      BLUEALLIANCE();
    }
    else if(pin0 == 1 && pin1 == 1 && pin2 == 1 && pin3 == 0){
      REDALLIANCE();
    }
    else if(pin0 == 1 && pin1 == 0 && pin2 == 0 && pin3 == 0){
      CONEREQUEST();
    }
    else if(pin0 == 0 && pin1 == 0 && pin2 == 0 && pin3 == 1){
      CONEAQUIRED();
    }
    else if(pin0 == 0 && pin1 == 1 && pin2 == 0 && pin3 == 0){
      CUBEREQUEST();
    }
    else if(pin0 == 0 && pin1 == 0 && pin2 == 1 && pin3 == 0){
      CUBEAQUIRED();
    }
    else if(pin0 == 0 && pin1 == 0 && pin2 == 1 && pin3 == 1){
      RANDOMLIGHTS();      
    }
    else{
      CLEAR();
    }
    // else if(pin0 == 1 && pin1 == 0 && pin2 == 1 && pin3 == 0){
    //   AUTOBALANCE();
    // }
   

    
      
      
  }

