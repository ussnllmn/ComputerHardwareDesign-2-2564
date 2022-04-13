byte zero[] = {
  B00000,
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B10001,
  B01110
};

byte one[] = {
  B00000,
  B00000,
  B01110,
  B10001,
  B10101,
  B11001,
  B00010,
  B01100
};

byte two[] = {
  B10000,
  B10000,
  B10101,
  B10111,
  B10101,
  B10001,
  B10001,
  B01110
};

byte three[] = {
  B00000,
  B00000,
  B10001,
  B11011,
  B10101,
  B10001,
  B11001,
  B11001
};

byte four[] = {
  B00001,
  B00010,
  B01100,
  B10000,
  B10110,
  B10100,
  B10010,
  B01111
};

byte five[] = {
  B00001,
  B01110,
  B01100,
  B10000,
  B10110,
  B10100,
  B10010,
  B01111
};

byte six[] = {
  B10000,
  B01000,
  B00110,
  B00001,
  B01101,
  B11101,
  B10001,
  B01110
};

byte seven[] = {
  B00001,
  B00001,
  B10001,
  B11011,
  B10101,
  B10001,
  B11001,
  B11001
};

byte eight[] = {
  B00001,
  B00001,
  B00110,
  B01000,
  B10011,
  B10001,
  B10101,
  B11011
};

byte nine[] = {
  B00001,
  B00010,
  B00110,
  B01000,
  B10100,
  B10010,
  B10101,
  B01100
};

void print_Custom_digit(char digit, int RowCursor, int ColCursor){
  lcd.setCursor(ColCursor, RowCursor);
  if (digit == '0'){
    lcd.createChar(create_count, zero);
    lcd.setCursor(ColCursor, RowCursor);
    lcd.write((byte)create_count);
    create_count++;
  }
  else if(digit == '1'){
    lcd.createChar(create_count, one);
    lcd.setCursor(ColCursor, RowCursor);
    lcd.write((byte)create_count);
    create_count++;
  }
  else if(digit == '2'){
    lcd.createChar(create_count, two);
    lcd.setCursor(ColCursor, RowCursor);
    lcd.write((byte)create_count);
    create_count++;
  }
  else if(digit == '3'){
    lcd.createChar(create_count, three);
    lcd.setCursor(ColCursor, RowCursor);
    lcd.write((byte)create_count);
    create_count++;
  }
  else if(digit == '4'){
    lcd.createChar(create_count, four);
    lcd.setCursor(ColCursor, RowCursor);
    lcd.write((byte)create_count);
    create_count++;
  }
  else if(digit == '5'){
    lcd.createChar(create_count, five);
    lcd.setCursor(ColCursor, RowCursor);
    lcd.write((byte)create_count);
    create_count++;
  }
  else if(digit == '6'){
    lcd.createChar(create_count, six);
    lcd.setCursor(ColCursor, RowCursor);
    lcd.write((byte)create_count);
    create_count++;
  }
  else if(digit == '7'){
    lcd.createChar(create_count, seven);
    lcd.setCursor(ColCursor, RowCursor);
    lcd.write((byte)create_count);
    create_count++;
  }
  else if(digit == '8'){
    lcd.createChar(create_count, eight);
    lcd.setCursor(ColCursor, RowCursor);
    lcd.write((byte)create_count);
    create_count++;
  }
  else if(digit == '9'){
    lcd.createChar(create_count, nine);
    lcd.setCursor(ColCursor, RowCursor);
    lcd.write((byte)create_count);
    create_count++;
  }
  else if(digit == ':'){
    lcd.print(":");
  }
  else{
    lcd.createChar(create_count, zero);
    lcd.setCursor(ColCursor, RowCursor);
    lcd.write((byte)create_count);
    create_count++;
  }
}

void print_Original_digit(char digit, int RowCursor, int ColCursor){
  lcd.setCursor(ColCursor, RowCursor);
  if (digit == '0')
    lcd.print("0");
  else if(digit == '1')
    lcd.print("1");
  else if(digit == '2')
    lcd.print("2");
  else if(digit == '3')
    lcd.print("3");
  else if(digit == '4')
    lcd.print("4");
  else if(digit == '5')
    lcd.print("5");
  else if(digit == '6')
    lcd.print("6");
  else if(digit == '7')
    lcd.print("7");
  else if(digit == '8')
    lcd.print("8");
  else if(digit == '9')
    lcd.print("9");
  else if(digit == ':')
    lcd.print(":");
  else
    lcd.print("0");
}
