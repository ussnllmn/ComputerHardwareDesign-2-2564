#include "SoftPWM.h"

void setup()
{
  // Initialize
  SoftPWMBegin();

  // Create and set pin 2-9 to 0 (off)
  SoftPWMSet(2, 0);
  SoftPWMSet(3, 0);
  SoftPWMSet(4, 0);
  SoftPWMSet(5, 0);
  SoftPWMSet(6, 0);
  SoftPWMSet(7, 0);
  SoftPWMSet(8, 0);
  SoftPWMSet(9, 0);
  
  // Set fade time for all pin to 100 ms fade-up time, and 100 ms fade-down time
  SoftPWMSetFadeTime(ALL, 100, 100);

}

void loop()
{

  // fade in from min to max in increments of 2 points:
  for (int fadeValue = 0 ; fadeValue <= 200; fadeValue += 2) {
    // sets the value (range from 0 to 255):
    SoftPWMSet(2, fadeValue);
    SoftPWMSet(4, fadeValue);
    SoftPWMSet(6, fadeValue);
    SoftPWMSet(8, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 2 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    SoftPWMSet(2, fadeValue);
    SoftPWMSet(4, fadeValue);
    SoftPWMSet(6, fadeValue);
    SoftPWMSet(8, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // delay 2 second
  delay(2000);

  // fade in from min to max in increments of 2 points:
  for (int fadeValue = 0 ; fadeValue <= 200; fadeValue += 2) {
    // sets the value (range from 0 to 255):
    SoftPWMSet(3, fadeValue);
    SoftPWMSet(5, fadeValue);
    SoftPWMSet(7, fadeValue);
    SoftPWMSet(9, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 2 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    SoftPWMSet(3, fadeValue);
    SoftPWMSet(5, fadeValue);
    SoftPWMSet(7, fadeValue);
    SoftPWMSet(9, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // delay 2 second
  delay(2000);
}