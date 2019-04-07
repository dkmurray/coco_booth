#include "TMRpcm.h"
#include "SPI.h"

TMRpcm audio;
#define SD_ChipSelectPin 8

void setup() {
  audio.speakerPin = 9;
  Serial.begin(9600);           // start serial for output
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;
  }
}

void loop() {
  audio.setVolume(5);
  audio.play("ext.wav");
  delay(120000);
}
