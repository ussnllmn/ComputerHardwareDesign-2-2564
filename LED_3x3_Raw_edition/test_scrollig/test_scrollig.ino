// Raws 
#define R1 3
#define R2 5
#define R3 6

//Columns
#define C1 9
#define C2 10
#define C3 11

int Cat [3] [9] ={
  {0,1,1,1,0,1,1,1,0},
  {1,0,1,0,1,0,1,0,1},
  {1,1,0,1,1,1,0,1,1},
  };
  
int position=0;
  
void setup() {
   pinMode(R1, OUTPUT);
   pinMode(R2, OUTPUT);
   pinMode(R3, OUTPUT);
   
   pinMode(C1, OUTPUT);
   pinMode(C2, OUTPUT);
   pinMode(C3, OUTPUT);
}


void SelectRow(int row){
  if (row==1) digitalWrite(R1,HIGH); else digitalWrite(R1,LOW);
  if (row==2) digitalWrite(R2,HIGH); else digitalWrite(R2,LOW);
  if (row==3) digitalWrite(R3,HIGH); else digitalWrite(R3,LOW);
}

void Set_LED_in_Active_Row(int column, int state){
  if (column==1) digitalWrite(C1,state);   
  if (column==2) digitalWrite(C2,state); 
  if (column==3) digitalWrite(C3,state); 
}

void loop() {

  for (int x=0; x<3;x++){
    for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){
        Set_LED_in_Active_Row(i+1,Cat[j][(i+position)-abs((i+position)/9)*9]);
      }
      delay(2);
    }
  }
  position=position+1;
}
