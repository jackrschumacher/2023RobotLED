// Create 4 array's of LED's with 81 LEDs each
#include <FastLED.h>

#define NUM_STRIPS 4
#define NUM_LEDS_PER_STRIP 81
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];
CRGB redStrip[NUM_LEDS_PER_STRIP];

// Define active state of pins vs inactive pins
#define PIN_ACTIVE  0
#define PIN_INACTIVE 1

// Intialize random numbers for random LED pattern
long randNumber1;
long randNumber2;
long randNumber3;

// Setup the different strips of LEDs 
void setup() {
  FastLED.setBrightness(50);
  // tell FastLED there's 60 NEOPIXEL leds on pin 2
  FastLED.addLeds<NEOPIXEL, 12>(leds[0], NUM_LEDS_PER_STRIP);
    pinMode(0,INPUT_PULLUP);
    pinMode(1,INPUT_PULLUP);
    pinMode(2,INPUT_PULLUP);
    pinMode(3,INPUT_PULLUP);
}
// Different LED patterns
void REDALLIANCE()
  {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            leds[0][i] = CRGB(255,0,0);
            FastLED.show();
        }
  }
void CONEREQUEST()
{
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            leds[0][i] = CRGB(230,100,1);
            FastLED.show();
            
            
        }
        FastLED.delay(500);
        CLEAR();
}
void CONEAQUIRED()
  {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            leds[0][i] = CRGB(230,100,1);
            FastLED.show();
        }
  }
void CUBEREQUEST()
  {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            leds[0][i] = CRGB(20,0,25);
            FastLED.show();
        }
        FastLED.delay(500);
        CLEAR();
  }
void CUBEAQUIRED()
  {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            leds[0][i] = CRGB(20,0,25);
            FastLED.show();
        }
  }
void DISABLED()
  {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            leds[0][i] = CRGB(235,123,98);
            FastLED.show();
        }
  }
void BLUEALLIANCE()
  {
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) 
          leds[0][i] = CRGB(0,0,255)
          FastLED.show();
      }
  }
void TEAMCOLORS()
{
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            leds[0][i] = CRGB(0,0,255);
            delay(25);
            FastLED.show();
        }
  FastLED.delay(250);
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            leds[0][i] = CRGB(255,255,255);
            delay(25);
            FastLED.show();
        }
  FastLED.delay(250);
  for(int i = 81; i >= 0; i--) {
            leds[0][i] = CRGB(0,0,255);
            delay(25);
            FastLED.show();
        }
  FastLED.delay(250);
  for(int i = 81; i >= 0; i--) {
            leds[0][i] = CRGB(255,255,255);
            delay(25);
            FastLED.show();
        }
  FastLED.delay(250);
}
void CLEAR(){
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++
      leds[0][i] = CRGB(0,0,
      FastLED.show();
    }
}
void RANDOMLIGHTS(){
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            
            randNumber1 = random(0, 255);
            randNumber2 = random(0,225);
            randNumber3 = random(0,225);
            leds[0][i] = CRGB(randNumber1,randNumber2,randNumber3);
            
            FastLED.show();
        }
}
void AUTOBALANCE(){
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
                     
}
void loop(){
 
  // Initialize digital Read pins
  int pin0 = digitalRead(0);
  int pin1 = digitalRead(1);
  int pin2 = digitalRead(2);
  int pin3 = digitalRead(3);
  
   
    
    // If statements determining which pattern is being sent from the RIO w/ DIO
    if(pin0 == PIN_INACTIVE && pin1 == PIN_INACTIVE && pin2 == PIN_INACTIVE && pin3 == PIN_INACTIVE){
      DISABLED();
    }
    else if(pin0 == PIN_ACTIVE && pin1 == PIN_ACTIVE && pin2 == PIN_ACTIVE && pin3 == PIN_ACTIVE){
      TEAMCOLORS();
    }
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
    else if(pin0 == 1 && pin1 == 0 && pin2 == 1 && pin3 == 0){
      AUTOBALANCE();
    }

}

