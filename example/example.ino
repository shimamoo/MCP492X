#include "MCP4922.h"
#include <SPI.h>

MCP4922 DAC1(9, 10);
MCP4922 DAC2(9, 10);
//(LDAC pin, SlaveSelect pin)

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
