/*
Program to test the LiquidCrystal library on a 4*20 LCD display

*/

#include <LiquidCrystal.h>
#include <wire.h>

//constants for the number of rows and columns in the LCD
const int numRows = 4;
const int numCols = 20;

//intialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(numCols, numRows);
  lcd.print("hello world!"); //print a message to the lcd 
}

void loop() {
  //set the cursor to column 0, line 1 
  //(note: line 1 is the second row, since counting begins at 0):
  lcd.setCursor(0,1);
  //print the number of second since reset: 
  lcd.print(millis()/1000);
}
