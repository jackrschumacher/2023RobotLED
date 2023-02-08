// ArrayOfLedArrays - see https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples for more info on
// using multiple controllers.  In this example, we're going to set up three NEOPIXEL strips on three
// different pins, each strip getting its own CRGB array to be played with, only this time they're going
// to be all parts of an array of arrays.
// Import library
#include <FastLED.h>

#define NUM_STRIPS 4
#define NUM_LEDS_PER_STRIP 81
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];
CRGB purpleStrip[NUM_LEDS_PER_STRIP];


// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setup() {
  // tell FastLED there's 60 NEOPIXEL leds on pin 2
  FastLED.addLeds<NEOPIXEL, 12>(leds[0], NUM_LEDS_PER_STRIP);
  for(int i =0; i < NUM_LEDS_PER_STRIP; i++){
    purpleStrip[i] = CRGB(20,0,25);
    
  }
  
}
void setPurple()
  {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            // Does take RGB
            leds[0][i] = CRGB(20,0,25);
            // (85,12.7,73.7)
            FastLED.show();
        }
  }

void loop() {
    
    // This inner loop will go over each led in the current strip, one at a time  
    
    
    setPurple();
    
      
      
  }

