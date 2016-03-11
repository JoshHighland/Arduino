/*
* These numbers are where the LED is, not the pins on the board.
* 
* We use a 74LS377 Octal D-Type Flip-Flop to set the row output on 
* one of the 7 flip-flop outputs, requiring only two wires (data1 + clock).
* http://www.datasheetcatalog.com/datasheets_pdf/S/N/7/4/SN74LS377N.shtml
* 
*  1 row = +5 in 2
*  2 row = +5 in 7
*  3 row = +5 in 1
*  4 row = +5 in 43 or 5
*  5 row = +5 in 47
*  6 row = +5 in 41
*  7 row = +5 in 46
*  
*  
* NOTE: For the column output, we could use a "3 to 8 decoder" that gives HIGH for all pins expect (ABC).
* http://www.datasheetcatalog.com/datasheets_pdf/7/4/L/S/74LS138.shtml
* Pins from Arduino connect to A,B,C.  Enable pins set to enable (G1=+5, G2A=GND, G2B=GND).
* Output pins (Y1-Y5) goes to 1-5 column pins on LED.
* 
* For now, we just use 5 pins direct between Arduino and LED.
* 
*  1 col = 0 in 42
*  2 col = 0 in 3
*  3 col = 0 in 44 or 4
*  4 col = 0 in 45
*  5 col = 0 in 6
*  
*/

int pinClock = 2;
int pinD = 5;
int pinCol[] = {8,9,10,11,12};

void setup() {
  pinMode(pinD, OUTPUT); digitalWrite(pinD, LOW);
  pinMode(pinClock, OUTPUT); digitalWrite(pinClock, LOW);
  for (int i=0;i<5;i++) {
    pinMode(pinCol[i], OUTPUT); digitalWrite(pinCol[i], HIGH); // HIGH is LED off
  }
}

void clock() {
  digitalWrite(pinClock, HIGH); 
  delayMicroseconds(5);
  digitalWrite(pinClock, LOW);
  delayMicroseconds(5);
}

void row(int row) {
  digitalWrite(pinD, LOW);
  for (int i=0;i<8;i++) {
    clock();  // Now Q1 to Q8 are all LOW.
  }

  digitalWrite(pinD, HIGH);
  clock(); // Shift data over (Q1 is HIGH now, rest are low)
  
  digitalWrite(pinD, LOW);
  for (int r=1;r<row;r++) {
    clock(); // Shift data over to correct row.
  }
}

void off() {
  for (int i=0;i<5;i++) { // Turn off all of the columns
    digitalWrite(pinCol[i], HIGH); // HIGH is LED off
  }  
}

void col(int col) {
  off();
  
  col--; // We think of columns as starting at 1, but array index starts at 0.
  if ((col>=0) && (col<5)) {    
    digitalWrite(pinCol[col], LOW); // LOW is LED on, so turn on the column.
  }
}

int r=1;
int c=1;

void advanceLed() {
  r++;
  if (r==8) {
    r=1;
    c++;
    if (c==6) {
      c=1;
    }
  }
}

void loop() {
  row(r);
  col(c);
  delay(1);
  advanceLed();
}
