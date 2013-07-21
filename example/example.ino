#include "MCP492X.h"
#include <SPI.h>

//MCP492X -> Arduino(Uno/Mega)
//SCK -> SCK(D13/D52)
//SDI -> MOSI(D11/D51)


MCP4922 DAC1(9, 10);
MCP4922 DAC2(9, 10);
//(LDAC pin, CS pin)

void setup() {
  
  //begin
  DAC1.begin();
  DAC2.begin();
  
}

void loop() {
  
  DAC1.set(0, 1, 1, 1, 1023);
  DAC2.set(1, 1, 1, 1, 4095);
  // (!A/B, BUF, !GA, !SHDN, OutputVal)
  // !A/B  : DACA or DACB Select
  // BUF   : VREF Input Buffer Control
  // !GA   : Output Gain Select
  // !SHDN : Output Power Down Control
  // OutputVal is 0 to 4095
  
  DAC1.update();
  DAC2.update();
  //Update Output
}
