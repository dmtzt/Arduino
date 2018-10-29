//Include Adafruit_Neopixel header file to control LEDs
#include <Adafruit_NeoPixel.h>

//Design a variable for Serial.read
int state = 0;

//Define macros to identify each output pin
#define LEFTPIN 5
#define RIGHTPIN 6
#define MIDDLEPIN 9
#define BRAKEPIN 10
#define NIGHTPIN 11

//Define macros to identify each mode
#define OFF 0
#define LEFTTURN 1
#define RIGHTTURN 2
#define HAZARD 3
#define BRAKE 4
#define BRAKEOFF 5
#define NIGHT 6
#define NIGHTOFF 7

//Set each strip the number of sequential LEDs,
//the pin number to which is connected, 
//and the type of strip that is connected, according to the library
Adafruit_NeoPixel stripLeft = Adafruit_NeoPixel(10, LEFTPIN, NEO_RGB);
Adafruit_NeoPixel stripRight = Adafruit_NeoPixel(10, RIGHTPIN, NEO_RGB);
Adafruit_NeoPixel stripMiddle = Adafruit_NeoPixel(11, MIDDLEPIN, NEO_RGB);
Adafruit_NeoPixel stripBrake = Adafruit_NeoPixel(45, BRAKEPIN, NEO_RGB);
Adafruit_NeoPixel stripNight = Adafruit_NeoPixel(60, NIGHTPIN, NEO_RGB);

//Set colors to left turn strip
uint32_t offLeft = stripLeft.Color(0, 0, 0);
uint32_t whiteLeft = stripLeft.Color(255, 255, 255);
uint32_t yellowLeft = stripLeft.Color(255, 255, 0);
uint32_t redLeft = stripLeft.Color(255, 0, 0);

//Set colors to right turn strip
uint32_t offRight = stripRight.Color(0, 0, 0);
uint32_t whiteRight = stripRight.Color(255, 255, 255);
uint32_t yellowRight = stripRight.Color(255, 255, 0);
uint32_t redRight = stripRight.Color(255, 0, 0);

//Set colors to middle turn strip
uint32_t offMiddle = stripMiddle.Color(0, 0, 0);
uint32_t whiteMiddle = stripMiddle.Color(255, 255, 255);
uint32_t yellowMiddle = stripMiddle.Color(255, 255, 0);
uint32_t redMiddle = stripMiddle.Color(255, 0, 0);
  
//Set colors to brake strip
uint32_t offBrake = stripBrake.Color(0, 0, 0);
uint32_t whiteBrake = stripBrake.Color(255, 255, 255);
uint32_t yellowBrake = stripBrake.Color(255, 255, 0);
uint32_t redBrake = stripBrake.Color(0, 255, 0);

//Set colors to night mode strip
uint32_t offNight = stripNight.Color(0, 0, 0);
uint32_t whiteNight = stripNight.Color(255, 255, 255);
uint32_t yellowNight = stripNight.Color(255, 255, 0);
uint32_t redNight = stripNight.Color(255, 0, 0);  

//Function to turn LEDs on when setup runs
void setupOn() {
  for (int n = 0; n < 10; n++) {
    stripLeft.setPixelColor(n, whiteLeft);
    stripRight.setPixelColor(n, whiteRight);
  }
  for (int n = 0; n < 11; n++) {
    stripMiddle.setPixelColor(n, whiteMiddle);
  }
  for (int n = 0; n < 45; n++) {
    stripBrake.setPixelColor(n, whiteBrake);
  }
  for (int n = 0; n < 45; n++) {
    stripNight.setPixelColor(n, whiteNight);
  }
  stripLeft.show();
  stripRight.show();
  stripMiddle.show();
  stripBrake.show();
  stripNight.show();
}

//Function to turn LEDs off when setup is about to end
void setupOff() {
 for (int n = 0; n < 10; n++) {
    stripLeft.setPixelColor(n, offLeft);
    stripRight.setPixelColor(n, offRight);
  }
  for (int n = 0; n < 11; n++) {
    stripMiddle.setPixelColor(n, offMiddle);
  }
  for (int n = 0; n < 45; n++) {
    stripBrake.setPixelColor(n, offBrake);
  }
  for (int n = 0; n < 45; n++) {
    stripNight.setPixelColor(n, offNight);
  }
  stripLeft.show();
  stripRight.show();
  stripMiddle.show();
  stripBrake.show();
  stripNight.show();
}

void setup() {
  Serial.begin(9600);
  stripLeft.begin();
  stripRight.begin();
  stripMiddle.begin();
  stripBrake.begin();
  stripNight.begin();
  
  setupOn();
  delay(2000);
  setupOff();
}

void loop() {
  if(Serial.available() > 0){
    state = Serial.read();
  }
  if ('0' <= state && '9' >= state){
        state = state - '0';
  }
  
  if (state == OFF) {
    setupOff();
  }
  
  if (state == LEFTTURN) {
    for (int n = 0; n < 10; n++) {
      stripLeft.setPixelColor(n, yellowLeft);
    }
    for (int n = 0; n < 11; n++) {
      stripMiddle.setPixelColor(n, yellowMiddle);
    }
    stripLeft.show();
    stripMiddle.show();
    delay(706);
    
    for (int n = 0; n < 10; n++) {
      stripLeft.setPixelColor(n, offLeft);
    }
    for (int n = 0; n < 11; n++) {
      stripMiddle.setPixelColor(n, offMiddle);
    }
    stripLeft.show();
    stripMiddle.show();
    delay(706);
  }
  else if (state == RIGHTTURN) {
    for (int n = 0; n < 10; n++) {
      stripRight.setPixelColor(n, yellowRight);
    }
    for (int n = 0; n < 11; n++) {
      stripMiddle.setPixelColor(n, yellowMiddle);
    }
    stripRight.show();
    stripMiddle.show();
    delay(706);
    
    for (int n = 0; n < 10; n++) {
      stripRight.setPixelColor(n, offRight);
    }
    for (int n = 0; n < 11; n++) {
      stripMiddle.setPixelColor(n, offMiddle);
    }
    stripRight.show();
    stripMiddle.show();
    delay(706);
  }
  else if (state == HAZARD) {
    for (int n = 0; n < 10; n++) {
      stripLeft.setPixelColor(n, yellowLeft);
      stripRight.setPixelColor(n, yellowRight);
    }
    for (int n = 0; n < 11; n++) {
      stripMiddle.setPixelColor(n, yellowMiddle);
    }
    stripRight.show();
    stripLeft.show();
    stripMiddle.show();
    delay(706);
    
    for (int n = 0; n < 10; n++) {
      stripLeft.setPixelColor(n, offLeft);
      stripRight.setPixelColor(n, offRight);
    }
    for (int n = 0; n < 11; n++) {
      stripMiddle.setPixelColor(n, offMiddle);
    }
    stripRight.show();
    stripLeft.show();
    stripMiddle.show();
    delay(706);
  }
  else if (state == BRAKE) {
    for (int n = 0; n < 45; n++) {
    stripBrake.setPixelColor(n, redBrake);
    }
    stripBrake.show();
  }
  else if (state == BRAKEOFF) {
    for (int n = 0; n < 45; n++) {
    stripBrake.setPixelColor(n, offBrake);
    }
    stripBrake.show();
  }
  else if (state == NIGHT) {
    for (int n = 0; n < 45; n++) {
    stripNight.setPixelColor(n, whiteNight);
    }
    stripNight.show();
  }
  else if(state == NIGHTOFF) {
    for (int n = 0; n < 45; n++) {
    stripNight.setPixelColor(n, offNight);
    }
    stripNight.show();
  }
}


