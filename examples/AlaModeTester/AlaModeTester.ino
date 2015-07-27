#include <stdint.h>
#include <TouchScreen.h> 
#include <TFT.h>
#include <Wire.h>

#define YP A2   // must be an analog pin, use "An" notation!
#define XM A1   // must be an analog pin, use "An" notation!
#define YM 14   // can be a digital pin, this is A0
#define XP 17   // can be a digital pin, this is A3 
const int BAUD = 9600;

int count = 0;

void led(bool val){
  uint8_t out[1];
  uint8_t led_addr = 2;
  if(val){
    out[0] = 1;
  }
  else{
    out[0] = 0;
  }
  I2C_raw_write(42, led_addr, 1, out);
}
void setup(){
  Wire.begin();
  Serial.begin(BAUD);
  Serial.println("WyoLum 'A la Mode Tester");
  Serial.println("Version 1.0");
  Serial1.begin(BAUD);
  Tft.init();  //init TFT library
}
void loop(){
  if(checkRTC()){
    Serial.println("RTC OK");
    Tft.drawString("RTC :(",0,120,2,BLACK);
    Tft.drawString("RTC :)",0,120,2,GREEN);
  }
  else{
    Serial.println("RTC BAD");
    Tft.drawString("RTC :)",0,120,2, BLACK);
    Tft.drawString("RTC :(",0,120,2, RED);
  }
  
  // Tft.fillRectangle(0, 190, MAX_X, 35, BLACK);

  if(checkSerial1()){
    Serial.println("SERIAL OK");
    Tft.drawString("Ser :(",0,200,2,BLACK);
    Tft.drawString("Ser :)",0,200,2,GREEN);
  }
  else{
    Serial.println("SERIAL BAD");
    Tft.drawString("Ser :)",0,200,2, BLACK);
    Tft.drawString("Ser :(",0,200,2, RED);
  }
  
  if(checkSD()){
    Serial.println("SD OK");
    Tft.drawString(" SD :(",0,160,2,BLACK);
    Tft.drawString(" SD :)",0,160,2,GREEN);
  }
  else{
    Serial.println("SD BAD");
    Tft.drawString(" SD :)",0,160,2, BLACK);
    Tft.drawString(" SD :(",0,160,2, RED);
  }
  if(checkI2C()){
    Serial.println("I2C OK");
    Tft.drawString("I2C :(",0,240,2,BLACK);
    Tft.drawString("I2C :)",0,240,2,GREEN);
  }
  else{
    Serial.println("I2C BAD");
    Tft.drawString("I2C :)",0,240,2, BLACK);
    Tft.drawString("I2C :(",0,240,2, RED);
  }
  Serial.println("");
  Serial.println("");
  led(count % 2);
  delay(1000);
  count++;
}

bool checkSerial1(){
  bool out = true;
  char *msg = "0123456789ABCD";
  int n = strlen(msg);
  int i;
  char c;

  Serial1.write(msg);
  delay(100);
  if(!Serial1.available()){
    Serial.println("no serial available");
    out = false;
  }
  else{
    i = 0;
    while(Serial1.available()){
      c = Serial1.read();
      if(c != msg[i++]){
        Serial.print("read ");
        Serial.print(c);
        Serial.println(" failed comparison");
    out = false;
	Serial1.flush();
      }
    }
  }
  Serial1.flush();
  return out;
}

/********************************************************************************
 * RTC code
 ********************************************************************************/
#define IS_BCD true
#define IS_DEC false
#define IS_BYTES false
const int DS3231_ADDR = 104;

// decimal to binary coded decimal
uint8_t dec2bcd(int dec){
  uint8_t t = dec / 10;
  uint8_t o = dec - t * 10;
  return (t << 4) + o;
}

// binary coded decimal to decimal
int bcd2dec(uint8_t bcd){
  return (((bcd & 0b11110000)>>4)*10 + (bcd & 0b00001111));
}

void rtc_raw_write(uint8_t addr,
		   uint8_t n_byte,
		   bool is_bcd,
		   uint8_t *source){
  uint8_t byte;

  Wire.beginTransmission(DS3231_ADDR); 
  Wire.write(addr); // start at address addr
  for(uint8_t i = 0; i < n_byte; i++){
    if(is_bcd){
      byte = dec2bcd(source[i]);
    }
    else{
      byte = source[i];
    }
    Wire.write(byte);
  }
  Wire.endTransmission();  
}

