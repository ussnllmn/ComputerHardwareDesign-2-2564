// Don't forget to change number in for loop.
void Pattern_CheckLED(){
    for (int i=1;i<4;i++) {
    for (int j=1;j<4;j++){
      SelectRow(i);
      SelectColumn(j); 
      delay(300);
    }
  }
  SelectRow(5);
  SelectColumn(5); 
}
void SelectColumn(int column){
  if (column==1) digitalWrite(C1,LOW); else digitalWrite(C1,HIGH);
  if (column==2) digitalWrite(C2,LOW); else digitalWrite(C2,HIGH);
  if (column==3) digitalWrite(C3,LOW); else digitalWrite(C3,HIGH);
}
