/*********************

Read a message from the Serial port and display it on the LCD

**********************/

// include the library code:
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>

// The shield uses the I2C SCL and SDA pins. On classic Arduinos
// this is Analog 4 and 5 so you can't use those for analogRead() anymore
// However, you can connect other I2C sensors to the I2C bus and share
// the I2C bus.
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// These #defines make it easy to set the backlight color
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

void setup() {
  // Debugging output
  Serial.begin(9600);
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);

  // Print a message to the LCD. We track how long it takes since
  // this library has been optimized a bit and we're proud of it :)
  lcd.print("a la Mode!");
  //Serial.print("Took "); Serial.print(time); Serial.println(" ms");
  lcd.setBacklight(TEAL);
}

uint8_t i=0;
char cmd_buffer[100];
void loop() {
   
  if (sReadline() > 0){
    if (cmd_buffer[0] == '1'){
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
    }else{
      lcd.setCursor(0,0);
      lcd.print("                ");
      lcd.setCursor(0,0);
    }
    lcd.print(cmd_buffer+1);
    
  }
  uint8_t buttons = lcd.readButtons();

  if (buttons) {
    if (buttons & BUTTON_UP) {
      Serial.print("U");
    }
    if (buttons & BUTTON_DOWN) {
      Serial.print("D");
    }
    if (buttons & BUTTON_LEFT) {
      Serial.print("L");
    }
    if (buttons & BUTTON_RIGHT) {
      Serial.print("R");
    }
    if (buttons & BUTTON_SELECT) {
      Serial.print("S");
    }
    delay(500);
  }
}

// Read a line terminated by newline into cmd_buffer. Return length
// If there's nothing waiting return zero
int sReadline(){
  int x=0;
  if (Serial.available()){
    delay(100);
    while(Serial.available() && (x < 99)){
      cmd_buffer[x] = Serial.read();
      if (cmd_buffer[x] == '\n')
        break;
      x++;
    }
    cmd_buffer[x] =(char)0;
    return (x-1);
  }
  else
    return 0;
}
