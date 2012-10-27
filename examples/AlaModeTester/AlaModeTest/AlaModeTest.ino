#include <Wire.h>
#include <SD.h>

const int WID = 42;
const int DS3231_ADDR = 104;
const int N_DATA_BYTE = 32;
const int BAUD = 115200;
const int CHIPSELECT = 10;
uint8_t data[N_DATA_BYTE];
uint8_t address;

void setup(){
  Serial.begin(BAUD);
  Wire.begin(WID);

  Wire.onReceive(ALAMODE_onReceive);
  Wire.onRequest(ALAMODE_onRequest);
  for(int ii=0; ii < N_DATA_BYTE; ii++){
    data[ii] = 255;
  }
  data[1] = test_SD();
}

void loop(){
  while(Serial.available()){
    Serial.write(Serial.read()); // ECHO SERIAL
  }
  if(data[2]){
    digitalWrite(13, HIGH);
  }
  else{
    digitalWrite(13, LOW);
  }
}

void ALAMODE_onReceive(int n_byte){
  address = Wire.read();
  int idx = address;
  while(Wire.available() && (address + idx < N_DATA_BYTE)){
    data[address + idx] = Wire.read();
    idx++;
  }
}

void ALAMODE_onRequest(){
  int n_byte = 32;
  if(N_DATA_BYTE - address < 32){
    n_byte = N_DATA_BYTE - address;
  }
  Wire.write(data + address, n_byte);
}

uint8_t test_SD(){
  uint8_t status = 0; // ALL PASS
  File myFile;
  char *msg = "0123456789";

  pinMode(CHIPSELECT, OUTPUT);
  if (!SD.begin(CHIPSELECT)) {
    Serial.println("initialization failed!");
    status |= 1 << 2;
  }
  else{
    SD.remove("test.txt");
    myFile = SD.open("test.txt", FILE_WRITE);

    // if the file opened okay, write to it:
    if (myFile) {
      delay(300);
      myFile.print(msg);
      myFile.close();
    } 
    else {
      // if the file didn't open for writing, print an error:
      status |= 1 << 1;
    }

    // re-open the file for reading:
    myFile = SD.open("test.txt");
    if (myFile) {
      int ii = 0;
      
      while (myFile.available()) {
	if(msg[ii++] != myFile.read()){
	  status |= 1;
	}
      }
      myFile.close();
    }
  }
  return status;
}
