#include <Adafruit_DotStar.h>
#include <SPI.h>        

#define NUMPIXELS 35 // Number of LEDs in strip

// Here's how to control the LEDs from any two pins:
#define DATAPIN    6
#define CLOCKPIN   7

// (Arduino Uno = pin 11 for data, 13 for clock, other boards are different).
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DOTSTAR_BRG);
Adafruit_DotStar strip_2 = Adafruit_DotStar(NUMPIXELS,DATAPIN ,CLOCKPIN,DOTSTAR_BRG);


void setup() {
  strip.begin(); // Initialize pins for output
  strip_2.begin();
  strip.show();  // Turn all LEDs off ASAP
  strip_2.show();
}

int      head  = 0, tail = -2; // Index of first 'on' and 'off' pixels
uint32_t color = 0xFF0000;      // 'On' color (starts red)

void loop() {

  strip.setPixelColor(head, color); // 'On' pixel at head
  strip.setPixelColor(tail, 0);     // 'Off' pixel at tail
  strip.show();                     // Refresh strip

  strip_2.setPixelColor(head, color); // 'On' pixel at head
  strip_2.setPixelColor(tail, 0);     // 'Off' pixel at tail
  strip_2.show();                     // Refresh strip
  
  delay(20);                        // Pause 20 milliseconds (~50 FPS)

  if (++head >= NUMPIXELS) {        // Increment head index.  Off end of strip?
    head = 0;                       //  Yes, reset head index to start
    if ((color >>= 8) == 0)         //  Next color (R->G->B) ... past blue now?
      color = 0xFF0000;             //   Yes, reset to red
  }
  if (++tail >= NUMPIXELS) tail = 0; // Increment, reset tail index
}
