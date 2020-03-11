#include <FastLED.h>

#define NUM_LEDS 88
#define NUM_STRING_LEDS 500

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

void do_funny_string(int r, int g, int b) {
  for (int i = 0; i < NUM_STRING_LEDS; i++) {
    string_leds[i].setRGB(r, g, b);
    FastLED.show();
    delay(20);
    string_leds[i] = CRGB::Black;
  }
}

void do_border(int r, int g, int b){
  // 0 - 10
  leds[0].setRGB(r, g, b);
  for (int i = 0; i < 10; i++) {
    leds[i].setRGB(r, g, b);
    FastLED.show();
    delay(50);
    leds[i] = CRGB::Black;
  }
  // 10 - 77
  // 10, 11, 22, 33, 44, 55, 66, 77,
  leds[10].setRGB(r, g, b);
  for (int i = 11; i < 78; i += 11) {
    leds[10] = CRGB::Black;
    leds[i].setRGB(r, g, b);
    FastLED.show();
    delay(50);
    leds[i] = CRGB::Black;
  }
  // 77 - 87
  leds[77].setRGB(r, g, b);
  for (int i = 77; i < 87; i++) {
    leds[i].setRGB(r, g, b);
    FastLED.show();
    delay(50);
    leds[i] = CRGB::Black;
  }
  // 87 - 0 
  leds[87].setRGB(r, g, b);
  for (int i = 87; i > 20; i -= 11) {
    leds[i].setRGB(r, g, b);
    FastLED.show();
    delay(50);
    leds[i] = CRGB::Black;
  }
}

void setup() {
  FastLED.addLeds<WS2812, DATA_PIN_LED, GRB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812, DATA_PIN_STRING>(string_leds, NUM_STRING_LEDS);
  FastLED.setMaxRefreshRate(100);
}

void loop() {
  do_border(255, 255, 0);
  FastLED.clear();
}
