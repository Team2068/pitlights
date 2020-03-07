#include <FastLED.h>
#define DATA_PIN 6
#define NUM_LEDS 88

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int dot = 0; dot < NUM_LEDS; dot++) {
    leds[dot] = CRGB::Blue;
    FastLED.show();
    // clear this led for the next time around the loop
    leds[dot] = CRGB::Black;
    delay(30);
  }
  /*for (int j = 0; j < NUM_LEDS; j++) {
    leds[j] = (smile[j] > 0) ? CRGB::Yellow : CRGB::Black;
    FastLED.show();
    }*/
}
