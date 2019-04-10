#include <MD_YX5300.h>

// Connections for serial interface to the YX5300 module
#define ARDUINO_RX 5  // connect to TX of MP3 Player module
#define ARDUINO_TX 6  // connect to RX of MP3 Player module

// Define global variables
MD_YX5300 mp3(ARDUINO_RX, ARDUINO_TX);
bool bUseSynch = true;   // use synchronous? 
uint8_t fldr1 = 01;
uint8_t fldr2 = 02;
uint8_t file1 = 001;
uint8_t file2 = 002;


#define relay4 11
#define relay3 10
#define relay2 9
#define relay1 8


void setup() {
  // Set up relays
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  
  pinMode(13, INPUT_PULLUP); // Set up switch pin 13
  Serial.begin(57600);
  mp3.begin();
  mp3.setSynchronous(bUseSynch);
  mp3.volume(20);
  mp3.playFolderRepeat(fldr1);
}

void loop() {
  if(digitalRead(13) == LOW) { // Switch is pressed
    mp3.volume(30);
    mp3.playSpecific(fldr2, file2);
    delay(2200);
    digitalWrite(relay1, LOW);
    delay(1800);
    digitalWrite(relay2, LOW);
    delay(1700);    
    digitalWrite(relay3, LOW);
    delay(2200);    
    digitalWrite(relay4, LOW);
    delay(9100);
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);
    mp3.volume(20);
    mp3.playFolderRepeat(fldr1);
  }
}

void on_off(int relay){
  digitalWrite(relay, LOW);
  delay(200);
  digitalWrite(relay, HIGH);
}
