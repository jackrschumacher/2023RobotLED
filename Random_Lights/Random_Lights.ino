// ArrayOfLedArrays - see https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples for more info on
// using multiple controllers.  In this example, we're going to set up three NEOPIXEL strips on three
// different pins, each strip getting its own CRGB array to be played with, only this time they're going
// to be all parts of an array of arrays.
// Import library
#include <FastLED.h>

#define NUM_STRIPS 4
#define NUM_LEDS_PER_STRIP 81
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];
// CRGB blueStrip[NUM_LEDS_PER_STRIP];
// CRGB whiteStrip[NUM_LEDS_PER_STRIP];

long randNumber1;
long randNumber2;
long randNumber3;

// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setup() {
  FastLED.setBrightness(50);
  
  // tell FastLED there's 81 NEOPIXEL leds on pin 12
  FastLED.addLeds<NEOPIXEL, 12>(leds[0], NUM_LEDS_PER_STRIP);
  // for(int i =0; i < NUM_LEDS_PER_STRIP; i++){
  //   blueStrip[i] = CRGB(7,30,74);
  //   whiteStrip[i] = CRGB(255,255,255);
    
    
  // }
  
}

void setRandom()
  {
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
    
    // This inner loop will go over each led in the current strip, one at a time  
    
    setRandom();
    
      
  }

