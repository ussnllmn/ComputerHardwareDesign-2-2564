#include <Wire.h> 
#include <DS1302.h>
#include <LiquidCrystal_I2C.h>

Time t;
DS1302 rtc(2, 3, 4);
LiquidCrystal_I2C lcd(0x27,20,2);

int create_count = 0;
boolean show_original = false;

void setup()
{
  Serial.begin(9600);
    
  lcd.init();                      
  lcd.backlight();
  
  rtc.halt(false);
  rtc.writeProtect(false);
//  The following lines can be commented out to use the values already stored in the DS1302
//  rtc.setDOW(MONDAY); // Set Day-of-Week to FRIDAY
  rtc.setTime(19, 26, 30); // Set the time to 12:00:00 (24hr format)
  rtc.setDate(3, 6, 2019); // Set the date to August 6th, 2010

}
 
void loop()
{
  t = rtc.getTime();
  
  // Print Hour
  char temp_Hour[10]; 
  sprintf(temp_Hour, "%2d",t.hour);
  // Print in costom form
  print_Custom_digit(temp_Hour[0],1,4);
  print_Custom_digit(temp_Hour[1],1,5);
  print_Custom_digit(':',1,6);
  //////////////////////////////////////////////////////////
  
  // Print Min
  char temp_Min[10]; 
  sprintf(temp_Min, "%2d",t.min);
  // Print in costom form
  print_Custom_digit(temp_Min[0],1,7);
  print_Custom_digit(temp_Min[1],1,8);
  print_Custom_digit(':',1,9);
  //////////////////////////////////////////////////////////
  
  // Print Sec
  char temp_Sec[10]; 
  sprintf(temp_Sec, "%2d",t.sec);
  // Print in costom form
  print_Custom_digit(temp_Sec[0],1,10);
  print_Custom_digit(temp_Sec[1],1,11);
  //////////////////////////////////////////////////////////
  
  // Print in normal form
  if (show_original == true){
    // Print Hour 
    print_Original_digit(temp_Hour[0],0,4);
    print_Original_digit(temp_Hour[1],0,5);
    print_Original_digit(':',0,6);
    // Print Min 
    print_Original_digit(temp_Min[0],0,7);
    print_Original_digit(temp_Min[1],0,8);
    print_Original_digit(':',0,9);
    // Print Sec
    print_Original_digit(temp_Sec[0],0,10);
    print_Original_digit(temp_Sec[1],0,11);
  }
  else{
    lcd.setCursor(0,0);
    lcd.print("---Thai clock---");
  }
  
  create_count = 0;
}
