int blink_period = 250;
int blink_time = 2;

int fade_Max = 255;
int fade_Value = 2;

int num_led = 3;

int ON_ALL [3] [3] ={
  {0,0,0},
  {0,0,0},
  {0,0,0},
  };
  
int OFF_ALL [3] [3] ={
  {1,1,1},
  {1,1,1},
  {1,1,1},
  };
  
void Pattern_Default(){  
  // PATTERN_1 = BLINK
  for (int j=0;j<blink_time;j++){
    ON_LED();
    OFF_LED();
  }
  
  // PATTERN_2 = FADING
  for (int j=0;j<blink_time;j++){
    // FADE IN
    for (int fadeValue = 0 ; fadeValue <= fade_Max; fadeValue += fade_Value) {
      for (int j=0;j<num_led;j++){
        SelectRow_Fade(j+1, fadeValue);
        for (int i=0;i<num_led;i++){
          Set_LED_in_Active_Row(i+1 ,ON_ALL[j][i]);
        }
        delay(2);
      }
    }
    ON_LED();
    // FADE OUT
    for (int fadeValue = fade_Max ; fadeValue >= 0; fadeValue -= fade_Value) {
      for (int j=0;j<num_led;j++){
        SelectRow_Fade(j+1, fadeValue);
        for (int i=0;i<num_led;i++){
          Set_LED_in_Active_Row(i+1 ,ON_ALL[j][i]);
        }
        delay(2);
      }
    }
    OFF_LED();
  }
}

void ON_LED(){
    // ON ALL LED
    for (int j=0;j<blink_period;j++){
      for (int j=0;j<num_led;j++){
      SelectRow(j+1);
        for (int i=0;i<num_led;i++){
          Set_LED_in_Active_Row(i+1 ,ON_ALL[j][i]);
        }
        delay(2);
      }
    }
}

void OFF_LED(){
    // OFF ALL LED
    for (int j=0;j<blink_period;j++){
      for (int j=0;j<num_led;j++){
      SelectRow(j+1);
        for (int i=0;i<num_led;i++){
          Set_LED_in_Active_Row(i+1 ,OFF_ALL[j][i]);
        }
        delay(2);
      }
    }
}
void SelectRow(int row){
  if (row==1) digitalWrite(R1,HIGH); else digitalWrite(R1,LOW);
  if (row==2) digitalWrite(R2,HIGH); else digitalWrite(R2,LOW);
  if (row==3) digitalWrite(R3,HIGH); else digitalWrite(R3,LOW);
}

void SelectRow_Fade(int row, int fade){
  if (row==1) analogWrite(R1,fade); else digitalWrite(R1,LOW);
  if (row==2) analogWrite(R2,fade); else digitalWrite(R2,LOW);
  if (row==3) analogWrite(R3,fade); else digitalWrite(R3,LOW);
}
