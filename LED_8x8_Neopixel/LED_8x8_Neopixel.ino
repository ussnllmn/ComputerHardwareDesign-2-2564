#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h>
#endif
#ifndef PSTR
 #define PSTR
#endif

#define LED_PIN    6
#define LED_COUNT 64
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, LED_PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);
  
const int Pattern_1_Pin = 2;     
const int Pattern_2_Pin = 3;     
const int Pattern_3_Pin = 4;     

int Pattern_1_State, Pattern_2_State, Pattern_3_State, Switch;   
int Pattern_1, Pattern_2, Pattern_3;   

int x    = matrix.width();

void setup() {
  strip.begin();           
  strip.show();
  strip.setBrightness(255);
  
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(10);
  matrix.setTextColor(matrix.Color(0, 255, 0));
  
  Serial.begin(9600);
  pinMode(Pattern_1_Pin, INPUT);
  pinMode(Pattern_2_Pin, INPUT);
  pinMode(Pattern_3_Pin, INPUT);
}

void loop() {
  Pattern_1_State = digitalRead(Pattern_1_Pin);
  Pattern_2_State = digitalRead(Pattern_2_Pin);
  Pattern_3_State = digitalRead(Pattern_3_Pin);

  if (Pattern_1_State == HIGH && Pattern_1 == LOW) {
    Switch =! Switch;
    if(Switch == 1)
      Pattern_on_off(strip.Color(20, 0, 0));
    else
      Pattern_on_off(strip.Color(0, 0, 0));
  }
  
  if (Pattern_2_State == HIGH && Pattern_2 == LOW) {
    for(int i=0; i<3; i++) { 
      Pattern_fade(); 
      delay(1000);        
    }
  }
  
  if (Pattern_3_State == HIGH && Pattern_3 == LOW) {
    for(int i=0; i<130; i++) { 
      Pattern_text();
      delay(100);     
    }
  }

  Pattern_1 = Pattern_1_State;
  Pattern_2 = Pattern_2_State;
  Pattern_3 = Pattern_3_State;
}
void Pattern_text(){
  matrix.fillScreen(0);
  matrix.setCursor(x, 1);
  matrix.print(F("KMITL"));
  if(--x < -36)
    x = matrix.width();
  matrix.show();
}

void Pattern_fade(){
  // fade in from min to max in increments of 1 points:
  for (float fadeValue = 0 ; fadeValue <= 20; fadeValue += 1) {
    Pattern_on_off(strip.Color(0, 0, fadeValue));
//    Serial.println(fadeValue);
    delay(50);
  }

  // fade out from max to min in decrement of 1 points:
  for (float fadeValue = 20 ; fadeValue >= 0; fadeValue -= 1) {
    Pattern_on_off(strip.Color(0, 0, fadeValue));
//    Serial.println(fadeValue);
    delay(50);
  }
}

void Pattern_on_off(uint32_t color) {
  for(int i=0; i<strip.numPixels(); i++) { 
    strip.setPixelColor(i, color);         
    strip.show();                        
  }
}
