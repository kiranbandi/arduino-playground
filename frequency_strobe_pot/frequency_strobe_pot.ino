#include <SPI.h>
#include <Adafruit_DotStar.h>

//sets constants
const int analogInPin = A1;  // Analog input pin that the potentiometer is attached to
// Define the number of LEDs that are available
#define NUMPIXELS 50

// Variables etc...
float sensorValue = 1;       // value read from the pot
float hold = 1;              // hold time between iterations (sort of)
float holdFrequency = 1;
unsigned long microsPrev = 0;       // set up value for timing       
unsigned long microsCurrent = 0;    // used for timing purposes
unsigned long millisSerial =0;      //used for serial output timing
float frequency = 1;         // stores frequency
float rpm = 0;              // rpm

// Create strip
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DOTSTAR_BRG);

void setup() {

  // lower speeds can delay execution
  strip.begin(); // Initialize the strip
  strip.show();  // Turn off all LEDS within the Numpixels Range

  //initialize pins as outputs
  pinMode(analogInPin,INPUT);

//  Digital Pins turning off 
  pinMode(A0, OUTPUT);
  pinMode(A2, OUTPUT);
  digitalWrite(A0,LOW);
  digitalWrite(A2,HIGH);

}

void loop() {
      
  // this while is a workaround for timer limitations using micros vs millis
  sensorValue = analogRead(analogInPin);   //take potentiometer reading
  hold = sensorValue*55 + 100;             //add some time to scale and for code execution
  microsCurrent = micros();                // collect current time
  if (microsCurrent > microsPrev + hold){  //set up timing loop
    frequency = 1000000/(microsCurrent - microsPrev);    
    microsPrev = microsPrev + hold;            //set up millis for delay stuff

    //set all 6 LEDs high (they were already plugged in)

     for (int i = 15; i < 35; i++) {
        strip.setPixelColor(i, 0xFFFFFF); // color format is GRB
      }
      strip.show();

    delayMicroseconds(.02*hold);  //leave LEDs on long enough  to see
    //set all LEDs low
    
     for (int j = 15; j < 35; j++) {
        strip.setPixelColor(j, 0x000000); // color format is GRB
       }
     strip.show();
//
//    if(millis() > millisSerial + 200){ 
//        millisSerial=millis();    //reset timer
//        holdFrequency = 1000000/hold;    
//        // do some math to find values
//        rpm = frequency * 60;
////         print the results to the serial monitor:
//        Serial.print("sensor  " ); //print sensor data for debug
//        Serial.print(sensorValue);
//        Serial.print("holdFreq = " );                       
//        Serial.print(holdFrequency);
//        Serial.print("  freq = " );                       
//        Serial.print(frequency);      
//        Serial.print("  rpm = ");      
//        Serial.println(rpm);
//    }
  }
}
