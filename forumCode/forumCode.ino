
#include <Wire.h> //I2C library
const byte LCDa = 40; //LCD address on I2C bus
int ret = 0;
int reti = 0;

void setup()
  {
    delay(200);
    Wire.begin(); // join i2c bus (address optional for master)
  
    Serial.begin(9600);
  
//    delay(100);
    byte lcdClear[2];
    lcdClear[0] = 0xFE;
    lcdClear[1] = 0x51;
    Wire.beginTransmission(LCDa);
//    delay(20);
    Wire.write(lcdClear, 2);
//    delay(20);
    ret = Wire.endTransmission();
    reti++;
        
    Serial.println(reti);
    Serial.println(ret);
    
    delay(500);
    
   //Set cursor to first line
    Wire.beginTransmission(LCDa);
    byte cmd[3];
    cmd[0] = 0xFE;
    cmd[1] = 0x45;
    cmd[2] = 0x00;    
    Wire.write(cmd, 3);
//    delay(20);
    ret = Wire.endTransmission();
    reti++;
        
    Serial.println(reti);
    Serial.println(ret);
    delayMicroseconds(10000);
  
    //Create first char string
    
    for (byte i=47; i<66; i++)                // send 80 consecutive displayable characters to the LCD
      {
        Wire.beginTransmission(LCDa);
        Wire.write(i);
        ret = Wire.endTransmission();
        reti++;
        
        Serial.println(reti);
        Serial.println(ret);
        delayMicroseconds(10000);

//        delay(100);                            // this delay allows you to observe the addressing sequence
      }
      
    cmd[2] = 0x40;
    Wire.beginTransmission(LCDa);
    Wire.write(cmd, 3);
//    delay(20); 
    ret = Wire.endTransmission();
    reti++;
        
    Serial.println(reti);
    Serial.println(ret);    
    
    delayMicroseconds(10000);
      
    for (byte i=48; i<67; i++)                // send 80 consecutive displayable characters to the LCD
      {
        Wire.beginTransmission(LCDa);
        Wire.write(i);
        ret = Wire.endTransmission();
        reti++;
            
        Serial.println(reti);
        Serial.println(ret); 
 
        delayMicroseconds(10000);
//        delay(100);                            // this delay allows you to observe the addressing sequence
      }  
    
      
    cmd[2] = 0x14;
    Wire.beginTransmission(LCDa);
    Wire.write(cmd, 3);
//    delay(20); 
    ret = Wire.endTransmission();
    reti++;
        
    Serial.println(reti);
    Serial.println(ret);

    delayMicroseconds(10000);
    
    for (byte i=47; i<66; i++)                // send 80 consecutive displayable characters to the LCD
      {
        Wire.beginTransmission(LCDa);
        Wire.write(i);
        ret = Wire.endTransmission();
        reti++;
            
        Serial.println(reti);
        Serial.println(ret); 
 
        delayMicroseconds(10000);
      }


//  Serial.println(TWI_FREQ);

//  byte arr[40];
//  char ch = 'a';
//  int i = 0;
//  for(i; i < 39; i++){
//    arr[i] = ch;
//    ch++;
//  }
//  arr[39] = 0;
//  Wire.beginTransmission(LCDa);
//  Wire.write(arr, 39);
//  delay(1000);
//  Wire.endTransmission();
  }

void loop()
  {  
  }
