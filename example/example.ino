#include "MCP4922.h"
#include <SPI.h>

MCP4922 DAC1(9, 10);
MCP4922 DAC2(9, 10);
//(LDAC pin, SlaveSelect pin)

void setup() {
  
  //setting
  DAC1.begin(0,1,1,1);
  DAC2.begin(0,1,1,1);
  // (!A/B, BUF, !GA, !SHDN)
  // !A/B  : DACA or DACB Select
  // BUF   : VREF Input Buffer Control
  // !GA   : Output Gain Select
  // !SHDN : Output Power Down Control
}

void loop() {
  
  DAC1.set(1023);
  DAC2.set(4095);
  //value is 0 to 4095

}
