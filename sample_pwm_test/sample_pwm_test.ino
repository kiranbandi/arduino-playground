#include <SPI.h>
#include <Adafruit_DotStar.h>

// Define the number of LEDs that are available
#define NUMPIXELS 32


// Here's how to control the LEDs from any two pins:
#define DATAPIN    6
#define CLOCKPIN   7


// Create strip
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DOTSTAR_BRG);
Adafruit_DotStar strip_2 = Adafruit_DotStar(NUMPIXELS,DATAPIN ,CLOCKPIN,DOTSTAR_BRG);


void setup() {
  strip.begin(); // Initialize the strip
  strip.show();  // Turn off all LEDS within the Numpixels Rang
  strip_2.begin();
  strip_2.show();
}

void loop() {

  int head = 0;
  int tail = 32;
  int delayCount = 2;

  for (int i = head; i <= tail; i++) {
    strip.setPixelColor(i, 0xFFFFFF); // color format is GRB
    strip_2.setPixelColor(i, 0xFFFFFF);
  }
  strip.show();
  strip_2.show();
  delay(delayCount);

  for (int i = head; i <= tail; i++) {
    strip.setPixelColor(i, 0x000000); // color format is GRB
    strip_2.setPixelColor(i, 0x000000); 
  }

  strip.show();
  strip_2.show();
  delay(delayCount);

}
