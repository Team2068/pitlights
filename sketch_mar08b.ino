#include <FastLED.h>

#define NUM_LEDS 88
#define NUM_STRING_LEDS 200

#define DATA_PIN_STRING 5
#define DATA_PIN_LED 6

CRGB leds[NUM_LEDS];
CRGB string_leds[NUM_STRING_LEDS];

void set_all_leds(int r, int g, int b) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].setRGB(r, g, b);
  }
}

void set_all_string(int r, int g, int b) {
  for (int i = 0; i < NUM_STRING_LEDS; i++) {
    string_leds[i].setRGB(r, g, b);
  }
}

void do_funny(int r, int g, int b) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].setRGB(r, g, b);
    FastLED.show();
    delay(20);
    leds[i] = CRGB::Black;
  }
}

void do_border(int r, int g, int b){
  // 0 - 10
  leds[0].setRGB(r, g, b);
  for (int i = 0; i < 10; i++) {
    leds[i].setRGB(r, g, b);
    FastLED.show();
    delay(20);
    leds[i] = CRGB::Black;
  }
  // 10 - 77
  leds[10].setRGB(r, g, b);
  for (int i = 10; i < 77; i += 7.7) {
    leds[i].setRGB(r, g, b);
    FastLED.show();
    delay(20);
    leds[i] = CRGB::Black;
  }
  // 77 - 87
  leds[77].setRGB(r, g, b);
  for (int i = 77; i < 87; i++) {
    leds[i].setRGB(r, g, b);
    FastLED.show();
    delay(20);
    leds[i] = CRGB::Black;
  }
  // 87 - 0 
  leds[87].setRGB(r, g, b);
  for (int i = 87; i > 0; i -= 11) {
    leds[i].setRGB(r, g, b);
    FastLED.show();
    delay(20);
    leds[i] = CRGB::Black;
  }
}

void setup() {
  FastLED.addLeds<WS2812, DATA_PIN_LED, GRB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812, DATA_PIN_STRING>(string_leds, NUM_STRING_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:
  do_border(255, 255, 0);
  //do_funny(255, 255, 0);
}
