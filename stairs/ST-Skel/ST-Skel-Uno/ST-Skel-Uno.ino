#include <MD_YX5300.h>

// Connections for serial interface to the YX5300 module
#define ARDUINO_RX 5  // connect to TX of MP3 Player module
#define ARDUINO_TX 6  // connect to RX of MP3 Player module

// Define global variables
MD_YX5300 mp3(ARDUINO_RX, ARDUINO_TX);
bool bUseSynch = true;   // use synchronous? 
uint8_t file = 001;

void setup() {
  pinMode(13, INPUT); // Set up PIR Sensor pin 13
  Serial.begin(57600);
  mp3.begin();

  mp3.setSynchronous(bUseSynch);
  //mp3.playTrackRepeat(file);
}

void loop() {
  if(digitalRead(13) == HIGH) { // Sensor is triggered
    mp3.playTrack(file);
    delay(3500);
  }
}
