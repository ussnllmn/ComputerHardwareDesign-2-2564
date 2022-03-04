const int buttonPin_1 = A0; 
const int buttonPin_2 = A1; 
const int buttonPin_3 = A2; 
int buttonState_1,buttonState_2,buttonState_3 = 0;

// Test Value
int t = 1;

// Raws 
#define R1 3
#define R2 5
#define R3 6

//Columns
#define C1 9
#define C2 10
#define C3 11

int Cat [3] [3] ={
  {0,1,1},
  {1,0,1},
  {0,1,0},
  };
  

void setup() {
   Serial.begin(9600);
   
   pinMode(buttonPin_1, INPUT);
   pinMode(buttonPin_2, INPUT);
   pinMode(buttonPin_3, INPUT);
   
   pinMode(R1, OUTPUT);
   pinMode(R2, OUTPUT);
   pinMode(R3, OUTPUT);
   
   pinMode(C1, OUTPUT);
   pinMode(C2, OUTPUT);
   pinMode(C3, OUTPUT);
  
}

void Set_LED_in_Active_Row(int column, int state){
  if (column==1) digitalWrite(C1,state);   
  if (column==2) digitalWrite(C2,state); 
  if (column==3) digitalWrite(C3,state); 
}

void loop() {  
  buttonState_1 = digitalRead(buttonPin_1);
  buttonState_2 = digitalRead(buttonPin_2);
  buttonState_3 = digitalRead(buttonPin_3);

  if (buttonState_1 == HIGH) {
    Pattern_Default();  
  } 
  if (buttonState_2 == HIGH) {
    Pattern_CheckLED();
  } 
  if (buttonState_3 == HIGH) {
    Pattern_Scrolling();
  } 
//if(t==1)
//  Default_Pattern();  
//t=0;
}
