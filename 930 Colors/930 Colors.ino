// ArrayOfLedArrays - see https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples for more info on
// using multiple controllers.  In this example, we're going to set up three NEOPIXEL strips on three
// different pins, each strip getting its own CRGB array to be played with, only this time they're going
// to be all parts of an array of arrays.
// Import library
#include <FastLED.h>

#define NUM_STRIPS 1
#define NUM_LEDS_PER_STRIP 60
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];
CRGB blueStrip[NUM_LEDS_PER_STRIP];
CRGB whiteStrip[NUM_LEDS_PER_STRIP];
CRGB blackStrip[NUM_LEDS_PER_STRIP];

// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setup() {
  // tell FastLED there's 60 NEOPIXEL leds on pin 2
  FastLED.addLeds<NEOPIXEL, 12>(leds[0], NUM_LEDS_PER_STRIP);
  for(int i =0; i < NUM_LEDS_PER_STRIP; i++){
    blueStrip[i] = CRGB(7,30,74);
    whiteStrip[i] = CRGB(255,255,255);
    blackStrip[i] = CRGB(0,0,0);
    
  }
  
}
void setBlack(){
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
      // Does take RGB
      leds[0][i] = CRGB(0,0,0);
      // (85,12.7,73.7)
      FastLED.show();
    }
}
void setBluePattern()
  {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            // Does take RGB
            leds[0][i] = CRGB(0,0,255);
            delay(50);
            FastLED.show();
        }
  }
void setWhitePattern()
  {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            // Does take RGB
            leds[0][i] = CRGB(255,255,255);
            delay(50);
            FastLED.show();
        }
  }


void loop() {
    
    // This inner loop will go over each led in the current strip, one at a time  
    
    
    setBluePattern();
    FastLED.delay(1000);
    setWhitePattern();
    FastLED.delay(1000);
      
  }

