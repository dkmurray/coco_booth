#include <FastLED.h>

#define LED_PIN     14
#define NUM_LEDS    150
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

CRGBPalette16 currentPalette;
TBlendType    currentBlending;


extern const TProgmemPalette16 Fyrus_p PROGMEM;

DEFINE_GRADIENT_PALETTE( heatmap_gp ) {
0, 0, 0, 0, // black
128,   255, 255,  0,   //bright yellow
191, 255, 140,  0,// Orange
255, 255,   0,  0}; //red

CRGBPalette16 Fyrus = heatmap_gp;


/*//////////////////////////////////////////////////////////////////////////////
// Initialize.
//////////////////////////////////////////////////////////////////////////////*/
void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
    currentPalette = Fyrus_p;
    currentBlending = LINEARBLEND;
}

/*//////////////////////////////////////////////////////////////////////////////
// Main loop
//////////////////////////////////////////////////////////////////////////////*/
void loop() {
    ledTest(7500);
}


/*//////////////////////////////////////////////////////////////////////////////
// Helper routine to dump a byte array as hex values to Serial.
//////////////////////////////////////////////////////////////////////////////*/

void ledTest(int time){
  time = time/10;
  for(int i = 0; i < time; i++){
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);
    FastLED.show();
    FastLED.delay(10);
  }
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    
    for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}

const TProgmemPalette16 Fyrus_p PROGMEM =
{
    CRGB::Red,
    CRGB::Orange,
    CRGB::Yellow,
    CRGB::Green,

    CRGB::Red,
    CRGB::Blue,
    CRGB::Red,
    CRGB::Orange,

    CRGB::Yellow,
    CRGB::Red,
    CRGB::Red,
    CRGB::Orange,

    CRGB::Yellow,
    CRGB::Red,
    CRGB::Yellow,
    CRGB::Blue
};
