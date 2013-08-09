#include <Wire.h>  //I2C library

const byte LCDa = 40; //LCD address on I2C bus

const byte LCD_CLEAR[2] = {0xFE, 0x51};
const byte LCD_CLEAR_COUNT = 2;

const byte LCD_SET_CURSOR[2] = {0xFE, 0x45};
const byte LCD_SET_CURSOR_COUNT = 2;

//const byte LCD_UNDERLINE_CURSOR_ON[2] = {0xFE, 0x47};
//const byte LCD_UNDERLINE_CURSOR_ON_COUNT = 2;

//const byte LCD_UNDERLINE_CURSOR_OFF[2] = {0xFE, 0x48};
//const byte LCD_UNDERLINE_CURSOR_OFF_COUNT = 2;

void setup()
{
    delay(200);
    Wire.begin(); // join i2c bus (address optional for master)
    
    Wire.beginTransmission(LCDa);
    Wire.write(LCD_CLEAR, LCD_CLEAR_COUNT);  //Clear screen every time the program begins
    Wire.endTransmission();
    delayMicroseconds(1500);
    
    //Set cursor to 1st line
    Wire.beginTransmission(LCDa);
    Wire.write(LCD_SET_CURSOR, LCD_SET_CURSOR_COUNT);
    Wire.write(0x00);
    Wire.endTransmission();
    delayMicroseconds(100);
  
    //Create first char string
    Wire.beginTransmission(LCDa);
    for (byte i=47; i<66; i++) { Wire.write(i); }
    Wire.endTransmission();


    //Set cursor to 2nd line
    Wire.beginTransmission(LCDa);
    Wire.write(LCD_SET_CURSOR, LCD_SET_CURSOR_COUNT);
    Wire.write(0x40);
    Wire.endTransmission();
    delayMicroseconds(100);
     

    Wire.beginTransmission(LCDa);
    for (byte i=48; i<67; i++) { Wire.write(i); }
    Wire.endTransmission();
    
    
    //Set cursor to 3rd line
    Wire.beginTransmission(LCDa);
    Wire.write(LCD_SET_CURSOR, LCD_SET_CURSOR_COUNT);
    Wire.write(0x14);
    Wire.endTransmission();
    delayMicroseconds(100);
    
    //Write 3rd char string on 3rd line
    Wire.beginTransmission(LCDa);
    for (byte i=47; i<66; i++) { Wire.write(i); }
    Wire.endTransmission();

}

void loop()
{  
}
