#include <Wire.h>

const byte LCD = 40;

//void lcd_clear(void){
//  tx_packet[0] = 0xFE;
//  tx_packet[1] = 0x51;
//  Wire.write(tx_packet, 2);
//  delay(15);
//}

void setup()
{
  delay(200);
  Wire.begin(); // join i2c bus
  delay(200);
}

void loop()
{ 
  Wire.beginTransmission(LCD); // transmit to device #44 (0x2c), ours is set to 40 (0x28)

  byte tx_packet[2];
  
  //Display I2C
  tx_packet[0] = 0xFE;
  tx_packet[1] = 0x72;
  Wire.write(tx_packet, 2);
  delay(3);
  Wire.endTransmission(-1);
  
  Wire.beginTransmission(LCD);
  Wire.write("Hello World!");
  delay(10);
  Wire.endTransmission(-1);

  delay(2000);
}