bool rtc_raw_read(uint8_t addr,
		  uint8_t n_bytes,
		  bool is_bcd,
		  uint8_t *dest){
  bool out = false;
  Wire.beginTransmission(DS3231_ADDR); 
  // Wire.send(addr); 
  Wire.write(addr);
  Wire.endTransmission();
  Wire.requestFrom(DS3231_ADDR, (int)n_bytes); // request n_bytes bytes 
  if(Wire.available()){
    for(uint8_t i = 0; i < n_bytes; i++){
      dest[i] = Wire.read();
      if(is_bcd){ // needs to be converted to dec
	dest[i] = bcd2dec(dest[i]);
      }
    }
    out = true;
  }
  return out;
}

bool checkRTC(){
  bool out = true;
  uint8_t date[7];
  date[0] = 0;
  date[1] = 0;
  date[2] = 0;
  date[3] = 0;
  date[4] = 1;
  date[5] = 1;
  date[6] = 11;
  rtc_raw_write(0, 7, IS_BCD, date);
  date[6] = 0;


  if(rtc_raw_read(0, 7, true, date)){
    if(date[6] != 11){
      out = false;
    }
  }
  else{
    out = false;
  }
  return out;
}
/********************************************************************************
 * END RTC code
 ********************************************************************************/

/********************************************************************************
 * BEGIN I2C code
 ********************************************************************************/

void I2C_raw_write(uint8_t id,
		   uint8_t addr,
		   uint8_t n_byte,
		   uint8_t *source){
  Wire.beginTransmission(id);
  Wire.write(addr);
  for(uint8_t i=0; i < n_byte && i < 32; i++){
    Wire.write(source[i]);
  }
  Wire.endTransmission();
}

bool I2C_raw_read(uint8_t id,
		  uint8_t addr,
		  uint8_t n_byte,
		  uint8_t *dest){
  
  bool out = false;
  Wire.beginTransmission(id); 
  Wire.write(addr); 
  Wire.endTransmission();
  Wire.requestFrom((int)id, (int)n_byte); // request n_byte bytes 
  if(Wire.available()){
    for(uint8_t ii = 0; ii < n_byte && Wire.available(); ii++){
      dest[ii] = Wire.read();
    }
    out = true;
  }
  return out;
}
bool checkI2C(){
  bool out = true;
  uint8_t ping_addr = 3;
  uint8_t data_out[32];
  uint8_t data_in[32];
  int n_byte = 29;

  for(int ii=0; ii < n_byte; ii++){
    data_out[ii] = ii;
  }
  I2C_raw_write(42, ping_addr, n_byte, data_out);
  I2C_raw_read(42, ping_addr, n_byte, data_in);
  for(int ii=0; ii < n_byte; ii++){
    if(data_in[ii] != data_out[ii]){
      out = false;
    }
  }

  if(!out){
    Tft.drawString((char*)data_out, 0,40,2, RED);
    Tft.drawString((char*)data_in, 0,80,2, RED);
#ifdef NOTDEF
    for(int ii=0; ii<n_byte; ii++){
      Serial.print(ii, DEC);
      Serial.print(" ");
      Serial.print(data_out[ii]);
      Serial.print(" ");
      Serial.println(data_in[ii]);
    }
#endif
  }
  else{
    Tft.fillRectangle(0, 0, MAX_X, 110, BLACK);
  }

  return out;
}
//********************************************************************************
// END I2C
//********************************************************************************

bool checkSD(){
  uint8_t data_out[32];
  uint8_t sd_addr = 1;

  bool out;
  char *msg = "0";
  
  data_out[0] = 3; // FAIL
  I2C_raw_read(42, sd_addr, 1, data_out);
  
  out = (bool)data_out[0];
  msg[0] = '0' + data_out[0];
  Tft.drawString(msg, 0,280,2, BLUE);
  if(out > 0){
    out = false;
  }
  else{
    out = true;
  }
  return out;
}

void save(){
  int n_byte = 31;
  uint8_t mydata[32];
  uint8_t itsdata[32];
  for(int ii=0; ii<n_byte; ii++){
    mydata[ii] = ii;
  }
  I2C_raw_write(42, 0, n_byte, mydata);
  if(I2C_raw_read(42, 0, n_byte, itsdata)){
    for(int ii=0; ii<n_byte; ii++){
      Serial.print("itsdata[");
      Serial.print(ii);
      Serial.print("]:");
      Serial.println(itsdata[ii]);
    }
  }
  else{
    Serial.println("Problem reading I2C");
  }
  if(checkRTC()){
    Serial.println("RTC OK");
  }
  else{
    Serial.println("RTC Fail");
  }
  while(1) delay(100);
  
}